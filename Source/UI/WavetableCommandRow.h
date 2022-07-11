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

class Bank;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WavetableCommandRow  : public AbstractWavetableRow,
                             public juce::ComboBox::Listener,
                             public juce::Label::Listener
{
public:
    //==============================================================================
    WavetableCommandRow (std::shared_ptr < EventDispatcher > dispatcher);
    ~WavetableCommandRow() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	unsigned int get() const override;
	unsigned int getArgument() const;
	void set(unsigned int rownum, unsigned int value) override;
	void set(unsigned int rownum, unsigned int value, unsigned int argument);
	//void setBank(ReferenceCountedObjectPtr<Bank> value);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void labelTextChanged (juce::Label* labelThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	//ReferenceCountedObjectPtr<Bank> bank;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ComboBox> commandSelector;
    std::unique_ptr<juce::Label> rowLabel;
    std::unique_ptr<juce::Label> argumentLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WavetableCommandRow)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

