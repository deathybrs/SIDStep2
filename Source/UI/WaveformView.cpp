/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "../SIDProgram.h"

#include "../../Requirements/resid-0.16/sid.h"
//[/Headers]

#include "WaveformView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
double attack[] = {
        0.0020299458
      , 0.008119783
      , 0.0162395661
      , 0.0243593491
      , 0.0385689694
      , 0.0568384813
      , 0.0690181558
      , 0.0811978304
      , 0.101497288
      , 0.25374322
      , 0.50748644
      , 0.8119783039
      , 1.0149728799
      , 3.0449186398
      , 5.0748643996
      , 8.1197830394
};
double decay_release[] = {
        0.0060898373
      , 0.0243593491
      , 0.0487186982
      , 0.0730780474
      , 0.1157069083
      , 0.1705154438
      , 0.2070544675
      , 0.2435934912
      , 0.304491864
      , 0.7612296599
      , 1.5224593199
      , 2.4359349118
      , 3.0449186398
      , 9.1347559193
      , 15.2245931989
      , 24.3593491182
};

//[/MiscUserDefs]

//==============================================================================
WaveformView::WaveformView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //currentProgram = nullptr;
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             608
           , 328 );


    //[Constructor] You can add your own custom stuff here..
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> add (
                                                                              this );
    //[/Constructor]
}

WaveformView::~WaveformView ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]


    //[Destructor]. You can add your own custom destruction code here..
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> remove (
                                                                                 this );
    //[/Destructor]
}

//==============================================================================
void
    WaveformView::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    if ( currentProgram != nullptr )
    {
        const auto f   = 4000.0;
        const auto spf = static_cast < int > ( f / 50.0 );
        const auto e   = currentProgram -> GetEnvelope ();
        const auto wt  = currentProgram -> GetWavetable ();
        const auto cps = 985248.0 / f;

        // calculate duration - 0.5 is sustain, so this will show APPROXIMATELY a quarter note at 120bpm
        // Only approximately because it is one quarter note ABOVE AND BEYOND attack, decay and release.
        auto duration = attack [ e -> getDefaultAttack () ] + decay_release [ e -> getDefaultDecay () ];
        const auto release_at = static_cast < int > ( duration * 50.0 ) + 25;
        duration      = release_at / 50.0;
        duration += decay_release [ e -> getDefaultRelease () ] + .15;
        //duration += (duration * 0.2);

        // allocate memory
        const auto samples = f * duration + spf * 2;
        const ScopedPointer < short > render  = new short[static_cast < int > ( samples + spf )];
        memset (
                render
              , 0
              , static_cast < int > ( samples + spf ) );

        // reset sid chip and let run for a while
        auto s = new SID ();
        s -> set_chip_model (
                             MOS8580 );
        s -> enable_filter (
                            false );
        s -> set_sampling_parameters (
                                      985248
                                    , SAMPLE_FAST
                                    , f
                                    , 0.9 * f / 2.0 );
        s -> write (
                    0x18
                  , 0x0f );
        cycle_count cycles = cps * ( samples - 1 );
        //s->clock(static_cast<unsigned int>(cps * (samples - 1)), render);
        s -> clock (
                    cycles
                  , render
                  , samples - 1 );
        //int i = s->clock(static_cast<unsigned int>(cps * spf), render);
        cycles  = cps * spf;
        auto i = s -> clock (
                             cycles
                           , render
                           , spf );

        // fill preview
        s -> write (
                    5
                  , static_cast < unsigned char > ( ( e -> getDefaultAttack () << 4 ) + e -> getDefaultDecay () ) );
        s -> write (
                    6
                  , static_cast < unsigned char > ( ( e -> getDefaultSustain () << 4 ) + e -> getDefaultRelease () ) );
        currentProgram -> Start ();

        // A0 to show wave clearly while also allowing room for maximum vibrato
        const auto note = 33;
        SetNote (
                 s
               , note );
        s -> write (
                    4
                  , static_cast < unsigned char > ( wt -> GetCurrentWaveTableEntry () ) );
        auto cf   = 0;
        auto most = 0;
        cycles     = 0;
        while ( i < samples )
        {
            cycles += cps * spf;
            //i += s->clock(static_cast<unsigned int>(cps * spf), render + i);
            i += s -> clock (
                             cycles
                           , render + i
                           , spf );
            for ( auto j = -spf ; j < 0 ; j++ )
            {
                if ( abs (
                          render [ i + j ] ) > most )
                    most = abs (
                                render [ i + j ] );
            }
            cf++;
            if ( cf == release_at )
                currentProgram -> Release ();
            currentProgram -> Step ();
            const auto pulse_cycle       = currentProgram -> GetExpression () -> getCurrentPulseValue ();
            const auto pulse_table_cycle = currentProgram -> GetPulseTable () -> GetCurrentPulseTableEntry ();
            const auto pulse_value       = static_cast < int > ( pulse_cycle ) - 2048 + ( static_cast < int > ( pulse_table_cycle ) - 2048 ) + 2048;
            s -> write (
                        2
                      , pulse_value & 0xff );
            s -> write (
                        3
                      , ( pulse_value & 0xf00 ) >> 8 );
            SetNote (
                     s
                   , note );
            if ( wt -> Released () && wt -> DoneReleasing () )
                s -> write (
                            4
                          , static_cast < unsigned char > ( wt -> GetCurrentWaveTableEntry () & 0xfe ) );
            else
            {
                s -> write (
                            4
                          , static_cast < unsigned char > ( wt -> GetCurrentWaveTableEntry () ) );
            }
        }
        if ( most < 0x2000 )
        {
            most = 0x2000;
        }

        // render to screen
        const auto samples_per_pixel         = static_cast < int > ( samples / getWidth () );
        const auto amplitude_values_per_pixel = most * 2 / getHeight ();
        short last_min = 0;
        short last_max = 0;
        const Colour lt_blue (
                              0xff5090d0 );
        const Colour dk_grey (
                              0xff484848 );
        g . setColour (
                       lt_blue );
        for ( i = 0 ; i < getWidth () ; i++ )
        {
            auto min = render [ i * samples_per_pixel ], max = render [ i * samples_per_pixel ];
            for ( auto j = 1 ; j < samples_per_pixel ; j++ )
            {
                if ( render [ i * samples_per_pixel + j ] < min )
                    min = render [ i * samples_per_pixel + j ];
                if ( render [ i * samples_per_pixel + j ] > max )
                    max = render [ i * samples_per_pixel + j ];
            }
            if ( last_max < min ) { min = last_max; }
            if ( last_min > max ) { max = last_min; }
            const auto minPixel = ( min + most ) / amplitude_values_per_pixel;
            const auto maxPixel = ( max + most ) / amplitude_values_per_pixel;
            if ( minPixel == maxPixel )
            {
                g . setPixel (
                              i
                            , minPixel );
            }
            else
            {
                g . drawVerticalLine (
                                      i
                                    , static_cast < float > ( minPixel )
                                    , static_cast < float > ( maxPixel ) );
            }
            last_min = min;
            last_max = max;
        }

        // delete memory
        delete s;
        //delete[] render;
        g . setColour (
                       dk_grey );
        g . drawHorizontalLine (
                                most / amplitude_values_per_pixel
                              , 0.0f
                              , static_cast < float > ( getWidth () ) );
    }
    //[/UserPaint]
}

