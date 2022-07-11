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
// ReSharper disable CppClangTidyModernizeMakeUnique
#include "../Programs/Bank.h"
#include "../SIDProgram.h"
//[/Headers]

#include "WavetableRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WavetableRow::WavetableRow (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    AbstractWavetableRow (
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
    triangleCheckbox . reset (
                              new ToggleButton (
                                                "new toggle button" ) );
    addAndMakeVisible (
                       triangleCheckbox . get () );
    triangleCheckbox -> setButtonText (
                                       String () );
    triangleCheckbox -> addListener (
                                     this );
    triangleCheckbox -> setBounds (
                                   53
                                 , 6
                                 , 14
                                 , 14 );
    sawtoothCheckbox . reset (
                              new ToggleButton (
                                                "new toggle button" ) );
    addAndMakeVisible (
                       sawtoothCheckbox . get () );
    sawtoothCheckbox -> setButtonText (
                                       String () );
    sawtoothCheckbox -> addListener (
                                     this );
    sawtoothCheckbox -> setBounds (
                                   109
                                 , 6
                                 , 14
                                 , 14 );
    pulseCheckbox . reset (
                           new ToggleButton (
                                             "new toggle button" ) );
    addAndMakeVisible (
                       pulseCheckbox . get () );
    pulseCheckbox -> setButtonText (
                                    String () );
    pulseCheckbox -> addListener (
                                  this );
    pulseCheckbox -> setBounds (
                                165
                              , 6
                              , 14
                              , 14 );
    noiseCheckbox . reset (
                           new ToggleButton (
                                             "new toggle button" ) );
    addAndMakeVisible (
                       noiseCheckbox . get () );
    noiseCheckbox -> setButtonText (
                                    String () );
    noiseCheckbox -> addListener (
                                  this );
    noiseCheckbox -> setBounds (
                                221
                              , 6
                              , 14
                              , 14 );
    testCheckbox . reset (
                          new ToggleButton (
                                            "new toggle button" ) );
    addAndMakeVisible (
                       testCheckbox . get () );
    testCheckbox -> setButtonText (
                                   String () );
    testCheckbox -> addListener (
                                 this );
    testCheckbox -> setBounds (
                               277
                             , 6
                             , 14
                             , 14 );
    ringCheckbox . reset (
                          new ToggleButton (
                                            "new toggle button" ) );
    addAndMakeVisible (
                       ringCheckbox . get () );
    ringCheckbox -> setButtonText (
                                   String () );
    ringCheckbox -> addListener (
                                 this );
    ringCheckbox -> setBounds (
                               349
                             , 6
                             , 14
                             , 14 );
    synCheckbox . reset (
                         new ToggleButton (
                                           "new toggle button" ) );
    addAndMakeVisible (
                       synCheckbox . get () );
    synCheckbox -> setButtonText (
                                  String () );
    synCheckbox -> addListener (
                                this );
    synCheckbox -> setBounds (
                              421
                            , 6
                            , 14
                            , 14 );
    gateCheckbox . reset (
                          new ToggleButton (
                                            "new toggle button" ) );
    addAndMakeVisible (
                       gateCheckbox . get () );
    gateCheckbox -> setButtonText (
                                   String () );
    gateCheckbox -> addListener (
                                 this );
    gateCheckbox -> setBounds (
                               493
                             , 6
                             , 14
                             , 14 );
    cachedImage_wavetableRowBackdrop_png_1 = ImageCache::getFromMemory (
                                                                        wavetableRowBackdrop_png
                                                                      , wavetableRowBackdrop_pngSize );

    //[UserPreSize]
    testCheckbox -> setEnabled (
                                false );
    //[/UserPreSize]

    setSize (
             590
           , 24 );


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WavetableRow::~WavetableRow ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rowLabel         = nullptr;
    triangleCheckbox = nullptr;
    sawtoothCheckbox = nullptr;
    pulseCheckbox    = nullptr;
    noiseCheckbox    = nullptr;
    testCheckbox     = nullptr;
    ringCheckbox     = nullptr;
    synCheckbox      = nullptr;
    gateCheckbox     = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //bank = nullptr;
    //[/Destructor]
}

//==============================================================================
void
    WavetableRow::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g . fillAll (
                 Colours::white );
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
                             cachedImage_wavetableRowBackdrop_png_1
                           , x
                           , y
                           , width
                           , height
                           , RectanglePlacement::centred
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
    WavetableRow::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void
    WavetableRow::buttonClicked (
            Button* button_that_was_clicked
            )
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if ( button_that_was_clicked == triangleCheckbox . get () )
    {
        //[UserButtonCode_triangleCheckbox] -- add your button handler code here..
        //[/UserButtonCode_triangleCheckbox]
    }
    else if ( button_that_was_clicked == sawtoothCheckbox . get () )
    {
        //[UserButtonCode_sawtoothCheckbox] -- add your button handler code here..
        //[/UserButtonCode_sawtoothCheckbox]
    }
    else if ( button_that_was_clicked == pulseCheckbox . get () )
    {
        //[UserButtonCode_pulseCheckbox] -- add your button handler code here..
        //[/UserButtonCode_pulseCheckbox]
    }
    else if ( button_that_was_clicked == noiseCheckbox . get () )
    {
        //[UserButtonCode_noiseCheckbox] -- add your button handler code here..
        //[/UserButtonCode_noiseCheckbox]
    }
    else if ( button_that_was_clicked == testCheckbox . get () )
    {
        //[UserButtonCode_testCheckbox] -- add your button handler code here..
        //[/UserButtonCode_testCheckbox]
    }
    else if ( button_that_was_clicked == ringCheckbox . get () )
    {
        //[UserButtonCode_ringCheckbox] -- add your button handler code here..
        //[/UserButtonCode_ringCheckbox]
    }
    else if ( button_that_was_clicked == synCheckbox . get () )
    {
        //[UserButtonCode_synCheckbox] -- add your button handler code here..
        //[/UserButtonCode_synCheckbox]
    }
    else if ( button_that_was_clicked == gateCheckbox . get () )
    {
        //[UserButtonCode_gateCheckbox] -- add your button handler code here..
        //[/UserButtonCode_gateCheckbox]
    }

    //[UserbuttonClicked_Post]
    dispatcher -> wavetableSelectionChangedListeners -> call (
                                                              &WavetableSelectionChanged::onWavetableSelectionChanged
                                                            , static_cast < unsigned int > ( row ) );
    dispatcher -> wavetableRowChangedListeners -> call (
                                                        &WavetableRowChanged::onWavetableRowChanged
                                                      , get () );
    dispatcher -> bankRepaintWaveformListeners -> call (
                                                        &BankRepaintWaveform::onBankRepaintWaveform );
    //[/UserbuttonClicked_Post]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
unsigned int
    WavetableRow::get () const
{
    unsigned int ret = 0;
    if ( gateCheckbox -> getToggleState () )
        ret |= 0x01;
    if ( synCheckbox -> getToggleState () )
        ret |= 0x02;
    if ( ringCheckbox -> getToggleState () )
        ret |= 0x04;
    if ( testCheckbox -> getToggleState () )
        ret |= 0x08;
    if ( triangleCheckbox -> getToggleState () )
        ret |= 0x10;
    if ( sawtoothCheckbox -> getToggleState () )
        ret |= 0x20;
    if ( pulseCheckbox -> getToggleState () )
        ret |= 0x40;
    if ( noiseCheckbox -> getToggleState () )
        ret |= 0x80;
    return ret;
}

void
    WavetableRow::set (
            const unsigned int row_num
          , const unsigned int value
            )
{
    gateCheckbox -> setToggleState (
                                    ( value & 0x01 ) == 0x01
                                  , dontSendNotification );
    synCheckbox -> setToggleState (
                                   ( value & 0x02 ) == 0x02
                                 , dontSendNotification );
    ringCheckbox -> setToggleState (
                                    ( value & 0x04 ) == 0x04
                                  , dontSendNotification );
    testCheckbox -> setToggleState (
                                    ( value & 0x08 ) == 0x08
                                  , dontSendNotification );
    triangleCheckbox -> setToggleState (
                                        ( value & 0x10 ) == 0x10
                                      , dontSendNotification );
    sawtoothCheckbox -> setToggleState (
                                        ( value & 0x20 ) == 0x20
                                      , dontSendNotification );
    pulseCheckbox -> setToggleState (
                                     ( value & 0x40 ) == 0x40
                                   , dontSendNotification );
    noiseCheckbox -> setToggleState (
                                     ( value & 0x80 ) == 0x80
                                   , dontSendNotification );
    row                   = row_num;
    const auto row_string = String (
                                    row_num + 1 );
    rowLabel -> setText (
                         row_string . paddedLeft (
                                                  '0'
                                                , 2 )
                       , dontSendNotification );
}

//void WavetableRow::setBank(ReferenceCountedObjectPtr<Bank> value) {
//	bank = value;
//}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WavetableRow" componentName=""
                 parentClasses="public AbstractWavetableRow" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="590" initialHeight="24">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 592 24" resource="wavetableRowBackdrop_png" opacity="1.0"
           mode="1"/>
  </BACKGROUND>
  <LABEL name="new label" id="1b4eae892bfe6bdb" memberName="rowLabel"
         virtualName="" explicitFocusOrder="0" pos="0 4 44 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="01" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <TOGGLEBUTTON name="new toggle button" id="81225a8c35f7ea8f" memberName="triangleCheckbox"
                virtualName="" explicitFocusOrder="0" pos="53 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="a4da22dbb32f5d2a" memberName="sawtoothCheckbox"
                virtualName="" explicitFocusOrder="0" pos="109 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="bb73c739ae761157" memberName="pulseCheckbox"
                virtualName="" explicitFocusOrder="0" pos="165 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="3309ed3c2cb9c419" memberName="noiseCheckbox"
                virtualName="" explicitFocusOrder="0" pos="221 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="679bcd3623419e59" memberName="testCheckbox"
                virtualName="" explicitFocusOrder="0" pos="277 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="5c6a0a067ba10ea6" memberName="ringCheckbox"
                virtualName="" explicitFocusOrder="0" pos="349 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="2f9ec4adb84f1737" memberName="synCheckbox"
                virtualName="" explicitFocusOrder="0" pos="421 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="512ad5214d55f830" memberName="gateCheckbox"
                virtualName="" explicitFocusOrder="0" pos="493 6 14 14" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: wavetableRowBackdrop_png, 7688, "../../UI/Wavetable Row Backdrop.png"
