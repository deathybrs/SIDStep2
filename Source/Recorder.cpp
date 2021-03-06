#include "Recorder.h"

#include <string>

#include "Command.h"
#include "SIDProgram.h"

#include "Programs/Expression.h"

Recorder::Recorder (
        const std::shared_ptr < EventDispatcher >         dispatcher  // NOLINT(modernize-pass-by-value, performance-unnecessary-value-param)
      , const ReferenceCountedArray < SidProgram >& patch_list
        )
    :
    dispatcher (
                dispatcher )
  , programList (
                 patch_list ) {}

void
    Recorder::Start ()
{
    dispatcher -> noteOffListeners -> add (
                                           this );
    dispatcher -> noteOnListeners -> add (
                                          this );
    dispatcher -> attackParameterChangedListeners -> add (
                                                          this );
    dispatcher -> bandPassParameterChangedListeners -> add (
                                                            this );
    dispatcher -> cutoffParameterChangedListeners -> add (
                                                          this );
    dispatcher -> decayParameterChangedListeners -> add (
                                                         this );
    dispatcher -> filterVoiceParameterChangedListeners -> add (
                                                               this );
    dispatcher -> highPassParameterChangedListeners -> add (
                                                            this );
    dispatcher -> lowPassParameterChangedListeners -> add (
                                                           this );
    dispatcher -> pitchBendParameterChangedListeners -> add (
                                                             this );
    dispatcher -> programParameterChangedListeners -> add (
                                                           this );
    dispatcher -> pulseWidthParameterChangedListeners -> add (
                                                              this );
    dispatcher -> releaseParameterChangedListeners -> add (
                                                           this );
    dispatcher -> resonanceParameterChangedListeners -> add (
                                                             this );
    dispatcher -> sustainParameterChangedListeners -> add (
                                                           this );
    dispatcher -> vibratoAmountParameterChangedListeners -> add (
                                                                 this );
    dispatcher -> vibratoDelayParameterChangedListeners -> add (
                                                                this );
    dispatcher -> vibratoSpeedParameterChangedListeners -> add (
                                                                this );
    dispatcher -> volumeParameterChangedListeners -> add (
                                                          this );
    dispatcher -> quarterNoteTickListeners -> add (
                                                   this );
    recording = true;
}

