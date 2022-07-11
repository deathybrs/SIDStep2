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
//[/Headers]

#include "PulseTableRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PulseTableRow::PulseTableRow (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    AbstractPulseTableRow (
                           dispatcher )
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    rowLabel . reset (
                      new Label (
                                 "new label"
                               , TRANS (
                                        "01" ) ) );
    addAndMakeVisible (
                       rowLabel . get () );
    rowLabel -> setFont (
                         Font (
                               "C64 Pro Mono"
                             , 12.00F
                             , Font::plain ) . withTypefaceStyle (
                                                                  "Regular" ) );
    rowLabel -> setJustificationType (
                                      Justification::centredRight );
    rowLabel -> setEditable (
                             false
                           , false
                           , false );
    rowLabel -> setColour (
                           Label::textColourId
                         , Colour (
                                   0xff5090d0 ) );
    rowLabel -> setColour (
                           TextEditor::textColourId
                         , Colours::black );
    rowLabel -> setColour (
                           TextEditor::backgroundColourId
                         , Colour (
                                   0x00000000 ) );
    rowLabel -> setBounds (
                           0
                         , 4
                         , 44
                         , 18 );
    pulseCycle . reset (
                        new Label (
                                   "new label"
                                 , String () ) );
    addAndMakeVisible (
                       pulseCycle . get () );
    pulseCycle -> setFont (
                           Font (
                                 "C64 Pro"
                               , 15.00F
                               , Font::plain ) . withTypefaceStyle (
                                                                    "Regular" ) );
    pulseCycle -> setJustificationType (
                                        Justification::centredLeft );
    pulseCycle -> setEditable (
                               true
                             , true
                             , false );
    pulseCycle -> setColour (
                             Label::textColourId
                           , Colour (
                                     0xff5090d0 ) );
    pulseCycle -> setColour (
                             TextEditor::textColourId
                           , Colours::black );
    pulseCycle -> setColour (
                             TextEditor::backgroundColourId
                           , Colour (
                                     0x00000000 ) );
    pulseCycle -> addListener (
                               this );
    pulseCycle -> setBounds (
                             216
                           , 3
                           , 136
                           , 20 );
    cachedImage_pulseTableRow_png_1 = ImageCache::getFromMemory (
                                                                 pulseTableRow_png
                                                               , pulseTableRow_pngSize );

    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             590
           , 24 );


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PulseTableRow::~PulseTableRow ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rowLabel   = nullptr;
    pulseCycle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}


//==============================================================================
void
    PulseTableRow::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g . fillAll (
                 Colour (
                         0xff323e44 ) );
    {
        const auto x      = 0;
        const auto y      = 0;
        const auto width  = 592;
        const auto height = 24;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g . setColour (
                       Colours::black );
        g . drawImageWithin (
                             cachedImage_pulseTableRow_png_1
                           , x
                           , y
                           , width
                           , height
                           , RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize
                           , false );
    }

    //[UserPaint] Add your own custom painting code here..
    if ( selected )
    {
        const Colour lt_blue (
                              0xff5090d0 );
        g . setColour (
                       lt_blue );
        Path p;
        p . addTriangle (
                         0.0F
                       , 0.0F
                       , 12.0F
                       , 12.0F
                       , 0.0F
                       , 24.0F );
        g . fillPath (
                      p );
    }
    //[/UserPaint]
}

void
    PulseTableRow::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void
    PulseTableRow::labelTextChanged (
            Label* label_that_has_changed
            )
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if ( label_that_has_changed == pulseCycle . get () )
    {
        //[UserLabelCode_pulseCycle] -- add your label text handling code here..
        //[/UserLabelCode_pulseCycle]
    }

    //[UserlabelTextChanged_Post]
    dispatcher -> pulseTableSelectionChangedListeners -> call (
                                                               &PulseTableSelectionChanged::onPulseTableSelectionChanged
                                                             , static_cast < unsigned int > ( row ) );
    dispatcher -> pulseTableRowChangedListeners -> call (
                                                         &PulseTableRowChanged::onPulseTableRowChanged
                                                       , static_cast < unsigned int > ( pulseCycle -> getText () . getIntValue () ) );
    dispatcher -> bankRepaintWaveformListeners -> call (
                                                        &BankRepaintWaveform::onBankRepaintWaveform );
    //[/UserlabelTextChanged_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


auto
    PulseTableRow::Get () const -> unsigned { return static_cast < unsigned > ( pulseCycle -> getText () . getIntValue () ); }

