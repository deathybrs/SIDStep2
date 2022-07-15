#include "SIDStep2.h"

#include <array>

#include <JuceHeader.h>

#include "../Requirements/resid-0.16/SID.h"  // NOLINT(clang-diagnostic-nonportable-include-path)

#include "Exporter.h"
#include "Recorder.h"
#include "SIDProgram.h"
#include "SIDRegisters.h"

#include "Programs/Bank.h"

SidStep2::SidStep2 (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
{
    dispatcher -> sampleRateChangedListeners -> add ( 
                                                     this );
    dispatcher -> bankProgramChangedListeners -> add (
                                                      this );
    dispatcher -> liveTitleChangedListeners -> add (
                                                    this );
    dispatcher -> liveArtistChangedListeners -> add (
                                                     this );
    dispatcher -> livePatchEditorModeClickedListeners -> add (
                                                              this );
    dispatcher -> livePatchListModeListeners -> add (
                                                     this );
    dispatcher -> livePatchListSelectedIndexChangedListeners -> add (
                                                                     this );
    dispatcher -> liveRemovePatchClickedListeners -> add (
                                                          this );
    dispatcher -> livePatchChangedListeners -> add (
                                                    this );
    dispatcher -> programParameterChangedListeners -> add (
                                                           this );
    dispatcher -> patchEditorLiveModeClickedListeners -> add (
                                                              this );
    dispatcher -> liveExportArmedListeners -> add (
                                                   this );
    dispatcher -> liveDoneExportingListeners -> add (
                                                     this );
    sidRegisters = std::make_shared < SidRegisters > (
                                                      dispatcher );
    bank = std::make_shared < Bank > (
                                      dispatcher );
    sampleRate          = 0;
    samplesPerFrame     = 0;
    cyclesPerSample     = 0;
    sampleIndex         = 0;
    live                = true;
    patchListMode       = -1;
    patchSelectionIndex = 0;
    armed               = recording = false;
    sampleIndex         = 0;
}

SidStep2::~SidStep2 ()
{
    dispatcher -> sampleRateChangedListeners -> remove (
                                                        this );
    dispatcher -> bankProgramChangedListeners -> remove (
                                                         this );
    dispatcher -> liveTitleChangedListeners -> remove (
                                                       this );
    dispatcher -> liveArtistChangedListeners -> remove (
                                                        this );
    dispatcher -> livePatchEditorModeClickedListeners -> remove (
                                                                 this );
    dispatcher -> livePatchListModeListeners -> remove (
                                                        this );
    dispatcher -> livePatchListSelectedIndexChangedListeners -> remove (
                                                                        this );
    dispatcher -> liveRemovePatchClickedListeners -> remove (
                                                             this );
    dispatcher -> livePatchChangedListeners -> remove (
                                                       this );
    dispatcher -> programParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> patchEditorLiveModeClickedListeners -> remove (
                                                                 this );
    dispatcher -> liveExportArmedListeners -> remove (
                                                      this );
    dispatcher -> liveDoneExportingListeners -> remove (
                                                        this );
    sidRegisters = nullptr;
    bank         = nullptr;
    dispatcher   = nullptr;

    programs . clear (); 
    channelProgramCopies . clear (); 
    currentChannelProgram . clear ();
}

void
    SidStep2::Generate (
            MidiBuffer&                         midi_messages
          , AudioSampleBuffer&                  buffer
          , AudioPlayHead::CurrentPositionInfo& position_info
            )
{
    // Don't generate anything if we're not done being initialized by the VST host.
    if ( sampleRate == 0 ) { return; }

    // If the user is in the patch editor, then we pass generation to that code.
    if ( !live )
    {
        bank -> Generate (
                          midi_messages
                        , buffer
                        , position_info );
        return;
    }

    // Is the tempo is set, then calculate samples per quarter note and current
    // sample position in quarter notes.
    auto samples_per_quarter_note = 0;
    if ( position_info . bpm > 0 )
    {
        tempo                    = position_info . bpm;
        samples_per_quarter_note = static_cast < int > ( sampleRate * ONE_MINUTE / position_info . bpm );
    }

    // If the DAW is playing,
    if ( position_info . isPlaying )
    {
        // then determine the current sampleIndex into the song
        sampleIndex = static_cast < long > ( position_info . timeInSamples );

        // and further, if recording is armed then start recording.
        if ( armed )
        {
            recording = true;
            armed     = false;
            recorder -> Start ();
            const auto filter_volume = sidRegisters -> ReadRegister (
                                                                     0x18 );
            recorder -> onVolumeParameterChanged (
                                                  filter_volume );
            recorder -> onCutoffParameterChanged (
                                                  sidRegisters -> ReadRegister (
                                                                                0x15 ) * 0x100 + sidRegisters -> ReadRegister (
                                                                                                                               0x16 ) );
            recorder -> onResonanceParameterChanged (
                                                     sidRegisters -> ReadRegister (
                                                                                   0x18 ) & 0xF0 >> 4 );
            recorder -> onLowPassParameterChanged (
                                                   ( filter_volume & 0x10 ) == 0x10 );
            recorder -> onBandPassParameterChanged (
                                                    ( filter_volume & 0x20 ) == 0x20 );
            recorder -> onHighPassParameterChanged (
                                                    ( filter_volume & 0x40 ) == 0x40 );
            for ( size_t voice = 0 ; voice < 3 ; voice++ )
            {
                const auto bit = 0x01 << voice;
                recorder -> onFilterVoiceParameterChanged (
                                                           voice
                                                         , ( sidRegisters -> ReadRegister (
                                                                                           0x17 ) & bit ) == bit );
                recorder -> onProgramParameterChanged (
                                                       voice
                                                     , currentChannelProgram [ voice ] );
            }
            const auto start = static_cast < int > ( position_info . ppqLoopStart * samples_per_quarter_note / samplesPerFrame );
            const auto end   = static_cast < int > ( position_info . ppqLoopEnd * samples_per_quarter_note / samplesPerFrame );
            if ( position_info . isLooping )
            {
                recorder -> SetLoopPoints (
                                           start
                                         , end );
            }
        }
    } // Otherwise, if the DAW has stopped playing, then stop recording as well.
    else if ( recording )
    {
        // may want to move this block to the frame... although most people exporting SHOULD be smart enough to allow a 
        // little silence before they stop recording.
        recording = false;
        recorder -> Stop ();
        // fire stop recording event
        dispatcher -> liveDoneExportingListeners -> call (
                                                          &LiveDoneExporting::onLiveDoneExporting );

        // Actual exporter needs to run after the user is done with the export manager
        const Exporter exporter (
                                 recorder );
        MessageManager::callAsync (
                                   [=] ()
                                   {
                                       exporter . ToPatterns (
                                                              title . toStdString ()
                                                            , artist . toStdString () );
                                   } );
    }
    MidiBuffer::Iterator it (
                             midi_messages );
    MidiMessage                        m;
    int                                next_message_sample;
    std::array < short , BUFFER_SIZE > buf {};

    // If there are no MIDI messages, then set the processing to not look for
    // messages in this update.
    if ( !it . getNextEvent (
                             m
                           , next_message_sample ) ) { next_message_sample = buffer . getNumSamples (); }
    auto cycles = 0;
    // loop over the buffer (index is updated inside).
    for ( auto i = 0 ; i < buffer . getNumSamples () ; )
    {
        // if we have advanced to the next frame
        // If the next sample of the next midi event is now (or by some
        // stretch, passed)
        while ( i >= next_message_sample )
        {
            // Send the MIDI signal
            dispatcher -> midiSignalListeners -> call (
                                                       &MIDISignal::onMIDISignal
                                                     , m );

            // and just like earlier, if that was the last midi message, then
            // stop trying to process them.
            if ( !it . getNextEvent (
                                     m
                                   , next_message_sample ) ) { next_message_sample = buffer . getNumSamples (); }
        }
        const auto current_frame = static_cast < unsigned > ( sampleIndex / static_cast < double > ( samplesPerFrame ) );
        if ( current_frame != lastFrame )
        {
            if ( wasPlaying && position_info . isLooping && recorder != nullptr && current_frame < lastFrame && recording )
            {
                if ( position_info . bpm > 0 )
                {
                    // Have we stepped to the next quarter note?
                    if ( static_cast < int > ( sampleIndex ) % samples_per_quarter_note == 0 )
                    {
                        dispatcher -> quarterNoteTickListeners -> call (
                                                                        &QuarterNoteTick::onQuarterNoteTick
                                                                      , static_cast < unsigned int > ( sampleIndex / samples_per_quarter_note ) + 1
                                                                      , position_info . isPlaying );
                    }
                }
                // Then trigger the frame updates.
                recording = false;
                recorder -> Stop ();
                // fire stop recording event
                dispatcher -> liveDoneExportingListeners -> call (
                                                                  &LiveDoneExporting::onLiveDoneExporting );

                // Actual exporter needs to run after the user is done with the export manager
                const Exporter exporter (
                                         recorder );
                MessageManager::callAsync (
                                           [=] ()
                                           {
                                               exporter . ToPatterns (
                                                                      title . toStdString ()
                                                                    , artist . toStdString () );
                                           } );
            }
            else
            {
                // Then trigger the frame updates.
                Frame (
                       current_frame
                     , position_info . isPlaying );
            }
        }
        // Do extra work if the tempo is set
        if ( position_info . bpm > 0 )
        {
            // Have we stepped to the next quarter note?
            if ( static_cast < int > ( sampleIndex ) % samples_per_quarter_note == 0 )
            {
                dispatcher -> quarterNoteTickListeners -> call (
                                                                &QuarterNoteTick::onQuarterNoteTick
                                                              , static_cast < unsigned int > ( sampleIndex / samples_per_quarter_note )
                                                              , position_info . isPlaying );
            }
        }

        // Increase the cycles and update the clock on the SID chip.
        // I don't remember why the value is increased rather than static.
        cycles += static_cast < cycle_count > ( cyclesPerSample );
        const auto s = sidRegisters -> sid -> clock (
                                                     cycles
                                                   , buf . data ()
                                                   , 1 );

        // Then copy the samples into the buffer.
        for ( auto j = 0 ; j < s ; j++ )
        {
            buffer . setSample (
                                0
                              , i + j
                              , float (
                                       buf . at (
                                                 j ) ) / float (
                                                                SIXTEEN_BIT ) );
        }
        // advance the current sample
        sampleIndex += s;
        // and increase i and loop
        i += s;
    }
    wasPlaying = position_info . isPlaying;
}

void
    SidStep2::onLiveTitleChanged (
            const String value
            )
{
    title = String (
                    value );
}

void
    SidStep2::onLiveArtistChanged (
            const String value
            )
{
    artist = String (
                     value );
}

void
    SidStep2::FirePatchListChanged () const // NOLINT(readability-convert-member-functions-to-static)
{
    Array < String > value;
    for ( auto p : programs )
    {
        value . add (
                     String (
                             p -> GetName () ) );
    }
    dispatcher -> livePatchListChangedListeners -> call (
                                                         &LivePatchListChanged::onLivePatchListChanged
                                                       , value );
}

void
    SidStep2::GetStateInformation (
            MemoryBlock& dest_data
            ) const
{
    // This is here to allow attaching the debugger
    //NativeMessageBox::showMessageBox (
    //                                  AlertWindow::InfoIcon
    //                                , "Start Debugger"
    //                                , "You can attach the debugger now." );
    // this saves the config

    unsigned int data_version = 0x20200714;
    dest_data . append (
                        static_cast < const void* > ( &data_version )
                      , sizeof data_version );

    unsigned int patch_list_size = programs . size ();
    dest_data . append (
                        static_cast < const void* > ( &patch_list_size )
                      , sizeof patch_list_size );
    for ( auto i = 0 ; i < programs . size () ; i++ )
    {
        programs [ i ] -> WriteState (
                                      dest_data );
        for ( auto v = 0 ; v < 3 ; v++ )
        {
            channelProgramCopies [ v ] -> getUnchecked (
                                                        i ) -> WriteCopyState (
                                                                               dest_data );
        }
    }
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        unsigned int selection = currentChannelProgram [ v ];
        dest_data . append (
                            static_cast < const void* > ( &selection )
                          , sizeof selection );
        const unsigned int bit     = 1 << v;
        auto               vfilter = ( sidRegisters -> registers [ FILTER_RES_ROUTE ] & bit ) == bit;
        dest_data . append (
                            static_cast < const void* > ( &vfilter )
                          , sizeof vfilter );
    }
    unsigned int volume = sidRegisters -> registers [ VOLUME_FILTER_MODE ] & LOW_NYBBLE;
    dest_data . append (
                        static_cast < const void* > ( &volume )
                      , sizeof volume );
    unsigned int title_length = title . length ();
    dest_data . append (
                        static_cast < const void* > ( &title_length )
                      , sizeof title_length );
    const char* title_string = title . getCharPointer ();
    dest_data . append (
                        static_cast < const void* > ( title_string )
                      , title_length );
    unsigned int artist_length = artist . length ();
    dest_data . append (
                        static_cast < const void* > ( &artist_length )
                      , sizeof artist_length );
    const char* artist_string = artist . getCharPointer ();
    dest_data . append (
                        static_cast < const void* > ( artist_string )
                      , artist_length );
    // have to calculate backwards to get value.
    //auto log_val = static_cast<unsigned int>(
    //    round(
    //        cutoff_base * pow(
    //            binary_base, 1.0 / cutoff_divisor * (
    //                (
    //                    static_cast<double>(
    //                        value
    //                        ) / cutoff_range
    //                    ) - cutoff_offset
    //                )
    //        )
    //    )
    //    );
    const unsigned int cutoff_registers = sidRegisters -> registers [ CUTOFF_LO ] + ( sidRegisters -> registers [ CUTOFF_HI ] << 3 );
    const auto cutoff1 = cutoff_registers / SidRegisters::cutoff_base;
    const auto cutoff2 = sqrt (
                               cutoff1 );
    const auto cutoff3 = cutoff2 / ( 1.0 / SidRegisters::cutoff_divisor );
    const auto cutoff4 = cutoff3 - SidRegisters::cutoff_offset;
    const auto cutoff5 = cutoff4 * SidRegisters::cutoff_range;

    const auto cutoff = static_cast < unsigned int > ( cutoff5 );
    dest_data . append (
                        static_cast < const void* > ( &cutoff )
                      , sizeof cutoff );
    const unsigned int resonance = sidRegisters -> registers [ FILTER_RES_ROUTE ] >> 4;
    dest_data . append (
                        static_cast < const void* > ( &resonance )
                      , sizeof resonance );
    const auto lo_pass = ( sidRegisters -> registers [ VOLUME_FILTER_MODE ] & 0x10 ) == 0x10;
    dest_data . append (
                        static_cast < const void* > ( &lo_pass )
                      , sizeof lo_pass );
    const auto band_pass = ( sidRegisters -> registers [ VOLUME_FILTER_MODE ] & 0x20 ) == 0x20;
    dest_data . append (
                        static_cast < const void* > ( &band_pass )
                      , sizeof band_pass );
    const auto hi_pass = ( sidRegisters -> registers [ VOLUME_FILTER_MODE ] & 0x40 ) == 0x40;
    dest_data . append (
                        static_cast < const void* > ( &hi_pass )
                      , sizeof hi_pass );
}

