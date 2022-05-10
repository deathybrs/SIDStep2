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
#include <memory>
#include "ColumnRow.h"

//[/Headers]

#include "FrameRow.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FrameRow::FrameRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    FrameIndex = std::make_unique < Label > (
                                             "new label"
                                           , TRANS (
                                                    "0000" ) );
    addAndMakeVisible (
                       FrameIndex . get () );
    FrameIndex -> setFont (
                           Font (
                                 "C64 Pro Mono"
                               , 15.00F
                               , Font::plain ) . withTypefaceStyle (
                                                                    "Regular" ) );
    FrameIndex -> setJustificationType (
                                        Justification::centred );
    FrameIndex -> setEditable (
                               false
                             , false
                             , false );
    FrameIndex -> setColour (
                             Label::textColourId
                           , Colours::red );
    FrameIndex -> setBounds (
                             8
                           , 0
                           , 72
                           , 40 );


    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             1440
           , 40 );


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

FrameRow::~FrameRow ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    FrameIndex = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void
    FrameRow::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void
    FrameRow::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    FrameRow::AttachRow (
            const int                                                       frame
          , std::array < std::vector < size_t > , 4 >&                      max_widths
          , std::vector < std::shared_ptr < Command > >&                    global_commands
          , std::array < std::vector < std::shared_ptr < Command > > , 3 >& voice_commands
            )
{
    this -> frame  = frame;
    maxWidths      = max_widths;
    globalCommands = global_commands;
    voiceCommands  = voice_commands;
    FrameIndex -> setText (
                           String::toHexString (
                                                frame ) . paddedLeft (
                                                                      '0'
                                                                    , 4 )
                         , dontSendNotification );
    auto running_width = 72;
    {
        auto column_row = std::make_shared < ColumnRow > ();
        column_row -> AttachRow (
                                 max_widths . at (
                                                  0 )
                               , globalCommands );
        addAndMakeVisible (
                           *column_row );
        column_row -> setBounds (
                                 running_width
                               , 0
                               , column_row -> getWidth ()
                               , 40 );
        rows . at (
                   0 ) = column_row;
        running_width += column_row -> getWidth ();
    }
    for ( size_t voice = 0 ; voice < 3 ; voice++ )
    {
        auto column_row = std::make_shared < ColumnRow > ();
        column_row -> AttachRow (
                                 max_widths . at (
                                                  voice + 1 )
                               , voiceCommands . at (
                                                     voice ) );
        addAndMakeVisible (
                           *column_row );
        column_row -> setBounds (
                                 running_width
                               , 0
                               , column_row -> getWidth ()
                               , 40 );
        rows . at (
                   voice + 1 ) = column_row;
        running_width += column_row -> getWidth ();
    }
    setBounds (
               0
             , 0
             , running_width
             , 40 );
    repaint ();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FrameRow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1440" initialHeight="40">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="de998179226b566e" memberName="FrameIndex"
         virtualName="" explicitFocusOrder="0" pos="8 0 72 40" edTextCol="ff000000"
         edBkgCol="0" labelText="0000" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="C64 Pro Mono" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
