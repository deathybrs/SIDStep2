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
#include "../Listeners/ListenerInitializer.h"
#include "JuceHeader.h"


// ReSharper disable once CppInconsistentNaming
class SIDStepLookAndFeel;
class WavetableView;
class NoteTableView;
class PulseTableView;

//[/Headers]

#include "BankMenu.h"
#include "NoteTableText.h"
#include "PulseTableText.h"
#include "SavePatchAsDialog.h"
#include "WaveformView.h"
#include "WavetableText.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchEditor final
        : public Component
        , public BankProgramChanged
        , public BankStartSaveAs
        , public LivePatchEditorModeClicked
        , public PatchEditorShowNoteTable
        , public PatchEditorShowPulseTable
        , public PatchEditorShowWaveTable
        , public Slider::Listener
        , public Label::Listener
        , public Button::Listener
{
public:
    //==============================================================================
    explicit
        PatchEditor (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

    ~PatchEditor () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        onBankProgramChanged (
                String                                   old_id
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onBankStartSaveAs () override;

    void
        onLivePatchEditorModeClicked () override;

    void
        onPatchEditorShowNoteTable () override;

    void
        onPatchEditorShowPulseTable () override;

    void
        onPatchEditorShowWaveTable () override;

    //[/UserMethods]

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

    void
        sliderValueChanged (
                Slider* slider_that_was_moved
                ) override;

    void
        labelTextChanged (
                Label* label_that_has_changed
                ) override;

    void
        buttonClicked (
                Button* button_that_was_clicked
                ) override;

    // Binary resources:
    static const char* patchEditorBackdrop_png;
    static const int   patchEditorBackdrop_pngSize;
    static const char* liveModeButtonNormal_png;
    static const int   liveModeButtonNormal_pngSize;
    static const char* liveModeButtonOver_png;
    static const int   liveModeButtonOver_pngSize;
    static const char* liveModeButtonDown_png;
    static const int   liveModeButtonDown_pngSize;
    static const char* patchEditorButtonDown_png;
    static const int   patchEditorButtonDown_pngSize;
    static const char* downArrowNormal_png;
    static const int   downArrowNormal_pngSize;
    static const char* newRowNormal_png;
    static const int   newRowNormal_pngSize;
    static const char* newRowOver_png;
    static const int   newRowOver_pngSize;
    static const char* newRowDown_png;
    static const int   newRowDown_pngSize;
    static const char* newCommandNormal_png;
    static const int   newCommandNormal_pngSize;
    static const char* newCommandOver_png;
    static const int   newCommandOver_pngSize;
    static const char* newCommandDown_png;
    static const int   newCommandDown_pngSize;
    static const char* deleteNormal_png;
    static const int   deleteNormal_pngSize;
    static const char* deleteOver_png;
    static const int   deleteOver_pngSize;
    static const char* deleteDown_png;
    static const int   deleteDown_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < EventDispatcher >    dispatcher;
    std::shared_ptr < SIDStepLookAndFeel > look;
    std::shared_ptr < WavetableView >      wavetable;
    std::shared_ptr < NoteTableView >      noteTable;
    std::shared_ptr < PulseTableView >     pulseTable;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < Slider >            attackSlider;
    std::unique_ptr < Slider >            decaySlider;
    std::unique_ptr < Slider >            sustainSlider;
    std::unique_ptr < Slider >            releaseSlider;
    std::unique_ptr < Slider >            pitchBendRangeSlider;
    std::unique_ptr < Slider >            vibratoRangeSlider;
    std::unique_ptr < Slider >            vibratoSpeedSlider;
    std::unique_ptr < Slider >            pulseWidthRangeSlider;
    std::unique_ptr < Slider >            vibratoDelaySlider;
    std::unique_ptr < Label >             attackLabel;
    std::unique_ptr < Label >             decayLabel;
    std::unique_ptr < Label >             sustainLabel;
    std::unique_ptr < Label >             releaseLabel;
    std::unique_ptr < Label >             pitchBendRangeLabel;
    std::unique_ptr < Label >             vibratoRangeLabel;
    std::unique_ptr < Label >             vibratoSpeedLabel;
    std::unique_ptr < Label >             pulseWidthRangeLabel;
    std::unique_ptr < Label >             vibratoDelayLabel;
    std::unique_ptr < Label >             patchName;
    std::unique_ptr < ImageButton >       liveModeButton;
    std::unique_ptr < ImageButton >       menuButton;
    std::unique_ptr < Viewport >          commandTableViewport;
    std::unique_ptr < WavetableText >     wavetableText;
    std::unique_ptr < ImageButton >       newRowButton;
    std::unique_ptr < ImageButton >       newCommandButton;
    std::unique_ptr < ImageButton >       deleteButton;
    std::unique_ptr < WaveformView >      waveformView;
    std::unique_ptr < Label >             vibratoDefaultAmountLabel;
    std::unique_ptr < Label >             vibratoDefaultSpeedLabel;
    std::unique_ptr < Label >             pulseWidthCenterLabel;
    std::unique_ptr < Label >             pulseWidthDefaultLabel;
    std::unique_ptr < Slider >            vibratoDefaultAmountSlider;
    std::unique_ptr < Slider >            vibratoDefaultSpeedSlider;
    std::unique_ptr < Slider >            pulseWidthCenterSlider;
    std::unique_ptr < Slider >            pulseWidthDefaultSlider;
    std::unique_ptr < BankMenu >          bankMenu;
    std::unique_ptr < SavePatchAsDialog > saveAsDialog;
    std::unique_ptr < NoteTableText >     noteTableText;
    std::unique_ptr < PulseTableText >    pulseTableText;
    Image                                 cachedImage_patchEditorBackdrop_png_1;
    Image                                 cachedImage_patchEditorButtonDown_png_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  PatchEditor )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