void
    PulseTableRow::Set (
            const unsigned row_num
          , const unsigned value
            )
{
    row = static_cast < int > ( row_num );
    rowLabel -> setText (
                         String (
                                 row_num + 1 ) . paddedLeft (
                                                             '0'
                                                           , 2 )
                       , dontSendNotification );
    pulseCycle -> setText (
                           String (
                                   value )
                         , dontSendNotification );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PulseTableRow" componentName=""
                 parentClasses="public AbstractPulseTableRow" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="590" initialHeight="24">
  <BACKGROUND backgroundColour="ff323e44">
    <IMAGE pos="0 0 592 24" resource="pulseTableRow_png" opacity="1.0" mode="2"/>
  </BACKGROUND>
  <LABEL name="new label" id="1b4eae892bfe6bdb" memberName="rowLabel"
         virtualName="" explicitFocusOrder="0" pos="0 4 44 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="01" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="718fa581b1eabe4b" memberName="pulseCycle"
         virtualName="" explicitFocusOrder="0" pos="216 3 136 20" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: pulseTableRow_png, 686, "../../UI/PulseTableRow.png"
static const unsigned char resource_PulseTableRow_pulseTableRow_png[] = {
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
      , 59
      , 73
      , 68
      , 65
      , 84
      , 120
      , 156
      , 237
      , 221
      , 49
      , 78
      , 219
      , 96
      , 20
      , 7
      , 240
      , 23
      , 226
      , 40
      , 42
      , 82
      , 37
      , 70
      , 38
      , 6
      , 164
      , 170
      , 67
      , 71
      , 150
      , 178
      , 117
      , 96
      , 239
      , 212
      , 147
      , 112
      , 1
      , 142
      , 192
      , 5
      , 122
      , 130
      , 78
      , 244
      , 4
      , 29
      , 59
      , 209
      , 137
      , 129
      , 86
      , 98
      , 169
      , 132
      , 4
      , 234
      , 82
      , 32
      , 1
      , 129
      , 19
      , 58
      , 101
      , 9
      , 141
      , 98
      , 199
      , 177
      , 62
      , 199
      , 249
      , 253
      , 22
      , 15
      , 73
      , 236
      , 151
      , 23
      , 197
      , 74
      , 254
      , 121
      , 254
      , 210
      , 217
      , 222
      , 58
      , 126
      , 14
      , 0
      , 0
      , 10
      , 203
      , 82
      , 23
      , 0
      , 109
      , 149
      , 109
      , 246
      , 34
      , 235
      , 123
      , 139
      , 241
      , 210
      , 227
      , 205
      , 67
      , 140
      , 71
      , 190
      , 187
      , 194
      , 42
      , 115
      , 118
      , 135
      , 26
      , 116
      , 95
      , 101
      , 177
      , 119
      , 184
      , 31
      , 157
      , 238
      , 70
      , 234
      , 82
      , 104
      , 160
      , 235
      , 211
      , 203
      , 184
      , 248
      , 250
      , 51
      , 117
      , 25
      , 64
      , 5
      , 62
      , 64
      , 65
      , 13
      , 54
      , 178
      , 110
      , 116
      , 186
      , 27
      , 113
      , 113
      , 114
      , 30
      , 131
      , 171
      , 187
      , 212
      , 229
      , 208
      , 32
      , 59
      , 7
      , 187
      , 209
      , 237
      , 247
      , 82
      , 151
      , 1
      , 84
      , 228
      , 3
      , 20
      , 212
      , 232
      , 254
      , 207
      , 48
      , 6
      , 151
      , 183
      , 169
      , 203
      , 160
      , 65
      , 242
      , 251
      , 60
      , 117
      , 9
      , 192
      , 18
      , 248
      , 125
      , 1
      , 0
      , 160
      , 164
      , 86
      , 39
      , 80
      , 239
      , 143
      , 62
      , 20
      , 186
      , 223
      , 247
      , 163
      , 111
      , 181
      , 214
      , 209
      , 22
      , 243
      , 250
      , 169
      , 143
      , 0
      , 172
      , 11
      , 9
      , 20
      , 0
      , 64
      , 73
      , 173
      , 78
      , 160
      , 166
      , 77
      , 39
      , 36
      , 147
      , 68
      , 101
      , 178
      , 173
      , 154
      , 160
      , 204
      , 74
      , 104
      , 86
      , 61
      , 153
      , 153
      , 126
      , 94
      , 117
      , 247
      , 177
      , 172
      , 182
      , 246
      , 29
      , 128
      , 230
      , 146
      , 64
      , 1
      , 0
      , 148
      , 180
      , 86
      , 9
      , 84
      , 81
      , 69
      , 19
      , 151
      , 233
      , 219
      , 39
      , 219
      , 162
      , 179
      , 87
      , 139
      , 206
      , 104
      , 53
      , 109
      , 22
      , 105
      , 214
      , 241
      , 22
      , 237
      , 227
      , 172
      , 219
      , 103
      , 29
      , 119
      , 217
      , 125
      , 151
      , 92
      , 1
      , 48
      , 143
      , 4
      , 10
      , 0
      , 160
      , 164
      , 181
      , 74
      , 160
      , 154
      , 50
      , 43
      , 51
      , 47
      , 121
      , 89
      , 244
      , 113
      , 169
      , 103
      , 145
      , 150
      , 101
      , 209
      , 254
      , 84
      , 221
      , 111
      , 91
      , 250
      , 7
      , 64
      , 253
      , 36
      , 80
      , 0
      , 0
      , 37
      , 173
      , 85
      , 2
      , 213
      , 148
      , 68
      , 97
      , 122
      , 102
      , 103
      , 209
      , 100
      , 172
      , 232
      , 204
      , 15
      , 255
      , 167
      , 127
      , 0
      , 44
      , 74
      , 2
      , 5
      , 0
      , 80
      , 210
      , 90
      , 37
      , 80
      , 77
      , 51
      , 239
      , 234
      , 181
      , 121
      , 179
      , 56
      , 77
      , 73
      , 212
      , 138
      , 94
      , 149
      , 216
      , 180
      , 196
      , 167
      , 41
      , 253
      , 3
      , 96
      , 245
      , 72
      , 160
      , 0
      , 0
      , 74
      , 234
      , 108
      , 111
      , 29
      , 63
      , 167
      , 46
      , 162
      , 46
      , 85
      , 175
      , 230
      , 42
      , 187
      , 78
      , 83
      , 209
      , 245
      , 133
      , 170
      , 254
      , 71
      , 95
      , 170
      , 117
      , 140
      , 150
      , 117
      , 220
      , 162
      , 175
      , 203
      , 178
      , 250
      , 153
      , 98
      , 29
      , 173
      , 222
      , 235
      , 126
      , 236
      , 29
      , 238
      , 199
      , 217
      , 231
      , 31
      , 113
      , 251
      , 251
      , 111
      , 229
      , 253
      , 209
      , 30
      , 111
      , 62
      , 189
      , 139
      , 136
      , 136
      , 95
      , 95
      , 206
      , 18
      , 87
      , 2
      , 84
      , 33
      , 129
      , 2
      , 0
      , 40
      , 169
      , 213
      , 9
      , 20
      , 105
      , 173
      , 243
      , 138
      , 223
      , 147
      , 4
      , 234
      , 226
      , 228
      , 60
      , 6
      , 87
      , 119
      , 169
      , 203
      , 161
      , 65
      , 118
      , 14
      , 118
      , 35
      , 191
      , 207
      , 37
      , 80
      , 176
      , 226
      , 12
      , 145
      , 67
      , 13
      , 198
      , 249
      , 40
      , 158
      , 71
      , 227
      , 216
      , 253
      , 248
      , 54
      , 117
      , 41
      , 52
      , 208
      , 245
      , 233
      , 101
      , 234
      , 18
      , 128
      , 138
      , 36
      , 80
      , 80
      , 147
      , 108
      , 179
      , 23
      , 89
      , 223
      , 119
      , 20
      , 94
      , 122
      , 188
      , 121
      , 136
      , 241
      , 200
      , 169
      , 23
      , 86
      , 153
      , 179
      , 59
      , 212
      , 36
      , 31
      , 62
      , 69
      , 62
      , 124
      , 74
      , 93
      , 6
      , 0
      , 53
      , 248
      , 7
      , 212
      , 173
      , 215
      , 129
      , 15
      , 226
      , 26
      , 10
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
const char* PulseTableRow::pulseTableRow_png     = ( const char* ) resource_PulseTableRow_pulseTableRow_png;
const int   PulseTableRow::pulseTableRow_pngSize = 686;


//[EndFile] You can add extra defines here...
//[/EndFile]
