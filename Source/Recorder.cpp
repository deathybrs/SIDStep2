#include "Recorder.h"

#include <string>

#include "Command.h"
#include "SIDProgram.h"

#include "Programs/Expression.h"

Recorder::Recorder (
        const ReferenceCountedArray < SidProgram >& patch_list
        )
    :
    programList (
                 patch_list ) {}

Recorder::~Recorder () { Stop (); }

void
    Recorder::Start ()
{
    SharedResourcePointer < ListenerList < NoteOff > > () -> add (
                                                                  this );
    SharedResourcePointer < ListenerList < NoteOn > > () -> add (
                                                                 this );
    SharedResourcePointer < ListenerList < AttackParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < DecayParameterChanged > > () -> add (
                                                                                this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> add (
                                                                                      this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < PitchBendParameterChanged > > () -> add (
                                                                                    this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < PulseWidthParameterChanged > > () -> add (
                                                                                     this );
    SharedResourcePointer < ListenerList < ReleaseParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> add (
                                                                                    this );
    SharedResourcePointer < ListenerList < SustainParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> add (
                                                                                       this );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> add (
                                                                          this );
    recording = true;
}

void
    Recorder::Stop ()
{
    SharedResourcePointer < ListenerList < NoteOff > > () -> remove (
                                                                     this );
    SharedResourcePointer < ListenerList < NoteOn > > () -> remove (
                                                                    this );
    SharedResourcePointer < ListenerList < AttackParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < DecayParameterChanged > > () -> remove (
                                                                                   this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> remove (
                                                                                         this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < PitchBendParameterChanged > > () -> remove (
                                                                                       this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < PulseWidthParameterChanged > > () -> remove (
                                                                                        this );
    SharedResourcePointer < ListenerList < ReleaseParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> remove (
                                                                                       this );
    SharedResourcePointer < ListenerList < SustainParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> remove (
                                                                                           this );
    SharedResourcePointer < ListenerList < VibratoDelayParameterChanged > > () -> remove (
                                                                                          this );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> remove (
                                                                                          this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> remove (
                                                                             this );
    if ( recording && loopStart > 0 && loopEnd > 0 )
    {
        patternIndexes . push_back (
                                    {
                                            globalCommands . size ()
                                          , voiceCommands . at (
                                                                0 ) . size ()
                                          , voiceCommands . at (
                                                                1 ) . size ()
                                          , voiceCommands . at (
                                                                2 ) . size ()
                                    } );
        if ( patternFrame . at (
                                patternFrame . size () - 1 ) != currentFrame + 1 )
        {
            patternFrame . push_back (
                                      currentFrame + 1 );
        }
    }

    recording = false;
}

void
    Recorder::Frame (
            const unsigned frame
            )
{
    if ( !recording ) { return; }
    currentFrame = frame;
    for ( const auto& command : currentGlobalCommands )
    {
        globalCommands . push_back (
                                    command );
    }
    currentGlobalCommands . clear ();
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        for ( const auto& command : currentVoiceCommands . at (
                                                               v ) )
        {
            voiceCommands . at (
                                v ) . push_back (
                                                 command );
        }
        if ( notesChanged . at (
                                v ) )
        {
            if ( !currentNotes . at (
                                     v ) . empty () )
            {
                auto note_on = std::make_shared < Command > (
                                                             COMMANDS::NOTE_ON
                                                           , currentFrame
                                                           , currentNotes . at (
                                                                                v ) );
                voiceCommands . at (
                                    v ) . push_back (
                                                     note_on );
            }
            else
            {
                auto note_off = std::make_shared < Command > (
                                                              COMMANDS::NOTE_OFF
                                                            , currentFrame
                                                            , std::vector < unsigned char > () );
                voiceCommands . at (
                                    v ) . push_back (
                                                     note_off );
            }
            notesChanged . at (
                               v ) = false;
        }
        currentVoiceCommands . at (
                                   v ) . clear ();
    }
}

void
    Recorder::SaveDebug ()
{
    const auto f = fopen (
                          "output"
                        , "w" );
    fwrite (
            "global\n"
          , 1
          , 7
          , f );
    for ( const auto& command : globalCommands )
    {
        std::string arg;
        auto        r = command -> Render ();
        arg += "\t!byte ";
        auto first = true;
        for ( const auto& v : r )
        {
            if ( !first ) { arg += ","; }
            first = false;
            arg += std::to_string (
                                   v );
        }
        arg += "\n";
        fwrite (
                arg . c_str ()
              , 1
              , arg . length ()
              , f );
    }
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        auto arg = "\nvoice " + std::to_string (
                                                v ) + "\n";
        fwrite (
                arg . c_str ()
              , 1
              , arg . length ()
              , f );
        for ( const auto& command : voiceCommands . at (
                                                        v ) )
        {
            arg    = "";
            auto r = command -> Render ();
            arg += "\t!byte ";
            auto first = true;
            for ( const auto& val : r )
            {
                if ( !first ) { arg += ","; }
                first = false;
                arg += std::to_string (
                                       val );
            }
            arg += "\n";
            fwrite (
                    arg . c_str ()
                  , 1
                  , arg . length ()
                  , f );
        }
    }
    fclose (
            f );
}

void
    Recorder::onNoteOff (
            const unsigned channel
          , const unsigned note
          , const unsigned velocity
            )
{
    const auto f = std::find (
                              currentNotes . at (
                                                 channel ) . begin ()
                            , currentNotes . at (
                                                 channel ) . end ()
                            , note );
    if ( f != currentNotes . at (
                                 channel ) . end () )
    {
        currentNotes . at (
                           channel ) . erase (
                                              f );
        notesChanged . at (
                           channel ) = true;
    }
}

void
    Recorder::onNoteOn (
            const unsigned channel
          , const unsigned note
          , const unsigned velocity
            )
{
    const auto f = std::find (
                              currentNotes . at (
                                                 channel ) . begin ()
                            , currentNotes . at (
                                                 channel ) . end ()
                            , note );
    if ( f != currentNotes . at (
                                 channel ) . end () ) { return; }
    currentNotes . at (
                       channel ) . push_back (
                                              note );
    notesChanged . at (
                       channel ) = true;
}

void
    Recorder::onAttackParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentAttack . at (
                             voice ) == value ) { return; }
    RemovePendingVoice (
                        COMMANDS::CHANGE_ATTACK_DECAY
                      , voice );
    currentAttack . at (
                        voice ) = static_cast < unsigned char > ( value );
    const auto attack_decay     = std::make_shared < Command > (
                                                                COMMANDS::CHANGE_ATTACK_DECAY
                                                              , currentFrame
                                                              , std::vector < unsigned char > {
                                                                        static_cast < unsigned char > ( currentAttack . at (
                                                                                                                            voice ) << 4 | currentDecay . at (
                                                                                                                                                              voice ) )
                                                                } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    attack_decay );
}

void
    Recorder::onBandPassParameterChanged (
            const bool value
            )
{
    if ( currentBandPass == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::FILTER_MODE_VOLUME );
    currentBandPass          = value;
    auto current_filter_type = static_cast < unsigned char > ( 0 );
    if ( currentLowPass ) { current_filter_type |= 1; }
    if ( currentBandPass ) { current_filter_type |= 2; }
    if ( currentHighPass ) { current_filter_type |= 4; }
    current_filter_type *= 0x10;
    current_filter_type |= currentVolume;
    const auto set_filter_type = std::make_shared < Command > (
                                                               COMMANDS::FILTER_MODE_VOLUME
                                                             , currentFrame
                                                             , std::vector < unsigned char > {
                                                                       current_filter_type
                                                               } );
    currentGlobalCommands . push_back (
                                       set_filter_type );
}

void
    Recorder::onCutoffParameterChanged (
            const unsigned value
            )
{
    static const auto CUTOFF_BASE    = 0.9995117188;
    static const auto BINARY_BASE    = 2.0;
    static const auto CUTOFF_DIVISOR = 0.0833333333;
    static const auto CUTOFF_RANGE   = 2047.0;
    static const auto CUTOFF_OFFSET  = 0.0833333333;

    const auto        log_val        = static_cast < unsigned > ( round (
                                                                         CUTOFF_BASE * pow (
                                                                                            BINARY_BASE
                                                                                          , 1.0 / CUTOFF_DIVISOR * ( static_cast < double > ( value ) / CUTOFF_RANGE - CUTOFF_OFFSET ) ) ) ) / 0x08;
    if ( currentCutoff == log_val ) { return; }
    RemovePendingGlobal (
                         COMMANDS::CUTOFF );
    currentCutoff     = log_val;
    const auto cutoff = std::make_shared < Command > (
                                                      COMMANDS::CUTOFF
                                                    , currentFrame
                                                    , std::vector < unsigned char > {
                                                              static_cast < unsigned char > ( log_val & 0xFF )
                                                      } );
    currentGlobalCommands . push_back (
                                       cutoff );
}

void
    Recorder::onDecayParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentDecay . at (
                            voice ) == value ) { return; }
    RemovePendingVoice (
                        COMMANDS::CHANGE_ATTACK_DECAY
                      , voice );
    currentDecay . at (
                       voice ) = static_cast < unsigned char > ( value );
    const auto attack_decay    = std::make_shared < Command > (
                                                               COMMANDS::CHANGE_ATTACK_DECAY
                                                             , currentFrame
                                                             , std::vector < unsigned char > {
                                                                       static_cast < unsigned char > ( currentAttack . at (
                                                                                                                           voice ) << 4 | currentDecay . at (
                                                                                                                                                             voice ) )
                                                               } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    attack_decay );
}

void
    Recorder::onFilterVoiceParameterChanged (
            const unsigned voice
          , const bool     value
            )
{
    if ( currentVoiceFilters . at (
                                   voice ) == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::RESONANCE_ROUTING );
    currentVoiceFilters . at (
                              voice ) = value;
    auto current_voice_filters        = static_cast < unsigned char > ( 0 );
    for ( auto i = 0 ; i < 3 ; i++ )
    {
        if ( currentVoiceFilters . at (
                                       i ) ) { current_voice_filters |= 1 << i; }
    }
    current_voice_filters |= currentResonance * 0x10;
    const auto voice_filter_on_off = std::make_shared < Command > (
                                                                   COMMANDS::RESONANCE_ROUTING
                                                                 , currentFrame
                                                                 , std::vector < unsigned char > {
                                                                           current_voice_filters
                                                                   } );
    currentGlobalCommands . push_back (
                                       voice_filter_on_off );
}

void
    Recorder::onHighPassParameterChanged (
            const bool value
            )
{
    if ( currentHighPass == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::FILTER_MODE_VOLUME );
    currentHighPass          = value;
    auto current_filter_type = static_cast < unsigned char > ( 0 );
    if ( currentLowPass ) { current_filter_type |= 1; }
    if ( currentBandPass ) { current_filter_type |= 2; }
    if ( currentHighPass ) { current_filter_type |= 4; }
    current_filter_type *= 0x10;
    current_filter_type |= currentVolume;
    const auto set_filter_type = std::make_shared < Command > (
                                                               COMMANDS::FILTER_MODE_VOLUME
                                                             , currentFrame
                                                             , std::vector < unsigned char > {
                                                                       current_filter_type
                                                               } );
    currentGlobalCommands . push_back (
                                       set_filter_type );
}

void
    Recorder::onLowPassParameterChanged (
            const bool value
            )
{
    if ( currentLowPass == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::FILTER_MODE_VOLUME );
    currentLowPass           = value;
    auto current_filter_type = static_cast < unsigned char > ( 0 );
    if ( currentLowPass ) { current_filter_type |= 1; }
    if ( currentBandPass ) { current_filter_type |= 2; }
    if ( currentHighPass ) { current_filter_type |= 4; }
    current_filter_type *= 0x10;
    current_filter_type |= currentVolume;
    const auto set_filter_type = std::make_shared < Command > (
                                                               COMMANDS::FILTER_MODE_VOLUME
                                                             , currentFrame
                                                             , std::vector < unsigned char > {
                                                                       current_filter_type
                                                               } );
    currentGlobalCommands . push_back (
                                       set_filter_type );
}

void
    Recorder::onPitchBendParameterChanged (
            const unsigned voice
          , const float    value
            )
{
    if ( currentPitchBend == value ) { return; }
    currentPitchBend = value;
    RemovePendingVoice (
                        COMMANDS::PITCH_BEND
                      , voice );
    const auto p = programs . at (
                                  voice );
    if ( p == nullptr ) { return; }
    const auto e  = p -> GetExpression ();
    const auto pb = static_cast < unsigned short > ( e -> getPitchBend () * static_cast < float > ( e -> getPitchBendRange () ) );

    // So, now we have the pitch bend, as a floating point octave offset.  This
    // is completely dependent on the note being played, which makes this a
    // little tricky to implement... especially if it's an arp or something.
    // What to do, what to do.  For now, I'm actually just writing the raw PB
    // value
    const auto pitch_bend = std::make_shared < Command > (
                                                          COMMANDS::PITCH_BEND
                                                        , currentFrame
                                                        , std::vector < unsigned char > {
                                                                  static_cast < unsigned char > ( pb & 0xFF )
                                                                , static_cast < unsigned char > ( ( pb & 0xFF00 ) >> 8 )
                                                          } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    pitch_bend );
}

void
    Recorder::onLoadLivePatch (
            const unsigned                                 voice
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    // This never gets called, which is probably to be expected.
    programs . at (
                   voice ) = program;

    // This will probably also need to reset any live changes to ADSR and the like.
    currentAttack [ voice ]  = program -> GetEnvelope () -> getAttack ();
    currentDecay [ voice ]   = program -> GetEnvelope () -> getDecay ();
    currentSustain [ voice ] = program -> GetEnvelope () -> getSustain ();
    currentRelease [ voice ] = program -> GetEnvelope () -> getRelease ();
}

void
    Recorder::onProgramParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentProgram . at (
                              voice ) == value ) { return; }
    RemovePendingVoice (
                        COMMANDS::PROGRAM_CHANGE
                      , voice );
    currentProgram . at (
                         voice ) = value;
    const auto program_change    = std::make_shared < Command > (
                                                                 COMMANDS::PROGRAM_CHANGE
                                                               , currentFrame
                                                               , std::vector < unsigned char > {
                                                                         static_cast < unsigned char > ( value )
                                                                 } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    program_change );
    const auto program       = programList [ value ];
    currentAttack [ voice ]  = program -> GetEnvelope () -> getDefaultAttack ();
    currentDecay [ voice ]   = program -> GetEnvelope () -> getDefaultDecay ();
    currentSustain [ voice ] = program -> GetEnvelope () -> getDefaultSustain ();
    currentRelease [ voice ] = program -> GetEnvelope () -> getDefaultRelease ();
}