void
    SidStep2::ReadState20200714 (
            MemoryInputStream& stream
            )
{
    ReadState20200708 (
                       stream );
    unsigned int cutoff;
    stream . read (
                   &cutoff
                 , sizeof cutoff );
    dispatcher -> cutoffParameterChangedListeners -> call (
                                                           &CutoffParameterChanged::onCutoffParameterChanged
                                                         , cutoff );
    unsigned int resonance;
    stream . read (
                   &resonance
                 , sizeof resonance );
    dispatcher -> resonanceParameterChangedListeners -> call (
                                                              &ResonanceParameterChanged::onResonanceParameterChanged
                                                            , resonance );
    bool lo_pass;
    stream . read (
                   &lo_pass
                 , sizeof lo_pass );
    dispatcher -> lowPassParameterChangedListeners -> call (
                                                            &LowPassParameterChanged::onLowPassParameterChanged
                                                          , lo_pass );
    bool band_pass;
    stream . read (
                   &band_pass
                 , sizeof band_pass );
    dispatcher -> bandPassParameterChangedListeners -> call (
                                                             &BandPassParameterChanged::onBandPassParameterChanged
                                                           , band_pass );
    bool hi_pass;
    stream . read (
                   &hi_pass
                 , sizeof hi_pass );
    dispatcher -> highPassParameterChangedListeners -> call (
                                                             &HighPassParameterChanged::onHighPassParameterChanged
                                                           , hi_pass );
}

