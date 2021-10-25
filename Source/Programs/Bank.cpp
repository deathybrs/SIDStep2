#include "Bank.h"

#include "../Note.h"
#include "../SIDProgram.h"

#include "../SharedProperties.h"

#include "../Requirements/resid-0.16/sid.h"
// ReSharper restore CppUnusedIncludeDirective


using namespace juce;

Bank::Bank ()
    :
    sid (
         new SID )
  , currentProgram (
                    new SidProgram )
  , arpIndex (
              -1 )
  , sampleRate (
                0 )
  , samplesPerFrame (
                     0 )
  , cyclesPerSample (
                     0 )
  , sampleIndex (
                 0 )
{
    sid -> set_chip_model (
                           MOS8580 );
    sid -> enable_filter (
                          false );
    sid -> set_sampling_parameters (
                                    985248
                                  , SAMPLE_FAST
                                  , 44100
                                  , 19845 );
    for ( auto i = 0 ; i < 0x18 ; i++ )
    {
        registers . add (
                         0 );
        dirty . add (
                     false );
    }
    registers . add (
                     0x0f );
    dirty . add (
                 true );
    DirtyWrite (
                0x03
              , 0x08 );
    bankNewListeners -> add (
                             this );
    bankLoadListeners -> add (
                              this );
    bankSaveListeners -> add (
                              this );
    bankSaveAsListeners -> add (
                                this );
    SharedResourcePointer < ListenerList < BankRefreshLive > > () -> add (
                                                                          this );
    SharedResourcePointer < ListenerList < SampleRateChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LivePatchSelected > > () -> add (
                                                                            this );
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
}

Bank::~Bank ()
{
    properties -> saveIfNeeded ();
    bankNewListeners -> remove (
                                this );
    bankLoadListeners -> remove (
                                 this );
    bankSaveListeners -> remove (
                                 this );
    bankSaveAsListeners -> remove (
                                   this );
    SharedResourcePointer < ListenerList < BankRefreshLive > > () -> remove (
                                                                             this );
    SharedResourcePointer < ListenerList < SampleRateChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LivePatchSelected > > () -> remove (
                                                                               this );
}

void
    Bank::Generate (
            MidiBuffer&                         midi_messages
          , AudioSampleBuffer&                  buffer
          , AudioPlayHead::CurrentPositionInfo& position_info
            )
{
    MidiBuffer::Iterator it (
                             midi_messages );
    MidiMessage m;
    int         next_message_sample;
    short       buf[16];
    if ( position_info . isPlaying )
        sampleIndex = static_cast < long > ( position_info . timeInSamples );
    if ( !it . getNextEvent (
                             m
                           , next_message_sample ) )
        next_message_sample = buffer . getNumSamples ();
    for ( auto i = 0 ; i < buffer . getNumSamples () ; )
    {
        sampleIndex++;
        if ( sampleIndex % samplesPerFrame == 0 )
            Frame ();
        auto cycles = 0;
        while ( i >= next_message_sample )
        {
            if ( m . isNoteOff () )
            {
                int rit;
                for ( rit = 0 ; rit < releasedNotes . size () ; rit++ )
                {
                    if ( releasedNotes [ rit ] == static_cast < unsigned int > ( m . getNoteNumber () ) )
                        break;
                }
                if ( rit == releasedNotes . size () )
                    releasedNotes . add (
                                         m . getNoteNumber () );
            }
            else if ( m . isNoteOn () )
            {
                int nit;
                for ( nit = 0 ; nit < notes . size () ; nit++ )
                {
                    if ( notes [ nit ] . note == static_cast < unsigned int > ( m . getNoteNumber () ) )
                        break;
                }
                if ( nit == notes . size () )
                {
                    Note n;
                    n . note     = m . getNoteNumber ();
                    n . velocity = m . getVelocity ();
                    notes . add (
                                 n );
                }
                else
                {
                    int rit;
                    for ( rit = 0 ; rit < releasedNotes . size () ; rit++ )
                    {
                        if ( releasedNotes [ rit ] == static_cast < unsigned int > ( m . getNoteNumber () ) )
                            break;
                    }
                    if ( rit == releasedNotes . size () )
                        releasedNotes . remove (
                                                rit );
                }
            }
            if ( !it . getNextEvent (
                                     m
                                   , next_message_sample ) )
                next_message_sample = buffer . getNumSamples ();
        }
        cycles += cyclesPerSample;
        //int s = sid->clock(static_cast<unsigned int>(cyclesPerSample), buf);
        const auto s = sid -> clock (
                                     cycles
                                   , buf
                                   , 1 );
        for ( auto j = 0 ; j < s ; j++ )
            buffer . setSample (
                                0
                              , i + j
                              , float (
                                       buf [ j ] ) / float (
                                                            0x8000 ) );
        //buffer.setSample(0, i, float(buf[0]) / float(0x8000));

        i += s;
    }
}

