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
#include "../Programs/PatchTreeBuilder.h"
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
class BankMenu  : public Component,
                  public BankTreeChanged,
                  public BankLoad,
                  public PatchTreeBuilder,
                  public juce::Button::Listener
{
public:
    //==============================================================================
    BankMenu ();
    ~BankMenu() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void onBankTreeChanged() override;
	void onBankLoad(String id) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* newPatchNormal_png;
    static const int newPatchNormal_pngSize;
    static const char* newPatchOver_png;
    static const int newPatchOver_pngSize;
    static const char* newPatchDown_png;
    static const int newPatchDown_pngSize;
    static const char* savePatchNormal_png;
    static const int savePatchNormal_pngSize;
    static const char* savePatchOver_png;
    static const int savePatchOver_pngSize;
    static const char* savePatchDown_png;
    static const int savePatchDown_pngSize;
    static const char* savePatchAsNormal_png;
    static const int savePatchAsNormal_pngSize;
    static const char* savePatchAsOver_png;
    static const int savePatchAsOver_pngSize;
    static const char* savePatchAsDown_png;
    static const int savePatchAsDown_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ImageButton> newButton;
    std::unique_ptr<juce::ImageButton> saveButton;
    std::unique_ptr<juce::ImageButton> saveAsButton;
    std::unique_ptr<juce::TreeView> treeView;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BankMenu)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

