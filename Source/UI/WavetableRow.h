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
#include "../../JuceLibraryCode/JuceHeader.h"
#include "AbstractWavetableRow.h"

//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WavetableRow final
        : public AbstractWavetableRow
        , public Button::Listener
{
public:
    //==============================================================================
    explicit
        WavetableRow (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

    ~WavetableRow () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    unsigned int
        get () const override;

    void
        set (
                unsigned int row_num
              , unsigned int value
                ) override;

    //[/UserMethods]

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

    void
        buttonClicked (
                Button* button_that_was_clicked
                ) override;

    // Binary resources:
    // ReSharper disable CppInconsistentNaming
    static const char* wavetableRowBackdrop_png;
    static const int   wavetableRowBackdrop_pngSize;
    // ReSharper restore CppInconsistentNaming
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < Label >        rowLabel;
    std::unique_ptr < ToggleButton > triangleCheckbox;
    std::unique_ptr < ToggleButton > sawtoothCheckbox;
    std::unique_ptr < ToggleButton > pulseCheckbox;
    std::unique_ptr < ToggleButton > noiseCheckbox;
    std::unique_ptr < ToggleButton > testCheckbox;
    std::unique_ptr < ToggleButton > ringCheckbox;
    std::unique_ptr < ToggleButton > synCheckbox;
    std::unique_ptr < ToggleButton > gateCheckbox;
    // ReSharper disable CppInconsistentNaming
    Image                            cachedImage_wavetableRowBackdrop_png_1;
    // ReSharper restore CppInconsistentNaming


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  WavetableRow )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
