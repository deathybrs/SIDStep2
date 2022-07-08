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


class Patches;
// ReSharper disable once CppInconsistentNaming
class SIDStepLookAndFeel;
//[/Headers]

#include "PatchSelector.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!

    Too many inheritances for Projucer, here they are:

        : public Component
        , public ProgramParameterChanged
        , public PulseWidthParameterChanged
        , public AttackParameterChanged
        , public DecayParameterChanged
        , public SustainParameterChanged
        , public ReleaseParameterChanged
        , public FilterVoiceParameterChanged
        , public CutoffParameterChanged
        , public ResonanceParameterChanged
        , public LowPassParameterChanged
        , public BandPassParameterChanged
        , public HighPassParameterChanged
        , public VolumeParameterChanged
        , public PitchBendParameterChanged
        , public VibratoAmountParameterChanged
        , public VibratoDelayParameterChanged
        , public VibratoSpeedParameterChanged
        , public PatchEditorLiveModeClicked
        , public BankProgramChanged
        , public LivePatchListChanged
        , public ShowExportManager
        , public QuarterNoteTick
        , public LiveDoneExporting
        , public LiveTitleChanged
        , public LiveArtistChanged
        , public juce::Slider::Listener
        , public juce::Label::Listener
        , public juce::Button::Listener
        , public Timer

                                                                    //[/Comments]
