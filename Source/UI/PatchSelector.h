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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchSelector  : public Component,
                       public BankTreeChanged,
                       public PatchTreeBuilder
{
public:
    //==============================================================================
    PatchSelector ();
    ~PatchSelector() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	//void setPatchSelectorRoot(TreeViewItem *root) const;
	void onBankTreeChanged() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TreeView> treeView;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchSelector)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

