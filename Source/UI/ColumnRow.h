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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../../JuceLibraryCode/JuceHeader.h"
class Command;
class CommandRow;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ColumnRow  : public Component
{
public:
    //==============================================================================
    ColumnRow ();
    ~ColumnRow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        AttachRow (
                std::vector < size_t >&                      max_widths
              , std::vector < std::shared_ptr < Command > >& commands
                );

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::vector < size_t >                         maxWidths;
    std::vector < std::shared_ptr < Command > >    commands;
    std::vector < std::shared_ptr < CommandRow > > commandRows;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColumnRow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