void
    Recorder::onPulseWidthParameterChanged (
            const unsigned voice
          , const float    value
            )
{
    const auto p = programs . at (
                                  voice );
    if ( p == nullptr ) { return; }
    const auto e           = p -> GetExpression ();
    const auto pulse_cycle = static_cast < int > ( value * static_cast < float > ( e -> getPulseWidthRange () ) + static_cast < float > ( e -> getPulseWidthCenter () ) );
    const auto pulse_value = pulse_cycle - 2048;
    if ( currentPulseWidth == pulse_value ) { return; }
    currentPulseWidth = pulse_value;
    RemovePendingVoice (
                        COMMANDS::PULSE_WIDTH
                      , voice );
    const auto pulse_width = std::make_shared < Command > (
                                                           COMMANDS::PULSE_WIDTH
                                                         , currentFrame
                                                         , std::vector < unsigned char > {
                                                                   static_cast < unsigned char > ( pulse_value & 0xFF )
                                                                 , static_cast < unsigned char > ( ( pulse_value & 0xFF00 ) >> 8 )
                                                           } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    pulse_width );
}

void
    Recorder::onReleaseParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentRelease . at (
                              voice ) == value ) { return; }
    RemovePendingVoice (
                        COMMANDS::PULSE_WIDTH
                      , voice );
    currentRelease . at (
                         voice ) = static_cast < unsigned char > ( value * 0xF );
    const auto sustain_release   = std::make_shared < Command > (
                                                                 COMMANDS::CHANGE_SUSTAIN_RELEASE
                                                               , currentFrame
                                                               , std::vector < unsigned char > {
                                                                         static_cast < unsigned char > ( currentSustain . at (
                                                                                                                              voice ) << 4 | currentRelease . at (
                                                                                                                                                                  voice ) )
                                                                 } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    sustain_release );
}