static const unsigned char resource_WavetableRow_wavetableRowBackdrop_png[] = {
        137 , 80 , 78 , 71 , 13 , 10 , 26 , 10 , 0 , 0 , 0 , 13 , 73 , 72 , 68 , 82 , 0 , 0 , 2 , 80 , 0 , 0 , 0 , 24 , 8 , 6 , 0 , 0 , 0 , 53 , 118 , 195 , 109 , 0 , 0 , 0 , 9 , 112 , 72 , 89 , 115 , 0 , 0 , 13 , 215 , 0 , 0 , 13 , 215 , 1 , 66 , 40 , 155 , 120 , 0 , 0 , 10 , 79 , 105 , 67 , 67 , 80 , 80 , 104 , 111 , 116 , 111 , 115 , 104 , 111 , 112 , 32 , 73 , 67 , 67 , 32 , 112 , 114 , 111 , 102 , 105 , 108 , 101 , 0 , 0 , 120 , 218 , 157 , 83 , 103 , 84 , 83 , 233 , 22 , 61 , 247 , 222 , 244 , 66 , 75 , 136 , 128 , 148 , 75 , 111 , 82 , 21 , 8 , 32 , 82 , 66 , 139 , 128 , 20 , 145 , 38 , 42 , 33 , 9 , 16 , 74 , 136 , 33 , 161 , 217 , 21 , 81 , 193 , 17 , 69 , 69 , 4 , 27 , 200 , 160 , 136 , 3 , 142 , 142 , 128 , 140 , 21 , 81 , 44 , 12 , 138 , 10 , 216 , 7 , 228 , 33 , 162 , 142 , 131 , 163 , 136 , 138 , 202 , 251 , 225 , 123 , 163 , 107 , 214 , 188 , 247 , 230 , 205 , 254 , 181 , 215 , 62 , 231 , 172 , 243 , 157 , 179 , 207 , 7 , 192 , 8 , 12 , 150 , 72 , 51 , 81 , 53 , 128 , 12 , 169 , 66 , 30 , 17 , 224 , 131 , 199 , 196 , 198 , 225 , 228 , 46 , 64 , 129 , 10 , 36 , 112 , 0 , 16 , 8 , 179 , 100 , 33 , 115 , 253 , 35 , 1 , 0 , 248 , 126 , 60 , 60 , 43 , 34 , 192 , 7 , 190 , 0 , 1 , 120 , 211 , 11 , 8 , 0 , 192 , 77 , 155 , 192 , 48 , 28 , 135 , 255 , 15 , 234 , 66 , 153 , 92 , 1 , 128 , 132 , 1 , 192 , 116 , 145 , 56 , 75 , 8 , 128 , 20 , 0 , 64 , 122 , 142 , 66 , 166 , 0 , 64 , 70 , 1 , 128 , 157 , 152 , 38 , 83 , 0 , 160 , 4 , 0 , 96 , 203 , 99 , 98 , 227 , 0 , 80 , 45 , 0 , 96 , 39 , 127 , 230 , 211 , 0 , 128 , 157 , 248 , 153 , 123 , 1 , 0 , 91 , 148 , 33 , 21 , 1 , 160 , 145 , 0 , 32 , 19 , 101 , 136 , 68 , 0 , 104 , 59 , 0 , 172 , 207 , 86 , 138 , 69 , 0 , 88 , 48 , 0 , 20 , 102 , 75 , 196 , 57 , 0 , 216 , 45 , 0 , 48 , 73 , 87 , 102 , 72 , 0 , 176 , 183 , 0 , 192 , 206 , 16 , 11 , 178 , 0 , 8 , 12 , 0 , 48 , 81 , 136 , 133 , 41 , 0 , 4 , 123 , 0 , 96 , 200 , 35 , 35 , 120 , 0 , 132 , 153 , 0 , 20 , 70 , 242 , 87 , 60 , 241 , 43 , 174 , 16 , 231 , 42 , 0 , 0 , 120 , 153 , 178 , 60 , 185 , 36 , 57 , 69 , 129 , 91 , 8 , 45 , 113 , 7 , 87 , 87 , 46 , 30 , 40 , 206 , 73 , 23 , 43 , 20 , 54 , 97 , 2 , 97 , 154 , 64 , 46 , 194 , 121 , 153 , 25 , 50 , 129 , 52 , 15 , 224 , 243 , 204 , 0 , 0 , 160 , 145 , 21 , 17 , 224 , 131 , 243 , 253 , 120 , 206 , 14 , 174 , 206 , 206 , 54 , 142 , 182 , 14 , 95 , 45 , 234 , 191 , 6 , 255 , 34 , 98 , 98 , 227 , 254 , 229 , 207 , 171 , 112 , 64 , 0 , 0 , 225 , 116 , 126 , 209 , 254 , 44 , 47 , 179 , 26 , 128 , 59 , 6 , 128 , 109 , 254 , 162 , 37 , 238 , 4 , 104 , 94 , 11 , 160 , 117 , 247 , 139 , 102 , 178 , 15 , 64 , 181 , 0 , 160 , 233 , 218 , 87 , 243 , 112 , 248 , 126 , 60 , 60 , 69 , 161 , 144 , 185 , 217 , 217 , 229 , 228 , 228 , 216 , 74 , 196 , 66 , 91 , 97 , 202 , 87 , 125 , 254 , 103 , 194 , 95 , 192 , 87 , 253 , 108 , 249 , 126 , 60 , 252 , 247 , 245 , 224 , 190 , 226 , 36 , 129 , 50 , 93 , 129 , 71 , 4 , 248 , 224 , 194 , 204 , 244 , 76 , 165 , 28 , 207 , 146 , 9 , 132 , 98 , 220 , 230 , 143 , 71 , 252 , 183 , 11 , 255 , 252 , 29 , 211 , 34 , 196 , 73 , 98 , 185 , 88 , 42 , 20 , 227 , 81 , 18 , 113 , 142 , 68 , 154 , 140 , 243 , 50 , 165 , 34 , 137 , 66 , 146 , 41 , 197 , 37 , 210 , 255 , 100 , 226 , 223 , 44 , 251 , 3 , 62 , 223 , 53 , 0 , 176 , 106 , 62 , 1 , 123 , 145 , 45 , 168 , 93 , 99 , 3 , 246 , 75 , 39 , 16 , 88 , 116 , 192 , 226 , 247 , 0 , 0 , 242 , 187 , 111 , 193 , 212 , 40 , 8 , 3 , 128 , 104 , 131 , 225 , 207 , 119 , 255 , 239 , 63 , 253 , 71 , 160 , 37 , 0 , 128 , 102 , 73 , 146 , 113 , 0 , 0 , 94 , 68 , 36 , 46 , 84 , 202 , 179 , 63 , 199 , 8 , 0 , 0 , 68 , 160 , 129 , 42 , 176 , 65 , 27 , 244 , 193 , 24 , 44 , 192 , 6 , 28 , 193 , 5 , 220 , 193 , 11 , 252 , 96 , 54 , 132 , 66 , 36 , 196 , 194 , 66 , 16 , 66 , 10 , 100 , 128 , 28 , 114 , 96 , 41 , 172 , 130 , 66 , 40 , 134 , 205 , 176 , 29 , 42 , 96 , 47 , 212 , 64 , 29 , 52 , 192 , 81 , 104 , 134 , 147 , 112 , 14 , 46 , 194 , 85 , 184 , 14 , 61 , 112 , 15 , 250 , 97 , 8 , 158 , 193 , 40 , 188 , 129 , 9 , 4 , 65 , 200 , 8 , 19 , 97 , 33 , 218 , 136 , 1 , 98 , 138 , 88 , 35 , 142 , 8 , 23 , 153 , 133 , 248 , 33 , 193 , 72 , 4 , 18 , 139 , 36 , 32 , 201 , 136 , 20 , 81 , 34 , 75 , 145 , 53 , 72 , 49 , 82 , 138 , 84 , 32 , 85 , 72 , 29 , 242 , 61 , 114 , 2 , 57 , 135 , 92 , 70 , 186 , 145 , 59 , 200 , 0 , 50 , 130 , 252 , 134 , 188 , 71 , 49 , 148 , 129 , 178 , 81 , 61 , 212 , 12 , 181 , 67 , 185 , 168 , 55 , 26 , 132 , 70 , 162 , 11 , 208 , 100 , 116 , 49 , 154 , 143 , 22 , 160 , 155 , 208 , 114 , 180 , 26 , 61 , 140 , 54 , 161 , 231 , 208 , 171 , 104 , 15 , 218 , 143 , 62 , 67 , 199 , 48 , 192 , 232 , 24 , 7 , 51 , 196 , 108 , 48 , 46 , 198 , 195 , 66 , 177 , 56 , 44 , 9 , 147 , 99 , 203 , 177 , 34 , 172 , 12 , 171 , 198 , 26 , 176 , 86 , 172 , 3 , 187 , 137 , 245 , 99 , 207 , 177 , 119 , 4 , 18 , 129 , 69 , 192 , 9 , 54 , 4 , 119 , 66 , 32 , 97 , 30 , 65 , 72 , 88 , 76 , 88 , 78 , 216 , 72 , 168 , 32 , 28 , 36 , 52 , 17 , 218 , 9 , 55 , 9 , 3 , 132 , 81 , 194 , 39 , 34 , 147 , 168 , 75 , 180 , 38 , 186 , 17 , 249 , 196 , 24 , 98 , 50 , 49 , 135 , 88 , 72 , 44 , 35 , 214 , 18 , 143 , 19 , 47 , 16 , 123 , 136 , 67 , 196 , 55 , 36 , 18 , 137 , 67 , 50 , 39 , 185 , 144 , 2 , 73 , 177 , 164 , 84 , 210 , 18 , 210 , 70 , 210 , 110 , 82 , 35 , 233 , 44 , 169 , 155 , 52 , 72 , 26 , 35 , 147 , 201 , 218 , 100 , 107 , 178 , 7 , 57 , 148 , 44 , 32 , 43 , 200 , 133 , 228 , 157 , 228 , 195 , 228 , 51 , 228 , 27 , 228 , 33 , 242 , 91 , 10 , 157 , 98 , 64 , 113 , 164 , 248 , 83 , 226 , 40 , 82 , 202 , 106 , 74 , 25 , 229 , 16 , 229 , 52 , 229 , 6 , 101 , 152 , 50 , 65 , 85 , 163 , 154 , 82 , 221 , 168 , 161 , 84 , 17 , 53 , 143 , 90 , 66 , 173 , 161 , 182 , 82 , 175 , 81 , 135 , 168 , 19 , 52 , 117 , 154 , 57 , 205 , 131 , 22 , 73 , 75 , 165 , 173 , 162 , 149 , 211 , 26 , 104 , 23 , 104 , 247 , 105 , 175 , 232 , 116 , 186 , 17 , 221 , 149 , 30 , 78 , 151 , 208 , 87 , 210 , 203 , 233 , 71 , 232 , 151 , 232 , 3 , 244 , 119 , 12 , 13 , 134 , 21 , 131 , 199 , 136 , 103 , 40 , 25 , 155 , 24 , 7 , 24 , 103 , 25 , 119 , 24 , 175 , 152 , 76 , 166 , 25 , 211 , 139 , 25 , 199 , 84 , 48 , 55 , 49 , 235 , 152 , 231 , 153 , 15 , 153 , 111 , 85 , 88 , 42 , 182 , 42 , 124 , 21 , 145 , 202 , 10 , 149 , 74 , 149 , 38 , 149 , 27 , 42 , 47 , 84 , 169 , 170 , 166 , 170 , 222 , 170 , 11 , 85 , 243 , 85 , 203 , 84 , 143 , 169 , 94 , 83 , 125 , 174 , 70 , 85 , 51 , 83 , 227 , 169 , 9 , 212 , 150 , 171 , 85 , 170 , 157 , 80 , 235 , 83 , 27 , 83 , 103 , 169 , 59 , 168 , 135 , 170 , 103 , 168 , 111 , 84 , 63 , 164 , 126 , 89 , 253 , 137 , 6 , 89 , 195 , 76 , 195 , 79 , 67 , 164 , 81 , 160 , 177 , 95 , 227 , 188 , 198 , 32 , 11 , 99 , 25 , 179 , 120 , 44 , 33 , 107 , 13 , 171 , 134 , 117 , 129 , 53 , 196 , 38 , 177 , 205 , 217 , 124 , 118 , 42 , 187 , 152 , 253 , 29 , 187 , 139 , 61 , 170 , 169 , 161 , 57 , 67 , 51 , 74 , 51 , 87 , 179 , 82 , 243 , 148 , 102 , 63 , 7 , 227 , 152 , 113 , 248 , 156 , 116 , 78 , 9 , 231 , 40 , 167 , 151 , 243 , 126 , 138 , 222 , 20 , 239 , 41 , 226 , 41 , 27 , 166 , 52 , 76 , 185 , 49 , 101 , 92 , 107 , 170 , 150 , 151 , 150 , 88 , 171 , 72 , 171 , 81 , 171 , 71 , 235 , 189 , 54 , 174 , 237 , 167 , 157 , 166 , 189 , 69 , 187 , 89 , 251 , 129 , 14 , 65 , 199 , 74 , 39 , 92 , 39 , 71 , 103 , 143 , 206 , 5 , 157 , 231 , 83 , 217 , 83 , 221 , 167 , 10 , 167 , 22 , 77 , 61 , 58 , 245 , 174 , 46 , 170 , 107 , 165 , 27 , 161 , 187 , 68 , 119 , 191 , 110 , 167 , 238 , 152 , 158 , 190 , 94 , 128 , 158 , 76 , 111 , 167 , 222 , 121 , 189 , 231 , 250 , 28 , 125 , 47 , 253 , 84 , 253 , 109 , 250 , 167 , 245 , 71 , 12 , 88 , 6 , 179 , 12 , 36 , 6 , 219 , 12 , 206 , 24 , 60 , 197 , 53 , 113 , 111 , 60 , 29 , 47 , 199 , 219 , 241 , 81 , 67 , 93 , 195 , 64 , 67 , 165 , 97 , 149 , 97 , 151 , 225 , 132 , 145 , 185 , 209 , 60 , 163 , 213 , 70 , 141 , 70 , 15 , 140 , 105 , 198 , 92 , 227 , 36 , 227 , 109 , 198 , 109 , 198 , 163 , 38 , 6 , 38 , 33 , 38 , 75 , 77 , 234 , 77 , 238 , 154 , 82 , 77 , 185 , 166 , 41 , 166 , 59 , 76 , 59 , 76 , 199 , 205 , 204 , 205 , 162 , 205 , 214 , 153 , 53 , 155 , 61 , 49 , 215 , 50 , 231 , 155 , 231 , 155 , 215 , 155 , 223 , 183 , 96 , 90 , 120 , 90 , 44 , 182 , 168 , 182 , 184 , 101 , 73 , 178 , 228 , 90 , 166 , 89 , 238 , 182 , 188 , 110 , 133 , 90 , 57 , 89 , 165 , 88 , 85 , 90 , 93 , 179 , 70 , 173 , 157 , 173 , 37 , 214 , 187 , 173 , 187 , 167 , 17 , 167 , 185 , 78 , 147 , 78 , 171 , 158 , 214 , 103 , 195 , 176 , 241 , 182 , 201 , 182 , 169 , 183 , 25 , 176 , 229 , 216 , 6 , 219 , 174 , 182 , 109 , 182 , 125 , 97 , 103 , 98 , 23 , 103 , 183 , 197 , 174 , 195 , 238 , 147 , 189 , 147 , 125 , 186 , 125 , 141 , 253 , 61 , 7 , 13 , 135 , 217 , 14 , 171 , 29 , 90 , 29 , 126 , 115 , 180 , 114 , 20 , 58 , 86 , 58 , 222 , 154 , 206 , 156 , 238 , 63 , 125 , 197 , 244 , 150 , 233 , 47 , 103 , 88 , 207 , 16 , 207 , 216 , 51 , 227 , 182 , 19 , 203 , 41 , 196 , 105 , 157 , 83 , 155 , 211 , 71 , 103 , 23 , 103 , 185 , 115 , 131 , 243 , 136 , 139 , 137 , 75 , 130 , 203 , 46 , 151 , 62 , 46 , 155 , 27 , 198 , 221 , 200 , 189 , 228 , 74 , 116 , 245 , 113 , 93 , 225 , 122 , 210 , 245 , 157 , 155 , 179 , 155 , 194 , 237 , 168 , 219 , 175 , 238 , 54 , 238 , 105 , 238 , 135 , 220 , 159 , 204 , 52 , 159 , 41 , 158 , 89 , 51 , 115 , 208 , 195 , 200 , 67 , 224 , 81 , 229 , 209 , 63 , 11 , 159 , 149 , 48 , 107 , 223 , 172 , 126 , 79 , 67 , 79 , 129 , 103 , 181 , 231 , 35 , 47 , 99 , 47 , 145 , 87 , 173 , 215 , 176 , 183 , 165 , 119 , 170 , 247 , 97 , 239 , 23 , 62 , 246 , 62 , 114 , 159 , 227 , 62 , 227 , 60 , 55 , 222 , 50 , 222 , 89 , 95 , 204 , 55 , 192 , 183 , 200 , 183 , 203 , 79 , 195 , 111 , 158 , 95 , 133 , 223 , 67 , 127 , 35 , 255 , 100 , 255 , 122 , 255 , 209 , 0 , 167 , 128 , 37 , 1 , 103 , 3 , 137 , 129 , 65 , 129 , 91 , 2 , 251 , 248 , 122 , 124 , 33 , 191 , 142 , 63 , 58 , 219 , 101 , 246 , 178 , 217 , 237 , 65 , 140 , 160 , 185 , 65 , 21 , 65 , 143 , 130 , 173 , 130 , 229 , 193 , 173 , 33 , 104 , 200 , 236 , 144 , 173 , 33 , 247 , 231 , 152 , 206 , 145 , 206 , 105 , 14 , 133 , 80 , 126 , 232 , 214 , 208 , 7 , 97 , 230 , 97 , 139 , 195 , 126 , 12 , 39 , 133 , 135 , 133 , 87 , 134 , 63 , 142 , 112 , 136 , 88 , 26 , 209 , 49 , 151 , 53 , 119 , 209 , 220 , 67 , 115 , 223 , 68 , 250 , 68 , 150 , 68 , 222 , 155 , 103 , 49 , 79 , 57 , 175 , 45 , 74 , 53 , 42 , 62 , 170 , 46 , 106 , 60 , 218 , 55 , 186 , 52 , 186 , 63 , 198 , 46 , 102 , 89 , 204 , 213 , 88 , 157 , 88 , 73 , 108 , 75 , 28 , 57 , 46 , 42 , 174 , 54 , 110 , 108 , 190 , 223 , 252 , 237 , 243 , 135 , 226 , 157 , 226 , 11 , 227 , 123 , 23 , 152 , 47 , 200 , 93 , 112 , 121 , 161 , 206 , 194 , 244 , 133 , 167 , 22 , 169 , 46 , 18 , 44 , 58 , 150 , 64 , 76 , 136 , 78 , 56 , 148 , 240 , 65 , 16 , 42 , 168 , 22 , 140 , 37 , 242 , 19 , 119 , 37 , 142 , 10 , 121 , 194 , 29 , 194 , 103 , 34 , 47 , 209 , 54 , 209 , 136 , 216 , 67 , 92 , 42 , 30 , 78 , 242 , 72 , 42 , 77 , 122 , 146 , 236 , 145 , 188 , 53 , 121 , 36 , 197 , 51 , 165 , 44 , 229 , 185 , 132 , 39 , 169 , 144 , 188 , 76 , 13 , 76 , 221 , 155 , 58 , 158 , 22 , 154 , 118 , 32 , 109 , 50 , 61 , 58 , 189 , 49 , 131 , 146 , 145 , 144 , 113 , 66 , 170 , 33 , 77 , 147 , 182 , 103 , 234 , 103 , 230 , 102 , 118 , 203 , 172 , 101 , 133 , 178 , 254 , 197 , 110 , 139 , 183 , 47 , 30 , 149 , 7 , 201 , 107 , 179 , 144 , 172 , 5 , 89 , 45 , 10 , 182 , 66 , 166 , 232 , 84 , 90 , 40 , 215 , 42 , 7 , 178 , 103 , 101 , 87 , 102 , 191 , 205 , 137 , 202 , 57 , 150 , 171 , 158 , 43 , 205 , 237 , 204 , 179 , 202 , 219 , 144 , 55 , 156 , 239 , 159 , 255 , 237 , 18 , 194 , 18 , 225 , 146 , 182 , 165 , 134 , 75 , 87 , 45 , 29 , 88 , 230 , 189 , 172 , 106 , 57 , 178 , 60 , 113 , 121 , 219 , 10 , 227 , 21 , 5 , 43 , 134 , 86 , 6 , 172 , 60 , 184 , 138 , 182 , 42 , 109 , 213 , 79 , 171 , 237 , 87 , 151 , 174 , 126 , 189 , 38 , 122 , 77 , 107 , 129 , 94 , 193 , 202 , 130 , 193 , 181 , 1 , 107 , 235 , 11 , 85 , 10 , 229 , 133 , 125 , 235 , 220 , 215 , 237 , 93 , 79 , 88 , 47 , 89 , 223 , 181 , 97 , 250 , 134 , 157 , 27 , 62 , 21 , 137 , 138 , 174 , 20 , 219 , 23 , 151 , 21 , 127 , 216 , 40 , 220 , 120 , 229 , 27 , 135 , 111 , 202 , 191 , 153 , 220 , 148 , 180 , 169 , 171 , 196 , 185 , 100 , 207 , 102 , 210 , 102 , 233 , 230 , 222 , 45 , 158 , 91 , 14 , 150 , 170 , 151 , 230 , 151 , 14 , 110 , 13 , 217 , 218 , 180 , 13 , 223 , 86 , 180 , 237 , 245 , 246 , 69 , 219 , 47 , 151 , 205 , 40 , 219 , 187 , 131 , 182 , 67 , 185 , 163 , 191 , 60 , 184 , 188 , 101 , 167 , 201 , 206 , 205 , 59 , 63 , 84 , 164 , 84 , 244 , 84 , 250 , 84 , 54 , 238 , 210 , 221 , 181 , 97 , 215 , 248 , 110 , 209 , 238 , 27 , 123 , 188 , 246 , 52 , 236 , 213 , 219 , 91 , 188 , 247 , 253 , 62 , 201 , 190 , 219 , 85 , 1 , 85 , 77 , 213 , 102 , 213 , 101 , 251 , 73 , 251 , 179 , 247 , 63 , 174 , 137 , 170 , 233 , 248 , 150 , 251 , 109 , 93 , 173 , 78 , 109 , 113 , 237 , 199 , 3 , 210 , 3 , 253 , 7 , 35 , 14 , 182 , 215 , 185 , 212 , 213 , 29 , 210 , 61 , 84 , 82 , 143 , 214 , 43 , 235 , 71 , 14 , 199 , 31 , 190 , 254 , 157 , 239 , 119 , 45 , 13 , 54 , 13 , 85 , 141 , 156 , 198 , 226 , 35 , 112 , 68 , 121 , 228 , 233 , 247 , 9 , 223 , 247 , 30 , 13 , 58 , 218 , 118 , 140 , 123 , 172 , 225 , 7 , 211 , 31 , 118 , 29 , 103 , 29 , 47 , 106 , 66 , 154 , 242 , 154 , 70 , 155 , 83 , 154 , 251 , 91 , 98 , 91 , 186 , 79 , 204 , 62 , 209 , 214 , 234 , 222 , 122 , 252 , 71 , 219 , 31 , 15 , 156 , 52 , 60 , 89 , 121 , 74 , 243 , 84 , 201 , 105 , 218 , 233 , 130 , 211 , 147 , 103 , 242 , 207 , 140 , 157 , 149 , 157 , 125 , 126 , 46 , 249 , 220 , 96 , 219 , 162 , 182 , 123 , 231 , 99 , 206 , 223 , 106 , 15 , 111 , 239 , 186 , 16 , 116 , 225 , 210 , 69 , 255 , 139 , 231 , 59 , 188 , 59 , 206 , 92 , 242 , 184 , 116 , 242 , 178 , 219 , 229 , 19 , 87 , 184 , 87 , 154 , 175 , 58 , 95 , 109 , 234 , 116 , 234 , 60 , 254 , 147 , 211 , 79 , 199 , 187 , 156 , 187 , 154 , 174 , 185 , 92 , 107 , 185 , 238 , 122 , 189 , 181 , 123 , 102 , 247 , 233 , 27 , 158 , 55 , 206 , 221 , 244 , 189 , 121 , 241 , 22 , 255 , 214 , 213 , 158 , 57 , 61 , 221 , 189 , 243 , 122 , 111 , 247 , 197 , 247 , 245 , 223 , 22 , 221 , 126 , 114 , 39 , 253 , 206 , 203 , 187 , 217 , 119 , 39 , 238 , 173 , 188 , 79 , 188 , 95 , 244 , 64 , 237 , 65 , 217 , 67 , 221 , 135 , 213 , 63 , 91 , 254 , 220 , 216 , 239 , 220 , 127 , 106 , 192 , 119 , 160 , 243 , 209 , 220 , 71 , 247 , 6 , 133 , 131 , 207 , 254 , 145 , 245 , 143 , 15 , 67 , 5 , 143 , 153 , 143 , 203 , 134 , 13 , 134 , 235 , 158 , 56 , 62 , 57 , 57 , 226 , 63 , 114 , 253 , 233 , 252 , 167 , 67 , 207 , 100 , 207 , 38 , 158 , 23 , 254 , 162 , 254 , 203 , 174 , 23 , 22 , 47 , 126 , 248 , 213 , 235 , 215 , 206 , 209 , 152 , 209 , 161 , 151 , 242 , 151 , 147 , 191 , 109 , 124 , 165 , 253 , 234 , 192 , 235 , 25 , 175 , 219 , 198 , 194 , 198 , 30 , 190 , 201 , 120 , 51 , 49 , 94 , 244 , 86 , 251 , 237 , 193 , 119 , 220 , 119 , 29 , 239 , 163 , 223 , 15 , 79 , 228 , 124 , 32 , 127 , 40 , 255 , 104 , 249 , 177 , 245 , 83 , 208 , 167 , 251 , 147 , 25 , 147 , 147 , 255 , 4 , 3 , 152 , 243 , 252 , 99 , 51 , 45 , 219 , 0 , 0 , 0 , 32 , 99 , 72 , 82 , 77 , 0 , 0 , 122 , 37 , 0 , 0 , 128 , 131 , 0 , 0 , 249 , 255 , 0 , 0 , 128 , 233 , 0 , 0 , 117 , 48 , 0 , 0 , 234 , 96 , 0 , 0 , 58 , 152 , 0 , 0 , 23 , 111 , 146 , 95 , 197 , 70 , 0 , 0 , 19 , 51 , 73 , 68 , 65 , 84 , 120 , 218 , 236 , 93 , 91 , 112 , 27 , 215 , 121 , 254 , 22 , 139 , 5 , 176 , 184 , 131 , 196 , 133 , 32 , 8 , 222 , 68 , 81 , 34 , 169 , 43 , 229 , 139 , 124 , 147 , 237 , 212 , 147 , 198 , 158 , 196 , 105 , 27 , 199 , 157 , 206 , 180 , 190 , 52 , 158 , 62 , 116 , 38 , 105 , 38 , 126 , 235 , 116 , 58 , 153 , 62 , 118 , 38 , 174 , 235 , 180 , 153 , 100 , 234 , 36 , 182 , 107 , 119 , 38 , 105 , 220 , 212 , 110 , 51 , 181 , 61 , 118 , 163 , 58 , 150 , 45 , 217 , 50 , 69 , 210 , 188 , 136 , 18 , 69 , 241 , 14 , 130 , 32 , 136 , 251 , 29 , 139 , 237 , 195 , 18 , 11 , 64 , 192 , 46 , 64 , 2 , 36 , 33 , 233 , 124 , 79 , 32 , 246 , 252 , 60 , 56 , 103 , 207 , 229 , 59 , 223 , 249 , 207 , 127 , 168 , 54 , 243 , 139 , 60 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 8 , 106 , 134 , 130 , 84 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 33 , 80 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 4 , 132 , 64 , 17 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 52 , 19 , 148 , 164 , 10 , 118 , 6 , 74 , 65 , 97 , 232 , 91 , 39 , 1 , 0 , 147 , 63 , 189 , 4 , 62 , 199 , 239 , 169 , 125 , 35 , 48 , 244 , 220 , 48 , 104 , 90 , 129 , 233 , 55 , 198 , 145 , 137 , 166 , 247 , 220 , 126 , 47 , 202 , 103 , 232 , 48 , 202 , 166 , 137 , 44 , 135 , 49 , 249 , 242 , 200 , 174 , 217 , 3 , 144 , 124 , 222 , 208 , 246 , 168 , 84 , 64 , 99 , 214 , 32 , 177 , 17 , 223 , 211 , 250 , 221 , 171 , 242 , 17 , 16 , 16 , 16 , 16 , 2 , 117 , 139 , 192 , 122 , 204 , 1 , 189 , 203 , 40 , 126 , 246 , 141 , 174 , 237 , 169 , 125 , 35 , 144 , 39 , 7 , 131 , 207 , 156 , 192 , 212 , 43 , 163 , 219 , 38 , 65 , 245 , 218 , 239 , 85 , 249 , 118 , 154 , 102 , 47 , 236 , 27 , 133 , 158 , 199 , 250 , 96 , 31 , 110 , 199 , 228 , 207 , 70 , 17 , 89 , 12 , 238 , 254 , 192 , 193 , 50 , 48 , 116 , 24 , 193 , 165 , 184 , 93 , 205 , 71 , 211 , 194 , 214 , 156 , 54 , 29 , 78 , 33 , 151 , 205 , 221 , 70 , 171 , 56 , 128 , 102 , 232 , 170 , 201 , 114 , 89 , 14 , 252 , 109 , 84 , 45 , 4 , 59 , 17 , 4 , 164 , 159 , 241 , 60 , 0 , 114 , 212 , 140 , 16 , 168 , 70 , 54 , 54 , 215 , 3 , 157 , 226 , 223 , 174 , 51 , 93 , 216 , 24 , 247 , 214 , 172 , 34 , 213 , 107 , 223 , 104 , 176 , 86 , 45 , 6 , 159 , 62 , 142 , 169 , 87 , 198 , 144 , 137 , 165 , 247 , 220 , 126 , 183 , 113 , 254 , 251 , 103 , 43 , 126 , 127 , 250 , 251 , 15 , 237 , 137 , 253 , 94 , 192 , 216 , 99 , 1 , 0 , 152 , 122 , 204 , 136 , 44 , 6 , 193 , 232 , 85 , 176 , 15 , 59 , 225 , 189 , 184 , 130 , 108 , 60 , 43 , 105 , 103 , 234 , 179 , 160 , 229 , 144 , 13 , 243 , 239 , 206 , 130 , 223 , 6 , 249 , 80 , 153 , 213 , 0 , 128 , 84 , 40 , 177 , 171 , 229 , 58 , 241 , 157 , 187 , 107 , 78 , 59 , 245 , 202 , 40 , 194 , 243 , 193 , 219 , 102 , 28 , 82 , 233 , 85 , 24 , 126 , 254 , 222 , 170 , 233 , 166 , 95 , 31 , 67 , 104 , 54 , 112 , 91 , 143 , 217 , 238 , 135 , 123 , 208 , 58 , 100 , 171 , 248 , 44 , 19 , 75 , 99 , 242 , 231 , 163 , 183 , 109 , 221 , 168 , 140 , 26 , 12 , 127 , 239 , 180 , 228 , 243 , 185 , 183 , 103 , 176 , 62 , 226 , 33 , 19 , 63 , 33 , 80 , 141 , 129 , 245 , 88 , 27 , 52 , 173 , 90 , 36 , 183 , 182 , 75 , 52 , 86 , 237 , 182 , 84 , 164 , 122 , 237 , 27 , 141 , 184 , 55 , 10 , 173 , 67 , 143 , 193 , 103 , 119 , 166 , 36 , 213 , 107 , 79 , 80 , 31 , 24 , 157 , 10 , 26 , 139 , 160 , 212 , 232 , 92 , 6 , 0 , 64 , 231 , 35 , 7 , 96 , 59 , 225 , 128 , 146 , 85 , 98 , 225 , 221 , 107 , 98 , 218 , 238 , 199 , 14 , 130 , 109 , 97 , 113 , 249 , 223 , 190 , 0 , 159 , 227 , 225 , 126 , 184 , 7 , 122 , 151 , 17 , 145 , 197 , 16 , 194 , 139 , 65 , 112 , 105 , 14 , 92 , 34 , 91 , 53 , 79 , 181 , 73 , 35 , 16 , 168 , 96 , 74 , 102 , 161 , 64 , 137 , 233 , 164 , 144 , 142 , 166 , 145 , 203 , 72 , 171 , 88 , 161 , 185 , 194 , 196 , 175 , 100 , 149 , 208 , 57 , 13 , 226 , 223 , 169 , 64 , 18 , 201 , 64 , 129 , 192 , 113 , 201 , 204 , 158 , 215 , 189 , 193 , 109 , 130 , 130 , 17 , 150 , 239 , 185 , 76 , 14 , 145 , 165 , 208 , 190 , 181 , 131 , 108 , 42 , 139 , 76 , 56 , 85 , 68 , 176 , 212 , 160 , 89 , 37 , 212 , 38 , 13 , 180 , 118 , 29 , 18 , 254 , 4 , 120 , 46 , 7 , 74 , 65 , 129 , 181 , 106 , 11 , 118 , 201 , 44 , 210 , 225 , 212 , 173 , 221 , 71 , 12 , 12 , 52 , 69 , 101 , 46 , 134 , 66 , 125 , 251 , 78 , 131 , 26 , 11 , 11 , 198 , 160 , 18 , 219 , 111 , 58 , 90 , 104 , 7 , 140 , 134 , 1 , 205 , 42 , 193 , 104 , 25 , 104 , 90 , 216 , 134 , 40 , 188 , 26 , 11 , 11 , 80 , 216 , 202 , 143 , 67 , 58 , 114 , 115 , 207 , 21 , 183 , 116 , 203 , 25 , 122 , 110 , 24 , 250 , 118 , 131 , 108 , 154 , 232 , 106 , 100 , 91 , 62 , 28 , 197 , 234 , 209 , 242 , 135 , 11 , 0 , 128 , 190 , 63 , 26 , 168 , 89 , 69 , 170 , 215 , 190 , 24 , 125 , 79 , 12 , 160 , 117 , 208 , 46 , 72 , 172 , 18 , 200 , 68 , 82 , 24 , 251 , 231 , 79 , 145 , 203 , 72 , 55 , 252 , 169 , 87 , 199 , 48 , 248 , 244 , 113 , 129 , 4 , 237 , 64 , 73 , 170 , 215 , 94 , 118 , 213 , 120 , 204 , 46 , 63 , 1 , 135 , 82 , 184 , 252 , 250 , 248 , 77 , 185 , 117 , 211 , 247 , 135 , 3 , 208 , 119 , 202 , 111 , 243 , 69 , 151 , 195 , 152 , 125 , 115 , 90 , 54 , 77 , 126 , 43 , 88 , 248 , 108 , 0 , 99 , 80 , 195 , 122 , 84 , 88 , 109 , 183 , 14 , 217 , 176 , 240 , 222 , 53 , 128 , 7 , 40 , 90 , 1 , 199 , 176 , 19 , 148 , 82 , 1 , 214 , 170 , 69 , 210 , 31 , 135 , 214 , 174 , 7 , 0 , 56 , 238 , 116 , 162 , 247 , 235 , 135 , 16 , 247 , 70 , 49 , 241 , 47 , 213 , 251 , 131 , 198 , 188 , 69 , 160 , 66 , 73 , 201 , 52 , 135 , 255 , 236 , 24 , 88 , 155 , 14 , 144 , 107 , 211 , 20 , 48 , 250 , 143 , 23 , 36 , 223 , 223 , 244 , 107 , 99 , 226 , 103 , 99 , 183 , 25 , 131 , 207 , 156 , 16 , 255 , 246 , 141 , 173 , 97 , 249 , 236 , 252 , 254 , 190 , 195 , 111 , 12 , 66 , 157 , 87 , 227 , 130 , 41 , 92 , 122 , 241 , 147 , 125 , 27 , 159 , 130 , 87 , 253 , 152 , 253 , 85 , 161 , 173 , 244 , 126 , 237 , 16 , 236 , 167 , 156 , 232 , 253 , 218 , 33 , 0 , 192 , 232 , 15 , 63 , 69 , 210 , 31 , 7 , 163 , 99 , 112 , 236 , 47 , 239 , 20 , 211 , 109 , 76 , 120 , 75 , 236 , 154 , 5 , 106 , 139 , 6 , 125 , 127 , 112 , 24 , 10 , 153 , 109 , 74 , 158 , 7 , 150 , 127 , 123 , 29 , 193 , 217 , 205 , 138 , 207 , 219 , 239 , 239 , 132 , 251 , 161 , 110 , 64 , 33 , 144 , 220 , 203 , 111 , 140 , 35 , 124 , 61 , 40 , 62 , 191 , 243 , 175 , 31 , 128 , 202 , 160 , 194 , 221 , 127 , 115 , 6 , 145 , 165 , 48 , 166 , 94 , 189 , 121 , 148 , 168 , 254 , 63 , 30 , 130 , 229 , 144 , 13 , 114 , 251 , 107 , 201 , 64 , 18 , 227 , 63 , 250 , 12 , 60 , 87 , 185 , 127 , 29 , 255 , 206 , 93 , 160 , 40 , 129 , 209 , 196 , 60 , 17 , 76 , 254 , 236 , 146 , 248 , 204 , 245 , 96 , 23 , 220 , 15 , 247 , 192 , 253 , 72 , 47 , 220 , 143 , 244 , 98 , 250 , 181 , 177 , 146 , 5 , 205 , 78 , 80 , 156 , 95 , 100 , 49 , 84 , 146 , 31 , 33 , 80 , 77 , 6 , 67 , 135 , 81 , 114 , 251 , 37 , 143 , 237 , 110 , 195 , 228 , 213 , 163 , 132 , 63 , 1 , 255 , 196 , 58 , 0 , 30 , 174 , 51 , 93 , 96 , 107 , 84 , 145 , 234 , 181 , 47 , 41 , 159 , 203 , 132 , 209 , 151 , 46 , 32 , 21 , 148 , 158 , 196 , 78 , 254 , 213 , 105 , 48 , 122 , 21 , 82 , 1 , 233 , 52 , 217 , 120 , 166 , 148 , 4 , 61 , 179 , 61 , 18 , 84 , 175 , 189 , 20 , 90 , 134 , 108 , 184 , 254 , 246 , 21 , 36 , 54 , 165 , 29 , 163 , 7 , 159 , 62 , 1 , 149 , 89 , 35 , 170 , 121 , 55 , 19 , 90 , 143 , 217 , 49 , 250 , 210 , 5 , 89 , 255 , 130 , 147 , 223 , 61 , 141 , 217 , 255 , 152 , 150 , 77 , 163 , 119 , 27 , 74 , 212 , 168 , 238 , 223 , 239 , 3 , 69 , 11 , 19 , 134 , 202 , 168 , 129 , 193 , 101 , 68 , 100 , 57 , 12 , 214 , 166 , 5 , 165 , 20 , 190 , 103 , 109 , 90 , 128 , 162 , 68 , 245 , 196 , 208 , 105 , 6 , 0 , 104 , 219 , 12 , 80 , 208 , 20 , 114 , 28 , 95 , 147 , 2 , 149 , 150 , 105 , 123 , 172 , 85 , 135 , 137 , 31 , 95 , 68 , 90 , 70 , 145 , 28 , 126 , 254 , 94 , 40 , 89 , 101 , 195 , 87 , 162 , 246 , 225 , 118 , 201 , 103 , 49 , 79 , 4 , 49 , 79 , 164 , 244 , 93 , 28 , 177 , 131 , 86 , 201 , 15 , 135 , 49 , 79 , 4 , 10 , 21 , 13 , 182 , 181 , 160 , 100 , 208 , 42 , 69 , 201 , 231 , 226 , 124 , 19 , 254 , 56 , 34 , 11 , 193 , 61 , 29 , 159 , 106 , 65 , 46 , 203 , 35 , 112 , 213 , 95 , 84 , 174 , 168 , 248 , 89 , 107 , 215 , 139 , 132 , 80 , 178 , 191 , 39 , 50 , 136 , 44 , 133 , 75 , 190 , 219 , 169 , 157 , 28 , 140 , 221 , 102 , 100 , 18 , 28 , 86 , 254 , 231 , 170 , 100 , 26 , 203 , 97 , 27 , 90 , 6 , 109 , 146 , 4 , 138 , 162 , 40 , 177 , 205 , 11 , 133 , 231 , 75 , 200 , 122 , 38 , 154 , 6 , 165 , 16 , 38 , 116 , 46 , 147 , 133 , 66 , 169 , 128 , 82 , 163 , 44 , 81 , 231 , 138 , 211 , 43 , 181 , 12 , 20 , 91 , 233 , 121 , 158 , 7 , 151 , 204 , 66 , 201 , 50 , 85 , 203 , 146 , 137 , 167 , 75 , 252 , 208 , 20 , 52 , 37 , 107 , 151 , 73 , 100 , 37 , 73 , 143 , 216 , 239 , 59 , 76 , 184 , 244 , 194 , 199 , 85 , 251 , 23 , 163 , 221 , 89 , 255 , 74 , 5 , 146 , 8 , 93 , 15 , 20 , 253 , 166 , 130 , 194 , 107 , 234 , 177 , 136 , 74 , 82 , 37 , 187 , 188 , 50 , 172 , 117 , 234 , 193 , 72 , 148 , 147 , 214 , 208 , 48 , 245 , 90 , 182 , 109 , 151 , 77 , 102 , 17 , 91 , 141 , 16 , 2 , 117 , 179 , 161 , 88 , 61 , 90 , 249 , 191 , 121 , 81 , 45 , 90 , 249 , 112 , 161 , 38 , 21 , 169 , 94 , 251 , 221 , 68 , 179 , 146 , 168 , 84 , 36 , 133 , 116 , 72 , 122 , 123 , 129 , 207 , 241 , 82 , 253 , 184 , 249 , 219 , 19 , 40 , 89 , 98 , 43 , 20 , 176 , 250 , 255 , 201 , 43 , 80 , 92 , 154 , 3 , 173 , 162 , 209 , 122 , 68 , 80 , 159 , 66 , 215 , 3 , 48 , 245 , 88 , 208 , 58 , 100 , 71 , 100 , 57 , 12 , 93 , 155 , 190 , 64 , 110 , 108 , 186 , 138 , 43 , 123 , 5 , 77 , 65 , 101 , 97 , 43 , 18 , 82 , 138 , 162 , 96 , 63 , 229 , 68 , 120 , 62 , 88 , 228 , 3 , 149 , 108 , 202 , 186 , 237 , 125 , 188 , 95 , 242 , 217 , 242 , 217 , 249 , 50 , 2 , 213 , 249 , 200 , 129 , 170 , 4 , 96 , 249 , 236 , 60 , 212 , 102 , 22 , 182 , 19 , 142 , 202 , 131 , 169 , 150 , 41 , 201 , 215 , 55 , 234 , 149 , 37 , 80 , 251 , 133 , 108 , 34 , 131 , 153 , 55 , 190 , 168 , 248 , 172 , 237 , 110 , 23 , 236 , 167 , 156 , 178 , 246 , 149 , 78 , 158 , 238 , 212 , 174 , 90 , 255 , 200 , 38 , 210 , 136 , 173 , 197 , 36 , 211 , 104 , 157 , 6 , 168 , 76 , 234 , 29 , 215 , 197 , 200 , 11 , 165 , 138 , 161 , 245 , 168 , 3 , 125 , 223 , 24 , 16 , 255 , 158 , 251 , 175 , 25 , 172 , 127 , 94 , 240 , 255 , 57 , 242 , 220 , 176 , 120 , 176 , 33 , 29 , 73 , 227 , 234 , 47 , 39 , 197 , 211 , 212 , 114 , 24 , 251 , 225 , 5 , 36 , 252 , 133 , 237 , 102 , 93 , 187 , 81 , 214 , 238 , 242 , 191 , 142 , 33 , 120 , 109 , 127 , 253 , 214 , 54 , 198 , 189 , 216 , 24 , 247 , 86 , 124 , 118 , 248 , 169 , 99 , 162 , 146 , 116 , 35 , 86 , 62 , 92 , 192 , 210 , 255 , 94 , 7 , 0 , 116 , 125 , 249 , 128 , 64 , 182 , 42 , 189 , 59 , 187 , 30 , 3 , 79 , 29 , 223 , 182 , 93 , 51 , 41 , 87 , 132 , 64 , 213 , 165 , 62 , 9 , 240 , 79 , 120 , 107 , 82 , 145 , 234 , 181 , 191 , 93 , 73 , 20 , 129 , 204 , 36 , 67 , 81 , 34 , 129 , 218 , 24 , 243 , 194 , 113 , 167 , 160 , 128 , 132 , 231 , 131 , 88 , 254 , 224 , 58 , 76 , 207 , 89 , 208 , 50 , 100 , 197 , 252 , 123 , 179 , 208 , 58 , 139 , 8 , 148 , 85 , 43 , 174 , 128 , 185 , 116 , 182 , 68 , 125 , 97 , 139 , 252 , 243 , 138 , 97 , 234 , 53 , 163 , 231 , 171 , 253 , 136 , 46 , 135 , 197 , 85 , 187 , 156 , 15 , 212 , 126 , 192 , 121 , 175 , 27 , 74 , 86 , 40 , 11 , 151 , 204 , 98 , 245 , 227 , 165 , 194 , 164 , 229 , 212 , 163 , 101 , 192 , 6 , 83 , 175 , 25 , 20 , 221 , 3 , 255 , 148 , 15 , 122 , 167 , 1 , 106 , 139 , 6 , 52 , 43 , 144 , 201 , 252 , 0 , 94 , 9 , 225 , 133 , 16 , 148 , 234 , 40 , 146 , 69 , 138 , 104 , 251 , 189 , 110 , 208 , 154 , 202 , 249 , 197 , 101 , 38 , 254 , 221 , 0 , 219 , 162 , 69 , 219 , 93 , 174 , 194 , 223 , 118 , 29 , 0 , 32 , 48 , 179 , 129 , 84 , 56 , 5 , 46 , 153 , 129 , 227 , 14 , 87 , 217 , 137 , 171 , 196 , 102 , 92 , 210 , 201 , 124 , 227 , 11 , 47 , 178 , 73 , 193 , 39 , 142 , 86 , 210 , 176 , 157 , 108 , 131 , 74 , 167 , 66 , 219 , 93 , 46 , 36 , 54 , 227 , 200 , 198 , 179 , 48 , 116 , 24 , 203 , 242 , 202 , 195 , 113 , 71 , 187 , 228 , 68 , 187 , 23 , 72 , 71 , 82 , 136 , 46 , 135 , 161 , 182 , 104 , 4 , 95 , 65 , 171 , 22 , 134 , 27 , 78 , 142 , 230 , 56 , 190 , 140 , 80 , 239 , 60 , 191 , 52 , 210 , 69 , 139 , 10 , 141 , 77 , 11 , 165 , 90 , 9 , 214 , 97 , 128 , 146 , 101 , 16 , 93 , 139 , 66 , 223 , 166 , 7 , 235 , 208 , 138 , 99 , 102 , 114 , 51 , 81 , 81 , 101 , 217 , 47 , 104 , 90 , 88 , 24 , 187 , 205 , 101 , 223 , 7 , 175 , 248 , 69 , 181 , 203 , 119 , 201 , 3 , 220 , 240 , 94 , 53 , 22 , 45 , 140 , 221 , 38 , 104 , 219 , 244 , 176 , 15 , 59 , 17 , 94 , 8 , 33 , 120 , 117 , 179 , 100 , 135 , 196 , 126 , 194 , 41 , 42 , 87 , 153 , 104 , 186 , 68 , 9 , 141 , 174 , 70 , 96 , 232 , 52 , 129 , 181 , 106 , 161 , 50 , 8 , 164 , 216 , 63 , 233 , 3 , 151 , 222 , 106 , 127 , 12 , 141 , 214 , 35 , 118 , 40 , 117 , 194 , 1 , 153 , 228 , 102 , 28 , 225 , 249 , 208 , 190 , 142 , 55 , 132 , 64 , 213 , 169 , 62 , 9 , 42 , 72 , 117 , 21 , 169 , 94 , 123 , 66 , 162 , 8 , 42 , 78 , 154 , 54 , 45 , 104 , 53 , 141 , 84 , 32 , 137 , 192 , 204 , 134 , 72 , 160 , 60 , 231 , 150 , 16 , 89 , 9 , 35 , 29 , 74 , 65 , 101 , 18 , 182 , 241 , 244 , 197 , 10 , 148 , 93 , 11 , 213 , 214 , 68 , 178 , 248 , 222 , 28 , 204 , 253 , 45 , 160 , 85 , 12 , 140 , 221 , 38 , 176 , 86 , 22 , 129 , 153 , 10 , 3 , 235 , 214 , 214 , 149 , 222 , 101 , 20 , 183 , 53 , 228 , 182 , 240 , 246 , 3 , 109 , 119 , 117 , 136 , 74 , 82 , 54 , 201 , 97 , 101 , 203 , 207 , 16 , 0 , 108 , 39 , 218 , 208 , 50 , 96 , 131 , 161 , 211 , 12 , 67 , 167 , 25 , 73 , 127 , 2 , 214 , 99 , 109 , 48 , 118 , 155 , 74 , 86 , 193 , 213 , 16 , 184 , 178 , 81 , 152 , 16 , 134 , 219 , 69 , 2 , 117 , 99 , 126 , 123 , 13 , 93 , 187 , 1 , 186 , 10 , 62 , 85 , 107 , 159 , 173 , 136 , 4 , 169 , 235 , 209 , 62 , 40 , 232 , 210 , 137 , 111 , 99 , 194 , 43 , 73 , 160 , 150 , 207 , 46 , 32 , 233 , 23 , 8 , 163 , 202 , 160 , 130 , 237 , 100 , 27 , 212 , 22 , 13 , 186 , 31 , 59 , 136 , 141 , 9 , 47 , 18 , 222 , 56 , 220 , 191 , 215 , 83 , 49 , 175 , 124 , 253 , 80 , 244 , 254 , 181 , 7 , 223 , 232 , 26 , 124 , 163 , 107 , 232 , 125 , 188 , 31 , 246 , 225 , 118 , 116 , 63 , 122 , 176 , 34 , 233 , 25 , 249 , 193 , 199 , 13 , 202 , 207 , 131 , 165 , 15 , 10 , 36 , 124 , 224 , 169 , 227 , 48 , 245 , 90 , 208 , 255 , 228 , 32 , 0 , 224 , 210 , 139 , 231 , 197 , 248 , 105 , 0 , 16 , 188 , 22 , 192 , 236 , 155 , 83 , 77 , 213 , 135 , 244 , 110 , 35 , 122 , 31 , 63 , 84 , 246 , 253 , 244 , 107 , 99 , 34 , 129 , 154 , 123 , 251 , 74 , 185 , 64 , 112 , 220 , 1 , 99 , 183 , 9 , 150 , 254 , 86 , 88 , 250 , 91 , 49 , 247 , 246 , 12 , 60 , 69 , 11 , 138 , 124 , 31 , 164 , 182 , 24 , 84 , 114 , 51 , 129 , 185 , 183 , 74 , 7 , 154 , 222 , 175 , 31 , 130 , 253 , 100 , 65 , 201 , 92 , 250 , 96 , 78 , 36 , 152 , 42 , 163 , 6 , 173 , 71 , 236 , 96 , 91 , 89 , 244 , 62 , 126 , 8 , 27 , 227 , 94 , 66 , 160 , 110 , 118 , 245 , 169 , 86 , 21 , 169 , 94 , 123 , 66 , 162 , 8 , 42 , 14 , 118 , 29 , 194 , 228 , 31 , 89 , 9 , 33 , 178 , 28 , 6 , 151 , 230 , 144 , 218 , 76 , 32 , 48 , 235 , 7 , 120 , 192 , 63 , 181 , 14 , 231 , 61 , 110 , 97 , 224 , 201 , 19 , 40 , 94 , 80 , 43 , 114 , 91 , 36 , 221 , 63 , 181 , 14 , 239 , 197 , 85 , 56 , 238 , 104 , 135 , 177 , 219 , 84 , 118 , 90 , 73 , 161 , 84 , 128 , 207 , 229 , 160 , 110 , 221 , 138 , 201 , 68 , 1 , 10 , 70 , 33 , 156 , 218 , 105 , 226 , 119 , 202 , 232 , 148 , 37 , 219 , 49 , 106 , 75 , 121 , 76 , 169 , 213 , 223 , 205 , 99 , 125 , 68 , 133 , 238 , 175 , 244 , 65 , 169 , 101 , 74 , 210 , 23 , 148 , 167 , 32 , 214 , 47 , 222 , 124 , 199 , 184 , 55 , 167 , 214 , 17 , 89 , 137 , 148 , 168 , 137 , 139 , 239 , 95 , 3 , 163 , 97 , 224 , 122 , 176 , 235 , 182 , 234 , 39 , 209 , 149 , 8 , 104 , 85 , 249 , 184 , 219 , 58 , 100 , 7 , 173 , 84 , 192 , 122 , 196 , 142 , 76 , 60 , 67 , 6 , 20 , 0 , 113 , 79 , 12 , 75 , 191 , 189 , 14 , 99 , 151 , 185 , 196 , 71 , 169 , 24 , 29 , 15 , 119 , 151 , 41 , 139 , 172 , 93 , 223 , 248 , 5 , 209 , 61 , 29 , 226 , 169 , 96 , 133 , 154 , 110 , 186 , 186 , 34 , 4 , 170 , 78 , 245 , 169 , 22 , 21 , 169 , 94 , 123 , 66 , 162 , 8 , 164 , 9 , 148 , 160 , 56 , 196 , 150 , 35 , 224 , 146 , 89 , 140 , 189 , 116 , 1 , 92 , 58 , 39 , 250 , 78 , 109 , 78 , 250 , 224 , 188 , 199 , 13 , 219 , 112 , 27 , 104 , 149 , 18 , 153 , 72 , 10 , 57 , 14 , 80 , 155 , 213 , 160 , 33 , 108 , 193 , 229 , 227 , 68 , 37 , 182 , 148 , 134 , 226 , 35 , 238 , 74 , 150 , 193 , 137 , 111 , 223 , 133 , 132 , 63 , 81 , 22 , 110 , 32 , 29 , 78 , 54 , 117 , 128 , 61 , 5 , 67 , 195 , 122 , 212 , 33 , 155 , 38 , 239 , 103 , 226 , 254 , 82 , 47 , 148 , 90 , 84 , 76 , 207 , 115 , 184 , 41 , 9 , 84 , 112 , 46 , 80 , 246 , 187 , 215 , 62 , 89 , 134 , 202 , 160 , 186 , 237 , 8 , 212 , 250 , 231 , 158 , 18 , 95 , 166 , 60 , 90 , 6 , 109 , 160 , 89 , 37 , 250 , 158 , 24 , 68 , 100 , 41 , 12 , 239 , 167 , 43 , 132 , 64 , 173 , 71 , 17 , 95 , 143 , 2 , 15 , 66 , 146 , 64 , 185 , 206 , 116 , 237 , 201 , 214 , 108 , 219 , 157 , 174 , 166 , 174 , 43 , 66 , 160 , 26 , 160 , 62 , 85 , 83 , 145 , 234 , 181 , 39 , 36 , 138 , 64 , 154 , 64 , 9 , 254 , 79 , 145 , 101 , 225 , 116 , 211 , 141 , 39 , 114 , 10 , 219 , 120 , 194 , 182 , 86 , 116 , 45 , 10 , 138 , 162 , 196 , 109 , 174 , 120 , 145 , 239 , 71 , 210 , 39 , 16 , 40 , 173 , 85 , 39 , 146 , 120 , 67 , 151 , 25 , 74 , 45 , 3 , 131 , 150 , 17 , 201 , 18 , 159 , 227 , 65 , 41 , 40 , 36 , 131 , 205 , 29 , 59 , 40 , 29 , 21 , 156 , 124 , 165 , 144 , 44 , 114 , 234 , 189 , 242 , 203 , 9 , 40 , 148 , 165 , 206 , 65 , 58 , 167 , 30 , 221 , 143 , 30 , 132 , 249 , 160 , 5 , 67 , 223 , 58 , 9 , 223 , 200 , 26 , 214 , 47 , 53 , 47 , 145 , 138 , 44 , 134 , 224 , 57 , 191 , 130 , 150 , 1 , 43 , 172 , 71 , 237 , 112 , 156 , 106 , 135 , 185 , 183 , 5 , 43 , 31 , 206 , 203 , 58 , 98 , 215 , 165 , 114 , 77 , 251 , 144 , 240 , 39 , 224 , 184 , 195 , 9 , 83 , 175 , 5 , 29 , 103 , 186 , 224 , 40 , 58 , 137 , 152 , 63 , 177 , 182 , 95 , 48 , 116 , 24 , 75 , 252 , 121 , 54 , 38 , 214 , 101 , 79 , 45 , 199 , 125 , 49 , 172 , 126 , 180 , 8 , 131 , 219 , 8 , 67 , 151 , 25 , 230 , 190 , 150 , 146 , 211 , 96 , 197 , 39 , 244 , 110 , 71 , 116 , 125 , 249 , 0 , 24 , 189 , 106 , 203 , 193 , 63 , 131 , 249 , 119 , 102 , 197 , 103 , 70 , 183 , 9 , 246 , 59 , 218 , 27 , 154 , 223 , 194 , 123 , 215 , 36 , 231 , 139 , 212 , 230 , 254 , 187 , 15 , 220 , 242 , 173 , 129 , 82 , 212 , 111 , 95 , 77 , 61 , 146 , 83 , 145 , 0 , 190 , 46 , 251 , 106 , 42 , 148 , 130 , 166 , 68 , 135 , 222 , 202 , 5 , 32 , 36 , 234 , 86 , 5 , 173 , 166 , 193 , 218 , 180 , 224 , 179 , 57 , 196 , 214 , 162 , 18 , 141 , 170 , 176 , 141 , 39 , 16 , 166 , 40 , 20 , 140 , 2 , 230 , 190 , 22 , 129 , 80 , 21 , 17 , 168 , 116 , 52 , 13 , 46 , 197 , 129 , 102 , 149 , 112 , 127 , 169 , 7 , 90 , 187 , 190 , 180 , 255 , 80 , 66 , 27 , 245 , 79 , 172 , 195 , 122 , 204 , 81 , 147 , 255 , 19 , 99 , 84 , 131 , 151 , 89 , 169 , 238 , 230 , 34 , 150 , 207 , 242 , 136 , 44 , 214 , 230 , 35 , 81 , 233 , 88 , 116 , 190 , 95 , 49 , 58 , 21 , 24 , 157 , 10 , 161 , 93 , 56 , 21 , 69 , 53 , 240 , 58 , 247 , 84 , 56 , 137 , 205 , 169 , 117 , 176 , 91 , 91 , 173 , 58 , 167 , 1 , 58 , 167 , 1 , 222 , 145 , 85 , 0 , 187 , 67 , 160 , 18 , 27 , 113 , 36 , 54 , 226 , 48 , 31 , 16 , 148 , 138 , 124 , 56 , 140 , 102 , 129 , 177 , 199 , 82 , 226 , 163 , 21 , 243 , 68 , 228 , 9 , 212 , 90 , 20 , 139 , 107 , 81 , 184 , 30 , 232 , 130 , 161 , 203 , 140 , 150 , 1 , 27 , 90 , 6 , 108 , 205 , 59 , 8 , 40 , 20 , 242 , 109 , 168 , 193 , 253 , 203 , 50 , 96 , 21 , 131 , 246 , 230 , 50 , 57 , 108 , 140 , 149 , 158 , 210 , 107 , 52 , 129 , 10 , 92 , 222 , 168 , 232 , 100 , 79 , 20 , 168 , 61 , 64 , 120 , 62 , 136 , 187 , 255 , 246 , 161 , 170 , 105 , 26 , 161 , 62 , 73 , 169 , 72 , 0 , 234 , 178 , 151 , 83 , 161 , 66 , 243 , 1 , 28 , 255 , 246 , 221 , 85 , 7 , 184 , 76 , 157 , 49 , 118 , 164 , 72 , 208 , 110 , 147 , 176 , 164 , 63 , 142 , 193 , 167 , 79 , 128 , 151 , 137 , 73 , 164 , 80 , 43 , 154 , 218 , 15 , 71 , 182 , 124 , 155 , 113 , 156 , 252 , 238 , 105 , 217 , 109 , 176 , 100 , 32 , 33 , 249 , 92 , 239 , 50 , 130 , 162 , 40 , 68 , 214 , 34 , 178 , 215 , 176 , 228 , 183 , 241 , 0 , 32 , 182 , 22 , 133 , 82 , 195 , 148 , 76 , 40 , 55 , 182 , 23 , 253 , 86 , 52 , 115 , 115 , 191 , 101 , 139 , 53 , 9 , 167 , 97 , 90 , 143 , 216 , 144 , 10 , 38 , 176 , 122 , 110 , 9 , 106 , 139 , 6 , 27 , 19 , 94 , 249 , 182 , 60 , 185 , 142 , 131 , 223 , 28 , 148 , 77 , 19 , 95 , 139 , 53 , 148 , 76 , 79 , 190 , 252 , 57 , 160 , 160 , 48 , 252 , 189 , 123 , 160 , 50 , 170 , 113 , 234 , 249 , 123 , 202 , 210 , 172 , 126 , 188 , 12 , 207 , 39 , 130 , 115 , 107 , 255 , 147 , 131 , 48 , 184 , 77 , 149 , 231 , 158 , 173 , 88 , 90 , 254 , 73 , 31 , 22 , 222 , 157 , 5 , 151 , 202 , 110 , 43 , 63 , 255 , 132 , 15 , 243 , 239 , 206 , 238 , 234 , 248 , 84 , 9 , 190 , 75 , 30 , 4 , 175 , 109 , 162 , 227 , 129 , 46 , 88 , 6 , 172 , 232 , 126 , 180 , 31 , 185 , 84 , 22 , 51 , 191 , 152 , 192 , 193 , 111 , 14 , 129 , 102 , 74 , 103 , 92 , 243 , 129 , 22 , 28 , 253 , 139 , 83 , 117 , 169 , 107 , 43 , 191 , 155 , 135 , 247 , 243 , 213 , 178 , 239 , 143 , 60 , 55 , 44 , 191 , 192 , 147 , 35 , 132 , 161 , 36 , 58 , 15 , 247 , 66 , 239 , 148 , 14 , 54 , 170 , 212 , 42 , 177 , 62 , 34 , 61 , 70 , 6 , 102 , 253 , 200 , 38 , 50 , 176 , 30 , 119 , 192 , 224 , 54 , 193 , 113 , 186 , 163 , 148 , 16 , 81 , 194 , 233 , 201 , 197 , 247 , 231 , 74 , 212 , 219 , 188 , 93 , 30 , 109 , 167 , 59 , 74 , 182 , 182 , 175 , 255 , 230 , 10 , 184 , 244 , 246 , 239 , 129 , 228 , 18 , 89 , 92 , 255 , 239 , 43 , 208 , 88 , 88 , 56 , 239 , 115 , 67 , 239 , 50 , 160 , 247 , 171 , 229 , 33 , 55 , 60 , 231 , 151 , 171 , 94 , 12 , 30 , 158 , 15 , 202 , 94 , 193 , 2 , 0 , 9 , 95 , 12 , 89 , 25 , 223 , 174 , 169 , 159 , 143 , 130 , 209 , 171 , 208 , 255 , 228 , 16 , 180 , 14 , 61 , 134 , 254 , 188 , 16 , 90 , 65 , 101 , 20 , 98 , 189 , 173 , 126 , 180 , 136 , 192 , 149 , 77 , 36 , 188 , 81 , 92 , 253 , 247 , 41 , 40 , 148 , 52 , 6 , 159 , 61 , 14 , 70 , 199 , 148 , 164 , 103 , 116 , 213 , 227 , 97 , 201 , 229 , 231 , 27 , 93 , 131 , 231 , 163 , 69 , 248 , 46 , 121 , 209 , 253 , 149 , 3 , 208 , 181 , 27 , 112 , 240 , 137 , 193 , 178 , 32 , 187 , 49 , 111 , 20 , 243 , 191 , 185 , 74 , 8 , 212 , 110 , 99 , 234 , 149 , 209 , 58 , 87 , 135 , 20 , 92 , 103 , 186 , 106 , 82 , 143 , 164 , 84 , 36 , 113 , 128 , 217 , 161 , 189 , 156 , 10 , 53 , 247 , 214 , 76 , 217 , 41 , 134 , 221 , 66 , 25 , 9 , 122 , 246 , 68 , 221 , 246 , 213 , 174 , 125 , 185 , 242 , 139 , 201 , 170 , 87 , 129 , 100 , 227 , 153 , 138 , 19 , 219 , 205 , 128 , 241 , 31 , 95 , 132 , 74 , 47 , 31 , 195 , 166 , 248 , 106 , 133 , 74 , 4 , 10 , 16 , 162 , 149 , 203 , 33 , 178 , 18 , 70 , 42 , 152 , 132 , 218 , 164 , 65 , 116 , 37 , 12 , 181 , 177 , 144 , 103 , 220 , 83 , 170 , 92 , 37 , 139 , 8 , 84 , 62 , 180 , 65 , 204 , 19 , 193 , 181 , 255 , 156 , 6 , 207 , 113 , 8 , 47 , 132 , 16 , 247 , 70 , 49 , 249 , 211 , 234 , 113 , 88 , 22 , 222 , 153 , 197 , 194 , 59 , 179 , 141 , 212 , 148 , 74 , 47 , 197 , 229 , 43 , 213 , 87 , 90 , 236 , 71 , 0 , 160 , 212 , 149 , 215 , 47 , 173 , 42 , 56 , 163 , 210 , 44 , 83 , 49 , 77 , 113 , 127 , 228 , 210 , 210 , 87 , 157 , 200 , 229 , 167 , 208 , 208 , 187 , 58 , 62 , 73 , 183 , 153 , 52 , 210 , 209 , 180 , 232 , 20 , 157 , 87 , 164 , 20 , 74 , 26 , 58 , 167 , 161 , 236 , 20 , 158 , 146 , 101 , 160 , 100 , 25 , 168 , 230 , 54 , 119 , 174 , 126 , 5 , 83 , 21 , 67 , 90 , 240 , 252 , 206 , 69 , 144 , 208 , 92 , 0 , 147 , 47 , 143 , 200 , 95 , 181 , 146 , 203 , 33 , 238 , 149 , 38 , 26 , 113 , 79 , 20 , 113 , 79 , 20 , 186 , 118 , 61 , 12 , 110 , 19 , 44 , 7 , 91 , 203 , 73 , 77 , 38 , 7 , 239 , 197 , 213 , 138 , 118 , 121 , 180 , 12 , 218 , 74 , 8 , 148 , 111 , 196 , 131 , 28 , 199 , 75 , 146 , 111 , 201 , 159 , 155 , 229 , 224 , 189 , 184 , 10 , 131 , 219 , 4 , 231 , 125 , 110 , 104 , 90 , 216 , 138 , 23 , 102 , 111 , 78 , 251 , 170 , 18 , 168 , 217 , 55 , 167 , 234 , 62 , 193 , 23 , 89 , 12 , 137 , 68 , 137 , 86 , 211 , 48 , 116 , 154 , 42 , 44 , 244 , 18 , 226 , 5 , 229 , 217 , 34 , 165 , 150 , 162 , 21 , 21 , 211 , 239 , 52 , 191 , 240 , 124 , 16 , 235 , 35 , 9 , 192 , 159 , 64 , 118 , 107 , 76 , 215 , 85 , 137 , 212 , 79 , 8 , 84 , 19 , 195 , 122 , 204 , 1 , 77 , 11 , 91 , 179 , 122 , 84 , 73 , 69 , 2 , 80 , 151 , 125 , 51 , 248 , 66 , 73 , 145 , 160 , 186 , 73 , 88 , 149 , 107 , 95 , 248 , 28 , 95 , 114 , 215 , 217 , 173 , 134 , 92 , 38 , 87 , 87 , 249 , 242 , 17 , 200 , 99 , 85 , 8 , 20 , 120 , 225 , 10 , 11 , 181 , 81 , 141 , 116 , 40 , 5 , 46 , 153 , 5 , 159 , 205 , 33 , 21 , 78 , 149 , 249 , 76 , 37 , 182 , 252 , 160 , 248 , 92 , 97 , 123 , 41 , 48 , 227 , 71 , 46 , 155 , 195 , 236 , 175 , 47 , 239 , 107 , 125 , 133 , 231 , 67 , 184 , 240 , 119 , 103 , 107 , 74 , 91 , 107 , 186 , 233 , 87 , 199 , 26 , 242 , 219 , 106 , 205 , 175 , 145 , 200 , 68 , 51 , 184 , 248 , 247 , 231 , 10 , 175 , 249 , 134 , 149 , 250 , 194 , 187 , 179 , 88 , 252 , 96 , 174 , 68 , 253 , 24 , 249 , 193 , 57 , 72 , 81 , 154 , 92 , 134 , 3 , 69 , 81 , 101 , 54 , 114 , 249 , 181 , 157 , 238 , 64 , 199 , 25 , 105 , 135 , 116 , 5 , 77 , 33 , 19 , 77 , 99 , 236 , 71 , 159 , 1 , 220 , 246 , 79 , 28 , 20 , 7 , 159 , 172 , 7 , 158 , 79 , 86 , 176 , 57 , 181 , 33 , 65 , 106 , 10 , 245 , 102 , 236 , 49 , 195 , 117 , 95 , 103 , 89 , 154 , 124 , 16 , 218 , 185 , 183 , 102 , 144 , 142 , 164 , 196 , 19 , 172 , 113 , 95 , 12 , 151 , 95 , 31 , 47 , 16 , 201 , 27 , 250 , 243 , 226 , 251 , 115 , 96 , 180 , 76 , 17 , 223 , 171 , 108 , 119 , 35 , 162 , 158 , 200 , 30 , 182 , 163 , 36 , 70 , 94 , 56 , 47 , 61 , 110 , 39 , 202 , 21 , 172 , 75 , 255 , 112 , 30 , 213 , 168 , 113 , 37 , 59 , 185 , 252 , 184 , 84 , 33 , 253 , 236 , 175 , 166 , 64 , 209 , 149 , 23 , 32 , 213 , 34 , 180 , 19 , 2 , 213 , 36 , 112 , 221 , 95 , 155 , 239 , 146 , 156 , 138 , 84 , 175 , 189 , 235 , 254 , 206 , 166 , 33 , 80 , 187 , 65 , 162 , 14 , 255 , 233 , 81 , 124 , 241 , 147 , 207 , 247 , 181 , 76 , 245 , 94 , 151 , 177 , 27 , 215 , 109 , 212 , 68 , 160 , 182 , 20 , 168 , 200 , 74 , 245 , 235 , 49 , 18 , 190 , 184 , 72 , 142 , 184 , 20 , 135 , 241 , 159 , 92 , 172 , 120 , 137 , 239 , 198 , 196 , 26 , 88 , 155 , 22 , 225 , 133 , 160 , 24 , 11 , 38 , 48 , 227 , 39 , 131 , 65 , 19 , 130 , 231 , 121 , 217 , 237 , 25 , 46 , 205 , 1 , 55 , 108 , 51 , 229 , 79 , 92 , 202 , 75 , 88 , 92 , 205 , 249 , 81 , 116 , 225 , 58 , 32 , 41 , 82 , 198 , 165 , 57 , 217 , 223 , 185 , 23 , 72 , 248 , 98 , 72 , 248 , 170 , 251 , 129 , 169 , 244 , 106 , 152 , 182 , 252 , 3 , 43 , 43 , 40 , 193 , 18 , 82 , 199 , 37 , 179 , 146 , 215 , 200 , 0 , 144 , 188 , 114 , 164 , 154 , 221 , 158 , 182 , 163 , 220 , 214 , 137 , 218 , 109 , 160 , 158 , 203 , 167 , 107 , 201 , 47 , 19 , 203 , 0 , 104 , 254 , 176 , 18 , 132 , 64 , 201 , 32 , 191 , 66 , 247 , 87 , 241 , 245 , 144 , 82 , 145 , 236 , 195 , 78 , 241 , 243 , 78 , 237 , 119 , 51 , 148 , 193 , 78 , 47 , 134 , 204 , 147 , 160 , 67 , 127 , 114 , 180 , 226 , 36 , 188 , 219 , 246 , 141 , 42 , 95 , 120 , 62 , 88 , 49 , 226 , 110 , 113 , 71 , 15 , 207 , 7 , 118 , 205 , 190 , 94 , 196 , 189 , 49 , 128 , 138 , 85 , 191 , 14 , 70 , 130 , 80 , 85 , 108 , 243 , 193 , 20 , 102 , 127 , 61 , 13 , 80 , 133 , 35 , 253 , 177 , 181 , 8 , 25 , 12 , 8 , 42 , 43 , 59 , 231 , 150 , 224 , 57 , 183 , 116 , 203 , 148 , 39 , 112 , 101 , 3 , 99 , 255 , 244 , 169 , 244 , 156 , 16 , 76 , 146 , 151 , 78 , 80 , 88 , 64 , 180 , 153 , 95 , 228 , 73 , 53 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 212 , 14 , 5 , 169 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 2 , 130 , 237 , 225 , 255 , 7 , 0 , 124 , 48 , 168 , 127 , 155 , 151 , 10 , 90 , 0 , 0 , 0 , 0 , 73 , 69 , 78 , 68 , 174 , 66 , 96 , 130 , 0 , 0
};
const char* WavetableRow::wavetableRowBackdrop_png     = ( const char* ) resource_WavetableRow_wavetableRowBackdrop_png;
const int   WavetableRow::wavetableRowBackdrop_pngSize = 7688;


//[EndFile] You can add extra defines here...
//[/EndFile]
