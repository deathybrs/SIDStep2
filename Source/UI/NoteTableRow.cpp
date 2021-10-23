/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include <string>
#include "../Programs/ArpRow.h"
//[/Headers]

#include "NoteTableRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NoteTableRow::NoteTableRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    relativeAbsolute . reset (
                              new juce::ToggleButton (
                                                      "new toggle button" ) );
    addAndMakeVisible (
                       relativeAbsolute . get () );
    relativeAbsolute -> setButtonText (
                                       juce::String () );
    relativeAbsolute -> addListener (
                                     this );
    relativeAbsolute -> setBounds (
                                   54
                                 , 6
                                 , 14
                                 , 14 );
    noteOffset . reset (
                        new juce::Label (
                                         "new label"
                                       , juce::String () ) );
    addAndMakeVisible (
                       noteOffset . get () );
    noteOffset -> setFont (
                           juce::Font (
                                       "C64 Pro"
                                     , 15.00f
                                     , juce::Font::plain ) . withTypefaceStyle (
                                                                                "Regular" ) );
    noteOffset -> setJustificationType (
                                        juce::Justification::centred );
    noteOffset -> setEditable (
                               true
                             , true
                             , false );
    noteOffset -> setColour (
                             juce::Label::textColourId
                           , juce::Colour (
                                           0xff5090d0 ) );
    noteOffset -> setColour (
                             juce::TextEditor::textColourId
                           , juce::Colours::black );
    noteOffset -> setColour (
                             juce::TextEditor::backgroundColourId
                           , juce::Colour (
                                           0x00000000 ) );
    noteOffset -> addListener (
                               this );
    noteOffset -> setBounds (
                             296
                           , 3
                           , 56
                           , 20 );
    frequency . reset (
                       new juce::Label (
                                        "new label"
                                      , juce::String () ) );
    addAndMakeVisible (
                       frequency . get () );
    frequency -> setFont (
                          juce::Font (
                                      "C64 Pro"
                                    , 15.00f
                                    , juce::Font::plain ) . withTypefaceStyle (
                                                                               "Regular" ) );
    frequency -> setJustificationType (
                                       juce::Justification::centredLeft );
    frequency -> setEditable (
                              true
                            , true
                            , false );
    frequency -> setColour (
                            juce::Label::textColourId
                          , juce::Colour (
                                          0xff5090d0 ) );
    frequency -> setColour (
                            juce::TextEditor::textColourId
                          , juce::Colours::black );
    frequency -> setColour (
                            juce::TextEditor::backgroundColourId
                          , juce::Colour (
                                          0x00000000 ) );
    frequency -> addListener (
                              this );
    frequency -> setBounds (
                            496
                          , 3
                          , 94
                          , 20 );
    rowLabel . reset (
                      new juce::Label (
                                       "new label"
                                     , TRANS (
                                              "01" ) ) );
    addAndMakeVisible (
                       rowLabel . get () );
    rowLabel -> setFont (
                         juce::Font (
                                     "C64 Pro Mono"
                                   , 12.00f
                                   , juce::Font::plain ) . withTypefaceStyle (
                                                                              "Regular" ) );
    rowLabel -> setJustificationType (
                                      juce::Justification::centredRight );
    rowLabel -> setEditable (
                             false
                           , false
                           , false );
    rowLabel -> setColour (
                           juce::Label::textColourId
                         , juce::Colour (
                                         0xff5090d0 ) );
    rowLabel -> setColour (
                           juce::TextEditor::textColourId
                         , juce::Colours::black );
    rowLabel -> setColour (
                           juce::TextEditor::backgroundColourId
                         , juce::Colour (
                                         0x00000000 ) );
    rowLabel -> setBounds (
                           0
                         , 4
                         , 44
                         , 18 );
    cachedImage_noteTableAbsoluteRow_png_1 = juce::ImageCache::getFromMemory (
                                                                              noteTableAbsoluteRow_png
                                                                            , noteTableAbsoluteRow_pngSize );
    cachedImage_noteTableRelativeRow_png_2 = juce::ImageCache::getFromMemory (
                                                                              noteTableRelativeRow_png
                                                                            , noteTableRelativeRow_pngSize );

    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             590
           , 24 );


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NoteTableRow::~NoteTableRow ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    relativeAbsolute = nullptr;
    noteOffset       = nullptr;
    frequency        = nullptr;
    rowLabel         = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void
    NoteTableRow::paint (
            juce::Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        int x = 0, y = 0, width = 592, height = 24;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g . setColour (
                       juce::Colours::black );
        g . drawImage (
                       cachedImage_noteTableAbsoluteRow_png_1
                     , x
                     , y
                     , width
                     , height
                     , 0
                     , 0
                     , cachedImage_noteTableAbsoluteRow_png_1 . getWidth ()
                     , cachedImage_noteTableAbsoluteRow_png_1 . getHeight () );
    }
    {
        int x = 0, y = 0, width = 592, height = 24;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        if ( !relativeAbsolute -> getToggleState () )
        {
            //[/UserPaintCustomArguments]
            g . setColour (
                           juce::Colours::black );
            g . drawImage (
                           cachedImage_noteTableRelativeRow_png_2
                         , x
                         , y
                         , width
                         , height
                         , 0
                         , 0
                         , cachedImage_noteTableRelativeRow_png_2 . getWidth ()
                         , cachedImage_noteTableRelativeRow_png_2 . getHeight () );
        }

        //[UserPaint] Add your own custom painting code here..
    }
    if ( selected )
    {
        Colour ltBlue (
                       0xff5090d0 );
        g . setColour (
                       ltBlue );
        Path p;
        p . addTriangle (
                         0.0f
                       , 0.0f
                       , 12.0f
                       , 12.0f
                       , 0.0f
                       , 24.0f );
        g . fillPath (
                      p );
    }
    //[/UserPaint]
}

