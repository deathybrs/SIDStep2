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
class PulseTableCommandRow final
        : public AbstractPulseTableRow
        , public ComboBox::Listener
        , public Label::Listener
{
public:
    //==============================================================================
    explicit
        PulseTableCommandRow (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

    ~PulseTableCommandRow () override;

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
        comboBoxChanged (
                ComboBox* combo_box_that_has_changed
                ) override;

    void
        labelTextChanged (
                Label* label_that_has_changed
                ) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < ComboBox > commandSelector;
    std::unique_ptr < Label >    rowLabel;
    std::unique_ptr < Label >    argumentLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  PulseTableCommandRow )
};


//[EndFile] You can add extra defines here...
//[/EndFile]
