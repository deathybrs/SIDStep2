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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "AbstractPulseTableRow.h"


//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PulseTableRow final
        : public AbstractPulseTableRow
        , public Label::Listener
{
public:
    //==============================================================================
    explicit
        PulseTableRow (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

    ~PulseTableRow () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    auto
        Get () const -> unsigned override;

    void
        Set (
                unsigned row_num
              , unsigned value
                ) override;

    //[/UserMethods]

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

    void
        labelTextChanged (
                Label* label_that_has_changed
                ) override;

    // Binary resources:
    static const char* pulseTableRow_png;
    static const int   pulseTableRow_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < Label > rowLabel;
    std::unique_ptr < Label > pulseCycle;
    Image                     cachedImage_pulseTableRow_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  PulseTableRow )
};


//[EndFile] You can add extra defines here...
//[/EndFile]
