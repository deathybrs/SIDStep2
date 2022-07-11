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
class AbstractWavetableRow;


//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WavetableView final
        : public Component
        , public BankProgramChanged
        , public PatchEditorNewTableRowClicked
        , public PatchEditorNewTableCommandClicked
        , public PatchEditorDeleteTableRowClicked
        , public PatchEditorShowWaveTable
        , public PatchEditorShowNoteTable
        , public PatchEditorShowPulseTable
{
public:
    //==============================================================================
    WavetableView (
            const std::shared_ptr < EventDispatcher >& dispatcher
            );

    ~WavetableView () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        onPatchEditorShowNoteTable () override;

    void
        onPatchEditorShowPulseTable () override;

    void
        onPatchEditorShowWaveTable () override;

    void
        onBankProgramChanged (
                String                                   old_id
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onPatchEditorNewTableRowClicked () override;

    void
        onPatchEditorNewTableCommandClicked () override;

    void
        onPatchEditorDeleteTableRowClicked () override;

    //[/UserMethods]

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

    void
        mouseUp (
                const MouseEvent& e
                ) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < EventDispatcher > dispatcher;
    OwnedArray < AbstractWavetableRow > rows;
    int                                 selectedRow {};
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  WavetableView )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