void
    Bank::onBankNew ()
{
    currentProgram = new SidProgram ();
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
}

void
    Bank::onBankLoad (
            const String id
            )
{
    const ScopedPointer < XmlElement > patches_element = properties -> getXmlValue (
                                                                                    "patches" );
    auto        i                       = 0;
    XmlElement* current_program_element = nullptr;
    for ( ; i < patches_element -> getNumChildElements () ; i++ )
    {
        current_program_element = patches_element -> getChildElement (
                                                                      i ) -> getChildByAttribute (
                                                                                                  "id"
                                                                                                , id );
        if ( current_program_element != nullptr )
            break;
    }
    if ( current_program_element != nullptr )
    {
        currentProgram = new SidProgram (
                                         current_program_element );
    }
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
}

void
    Bank::onBankSave ()
{
    const ScopedPointer < XmlElement > patches_element = properties -> getXmlValue (
                                                                                    "patches" );
    auto        i                       = 0;
    XmlElement* current_program_element = nullptr;
    for ( ; i < patches_element -> getNumChildElements () ; i++ )
    {
        current_program_element = patches_element -> getChildElement (
                                                                      i ) -> getChildByAttribute (
                                                                                                  "id"
                                                                                                , currentProgram -> GetId () . toDashedString () );
        if ( current_program_element != nullptr ) { break; }
    }
    if ( currentProgram -> IsFactoryPreset () || current_program_element == nullptr )
    {
        bankStartSaveAsListeners -> call (
                                          &BankStartSaveAs::onBankStartSaveAs );
        return;
    }
    currentProgram -> Write (
                             current_program_element );
    properties -> setValue (
                            "patches"
                          , patches_element );
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
    bankTreeChangedListeners -> call (
                                      &BankTreeChanged::onBankTreeChanged );
}

void
    Bank::onBankSaveAs (
            const Category category
            )
{
    // TODO: Need way to replace old programs on a save as - in place, but not positive this works properly
    const auto old_id = currentProgram -> GetId () . toDashedString ();
    currentProgram -> ResetId ();
    const ScopedPointer < XmlElement > patches_element = properties -> getXmlValue (
                                                                                    "patches" );
    auto category_element = patches_element -> getChildByName (
                                                               GetCategoryElementName (
                                                                                       category ) );
    const auto current_program_element = new XmlElement (
                                                         "patch" );
    currentProgram -> Write (
                             current_program_element );
    category_element -> addChildElement (
                                         current_program_element );
    properties -> setValue (
                            "patches"
                          , patches_element );
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , old_id
                                       , currentProgram );
    bankTreeChangedListeners -> call (
                                      &BankTreeChanged::onBankTreeChanged );
}

void
    Bank::onSampleRateChanged (
            const double new_rate
            )
{
    sampleRate      = static_cast < int > ( new_rate );
    samplesPerFrame = static_cast < int > ( new_rate / 50 );
    cyclesPerSample = 985248.0 / new_rate;
    sid -> set_sampling_parameters (
                                    985248
                                  , SAMPLE_FAST
                                  , new_rate
                                  , 0.9 * new_rate / 2.0 );
}

void
    Bank::onBankRefreshLive ()
{
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
}

void
    Bank::onLivePatchSelected (
            const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    currentProgram = program;
    bankProgramChangedListeners -> call (
                                         &BankProgramChanged::onBankProgramChanged
                                       , currentProgram -> GetId () . toDashedString ()
                                       , currentProgram );
}

