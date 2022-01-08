#include "Exporter.h"

#include "Command.h"
#include "Recorder.h"

Exporter::Exporter (
        std::shared_ptr < Recorder >& record
        )
    :
    recording (
               record ) { }

auto
    Exporter::BuildPattern (
            const unsigned                                     first_frame
          , const int                                          last_frame
          , const std::vector < std::shared_ptr < Command > >& temp_pattern
            ) const -> std::vector < std::shared_ptr < Command > >
{
    auto new_pattern        = std::vector < std::shared_ptr < Command > > ();
    auto current_frame = 0;
    auto last_command_frame = 0;
    for ( const auto& command : temp_pattern )
    {
        const auto current_time = command -> GetTime () - static_cast < long > ( first_frame );
        _ASSERT (
                 current_time >= 0 );
        while ( static_cast < long > ( current_time ) > static_cast < long > ( current_frame ) )
        {
            const auto new_delay = current_time - current_frame > 255
                                       ? 255
                                       : current_time - current_frame;
            const auto delay = std::make_shared < Command > (
                                                             COMMANDS::DELAY
                                                           , last_command_frame
                                                           , std::vector < unsigned char > {
                                                                     static_cast < unsigned char > ( new_delay )
                                                             } );
            new_pattern . push_back (
                                     delay );
            // insert delay
            last_command_frame = current_frame;
            current_frame += new_delay;
        }
        current_frame = current_time;
        last_command_frame = current_frame;
        const auto new_command = std::make_shared < Command > (
                                                               command -> GetType ()
                                                             , current_frame
                                                             , command -> Render () );
        new_pattern . push_back (
                                 new_command );
    }
    while ( last_frame != -1 && static_cast < int > ( last_frame - first_frame ) > static_cast < int > ( current_frame ) )
    {
        const auto new_delay = last_frame - first_frame - current_frame > 255
                                   ? 255
                                   : last_frame - first_frame - current_frame;
        const auto delay = std::make_shared < Command > (
                                                         COMMANDS::DELAY
                                                       , last_command_frame
                                                       , std::vector < unsigned char > {
                                                                 static_cast < unsigned char > ( new_delay )
                                                         } );
        new_pattern . push_back (
                                 delay );
        // insert delay
        last_command_frame = current_frame;
        current_frame += new_delay;
    }

    return new_pattern;
}

void
    Exporter::AddOrReusePattern (
            std::vector < std::shared_ptr < Command > >& new_pattern
          , std::vector < int >&                         pattern_list
            )
{
    for ( size_t i = 0 ; i < patterns . size () ; i++ )
    {
        if ( patterns . at (
                            i ) . size () != new_pattern . size () ) { continue; }
        size_t j = 0;
        for ( ; j < new_pattern . size () ; j++ )
        {
            auto command = patterns . at (
                                          i ) . at (
                                                    j );
            auto new_command = new_pattern . at (
                                                 j );
            if ( *command != *new_command ) { break; }
        }
        if ( j == new_pattern . size () )
        {
            pattern_list . push_back (
                                      static_cast < int > ( i ) );
            return;
        }
    }
    patterns . push_back (
                          new_pattern );
    pattern_list . push_back (
                              static_cast < int > ( patterns . size () ) - 1 );
}