void
    SidStep2::ReadState20200708 (
            MemoryInputStream& stream
            )
{
    // and this loads it (the names are a bit misleading)
    unsigned int patch_list_size;
    stream . read (
                   &patch_list_size
                 , sizeof patch_list_size );
    for ( unsigned int i = 0 ; i < patch_list_size ; i++ )
    {
        auto p = SidProgram::LoadState (
                                        dispatcher
                                      , stream );
        programs . add (
                        p );
        for ( auto v = 0 ; v < 3 ; v++ )
        {
            auto c = SidProgram::LoadCopyState (
                                                stream
                                              , p );
            channelProgramCopies [ v ] -> add (
                                               c );
        }
    }
    FirePatchListChanged ();
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        unsigned int selection;
        stream . read (
                       &selection
                     , sizeof selection );
        currentChannelProgram . set (
                                     v
                                   , selection );
        dispatcher -> programParameterChangedListeners -> call (
                                                                &ProgramParameterChanged::onProgramParameterChanged
                                                              , v
                                                              , selection );
        bool filtered;
        stream . read (
                       &filtered
                     , sizeof filtered );
        dispatcher -> filterVoiceParameterChangedListeners -> call (
                                                                    &FilterVoiceParameterChanged::onFilterVoiceParameterChanged
                                                                  , v
                                                                  , filtered );
    }
    unsigned int volume;
    stream . read (
                   &volume
                 , sizeof volume );
    dispatcher -> volumeParameterChangedListeners -> call (
                                                           &VolumeParameterChanged::onVolumeParameterChanged
                                                         , volume );
    unsigned int title_length;
    stream . read (
                   &title_length
                 , sizeof title_length );
    const auto title_array_size = static_cast < int > ( title_length ) + 1;
    const auto title_string     = new char[title_array_size];
    stream . read (
                   title_string
                 , static_cast < int > ( title_length ) );
    title = String (
                    title_string
                  , title_length );
    delete[] title_string;
    dispatcher -> liveTitleChangedListeners -> call (
                                                     &LiveTitleChanged::onLiveTitleChanged
                                                   , title );
    unsigned int artist_length;
    stream . read (
                   &artist_length
                 , sizeof artist_length );
    const auto artist_array_size = static_cast < int > ( artist_length ) + 1;
    const auto artist_string     = new char[artist_array_size];
    stream . read (
                   artist_string
                 , static_cast < int > ( artist_length ) );
    artist = String (
                     artist_string
                   , artist_length );
    delete[] artist_string;
    dispatcher -> liveArtistChangedListeners -> call (
                                                      &LiveArtistChanged::onLiveArtistChanged
                                                    , artist );
}

