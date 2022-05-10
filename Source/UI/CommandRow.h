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

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CommandRow  : public Component
{
public:
    //==============================================================================
    CommandRow ();
    ~CommandRow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        AttachCommand (
                size_t                       max_width
              , std::shared_ptr < Command >& command
                );

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    size_t                                    maxWidth;
    std::shared_ptr < Command >               command;
    std::vector < std::shared_ptr < Label > > argumentLabels;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> commandLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CommandRow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

