#include "Exporter.h"
#include "Command.h"
#include "Recorder.h"
#include "SIDProgram.h"

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
    auto current_frame      = 0;
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
        current_frame          = current_time;
        last_command_frame     = current_frame;
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
    Exporter::ToPatterns (
            std::string title
          , std::string artist
            ) const
{
    FileChooser file_browser (
                              "Save SIDStep2 Export Data" );
    if ( file_browser . browseForFileToSave (
                                             true ) )
    {
        const auto filename = file_browser . getResult () . getFullPathName ();
        const auto file     = fopen (
                                     filename . toRawUTF8 ()
                                   , "wt" );
        String str = title + "\n" + artist + "\nglobal_commands:\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
        size_t frame_index = 0;
        auto   bar_start   = 0;
        for ( const auto& c : recording -> globalCommands )
        {
            str = "";
            while ( frame_index + 1 < recording -> patternFrame . size () && c -> GetTime () >= static_cast < long > ( recording -> patternFrame . at (
                                                                                                                                                       frame_index ) ) )
            {
                str += "# Bar " + String::toHexString (
                                                       static_cast < int > ( frame_index ) ) . paddedLeft (
                                                                                                           '0'
                                                                                                         , 2 ) + " (" + String::toHexString (
                                                                                                                                             static_cast < int > ( recording -> patternFrame . at (
                                                                                                                                                                                                   frame_index ) ) ) . paddedLeft (
                                                                                                                                                                                                                                   '0'
                                                                                                                                                                                                                                 , 4 ) + ")\n";
                bar_start = static_cast < long > ( recording -> patternFrame . at (
                                                                                   frame_index ) );
                frame_index++;
            }
            str += String::toHexString (
                                        c -> GetTime () - bar_start ) . paddedLeft (
                                                                                    '0'
                                                                                  , 4 ) + ",";
            switch ( c -> GetType () )
            {
                    //case COMMANDS::VOICE_FILTER_ON_OFF:
                    //    str += "VOICE_FILTER_ON_OFF";
                    //    break;
                case COMMANDS::CUTOFF:
                    str += "CUTOFF";
                    break;
                    //case COMMANDS::RESONANCE:
                    //    str += "RESONANCE";
                    //    break;
                    //case COMMANDS::SET_FILTER_TYPE:
                    //    str += "SET_FILTER_TYPE";
                    //    break;
                    //case COMMANDS::VOLUME:
                    //    str += "VOLUME";
                    //    break;
                case COMMANDS::DELAY:
                    str += "DELAY";
                    break;
                case COMMANDS::PROGRAM_CHANGE:
                    str += "PROGRAM_CHANGE";
                    break;
                case COMMANDS::NOTE_ON:
                    str += "NOTE_ON";
                    break;
                case COMMANDS::NOTE_OFF:
                    str += "NOTE_OFF";
                    break;
                case COMMANDS::PITCH_BEND:
                    str += "PITCH_BEND";
                    break;
                case COMMANDS::PULSE_WIDTH:
                    str += "PULSE_WIDTH";
                    break;
                case COMMANDS::CHANGE_ATTACK_DECAY:
                    str += "CHANGE_ATTACK_DECAY";
                    break;
                case COMMANDS::CHANGE_SUSTAIN_RELEASE:
                    str += "CHANGE_SUSTAIN_RELEASE";
                    break;
                case COMMANDS::VIBRATO_AMOUNT:
                    str += "VIBRATO_AMOUNT";
                    break;
                case COMMANDS::VIBRATO_SPEED:
                    str += "VIBRATO_SPEED";
                    break;
                case COMMANDS::VIBRATO_DELAY:
                    str += "VIBRATO_DELAY";
                    break;
                case COMMANDS::RESONANCE_ROUTING:
                    str += "RESONANCE_ROUTING";
                    break;
                case COMMANDS::FILTER_MODE_VOLUME:
                    str += "FILTER_MODE_VOLUME";
                    break;
                default:
                    str += "ERROR";
            }
            for ( const auto val : c -> Render () )
            {
                str += "," + String::toHexString (
                                                  val ) . paddedLeft (
                                                                      '0'
                                                                    , 2 );
            }
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
        }
        for ( auto v = 0 ; v < 3 ; v++ )
        {
            str = "voice_" + String::toHexString (
                                                  v ) + "_commands:\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
            frame_index = 0;
            bar_start   = 0;
            for ( const auto& c : recording -> voiceCommands . at (
                                                                   v ) )
            {
                str = "";
                while ( frame_index + 1 < recording -> patternFrame . size () && c -> GetTime () >= static_cast < long > ( recording -> patternFrame . at (
                                                                                                                                                           frame_index ) ) )
                {
                    str += "# Bar " + String::toHexString (
                                                           static_cast < int > ( frame_index ) ) . paddedLeft (
                                                                                                               '0'
                                                                                                             , 2 ) + " (" + String::toHexString (
                                                                                                                                                 static_cast < int > ( recording -> patternFrame . at (
                                                                                                                                                                                                       frame_index ) ) ) . paddedLeft (
                                                                                                                                                                                                                                       '0'
                                                                                                                                                                                                                                     , 4 ) + ")\n";
                    bar_start = static_cast < long > ( recording -> patternFrame . at (
                                                                                       frame_index ) );
                    frame_index++;
                }
                str += String::toHexString (
                                            c -> GetTime () - bar_start ) . paddedLeft (
                                                                                        '0'
                                                                                      , 4 ) + ",";
                switch ( c -> GetType () )
                {
                        //case COMMANDS::VOICE_FILTER_ON_OFF:
                        //    str += "VOICE_FILTER_ON_OFF";
                        //    break;
                    case COMMANDS::CUTOFF:
                        str += "CUTOFF";
                        break;
                        //case COMMANDS::RESONANCE:
                        //    str += "RESONANCE";
                        //    break;
                        //case COMMANDS::SET_FILTER_TYPE:
                        //    str += "SET_FILTER_TYPE";
                        //    break;
                        //case COMMANDS::VOLUME:
                        //    str += "VOLUME";
                        //    break;
                    case COMMANDS::DELAY:
                        str += "DELAY";
                        break;
                    case COMMANDS::PROGRAM_CHANGE:
                        str += "PROGRAM_CHANGE";
                        break;
                    case COMMANDS::NOTE_ON:
                        str += "NOTE_ON";
                        break;
                    case COMMANDS::NOTE_OFF:
                        str += "NOTE_OFF";
                        break;
                    case COMMANDS::PITCH_BEND:
                        str += "PITCH_BEND";
                        break;
                    case COMMANDS::PULSE_WIDTH:
                        str += "PULSE_WIDTH";
                        break;
                    case COMMANDS::CHANGE_ATTACK_DECAY:
                        str += "CHANGE_ATTACK_DECAY";
                        break;
                    case COMMANDS::CHANGE_SUSTAIN_RELEASE:
                        str += "CHANGE_SUSTAIN_RELEASE";
                        break;
                    case COMMANDS::VIBRATO_AMOUNT:
                        str += "VIBRATO_AMOUNT";
                        break;
                    case COMMANDS::VIBRATO_SPEED:
                        str += "VIBRATO_SPEED";
                        break;
                    case COMMANDS::VIBRATO_DELAY:
                        str += "VIBRATO_DELAY";
                        break;
                    case COMMANDS::RESONANCE_ROUTING:
                        str += "RESONANCE_ROUTING";
                        break;
                    case COMMANDS::FILTER_MODE_VOLUME:
                        str += "FILTER_MODE_VOLUME";
                        break;
                    default:
                        str += "ERROR";
                }
                for ( const auto val : c -> Render () )
                {
                    str += "," + String::toHexString (
                                                      val ) . paddedLeft (
                                                                          '0'
                                                                        , 2 );
                }
                str += "\n";
                fwrite (
                        str . toStdString () . c_str ()
                      , 1
                      , str . length ()
                      , file );
            }
        }
        str = "bars:\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
        for ( auto frame : recording -> patternFrame )
        {
            str = String::toHexString (
                                       static_cast < int > ( frame ) ) . paddedLeft (
                                                                                     '0'
                                                                                   , 4 ) + "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
        }
        str = "programs:\n";
        fwrite (
                str . toStdString () . c_str ()
              , 1
              , str . length ()
              , file );
        for ( const auto& patch : recording -> programList )
        {
            const auto& env = patch -> GetEnvelope ();
            str             = String::toHexString (
                                                   static_cast < int > ( env -> getDefaultAttack () << 4 | env -> getDefaultDecay () ) ) . paddedLeft (
                                                                                                                                                       '0'
                                                                                                                                                     , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( env -> getDefaultSustain () << 4 | env -> getDefaultRelease () ) ) . paddedLeft (
                                                                                                                                               '0'
                                                                                                                                             , 2 );
            str += ",";
            const auto& exp = patch -> GetExpression ();
            str += String::toHexString (
                                        static_cast < int > ( exp -> getPitchBendRange () & 0xFF ) ) . paddedLeft (
                                                                                                                   '0'
                                                                                                                 , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( ( exp -> getPitchBendRange () & 0xFF00 ) >> 8 ) ) . paddedLeft (
                                                                                                                              '0'
                                                                                                                            , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( exp -> getPulseWidthRange () & 0xFF ) ) . paddedLeft (
                                                                                                                    '0'
                                                                                                                  , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( ( exp -> getPulseWidthRange () & 0xFF00 ) >> 8 ) ) . paddedLeft (
                                                                                                                               '0'
                                                                                                                             , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( exp -> getPulseWidthCenter () & 0xFF ) ) . paddedLeft (
                                                                                                                     '0'
                                                                                                                   , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( ( exp -> getPulseWidthCenter () & 0xFF00 ) >> 8 ) ) . paddedLeft (
                                                                                                                                '0'
                                                                                                                              , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( exp -> getPulseWidthDefault () * 128 ) ) . paddedLeft (
                                                                                                                     '0'
                                                                                                                   , 2 );
            str += ",";
            const auto& vib = exp -> getVibrato ();
            str += String::toHexString (
                                        static_cast < int > ( vib -> GetVibratoRange () ) ) . paddedLeft (
                                                                                                          '0'
                                                                                                        , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( vib -> GetVibratoSpeed () ) ) . paddedLeft (
                                                                                                          '0'
                                                                                                        , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( vib -> GetDefaultVibratoAmount () ) ) . paddedLeft (
                                                                                                                  '0'
                                                                                                                , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( vib -> GetDefaultVibratoSpeed () ) ) . paddedLeft (
                                                                                                                 '0'
                                                                                                               , 2 );
            str += ",";
            str += String::toHexString (
                                        static_cast < int > ( vib -> GetVibratoDelay () ) ) . paddedLeft (
                                                                                                          '0'
                                                                                                        , 2 );
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
            const auto& wt = patch -> GetWavetable ();
            str            = "";
            for ( size_t i = 0 ; i < wt -> GetWaveTableSize () ; i++ )
            {
                const auto entry = wt -> GetWaveTableEntryAt (
                                                              i );
                if ( entry < 0x100 )
                {
                    str += String::toHexString (
                                                static_cast < int > ( entry ) ) . paddedLeft (
                                                                                              '0'
                                                                                            , 2 );
                    str += ",";
                }
                else
                {
                    if ( ( entry & 0x100 ) == 0x100 ) { str += "END"; }
                    else if ( ( entry & 0x200 ) == 0x200 )
                    {
                        str += "GOTO " + String::toHexString (
                                                              static_cast < int > ( entry & 0xFF ) ) . paddedLeft (
                                                                                                                   '0'
                                                                                                                 , 2 );
                    }
                    else if ( ( entry & 0x400 ) == 0x400 )
                    {
                        str += "SUSTAIN_TO " + String::toHexString (
                                                                    static_cast < int > ( entry & 0xFF ) ) . paddedLeft (
                                                                                                                         '0'
                                                                                                                       , 2 );
                    }
                    str += ",";
                }
            }
            if ( str . length () > 0 )
            {
                str = str . substring (
                                       0
                                     , str . length () - 1 );
            }
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
            const auto& nt = patch -> GetNoteTable ();
            str            = "";
            for ( size_t i = 0 ; i < nt -> GetNoteTableSize () ; i++ )
            {
                const auto& entry = nt -> GetNoteTableEntryAt (
                                                               i );
                switch ( entry . rowType )
                {
                    case RELATIVE:
                        if ( entry . value >= 0 ) { str += "+"; }
                        str += String::toHexString (
                                                    entry . value ) . paddedLeft (
                                                                                  '0'
                                                                                , 2 );
                        break;
                    case ABSOLUTE:
                        str += String::toHexString (
                                                    entry . value ) . paddedLeft (
                                                                                  '0'
                                                                                , 4 );
                        break;
                    case COMMAND:
                        if ( ( entry . value & 0x100 ) == 0x100 )
                        {
                            str += "END";
                            break;
                        }
                        if ( ( entry . value & 0x200 ) == 0x200 ) { str += "GOTO "; }
                        else
                            if ( ( entry . value & 0x400 ) == 0x400 ) { str += "SUSTAIN_TO "; }
                        str += String::toHexString (
                                                    entry . value & 0xFF ) . paddedLeft (
                                                                                         '0'
                                                                                       , 2 );
                        break;
                }
                str += ",";
            }
            if ( str . length () > 0 )
            {
                str = str . substring (
                                       0
                                     , str . length () - 1 );
            }
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
            const auto& pt = patch -> GetPulseTable ();
            str            = "";
            for ( size_t i = 0 ; i < pt -> GetPulseTableSize () ; i++ )
            {
                const auto entry = pt -> GetPulseTableEntryAt (
                                                               i );
                if ( entry < 0x1000 )
                {
                    str += String::toHexString (
                                                static_cast < int > ( entry & 0xFFF ) ) . paddedLeft (
                                                                                                      '0'
                                                                                                    , 3 );
                }
                else
                {
                    if ( ( entry & 0x1000 ) == 0x1000 ) { str += "END"; }
                    else if ( ( entry & 0x2000 ) == 0x2000 )
                    {
                        str += "GOTO " + String::toHexString (
                                                              static_cast < int > ( entry & 0xFFF ) ) . paddedLeft (
                                                                                                                    '0'
                                                                                                                  , 2 );
                    }
                    else if ( ( entry & 0x4000 ) == 0x4000 )
                    {
                        str += "SUSTAIN_TO " + String::toHexString (
                                                                    static_cast < int > ( entry & 0xFFF ) ) . paddedLeft (
                                                                                                                          '0'
                                                                                                                        , 2 );
                    }
                }
                str += ",";
            }
            if ( str . length () > 0 )
            {
                str = str . substring (
                                       0
                                     , str . length () - 1 );
            }
            str += "\n";
            fwrite (
                    str . toStdString () . c_str ()
                  , 1
                  , str . length ()
                  , file );
        }
        fclose (
                file );
    }
}