void
    WaveformView::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    WaveformView::SetNote (
            SID*         s
          , unsigned int note
            ) const
{
    const auto ex                       = currentProgram -> GetExpression ();
    const auto pb                       = ex -> getPitchBend () * ex -> getPitchBendRange () / 4096.0;
    const auto vib                      = ex -> getVibrato () -> GetCurrentVibratoValue () / 4096.0;
    const auto                                ntab                     = currentProgram -> GetNoteTable ();
    const auto                                current_note_table_entry = ntab -> GetCurrentNoteTableEntry ();
    const auto                                note_offset              = current_note_table_entry . rowType == RELATIVE
                                                                             ? current_note_table_entry . value
                                                                             : 0;
    auto f = 440.0 * pow (
                          2
                        , ( note + note_offset - 69.0 ) / 12.0 + pb + vib );
    if ( current_note_table_entry . rowType == ABSOLUTE ) { f = static_cast < double > ( current_note_table_entry . value ); }

    // 17.02841924063789015557504303485 = PAL constant
    const auto fv = 17.02841924063789015557504303485 * f;
    const auto v  = int (
                         fv );
    const auto lv = v & 0xff;
    const auto hv = ( v & 0xff00 ) >> 8;
    s -> write (
                0
              , static_cast < unsigned char > ( lv ) );
    s -> write (
                1
              , static_cast < unsigned char > ( hv ) );
}

void
    WaveformView::onBankProgramChanged (
            String                                   oldID
          , ReferenceCountedObjectPtr < SidProgram > program
            ) { currentProgram = program; }

void
    WaveformView::onBankRepaintWaveform () { repaint (); }


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WaveformView" componentName=""
                 parentClasses="public Component, public BankProgramChanged, public BankRepaintWaveform"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="608"
                 initialHeight="328">
  <BACKGROUND backgroundColour="ffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