void
    Recorder::onResonanceParameterChanged (
            const unsigned value
            )
{
    if ( currentResonance == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::RESONANCE_ROUTING );
    currentResonance     = value;
    auto current_resonance_routing = static_cast < unsigned char > ( 0 );
    for ( auto i = 0 ; i < 3 ; i++ )
    {
        if ( currentVoiceFilters . at (
                                       i ) ) { current_resonance_routing |= 1 << i; }
    }
    current_resonance_routing |= currentResonance * 0x10;
    const auto resonance = std::make_shared < Command > (
                                                         COMMANDS::RESONANCE_ROUTING
                                                       , currentFrame
                                                       , std::vector < unsigned char > {
                                                                 static_cast < unsigned char > ( current_resonance_routing )
                                                         } );
    currentGlobalCommands . push_back (
                                       resonance );
}

void
    Recorder::onSustainParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentSustain . at (
                              voice ) == value ) { return; }
    RemovePendingVoice (
                        COMMANDS::CHANGE_SUSTAIN_RELEASE
                      , voice );
    currentSustain . at (
                         voice ) = static_cast < unsigned char > ( value * 0xF );
    const auto sustain_release   = std::make_shared < Command > (
                                                                 COMMANDS::CHANGE_SUSTAIN_RELEASE
                                                               , currentFrame
                                                               , std::vector < unsigned char > {
                                                                         static_cast < unsigned char > ( currentSustain . at (
                                                                                                                              voice ) << 4 | currentRelease . at (
                                                                                                                                                                  voice ) )
                                                                 } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    sustain_release );
}

