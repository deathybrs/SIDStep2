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
class LiveMode
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
                juce::Graphics& g
                ) override;

    void
        resized () override;

    void
        sliderValueChanged (
                juce::Slider* sliderThatWasMoved
                ) override;

    void
        labelTextChanged (
                juce::Label* labelThatHasChanged
                ) override;

    void
        buttonClicked (
                juce::Button* buttonThatWasClicked
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
    bool                                 quarterNoteTicked;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < juce::Slider >       volumeSlider;
    std::unique_ptr < juce::Label >        volumeLabel;
    std::unique_ptr < juce::Slider >       patch1Slider;
    std::unique_ptr < juce::Slider >       attack1Slider;
    std::unique_ptr < juce::Slider >       decay1Slider;
    std::unique_ptr < juce::Slider >       sustain1Slider;
    std::unique_ptr < juce::Slider >       release1Slider;
    std::unique_ptr < juce::Slider >       pitchBend1Slider;
    std::unique_ptr < juce::Slider >       vibratoAmount1Slider;
    std::unique_ptr < juce::Slider >       vibratoSpeed1Slider;
    std::unique_ptr < juce::Slider >       pulseWidth1Slider;
    std::unique_ptr < juce::Slider >       vibratoDelay1Slider;
    std::unique_ptr < juce::Slider >       patch2Slider;
    std::unique_ptr < juce::Slider >       attack2Slider;
    std::unique_ptr < juce::Slider >       decay2Slider;
    std::unique_ptr < juce::Slider >       sustain2Slider;
    std::unique_ptr < juce::Slider >       release2Slider;
    std::unique_ptr < juce::Slider >       pitchBend2Slider;
    std::unique_ptr < juce::Slider >       vibratoAmount2Slider;
    std::unique_ptr < juce::Slider >       vibratoSpeed2Slider;
    std::unique_ptr < juce::Slider >       pulseWidth2Slider;
    std::unique_ptr < juce::Slider >       vibratoDelay2Slider;
    std::unique_ptr < juce::Slider >       patch3Slider;
    std::unique_ptr < juce::Slider >       attack3Slider;
    std::unique_ptr < juce::Slider >       decay3Slider;
    std::unique_ptr < juce::Slider >       sustain3Slider;
    std::unique_ptr < juce::Slider >       release3Slider;
    std::unique_ptr < juce::Slider >       pitchBend3Slider;
    std::unique_ptr < juce::Slider >       vibratoAmount3Slider;
    std::unique_ptr < juce::Slider >       vibratoSpeed3Slider;
    std::unique_ptr < juce::Slider >       pulseWidth3Slider;
    std::unique_ptr < juce::Slider >       vibratoDelay3Slider;
    std::unique_ptr < juce::Slider >       cutoffSlider;
    std::unique_ptr < juce::Slider >       resonanceSlider;
    std::unique_ptr < juce::Label >        patch1Label;
    std::unique_ptr < juce::Label >        attack1Label;
    std::unique_ptr < juce::Label >        decay1Label;
    std::unique_ptr < juce::Label >        sustain1Label;
    std::unique_ptr < juce::Label >        release1Label;
    std::unique_ptr < juce::Label >        pitchBend1Label;
    std::unique_ptr < juce::Label >        vibratoAmount1Label;
    std::unique_ptr < juce::Label >        vibratoSpeed1Label;
    std::unique_ptr < juce::Label >        pulseWidth1Label;
    std::unique_ptr < juce::Label >        vibratoDelay1Label;
    std::unique_ptr < juce::Label >        patch2Label;
    std::unique_ptr < juce::Label >        attack2Label;
    std::unique_ptr < juce::Label >        decay2Label;
    std::unique_ptr < juce::Label >        sustain2Label;
    std::unique_ptr < juce::Label >        release2Label;
    std::unique_ptr < juce::Label >        pitchBend2Label;
    std::unique_ptr < juce::Label >        vibratoAmount2Label;
    std::unique_ptr < juce::Label >        vibratoSpeed2Label;
    std::unique_ptr < juce::Label >        pulseWidth2Label;
    std::unique_ptr < juce::Label >        vibratoDelay2Label;
    std::unique_ptr < juce::Label >        patch3Label;
    std::unique_ptr < juce::Label >        attack3Label;
    std::unique_ptr < juce::Label >        decay3Label;
    std::unique_ptr < juce::Label >        sustain3Label;
    std::unique_ptr < juce::Label >        release3Label;
    std::unique_ptr < juce::Label >        pitchBend3Label;
    std::unique_ptr < juce::Label >        vibratoAmount3Label;
    std::unique_ptr < juce::Label >        vibratoSpeed3Label;
    std::unique_ptr < juce::Label >        pulseWidth3Label;
    std::unique_ptr < juce::Label >        vibratoDelay3Label;
    std::unique_ptr < juce::Label >        cutoffLabel;
    std::unique_ptr < juce::Label >        resonanceLabel;
    std::unique_ptr < juce::Label >        titleLabel;
    std::unique_ptr < juce::Label >        artistLabel;
    std::unique_ptr < juce::ImageButton >  exportButton;
    std::unique_ptr < juce::Viewport >     patchesViewport;
    std::unique_ptr < juce::ToggleButton > filter1Checkbox;
    std::unique_ptr < juce::ToggleButton > filter2Checkbox;
    std::unique_ptr < juce::ToggleButton > filter3Checkbox;
    std::unique_ptr < juce::ToggleButton > filterLowPassCheckbox;
    std::unique_ptr < juce::ToggleButton > filterBandPassCheckbox;
    std::unique_ptr < juce::ToggleButton > filterHighPassCheckbox;
    std::unique_ptr < juce::ImageButton >  patchEditorButton;
    std::unique_ptr < juce::ImageButton >  addPatchButton;
    std::unique_ptr < juce::ImageButton >  replacePatchButton;
    std::unique_ptr < juce::ImageButton >  removePatchButton;
    std::unique_ptr < PatchSelector >      patchSelector;
    juce::Image                            cachedImage_liveModeBackdrop_png_1;
    juce::Image                            cachedImage_recordIndicator_png_2;
    juce::Image                            cachedImage_liveModeButtonDown_png_3;
    juce::Image                            cachedImage_recordIndicatorblink_png_4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  LiveMode )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
