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

#include <array>

class Command;
class ColumnRow;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FrameRow  : public Component
{
public:
    //==============================================================================
    FrameRow ();
    ~FrameRow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        AttachRow (
                int                                                             frame
              , std::array < std::vector < size_t > , 4 >&                      max_widths
              , std::vector < std::shared_ptr < Command > >&                    global_commands
              , std::array < std::vector < std::shared_ptr < Command > > , 3 >& voice_commands
                );

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int                                                            frame {};
    std::array < std::vector < size_t > , 4 >                      maxWidths;
    std::vector < std::shared_ptr < Command > >                    globalCommands;
    std::array < std::vector < std::shared_ptr < Command > > , 3 > voiceCommands;

    std::array < std::shared_ptr < ColumnRow > , 4 > rows;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> FrameIndex;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FrameRow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