void
    Recorder::onVibratoAmountParameterChanged (
            const unsigned voice
          , const float    value
            )
{
    const auto p = programs . at (
                                  voice );
    if ( p == nullptr ) { return; }
    const auto e  = p -> GetExpression ();
    const auto v  = e -> getVibrato ();
    const auto va = static_cast < unsigned short > ( value * static_cast < float > ( v -> GetVibratoRange () ) );
    if ( currentVibratoAmount == va ) { return; }
    currentVibratoAmount = va;
    RemovePendingVoice (
                        COMMANDS::VIBRATO_AMOUNT
                      , voice );
    const auto vibrato_amount = std::make_shared < Command > (
                                                              COMMANDS::VIBRATO_AMOUNT
                                                            , currentFrame
                                                            , std::vector < unsigned char > {
                                                                      static_cast < unsigned char > ( va & 0xFF )
                                                                    , static_cast < unsigned char > ( ( va & 0xFF00 ) >> 8 )
                                                              } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    vibrato_amount );
}

void
    Recorder::onVibratoDelayParameterChanged (
            const unsigned voice
          , const unsigned value
            )
{
    if ( currentVibratoDelay == value ) { return; }
    currentVibratoDelay = value;
    RemovePendingVoice (
                        COMMANDS::VIBRATO_DELAY
                      , voice );
    const auto vibrato_delay = std::make_shared < Command > (
                                                             COMMANDS::VIBRATO_DELAY
                                                           , currentFrame
                                                           , std::vector < unsigned char > {
                                                                     static_cast < unsigned char > ( value & 0xFF )
                                                             } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    vibrato_delay );
}