void
    Exporter::ToPatterns ()
{
    const auto total_patterns = static_cast < int > ( recording -> patternFrame . size () );

    for ( auto pattern_index = 0 ; pattern_index < total_patterns ; pattern_index++ )
    {
        const auto first_frame = recording -> patternFrame . at (
                                                                 pattern_index );
        const auto last_frame = pattern_index < total_patterns - 1
                                    ? static_cast < int > ( recording -> patternFrame . at (
                                                                                            static_cast < size_t > ( pattern_index ) + 1 ) )
                                    : -1;
        // global
        {
            size_t i = 0;
            for ( ; i < recording -> globalCommands . size () ; i++ )
            {
                if ( recording -> globalCommands . at (
                                                       i ) -> GetTime () >= static_cast < long > ( first_frame ) )
                {
                    break;
                }
            }
            const auto pattern_lookup = i;
            for ( ; i < recording -> globalCommands . size () ; i++ )
            {
                if ( recording -> globalCommands . at (
                                                       i ) -> GetTime () > static_cast < long > ( last_frame ) )
                {
                    if ( i > pattern_lookup )
                    {
                        --i;
                    }
                    break;
                }
            }
            const auto pattern_lookup_end = i;
            //if ( static_cast < size_t > ( pattern_index ) + 1 < recording -> patternIndexes . size () )
            //{
            //    pattern_lookup_end = recording -> patternIndexes . at (
            //                                                           static_cast < size_t > ( pattern_index ) + 1 ) . at (
            //                                                                                                                0 ) + pattern_lookup;
            //    if ( pattern_lookup_end > recording -> globalCommands . size () ) { pattern_lookup_end = pattern_lookup; }
            //}
            //if ( pattern_index + 1 > static_cast < int > ( total_patterns ) )
            //{
            //    pattern_lookup_end = recording -> patternIndexes . at (
            //                                                           static_cast < size_t > ( pattern_index ) + 1 ) . at (
            //                                                                                                                0 );
            //}
            const auto temp_pattern = std::vector < std::shared_ptr < Command > > (
                                                                                   recording -> globalCommands . begin () + pattern_lookup
                                                                                 , recording -> globalCommands . begin () + pattern_lookup_end );
            auto new_pattern = BuildPattern (
                                             first_frame
                                           , last_frame
                                           , temp_pattern );
            AddOrReusePattern (
                               new_pattern
                             , globalPatternList );
        }

        for ( auto channel = 0 ; channel < 3 ; channel++ )
        {
            // channel
            //const auto pattern_lookup = recording -> patternIndexes . at (
            //                                                              pattern_index ) . at (
            //                                                                                    channel + 1 );
            //auto pattern_lookup_end = pattern_lookup;
            //if ( static_cast < size_t > ( pattern_index ) + 1 < recording -> patternIndexes . size () )
            //{
            //    pattern_lookup_end = recording -> patternIndexes . at (
            //                                                           static_cast < size_t > ( pattern_index ) + 1 ) . at (
            //                                                                                                                channel + 1 );
            //    if ( pattern_lookup_end > recording -> voiceCommands . at (
            //                                                               channel ) . size () ) { pattern_lookup_end = pattern_lookup; }
            //}
            //if ( pattern_index + 1 > static_cast < int > ( total_patterns ) )
            //{
            //    pattern_lookup_end = recording -> patternIndexes . at (
            //                                                           static_cast < size_t > ( pattern_index ) + 1 ) . at (
            //                                                                                                                channel + 1 );
            //}
            size_t i = 0;
            for ( ; i < recording -> voiceCommands . at (
                                                         channel ) . size () ; i++ )
            {
                if ( recording -> voiceCommands . at (
                                                      channel ) . at (
                                                                      i ) -> GetTime () > static_cast < long > ( first_frame ) ) { break; }
            }
            const auto pattern_lookup = i;
            for ( ; i < recording -> voiceCommands . at (
                                                         channel ) . size () ; i++ )
            {
                if ( recording -> voiceCommands . at (
                                                      channel ) . at (
                                                                      i ) -> GetTime () >= static_cast < long > ( last_frame ) )
                {
                    if ( i > pattern_lookup ) { --i; }
                    break;
                }
            }
            const auto pattern_lookup_end = i;
            const auto temp_pattern = std::vector < std::shared_ptr < Command > > (
                                                                                   recording -> voiceCommands . at (
                                                                                                                    channel ) . begin () + pattern_lookup
                                                                                 , recording -> voiceCommands . at (
                                                                                                                    channel ) . begin () + pattern_lookup_end );
            auto new_pattern = BuildPattern (
                                             first_frame
                                           , last_frame
                                           , temp_pattern );
            AddOrReusePattern (
                               new_pattern
                             , voicePatternList . at (
                                                      channel ) );
        }
    }
    const auto file = fopen (
                             "C:\\temp\\export.txt"
                           , "wt" );
    String str = "global_patterns:\n";
    fwrite (
            str . toStdString () . c_str ()
          , 1
          , str . length ()
          , file );
    for ( const auto val : globalPatternList )
    {
        str = String::toHexString (
                                   val ) . paddedLeft (
                                                       '0'
                                                     , 2 ) + "\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
    }
    str = "\n";
    fwrite (
            str . toStdString () . c_str ()
          , 1
          , str . length ()
          , file );
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        str = "voice_patterns_" + String::toHexString (
                                                       v + 1 ) + "\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
        for ( const auto& val : voicePatternList . at (
                                                       v ) )
        {
            str = String::toHexString (
                                       val ) . paddedLeft (
                                                           '0'
                                                         , 2 ) + "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
        }
        str = "\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
    }
    for ( size_t pi = 0 ; pi < patterns . size () ; pi++ )
    {
        const auto p = patterns . at (
                                      pi );
        str = "pattern_" + String::toHexString (
                                                static_cast < long long > ( pi ) ) + ":\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
        for ( const auto& c : p )
        {
            str = String::toHexString (
                                       c -> GetTime () ) . paddedLeft (
                                                                       '0'
                                                                     , 2 ) + "\t";
            switch ( c -> GetType () )
            {
                case COMMANDS::VOICE_FILTER_ON_OFF:
                    str += "VOICE_FILTER_ON_OFF ";
                    break;
                case COMMANDS::CUTOFF:
                    str += "CUTOFF ";
                    break;
                case COMMANDS::RESONANCE:
                    str += "RESONANCE ";
                    break;
                case COMMANDS::SET_FILTER_TYPE:
                    str += "SET_FILTER_TYPE ";
                    break;
                case COMMANDS::VOLUME:
                    str += "VOLUME ";
                    break;
                case COMMANDS::DELAY:
                    str += "DELAY ";
                    break;
                case COMMANDS::PROGRAM_CHANGE:
                    str += "PROGRAM_CHANGE ";
                    break;
                case COMMANDS::NOTE_ON:
                    str += "NOTE_ON ";
                    break;
                case COMMANDS::NOTE_OFF:
                    str += "NOTE_OFF ";
                    break;
                case COMMANDS::PITCH_BEND:
                    str += "PITCH_BEND ";
                    break;
                case COMMANDS::PULSE_WIDTH:
                    str += "PULSE_WIDTH ";
                    break;
                case COMMANDS::CHANGE_ATTACK_DECAY:
                    str += "CHANGE_ATTACK_DECAY ";
                    break;
                case COMMANDS::CHANGE_SUSTAIN_RELEASE:
                    str += "CHANGE_SUSTAIN_RELEASE ";
                    break;
                case COMMANDS::VIBRATO_AMOUNT:
                    str += "VIBRATO_AMOUNT ";
                    break;
                case COMMANDS::VIBRATO_SPEED:
                    str += "VIBRATO_SPEED ";
                    break;
                case COMMANDS::VIBRATO_DELAY:
                    str += "VIBRATO_DELAY ";
                    break;
                default:
                    str += "ERROR ";
            }
            for ( const auto val : c -> Render () )
            {
                str += String::toHexString (
                                            val ) . paddedLeft (
                                                                '0'
                                                              , 2 ) + " ";
            }
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
        }
        str = "\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
    }
    fclose (
            file );
}
