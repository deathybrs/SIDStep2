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
#include "../Listeners/ListenerInitializer.h"

class Bank;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SavePatchAsDialog  : public Component,
                           public PatchEditorNameChanged,
                           public juce::Label::Listener,
                           public juce::ComboBox::Listener,
                           public juce::Button::Listener
{
public:
    //==============================================================================
    SavePatchAsDialog ();
    ~SavePatchAsDialog() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	//void setBank(ReferenceCountedObjectPtr<Bank> value);
	void onPatchEditorNameChanged(String value) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void labelTextChanged (juce::Label* labelThatHasChanged) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* oknormal_png;
    static const int oknormal_pngSize;
    static const char* okover_png;
    static const int okover_pngSize;
    static const char* okdown_png;
    static const int okdown_pngSize;
    static const char* cancelNormal_png;
    static const int cancelNormal_pngSize;
    static const char* cancelOver_png;
    static const int cancelOver_pngSize;
    static const char* cancelDown_png;
    static const int cancelDown_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	//ReferenceCountedObjectPtr<Bank> bank;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> patchNameLabel;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::ComboBox> categorySelector;
    std::unique_ptr<juce::ImageButton> okButton;
    std::unique_ptr<juce::ImageButton> cancelButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SavePatchAsDialog)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