void
    SidStep2::SetStateInformation (
            const void* data
          , const int   size_in_bytes
            )
{
    // This is here to allow attaching the debugger
    //NativeMessageBox::showMessageBox (
    //                                  AlertWindow::InfoIcon
    //                                , "Start Debugger"
    //                                , "You can attach the debugger now." );
    programs . clear ();
    for ( auto v = 0 ; v < 3 ; v++ ) { channelProgramCopies [ v ] -> clear (); }
    MemoryInputStream stream (
                              data
                            , size_in_bytes
                            , false );

    unsigned int data_version;
    stream . read (
                   &data_version
                 , sizeof data_version );
    if ( data_version == 0x20200714 )
    {
        // Known current version
        ReadState20200714 (
                           stream );
    }
    else if ( data_version == 0x20200708 )
    {
        ReadState20200708 (
                           stream );
    }
    else
    {
        stream . setPosition (
                              0 );
        ReadState20200708 (
                           stream );
    }
}

void
    SidStep2::onSampleRateChanged (
            const double new_rate
            )
{
    sampleRate      = static_cast < int > ( new_rate );
    samplesPerFrame = static_cast < int > ( new_rate / FRAME_RATE );
    cyclesPerSample = CPU_FREQUENCY / new_rate;
    sidRegisters -> sid -> set_sampling_parameters (
                                                    static_cast < int > ( CPU_FREQUENCY )
                                                  , SAMPLE_FAST
                                                  , new_rate
                                                  , FILTER_COEFFICIENT * new_rate / 2 );
}


