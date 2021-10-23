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
class WavetableRow  : public AbstractWavetableRow,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    WavetableRow ();
    ~WavetableRow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	unsigned int get() const override;
	void set(unsigned int rownum, unsigned int value) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* wavetableRowBackdrop_png;
    static const int wavetableRowBackdrop_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> rowLabel;
    std::unique_ptr<juce::ToggleButton> triangleCheckbox;
    std::unique_ptr<juce::ToggleButton> sawtoothCheckbox;
    std::unique_ptr<juce::ToggleButton> pulseCheckbox;
    std::unique_ptr<juce::ToggleButton> noiseCheckbox;
    std::unique_ptr<juce::ToggleButton> testCheckbox;
    std::unique_ptr<juce::ToggleButton> ringCheckbox;
    std::unique_ptr<juce::ToggleButton> synCheckbox;
    std::unique_ptr<juce::ToggleButton> gateCheckbox;
    juce::Image cachedImage_wavetableRowBackdrop_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WavetableRow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

