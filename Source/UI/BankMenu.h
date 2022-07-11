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
#include <JuceHeader.h>

#include "../Listeners/ListenerInitializer.h"
#include "../Programs/PatchTreeBuilder.h"


class Bank;


//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class BankMenu
        : public Component
        , public BankTreeChanged
        , public BankLoad
        , public PatchTreeBuilder
        , public Button::Listener
{
public:
    //==============================================================================
    explicit
        BankMenu (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    ~BankMenu () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        onBankTreeChanged () override;

    void
        onBankLoad (
                String id
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
    static const char* newPatchNormal_png;
    static const int   newPatchNormal_pngSize;
    static const char* newPatchOver_png;
    static const int   newPatchOver_pngSize;
    static const char* newPatchDown_png;
    static const int   newPatchDown_pngSize;
    static const char* savePatchNormal_png;
    static const int   savePatchNormal_pngSize;
    static const char* savePatchOver_png;
    static const int   savePatchOver_pngSize;
    static const char* savePatchDown_png;
    static const int   savePatchDown_pngSize;
    static const char* savePatchAsNormal_png;
    static const int   savePatchAsNormal_pngSize;
    static const char* savePatchAsOver_png;
    static const int   savePatchAsOver_pngSize;
    static const char* savePatchAsDown_png;
    static const int   savePatchAsDown_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < EventDispatcher > dispatcher;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < ImageButton > newButton;
    std::unique_ptr < ImageButton > saveButton;
    std::unique_ptr < ImageButton > saveAsButton;
    std::unique_ptr < TreeView >    treeView;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  BankMenu )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