// This definition needs to be expanded - currently, this block of code responds to the FIRST construction
// to create a copy of the new program created by the bank.  It needs to respond to later events because the
// patch tree leaves trigger a reaction in bank that fires this event.
// 
// First, gotta suss what should be done.
// 
// Things that MIGHT happen in this event:
// 
// * It might be the startup mode that was first here.
// * It could be the result of adding to the program list
// * It could be the result of replacing on the program list
// * This SHOULDN'T need to do anything just because a program has been SaveAs'ed, as the programs themselves tend to 
//	 handle that.
void
    SidStep2::onBankProgramChanged (
            const String                                   old_id
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    if ( programs . size () == 0 )
    {
        programs . add (
                        new SidProgram (
                                        *program ) );
        for ( auto i = 0 ; i < 3 ; i++ )
        {
            channelProgramCopies . add (
                                        new ReferenceCountedArray < SidProgram > () );
            // ReSharper disable once CppNonReclaimedResourceAcquisition
            ReferenceCountedObjectPtr < SidProgram > p = new SidProgram (
                                                                         *program );
            channelProgramCopies [ i ] -> add (
                                               p );
            currentChannelProgram . add (
                                         0 );
            p -> SetForVoice (
                              i );
            dispatcher -> loadLivePatchListeners -> call (
                                                          &LoadLivePatch::onLoadLivePatch
                                                        , i
                                                        , p );
        }
        FirePatchListChanged ();
        return;
    }
    if ( live )
    {
        if ( patchListMode == 1 )
        {
            programs . add (
                            new SidProgram (
                                            *program ) );
            for ( auto i = 0 ; i < 3 ; i++ )
            {
                channelProgramCopies [ i ] -> add (
                                                   new SidProgram (
                                                                   *program ) );
            }
            FirePatchListChanged ();
            patchListMode = -1;
        }
        else if ( patchListMode == 2 && patchSelectionIndex != -1 )
        {
            programs . set (
                            patchSelectionIndex
                          , new SidProgram (
                                            *program ) );
            for ( auto i = 0 ; i < 3 ; i++ )
            {
                channelProgramCopies [ i ] -> set (
                                                   patchSelectionIndex
                                                 , new SidProgram (
                                                                   *program ) );
                if ( currentChannelProgram [ i ] == patchSelectionIndex )
                {
                    channelProgramCopies [ i ] -> getObjectPointer (
                                                                    patchSelectionIndex ) -> SetForVoice (
                                                                                                          i );
                    dispatcher -> loadLivePatchListeners -> call (
                                                                  &LoadLivePatch::onLoadLivePatch
                                                                , i
                                                                , channelProgramCopies [ i ] -> getObjectPointer (
                                                                                                                  currentChannelProgram [ i ] ) );
                }
            }
            FirePatchListChanged ();
            patchListMode = -1;
        }
    }
    else
    {
        for ( auto i = 0 ; i < programs . size () ; i++ )
        {
            if ( programs [ i ] -> GetId () . toDashedString () == old_id )
            {
                programs . set (
                                i
                              , new SidProgram (
                                                *program ) );
                for ( auto j = 0 ; j < 3 ; j++ )
                {
                    channelProgramCopies [ j ] -> set (
                                                       i
                                                     , new SidProgram (
                                                                       *program ) );
                    if ( currentChannelProgram [ j ] == i )
                    {
                        channelProgramCopies [ j ] -> getObjectPointer (
                                                                        i ) -> SetForVoice (
                                                                                            j );
                        dispatcher -> loadLivePatchListeners -> call (
                                                                      &LoadLivePatch::onLoadLivePatch
                                                                    , j
                                                                    , channelProgramCopies [ j ] -> getObjectPointer (
                                                                                                                      currentChannelProgram [ j ] ) );
                    }
                }
                FirePatchListChanged ();
                break;
            }
        }
    }
}