void
    NoteTableRow::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void
    NoteTableRow::buttonClicked (
            juce::Button* buttonThatWasClicked
            )
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if ( buttonThatWasClicked == relativeAbsolute . get () )
    {
        //[UserButtonCode_relativeAbsolute] -- add your button handler code here..
        noteOffset -> setText (
                               ""
                             , dontSendNotification );
        frequency -> setText (
                              ""
                            , dontSendNotification );
        // TODO(deathy): Make relative frequencies an option.
        frequency -> setEditable (
                                  relativeAbsolute -> getToggleState () );

        //[/UserButtonCode_relativeAbsolute]
    }

    //[UserbuttonClicked_Post]
    SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> call (
                                                                                     &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                                                   , static_cast < unsigned int > ( row ) );
    auto changed = Get ();
    SharedResourcePointer < ListenerList < NoteTableRowChanged > > () -> call (
                                                                               &NoteTableRowChanged::onNoteTableRowChanged
                                                                             , changed );
    SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                               &BankRepaintWaveform::onBankRepaintWaveform );
    //[/UserbuttonClicked_Post]
}

void
    NoteTableRow::labelTextChanged (
            juce::Label* labelThatHasChanged
            )
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if ( labelThatHasChanged == noteOffset . get () )
    {
        //[UserLabelCode_noteOffset] -- add your label text handling code here..
        if ( relativeAbsolute -> getToggleState () ) { SetFrequencyFromNote (); }
        //[/UserLabelCode_noteOffset]
    }
    else if ( labelThatHasChanged == frequency . get () )
    {
        //[UserLabelCode_frequency] -- add your label text handling code here..
        if ( relativeAbsolute -> getToggleState () ) { SetNoteFromFrequency (); }
        //[/UserLabelCode_frequency]
    }

    //[UserlabelTextChanged_Post]
    SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> call (
                                                                                     &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                                                   , static_cast < unsigned int > ( row ) );
    auto changed = Get ();
    SharedResourcePointer < ListenerList < NoteTableRowChanged > > () -> call (
                                                                               &NoteTableRowChanged::onNoteTableRowChanged
                                                                             , changed );
    SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                               &BankRepaintWaveform::onBankRepaintWaveform );
    //[/UserlabelTextChanged_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
auto
    NoteTableRow::Get () const -> ArpRow
{
    ArpRow ret {
            RELATIVE
          , 0
    };
    if ( relativeAbsolute -> getToggleState () )
    {
        ret . rowType = ABSOLUTE;
        if ( frequency -> getText () . length () > 0 )
        {
            ret . value = std::stoi (
                                     frequency -> getText () . toRawUTF8 () );
        }
    }
    else
    {
        if ( noteOffset -> getText () . length () > 0 )
        {
            ret . value = std::stoi (
                                     noteOffset -> getText () . toRawUTF8 () );
        }
    }
    return ret;
}

