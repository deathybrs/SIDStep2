#include "SIDStep2.h"

#include <array>

#include <JuceHeader.h>

#include "../Requirements/resid-0.16/SID.h"  // NOLINT(clang-diagnostic-nonportable-include-path)

#include "Exporter.h"
#include "Recorder.h"
#include "SIDProgram.h"
#include "SIDRegisters.h"

#include "Programs/Bank.h"

//#include "UI/ExportManager.h"

SidStep2::SidStep2 ()
{
    SharedResourcePointer < ListenerList < SampleRateChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> add (
                                                                           this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > > () -> add (
                                                                                     this );
    SharedResourcePointer < ListenerList < LivePatchListMode > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LivePatchListSelectedIndexChanged > > () -> add (
                                                                                            this );
    SharedResourcePointer < ListenerList < LiveRemovePatchClicked > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < LivePatchChanged > > () -> add (
                                                                           this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > > () -> add (
                                                                                     this );
    SharedResourcePointer < ListenerList < LiveExportArmed > > () -> add (
                                                                          this );
    SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> add (
                                                                            this );
    sidRegisters        = new SidRegisters ();
    bank                = new Bank ();
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
    SharedResourcePointer < ListenerList < SampleRateChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> remove (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > > () -> remove (
                                                                                        this );
    SharedResourcePointer < ListenerList < LivePatchListMode > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LivePatchListSelectedIndexChanged > > () -> remove (
                                                                                               this );
    SharedResourcePointer < ListenerList < LiveRemovePatchClicked > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < LivePatchChanged > > () -> remove (
                                                                              this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > > () -> remove (
                                                                                        this );
    SharedResourcePointer < ListenerList < LiveExportArmed > > () -> remove (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> remove (
                                                                               this );
    sidRegisters = nullptr;
    bank         = nullptr;
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
        }
    } // Otherwise, if the DAW has stopped playing, then stop recording as well.
    else if ( recording )
    {
        // may want to move this block to the frame... although most people exporting SHOULD be smart enough to allow a 
        // little silence before they stop recording.
        recording = false;
        recorder -> Stop ();
        // fire stop recording event
        SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> call (
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
            SharedResourcePointer < ListenerList < MIDISignal > > () -> call (
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
            // Then trigger the frame updates.
            Frame (
                   current_frame
                 , position_info . isPlaying );
        }
        // Do extra work if the tempo is set
        if ( position_info . bpm > 0 )
        {
            // Have we stepped to the next quarter note?
            if ( static_cast < int > ( sampleIndex ) % samples_per_quarter_note == 0 )
            {
                SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> call (
                                                                                       &QuarterNoteTick::onQuarterNoteTick
                                                                                     , static_cast < unsigned int > ( sampleIndex / samples_per_quarter_note ) );

                // If we're looping
                if ( position_info . isLooping )
                {
                    // Get the current quarter note
                    const auto quarter_note = static_cast < unsigned int > ( sampleIndex / samples_per_quarter_note ) + 1;
                    // If it's equal to the loop start, then set that looping
                    // point in the recording.
                    if ( quarter_note == static_cast < unsigned int > ( position_info . ppqLoopStart ) )
                    {
                        sidRegisters -> SetLoopStart (
                                                      static_cast < int > ( sampleIndex ) / samplesPerFrame );
                    }
                    // Same if it's the end, and further stop exporting if it has looped.
                    if ( quarter_note == static_cast < unsigned int > ( position_info . ppqLoopEnd ) )
                    {
                        sidRegisters -> SetLoopEnd (
                                                    static_cast < int > ( sampleIndex ) / samplesPerFrame );
                        SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> call (
                                                                                                 &LiveDoneExporting::onLiveDoneExporting );
                    }
                }
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
    SharedResourcePointer < ListenerList < LivePatchListChanged > > () -> call (
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
    // and this loads it (the names are a bit misleading)
    unsigned int patch_list_size;
    stream . read (
                   &patch_list_size
                 , sizeof patch_list_size );
    for ( unsigned int i = 0 ; i < patch_list_size ; i++ )
    {
        auto p = SidProgram::LoadState (
                                        stream );
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
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        unsigned int selection;
        stream . read (
                       &selection
                     , sizeof selection );
        currentChannelProgram . set (
                                     v
                                   , selection );
        SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> call (
                                                                                       &ProgramParameterChanged::onProgramParameterChanged
                                                                                     , v
                                                                                     , selection );
        bool filtered;
        stream . read (
                       &filtered
                     , sizeof filtered );
        SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> call (
                                                                                           &FilterVoiceParameterChanged::onFilterVoiceParameterChanged
                                                                                         , v
                                                                                         , filtered );
    }
    FirePatchListChanged ();
    unsigned int volume;
    stream . read (
                   &volume
                 , sizeof volume );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> call (
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
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> call (
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
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> call (
                                                                             &LiveArtistChanged::onLiveArtistChanged
                                                                           , artist );
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
            SharedResourcePointer < ListenerList < LoadLivePatch > > () -> call (
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
                    SharedResourcePointer < ListenerList < LoadLivePatch > > () -> call (
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
                        SharedResourcePointer < ListenerList < LoadLivePatch > > () -> call (
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
    SharedResourcePointer < ListenerList < LivePatchSelected > > () -> call (
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
                                              programs );
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
    SharedResourcePointer < ListenerList < ::Frame > > () -> call (
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
