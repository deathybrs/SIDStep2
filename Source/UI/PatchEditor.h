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
#include "JuceHeader.h"


#include "../Listeners/ListenerInitializer.h"


class SIDStepLookAndFeel;
class WavetableView;
class NoteTableView;
class PulseTableView;


//[/Headers]

#include "WavetableText.h"
#include "WaveformView.h"
#include "BankMenu.h"
#include "SavePatchAsDialog.h"
#include "NoteTableText.h"
#include "PulseTableText.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PatchEditor  : public Component,
                     public BankProgramChanged,
                     public BankStartSaveAs,
                     public LivePatchEditorModeClicked,
                     public PatchEditorShowNoteTable,
                     public PatchEditorShowPulseTable,
                     public PatchEditorShowWaveTable,
                     public juce::Slider::Listener,
                     public juce::Label::Listener,
                     public juce::Button::Listener
{
public:
    //==============================================================================
    PatchEditor ();
    ~PatchEditor() override;

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

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void labelTextChanged (juce::Label* labelThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* patchEditorBackdrop_png;
    static const int patchEditorBackdrop_pngSize;
    static const char* liveModeButtonNormal_png;
    static const int liveModeButtonNormal_pngSize;
    static const char* liveModeButtonOver_png;
    static const int liveModeButtonOver_pngSize;
    static const char* liveModeButtonDown_png;
    static const int liveModeButtonDown_pngSize;
    static const char* patchEditorButtonDown_png;
    static const int patchEditorButtonDown_pngSize;
    static const char* downArrowNormal_png;
    static const int downArrowNormal_pngSize;
    static const char* newRowNormal_png;
    static const int newRowNormal_pngSize;
    static const char* newRowOver_png;
    static const int newRowOver_pngSize;
    static const char* newRowDown_png;
    static const int newRowDown_pngSize;
    static const char* newCommandNormal_png;
    static const int newCommandNormal_pngSize;
    static const char* newCommandOver_png;
    static const int newCommandOver_pngSize;
    static const char* newCommandDown_png;
    static const int newCommandDown_pngSize;
    static const char* deleteNormal_png;
    static const int deleteNormal_pngSize;
    static const char* deleteOver_png;
    static const int deleteOver_pngSize;
    static const char* deleteDown_png;
    static const int deleteDown_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer < SIDStepLookAndFeel > look;
    ScopedPointer < WavetableView >      wavetable;
    ScopedPointer < NoteTableView >      noteTable;
    ScopedPointer < PulseTableView >     pulseTable;

    SharedResourcePointer < ListenerList < PatchEditorNameChanged > > patchEditorNameChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorAttackChanged > >  patchEditorAttackChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorDecayChanged > >   patchEditorDecayChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorSustainChanged > > patchEditorSustainChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorReleaseChanged > > patchEditorReleaseChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorPitchBendRangeChanged > >    patchEditorPitchBendRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthRangeChanged > >   patchEditorPulseWidthRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthCenterChanged > >  patchEditorPulseWidthCenterChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorPulseWidthDefaultChanged > > patchEditorPulseWidthDefaultChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorTremoloRangeChanged > >         patchEditorTremoloRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloSpeedChanged > >         patchEditorTremoloSpeedChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloDefaultAmountChanged > > patchEditorTremoloDefaultAmountChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorTremoloDefaultSpeedChanged > >  patchEditorTremoloDefaultSpeedChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorVibratoRangeChanged > >         patchEditorVibratoRangeChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoSpeedChanged > >         patchEditorVibratoSpeedChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDelayChanged > >         patchEditorVibratoDelayChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultAmountChanged > > patchEditorVibratoDefaultAmountChangedListeners;
    SharedResourcePointer < ListenerList < PatchEditorVibratoDefaultSpeedChanged > >  patchEditorVibratoDefaultSpeedChangedListeners;

    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > >     patchEditorNewWavetableRowClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > patchEditorNewWavetableCommandClickedListeners;
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > >  patchEditorDeleteWaveatableRowClickedListeners;

    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > > patchEditorLiveModeClickedListeners;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> attackSlider;
    std::unique_ptr<juce::Slider> decaySlider;
    std::unique_ptr<juce::Slider> sustainSlider;
    std::unique_ptr<juce::Slider> releaseSlider;
    std::unique_ptr<juce::Slider> pitchBendRangeSlider;
    std::unique_ptr<juce::Slider> vibratoRangeSlider;
    std::unique_ptr<juce::Slider> vibratoSpeedSlider;
    std::unique_ptr<juce::Slider> pulseWidthRangeSlider;
    std::unique_ptr<juce::Slider> vibratoDelaySlider;
    std::unique_ptr<juce::Label> attackLabel;
    std::unique_ptr<juce::Label> decayLabel;
    std::unique_ptr<juce::Label> sustainLabel;
    std::unique_ptr<juce::Label> releaseLabel;
    std::unique_ptr<juce::Label> pitchBendRangeLabel;
    std::unique_ptr<juce::Label> vibratoRangeLabel;
    std::unique_ptr<juce::Label> vibratoSpeedLabel;
    std::unique_ptr<juce::Label> pulseWidthRangeLabel;
    std::unique_ptr<juce::Label> vibratoDelayLabel;
    std::unique_ptr<juce::Label> patchName;
    std::unique_ptr<juce::ImageButton> liveModeButton;
    std::unique_ptr<juce::ImageButton> menuButton;
    std::unique_ptr<juce::Viewport> commandTableViewport;
    std::unique_ptr<WavetableText> wavetableText;
    std::unique_ptr<juce::ImageButton> newRowButton;
    std::unique_ptr<juce::ImageButton> newCommandButton;
    std::unique_ptr<juce::ImageButton> deleteButton;
    std::unique_ptr<WaveformView> waveformView;
    std::unique_ptr<juce::Label> vibratoDefaultAmountLabel;
    std::unique_ptr<juce::Label> vibratoDefaultSpeedLabel;
    std::unique_ptr<juce::Label> pulseWidthCenterLabel;
    std::unique_ptr<juce::Label> pulseWidthDefaultLabel;
    std::unique_ptr<juce::Slider> vibratoDefaultAmountSlider;
    std::unique_ptr<juce::Slider> vibratoDefaultSpeedSlider;
    std::unique_ptr<juce::Slider> pulseWidthCenterSlider;
    std::unique_ptr<juce::Slider> pulseWidthDefaultSlider;
    std::unique_ptr<BankMenu> bankMenu;
    std::unique_ptr<SavePatchAsDialog> saveAsDialog;
    std::unique_ptr<NoteTableText> noteTableText;
    std::unique_ptr<PulseTableText> pulseTableText;
    juce::Image cachedImage_patchEditorBackdrop_png_1;
    juce::Image cachedImage_patchEditorButtonDown_png_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PatchEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