void
    Recorder::Stop ()
{
    dispatcher -> noteOffListeners -> remove (
                                              this );
    dispatcher -> noteOnListeners -> remove (
                                             this );
    dispatcher -> attackParameterChangedListeners -> remove (
                                                             this );
    dispatcher -> bandPassParameterChangedListeners -> remove (
                                                               this );
    dispatcher -> cutoffParameterChangedListeners -> remove (
                                                             this );
    dispatcher -> decayParameterChangedListeners -> remove (
                                                            this );
    dispatcher -> filterVoiceParameterChangedListeners -> remove (
                                                                  this );
    dispatcher -> highPassParameterChangedListeners -> remove (
                                                               this );
    dispatcher -> lowPassParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> pitchBendParameterChangedListeners -> remove (
                                                                this );
    dispatcher -> programParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> pulseWidthParameterChangedListeners -> remove (
                                                                 this );
    dispatcher -> releaseParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> resonanceParameterChangedListeners -> remove (
                                                                this );
    dispatcher -> sustainParameterChangedListeners -> remove (
                                                              this );
    dispatcher -> vibratoAmountParameterChangedListeners -> remove (
                                                                    this );
    dispatcher -> vibratoDelayParameterChangedListeners -> remove (
                                                                   this );
    dispatcher -> vibratoSpeedParameterChangedListeners -> remove (
                                                                   this );
    dispatcher -> volumeParameterChangedListeners -> remove (
                                                             this );
    dispatcher -> quarterNoteTickListeners -> remove (
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
    // auto log_val =
    //                  static_cast<unsigned int>(round(
    //                      cutoff_base * pow(
    //                          binary_base, 1.0 / cutoff_divisor *
    //                              ((static_cast<double>(value) / cutoff_range) - cutoff_offset)
    //                          )
    //                      )
    //                  );
    // DirtyWrite(0x15, (log_val & 0x07)); DirtyWrite(0x16, (log_val & 0x7f8) >> 3);
    static const auto CUTOFF_BASE    = 0.9995117188;
    static const auto BINARY_BASE    = 2.0;
    static const auto CUTOFF_DIVISOR = 0.0833333333;
    static const auto CUTOFF_RANGE   = 2047.0;
    static const auto CUTOFF_OFFSET  = 0.0833333333;
    auto              log_val        = static_cast < unsigned > ( round (
                                                                         CUTOFF_BASE * pow (
                                                                                            BINARY_BASE
                                                                                          , 1.0 / CUTOFF_DIVISOR * ( static_cast < double > ( value ) / CUTOFF_RANGE - CUTOFF_OFFSET ) ) ) );
    log_val = log_val & 0x7f8;
    log_val = log_val >> 3;
    if ( currentCutoff == log_val ) { return; }
    RemovePendingGlobal (
                         COMMANDS::CUTOFF );
    currentCutoff     = log_val;
    const auto cutoff = std::make_shared < Command > (
                                                      COMMANDS::CUTOFF
                                                    , currentFrame
                                                    , std::vector < unsigned char > {
                                                              static_cast < unsigned char > ( log_val )
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
    const auto p = programs . at (
                                  voice );
    if ( p == nullptr ) { return; }
    const auto e  = p -> GetExpression ();
    const auto pb = value * static_cast < float > ( e -> getPitchBendRange () ) / static_cast < float > ( 4096 );
    const auto f = 440.0 * pow (
                                2
                              , static_cast < double > ( pb ) ) - 440.0;
    if ( currentPitchBend . at ( 
                                voice ) == f ) { return; }
    currentPitchBend . at (
                           voice ) = f;
    RemovePendingVoice (
                        COMMANDS::PITCH_BEND
                      , voice );

    const auto fv = 17.02841924063789015557504303485 * f;
    const auto v  = int (
                         fv );
    const auto lv = v & 0xff;
    const auto hv = ( v & 0xff00 ) >> 8;

    // So, now we have the pitch bend, as a floating point octave offset.  This
    // is completely dependent on the note being played, which makes this a
    // little tricky to implement... especially if it's an arp or something.
    // What to do, what to do.  For now, I'm actually just writing the raw PB
    // value
    const auto pitch_bend = std::make_shared < Command > (
                                                          COMMANDS::PITCH_BEND
                                                        , currentFrame
                                                        , std::vector < unsigned char > {
                                                                  static_cast < unsigned char > ( lv )
                                                                , static_cast < unsigned char > ( hv )
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
    currentAttack . at (
                        voice ) = program -> GetEnvelope () -> getAttack ();
    currentDecay . at (
                       voice ) = program -> GetEnvelope () -> getDecay ();
    currentSustain . at (
                         voice ) = program -> GetEnvelope () -> getSustain ();
    currentRelease . at (
                         voice ) = program -> GetEnvelope () -> getRelease ();
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
    if ( !currentNotes . at (
                             voice ) . empty () )
    {
        const auto note_off = std::make_shared < Command > (
                                                            COMMANDS::NOTE_OFF
                                                          , currentFrame
                                                          , std::vector < unsigned char > () );
        voiceCommands . at (
                            voice ) . push_back (
                                                 note_off );
        currentNotes . at (
                           voice ) . clear ();
        notesChanged . at (
                           voice ) = false;
    }
    const auto program_change    = std::make_shared < Command > (
                                                                 COMMANDS::PROGRAM_CHANGE
                                                               , currentFrame
                                                               , std::vector < unsigned char > {
                                                                         static_cast < unsigned char > ( value )
                                                                 } );
    currentVoiceCommands . at (
                               voice ) . push_back (
                                                    program_change );
    const auto program = programList [ static_cast < int > ( value ) ];
    programs . at (
                   voice ) = program;
    currentAttack . at (
                        voice ) = program -> GetEnvelope () -> getDefaultAttack ();
    currentDecay . at (
                       voice ) = program -> GetEnvelope () -> getDefaultDecay ();
    currentSustain . at (
                         voice ) = program -> GetEnvelope () -> getDefaultSustain ();
    currentRelease . at (
                         voice ) = program -> GetEnvelope () -> getDefaultRelease ();
    currentPulseWidth . at (
                            voice ) = 0;
    const auto vibrato = program -> GetExpression () -> getVibrato ();
    currentVibratoAmount . at (
                               voice ) = vibrato -> GetDefaultVibratoAmount () * static_cast < float > ( vibrato -> GetVibratoRange () );
    currentVibratoSpeed . at (
                              voice ) = vibrato -> GetDefaultVibratoSpeed () * static_cast < float > ( vibrato -> GetVibratoSpeed () );
    currentVibratoDelay . at (
                              voice ) = vibrato -> GetVibratoDelay ();
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
    if ( currentPulseWidth . at (
                                 voice ) == pulse_value ) { return; }
    currentPulseWidth . at (
                            voice ) = pulse_value;
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
                         voice ) = static_cast < unsigned char > ( value );
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
    currentResonance               = value;
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
                         voice ) = static_cast < unsigned char > ( value );
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
    const auto vf = value * static_cast < float > ( v -> GetVibratoRange () );
    const auto vs = currentVibratoSpeed . at (
                                              voice );
    if ( currentVibratoAmount . at (
                                    voice ) == vf ) { return; }
    currentVibratoAmount . at (
                               voice ) = vf;
    // build vibrato table here
    std::vector < unsigned char > table;
    table . push_back (
                       static_cast < unsigned char > ( vs * 2 ) & 0xff );
    static const auto PI = 3.1415926535897932384626433832795;
    for ( size_t i = 0 ; i < vs ; i++ )
    {
        const auto time   = i / vs;
        const auto factor = sin (
                                 PI * 2 * time );
        static const auto SCALE = 17.02841924;
        const auto octaves     = vf * factor / 4096.0;
        const auto frequency = 440.0 * pow (
                                            2
                                          , octaves ) - 440.0;
        const auto calculated_value = static_cast < short > ( frequency * SCALE );
        table . push_back (
                           static_cast < unsigned char > ( calculated_value & 0xFF ) );
        table . push_back (
                           static_cast < unsigned char > ( ( calculated_value & 0xFF00 ) >> 8 ) );
    }

    RemovePendingVoice (
                        COMMANDS::VIBRATO_TABLE
                      , voice );
    const auto vibrato_amount = std::make_shared < Command > (
                                                              COMMANDS::VIBRATO_TABLE
                                                            , currentFrame
                                                            , table );
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
    if ( currentVibratoDelay . at (
                                   voice ) == value ) { return; }
    currentVibratoDelay . at (
                              voice ) = value;
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
    const auto vs = value * static_cast < float > ( v -> GetVibratoSpeed () );
    const auto vf = currentVibratoAmount . at (
                                               voice );
    if ( currentVibratoSpeed . at ( 
                                   voice ) == vs ) { return; }
    currentVibratoSpeed . at (
                              voice ) = vs;
    // build vibrato table here
    std::vector < unsigned char > table;
    table . push_back (
                       static_cast < unsigned char > ( vs * 2 ) & 0xff );
    static const auto PI2 = 3.1415926535897932384626433832795 * 2;
    for ( size_t i = 0 ; i < vs ; i++ )
    {
        const auto time   = i / vs;
        const auto factor = sin (
                                 PI2 * time );
        static const auto SCALE     = 17.02841924;
        const auto        cents     = vf * factor / 4096.0;
        const auto        frequency = 440.0 * pow (
                                                   2
                                                 , cents ) - 440.0;
        const auto calculated_value = static_cast < short > ( frequency * SCALE );
        table . push_back (
                           static_cast < unsigned char > ( calculated_value & 0xFF ) );
        table . push_back (
                           static_cast < unsigned char > ( ( calculated_value & 0xFF00 ) >> 8 ) );
    }
    RemovePendingVoice (
                        COMMANDS::VIBRATO_TABLE
                      , voice );
    const auto vibrato_speed = std::make_shared < Command > (
                                                             COMMANDS::VIBRATO_TABLE
                                                           , currentFrame
                                                           , table );
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
    currentVolume            = value;
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
          , bool           playing
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
    loopEnd   = end;
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