*/
class LiveMode final
        : public Component
        , public ProgramParameterChanged
        , public PulseWidthParameterChanged
        , public AttackParameterChanged
        , public DecayParameterChanged
        , public SustainParameterChanged
        , public ReleaseParameterChanged
        , public FilterVoiceParameterChanged
        , public CutoffParameterChanged
        , public ResonanceParameterChanged
        , public LowPassParameterChanged
        , public BandPassParameterChanged
        , public HighPassParameterChanged
        , public VolumeParameterChanged
        , public PitchBendParameterChanged
        , public VibratoAmountParameterChanged
        , public VibratoDelayParameterChanged
        , public VibratoSpeedParameterChanged
        , public PatchEditorLiveModeClicked
        , public BankProgramChanged
        , public LivePatchListChanged
        , public ShowExportManager
        , public QuarterNoteTick
        , public LiveDoneExporting
        , public LiveTitleChanged
        , public LiveArtistChanged
        , public Slider::Listener
        , public Label::Listener
        , public Button::Listener
        , public Timer
{
public:
    //==============================================================================
    LiveMode ();

    ~LiveMode () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void
        onProgramParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    // Pulse Width ($d402-$d403 / $d409-$d40a / $d410-$d411)
    void
        onPulseWidthParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    // ADSR ($d405-$d406 / $d40c-$d40d / $d413-$d414)
    void
        onAttackParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onDecayParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onSustainParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onReleaseParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    // Filter Routing ($d417)
    void
        onFilterVoiceParameterChanged (
                unsigned int voice
              , bool         value
                ) override;

    // Filter Cutoff ($d415-$d416)
    void
        onCutoffParameterChanged (
                unsigned int value
                ) override;

    // Filter Routing ($d417)
    void
        onResonanceParameterChanged (
                unsigned int value
                ) override;

    // Filter Mode & Volume Control ($d418)
    void
        onLowPassParameterChanged (
                bool value
                ) override;

    void
        onBandPassParameterChanged (
                bool value
                ) override;

    void
        onHighPassParameterChanged (
                bool value
                ) override;

    void
        onVolumeParameterChanged (
                unsigned int value
                ) override;

    // No direct memory
    void
        onPitchBendParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onVibratoAmountParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onVibratoDelayParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onVibratoSpeedParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onPatchEditorLiveModeClicked () override;

    void
        onBankProgramChanged (
                String                                   old_id
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onLivePatchListChanged (
                Array < String > names
                ) override;

    void
        onLiveTitleChanged (
                String value
                ) override;

    void
        onLiveArtistChanged (
                String value
                ) override;

    void
        onQuarterNoteTick (
                unsigned int ppq
              , bool         playing
                ) override;

    void
        timerCallback () override;

    void
        onLiveDoneExporting () override;

    void
        onShowExportManager (
                std::shared_ptr < Recorder > record
                ) override;

    //int getPatchListMode() const;
    void
        HidePatchSelector () const;

    void
        RefreshPatches ();

    int
        GetPatchListIndex () const;

    void
        SendInit () const;

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
    static const char* liveModeBackdrop_png;
    static const int   liveModeBackdrop_pngSize;
    static const char* recordnormal_png;
    static const int   recordnormal_pngSize;
    static const char* recordover_png;
    static const int   recordover_pngSize;
    static const char* recorddown_png;
    static const int   recorddown_pngSize;
    static const char* recordIndicator_png;
    static const int   recordIndicator_pngSize;
    static const char* recordIndicatorblink_png;
    static const int   recordIndicatorblink_pngSize;
    static const char* bigCheck_png;
    static const int   bigCheck_pngSize;
    static const char* liveModeButtonDown_png;
    static const int   liveModeButtonDown_pngSize;
    static const char* patchEditorButtonNormal_png;
    static const int   patchEditorButtonNormal_pngSize;
    static const char* patchEditorButtonOver_png;
    static const int   patchEditorButtonOver_pngSize;
    static const char* patchEditorButtonDown_png;
    static const int   patchEditorButtonDown_pngSize;
    static const char* addButtonNormal_png;
    static const int   addButtonNormal_pngSize;
    static const char* addButtonOver_png;
    static const int   addButtonOver_pngSize;
    static const char* addButtonDown_png;
    static const int   addButtonDown_pngSize;
    static const char* replaceButtonNormal_png;
    static const int   replaceButtonNormal_pngSize;
    static const char* replaceButtonOver_png;
    static const int   replaceButtonOver_pngSize;
    static const char* replaceButtonDown_png;
    static const int   replaceButtonDown_pngSize;
    static const char* removeButtonNormal_png;
    static const int   removeButtonNormal_pngSize;
    static const char* removeButtonOver_png;
    static const int   removeButtonOver_pngSize;
    static const char* removeButtonDown_png;
    static const int   removeButtonDown_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer < SIDStepLookAndFeel > look;
    ScopedPointer < Patches >            patches;
    bool                                 armed;
    bool                                 quarterNoteTicked {};
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < Slider >       volumeSlider;
    std::unique_ptr < Label >        volumeLabel;
    std::unique_ptr < Slider >       patch1Slider;
    std::unique_ptr < Slider >       attack1Slider;
    std::unique_ptr < Slider >       decay1Slider;
    std::unique_ptr < Slider >       sustain1Slider;
    std::unique_ptr < Slider >       release1Slider;
    std::unique_ptr < Slider >       pitchBend1Slider;
    std::unique_ptr < Slider >       vibratoAmount1Slider;
    std::unique_ptr < Slider >       vibratoSpeed1Slider;
    std::unique_ptr < Slider >       pulseWidth1Slider;
    std::unique_ptr < Slider >       vibratoDelay1Slider;
    std::unique_ptr < Slider >       patch2Slider;
    std::unique_ptr < Slider >       attack2Slider;
    std::unique_ptr < Slider >       decay2Slider;
    std::unique_ptr < Slider >       sustain2Slider;
    std::unique_ptr < Slider >       release2Slider;
    std::unique_ptr < Slider >       pitchBend2Slider;
    std::unique_ptr < Slider >       vibratoAmount2Slider;
    std::unique_ptr < Slider >       vibratoSpeed2Slider;
    std::unique_ptr < Slider >       pulseWidth2Slider;
    std::unique_ptr < Slider >       vibratoDelay2Slider;
    std::unique_ptr < Slider >       patch3Slider;
    std::unique_ptr < Slider >       attack3Slider;
    std::unique_ptr < Slider >       decay3Slider;
    std::unique_ptr < Slider >       sustain3Slider;
    std::unique_ptr < Slider >       release3Slider;
    std::unique_ptr < Slider >       pitchBend3Slider;
    std::unique_ptr < Slider >       vibratoAmount3Slider;
    std::unique_ptr < Slider >       vibratoSpeed3Slider;
    std::unique_ptr < Slider >       pulseWidth3Slider;
    std::unique_ptr < Slider >       vibratoDelay3Slider;
    std::unique_ptr < Slider >       cutoffSlider;
    std::unique_ptr < Slider >       resonanceSlider;
    std::unique_ptr < Label >        patch1Label;
    std::unique_ptr < Label >        attack1Label;
    std::unique_ptr < Label >        decay1Label;
    std::unique_ptr < Label >        sustain1Label;
    std::unique_ptr < Label >        release1Label;
    std::unique_ptr < Label >        pitchBend1Label;
    std::unique_ptr < Label >        vibratoAmount1Label;
    std::unique_ptr < Label >        vibratoSpeed1Label;
    std::unique_ptr < Label >        pulseWidth1Label;
    std::unique_ptr < Label >        vibratoDelay1Label;
    std::unique_ptr < Label >        patch2Label;
    std::unique_ptr < Label >        attack2Label;
    std::unique_ptr < Label >        decay2Label;
    std::unique_ptr < Label >        sustain2Label;
    std::unique_ptr < Label >        release2Label;
    std::unique_ptr < Label >        pitchBend2Label;
    std::unique_ptr < Label >        vibratoAmount2Label;
    std::unique_ptr < Label >        vibratoSpeed2Label;
    std::unique_ptr < Label >        pulseWidth2Label;
    std::unique_ptr < Label >        vibratoDelay2Label;
    std::unique_ptr < Label >        patch3Label;
    std::unique_ptr < Label >        attack3Label;
    std::unique_ptr < Label >        decay3Label;
    std::unique_ptr < Label >        sustain3Label;
    std::unique_ptr < Label >        release3Label;
    std::unique_ptr < Label >        pitchBend3Label;
    std::unique_ptr < Label >        vibratoAmount3Label;
    std::unique_ptr < Label >        vibratoSpeed3Label;
    std::unique_ptr < Label >        pulseWidth3Label;
    std::unique_ptr < Label >        vibratoDelay3Label;
    std::unique_ptr < Label >        cutoffLabel;
    std::unique_ptr < Label >        resonanceLabel;
    std::unique_ptr < Label >        titleLabel;
    std::unique_ptr < Label >        artistLabel;
    std::unique_ptr < ImageButton >  exportButton;
    std::unique_ptr < Viewport >     patchesViewport;
    std::unique_ptr < ToggleButton > filter1Checkbox;
    std::unique_ptr < ToggleButton > filter2Checkbox;
    std::unique_ptr < ToggleButton > filter3Checkbox;
    std::unique_ptr < ToggleButton > filterLowPassCheckbox;
    std::unique_ptr < ToggleButton > filterBandPassCheckbox;
    std::unique_ptr < ToggleButton > filterHighPassCheckbox;
    std::unique_ptr < ImageButton >  patchEditorButton;
    std::unique_ptr < ImageButton >  addPatchButton;
    std::unique_ptr < ImageButton >  replacePatchButton;
    std::unique_ptr < ImageButton >  removePatchButton;
    std::unique_ptr < PatchSelector >      patchSelector;
    Image                            cachedImage_liveModeBackdrop_png_1;
    Image                            cachedImage_recordIndicator_png_2;
    Image                            cachedImage_liveModeButtonDown_png_3;
    Image                            cachedImage_recordIndicatorblink_png_4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  LiveMode )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
