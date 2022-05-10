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
#include "CommandRow.h"

//[/Headers]

#include "ColumnRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ColumnRow::ColumnRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (360, 40);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ColumnRow::~ColumnRow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ColumnRow::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ColumnRow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    ColumnRow::AttachRow (
            std::vector < size_t >&                      max_widths
          , std::vector < std::shared_ptr < Command > >& commands
            )
{
    maxWidths        = max_widths;
    this -> commands = commands;
    auto width       = 0;
    for ( size_t command_index = 0 ; command_index < commands . size () ; command_index++ )
    {
        auto command_row = std::make_shared < CommandRow > ();
        command_row -> AttachCommand (
                                      max_widths . at (
                                                       command_index )
                                    , commands . at (
                                                     command_index ) );
        commandRows . push_back (
                                 command_row );
        addAndMakeVisible (
                           *command_row );
        command_row -> setTopLeftPosition (
                                           width
                                         , 0 );
        width += command_row -> getWidth ();
    }
    setBounds (
               0
             , 0
             , width
             , 40 );
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ColumnRow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="360" initialHeight="40">
  <BACKGROUND backgroundColour="323e44"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

