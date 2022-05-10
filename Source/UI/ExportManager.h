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
#include "../Listeners/ListenerInitializer.h"
class Recorder;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ExportManager  : public Component,
                       public LivePatchEditorModeClicked,
                       public PatchEditorLiveModeClicked,
                       public ShowExportManager
{
public:
    //==============================================================================
    ExportManager ();
    ~ExportManager() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        AttachRecording (
                std::shared_ptr < Recorder >& record
                );

    void
        onLivePatchEditorModeClicked () override;

    void
        onPatchEditorLiveModeClicked () override;

    void
        onShowExportManager (
                std::shared_ptr < Recorder > record
                ) override;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < Recorder > recording;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Viewport> juce__viewport;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ExportManager)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