void
    SidStep2::onLivePatchEditorModeClicked () { live = false; }

void
    SidStep2::onPatchEditorLiveModeClicked () { live = true; }

void
    SidStep2::onLivePatchListMode (
            const int value
            ) { patchListMode = value; }

void
    SidStep2::onLivePatchListSelectedIndexChanged (
            const int value
            )
{
    patchSelectionIndex = value;
    dispatcher -> livePatchSelectedListeners -> call (
                                                      &LivePatchSelected::onLivePatchSelected
                                                    , programs [ value ] );
}

void
    SidStep2::onLiveRemovePatchClicked ()
{
    if ( live )
    {
        if ( programs . size () == 1 )
        {
            NativeMessageBox::showMessageBox (
                                              AlertWindow::WarningIcon
                                            , "Error!"
                                            , "Must have at least one loaded patch." );
            return;
        }
        programs . remove (
                           patchSelectionIndex );
        if ( patchSelectionIndex >= programs . size () ) { patchSelectionIndex--; }
        FirePatchListChanged ();
        patchListMode = -1;
    }
}

void
    SidStep2::onLiveExportArmed ()
{
    armed    = true;
    recorder = nullptr;
    recorder = std::make_shared < Recorder > (
                                              dispatcher
                                            , programs );
}

void
    SidStep2::onLiveDoneExporting ()
{
    armed = false;
    recorder -> Stop ();
}

void
    SidStep2::Frame (
            const unsigned frame
          , const bool     playing
            )
{
    if ( lastFrame == frame ) { return; }
    lastFrame = frame;
    if ( playing )
    {
        sidRegisters -> SetFrame (
                                  frame );
    }
    dispatcher -> frameListeners -> call (
                                          &Frame::onFrame );
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        ProcessVoice (
                      v );
    }
    sidRegisters -> WriteRegisters ();
    if ( recorder != nullptr )
    {
        recorder -> Frame (
                           frame );
    }
}

void
    SidStep2::ProcessVoice (
            const int v
            ) const
{ 
    sidRegisters -> ProcessNotesOnOff (
                                       v );
    sidRegisters -> ProcessPulseWidth (
                                       v );
    sidRegisters -> WriteNotes (
                                v );
}