void
    Recorder::onVibratoSpeedParameterChanged (
            const unsigned voice
          , const float    value
            )
{
    const auto p = programs . at (
                                  voice );
    if ( p == nullptr ) { return; }
    const auto e  = p -> GetExpression ();
    const auto v  = e -> getVibrato ();
    const auto vs = static_cast < unsigned short > ( value * static_cast < float > ( v -> GetVibratoSpeed () ) );
    if ( currentVibratoSpeed == vs ) { return; }
    currentVibratoSpeed = vs;
    RemovePendingVoice (
                        COMMANDS::VIBRATO_SPEED
                      , voice );
    const auto vibrato_speed = std::make_shared < Command > (
                                                             COMMANDS::VIBRATO_SPEED
                                                           , currentFrame
                                                           , std::vector < unsigned char > {
                                                                     static_cast < unsigned char > ( vs & 0xFF )
                                                             } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    vibrato_speed );
}

void
    Recorder::onVolumeParameterChanged (
            const unsigned value
            )
{
    if ( currentVolume == value ) { return; }
    RemovePendingGlobal (
                         COMMANDS::FILTER_MODE_VOLUME );
    currentVolume     = value;
    auto current_filter_type = static_cast < unsigned char > ( 0 );
    if ( currentLowPass ) { current_filter_type |= 1; }
    if ( currentBandPass ) { current_filter_type |= 2; }
    if ( currentHighPass ) { current_filter_type |= 4; }
    current_filter_type *= 0x10;
    current_filter_type |= currentVolume;
    const auto volume = std::make_shared < Command > (
                                                      COMMANDS::FILTER_MODE_VOLUME
                                                    , currentFrame
                                                    , std::vector < unsigned char > {
                                                              static_cast < unsigned char > ( current_filter_type )
                                                      } );
    currentGlobalCommands . push_back (
                                       volume );
}