void
    NoteTableRow::Set (
            const unsigned row_num
          , const ArpRow   value
            )
{
    relativeAbsolute -> setToggleState (
                                        value . rowType == ABSOLUTE
                                      , dontSendNotification );
    if ( !relativeAbsolute -> getToggleState () )
    {
        noteOffset -> setText (
                               String (
                                       value . value )
                             , dontSendNotification );
        frequency -> setText (
                              ""
                            , dontSendNotification );
        frequency -> setEditable (
                                  false );
    }
    else
    {
        frequency -> setText (
                              String (
                                      value . value )
                            , dontSendNotification );
        SetNoteFromFrequency ();
    }
    row                   = static_cast < int > ( row_num );
    const auto row_string = String (
                                    row_num + 1 );
    rowLabel -> setText (
                         row_string . paddedLeft (
                                                  '0'
                                                , 2 )
                       , dontSendNotification );
}

void
    NoteTableRow::SetNoteFromFrequency () const
{
    static const std::vector < String > INVERSE_BASE_SCALE {
            "C-"
          , "C#"
          , "D-"
          , "D#"
          , "E-"
          , "F-"
          , "F#"
          , "G-"
          , "G#"
          , "A-"
          , "A#"
          , "B-"
    };
    const auto v = std::stoi (
                              frequency -> getText () . toRawUTF8 () );
    if ( v == 0 ) { return; }
    const auto mv = v / 440.0;
    const auto bp = log2 (
                          mv );
    const auto ov     = bp * 12.0;
    const auto note   = ov + 69;
    const auto i_note = static_cast < int > ( round (
                                                     note ) );
    const auto note_part = String (
                                   INVERSE_BASE_SCALE [ i_note % 12 ] );
    const auto octave_part = String (
                                     static_cast < int > ( i_note / 12 ) - 1 );
    noteOffset -> setText (
                           note_part + octave_part
                         , dontSendNotification );
}