void
    Bank::Frame ()
{
    const auto e  = currentProgram -> GetEnvelope ();
    const auto wt = currentProgram -> GetWavetable ();
    if ( notes . size () > 0 && arpIndex != -1 ) { ReleaseProcessor (); }
    if ( arpIndex == -1 && notes . size () > 0 )
    {
        DirtyWrite (
                    5
                  , ( e -> getDefaultAttack () << 4 ) + e -> getDefaultDecay () );
        DirtyWrite (
                    6
                  , ( e -> getDefaultSustain () << 4 ) + e -> getDefaultRelease () );
        arpIndex = 0;
        currentProgram -> Start ();
    }
    if ( notes . size () > 0 )
    {
        if ( arpIndex >= notes . size () ) { arpIndex = 0; }
        const auto pulse_cycle       = currentProgram -> GetExpression () -> getCurrentPulseValue ();
        const auto pulse_table_cycle = currentProgram -> GetPulseTable () -> GetCurrentPulseTableEntry ();
        const auto pulse_value       = static_cast < int > ( pulse_cycle ) - 2048 + ( static_cast < int > ( pulse_table_cycle ) - 2048 ) + 2048;
        DirtyWrite (
                    2
                  , pulse_value & 0xff );
        DirtyWrite (
                    3
                  , ( pulse_value & 0xf00 ) >> 8 );
        SetNote (
                 notes [ arpIndex ] . note );
        DirtyWrite (
                    4
                  , wt -> GetCurrentWaveTableEntry () );
        arpIndex++;
    }
    for ( auto i = 0x15 ; i < 0x19 ; i++ )
        DirtyWrite (
                    i );
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        for ( auto j = 0 ; j < 7 ; j++ )
            if ( j != 4 )
                DirtyWrite (
                            v * 7 + j );
        DirtyWrite (
                    v * 7 + 4 );
    }
    currentProgram -> Step ();
}

void
    Bank::SetNote (
            const unsigned int note
            )
{
    const auto ex                       = currentProgram -> GetExpression ();
    const auto vib                      = ex -> getVibrato () -> GetCurrentVibratoValue () / 4096.0;
    const auto n_tab                    = currentProgram -> GetNoteTable ();
    const auto current_note_table_entry = n_tab -> GetCurrentNoteTableEntry ();
    const auto note_offset              = current_note_table_entry . rowType == RELATIVE
                                              ? current_note_table_entry . value
                                              : 0;
    auto f = 440.0 * pow (
                          2
                        , ( note + note_offset - 69.0 ) / 12.0 + vib );
    if ( current_note_table_entry . rowType == ABSOLUTE ) { f = static_cast < double > ( current_note_table_entry . value ); }

    // 17.02841924063789015557504303485 = PAL constant
    const auto fv = 17.02841924063789015557504303485 * f;
    const auto v  = int (
                         fv );
    const auto lv = v & 0xff;
    const auto hv = ( v & 0xff00 ) >> 8;
    DirtyWrite (
                0
              , lv );
    DirtyWrite (
                1
              , hv );
}

void
    Bank::ReleaseProcessor ()
{
    // if there are more active notes than releasing notes, then release the exiting notes immediately
    if ( notes . size () > releasedNotes . size () )
    {
        NotesOff ();
        if ( currentProgram -> GetWavetable () -> Released () )
            arpIndex = -1;
        return;
    }
    // otherwise, if all notes are releasing, check to see if the wavetable has finished releasing
    if ( notes . size () == releasedNotes . size () )
    {
        const auto wt = currentProgram -> GetWavetable ();
        if ( !wt -> Released () ) { currentProgram -> Release (); }
        if ( wt -> DoneReleasing () )
        {
            // if so, then finish releasing notes
            NotesOff ();
            DirtyWrite (
                        4
                      , wt -> GetCurrentWaveTableEntry () & 0xfe );
            arpIndex = -1;
        }
    }
}

void
    Bank::NotesOff ()
{
    for each ( unsigned int cn in releasedNotes )
    {
        int nit;
        for ( nit = 0 ; nit < notes . size () ; nit++ )
        {
            if ( notes [ nit ] . note == cn )
                break;
        }
        if ( nit != notes . size () )
            notes . remove (
                            nit );
    }
    releasedNotes . clear ();
}

void
    Bank::DirtyWrite (
            const int index
            )
{
    if ( !dirty [ index ] )
        return;
    sid -> write (
                  index
                , static_cast < unsigned char > ( registers [ index ] ) );
    dirty . set (
                 index
               , false );
}

void
    Bank::DirtyWrite (
            const int index
          , const int value
            )
{
    if ( registers [ index ] == value )
        return;
    registers . set (
                     index
                   , value );
    dirty . set (
                 index
               , true );
}


// TODO: Move this into a better place for it
String
    Bank::GetCategoryElementName (
            const Category c
            )
{
    switch ( c )
    {
        case Bass:
            return "basses";
        case Drums:
            return "drums";
        case Lead:
            return "leads";
        case Keys:
            return "keys";
        case Pad:
            return "pads";
        case SFX:
            return "sfx";
        default: case Misc:
            return "misc";
    }
}