void
    Recorder::onQuarterNoteTick (
            const unsigned ppq
            )
{
    if ( ppq == static_cast < unsigned > ( currentPpq ) ) { return; }
    currentPpq = static_cast < int > ( ppq );
    if ( ppq % 4 == 0 )
    {
        patternIndexes . push_back (
                                    {
                                            globalCommands . size ()
                                          , voiceCommands . at (
                                                                0 ) . size ()
                                          , voiceCommands . at (
                                                                1 ) . size ()
                                          , voiceCommands . at (
                                                                2 ) . size ()
                                    } );
        if ( currentFrame == 0x780 )
        {
            var i = 0;
        }
        if ( patternFrame . empty () || patternFrame . at (
                                                           patternFrame . size () - 1 ) != currentFrame )
        {
            patternFrame . push_back (
                                      currentFrame );
        }
    }
}

void
    Recorder::SetLoopPoints (
            const int start
          , const int end
            )
{
    loopStart = start;
    loopEnd = end;
}

//void
//    Recorder::SetLoopStart ()
//{
//    loopStart = currentFrame;
//}
//
//void
//    Recorder::SetLoopEnd ()
//{
//    loopEnd = currentFrame;
//}

void
    Recorder::RemovePendingGlobal (
            const COMMANDS type
            )
{
    const auto f = std::find_if (
                                 currentGlobalCommands . begin ()
                               , currentGlobalCommands . end ()
                               , [type] (
                                 const std::shared_ptr < Command >& c
                                 )
                                 {
                                     return c -> GetType () == type;
                                 } );
    if ( f != currentGlobalCommands . end () )
    {
        currentGlobalCommands . erase (
                                       f );
    }
}

void
    Recorder::RemovePendingVoice (
            const COMMANDS type
          , const unsigned voice
            )
{
    const auto f = std::find_if (
                                 currentVoiceCommands . at (
                                                            voice ) . begin ()
                               , currentVoiceCommands . at (
                                                            voice ) . end ()
                               , [type] (
                                 const std::shared_ptr < Command >& c
                                 )
                                 {
                                     return c -> GetType () == type;
                                 } );
    if ( f != currentVoiceCommands . at (
                                         voice ) . end () )
    {
        currentVoiceCommands . at (
                                   voice ) . erase (
                                                    f );
    }
}
