#include "SIDRegisters.h"


#include <array>


#include "SIDProgram.h"


#include "../Requirements/resid-0.16/sid.h"


SidRegisters::SidRegisters ()
    :
    fileBrowser (
                 "Save SIDDump File" )
  , sid (
         new SID () )
{
    sid -> set_chip_model (
                           MOS8580 );
    sid -> enable_filter (
                          true );
    sid -> set_sampling_parameters (
                                    clock_freq
                                  , SAMPLE_FAST
                                  , sample_freq
                                  , pass_freq );
    for ( auto i = 0 ; i < last_register ; i++ )
    {
        registers . add (
                         0 );
        dirty . add (
                     false );
    }
    registers . add (
                     low_nybble_max );
    dirty . add (
                 true );
    for ( auto i = 0 ; i < 3 ; i++ )
    {
        DirtyWrite (
                    0x03 + i * 7
                  , pulse_width_default );
        notes . add (
                     new Array < Note > () );
        releasedNotes . add (
                             new Array < unsigned int > () );
        arpIndex . add (
                        -1 );
        programs . add (
                        nullptr );
        hardRestartCounter . add (
                                  -1 );
        hardRestartReleasedNotesDelay . add (
                                             new OwnedArray < Array < unsigned int > > () );
        for ( auto j = 0 ; j < 3 ; j++ )
        {
            hardRestartReleasedNotesDelay . getUnchecked (
                                                          i ) -> add (
                                                                      new Array < unsigned int > () );
        }
        hardRestartReleasedNotesDelayIndex = 0;
    }
    SharedResourcePointer < ListenerList < LiveCutoffChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LiveResonanceChanged > > () -> add (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveLowPassChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveBandPassChanged > > () -> add (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveHighPassChanged > > () -> add (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LoadLivePatch > > () -> add (
                                                                        this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> add (
                                                                                    this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> add (
                                                                                      this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < NoteOn > > () -> add (
                                                                 this );
    SharedResourcePointer < ListenerList < NoteOff > > () -> add (
                                                                  this );
    SharedResourcePointer < ListenerList < LiveExportArmed > > () -> add (
                                                                          this );
    SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> add (
                                                                           this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> add (
                                                                          this );
}

SidRegisters::~SidRegisters ()
{
    SharedResourcePointer < ListenerList < LiveCutoffChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveResonanceChanged > > () -> remove (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < LiveLowPassChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveBandPassChanged > > () -> remove (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveHighPassChanged > > () -> remove (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LoadLivePatch > > () -> remove (
                                                                           this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> remove (
                                                                                       this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> remove (
                                                                                         this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < NoteOn > > () -> remove (
                                                                    this );
    SharedResourcePointer < ListenerList < NoteOff > > () -> remove (
                                                                     this );
    SharedResourcePointer < ListenerList < LiveExportArmed > > () -> remove (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> remove (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> remove (
                                                                             this );
    sid = nullptr;
    notes . clear ();
    releasedNotes . clear ();
    arpIndex . clear ();
    registers . clear ();
    dirty . clear ();
    hardRestartReleasedNotesDelay . clear ();
}

void
    SidRegisters::SetNote (
            const unsigned int voice
          , const unsigned int note
            )
{
    if ( voice > 2 ) { return; }
    const auto p                        = programs [ static_cast < int > ( voice ) ];
    const auto e                        = p -> GetExpression ();
    const auto pb                       = e -> getPitchBend () * static_cast < float > ( e -> getPitchBendRange () ) / static_cast < float > ( binary_bit_13 );
    const auto vib                      = e -> getVibrato () -> GetCurrentVibratoValue () / binary_bit_13;
    const auto note_table               = p -> GetNoteTable ();
    const auto current_note_table_entry = note_table -> GetCurrentNoteTableEntry ();
    const auto note_offset              = current_note_table_entry . rowType == RELATIVE
                                              ? current_note_table_entry . value
                                              : 0;
    auto f = middle_a * pow (
                             2
                           , ( static_cast < double > ( note ) + static_cast < double > ( note_offset ) - note_middle_offset ) / octave + static_cast < double > ( pb ) + vib );
    if ( current_note_table_entry . rowType == ABSOLUTE ) { f = static_cast < double > ( current_note_table_entry . value ); }

    // 17.02841924063789015557504303485 = PAL constant
    const auto fv = 17.02841924063789015557504303485 * f;
    const auto v  = int (
                         fv );
    const auto lv = v & _8_bits_max;
    const auto hv = ( v & 0xff00 ) >> 8;
    const auto r  = voice * 7;
    DirtyWrite (
                r
              , lv );
    DirtyWrite (
                static_cast < int > ( r + 1 )
              , hv );
}

void
    SidRegisters::onLiveDoneExporting ()
{
    if ( !recording ) { return; }
    recording                                                  = false;
    const std::array < int , register_array_size > order_table = {
            0x00
          , 0x01
          , 0x02
          , 0x03
          , 0x05
          , 0x06
          , 0x07
          , 0x08
          , 0x09
          , 0x0a
          , 0x0c
          , 0x0d
          , 0x0e
          , 0x0f
          , 0x10
          , 0x11
          , 0x13
          , 0x14
          , 0x15
          , 0x16
          , 0x17
          , 0x18
          , 0x04
          , 0x0b
          , 0x12
    };
    MessageManager::callAsync (
                               [=] ()
                               {
                                   if ( fileBrowser . browseForFileToSave (
                                                                           true ) )
                                   {
                                       const auto f = fileBrowser . getResult ();
                                       if ( f . exists () )
                                       {
                                           auto res = f . deleteFile ();
                                           if ( res ) { res = f . create (); }
                                           if ( !res ) { return; }
                                       }
                                       FileOutputStream file (
                                                              f );
                                       //auto row_idx = 0;
                                       //auto bar = 0;
                                       //auto loop_point = -1;
                                       //for ( const auto& row : record )
                                       //{
                                       //    if ( std::all_of (
                                       //                      row . begin ()
                                       //                    , row . end ()
                                       //                    , [=] (
                                       //                      const int value
                                       //                      )
                                       //                      {
                                       //                          return value == _8_bits_max;
                                       //                      } ) )
                                       //    {
                                       //        if ( loop_point == -1 )
                                       //        {
                                       //            loop_point = row_idx + 2;
                                       //        }

                                       //        continue;
                                       //    }
                                       //    if ( loop_point == row_idx )
                                       //    {
                                       //        file . writeText (
                                       //                          "data_loop:\n"
                                       //                        , false
                                       //                        , false );
                                       //    }
                                       //    if ( std::find (
                                       //                    barFrames . begin ()
                                       //                  , barFrames . end ()
                                       //                  , row_idx + 25 ) != barFrames . end () )
                                       //    {
                                       //        file . writeText (
                                       //                          "bar_" + String (
                                       //                                           bar++ ) + ":\n"
                                       //                        , false
                                       //                        , false );
                                       //    }
                                       //    //file . writeText (
                                       //    //                  "    !byte "
                                       //    //                , false
                                       //    //                , false );

                                       //    for ( auto i = 0 ; i < register_array_size ; i++ )
                                       //    {
                                       //        file . writeText (
                                       //                          String (
                                       //                                  row . at (
                                       //                                            i ) ) . paddedLeft (
                                       //                                                                ' '
                                       //                                                              , 3 )
                                       //                        , false
                                       //                        , false );
                                       //        if ( i != register_array_size - 1 )
                                       //        {
                                       //            file . writeText (
                                       //                              ", "
                                       //                            , false
                                       //                            , false );
                                       //        }
                                       //    }
                                       //    file . writeText (
                                       //                      "\n"
                                       //                    , false
                                       //                    , false );

                                       //    row_idx++;
                                       //}

                                       std::array < int , register_array_size > prev {};
                                       prev . fill (
                                                    -1 );

                                       auto                delay      = 0;
                                       auto                loop_point = -1;
                                       auto                frame      = 0;
                                       std::vector < int > raw;
                                       std::vector < int > bar_byte_stream_index;

                                       bar_byte_stream_index . push_back (
                                                                          0 );
                                       for ( const auto& row : record )
                                       {
                                           if ( std::find (
                                                           barFrames . begin ()
                                                         , barFrames . end ()
                                                         , frame ) != barFrames . end () )
                                           {
                                               bar_byte_stream_index . push_back (
                                                                                  raw . size () );
                                           }
                                           if ( std::all_of (
                                                             row . begin ()
                                                           , row . end ()
                                                           , [=] (
                                                             const int value
                                                             )
                                                             {
                                                                 return value == _8_bits_max;
                                                             } ) )
                                           {
                                               if ( loop_point == -1 )
                                               {
                                                   while ( delay > _7_bits_max )
                                                   {
                                                       raw . push_back (
                                                                        _8_bits_max );
                                                       delay -= _7_bits_max;
                                                   }
                                                   if ( delay > 0 )
                                                   {
                                                       raw . push_back (
                                                                        delay + delay_bit + 1 );
                                                   }
                                                   delay      = -1;
                                                   loop_point = raw . size ();
                                               }
                                           }
                                           else
                                           {
                                               if ( !raw . empty () ) { delay++; }
                                               for ( auto order = 0 ; order < register_array_size ; order++ )
                                               {
                                                   const auto reg = order_table . at (
                                                                                      order );
                                                   if ( row . at (
                                                                  reg ) != prev . at (
                                                                                      reg ) )
                                                   {
                                                       while ( delay > _7_bits_max )
                                                       {
                                                           raw . push_back (
                                                                            _8_bits_max );
                                                           delay -= _7_bits_max;
                                                       }
                                                       if ( delay > 0 )
                                                       {
                                                           raw . push_back (
                                                                            delay + delay_bit );
                                                           delay = 0;
                                                       }
                                                       raw . push_back (
                                                                        reg );
                                                       raw . push_back (
                                                                        row . at (
                                                                                  reg ) );
                                                   }
                                               }
                                           }
                                           prev = row;
                                           frame++;
                                       }
                                       while ( delay > _7_bits_max )
                                       {
                                           raw . push_back (
                                                            _8_bits_max );
                                           delay -= _7_bits_max;
                                       }
                                       if ( delay >= 0 )
                                       {
                                           raw . push_back (
                                                            delay + delay_bit + 1 );
                                       }
                                       //for ( const auto& row : record )
                                       String r = "";
                                       file . writeText (
                                                         "\t*= $1000\n\n!addr\tzp = $FB\n\n\ninterface\n\tjmp .init\n\tjmp .play\n\t\n"
                                                       , false
                                                       , false );
                                       if ( songTitle . length () > 0 )
                                       {
                                           file . writeText (
                                                             "\t!scr \"" + songTitle . toLowerCase () + "\", 0\n"
                                                           , false
                                                           , false );
                                       }
                                       if ( songArtist . length () > 0 )
                                       {
                                           file . writeText (
                                                             "\t!scr \"by " + songArtist . toLowerCase () + "\", 0\n"
                                                           , false
                                                           , false );
                                       }
                                       if ( loop_point > -1 && static_cast < unsigned int > ( loop_point ) != raw . size () )
                                       {
                                           file . writeText (
                                                             "\n.init\n\tlda # > data\n\tsta zp + 1\n\tlda #$00\n\tsta zp\n\tsta index\n\tsta delay\n\tldy # < data\n\tsty index\n\t\n.play\n\tlda delay\n!zone\n\tbeq .next\n\tdec delay\n\trts\n.next\n\tldy index\ncontinue\n\tlda (zp), y\n\tbmi delay_command\n\ttax\n\tiny\n!zone\n\tbne .next\n\tinc zp + 1\n.next\n\tlda (zp), y\n\tsta $d400, x\n\tiny\n\tbne continue\n\tinc zp + 1\n\tbne continue\n\t\ndelay_command\n\tand #$7F\n\tsta delay\n\tdec delay\n\tiny\n!zone\n\tbne .next\n\tinc zp + 1\n.next\n\tcpy #<data_end\n\tbne .return\n\tlda #>data_end\n\tcmp zp + 1\n\tbne .return\n\tlda # > data_loop\n\tsta zp + 1\n\tldy # < data_loop\n.return\n\tsty index\n\trts\n\t\nindex\n\t!byte $00\ndelay\n\t!byte $00\n\n"
                                                           , false
                                                           , false );
                                       }
                                       else
                                       {
                                           // Non-Looping
                                           file . writeText (
                                                             "\n.init\n\tlda # > data\n\tsta zp + 1\n\tlda #$00\n\tsta zp\n\tsta index\n\tsta delay\n\tldy # < data\n\tsty index\n\t\n.play\n\tlda delay\n!zone\n\tbeq .next\n\tdec delay\n\trts\n.next\n\tldy index\ncontinue\n\tlda (zp), y\n\tbmi delay_command\n\ttax\n\tiny\n!zone\n\tbne .next\n\tinc zp + 1\n.next\n\tlda (zp), y\n\tsta $d400, x\n\tiny\n\tbne continue\n\tinc zp + 1\n\tbne continue\n\t\ndelay_command\n\tand #$7F\n\tsta delay\n\tdec delay\n\tiny\n!zone\n\tbne .next\n\tinc zp + 1\n.next\n\tcpy #<data_end\n\tbne .return\n\tlda #>data_end\n\tcmp zp + 1\n\tbne .return\n\trts\n.return\n\tsty index\n\trts\n\t\nindex\n\t!byte $00\ndelay\n\t!byte $00\n\n"
                                                           , false
                                                           , false );
                                       }
                                       file . writeText (
                                                         "data:\n; Bar 0\n\t!byte "
                                                       , false
                                                       , false );
                                       auto value_index = 0;
                                       auto bar_number = 0;
                                       //for ( const auto& row : raw )
                                       for ( size_t i = 0 ; i < raw . size () ; i++ )
                                       {
                                           auto& row = raw [ i ];
                                           if ( static_cast < int > ( i ) == loop_point )
                                           {
                                               file . writeText (
                                                                 r + "\ndata_loop:\n\t!byte "
                                                               , false
                                                               , false );
                                               value_index += data_row_length - value_index % data_row_length;
                                               r = "";
                                           }
                                           if ( ( row & delay_bit ) == delay_bit )
                                           {
                                               r += "$" + String::toHexString (
                                                                               row ) . paddedLeft (
                                                                                                   '0'
                                                                                                 , 2 ) . toUpperCase ();
                                               if ( std::find (
                                                               bar_byte_stream_index . begin ()
                                                             , bar_byte_stream_index . end ()
                                                             , i ) != bar_byte_stream_index . end () )
                                               {
                                                   r += "\n; Bar " + String (
                                                                             ++bar_number );
                                               }
                                               r += "\n\t!byte ";
                                           }
                                           else
                                           {
                                               r += "$" + String::toHexString (
                                                                               row ) . paddedLeft (
                                                                                                   '0'
                                                                                                 , 2 ) . toUpperCase ();
                                               value_index++;
                                               row = raw [ ++i ];
                                               r += ", $" + String::toHexString (
                                                                                 row ) . paddedLeft (
                                                                                                     '0'
                                                                                                   , 2 ) . toUpperCase ();
                                               value_index++;
                                               r += ", ";
                                           }

                                           //if ( value_index % data_row_length == 0 )
                                           //{
                                           //    if ( r . length () > 0 )
                                           //    {
                                           //        file . writeText (
                                           //                          r + "\n"
                                           //                        , false
                                           //                        , false );
                                           //    }
                                           //    r = "\t!byte ";
                                           //}
                                           //else { r += ", "; }
                                           //r += "$" + String::toHexString (
                                           //                                row ) . paddedLeft (
                                           //                                                    '0'
                                           //                                                  , 2 ) . toUpperCase ();
                                           //value_index++;
                                       }
                                       file . writeText (
                                                         r + "\ndata_end:\n"
                                                       , false
                                                       , false );
                                   }
                               } );
}

void
    SidRegisters::onLiveExportArmed ()
{
    recording    = true;
    currentFrame = 0;
}

void
    SidRegisters::onLiveTitleChanged (
            const String value
            ) { songTitle = value; }

void
    SidRegisters::onLiveArtistChanged (
            const String value
            ) { songArtist = value; }

void
    SidRegisters::onNoteOff (
            const unsigned int channel
          , const int unsigned note
          , const unsigned int velocity
            )
{
    const auto i_channel = static_cast < int > ( channel );
    int        idx;
    auto       jdx = 0;
    for ( idx = 0 ; idx < 3 ; idx++ )
    {
        for ( jdx = 0 ; jdx < hardRestartReleasedNotesDelay . getUnchecked (
                                                                            i_channel ) -> getUnchecked (
                                                                                                         idx ) -> size () ; jdx++ )
        {
            if ( hardRestartReleasedNotesDelay . getUnchecked (
                                                               i_channel ) -> getUnchecked (
                                                                                            idx ) -> getUnchecked (
                                                                                                                   jdx ) == note ) { break; }
        }
        if ( jdx != hardRestartReleasedNotesDelay . getUnchecked (
                                                                  i_channel ) -> getUnchecked (
                                                                                               idx ) -> size () ) { break; }
    }
    auto rit = 0;
    if ( idx == 3 && jdx == hardRestartReleasedNotesDelay . getUnchecked (
                                                                          i_channel ) -> getUnchecked (
                                                                                                       2 ) -> size () )
    {
        for ( rit = 0 ; rit < releasedNotes [ i_channel ] -> size () ; rit++ )
        {
            if ( releasedNotes [ i_channel ] -> getUnchecked (
                                                              rit ) == note ) { break; }
        }
    }

    // Add a delay here - will use an array that is indexed by channels, then frames (there are a total of 3 of these,
    // 2 frames away, 1 frame away, and current).  This will mean needing to check for all of these buffers in the loop
    // immediately above, and then processing the current buffer in ProcessNotesOnOff below, before anything else.  It
    // is probably also necessary to check the buffers in onNoteOn to remove the release if it exists in the buffers.
    if ( idx == 3 && jdx == hardRestartReleasedNotesDelay . getUnchecked (
                                                                          i_channel ) -> getUnchecked (
                                                                                                       2 ) -> size () && rit == releasedNotes [ i_channel ] -> size () )
    {
        hardRestartReleasedNotesDelay . getUnchecked (
                                                      i_channel ) -> getUnchecked (
                                                                                   hardRestartReleasedNotesDelayIndex ) -> add (
                                                                                                                                note );
    }
}

void
    SidRegisters::onNoteOn (
            const unsigned int channel
          , const unsigned int note
          , const unsigned int velocity
            )
{
    const auto i_channel = static_cast < int > ( channel );
    int        note_index;
    for ( note_index = 0 ; note_index < notes [ i_channel ] -> size () ; note_index++ )
    {
        if ( notes [ i_channel ] -> getUnchecked (
                                                  note_index ) . note == note ) { break; }
    }
    if ( note_index == notes [ i_channel ] -> size () )
    {
        const Note n {
                note
              , velocity
        };
        notes [ i_channel ] -> add (
                                    n );
    }
    else
    {
        int  idx;
        auto jdx = 0;
        // BUG: I don't know where the hard restart bug is coming from, but it might be in here.  There are very few places where I even touch it.
        // Hrm... I break out of the loop possibly before the end of the voice loop, which may mean that if there are simultaneous hard restarts that
        // only the lower voice channel gets processed.
        //
        // No, wait... i_channel is the channel index, so what is idx?
        for ( idx = 0 ; idx < 3 ; idx++ )
        {
            for ( jdx = 0 ; jdx < hardRestartReleasedNotesDelay . getUnchecked (
                                                                                i_channel ) -> getUnchecked (
                                                                                                             idx ) -> size () ; jdx++ )
            {
                if ( hardRestartReleasedNotesDelay . getUnchecked (
                                                                   i_channel ) -> getUnchecked (
                                                                                                idx ) -> getUnchecked (
                                                                                                                       jdx ) == note ) { break; }
            }
            if ( jdx != hardRestartReleasedNotesDelay . getUnchecked (
                                                                      i_channel ) -> getUnchecked (
                                                                                                   idx ) -> size () ) { break; }
        }
        if ( idx != 3 || jdx != hardRestartReleasedNotesDelay . getUnchecked (
                                                                              i_channel ) -> getUnchecked (
                                                                                                           2 ) -> size () )
        {
            hardRestartReleasedNotesDelay . getUnchecked (
                                                          i_channel ) -> getUnchecked (
                                                                                       idx ) -> remove (
                                                                                                        jdx );
        }
        else
        {
            int rit;
            for ( rit = 0 ; rit < releasedNotes [ i_channel ] -> size () ; rit++ )
            {
                if ( releasedNotes [ i_channel ] -> getUnchecked (
                                                                  rit ) == note ) { break; }
            }
            if ( rit != releasedNotes [ i_channel ] -> size () )
            {
                releasedNotes [ i_channel ] -> remove (
                                                       rit );
            }
        }
    }
}

void
    SidRegisters::onLoadLivePatch (
            const unsigned int                             voice
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    programs . set (
                    static_cast < int > ( voice )
                  , program );
}

void
    SidRegisters::onQuarterNoteTick (
            const unsigned int ppq
            )
{
    currentQuarterNote = ppq;
    const auto current_bar = currentQuarterNote / 4;
    if ( current_bar >= barFrames . size () )
    {
        barFrames . push_back (
                               currentFrame );
    }
}

void
    SidRegisters::SetFrame (
            const unsigned frame
            )
{
    if ( recording && frame < currentFrame )
    {
        SharedResourcePointer < ListenerList < LiveDoneExporting > > () -> call (
                                                                                 &LiveDoneExporting::onLiveDoneExporting );
        return;
    }
    if ( frame == 0 )
    {
        record . clear ();
    }
    lastFrame = currentFrame;
    currentFrame = frame;
}

void
    SidRegisters::SetLoopStart (
            const unsigned frame
            )
{
    loopStart                                          = frame;
    static const auto                   REGISTER_COUNT = 0x19;
    std::array < int , REGISTER_COUNT > row {};
    row . fill (
                _8_bits_max );
    record . push_back (
                        row );
}

void
    SidRegisters::SetLoopEnd (
            const unsigned frame
            )
{
    loopEnd                                            = frame;
    static const auto                   REGISTER_COUNT = 0x19;
    std::array < int , REGISTER_COUNT > row {};
    row . fill (
                _8_bits_max );
    record . push_back (
                        row );
}

void
    SidRegisters::ProcessNotesOnOff (
            const int v
            )
{
    if ( v == 0 )
    {
        hardRestartReleasedNotesDelayIndex++;
        hardRestartReleasedNotesDelayIndex %= 3; 
    }
    for ( auto i = 0 ; i < hardRestartReleasedNotesDelay . getUnchecked (
                                                                         v ) -> getUnchecked (
                                                                                              hardRestartReleasedNotesDelayIndex ) -> size () ; i++ )
    {
        releasedNotes [ v ] -> add (
                                    hardRestartReleasedNotesDelay . getUnchecked (
                                                                                  v ) -> getUnchecked (
                                                                                                       hardRestartReleasedNotesDelayIndex ) -> getUnchecked (
                                                                                                                                                             i ) );
    }
    hardRestartReleasedNotesDelay . getUnchecked (
                                                  v ) -> getUnchecked (
                                                                       hardRestartReleasedNotesDelayIndex ) -> clear ();
    const auto p = programs [ v ];
    const auto         e      = p -> GetEnvelope ();
    const unsigned int offset = v * 7;
    if ( notes [ v ] -> size () > 0 && arpIndex [ v ] != -1 )
    {
        ReleaseProcessor (
                          v );
    }
    if ( arpIndex [ v ] == -1 && notes [ v ] -> size () > 0 && hardRestartCounter [ v ] < 0 )
    {
        hardRestartCounter . set (
                                  v
                                , 3 );
        DirtyWrite (
                    static_cast < int > ( offset ) + attack_decay_offset
                  , 0 );
        DirtyWrite (
                    static_cast < int > ( offset ) + sustain_release_offset
                  , 0 );
        DirtyWrite (
                    static_cast < int > ( offset ) + voice_control_offset
                  , 0 );
    }
    if ( hardRestartCounter [ v ] > 0 )
    {
        hardRestartCounter . set (
                                  v
                                , hardRestartCounter [ v ] - 1 );
    }
    else if ( hardRestartCounter [ v ] == 0 )
    {
        hardRestartCounter . set (
                                  v
                                , hardRestartCounter [ v ] - 1 );
        DirtyWrite (
                    static_cast < int > ( offset ) + attack_decay_offset
                  , static_cast < int > ( ( e -> getAttack () << voice_control_offset ) + e -> getDecay () ) );
        DirtyWrite (
                    static_cast < int > ( offset ) + sustain_release_offset
                  , static_cast < int > ( ( e -> getSustain () << voice_control_offset ) + e -> getRelease () ) );
        arpIndex . set (
                        v
                      , 0 );
        p -> Start ();
    }
}

void
    SidRegisters::ProcessPulseWidth (
            const int v
            )
{
    const auto         p      = programs [ v ];
    const auto         ex     = p -> GetExpression ();
    const unsigned int offset = v * 7;

    const auto pulse_cycle       = ex -> getCurrentPulseValue ();
    const auto pulse_table_cycle = p -> GetPulseTable () -> GetCurrentPulseTableEntry ();
    const auto pulse_value       = static_cast < int > ( pulse_cycle ) - 2048 + ( static_cast < int > ( pulse_table_cycle ) - 2048 ) + 2048;
    DirtyWrite (
                static_cast < int > ( offset ) + 2
              , pulse_value & _8_bits_max );
    DirtyWrite (
                static_cast < int > ( offset ) + 3
              , ( pulse_value & pulse_hi_nybble ) >> pulse_hi_nybble_bit_shift );

    p -> Step ();
}

void
    SidRegisters::WriteNotes (
            const int v
            )
{
    if ( notes [ v ] -> size () > 0 && hardRestartCounter [ v ] < 0 )
    {
        if ( arpIndex [ v ] >= notes [ v ] -> size () )
        {
            arpIndex . set (
                            v
                          , 0 );
        }
        SetNote (
                 v
               , notes [ v ] -> getUnchecked (
                                              arpIndex [ v ] ) . note );
        DirtyWrite (
                    v * voice_register_offset + 4
                  , static_cast < int > ( programs [ v ] -> GetWavetable () -> GetCurrentWaveTableEntry () ) );
        arpIndex . set (
                        v
                      , arpIndex [ v ] + 1 );
    }
}

void
    SidRegisters::WriteRegisters ()
{
    if ( lastFrame == currentFrame )
    {
        return;
    }
    static const auto                   REGISTER_COUNT = 0x19;
    std::array < int , REGISTER_COUNT > row {};
    row . fill (
                -1 );
    static const auto GLOBAL_START = 0x15;
    for ( auto i = GLOBAL_START ; i < REGISTER_COUNT ; i++ )
    {
        DirtyWrite (
                    i
                  , row );
    }
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        for ( auto j = 0 ; j < voice_register_offset ; j++ )
        {
            if ( j != 4 )
            {
                DirtyWrite (
                            v * voice_register_offset + j
                          , row );
            }
        }
        DirtyWrite (
                    v * voice_register_offset + 4
                  , row );
    }
    if ( recording )
    {
        if ( currentFrame == 0 )
        {
            record . clear ();
            barFrames . clear ();
            barFrames . push_back (
                                   0 );
        }
        if ( lastFrame != currentFrame )
        {
            record . push_back (
                                row );
        }
    }
}

void
    SidRegisters::ReleaseProcessor (
            const int v
            )
{
    const auto current_program = programs [ v ];

    // if there are more active notes than releasing notes, then release the exiting notes immediately
    // Perhaps better to say "if notes and releasing notes do not match"
    const auto match = NotesMatchesReleasedNotes (
                                                  v );
    if ( !match )
    {
        const auto wt = current_program -> GetWavetable ();
        if ( wt -> Released () ) { current_program -> Start (); }
        NotesOff (
                  v );
        if ( current_program -> GetWavetable () -> Released () )
        {
            arpIndex . set (
                            v
                          , -1 );
        }
        return;
    }
    // otherwise, if all notes are releasing, check to see if the wavetable has finished releasing
    const auto wt = current_program -> GetWavetable ();
    if ( !wt -> Released () ) { current_program -> Release (); }
    if ( wt -> DoneReleasing () )
    {
        // if so, then finish releasing notes
        NotesOff (
                  v );
        DirtyWrite (
                    v * voice_register_offset + 4
                  , static_cast < int > ( wt -> GetCurrentWaveTableEntry () & wavetable_command_bitmask ) );
        arpIndex . set (
                        v
                      , -1 );
    }
}

void
    SidRegisters::NotesOff (
            const int v
            ) const
{
    for ( auto i = 0 ; i < releasedNotes [ v ] -> size () ; i++ )
    {
        const auto cn = releasedNotes [ v ] -> getUnchecked (
                                                             i );
        int nit;
        for ( nit = 0 ; nit < notes [ v ] -> size () ; nit++ )
        {
            if ( notes [ v ] -> getUnchecked (
                                              nit ) . note == cn ) { break; }
        }

        if ( nit != notes [ v ] -> size () )
        {
            notes [ v ] -> remove (
                                   nit );
        }
    }
    releasedNotes [ v ] -> clear ();
}

auto
    SidRegisters::NotesMatchesReleasedNotes (
            const int v
            ) const -> bool
{
    for ( auto i = 0 ; i < notes [ v ] -> size () ; i++ )
    {
        if ( !releasedNotes [ v ] -> contains (
                                               notes [ v ] -> getReference (
                                                                            i ) . note ) ) { return false; }
    }
    return true;
}

void
    SidRegisters::DirtyWrite (
            const int                                 index
          , std::array < int , register_array_size >& row
            )
{
    row . at (
              index ) = static_cast < unsigned char > ( registers [ index ] );
    if ( !dirty [ index ] ) { return; }
    sid -> write (
                  index
                , static_cast < unsigned char > ( registers [ index ] ) );
    dirty . set (
                 index
               , false );
}

void
    SidRegisters::DirtyWrite (
            const int index
          , const int value
            )
{
    if ( registers [ index ] == value ) { return; }
    registers . set (
                     index
                   , value );
    dirty . set (
                 index
               , true );
}