void
    NoteTableRow::SetFrequencyFromNote () const
{
    static const std::map < String , int > BASE_SCALE {
            {
                    "c-"
                  , 0
            }
          , {
                    "c#"
                  , 1
            }
          , {
                    "db"
                  , 1
            }
          , {
                    "d-"
                  , 2
            }
          , {
                    "d#"
                  , 3
            }
          , {
                    "eb"
                  , 3
            }
          , {
                    "e-"
                  , 4
            }
          , {
                    "f-"
                  , 5
            }
          , {
                    "f#"
                  , 6
            }
          , {
                    "gb"
                  , 6
            }
          , {
                    "g-"
                  , 7
            }
          , {
                    "g#"
                  , 8
            }
          , {
                    "ab"
                  , 8
            }
          , {
                    "a-"
                  , 9
            }
          , {
                    "a#"
                  , 10
            }
          , {
                    "bb"
                  , 10
            }
          , {
                    "b-"
                  , 11
            }
           ,
    };
    const auto note_text = noteOffset -> getText ();
    const auto note_part = note_text . substring (
                                                  0
                                                , 2 ) . toLowerCase ();
    if ( BASE_SCALE . find (
                            note_part ) == BASE_SCALE . end () ) { return; }
    const auto note_index = BASE_SCALE . at (
                                             note_part );
    const auto octave_part = std::stoi (
                                        note_text . substring (
                                                               2 ) . toRawUTF8 () ) + 1;
    const auto note = octave_part * 12 + note_index;
    // Note 69 = 440 = Middle A
    const auto f = 440.0 * pow (
                                2
                              , ( note - 69.0 ) / 12.0 );

    //// 17.02841924063789015557504303485 = PAL constant
    //const auto fv = 17.02841924063789015557504303485 * f;
    const auto v = int (
                        f );
    frequency -> setText (
                          String (
                                  v )
                        , dontSendNotification );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NoteTableRow" componentName=""
                 parentClasses="public AbstractNoteTableRow" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="590" initialHeight="24">
  <BACKGROUND backgroundColour="0">
    <IMAGE pos="0 0 592 24" resource="noteTableAbsoluteRow_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="0 0 592 24" resource="noteTableRelativeRow_png" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="new toggle button" id="449730a9aa88bdb9" memberName="relativeAbsolute"
                virtualName="" explicitFocusOrder="0" pos="54 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="c84faa199ea1ccce" memberName="noteOffset"
         virtualName="" explicitFocusOrder="0" pos="296 3 56 20" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="718fa581b1eabe4b" memberName="frequency"
         virtualName="" explicitFocusOrder="0" pos="496 3 94 20" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="1b4eae892bfe6bdb" memberName="rowLabel"
         virtualName="" explicitFocusOrder="0" pos="0 4 44 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="01" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: noteTableAbsoluteRow_png, 769, "../../UI/NoteTableAbsoluteRow.png"
static const unsigned char resource_NoteTableRow_noteTableAbsoluteRow_png[] = {
        137
      , 80
      , 78
      , 71
      , 13
      , 10
      , 26
      , 10
      , 0
      , 0
      , 0
      , 13
      , 73
      , 72
      , 68
      , 82
      , 0
      , 0
      , 2
      , 80
      , 0
      , 0
      , 0
      , 24
      , 8
      , 6
      , 0
      , 0
      , 0
      , 53
      , 118
      , 195
      , 109
      , 0
      , 0
      , 0
      , 9
      , 112
      , 72
      , 89
      , 115
      , 0
      , 0
      , 14
      , 195
      , 0
      , 0
      , 14
      , 195
      , 1
      , 199
      , 111
      , 168
      , 100
      , 0
      , 0
      , 0
      , 25
      , 116
      , 69
      , 88
      , 116
      , 83
      , 111
      , 102
      , 116
      , 119
      , 97
      , 114
      , 101
      , 0
      , 119
      , 119
      , 119
      , 46
      , 105
      , 110
      , 107
      , 115
      , 99
      , 97
      , 112
      , 101
      , 46
      , 111
      , 114
      , 103
      , 155
      , 238
      , 60
      , 26
      , 0
      , 0
      , 2
      , 142
      , 73
      , 68
      , 65
      , 84
      , 120
      , 156
      , 237
      , 220
      , 59
      , 110
      , 219
      , 64
      , 16
      , 198
      , 241
      , 145
      , 32
      , 193
      , 128
      , 11
      , 195
      , 165
      , 239
      , 160
      , 70
      , 133
      , 2
      , 24
      , 144
      , 11
      , 95
      , 69
      , 151
      , 136
      , 144
      , 78
      , 93
      , 224
      , 84
      , 190
      , 129
      , 175
      , 226
      , 34
      , 2
      , 12
      , 88
      , 133
      , 27
      , 223
      , 35
      , 113
      , 33
      , 88
      , 161
      , 96
      , 166
      , 18
      , 130
      , 16
      , 33
      , 246
      , 193
      , 221
      , 204
      , 62
      , 254
      , 191
      , 206
      , 15
      , 146
      , 67
      , 238
      , 154
      , 88
      , 126
      , 26
      , 115
      , 116
      , 117
      , 121
      , 223
      , 10
      , 0
      , 0
      , 0
      , 172
      , 141
      , 181
      , 11
      , 0
      , 0
      , 0
      , 200
      , 205
      , 68
      , 187
      , 0
      , 0
      , 248
      , 151
      , 197
      , 151
      , 27
      , 25
      , 125
      , 104
      , 87
      , 17
      , 95
      , 59
      , 22
      , 217
      , 125
      , 253
      , 174
      , 93
      , 6
      , 50
      , 179
      , 248
      , 188
      , 148
      , 201
      , 249
      , 84
      , 187
      , 140
      , 42
      , 29
      , 247
      , 141
      , 236
      , 190
      , 109
      , 89
      , 64
      , 1
      , 72
      , 212
      , 71
      , 43
      , 207
      , 119
      , 91
      , 237
      , 42
      , 162
      , 91
      , 172
      , 151
      , 218
      , 37
      , 32
      , 67
      , 147
      , 243
      , 169
      , 188
      , 62
      , 188
      , 72
      , 243
      , 118
      , 208
      , 46
      , 165
      , 42
      , 211
      , 139
      , 51
      , 153
      , 173
      , 230
      , 34
      , 66
      , 2
      , 5
      , 0
      , 64
      , 150
      , 126
      , 253
      , 124
      , 151
      , 195
      , 143
      , 119
      , 237
      , 50
      , 170
      , 210
      , 182
      , 127
      , 218
      , 198
      , 233
      , 129
      , 2
      , 0
      , 0
      , 112
      , 68
      , 2
      , 53
      , 192
      , 245
      , 230
      , 246
      , 175
      , 175
      , 159
      , 54
      , 143
      , 42
      , 117
      , 160
      , 124
      , 166
      , 185
      , 198
      , 92
      , 172
      , 71
      , 119
      , 172
      , 77
      , 152
      , 11
      , 64
      , 28
      , 36
      , 80
      , 0
      , 0
      , 0
      , 142
      , 138
      , 78
      , 160
      , 92
      , 158
      , 212
      , 92
      , 158
      , 210
      , 250
      , 246
      , 123
      , 250
      , 126
      , 174
      , 233
      , 64
      , 223
      , 121
      , 197
      , 170
      , 55
      , 151
      , 235
      , 146
      , 162
      , 190
      , 185
      , 22
      , 251
      , 120
      , 39
      , 140
      , 85
      , 58
      , 24
      , 11
      , 64
      , 71
      , 209
      , 11
      , 40
      , 17
      , 187
      , 155
      , 139
      , 107
      , 36
      , 14
      , 0
      , 0
      , 234
      , 86
      , 252
      , 2
      , 42
      , 36
      , 219
      , 62
      , 148
      , 208
      , 233
      , 128
      , 237
      , 2
      , 207
      , 148
      , 124
      , 153
      , 126
      , 255
      , 244
      , 181
      , 105
      , 59
      , 223
      , 126
      , 156
      , 208
      , 251
      , 237
      , 170
      , 241
      , 73
      , 220
      , 118
      , 110
      , 184
      , 94
      , 59
      , 198
      , 170
      , 60
      , 190
      , 247
      , 17
      , 219
      , 237
      , 125
      , 183
      , 235
      , 110
      , 63
      , 180
      , 223
      , 47
      , 244
      , 92
      , 239
      , 219
      , 206
      , 245
      , 120
      , 244
      , 49
      , 150
      , 135
      , 30
      , 40
      , 0
      , 0
      , 0
      , 71
      , 36
      , 80
      , 3
      , 248
      , 126
      , 244
      , 103
      , 219
      , 107
      , 228
      , 251
      , 68
      , 162
      , 149
      , 148
      , 153
      , 248
      , 158
      , 95
      , 170
      , 231
      , 147
      , 3
      , 223
      , 107
      , 199
      , 88
      , 229
      , 195
      , 247
      , 62
      , 97
      , 59
      , 54
      , 190
      , 99
      , 58
      , 52
      , 41
      , 114
      , 21
      , 106
      , 238
      , 133
      , 58
      , 63
      , 148
      , 143
      , 4
      , 10
      , 0
      , 0
      , 192
      , 17
      , 9
      , 212
      , 0
      , 161
      , 62
      , 75
      , 55
      , 165
      , 0
      , 221
      , 159
      , 155
      , 246
      , 87
      , 58
      , 154
      , 254
      , 237
      , 251
      , 202
      , 180
      , 165
      , 94
      , 95
      , 9
      , 66
      , 253
      , 253
      , 251
      , 38
      , 220
      , 169
      , 202
      , 165
      , 78
      , 228
      , 139
      , 4
      , 10
      , 0
      , 0
      , 192
      , 17
      , 9
      , 84
      , 6
      , 76
      , 253
      , 38
      , 181
      , 245
      , 147
      , 212
      , 114
      , 158
      , 54
      , 82
      , 79
      , 162
      , 24
      , 171
      , 242
      , 184
      , 246
      , 88
      , 153
      , 18
      , 244
      , 88
      , 82
      , 155
      , 123
      , 218
      , 215
      , 3
      , 225
      , 145
      , 64
      , 1
      , 0
      , 0
      , 56
      , 42
      , 62
      , 129
      , 74
      , 113
      , 149
      , 239
      , 251
      , 95
      , 120
      , 125
      , 76
      , 239
      , 115
      , 26
      , 122
      , 60
      , 223
      , 222
      , 44
      , 19
      , 211
      , 126
      , 232
      , 5
      , 27
      , 46
      , 212
      , 181
      , 99
      , 172
      , 234
      , 53
      , 116
      , 76
      , 93
      , 223
      , 159
      , 228
      , 123
      , 127
      , 249
      , 223
      , 115
      , 207
      , 247
      , 120
      , 188
      , 255
      , 169
      , 28
      , 69
      , 47
      , 160
      , 152
      , 136
      , 0
      , 0
      , 32
      , 134
      , 209
      , 213
      , 229
      , 125
      , 171
      , 93
      , 4
      , 0
      , 116
      , 45
      , 214
      , 75
      , 217
      , 221
      , 109
      , 181
      , 203
      , 136
      , 174
      , 150
      , 243
      , 236
      , 170
      , 45
      , 121
      , 9
      , 253
      , 118
      , 254
      , 235
      , 205
      , 173
      , 188
      , 62
      , 188
      , 72
      , 243
      , 118
      , 240
      , 47
      , 10
      , 206
      , 166
      , 23
      , 103
      , 50
      , 91
      , 205
      , 229
      , 105
      , 243
      , 88
      , 118
      , 2
      , 5
      , 32
      , 99
      , 227
      , 145
      , 124
      , 90
      , 223
      , 104
      , 87
      , 17
      , 93
      , 75
      , 39
      , 42
      , 60
      , 28
      , 247
      , 141
      , 204
      , 86
      , 115
      , 237
      , 50
      , 170
      , 116
      , 220
      , 55
      , 34
      , 66
      , 2
      , 5
      , 0
      , 0
      , 224
      , 140
      , 103
      , 31
      , 0
      , 0
      , 0
      , 71
      , 191
      , 1
      , 125
      , 54
      , 133
      , 110
      , 56
      , 180
      , 238
      , 36
      , 0
      , 0
      , 0
      , 0
      , 73
      , 69
      , 78
      , 68
      , 174
      , 66
      , 96
      , 130
      , 0
      , 0
};
const char* NoteTableRow::noteTableAbsoluteRow_png     = ( const char* ) resource_NoteTableRow_noteTableAbsoluteRow_png;
const int   NoteTableRow::noteTableAbsoluteRow_pngSize = 769;

// JUCER_RESOURCE: noteTableRelativeRow_png, 838, "../../UI/NoteTableRelativeRow.png"
static const unsigned char resource_NoteTableRow_noteTableRelativeRow_png[] = {
        137
      , 80
      , 78
      , 71
      , 13
      , 10
      , 26
      , 10
      , 0
      , 0
      , 0
      , 13
      , 73
      , 72
      , 68
      , 82
      , 0
      , 0
      , 2
      , 80
      , 0
      , 0
      , 0
      , 24
      , 8
      , 6
      , 0
      , 0
      , 0
      , 53
      , 118
      , 195
      , 109
      , 0
      , 0
      , 0
      , 9
      , 112
      , 72
      , 89
      , 115
      , 0
      , 0
      , 14
      , 195
      , 0
      , 0
      , 14
      , 195
      , 1
      , 199
      , 111
      , 168
      , 100
      , 0
      , 0
      , 0
      , 25
      , 116
      , 69
      , 88
      , 116
      , 83
      , 111
      , 102
      , 116
      , 119
      , 97
      , 114
      , 101
      , 0
      , 119
      , 119
      , 119
      , 46
      , 105
      , 110
      , 107
      , 115
      , 99
      , 97
      , 112
      , 101
      , 46
      , 111
      , 114
      , 103
      , 155
      , 238
      , 60
      , 26
      , 0
      , 0
      , 2
      , 211
      , 73
      , 68
      , 65
      , 84
      , 120
      , 156
      , 237
      , 220
      , 189
      , 110
      , 26
      , 65
      , 16
      , 192
      , 241
      , 1
      , 129
      , 136
      , 92
      , 88
      , 148
      , 126
      , 7
      , 26
      , 34
      , 17
      , 201
      , 18
      , 46
      , 242
      , 42
      , 188
      , 65
      , 170
      , 160
      , 116
      , 116
      , 145
      , 83
      , 241
      , 6
      , 126
      , 21
      , 23
      , 65
      , 66
      , 10
      , 82
      , 220
      , 248
      , 61
      , 28
      , 23
      , 8
      , 2
      , 242
      , 165
      , 66
      , 145
      , 80
      , 200
      , 238
      , 236
      , 199
      , 237
      , 237
      , 222
      , 255
      , 215
      , 88
      , 150
      , 247
      , 238
      , 134
      , 189
      , 229
      , 124
      , 51
      , 12
      , 215
      , 185
      , 25
      , 46
      , 43
      , 1
      , 0
      , 0
      , 128
      , 181
      , 110
      , 234
      , 0
      , 0
      , 0
      , 0
      , 114
      , 211
      , 75
      , 29
      , 0
      , 0
      , 252
      , 203
      , 228
      , 203
      , 157
      , 116
      , 222
      , 82
      , 71
      , 17
      , 95
      , 213
      , 21
      , 217
      , 124
      , 253
      , 158
      , 58
      , 12
      , 100
      , 102
      , 242
      , 121
      , 42
      , 189
      , 171
      , 126
      , 234
      , 48
      , 90
      , 233
      , 184
      , 61
      , 200
      , 230
      , 219
      , 138
      , 27
      , 40
      , 0
      , 13
      , 245
      , 86
      , 201
      , 143
      , 251
      , 85
      , 234
      , 40
      , 162
      , 155
      , 204
      , 167
      , 169
      , 67
      , 64
      , 134
      , 122
      , 87
      , 125
      , 121
      , 126
      , 120
      , 146
      , 195
      , 235
      , 62
      , 117
      , 40
      , 173
      , 210
      , 191
      , 30
      , 200
      , 104
      , 54
      , 22
      , 17
      , 42
      , 80
      , 0
      , 0
      , 100
      , 233
      , 247
      , 175
      , 157
      , 236
      , 95
      , 118
      , 169
      , 195
      , 104
      , 149
      , 170
      , 250
      , 219
      , 54
      , 78
      , 15
      , 20
      , 0
      , 0
      , 128
      , 18
      , 21
      , 40
      , 133
      , 219
      , 197
      , 71
      , 171
      , 113
      , 235
      , 197
      , 99
      , 212
      , 56
      , 208
      , 92
      , 166
      , 53
      , 194
      , 218
      , 128
      , 47
      , 219
      , 235
      , 208
      , 9
      , 107
      , 14
      , 136
      , 131
      , 10
      , 20
      , 0
      , 0
      , 128
      , 82
      , 209
      , 21
      , 40
      , 77
      , 166
      , 230
      , 146
      , 165
      , 157
      , 111
      , 115
      , 58
      , 222
      , 233
      , 167
      , 111
      , 230
      , 119
      , 41
      , 254
      , 88
      , 25
      , 229
      , 249
      , 241
      , 76
      , 199
      , 209
      , 142
      , 47
      , 153
      , 105
      , 46
      , 108
      , 215
      , 134
      , 246
      , 156
      , 215
      , 189
      , 70
      , 180
      , 88
      , 35
      , 241
      , 49
      , 167
      , 64
      , 26
      , 69
      , 223
      , 64
      , 137
      , 216
      , 93
      , 92
      , 180
      , 37
      , 113
      , 0
      , 0
      , 208
      , 110
      , 197
      , 223
      , 64
      , 53
      , 137
      , 182
      , 63
      , 230
      , 244
      , 187
      , 237
      , 13
      , 158
      , 118
      , 255
      , 166
      , 241
      , 166
      , 234
      , 129
      , 111
      , 133
      , 74
      , 251
      , 247
      , 115
      , 37
      , 101
      , 222
      , 177
      , 171
      , 127
      , 174
      , 253
      , 123
      , 117
      , 175
      , 41
      , 196
      , 227
      , 219
      , 195
      , 233
      , 250
      , 126
      , 212
      , 30
      , 183
      , 238
      , 235
      , 70
      , 93
      , 243
      , 226
      , 251
      , 186
      , 208
      , 60
      , 244
      , 64
      , 1
      , 0
      , 0
      , 40
      , 81
      , 129
      , 242
      , 96
      , 219
      , 127
      , 18
      , 170
      , 63
      , 198
      , 196
      , 148
      , 33
      , 157
      , 239
      , 223
      , 53
      , 3
      , 138
      , 221
      , 119
      , 83
      , 215
      , 124
      , 53
      , 193
      , 165
      , 185
      , 188
      , 52
      , 7
      , 190
      , 227
      , 109
      , 231
      , 202
      , 245
      , 28
      , 144
      , 85
      , 215
      , 207
      , 117
      , 142
      , 109
      , 207
      , 169
      , 235
      , 90
      , 240
      , 173
      , 20
      , 105
      , 133
      , 186
      , 110
      , 132
      , 122
      , 125
      , 40
      , 31
      , 21
      , 40
      , 0
      , 0
      , 0
      , 37
      , 42
      , 80
      , 1
      , 185
      , 102
      , 247
      , 161
      , 212
      , 213
      , 12
      , 175
      , 237
      , 205
      , 242
      , 85
      , 114
      , 147
      , 191
      , 54
      , 155
      , 245
      , 29
      , 239
      , 90
      , 61
      , 44
      , 249
      , 28
      , 228
      , 46
      , 84
      , 229
      , 35
      , 245
      , 245
      , 43
      , 180
      , 92
      , 226
      , 68
      , 190
      , 168
      , 64
      , 1
      , 0
      , 0
      , 40
      , 81
      , 129
      , 242
      , 112
      , 41
      , 187
      , 55
      , 101
      , 114
      , 161
      , 63
      , 43
      , 175
      , 187
      , 215
      , 192
      , 86
      , 168
      , 234
      , 7
      , 189
      , 5
      , 254
      , 180
      , 253
      , 113
      , 182
      , 219
      , 163
      , 125
      , 180
      , 61
      , 86
      , 166
      , 247
      , 127
      , 44
      , 77
      , 91
      , 179
      , 169
      , 231
      , 3
      , 225
      , 81
      , 129
      , 2
      , 0
      , 0
      , 80
      , 234
      , 220
      , 12
      , 151
      , 149
      , 121
      , 88
      , 158
      , 66
      , 63
      , 137
      , 188
      , 105
      , 207
      , 39
      , 9
      , 253
      , 60
      , 19
      , 211
      , 126
      , 108
      , 123
      , 159
      , 108
      , 191
      , 189
      , 231
      , 219
      , 119
      , 211
      , 180
      , 12
      , 83
      , 36
      , 221
      , 220
      , 132
      , 122
      , 6
      , 143
      , 118
      , 123
      , 223
      , 190
      , 153
      , 255
      , 109
      , 63
      , 153
      , 79
      , 101
      , 115
      , 191
      , 178
      , 218
      , 127
      , 206
      , 180
      , 175
      , 51
      , 214
      , 55
      , 43
      , 181
      , 219
      , 159
      , 243
      , 221
      , 95
      , 168
      , 235
      , 153
      , 239
      , 117
      , 179
      , 238
      , 231
      , 213
      , 249
      , 156
      , 207
      , 159
      , 203
      , 181
      , 236
      , 95
      , 118
      , 86
      , 227
      , 17
      , 198
      , 96
      , 248
      , 78
      , 222
      , 127
      , 186
      , 149
      , 245
      , 226
      , 177
      , 236
      , 143
      , 240
      , 154
      , 248
      , 15
      , 22
      , 0
      , 0
      , 228
      , 175
      , 232
      , 10
      , 20
      , 128
      , 124
      , 81
      , 129
      , 42
      , 91
      , 219
      , 158
      , 163
      , 20
      , 163
      , 130
      , 247
      , 252
      , 240
      , 36
      , 135
      , 215
      , 189
      , 123
      , 80
      , 80
      , 235
      , 95
      , 15
      , 100
      , 52
      , 27
      , 151
      , 95
      , 129
      , 2
      , 144
      , 177
      , 110
      , 71
      , 62
      , 204
      , 239
      , 82
      , 71
      , 17
      , 93
      , 69
      , 39
      , 42
      , 28
      , 28
      , 183
      , 7
      , 25
      , 205
      , 198
      , 169
      , 195
      , 104
      , 165
      , 227
      , 246
      , 32
      , 34
      , 84
      , 160
      , 0
      , 0
      , 0
      , 212
      , 200
      , 125
      , 0
      , 0
      , 0
      , 148
      , 254
      , 0
      , 86
      , 226
      , 185
      , 90
      , 65
      , 200
      , 183
      , 14
      , 0
      , 0
      , 0
      , 0
      , 73
      , 69
      , 78
      , 68
      , 174
      , 66
      , 96
      , 130
      , 0
      , 0
};
const char* NoteTableRow::noteTableRelativeRow_png     = ( const char* ) resource_NoteTableRow_noteTableRelativeRow_png;
const int   NoteTableRow::noteTableRelativeRow_pngSize = 838;


//[EndFile] You can add extra defines here...
//[/EndFile]
