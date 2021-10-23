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

//[Headers] You can add your own extra header files here...
#include "../SIDProgram.h"

#include "NoteTableView.h"
#include "PulseTableView.h"
#include "SIDStepLookAndFeel.h"
#include "WavetableView.h"
//[/Headers]

#include "PatchEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatchEditor::PatchEditor ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    look = new SIDStepLookAndFeel;
    setLookAndFeel (
                    look
                   );
	//core = nullptr;
    //[/Constructor_pre]

    attackSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (attackSlider.get());
    attackSlider->setRange (0, 15, 1);
    attackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    attackSlider->addListener (this);

    attackSlider->setBounds (64, 121, 48, 48);

    decaySlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (decaySlider.get());
    decaySlider->setRange (0, 15, 1);
    decaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    decaySlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    decaySlider->addListener (this);

    decaySlider->setBounds (144, 121, 48, 48);

    sustainSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (sustainSlider.get());
    sustainSlider->setRange (0, 15, 1);
    sustainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    sustainSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    sustainSlider->addListener (this);

    sustainSlider->setBounds (224, 121, 48, 48);

    releaseSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (releaseSlider.get());
    releaseSlider->setRange (0, 15, 1);
    releaseSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    releaseSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    releaseSlider->addListener (this);

    releaseSlider->setBounds (304, 121, 48, 48);

    pitchBendRangeSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pitchBendRangeSlider.get());
    pitchBendRangeSlider->setRange (0, 8192, 1);
    pitchBendRangeSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pitchBendRangeSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pitchBendRangeSlider->addListener (this);

    pitchBendRangeSlider->setBounds (64, 209, 48, 48);

    vibratoRangeSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoRangeSlider.get());
    vibratoRangeSlider->setRange (0, 8192, 1);
    vibratoRangeSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoRangeSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoRangeSlider->addListener (this);

    vibratoRangeSlider->setBounds (224, 209, 48, 48);

    vibratoSpeedSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoSpeedSlider.get());
    vibratoSpeedSlider->setRange (0, 50, 1);
    vibratoSpeedSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoSpeedSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoSpeedSlider->addListener (this);

    vibratoSpeedSlider->setBounds (304, 209, 48, 48);

    pulseWidthRangeSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidthRangeSlider.get());
    pulseWidthRangeSlider->setRange (0, 4095, 1);
    pulseWidthRangeSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidthRangeSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidthRangeSlider->addListener (this);

    pulseWidthRangeSlider->setBounds (64, 297, 48, 48);

    vibratoDelaySlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDelaySlider.get());
    vibratoDelaySlider->setRange (0, 15, 1);
    vibratoDelaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDelaySlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDelaySlider->addListener (this);

    vibratoDelaySlider->setBounds (224, 367, 48, 48);

    attackLabel.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (attackLabel.get());
    attackLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attackLabel->setJustificationType (juce::Justification::centred);
    attackLabel->setEditable (true, true, false);
    attackLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    attackLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attackLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    attackLabel->addListener (this);

    attackLabel->setBounds (64, 97, 48, 18);

    decayLabel.reset (new juce::Label ("new label",
                                       TRANS("0")));
    addAndMakeVisible (decayLabel.get());
    decayLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decayLabel->setJustificationType (juce::Justification::centred);
    decayLabel->setEditable (true, true, false);
    decayLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    decayLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decayLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    decayLabel->addListener (this);

    decayLabel->setBounds (144, 97, 48, 18);

    sustainLabel.reset (new juce::Label ("new label",
                                         TRANS("0")));
    addAndMakeVisible (sustainLabel.get());
    sustainLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustainLabel->setJustificationType (juce::Justification::centred);
    sustainLabel->setEditable (true, true, false);
    sustainLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    sustainLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustainLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    sustainLabel->addListener (this);

    sustainLabel->setBounds (224, 97, 48, 18);

    releaseLabel.reset (new juce::Label ("new label",
                                         TRANS("0")));
    addAndMakeVisible (releaseLabel.get());
    releaseLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    releaseLabel->setJustificationType (juce::Justification::centred);
    releaseLabel->setEditable (true, true, false);
    releaseLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    releaseLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    releaseLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    releaseLabel->addListener (this);

    releaseLabel->setBounds (304, 97, 48, 18);

    pitchBendRangeLabel.reset (new juce::Label ("new label",
                                                TRANS("0")));
    addAndMakeVisible (pitchBendRangeLabel.get());
    pitchBendRangeLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pitchBendRangeLabel->setJustificationType (juce::Justification::centred);
    pitchBendRangeLabel->setEditable (true, true, false);
    pitchBendRangeLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pitchBendRangeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pitchBendRangeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    pitchBendRangeLabel->addListener (this);

    pitchBendRangeLabel->setBounds (64, 185, 48, 18);

    vibratoRangeLabel.reset (new juce::Label ("new label",
                                              TRANS("0")));
    addAndMakeVisible (vibratoRangeLabel.get());
    vibratoRangeLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoRangeLabel->setJustificationType (juce::Justification::centred);
    vibratoRangeLabel->setEditable (true, true, false);
    vibratoRangeLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoRangeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoRangeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    vibratoRangeLabel->addListener (this);

    vibratoRangeLabel->setBounds (224, 185, 48, 18);

    vibratoSpeedLabel.reset (new juce::Label ("new label",
                                              TRANS("0")));
    addAndMakeVisible (vibratoSpeedLabel.get());
    vibratoSpeedLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoSpeedLabel->setJustificationType (juce::Justification::centred);
    vibratoSpeedLabel->setEditable (true, true, false);
    vibratoSpeedLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoSpeedLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoSpeedLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    vibratoSpeedLabel->addListener (this);

    vibratoSpeedLabel->setBounds (304, 185, 48, 18);

    pulseWidthRangeLabel.reset (new juce::Label ("new label",
                                                 TRANS("0")));
    addAndMakeVisible (pulseWidthRangeLabel.get());
    pulseWidthRangeLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidthRangeLabel->setJustificationType (juce::Justification::centred);
    pulseWidthRangeLabel->setEditable (true, true, false);
    pulseWidthRangeLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidthRangeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidthRangeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    pulseWidthRangeLabel->addListener (this);

    pulseWidthRangeLabel->setBounds (64, 273, 48, 18);

    vibratoDelayLabel.reset (new juce::Label ("new label",
                                              TRANS("0")));
    addAndMakeVisible (vibratoDelayLabel.get());
    vibratoDelayLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDelayLabel->setJustificationType (juce::Justification::centred);
    vibratoDelayLabel->setEditable (true, true, false);
    vibratoDelayLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDelayLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDelayLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    vibratoDelayLabel->addListener (this);

    vibratoDelayLabel->setBounds (224, 343, 48, 18);

    patchName.reset (new juce::Label ("new label",
                                      TRANS("Patch Name")));
    addAndMakeVisible (patchName.get());
    patchName->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    patchName->setJustificationType (juce::Justification::centredLeft);
    patchName->setEditable (true, true, false);
    patchName->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    patchName->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    patchName->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    patchName->addListener (this);

    patchName->setBounds (24, 71, 324, 16);

    liveModeButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (liveModeButton.get());
    liveModeButton->addListener (this);

    liveModeButton->setImages (false, true, true,
                               juce::ImageCache::getFromMemory (liveModeButtonNormal_png, liveModeButtonNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                               juce::ImageCache::getFromMemory (liveModeButtonOver_png, liveModeButtonOver_pngSize), 1.000f, juce::Colour (0x00000000),
                               juce::ImageCache::getFromMemory (liveModeButtonDown_png, liveModeButtonDown_pngSize), 1.000f, juce::Colour (0x00000000));
    liveModeButton->setBounds (32, 544, 154, 26);

    menuButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (menuButton.get());
    menuButton->addListener (this);

    menuButton->setImages (false, true, true,
                           juce::ImageCache::getFromMemory (downArrowNormal_png, downArrowNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                           juce::Image(), 1.000f, juce::Colour (0x00000000),
                           juce::Image(), 1.000f, juce::Colour (0x00000000));
    menuButton->setBounds (353, 73, 14, 12);

    commandTableViewport.reset (new juce::Viewport ("new viewport"));
    addAndMakeVisible (commandTableViewport.get());
    commandTableViewport->setScrollBarsShown (true, false);
    commandTableViewport->setScrollBarThickness (16);

    commandTableViewport->setBounds (400, 16, 608, 184);

    wavetableText.reset (new WavetableText());
    addAndMakeVisible (wavetableText.get());
    wavetableText->setBounds (416, 8, 110, 17);

    newRowButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (newRowButton.get());
    newRowButton->addListener (this);

    newRowButton->setImages (false, true, true,
                             juce::ImageCache::getFromMemory (newRowNormal_png, newRowNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (newRowOver_png, newRowOver_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (newRowDown_png, newRowDown_pngSize), 1.000f, juce::Colour (0x00000000));
    newRowButton->setBounds (448, 192, 154, 26);

    newCommandButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (newCommandButton.get());
    newCommandButton->addListener (this);

    newCommandButton->setImages (false, true, true,
                                 juce::ImageCache::getFromMemory (newCommandNormal_png, newCommandNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                                 juce::ImageCache::getFromMemory (newCommandOver_png, newCommandOver_pngSize), 1.000f, juce::Colour (0x00000000),
                                 juce::ImageCache::getFromMemory (newCommandDown_png, newCommandDown_pngSize), 1.000f, juce::Colour (0x00000000));
    newCommandButton->setBounds (624, 192, 154, 26);

    deleteButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (deleteButton.get());
    deleteButton->addListener (this);

    deleteButton->setImages (false, true, true,
                             juce::ImageCache::getFromMemory (deleteNormal_png, deleteNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (deleteOver_png, deleteOver_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (deleteDown_png, deleteDown_pngSize), 1.000f, juce::Colour (0x00000000));
    deleteButton->setBounds (800, 192, 154, 26);

    waveformView.reset (new WaveformView());
    addAndMakeVisible (waveformView.get());
    waveformView->setBounds (400, 248, 608, 296);

    vibratoDefaultAmountLabel.reset (new juce::Label ("new label",
                                                      TRANS("0%")));
    addAndMakeVisible (vibratoDefaultAmountLabel.get());
    vibratoDefaultAmountLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDefaultAmountLabel->setJustificationType (juce::Justification::centred);
    vibratoDefaultAmountLabel->setEditable (true, true, false);
    vibratoDefaultAmountLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDefaultAmountLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDefaultAmountLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    vibratoDefaultAmountLabel->addListener (this);

    vibratoDefaultAmountLabel->setBounds (224, 264, 48, 18);

    vibratoDefaultSpeedLabel.reset (new juce::Label ("new label",
                                                     TRANS("0%")));
    addAndMakeVisible (vibratoDefaultSpeedLabel.get());
    vibratoDefaultSpeedLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDefaultSpeedLabel->setJustificationType (juce::Justification::centred);
    vibratoDefaultSpeedLabel->setEditable (true, true, false);
    vibratoDefaultSpeedLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDefaultSpeedLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDefaultSpeedLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    vibratoDefaultSpeedLabel->addListener (this);

    vibratoDefaultSpeedLabel->setBounds (304, 264, 48, 18);

    pulseWidthCenterLabel.reset (new juce::Label ("new label",
                                                  TRANS("0")));
    addAndMakeVisible (pulseWidthCenterLabel.get());
    pulseWidthCenterLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidthCenterLabel->setJustificationType (juce::Justification::centred);
    pulseWidthCenterLabel->setEditable (true, true, false);
    pulseWidthCenterLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidthCenterLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidthCenterLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    pulseWidthCenterLabel->addListener (this);

    pulseWidthCenterLabel->setBounds (64, 353, 48, 18);

    pulseWidthDefaultLabel.reset (new juce::Label ("new label",
                                                   TRANS("0%")));
    addAndMakeVisible (pulseWidthDefaultLabel.get());
    pulseWidthDefaultLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidthDefaultLabel->setJustificationType (juce::Justification::centred);
    pulseWidthDefaultLabel->setEditable (true, true, false);
    pulseWidthDefaultLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidthDefaultLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidthDefaultLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    pulseWidthDefaultLabel->addListener (this);

    pulseWidthDefaultLabel->setBounds (64, 433, 48, 18);

    vibratoDefaultAmountSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDefaultAmountSlider.get());
    vibratoDefaultAmountSlider->setRange (0, 100, 1);
    vibratoDefaultAmountSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDefaultAmountSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDefaultAmountSlider->addListener (this);

    vibratoDefaultAmountSlider->setBounds (224, 288, 48, 48);

    vibratoDefaultSpeedSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDefaultSpeedSlider.get());
    vibratoDefaultSpeedSlider->setRange (0, 100, 1);
    vibratoDefaultSpeedSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDefaultSpeedSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDefaultSpeedSlider->addListener (this);

    vibratoDefaultSpeedSlider->setBounds (304, 288, 48, 48);

    pulseWidthCenterSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidthCenterSlider.get());
    pulseWidthCenterSlider->setRange (0, 4095, 1);
    pulseWidthCenterSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidthCenterSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidthCenterSlider->addListener (this);

    pulseWidthCenterSlider->setBounds (64, 376, 48, 48);

    pulseWidthDefaultSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidthDefaultSlider.get());
    pulseWidthDefaultSlider->setRange (-100, 100, 1);
    pulseWidthDefaultSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidthDefaultSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidthDefaultSlider->addListener (this);

    pulseWidthDefaultSlider->setBounds (64, 456, 48, 48);

    bankMenu.reset (new BankMenu());
    addAndMakeVisible (bankMenu.get());
    bankMenu->setBounds (24, 80, 324, 448);

    saveAsDialog.reset (new SavePatchAsDialog());
    addAndMakeVisible (saveAsDialog.get());
    saveAsDialog->setBounds (274, 239, 476, 98);

    noteTableText.reset (new NoteTableText());
    addAndMakeVisible (noteTableText.get());
    noteTableText->setBounds (632, 8, 131, 17);

    pulseTableText.reset (new PulseTableText());
    addAndMakeVisible (pulseTableText.get());
    pulseTableText->setBounds (840, 8, 141, 17);

    cachedImage_patchEditorBackdrop_png_1 = juce::ImageCache::getFromMemory (patchEditorBackdrop_png, patchEditorBackdrop_pngSize);
    cachedImage_patchEditorButtonDown_png_2 = juce::ImageCache::getFromMemory (patchEditorButtonDown_png, patchEditorButtonDown_pngSize);

    //[UserPreSize]
    wavetable = new WavetableView ();
    commandTableViewport -> setViewedComponent (
                                                wavetable
                                              , false
                                               );
    commandTableViewport -> getVerticalScrollBar () -> setAutoHide (
                                                                    false
                                                                   );
    bankMenu -> setVisible (
                            false
                           );
    saveAsDialog -> setVisible (
                                false
                               );

    noteTable = new NoteTableView ();
    pulseTable = new PulseTableView ();

    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this
                                                                            );
    SharedResourcePointer < ListenerList < BankStartSaveAs > > () -> add (
                                                                          this
                                                                         );
    SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > > () -> add (
                                                                                     this
                                                                                    );
    SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> add (
                                                                                    this
                                                                                   );
    SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> add (
                                                                                   this
                                                                                  );
    //[/UserPreSize]

    setSize (1024, 576);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatchEditor::~PatchEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this
                                                                               );
    SharedResourcePointer < ListenerList < BankStartSaveAs > > () -> remove (
                                                                             this
                                                                            );
    SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > > () -> remove (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> remove (
                                                                                      this
                                                                                     );
    SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> remove (
                                                                                       this
                                                                                      );
    SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> remove (
                                                                                      this
                                                                                     );
    //[/Destructor_pre]

    attackSlider = nullptr;
    decaySlider = nullptr;
    sustainSlider = nullptr;
    releaseSlider = nullptr;
    pitchBendRangeSlider = nullptr;
    vibratoRangeSlider = nullptr;
    vibratoSpeedSlider = nullptr;
    pulseWidthRangeSlider = nullptr;
    vibratoDelaySlider = nullptr;
    attackLabel = nullptr;
    decayLabel = nullptr;
    sustainLabel = nullptr;
    releaseLabel = nullptr;
    pitchBendRangeLabel = nullptr;
    vibratoRangeLabel = nullptr;
    vibratoSpeedLabel = nullptr;
    pulseWidthRangeLabel = nullptr;
    vibratoDelayLabel = nullptr;
    patchName = nullptr;
    liveModeButton = nullptr;
    menuButton = nullptr;
    commandTableViewport = nullptr;
    wavetableText = nullptr;
    newRowButton = nullptr;
    newCommandButton = nullptr;
    deleteButton = nullptr;
    waveformView = nullptr;
    vibratoDefaultAmountLabel = nullptr;
    vibratoDefaultSpeedLabel = nullptr;
    pulseWidthCenterLabel = nullptr;
    pulseWidthDefaultLabel = nullptr;
    vibratoDefaultAmountSlider = nullptr;
    vibratoDefaultSpeedSlider = nullptr;
    pulseWidthCenterSlider = nullptr;
    pulseWidthDefaultSlider = nullptr;
    bankMenu = nullptr;
    saveAsDialog = nullptr;
    noteTableText = nullptr;
    pulseTableText = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    wavetable  = nullptr;
    noteTable  = nullptr;
    pulseTable = nullptr;
    look       = nullptr;
    //[/Destructor]
}

//==============================================================================
void PatchEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::white);

    {
        int x = 0, y = 0, width = 1024, height = 576;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_patchEditorBackdrop_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_patchEditorBackdrop_png_1.getWidth(), cachedImage_patchEditorBackdrop_png_1.getHeight());
    }

    {
        int x = 208, y = 544, width = 154, height = 26;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_patchEditorButtonDown_png_2,
                     x, y, width, height,
                     0, 0, cachedImage_patchEditorButtonDown_png_2.getWidth(), cachedImage_patchEditorButtonDown_png_2.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PatchEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attackSlider.get())
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        attackLabel -> setText (
                                attackSlider -> getTextFromValue (
                                                                  attackSlider -> getValue ()
                                                                 )
                              , dontSendNotification
                               );
        patchEditorAttackChangedListeners -> call (
                                                   &PatchEditorAttackChanged::onPatchEditorAttackChanged
                                                 , static_cast < unsigned int > ( attackSlider -> getValue () )
                                                  );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider.get())
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        decayLabel -> setText (
                               decaySlider -> getTextFromValue (
                                                                decaySlider -> getValue ()
                                                               )
                             , dontSendNotification
                              );
        patchEditorDecayChangedListeners -> call (
                                                  &PatchEditorDecayChanged::onPatchEditorDecayChanged
                                                , static_cast < unsigned int > ( decaySlider -> getValue () )
                                                 );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == sustainSlider.get())
    {
        //[UserSliderCode_sustainSlider] -- add your slider handling code here..
        sustainLabel -> setText (
                                 sustainSlider -> getTextFromValue (
                                                                    sustainSlider -> getValue ()
                                                                   )
                               , dontSendNotification
                                );
        patchEditorSustainChangedListeners -> call (
                                                    &PatchEditorSustainChanged::onPatchEditorSustainChanged
                                                  , static_cast < unsigned int > ( sustainSlider -> getValue () )
                                                   );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_sustainSlider]
    }
    else if (sliderThatWasMoved == releaseSlider.get())
    {
        //[UserSliderCode_releaseSlider] -- add your slider handling code here..
        releaseLabel -> setText (
                                 releaseSlider -> getTextFromValue (
                                                                    releaseSlider -> getValue ()
                                                                   )
                               , dontSendNotification
                                );
        patchEditorReleaseChangedListeners -> call (
                                                    &PatchEditorReleaseChanged::onPatchEditorReleaseChanged
                                                  , static_cast < unsigned int > ( releaseSlider -> getValue () )
                                                   );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_releaseSlider]
    }
    else if (sliderThatWasMoved == pitchBendRangeSlider.get())
    {
        //[UserSliderCode_pitchBendRangeSlider] -- add your slider handling code here..
        pitchBendRangeLabel -> setText (
                                        pitchBendRangeSlider -> getTextFromValue (
                                                                                  pitchBendRangeSlider -> getValue ()
                                                                                 )
                                      , dontSendNotification
                                       );
        patchEditorPitchBendRangeChangedListeners -> call (
                                                           &PatchEditorPitchBendRangeChanged::onPatchEditorPitchBendRangeChanged
                                                         , static_cast < unsigned int > ( pitchBendRangeSlider -> getValue () )
                                                          );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_pitchBendRangeSlider]
    }
    else if (sliderThatWasMoved == vibratoRangeSlider.get())
    {
        //[UserSliderCode_vibratoRangeSlider] -- add your slider handling code here..
        vibratoRangeLabel -> setText (
                                      vibratoRangeSlider -> getTextFromValue (
                                                                              vibratoRangeSlider -> getValue ()
                                                                             )
                                    , dontSendNotification
                                     );
        patchEditorVibratoRangeChangedListeners -> call (
                                                         &PatchEditorVibratoRangeChanged::onPatchEditorVibratoRangeChanged
                                                       , static_cast < unsigned int > ( vibratoRangeSlider -> getValue () )
                                                        );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_vibratoRangeSlider]
    }
    else if (sliderThatWasMoved == vibratoSpeedSlider.get())
    {
        //[UserSliderCode_vibratoSpeedSlider] -- add your slider handling code here..
        vibratoSpeedLabel -> setText (
                                      vibratoSpeedSlider -> getTextFromValue (
                                                                              vibratoSpeedSlider -> getValue ()
                                                                             )
                                    , dontSendNotification
                                     );
        patchEditorVibratoSpeedChangedListeners -> call (
                                                         &PatchEditorVibratoSpeedChanged::onPatchEditorVibratoSpeedChanged
                                                       , static_cast < unsigned int > ( vibratoSpeedSlider -> getValue () )
                                                        );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_vibratoSpeedSlider]
    }
    else if (sliderThatWasMoved == pulseWidthRangeSlider.get())
    {
        //[UserSliderCode_pulseWidthRangeSlider] -- add your slider handling code here..
        pulseWidthRangeLabel -> setText (
                                         pulseWidthRangeSlider -> getTextFromValue (
                                                                                    pulseWidthRangeSlider -> getValue ()
                                                                                   )
                                       , dontSendNotification
                                        );
        patchEditorPulseWidthRangeChangedListeners -> call (
                                                            &PatchEditorPulseWidthRangeChanged::onPatchEditorPulseWidthRangeChanged
                                                          , static_cast < unsigned int > ( pulseWidthRangeSlider -> getValue () )
                                                           );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_pulseWidthRangeSlider]
    }
    else if (sliderThatWasMoved == vibratoDelaySlider.get())
    {
        //[UserSliderCode_vibratoDelaySlider] -- add your slider handling code here..
        vibratoDelayLabel -> setText (
                                      vibratoDelaySlider -> getTextFromValue (
                                                                              vibratoDelaySlider -> getValue ()
                                                                             )
                                    , dontSendNotification
                                     );
        patchEditorVibratoDelayChangedListeners -> call (
                                                         &PatchEditorVibratoDelayChanged::onPatchEditorVibratoDelayChanged
                                                       , static_cast < unsigned int > ( vibratoDelaySlider -> getValue () )
                                                        );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_vibratoDelaySlider]
    }
    else if (sliderThatWasMoved == vibratoDefaultAmountSlider.get())
    {
        //[UserSliderCode_vibratoDefaultAmountSlider] -- add your slider handling code here..
        vibratoDefaultAmountLabel -> setText (
                                              vibratoDefaultAmountSlider -> getTextFromValue (
                                                                                              vibratoDefaultAmountSlider -> getValue ()
                                                                                             ) + "%"
                                            , dontSendNotification
                                             );
        patchEditorVibratoDefaultAmountChangedListeners -> call (
                                                                 &PatchEditorVibratoDefaultAmountChanged::onPatchEditorVibratoDefaultAmountChanged
                                                               , static_cast < float > ( vibratoDefaultAmountSlider -> getValue () / 100.0 )
                                                                );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_vibratoDefaultAmountSlider]
    }
    else if (sliderThatWasMoved == vibratoDefaultSpeedSlider.get())
    {
        //[UserSliderCode_vibratoDefaultSpeedSlider] -- add your slider handling code here..
        vibratoDefaultSpeedLabel -> setText (
                                             vibratoDefaultSpeedSlider -> getTextFromValue (
                                                                                            vibratoDefaultSpeedSlider -> getValue ()
                                                                                           ) + "%"
                                           , dontSendNotification
                                            );
        patchEditorVibratoDefaultSpeedChangedListeners -> call (
                                                                &PatchEditorVibratoDefaultSpeedChanged::onPatchEditorVibratoDefaultSpeedChanged
                                                              , static_cast < float > ( vibratoDefaultSpeedSlider -> getValue () / 100.0 )
                                                               );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_vibratoDefaultSpeedSlider]
    }
    else if (sliderThatWasMoved == pulseWidthCenterSlider.get())
    {
        //[UserSliderCode_pulseWidthCenterSlider] -- add your slider handling code here..
        pulseWidthCenterLabel -> setText (
                                          pulseWidthCenterSlider -> getTextFromValue (
                                                                                      pulseWidthCenterSlider -> getValue ()
                                                                                     )
                                        , dontSendNotification
                                         );
        patchEditorPulseWidthCenterChangedListeners -> call (
                                                             &PatchEditorPulseWidthCenterChanged::onPatchEditorPulseWidthCenterChanged
                                                           , static_cast < unsigned int > ( pulseWidthCenterSlider -> getValue () )
                                                            );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_pulseWidthCenterSlider]
    }
    else if (sliderThatWasMoved == pulseWidthDefaultSlider.get())
    {
        //[UserSliderCode_pulseWidthDefaultSlider] -- add your slider handling code here..
        pulseWidthDefaultLabel -> setText (
                                           pulseWidthDefaultSlider -> getTextFromValue (
                                                                                        pulseWidthDefaultSlider -> getValue ()
                                                                                       ) + "%"
                                         , dontSendNotification
                                          );
        patchEditorPulseWidthDefaultChangedListeners -> call (
                                                              &PatchEditorPulseWidthDefaultChanged::onPatchEditorPulseWidthDefaultChanged
                                                            , static_cast < float > ( pulseWidthDefaultSlider -> getValue () / 100.0 )
                                                             );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserSliderCode_pulseWidthDefaultSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PatchEditor::labelTextChanged (juce::Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == attackLabel.get())
    {
        //[UserLabelCode_attackLabel] -- add your label text handling code here..
        attackSlider -> setValue (
                                  attackLabel -> getText () . getIntValue ()
                                 );
        //[/UserLabelCode_attackLabel]
    }
    else if (labelThatHasChanged == decayLabel.get())
    {
        //[UserLabelCode_decayLabel] -- add your label text handling code here..
        decaySlider -> setValue (
                                 decayLabel -> getText () . getIntValue ()
                                );
        //[/UserLabelCode_decayLabel]
    }
    else if (labelThatHasChanged == sustainLabel.get())
    {
        //[UserLabelCode_sustainLabel] -- add your label text handling code here..
        sustainSlider -> setValue (
                                   sustainLabel -> getText () . getIntValue ()
                                  );
        //[/UserLabelCode_sustainLabel]
    }
    else if (labelThatHasChanged == releaseLabel.get())
    {
        //[UserLabelCode_releaseLabel] -- add your label text handling code here..
        releaseSlider -> setValue (
                                   releaseLabel -> getText () . getIntValue ()
                                  );
        //[/UserLabelCode_releaseLabel]
    }
    else if (labelThatHasChanged == pitchBendRangeLabel.get())
    {
        //[UserLabelCode_pitchBendRangeLabel] -- add your label text handling code here..
        pitchBendRangeSlider -> setValue (
                                          pitchBendRangeLabel -> getText () . getIntValue ()
                                         );
        //[/UserLabelCode_pitchBendRangeLabel]
    }
    else if (labelThatHasChanged == vibratoRangeLabel.get())
    {
        //[UserLabelCode_vibratoRangeLabel] -- add your label text handling code here..
        vibratoRangeSlider -> setValue (
                                        vibratoRangeLabel -> getText () . getIntValue ()
                                       );
        //[/UserLabelCode_vibratoRangeLabel]
    }
    else if (labelThatHasChanged == vibratoSpeedLabel.get())
    {
        //[UserLabelCode_vibratoSpeedLabel] -- add your label text handling code here..
        vibratoSpeedSlider -> setValue (
                                        vibratoSpeedLabel -> getText () . getIntValue ()
                                       );
        //[/UserLabelCode_vibratoSpeedLabel]
    }
    else if (labelThatHasChanged == pulseWidthRangeLabel.get())
    {
        //[UserLabelCode_pulseWidthRangeLabel] -- add your label text handling code here..
        pulseWidthRangeSlider -> setValue (
                                           pulseWidthRangeLabel -> getText () . getIntValue ()
                                          );
        //[/UserLabelCode_pulseWidthRangeLabel]
    }
    else if (labelThatHasChanged == vibratoDelayLabel.get())
    {
        //[UserLabelCode_vibratoDelayLabel] -- add your label text handling code here..
        vibratoDelaySlider -> setValue (
                                        vibratoDelayLabel -> getText () . getIntValue ()
                                       );
        //[/UserLabelCode_vibratoDelayLabel]
    }
    else if (labelThatHasChanged == patchName.get())
    {
        //[UserLabelCode_patchName] -- add your label text handling code here..
        patchEditorNameChangedListeners -> call (
                                                 &PatchEditorNameChanged::onPatchEditorNameChanged
                                               , patchName -> getText ()
                                                );
        //[/UserLabelCode_patchName]
    }
    else if (labelThatHasChanged == vibratoDefaultAmountLabel.get())
    {
        //[UserLabelCode_vibratoDefaultAmountLabel] -- add your label text handling code here..
        vibratoDefaultAmountSlider -> setValue (
                                                vibratoDefaultAmountLabel -> getText () . getIntValue ()
                                               );
        //[/UserLabelCode_vibratoDefaultAmountLabel]
    }
    else if (labelThatHasChanged == vibratoDefaultSpeedLabel.get())
    {
        //[UserLabelCode_vibratoDefaultSpeedLabel] -- add your label text handling code here..
        vibratoDefaultSpeedSlider -> setValue (
                                               vibratoDefaultSpeedLabel -> getText () . getIntValue ()
                                              );
        //[/UserLabelCode_vibratoDefaultSpeedLabel]
    }
    else if (labelThatHasChanged == pulseWidthCenterLabel.get())
    {
        //[UserLabelCode_pulseWidthCenterLabel] -- add your label text handling code here..
        pulseWidthCenterSlider -> setValue (
                                            pulseWidthCenterLabel -> getText () . getIntValue ()
                                           );
        //[/UserLabelCode_pulseWidthCenterLabel]
    }
    else if (labelThatHasChanged == pulseWidthDefaultLabel.get())
    {
        //[UserLabelCode_pulseWidthDefaultLabel] -- add your label text handling code here..
        pulseWidthDefaultSlider -> setValue (
                                             pulseWidthDefaultLabel -> getText () . getIntValue ()
                                            );
        //[/UserLabelCode_pulseWidthDefaultLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void PatchEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == liveModeButton.get())
    {
        //[UserButtonCode_liveModeButton] -- add your button handler code here..
		// TODO: Need to trigger sending a BankProgramChanged event before the switch so that live patches will be refreshed.
		// In order to do this, Bank will need to respond to the PatchEditorLiveModeClicked event.  Not sure how to manage
		// the timing yet, but SIDStep2 will STILL need to respond to the PatchEditorLiveModeClicked event as WELL, because
		// a refresh during a save as must be executed immediately to allow for properly refreshing oldID.
        SharedResourcePointer < ListenerList < BankRefreshLive > > () -> call (
                                                                               &BankRefreshLive::onBankRefreshLive
                                                                              );
        patchEditorLiveModeClickedListeners -> call (
                                                     &PatchEditorLiveModeClicked::onPatchEditorLiveModeClicked
                                                    );
        setVisible (
                    false
                   );
        //[/UserButtonCode_liveModeButton]
    }
    else if (buttonThatWasClicked == menuButton.get())
    {
        //[UserButtonCode_menuButton] -- add your button handler code here..
        bankMenu -> setVisible (
                                !bankMenu -> isVisible ()
                               );
        //[/UserButtonCode_menuButton]
    }
    else if (buttonThatWasClicked == newRowButton.get())
    {
        //[UserButtonCode_newRowButton] -- add your button handler code here..
        patchEditorNewWavetableRowClickedListeners -> call (
                                                            &PatchEditorNewTableRowClicked::onPatchEditorNewTableRowClicked
                                                           );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserButtonCode_newRowButton]
    }
    else if (buttonThatWasClicked == newCommandButton.get())
    {
        //[UserButtonCode_newCommandButton] -- add your button handler code here..
        patchEditorNewWavetableCommandClickedListeners -> call (
                                                                &PatchEditorNewTableCommandClicked::onPatchEditorNewTableCommandClicked
                                                               );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserButtonCode_newCommandButton]
    }
    else if (buttonThatWasClicked == deleteButton.get())
    {
        //[UserButtonCode_deleteButton] -- add your button handler code here..
        patchEditorDeleteWaveatableRowClickedListeners -> call (
                                                                &PatchEditorDeleteTableRowClicked::onPatchEditorDeleteTableRowClicked
                                                               );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserButtonCode_deleteButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    PatchEditor::onBankProgramChanged (
            String                                   old_id
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    //currentProgram = program;

    patchName -> setText (
                          program -> GetName ()
                        , dontSendNotification
                         );

    const auto e  = program -> GetEnvelope ();
    const auto ex = program -> GetExpression ();
    const auto v  = ex -> getVibrato ();
    const auto t  = ex -> getTremolo ();

    attackSlider -> setValue (
                              e -> getAttack ()
                            , dontSendNotification
                             );
    attackLabel -> setText (
                            attackSlider -> getTextFromValue (
                                                              attackSlider -> getValue ()
                                                             )
                          , dontSendNotification
                           );

    decaySlider -> setValue (
                             e -> getDecay ()
                           , dontSendNotification
                            );
    decayLabel -> setText (
                           decaySlider -> getTextFromValue (
                                                            decaySlider -> getValue ()
                                                           )
                         , dontSendNotification
                          );

    sustainSlider -> setValue (
                               e -> getSustain ()
                             , dontSendNotification
                              );
    sustainLabel -> setText (
                             sustainSlider -> getTextFromValue (
                                                                sustainSlider -> getValue ()
                                                               )
                           , dontSendNotification
                            );

    releaseSlider -> setValue (
                               e -> getRelease ()
                             , dontSendNotification
                              );
    releaseLabel -> setText (
                             releaseSlider -> getTextFromValue (
                                                                releaseSlider -> getValue ()
                                                               )
                           , dontSendNotification
                            );

    pitchBendRangeSlider -> setValue (
                                      ex -> getPitchBendRange ()
                                    , dontSendNotification
                                     );
    pitchBendRangeLabel -> setText (
                                    pitchBendRangeSlider -> getTextFromValue (
                                                                              pitchBendRangeSlider -> getValue ()
                                                                             )
                                  , dontSendNotification
                                   );

    pulseWidthRangeSlider -> setValue (
                                       ex -> getPulseWidthRange ()
                                     , dontSendNotification
                                      );
    pulseWidthRangeLabel -> setText (
                                     pulseWidthRangeSlider -> getTextFromValue (
                                                                                pulseWidthRangeSlider -> getValue ()
                                                                               )
                                   , dontSendNotification
                                    );

    pulseWidthCenterSlider -> setValue (
                                        ex -> getPulseWidthCenter ()
                                      , dontSendNotification
                                       );
    pulseWidthCenterLabel -> setText (
                                      pulseWidthCenterSlider -> getTextFromValue (
                                                                                  pulseWidthCenterSlider -> getValue ()
                                                                                 )
                                    , dontSendNotification
                                     );

    pulseWidthDefaultSlider -> setValue (
                                         ex -> getPulseWidthDefault () * 100
                                       , dontSendNotification
                                        );
    pulseWidthDefaultLabel -> setText (
                                       pulseWidthDefaultSlider -> getTextFromValue (
                                                                                    pulseWidthDefaultSlider -> getValue ()
                                                                                   ) + "%"
                                     , dontSendNotification
                                      );

    vibratoRangeSlider -> setValue (
                                    v -> GetVibratoRange ()
                                  , dontSendNotification
                                   );
    vibratoRangeLabel -> setText (
                                  vibratoRangeSlider -> getTextFromValue (
                                                                          vibratoRangeSlider -> getValue ()
                                                                         )
                                , dontSendNotification
                                 );

    vibratoSpeedSlider -> setValue (
                                    v -> GetVibratoSpeed ()
                                  , dontSendNotification
                                   );
    vibratoSpeedLabel -> setText (
                                  vibratoSpeedSlider -> getTextFromValue (
                                                                          vibratoSpeedSlider -> getValue ()
                                                                         )
                                , dontSendNotification
                                 );

    vibratoDefaultAmountSlider -> setValue (
                                            v -> GetDefaultVibratoAmount () * 100
                                          , dontSendNotification
                                           );
    vibratoDefaultAmountLabel -> setText (
                                          vibratoDefaultAmountSlider -> getTextFromValue (
                                                                                          vibratoDefaultAmountSlider -> getValue ()
                                                                                         ) + "%"
                                        , dontSendNotification
                                         );

    vibratoDefaultSpeedSlider -> setValue (
                                           v -> GetDefaultVibratoSpeed () * 100
                                         , dontSendNotification
                                          );
    vibratoDefaultSpeedLabel -> setText (
                                         vibratoDefaultSpeedSlider -> getTextFromValue (
                                                                                        vibratoDefaultSpeedSlider -> getValue ()
                                                                                       ) + "%"
                                       , dontSendNotification
                                        );

    repaint ();

    MessageManager::callAsync (
                               [=] ()
                               {
                                   SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> call (
                                                                                                                   &PatchEditorShowWaveTable::
                                                                                                                   onPatchEditorShowWaveTable
                                                                                                                  );
                               }
                              );
}


void
    PatchEditor::onBankStartSaveAs ()
{
    saveAsDialog -> setVisible (
                                true
                               );
}


void
    PatchEditor::onLivePatchEditorModeClicked ()
{
    setVisible (
                true
               );
}


void
    PatchEditor::onPatchEditorShowNoteTable ()
{
    commandTableViewport -> setViewedComponent (
                                                noteTable
                                              , false
                                               );
}


void
    PatchEditor::onPatchEditorShowPulseTable ()
{
    commandTableViewport -> setViewedComponent (
                                                pulseTable
                                              , false
                                               );
}


void
    PatchEditor::onPatchEditorShowWaveTable ()
{
    commandTableViewport -> setViewedComponent (
                                                wavetable
                                              , false
                                               );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchEditor" componentName=""
                 parentClasses="public Component, public BankProgramChanged, public BankStartSaveAs, public LivePatchEditorModeClicked, public PatchEditorShowNoteTable, public PatchEditorShowPulseTable, public PatchEditorShowWaveTable"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="1024"
                 initialHeight="576">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 1024 576" resource="patchEditorBackdrop_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="208 544 154 26" resource="patchEditorButtonDown_png" opacity="1.0"
           mode="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="2cd41b7a823a6bbf" memberName="attackSlider"
          virtualName="" explicitFocusOrder="0" pos="64 121 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="d0eb97745507bc2c" memberName="decaySlider"
          virtualName="" explicitFocusOrder="0" pos="144 121 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="e5784263e4921b63" memberName="sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="224 121 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7a2342fded630851" memberName="releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="304 121 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="5bc7fdbcca1bb289" memberName="pitchBendRangeSlider"
          virtualName="" explicitFocusOrder="0" pos="64 209 48 48" min="0.0"
          max="8192.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f7cfaf569a269657" memberName="vibratoRangeSlider"
          virtualName="" explicitFocusOrder="0" pos="224 209 48 48" min="0.0"
          max="8192.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7d3bed32c5886626" memberName="vibratoSpeedSlider"
          virtualName="" explicitFocusOrder="0" pos="304 209 48 48" min="0.0"
          max="50.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f3f43917dd8ba620" memberName="pulseWidthRangeSlider"
          virtualName="" explicitFocusOrder="0" pos="64 297 48 48" min="0.0"
          max="4095.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a1ac9c263317de1b" memberName="vibratoDelaySlider"
          virtualName="" explicitFocusOrder="0" pos="224 367 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="77267ab013a4c949" memberName="attackLabel"
         virtualName="" explicitFocusOrder="0" pos="64 97 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="19baaaadba91b1b8" memberName="decayLabel"
         virtualName="" explicitFocusOrder="0" pos="144 97 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="83d52dcf5372e118" memberName="sustainLabel"
         virtualName="" explicitFocusOrder="0" pos="224 97 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8db7a6b3640585ff" memberName="releaseLabel"
         virtualName="" explicitFocusOrder="0" pos="304 97 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1b4eae892bfe6bdb" memberName="pitchBendRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="64 185 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="fb3cfd8322f97df9" memberName="vibratoRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="224 185 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bf0e8fcca263bb70" memberName="vibratoSpeedLabel"
         virtualName="" explicitFocusOrder="0" pos="304 185 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d744a5b8e6b6053d" memberName="pulseWidthRangeLabel"
         virtualName="" explicitFocusOrder="0" pos="64 273 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1925133b210c2aaf" memberName="vibratoDelayLabel"
         virtualName="" explicitFocusOrder="0" pos="224 343 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ea9b0e712c154b55" memberName="patchName"
         virtualName="" explicitFocusOrder="0" pos="24 71 324 16" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="Patch Name" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="new button" id="3cacf57910e35e81" memberName="liveModeButton"
               virtualName="" explicitFocusOrder="0" pos="32 544 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="liveModeButtonNormal_png" opacityNormal="1.0"
               colourNormal="0" resourceOver="liveModeButtonOver_png" opacityOver="1.0"
               colourOver="0" resourceDown="liveModeButtonDown_png" opacityDown="1.0"
               colourDown="0"/>
  <IMAGEBUTTON name="new button" id="786cd39810ba357a" memberName="menuButton"
               virtualName="" explicitFocusOrder="0" pos="353 73 14 12" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="downArrowNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="" opacityOver="1.0" colourOver="0" resourceDown=""
               opacityDown="1.0" colourDown="0"/>
  <VIEWPORT name="new viewport" id="bf26876a7aa88432" memberName="commandTableViewport"
            virtualName="" explicitFocusOrder="0" pos="400 16 608 184" vscroll="1"
            hscroll="0" scrollbarThickness="16" contentType="0" jucerFile="WavetableView.cpp"
            contentClass="" constructorParams=""/>
  <JUCERCOMP name="" id="e69b3e9625ea8249" memberName="wavetableText" virtualName=""
             explicitFocusOrder="0" pos="416 8 110 17" sourceFile="WavetableText.cpp"
             constructorParams=""/>
  <IMAGEBUTTON name="new button" id="5074c2d12ab6cc20" memberName="newRowButton"
               virtualName="" explicitFocusOrder="0" pos="448 192 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="newRowNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="newRowOver_png" opacityOver="1.0" colourOver="0"
               resourceDown="newRowDown_png" opacityDown="1.0" colourDown="0"/>
  <IMAGEBUTTON name="new button" id="4bfd9e29bd87063" memberName="newCommandButton"
               virtualName="" explicitFocusOrder="0" pos="624 192 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="newCommandNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="newCommandOver_png" opacityOver="1.0" colourOver="0"
               resourceDown="newCommandDown_png" opacityDown="1.0" colourDown="0"/>
  <IMAGEBUTTON name="new button" id="4f91e601a6e818cd" memberName="deleteButton"
               virtualName="" explicitFocusOrder="0" pos="800 192 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="deleteNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="deleteOver_png" opacityOver="1.0" colourOver="0"
               resourceDown="deleteDown_png" opacityDown="1.0" colourDown="0"/>
  <JUCERCOMP name="" id="f252ae17811a83c" memberName="waveformView" virtualName=""
             explicitFocusOrder="0" pos="400 248 608 296" sourceFile="WaveformView.cpp"
             constructorParams=""/>
  <LABEL name="new label" id="fcec55ed8a0d807c" memberName="vibratoDefaultAmountLabel"
         virtualName="" explicitFocusOrder="0" pos="224 264 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="38a29eacc682410d" memberName="vibratoDefaultSpeedLabel"
         virtualName="" explicitFocusOrder="0" pos="304 264 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="84c24db139122cf4" memberName="pulseWidthCenterLabel"
         virtualName="" explicitFocusOrder="0" pos="64 353 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="7dec2956c5fe9349" memberName="pulseWidthDefaultLabel"
         virtualName="" explicitFocusOrder="0" pos="64 433 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="4d555b08be48dcee" memberName="vibratoDefaultAmountSlider"
          virtualName="" explicitFocusOrder="0" pos="224 288 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="254b7b10e3d6ca53" memberName="vibratoDefaultSpeedSlider"
          virtualName="" explicitFocusOrder="0" pos="304 288 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="8d776adc94f70db7" memberName="pulseWidthCenterSlider"
          virtualName="" explicitFocusOrder="0" pos="64 376 48 48" min="0.0"
          max="4095.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="deb17363d6a80ad" memberName="pulseWidthDefaultSlider"
          virtualName="" explicitFocusOrder="0" pos="64 456 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <JUCERCOMP name="" id="cfb51def3185550f" memberName="bankMenu" virtualName=""
             explicitFocusOrder="0" pos="24 80 324 448" sourceFile="BankMenu.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="775992dc0c12017" memberName="saveAsDialog" virtualName=""
             explicitFocusOrder="0" pos="274 239 476 98" sourceFile="SavePatchAsDialog.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="8e7b5ba0d4d1d31c" memberName="noteTableText" virtualName=""
             explicitFocusOrder="0" pos="632 8 131 17" sourceFile="NoteTableText.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="4e2e9d5f1d09cab6" memberName="pulseTableText" virtualName=""
             explicitFocusOrder="0" pos="840 8 141 17" sourceFile="PulseTableText.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: patchEditorBackdrop_png, 30947, "../../UI/Patch Editor Backdrop.png"
static const unsigned char resource_PatchEditor_patchEditorBackdrop_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,4,0,0,0,2,64,8,6,0,0,0,19,149,20,213,0,0,0,9,112,72,89,115,0,0,14,195,0,
0,14,195,1,199,111,168,100,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,99,116,69,88,116,67,111,112,121,114,105,
103,104,116,0,67,67,32,65,116,116,114,105,98,117,116,105,111,110,45,78,111,110,67,111,109,109,101,114,99,105,97,108,45,83,104,97,114,101,65,108,105,107,101,32,104,116,116,112,58,47,47,99,114,101,97,116,
105,118,101,99,111,109,109,111,110,115,46,111,114,103,47,108,105,99,101,110,115,101,115,47,98,121,45,110,99,45,115,97,47,52,46,48,47,67,211,34,92,0,0,32,0,73,68,65,84,120,156,236,221,119,124,99,231,125,
231,251,47,122,33,216,59,57,67,114,134,163,233,163,105,178,52,146,101,89,142,108,89,142,101,91,78,156,186,41,118,98,103,211,110,34,239,102,55,251,202,174,75,156,221,236,221,100,115,227,196,251,202,38,
27,251,102,211,179,185,174,145,236,40,177,20,171,140,213,44,77,215,136,211,72,206,12,123,39,136,94,239,31,16,65,130,4,73,128,0,8,128,248,188,95,47,39,115,14,206,121,206,239,60,4,245,226,243,59,207,243,
59,134,199,62,127,46,46,0,0,0,0,0,176,173,25,139,29,0,0,0,0,0,0,40,60,18,0,0,0,0,0,0,84,0,18,0,0,0,0,0,0,84,0,115,166,7,46,140,245,235,242,55,255,80,147,87,191,167,72,208,155,215,32,44,118,151,90,15,222,
175,131,143,254,138,156,13,29,91,114,189,234,182,221,114,143,222,216,146,123,201,212,86,247,49,176,145,74,252,61,4,0,0,0,182,43,67,38,69,0,221,163,215,245,252,31,252,180,34,129,252,254,145,190,146,173,
186,81,239,252,228,95,41,18,244,110,201,245,10,105,241,94,156,13,237,25,29,191,213,125,156,105,92,168,92,91,245,157,44,36,190,239,0,0,0,192,146,140,150,0,188,241,15,191,191,37,131,128,224,194,180,222,
252,199,63,218,178,235,21,210,226,189,100,106,171,251,24,216,72,37,254,30,2,0,0,0,219,217,134,75,0,226,241,152,38,175,190,178,21,177,72,146,38,250,94,84,216,55,191,101,215,43,164,201,43,47,101,116,220,
86,247,113,166,113,161,114,109,245,119,178,144,248,190,3,0,0,0,9,27,38,0,98,225,160,98,209,72,114,219,225,48,105,164,255,135,242,22,128,207,23,81,103,239,151,147,219,193,133,233,148,207,11,121,189,66,
223,75,56,195,167,167,91,221,199,153,198,133,202,181,149,223,73,190,239,0,0,0,192,214,72,155,0,88,175,240,151,193,96,144,193,144,191,0,140,198,245,27,43,228,245,10,125,47,209,144,95,95,127,252,88,214,
69,14,139,25,87,58,155,41,4,71,17,182,237,165,156,127,15,1,0,0,0,36,172,74,0,108,135,194,95,165,38,28,240,104,232,204,83,154,188,246,189,146,42,114,184,50,174,116,133,210,54,251,125,200,164,109,0,0,0,
0,192,214,89,85,4,112,59,20,254,42,85,165,90,228,112,189,66,105,185,198,74,17,54,0,0,0,0,40,13,41,51,0,182,83,225,175,82,85,170,69,14,211,21,74,203,215,247,129,34,108,0,0,0,0,80,124,41,9,128,205,22,254,
242,251,163,41,69,183,214,226,112,152,52,124,227,35,171,246,205,142,254,104,202,190,229,69,188,124,190,136,26,58,254,207,134,237,100,26,87,60,30,223,240,188,76,218,217,204,189,72,155,47,114,88,200,62,
150,210,23,74,219,236,247,129,34,108,229,207,104,177,201,104,50,39,127,254,133,252,61,44,244,239,184,197,94,181,97,59,0,0,0,64,37,88,247,45,0,217,20,231,138,197,54,30,88,175,53,246,94,121,141,149,69,188,
86,182,157,205,24,62,147,184,54,211,206,102,239,101,245,241,165,209,199,139,133,1,215,147,105,172,217,180,157,109,129,196,92,109,245,245,50,141,161,212,24,12,70,53,221,113,183,38,250,94,76,238,43,228,
239,97,33,219,110,222,119,42,243,198,0,0,0,128,109,108,195,215,0,2,133,180,213,5,18,75,161,32,99,185,20,72,60,252,193,199,245,252,192,249,45,73,138,20,138,205,85,175,3,239,251,197,98,135,1,0,0,0,148,4,
18,0,40,9,139,197,2,67,158,153,45,25,140,111,245,245,214,139,225,228,191,250,173,162,92,127,35,53,29,123,245,192,227,127,174,203,79,252,129,38,175,127,79,209,80,32,175,237,155,109,85,114,181,116,107,97,
188,191,32,109,183,236,191,79,135,62,248,171,37,59,203,98,59,242,141,123,52,121,102,76,115,253,51,10,206,5,21,11,71,139,29,18,0,0,64,73,184,231,51,239,148,36,189,242,155,207,173,123,156,209,98,146,173,
206,174,186,222,122,53,159,104,147,179,197,149,215,56,10,146,0,48,89,29,250,192,239,188,164,104,200,175,39,254,253,189,133,184,68,197,219,142,125,188,213,5,18,75,161,32,99,169,23,72,172,105,223,163,83,
63,247,5,73,202,219,119,109,241,187,187,92,33,219,70,225,197,35,49,13,60,117,93,147,175,143,110,170,206,10,0,0,0,18,98,225,168,252,147,94,249,39,189,26,123,101,88,45,39,59,212,243,72,175,12,230,85,47,
240,219,148,130,206,0,200,164,144,88,58,43,255,128,52,219,171,74,234,181,121,82,230,133,203,50,41,192,151,139,124,244,113,166,197,253,50,149,238,158,211,201,87,129,196,76,109,245,245,50,137,129,2,137,
40,119,241,72,76,111,254,213,121,185,7,75,239,237,38,0,0,0,229,44,30,143,107,252,181,97,249,167,188,58,240,19,119,230,37,9,80,144,4,192,122,69,223,54,83,148,175,101,239,41,141,92,120,38,215,176,242,174,
80,133,1,51,145,207,62,206,166,16,97,230,109,110,124,76,62,11,36,102,98,171,175,151,73,12,139,63,199,114,40,12,8,164,51,240,212,117,6,255,0,0,0,5,228,30,156,211,224,63,93,215,174,247,239,205,185,173,252,
204,35,40,32,155,171,94,7,190,159,34,94,216,222,22,11,3,62,247,251,63,41,223,204,104,177,195,1,50,226,27,247,104,242,117,190,175,0,0,0,133,54,241,250,136,124,19,185,207,30,46,217,4,128,217,86,165,142,
163,239,209,3,159,252,203,210,123,34,106,48,200,100,181,23,59,10,108,67,139,133,1,129,114,48,113,134,53,255,0,0,0,91,33,30,75,252,237,149,171,146,123,11,128,189,166,73,143,124,238,233,148,125,209,144,
191,72,209,164,103,178,216,203,186,0,95,41,214,84,192,146,82,47,12,8,44,154,239,159,45,118,8,0,0,0,21,99,254,70,238,127,123,165,36,0,50,41,40,151,105,161,187,76,85,122,81,180,98,244,113,60,26,217,84,225,
192,116,113,165,227,247,71,51,42,114,184,153,66,132,153,182,93,200,130,140,133,142,161,210,126,7,80,190,66,243,193,98,135,0,0,0,80,49,242,241,183,87,74,2,192,96,48,170,233,142,187,53,209,247,98,114,223,
102,11,221,101,42,147,162,104,54,87,253,230,26,47,19,91,222,199,225,213,95,156,76,10,7,102,51,211,183,144,133,8,115,137,53,95,5,25,75,33,6,160,216,162,161,104,177,67,0,0,0,168,24,209,80,36,231,54,86,213,
0,56,252,193,199,101,182,85,229,220,112,174,40,138,6,0,0,0,0,64,254,172,74,0,212,116,236,213,3,143,255,185,218,14,190,163,36,10,221,81,20,13,0,0,0,0,128,220,165,45,2,88,211,190,71,167,126,238,11,146,84,
18,133,238,38,40,138,86,112,107,21,95,204,199,207,222,100,117,232,3,191,147,250,51,44,133,239,85,190,44,222,223,118,186,39,0,0,0,0,219,207,134,111,1,200,164,48,96,166,54,91,20,109,187,87,172,55,89,108,
138,199,162,69,237,227,114,41,60,151,75,49,68,0,0,0,0,168,100,105,19,0,11,99,253,186,252,205,63,212,228,213,239,41,18,92,61,48,204,182,192,219,162,237,82,20,45,26,14,232,201,95,127,123,218,190,217,92,
123,155,43,202,151,206,118,233,227,245,108,182,24,98,161,44,22,174,4,0,0,0,128,82,182,42,1,224,30,189,174,231,255,224,167,183,253,83,247,156,196,227,121,27,252,3,0,0,0,0,176,21,86,21,1,124,227,31,126,
159,193,63,0,0,0,0,0,219,76,74,2,32,30,143,105,242,234,43,57,55,106,175,105,210,99,159,63,183,170,240,27,242,135,62,6,0,0,0,0,100,35,101,9,64,44,28,76,22,162,147,18,5,215,70,250,127,104,195,70,202,181,
160,92,46,50,237,27,191,63,154,210,55,146,20,95,182,80,159,62,206,78,186,254,204,69,124,173,162,9,235,200,165,16,225,70,223,7,73,178,216,171,54,213,54,0,0,0,0,172,103,221,183,0,24,12,134,140,10,174,173,
44,40,87,9,69,209,50,237,27,105,253,130,126,149,208,199,249,142,117,179,5,18,243,41,151,66,132,27,197,223,188,239,212,230,27,207,179,141,10,130,110,198,226,247,193,98,119,169,186,109,183,220,163,55,10,
210,118,235,193,251,117,240,209,95,145,179,161,35,47,109,3,0,0,0,229,110,195,215,0,2,216,58,54,87,189,14,188,239,23,139,29,134,164,194,23,4,13,7,60,154,25,188,80,176,182,135,206,60,165,201,107,223,211,
59,63,249,87,114,54,180,23,228,58,0,0,0,64,57,89,85,4,16,192,214,51,219,170,212,113,244,61,122,224,147,127,89,50,79,172,183,67,65,208,224,194,180,222,252,199,63,42,118,24,0,0,0,64,73,96,6,0,42,150,217,
94,85,244,1,174,201,234,40,201,66,142,249,42,8,90,10,38,175,148,94,255,2,0,0,0,197,144,146,0,48,90,108,50,154,204,201,66,128,62,95,68,13,29,255,39,229,4,135,195,164,225,27,31,89,181,175,80,69,209,50,45,
146,151,78,186,184,86,22,211,219,108,59,233,100,82,224,205,230,106,80,216,239,46,169,62,150,210,23,158,43,244,247,97,249,207,98,43,250,97,229,207,126,179,131,255,92,10,17,150,75,193,191,205,22,4,77,103,
163,223,195,66,255,142,87,106,193,76,0,0,0,96,165,148,4,128,193,96,84,211,29,119,107,162,239,197,228,190,149,5,203,214,42,154,94,168,162,104,217,20,219,75,127,126,234,246,202,98,122,155,109,103,45,27,
21,120,107,57,112,159,130,11,51,37,213,199,82,250,194,115,133,254,62,172,252,89,20,186,31,54,251,179,79,39,95,133,8,75,169,224,223,122,10,249,123,88,42,191,227,0,0,0,192,118,183,170,6,192,225,15,62,46,
179,173,52,159,74,150,187,197,2,111,165,214,199,235,21,158,43,181,88,183,147,82,42,248,7,0,0,0,96,251,91,149,0,168,233,216,171,7,30,255,115,181,29,124,135,76,86,123,49,98,218,118,86,22,120,43,149,62,206,
164,240,92,169,196,186,157,148,98,193,63,0,0,0,0,219,95,218,34,128,53,237,123,116,234,231,190,32,41,241,94,237,39,254,253,189,91,26,212,118,177,94,129,183,98,246,113,182,133,231,54,19,235,203,175,76,234,
211,191,117,94,87,175,185,87,125,102,48,72,199,143,53,232,51,191,113,52,243,160,75,152,201,234,208,251,127,251,57,189,241,228,31,106,248,236,63,43,26,14,172,58,198,98,119,169,231,190,31,212,222,135,126,
38,183,181,28,121,16,139,132,54,140,181,235,238,15,166,236,243,251,35,234,217,247,213,85,199,214,212,88,244,209,159,236,213,39,255,175,131,197,190,45,0,0,0,0,27,216,240,45,0,153,20,130,203,197,102,138,
228,229,235,122,133,190,151,76,11,188,109,117,31,231,82,120,46,211,88,55,90,35,255,47,207,142,233,95,158,29,75,217,183,149,63,123,41,191,111,1,184,240,213,255,166,193,23,191,178,230,231,97,159,91,151,
159,252,130,12,6,163,238,120,232,99,121,185,230,102,101,18,107,223,83,127,44,131,209,168,120,44,38,41,81,143,97,110,62,180,234,216,185,249,144,62,247,219,23,244,91,255,245,98,86,9,128,82,252,61,4,0,0,
0,182,187,13,19,0,153,20,130,203,167,76,138,228,229,83,33,219,206,180,192,219,86,247,113,46,133,231,10,25,235,86,255,236,91,246,158,210,200,133,103,242,210,214,173,87,159,200,232,184,27,207,255,173,36,
131,164,141,239,203,96,48,170,97,247,113,53,244,220,153,216,17,143,107,226,202,203,154,31,190,146,213,249,206,134,14,141,94,252,142,34,1,79,86,177,26,140,102,197,99,171,7,253,233,196,227,241,53,139,54,
102,162,84,191,239,0,0,0,192,118,178,97,2,64,74,20,130,123,126,224,188,34,193,194,190,78,107,177,40,90,36,224,217,146,235,21,82,182,5,222,182,186,143,115,145,77,172,159,251,244,49,125,226,99,119,164,236,
251,212,111,158,211,23,255,247,181,180,113,109,213,207,222,230,170,215,129,239,255,197,60,37,0,226,138,69,18,3,229,218,90,171,250,206,125,40,229,211,185,185,144,14,28,255,134,36,41,48,63,161,55,158,248,
124,86,173,239,126,224,199,116,228,177,127,167,87,254,223,127,163,177,75,207,102,29,221,242,25,27,203,109,20,235,226,61,101,114,108,169,162,208,34,0,0,0,176,100,85,17,192,116,10,93,8,110,171,139,228,153,
109,85,170,219,121,112,75,238,37,83,91,221,199,185,200,38,86,171,213,40,135,195,148,242,63,179,101,105,174,184,209,108,93,245,179,223,247,240,39,114,138,111,61,133,46,192,103,144,86,221,175,211,105,202,
169,205,254,231,255,86,151,190,241,123,155,26,252,75,74,59,248,151,178,139,181,16,247,85,72,20,90,4,0,0,0,86,203,104,6,128,148,90,8,110,43,108,245,245,74,65,57,221,243,122,177,94,252,218,239,234,198,115,
127,157,81,59,6,163,81,147,215,94,209,179,191,247,227,201,125,177,112,48,249,239,7,238,111,213,177,59,235,83,206,121,238,133,113,157,191,56,155,178,111,163,227,142,126,228,55,180,235,254,31,78,249,60,
26,242,103,20,227,162,197,194,134,87,86,20,54,140,46,139,55,19,233,98,77,103,121,252,253,47,252,109,78,231,219,172,70,253,235,143,239,77,249,220,225,88,61,128,183,217,76,250,149,95,220,159,178,47,24,140,
233,255,124,121,112,253,139,25,12,178,56,170,83,119,201,160,144,111,126,205,235,7,131,49,253,201,151,174,166,94,127,131,227,108,174,122,189,239,63,127,103,253,88,0,0,0,0,164,149,113,2,96,209,240,11,55,
117,251,153,129,85,251,171,119,214,232,208,207,158,200,75,80,216,216,181,47,191,161,233,75,147,171,246,183,190,173,67,187,222,191,52,128,122,243,175,206,107,254,250,236,170,227,58,223,209,173,157,15,237,
74,110,95,250,211,51,242,12,175,174,216,223,245,238,94,117,220,191,51,101,223,220,181,25,245,253,245,5,73,146,163,217,169,163,191,116,247,166,239,35,26,10,40,26,90,93,137,126,209,247,63,210,169,159,95,
49,32,252,15,159,58,179,42,1,176,209,113,177,104,120,85,219,217,22,95,92,115,157,122,150,139,223,211,197,154,206,242,248,23,139,241,109,246,124,135,195,172,207,125,250,216,134,231,216,237,166,85,199,205,
207,135,54,78,0,196,227,10,251,86,127,127,22,165,187,254,252,124,104,85,2,96,163,227,98,177,232,6,119,0,0,0,0,96,45,25,39,0,226,177,184,38,207,140,201,51,188,32,73,106,58,218,42,163,37,177,130,96,246,
205,105,133,189,97,77,188,54,170,154,222,58,217,235,29,133,137,54,143,102,251,166,20,246,36,6,133,217,198,188,112,107,78,254,137,196,211,99,103,187,75,174,206,234,13,206,144,60,67,110,249,198,18,235,218,
29,45,78,85,119,213,110,34,106,41,236,9,105,182,111,90,129,153,128,140,22,163,154,142,182,38,63,155,124,125,76,254,73,175,38,94,27,149,171,171,90,158,91,11,10,205,7,101,114,152,213,120,168,57,113,80,84,
154,56,59,42,239,168,39,229,184,176,55,36,139,203,170,250,253,141,146,164,88,40,166,169,11,227,242,12,187,53,241,218,168,154,79,182,201,176,205,222,243,182,213,197,23,1,0,0,0,160,152,50,79,0,68,227,234,
127,242,74,114,187,251,225,94,89,170,172,146,164,75,163,137,167,199,253,79,94,209,29,31,57,84,22,9,128,225,23,110,37,159,120,103,27,243,228,133,113,77,188,54,42,41,241,36,61,147,4,192,76,223,164,70,78,
223,150,148,120,74,191,217,4,64,96,54,144,252,57,88,171,173,218,253,232,190,165,184,206,142,203,61,56,47,247,224,188,122,30,217,163,193,167,174,75,74,60,165,95,60,46,22,142,105,226,236,168,230,174,79,
107,238,250,116,202,113,213,59,107,146,199,133,22,66,154,186,48,174,153,55,39,53,243,230,164,154,143,183,74,166,252,36,0,62,247,233,99,250,204,111,28,77,251,217,86,23,150,219,76,241,197,116,133,13,55,
178,188,136,158,229,173,196,217,252,124,72,7,142,255,195,138,227,44,122,243,236,135,146,215,249,204,111,28,93,213,39,159,254,205,115,250,220,111,95,88,227,58,107,159,223,177,251,203,107,30,187,40,93,76,
241,120,92,54,235,234,229,2,181,181,86,141,14,252,208,154,247,156,174,216,35,0,0,0,128,226,201,122,9,64,58,251,126,244,144,162,145,196,20,101,171,43,145,20,24,57,125,75,19,175,143,174,58,182,166,167,78,
187,63,180,79,129,25,191,250,254,50,253,32,70,146,234,246,53,170,231,145,61,242,142,46,232,218,223,95,150,36,89,170,44,58,244,241,165,101,6,231,254,199,171,82,52,241,196,182,243,129,110,13,63,127,115,
205,246,90,239,234,80,251,219,151,166,178,167,139,57,93,187,43,217,26,237,178,213,101,86,164,111,240,91,215,52,119,109,70,146,20,246,47,77,65,159,186,48,158,156,150,191,216,31,153,170,106,115,233,216,
175,222,35,41,241,4,59,27,183,159,25,208,212,165,241,148,125,117,251,26,117,108,95,226,169,191,209,188,113,81,183,55,255,226,188,252,19,185,85,232,183,90,140,146,37,253,103,161,208,214,22,150,91,44,104,
120,249,137,63,208,228,245,239,173,187,28,97,209,98,97,195,108,44,22,209,91,201,231,75,45,208,103,181,24,83,255,109,89,221,39,161,112,76,161,112,76,233,172,119,254,122,215,90,47,38,73,105,19,0,82,250,
123,90,180,188,216,35,0,0,0,128,226,203,75,2,192,82,109,75,142,231,226,145,152,230,251,103,229,29,91,80,96,214,175,218,93,245,137,209,143,164,133,219,243,242,77,120,53,223,63,43,163,217,168,192,108,98,
26,189,193,40,213,244,44,21,53,115,223,156,151,127,60,113,92,60,22,79,30,23,139,164,174,255,13,206,6,20,143,38,6,66,209,96,36,121,156,209,98,82,245,206,154,68,60,241,184,220,3,115,242,142,122,52,223,63,
43,71,163,83,254,105,95,74,59,38,139,73,70,139,73,254,105,191,66,243,1,5,103,252,178,184,172,114,52,57,37,73,97,95,88,190,177,196,59,212,13,102,67,74,2,32,56,27,208,124,127,234,122,116,87,103,141,76,54,
147,44,46,171,108,245,246,183,226,136,41,26,72,12,172,76,54,115,114,191,101,69,242,97,35,70,139,113,213,108,133,197,184,21,143,203,90,99,147,163,201,41,163,101,105,96,22,11,71,53,223,63,171,88,52,38,91,
157,93,193,217,165,65,174,201,106,74,206,228,88,228,155,240,200,63,145,232,35,71,163,67,214,90,187,244,214,244,127,107,141,77,97,95,88,33,79,102,239,135,79,231,249,211,227,58,127,97,69,17,191,119,180,
234,232,145,250,148,34,116,207,189,48,158,238,244,188,91,171,160,97,36,232,211,147,191,126,159,164,212,226,116,199,142,36,190,171,193,80,76,255,235,139,169,107,216,173,54,163,254,245,207,110,188,62,95,
74,95,112,47,147,196,194,122,69,0,179,77,76,228,98,163,251,127,231,253,173,178,90,140,153,21,17,4,0,0,0,80,112,121,73,0,44,23,246,71,244,230,95,156,79,110,239,255,137,35,50,152,18,79,26,207,125,225,85,
121,134,221,122,243,47,206,171,231,145,61,201,99,12,38,163,14,252,212,210,148,240,215,127,247,69,205,15,204,106,126,96,54,229,184,76,217,234,108,201,246,98,225,152,94,253,47,207,107,234,210,184,166,46,
141,167,76,121,95,116,199,71,14,169,241,112,179,38,207,142,36,167,233,215,239,107,76,22,211,91,94,244,110,165,197,118,151,59,252,137,19,114,117,214,168,243,129,110,117,62,208,45,73,186,245,244,141,180,
109,231,67,186,184,23,103,30,72,82,112,46,168,55,255,226,188,118,63,186,79,59,223,181,75,175,254,151,231,215,109,111,248,249,155,201,2,131,205,199,59,82,138,0,246,62,182,127,221,254,200,196,183,254,105,
88,127,252,167,169,3,199,255,251,63,159,208,209,35,245,41,69,232,254,195,167,206,108,250,26,249,16,95,246,250,188,116,197,233,2,254,136,62,245,185,115,41,251,234,106,173,25,39,0,210,21,220,203,68,166,
69,0,11,109,163,251,127,223,123,59,245,190,247,118,102,86,68,16,0,0,0,64,193,229,61,1,80,106,86,38,23,28,141,78,57,90,170,52,240,173,107,10,76,249,214,57,51,51,77,135,91,213,124,162,77,146,228,238,159,
211,240,233,155,26,252,214,117,85,239,168,81,247,251,178,79,94,100,106,248,249,155,114,15,206,73,146,106,118,213,37,239,209,90,99,91,117,172,173,206,166,221,31,220,47,103,179,115,205,246,6,191,121,45,
57,51,162,126,127,147,90,78,36,222,157,110,111,88,251,28,0,0,0,0,64,249,200,75,2,32,188,16,76,174,167,143,167,95,154,188,190,184,146,211,247,165,196,116,249,197,169,233,38,155,89,246,122,135,66,158,144,
226,177,212,227,12,138,107,163,154,237,6,163,84,187,59,117,186,180,181,214,38,179,109,245,173,155,237,22,217,235,29,10,204,249,21,13,70,147,215,10,121,214,126,207,187,173,222,158,108,63,236,77,172,243,
247,12,187,149,229,242,252,140,197,194,49,133,60,65,45,220,158,151,123,112,86,182,90,135,44,7,173,171,238,113,57,163,197,148,252,60,182,98,237,120,52,20,85,52,228,215,194,237,57,249,167,252,178,86,219,
100,175,119,172,219,222,86,90,44,120,151,174,184,221,114,150,53,214,179,151,178,116,5,247,210,137,199,227,155,42,34,88,74,230,230,67,201,34,132,159,251,244,81,125,252,163,119,108,88,68,16,0,0,0,64,126,
229,37,1,112,229,239,222,72,86,212,223,204,148,253,88,36,166,115,127,240,74,202,190,166,35,45,218,243,131,7,37,73,205,199,219,146,239,189,95,121,92,62,117,220,223,165,142,251,187,244,202,111,61,175,169,
11,227,154,186,176,53,107,208,179,225,29,243,232,141,47,37,166,198,91,171,173,201,130,128,155,53,119,101,58,229,45,0,135,126,246,196,6,103,108,173,197,130,119,233,138,219,109,7,233,10,238,165,99,179,154,
178,46,34,88,106,22,99,141,68,150,210,118,91,89,179,0,0,0,0,168,116,25,39,0,12,38,131,118,63,186,79,179,215,167,53,219,55,165,155,255,124,67,198,183,6,27,193,185,128,236,13,14,117,220,215,37,87,87,181,
118,63,186,79,211,125,147,154,191,62,163,129,111,94,151,140,137,63,248,35,158,144,156,45,85,106,187,123,71,74,33,61,131,201,168,93,239,75,125,173,154,173,49,181,210,126,203,137,14,213,246,52,72,82,178,
109,73,170,233,169,85,211,225,54,25,237,153,13,124,60,195,110,77,156,29,85,112,110,169,16,222,196,153,17,121,199,220,234,122,119,175,36,105,215,251,247,72,177,165,10,230,190,73,143,198,94,25,206,168,253,
181,52,236,111,150,189,206,169,129,111,93,149,123,112,46,249,42,63,103,179,75,109,247,116,110,170,205,72,32,146,242,106,198,229,90,79,116,104,247,163,251,52,250,202,109,133,60,161,165,227,222,170,163,
88,183,167,81,13,251,155,164,101,227,175,229,175,24,92,169,241,96,139,166,47,79,72,146,66,115,75,5,0,151,183,109,52,26,213,243,253,27,191,30,111,177,56,220,114,233,10,235,157,91,86,40,48,16,140,234,11,
127,212,151,114,78,186,130,123,107,157,111,48,101,159,235,50,24,151,58,103,249,245,211,21,44,92,180,214,128,54,211,243,151,123,238,133,113,157,191,56,155,151,235,47,221,147,81,241,88,44,171,54,243,93,
196,239,185,23,198,21,14,165,206,68,89,188,254,114,139,197,34,125,254,165,226,159,217,190,249,2,0,0,0,192,146,204,19,0,70,131,90,238,106,87,44,28,149,251,230,156,102,175,78,167,124,238,108,112,169,229,
174,246,196,191,91,92,10,121,130,242,12,187,53,253,230,196,210,65,70,201,209,226,84,203,93,237,242,79,250,150,181,173,228,185,43,197,99,113,197,130,81,185,218,171,229,106,175,150,36,249,39,189,154,191,
62,35,147,195,172,170,206,26,181,220,213,174,185,27,179,50,57,18,183,147,110,122,255,162,208,124,64,211,111,36,10,220,45,30,239,25,93,80,200,29,212,142,7,119,41,30,142,169,241,64,75,202,57,166,27,102,
141,189,50,44,147,213,36,179,205,44,163,217,148,60,215,104,94,26,144,24,77,75,109,26,87,196,224,218,81,35,215,142,26,221,126,118,64,33,79,40,25,67,180,55,146,85,2,192,96,92,186,134,164,100,59,43,117,220,
215,245,86,191,204,164,92,111,241,190,171,119,38,250,109,230,242,68,178,189,88,52,182,102,123,85,109,213,171,218,88,25,131,201,156,89,2,96,177,56,92,58,233,10,203,73,82,32,16,205,168,224,222,90,231,215,
180,101,63,51,197,108,175,146,179,161,93,190,153,209,148,235,167,43,88,184,145,205,156,255,31,62,117,102,41,1,144,227,245,151,238,201,37,139,189,42,171,123,202,119,17,191,127,252,167,97,253,227,63,165,
38,212,22,175,191,92,186,98,145,53,237,133,171,171,1,0,0,0,108,119,89,63,22,109,187,119,135,218,238,221,177,225,113,59,30,236,209,142,7,123,54,19,83,10,207,240,66,114,202,251,74,119,253,218,125,201,55,
12,212,245,214,235,109,191,126,255,134,237,53,28,108,81,195,193,150,180,159,45,175,212,159,206,222,31,62,172,218,61,137,65,74,186,165,14,235,181,189,232,228,175,221,183,97,140,235,113,117,214,100,116,
159,139,246,254,200,161,117,63,207,36,230,69,173,119,117,100,124,221,82,178,227,196,251,212,180,231,228,166,206,189,243,7,126,93,175,254,217,175,41,22,205,108,170,126,57,40,215,123,50,219,171,116,232,
131,159,44,118,24,0,0,0,64,217,50,60,246,249,115,27,213,209,43,136,176,55,164,209,151,134,18,65,24,13,218,249,125,187,210,30,23,156,11,106,252,181,244,211,239,119,126,223,238,188,22,219,155,187,62,45,
247,224,252,154,159,55,31,111,151,163,209,145,191,11,110,83,125,255,248,63,213,247,79,127,34,41,177,38,221,156,197,186,244,120,60,46,255,178,41,223,159,251,244,49,125,226,99,107,207,42,88,156,242,254,
233,207,157,211,23,255,247,245,148,243,109,174,6,29,251,145,79,171,237,240,3,57,77,29,95,24,31,208,27,255,240,251,26,123,35,241,250,196,92,239,41,211,243,67,161,104,114,189,188,189,182,89,129,249,201,
156,175,239,108,236,212,195,159,250,102,86,247,180,120,190,211,105,78,187,127,165,116,199,89,173,166,100,17,195,116,44,22,163,204,102,67,74,97,195,229,247,223,117,207,135,116,224,125,191,32,71,93,91,134,
119,141,173,240,242,103,159,45,118,8,0,0,0,101,225,158,207,188,83,146,244,202,111,62,151,83,59,167,62,251,96,78,231,23,237,53,128,150,42,171,186,222,189,123,195,227,108,117,182,140,142,203,135,186,61,
141,170,219,211,184,37,215,218,206,58,143,63,172,171,79,127,73,177,104,36,89,196,111,179,172,86,99,70,133,226,66,225,216,170,130,120,61,247,254,128,218,143,60,184,233,107,47,170,110,221,165,67,31,248,
85,77,244,189,152,151,123,202,246,124,139,163,90,119,253,228,127,213,139,255,243,231,115,190,254,206,19,239,147,180,185,123,90,175,96,161,181,170,78,33,239,220,154,199,173,85,196,48,147,235,88,28,213,
58,244,129,199,101,115,149,198,155,41,0,0,0,128,114,85,180,4,0,182,175,234,182,94,221,253,177,255,174,139,95,255,61,121,167,214,94,82,145,137,116,5,227,210,89,94,240,207,108,115,170,251,212,135,181,239,
145,159,207,233,218,203,229,122,79,102,155,83,237,119,126,159,102,6,206,103,117,126,109,231,62,29,253,161,255,168,134,158,59,115,190,254,202,62,201,199,207,41,217,238,195,63,167,139,95,253,111,26,185,
240,140,162,225,213,175,205,76,87,196,49,29,223,138,25,5,139,247,207,224,31,0,0,0,200,93,209,150,0,160,50,68,130,62,197,179,88,107,110,48,153,52,114,238,105,157,249,219,207,108,250,154,247,255,242,151,
54,189,230,63,19,217,222,147,148,120,138,45,131,33,171,243,77,54,167,140,105,222,94,176,153,62,53,219,170,214,61,102,189,54,13,38,147,76,22,187,34,1,239,134,237,198,99,209,148,227,190,243,223,127,68,190,
153,209,140,99,93,174,105,207,93,186,255,151,191,184,169,115,177,53,88,2,0,0,0,144,153,138,95,2,128,202,96,182,57,179,62,103,199,93,223,175,155,175,124,67,211,253,233,139,63,174,123,110,14,5,255,50,181,
153,123,42,165,243,55,219,166,197,89,179,225,49,6,163,41,229,184,205,22,28,164,224,31,0,0,0,144,127,36,0,80,114,140,38,139,222,254,75,127,162,225,115,223,150,123,228,90,70,231,24,12,70,213,119,31,81,219,
225,7,10,28,29,178,209,118,248,65,189,235,223,255,127,26,57,255,180,34,65,223,198,39,72,178,58,107,181,227,228,35,20,252,3,0,0,0,242,140,4,0,74,146,209,100,209,206,147,223,47,21,246,97,62,182,64,117,235,
46,237,123,248,19,197,14,3,0,0,0,168,120,121,124,137,30,0,0,0,0,0,40,85,36,0,0,0,0,0,0,168,0,36,0,0,0,0,0,0,168,0,5,173,1,224,159,242,233,246,211,55,52,223,63,167,104,40,186,241,9,0,176,157,25,164,83,
159,121,80,82,110,175,208,51,89,77,170,237,109,80,207,35,123,100,173,181,229,39,54,0,0,0,108,123,5,75,0,132,220,1,93,250,210,25,69,253,217,189,254,11,0,176,190,104,40,170,153,55,39,53,63,48,171,195,31,
63,33,71,83,254,95,13,9,0,0,128,237,39,111,75,0,124,163,110,157,253,131,151,147,219,131,79,245,51,248,7,128,2,138,6,34,186,245,116,127,114,251,250,215,222,84,120,33,88,196,136,0,0,0,80,202,114,158,1,16,
11,70,116,237,235,87,52,219,55,37,197,227,201,253,243,253,51,185,54,13,0,216,128,123,96,54,249,239,169,243,227,154,185,60,169,142,183,119,169,227,254,46,25,205,148,121,1,0,0,192,146,156,18,0,183,255,165,
95,163,223,29,82,44,26,91,245,89,44,196,211,127,0,40,180,104,48,181,190,74,44,28,211,208,179,131,154,56,51,170,174,135,118,169,233,206,54,201,80,164,224,0,0,0,80,82,54,149,0,152,189,62,173,27,95,237,83,
196,23,206,119,60,0,128,60,8,185,131,186,254,181,62,77,156,29,85,247,35,123,85,213,86,85,236,144,0,0,0,80,100,89,37,0,130,51,62,93,253,251,55,228,29,243,22,42,30,0,64,30,185,7,231,117,233,79,94,83,227,
157,45,234,126,79,175,44,46,107,177,67,2,0,0,64,145,100,148,0,136,134,98,26,124,242,170,166,46,142,43,190,108,157,63,0,160,244,197,227,113,77,157,31,215,236,149,105,117,222,223,165,246,83,59,100,160,62,
0,0,0,64,197,217,48,1,48,124,250,150,134,159,189,169,88,36,186,209,161,0,128,18,182,248,214,128,137,179,99,234,126,111,175,234,247,54,22,59,36,0,0,0,108,161,140,30,1,241,212,31,0,182,15,131,226,138,133,
87,23,111,5,0,0,192,246,182,225,12,128,206,251,187,212,118,247,14,93,255,218,155,154,233,155,148,129,92,0,0,148,37,147,213,164,246,251,118,170,243,254,46,150,0,0,0,0,84,160,140,106,0,152,172,70,237,251,
145,67,20,1,4,128,50,100,48,24,40,2,8,0,0,128,236,222,2,96,107,112,234,200,207,191,77,51,151,38,116,227,201,171,138,6,34,133,138,11,0,144,7,174,29,53,234,121,100,143,92,59,106,138,29,10,0,0,0,138,44,171,
4,192,162,134,195,45,106,56,220,162,219,255,210,175,145,211,183,20,103,41,41,0,148,20,107,141,77,93,15,237,82,211,157,109,146,161,216,209,0,0,0,160,20,108,42,1,176,104,231,247,237,86,251,125,59,117,253,
203,125,154,187,49,35,45,43,22,104,180,154,153,33,0,0,5,102,182,165,254,103,220,104,49,170,237,158,29,234,124,160,91,38,171,169,72,81,1,0,0,160,20,229,148,0,144,36,179,221,162,253,63,113,68,222,145,5,
93,251,251,55,146,251,235,246,52,104,250,210,68,174,205,3,0,214,81,211,91,159,252,119,211,145,22,117,189,167,87,214,26,91,17,35,2,0,0,64,169,202,91,25,232,170,142,106,29,123,252,84,114,187,231,189,189,
50,59,44,249,106,30,0,176,130,217,97,209,206,135,118,39,183,247,252,224,65,6,255,0,0,0,88,83,193,222,3,101,169,182,233,208,199,79,168,225,96,243,170,41,170,0,80,145,226,82,60,30,207,185,110,138,217,102,
86,227,225,102,221,249,11,119,201,209,232,200,79,108,0,0,0,216,246,10,58,50,119,52,58,180,247,135,15,21,242,18,0,80,126,12,210,169,207,62,88,236,40,0,0,0,80,97,10,54,3,0,0,0,0,0,0,148,14,18,0,0,0,0,0,
0,84,0,18,0,0,0,0,0,0,84,0,18,0,0,0,0,0,0,84,0,18,0,0,0,0,0,0,84,0,18,0,0,0,0,0,0,84,0,18,0,0,0,0,0,0,84,0,115,177,3,40,5,129,105,159,110,62,221,47,119,255,172,162,193,104,177,195,89,151,201,106,86,205,
174,58,117,189,123,183,28,205,206,98,135,35,137,254,203,21,253,151,27,250,15,0,0,0,200,76,197,39,0,252,211,126,189,241,197,179,138,248,195,197,14,37,35,209,80,68,179,87,166,228,30,156,213,225,143,159,
44,250,32,130,254,203,13,253,151,27,250,15,0,0,0,200,92,217,39,0,174,127,173,79,179,111,78,38,183,143,63,126,74,102,167,37,227,243,111,63,51,80,54,131,135,229,162,193,168,110,125,187,95,251,126,252,112,
86,231,77,156,25,209,205,167,110,172,249,57,253,151,153,219,223,25,208,216,75,67,105,63,51,90,76,58,249,239,238,203,172,157,10,235,191,141,190,127,18,253,7,0,0,0,20,74,217,38,0,98,225,152,98,225,168,98,
193,176,162,161,165,105,191,17,95,88,50,72,102,71,102,131,88,247,192,108,161,66,44,184,249,129,153,172,207,137,71,149,210,95,38,171,73,6,147,81,209,96,68,241,88,156,254,219,64,60,18,83,52,20,85,52,16,
81,52,20,77,246,223,162,72,32,188,212,143,38,131,204,182,245,127,197,42,174,255,214,248,254,45,162,255,0,0,0,128,194,41,219,4,192,208,179,3,26,249,238,237,85,251,207,253,143,87,101,52,27,117,247,127,122,
32,163,118,98,161,72,190,67,219,50,177,112,76,177,104,92,70,147,97,211,109,236,254,224,126,53,30,110,214,165,63,125,93,158,225,5,250,111,3,19,103,199,52,240,205,171,201,237,197,254,91,244,250,239,126,
87,97,111,88,175,253,206,119,229,104,114,234,232,47,223,189,126,12,21,214,127,43,209,127,185,245,31,0,0,0,144,141,178,75,0,132,189,97,133,230,3,10,121,18,211,126,109,245,118,153,237,75,79,171,125,227,
30,73,146,119,100,65,70,139,137,53,182,25,178,55,85,41,30,163,255,114,229,108,117,41,226,79,12,74,109,245,142,34,71,3,0,0,0,0,75,10,158,0,136,133,99,26,127,125,68,211,23,39,228,155,240,42,22,222,92,149,
238,214,183,117,104,215,251,247,106,230,242,100,202,19,216,174,135,122,211,62,65,188,248,191,94,79,62,65,244,79,249,116,254,127,188,154,210,222,221,159,122,231,182,122,242,246,234,111,61,167,88,12,9,246,
204,0,0,32,0,73,68,65,84,52,190,230,231,139,253,183,150,61,31,222,47,137,254,91,203,70,253,183,232,192,79,29,93,181,143,254,203,188,255,210,161,255,150,24,45,38,57,91,171,212,120,164,69,109,39,59,100,
48,243,38,87,0,0,0,100,174,160,9,128,144,59,168,190,191,190,152,124,170,92,8,158,97,183,12,203,254,6,142,69,98,5,187,22,96,175,183,171,225,64,179,124,19,94,5,166,125,171,190,127,146,36,163,81,13,251,27,
139,18,95,185,73,247,251,107,48,74,245,251,154,101,171,181,21,47,176,18,21,11,71,229,25,114,203,51,228,214,212,217,81,237,251,241,59,101,173,161,159,0,0,0,144,153,130,37,0,226,145,88,193,7,255,146,52,
250,210,109,141,190,84,208,75,0,73,181,123,26,84,187,167,65,183,190,125,67,35,223,245,165,253,254,101,83,67,161,210,173,213,127,123,127,228,80,113,2,42,35,222,49,175,174,252,205,5,29,254,248,73,102,2,
0,0,0,32,35,5,75,0,140,189,54,82,240,193,191,36,213,239,109,148,189,113,105,157,250,248,247,134,153,5,128,130,171,238,174,83,123,154,175,217,248,247,134,165,120,92,163,47,222,150,217,105,81,243,177,182,
173,15,174,140,181,222,213,41,179,221,36,73,138,199,164,217,43,147,10,206,7,139,28,85,233,242,142,121,53,254,250,168,218,238,233,44,118,40,0,0,0,40,3,5,75,0,76,95,156,72,217,174,63,208,164,221,143,238,
149,165,202,154,215,235,52,221,217,150,82,3,96,234,194,216,170,4,128,163,201,169,83,159,125,48,175,215,45,53,119,127,234,157,5,107,155,254,91,173,126,111,163,234,247,174,158,230,63,117,97,76,97,111,88,
55,255,249,134,28,77,78,53,31,107,163,255,178,176,227,93,221,201,255,70,24,140,82,195,129,196,239,118,251,169,29,121,105,191,84,101,218,127,97,79,72,3,79,94,209,76,223,116,114,223,244,197,113,18,0,0,0,
0,200,72,193,18,0,254,73,111,202,118,33,6,255,200,159,209,23,111,43,56,23,80,52,24,149,209,100,80,215,195,123,100,118,150,221,75,34,10,110,225,214,188,166,47,45,37,183,90,142,183,203,217,238,42,98,68,
229,173,249,120,155,170,218,170,53,250,210,45,5,231,130,186,253,204,128,76,54,179,186,223,219,91,236,208,74,146,197,101,85,207,163,251,52,211,247,98,114,159,111,194,87,196,136,0,0,0,80,78,10,54,194,139,
134,82,171,253,51,248,47,109,211,111,76,200,51,188,32,41,177,6,155,39,138,233,249,198,189,26,123,117,56,185,93,221,85,71,2,32,7,117,189,141,106,60,220,172,169,11,99,10,206,5,53,113,102,84,70,179,145,4,
192,58,172,174,212,255,150,70,67,145,34,69,2,0,0,128,114,195,35,222,10,55,242,226,45,77,93,24,147,127,218,47,73,218,243,3,7,120,242,191,142,186,59,26,181,239,199,15,107,242,236,184,102,222,156,76,246,
223,162,72,32,42,131,201,168,189,63,114,80,38,43,253,152,169,238,247,238,81,36,16,214,141,175,244,41,26,142,232,202,223,92,148,181,214,182,233,87,7,2,0,0,0,88,141,17,74,133,243,142,44,104,249,98,141,218,
222,122,102,107,172,195,86,103,147,173,206,166,133,155,243,146,86,247,159,148,152,65,81,191,183,105,235,131,43,99,213,93,181,146,36,131,217,160,120,80,154,189,58,45,71,147,115,131,179,0,0,0,0,100,163,
236,18,0,141,135,155,85,221,93,147,220,182,214,218,83,62,63,248,177,227,138,199,18,69,0,13,38,211,150,198,86,14,86,246,223,74,102,7,131,255,76,180,221,187,83,77,71,91,211,126,102,48,24,182,56,154,242,
193,239,47,0,0,0,80,60,101,151,0,48,59,44,50,59,44,107,126,158,237,83,67,163,213,172,152,63,156,107,88,69,97,180,24,101,52,101,55,216,220,168,255,178,142,161,194,250,111,145,213,101,93,181,22,123,83,49,
84,88,255,241,251,187,36,151,239,31,0,0,0,176,25,198,98,7,80,108,181,187,235,138,29,194,166,213,238,110,40,118,8,244,95,206,49,208,127,185,197,64,255,1,0,0,0,153,170,248,4,192,206,135,118,231,245,137,
248,86,49,219,204,234,122,207,238,98,135,65,255,229,136,254,203,13,253,7,0,0,0,100,174,226,19,0,246,6,135,14,127,226,132,26,14,54,203,108,43,253,21,17,38,155,73,13,7,155,117,231,47,190,173,36,138,164,
209,127,185,161,255,114,67,255,1,0,0,0,153,43,253,191,152,183,128,189,193,161,189,63,124,168,216,97,148,45,250,47,55,244,95,110,232,63,0,0,0,32,51,21,63,3,0,0,0,0,0,128,74,64,2,0,0,0,0,0,128,10,64,2,0,
0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,
0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,
0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,
0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,
128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,
10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,64,2,0,0,0,0,0,128,10,96,46,118,0,0,10,239,220,31,190,162,88,56,154,209,177,189,63,112,64,181,187,234,11,28,17,0,0,0,128,173,70,2,0,
168,0,33,119,80,177,72,44,177,97,144,12,6,195,154,199,198,163,241,45,138,106,243,226,241,184,226,177,213,251,141,166,181,239,11,0,0,0,168,116,36,0,128,10,227,234,168,214,225,79,156,44,118,24,57,25,253,
238,144,110,61,125,99,213,254,163,191,116,183,28,205,206,34,68,4,0,0,0,148,190,130,37,0,76,86,179,162,161,72,114,59,236,9,201,226,178,22,234,114,0,242,44,52,31,84,52,146,230,49,251,50,22,135,89,102,167,
101,233,156,133,144,162,161,165,165,6,142,6,135,244,214,67,249,120,36,166,192,124,48,227,115,151,51,89,12,178,214,216,147,219,102,167,73,246,6,135,34,222,176,34,193,72,218,115,22,173,188,238,74,182,26,
155,140,150,165,114,40,129,25,191,226,27,76,130,176,184,44,50,219,86,255,231,115,189,115,87,222,239,102,133,22,66,41,219,38,43,121,92,0,0,0,100,166,96,127,57,58,90,156,242,12,185,147,219,253,79,94,213,
174,71,247,202,74,18,0,40,11,111,254,229,121,249,167,124,235,30,211,241,246,157,234,122,79,111,114,187,255,27,87,52,119,125,58,185,125,247,127,124,32,57,184,246,142,123,116,233,79,207,100,124,238,114,
174,206,212,89,11,45,39,58,212,114,162,67,3,79,94,211,248,107,195,235,198,184,242,186,43,237,255,87,119,170,238,142,134,228,246,133,63,250,222,210,114,137,53,236,122,255,94,181,190,173,99,213,254,245,
206,93,121,191,155,17,242,132,212,255,141,43,41,251,156,45,204,120,0,0,0,64,102,10,150,0,104,60,210,146,146,0,152,237,155,210,108,223,84,161,46,7,32,141,187,255,211,3,50,154,83,95,246,17,9,70,53,119,99,
54,185,109,171,179,203,209,232,208,200,119,111,235,214,183,111,232,232,47,223,45,71,83,234,160,210,104,50,168,186,187,46,185,29,246,132,229,155,240,40,56,31,208,220,141,89,57,155,157,178,214,216,54,21,
163,127,202,167,224,124,80,17,127,88,146,84,189,163,70,70,171,73,146,20,143,197,228,30,156,79,198,108,173,182,200,217,226,202,168,221,88,52,46,247,224,156,2,211,137,36,134,197,101,149,179,165,42,229,186,
33,119,80,222,177,5,201,104,80,77,87,141,140,22,83,74,27,38,155,73,174,206,154,228,118,104,62,32,255,180,95,254,41,175,230,110,204,202,213,238,146,217,105,209,194,144,91,209,96,84,241,44,250,106,224,155,
87,53,254,189,145,77,245,217,114,205,39,218,114,110,3,0,0,0,149,161,96,9,128,182,147,29,154,60,59,38,223,152,167,80,151,0,176,9,129,41,159,250,254,242,124,114,59,147,39,211,38,187,89,7,126,234,104,114,
123,250,210,164,174,125,249,13,77,95,154,212,244,165,201,53,159,136,103,98,236,229,225,148,167,248,187,63,180,63,185,142,63,236,13,233,245,223,125,49,25,115,227,161,102,221,241,67,135,50,106,55,26,8,167,
220,103,77,119,109,202,185,139,179,7,110,63,51,32,41,125,253,0,71,147,51,229,190,71,78,223,214,173,167,111,104,236,149,97,141,189,50,156,156,61,208,255,245,190,228,108,9,115,149,165,96,125,181,82,237,
238,122,181,28,207,79,91,0,0,0,216,254,10,150,0,48,152,141,218,255,227,71,212,247,55,23,73,2,0,37,196,82,101,81,253,190,230,228,246,242,39,220,165,96,250,242,132,172,174,196,108,130,229,117,68,202,69,
44,28,215,196,235,163,201,109,207,168,123,157,163,55,175,118,119,189,122,127,224,64,178,198,2,0,0,0,176,145,130,86,143,178,214,216,116,228,19,39,52,254,250,168,166,47,140,203,55,225,93,179,200,23,128,
173,97,171,179,107,247,7,247,22,59,140,53,13,125,103,176,216,33,228,36,26,138,168,255,137,43,27,31,184,9,38,171,89,206,22,167,154,79,180,37,158,252,51,248,7,0,0,64,22,10,94,62,218,96,50,170,237,238,78,
181,221,221,89,232,75,1,200,65,199,219,119,170,227,237,59,115,106,163,249,88,171,170,187,107,52,246,242,144,194,222,176,134,158,27,144,193,144,168,65,16,242,36,42,241,59,91,170,212,120,164,69,174,29,233,
103,30,180,159,218,33,115,85,250,106,249,206,166,170,180,251,11,37,52,31,76,46,17,144,148,172,107,82,191,183,73,174,157,213,178,55,58,86,157,99,180,152,212,249,64,215,154,109,186,118,84,75,74,20,18,220,
245,254,210,77,196,0,0,0,96,251,225,253,81,0,242,166,241,112,139,36,105,234,252,184,194,222,176,70,78,223,94,117,140,163,217,169,206,119,116,175,217,70,203,201,142,85,107,241,139,37,228,9,105,248,133,
155,171,246,215,221,209,176,230,58,126,147,213,184,238,253,1,0,0,0,197,66,2,0,168,48,129,89,191,174,127,229,242,154,159,183,191,189,91,85,109,185,61,105,239,122,184,87,209,96,68,55,190,126,69,241,104,
226,181,120,246,122,135,118,124,95,143,108,181,246,148,99,155,143,183,169,186,187,70,163,223,189,37,239,152,87,183,190,125,67,38,91,106,53,126,91,131,67,59,223,181,43,185,61,123,117,90,211,23,199,229,
29,89,72,57,110,241,220,222,199,246,203,108,51,107,207,15,30,80,112,38,160,219,223,25,208,194,144,59,229,190,23,207,237,120,251,78,57,219,92,105,223,98,176,24,243,74,85,29,169,179,23,150,223,111,36,24,
77,219,191,117,251,154,212,244,86,130,4,0,0,0,40,6,18,0,64,133,137,248,34,154,186,56,177,230,231,77,119,182,73,57,38,0,234,247,54,74,146,250,191,113,69,241,183,246,153,157,102,53,29,105,93,117,172,171,
179,90,174,206,106,77,157,159,144,228,213,236,213,233,180,199,44,79,0,248,39,124,105,239,97,241,220,221,31,220,47,163,197,168,166,35,173,242,12,187,117,251,59,3,10,205,7,211,158,83,211,83,175,186,59,26,
210,222,199,90,49,175,180,252,126,99,145,88,218,235,88,107,108,18,9,0,0,0,0,20,145,225,177,207,159,139,111,124,24,128,114,22,143,101,254,107,110,48,24,18,197,229,98,241,228,224,221,32,73,198,165,138,115,
209,80,68,190,113,111,114,219,86,239,144,213,101,93,213,214,194,144,91,138,39,90,49,89,77,114,182,186,214,188,174,127,202,167,136,63,156,246,179,149,231,134,23,130,10,204,5,36,73,22,167,69,102,167,85,
70,139,81,134,183,98,52,44,139,85,113,41,30,95,251,254,147,247,187,120,111,254,101,111,30,48,74,38,155,89,134,184,180,97,15,26,214,239,103,131,97,241,255,108,31,47,127,246,217,98,135,0,0,0,80,22,238,249,
204,59,37,73,175,252,230,115,57,181,115,234,179,15,230,116,62,51,0,128,10,144,50,32,206,148,209,176,102,145,121,147,213,172,234,157,181,74,12,139,215,110,187,122,141,66,127,233,56,154,50,95,247,111,169,
182,201,82,189,122,202,126,90,134,183,6,249,25,50,57,86,255,103,49,158,225,233,155,234,103,0,0,0,96,139,144,0,144,20,143,198,52,125,105,66,238,219,243,169,79,255,74,141,65,178,186,108,170,219,211,168,
218,61,245,197,142,6,121,18,114,7,52,244,236,77,205,15,204,42,18,40,225,239,159,36,179,221,172,218,93,13,218,249,174,110,89,170,109,138,203,32,99,60,174,120,38,3,236,245,115,5,89,49,196,227,138,27,140,
146,226,101,221,127,0,0,0,192,86,42,171,4,192,236,213,41,141,188,112,43,171,115,170,58,107,212,243,200,158,53,63,143,250,35,186,252,151,231,87,21,19,43,101,163,47,15,169,249,88,171,118,127,104,127,86,
79,54,81,122,130,115,1,189,241,197,51,10,121,66,197,14,37,35,81,127,68,19,179,35,154,187,58,165,195,159,56,41,107,173,45,179,193,191,148,28,252,47,220,154,211,248,235,99,106,56,208,172,134,253,141,201,
143,135,79,223,148,127,210,159,56,212,16,87,239,99,7,214,108,42,113,205,248,182,232,63,0,0,0,96,171,148,85,2,32,188,16,214,194,109,119,86,231,24,45,166,117,63,31,120,234,90,89,13,254,23,77,158,27,87,245,
142,58,181,220,213,94,236,80,144,131,219,79,247,151,205,224,117,185,144,39,164,91,79,223,208,158,31,60,152,245,185,129,233,128,166,206,143,201,94,111,79,73,0,204,93,155,213,194,205,185,228,246,122,9,128,
69,149,216,127,0,0,0,192,102,149,85,2,32,223,226,145,152,166,223,152,44,118,24,155,54,121,97,140,4,192,22,90,184,53,175,91,223,190,145,213,57,246,70,199,186,3,217,217,235,51,185,134,85,52,217,198,238,
27,245,104,224,169,235,10,123,83,7,236,195,167,111,106,238,218,172,252,99,158,148,253,111,252,217,57,89,171,173,186,227,35,107,15,146,43,169,255,0,0,0,128,92,149,87,2,192,144,90,100,43,30,79,45,205,189,
178,0,215,70,149,207,35,254,176,226,145,88,94,67,220,74,33,119,160,216,33,84,148,176,47,146,245,12,148,104,104,253,239,87,180,196,215,172,175,39,219,122,25,145,64,36,229,9,255,34,255,164,63,237,254,133,
155,115,178,213,217,215,143,161,130,250,15,0,0,0,200,85,89,37,0,90,78,180,171,229,196,210,19,239,235,95,185,156,242,190,237,19,159,60,149,44,172,229,159,246,235,252,23,94,89,183,189,245,94,13,86,14,226,
49,214,255,163,252,52,30,106,86,215,123,246,200,228,72,93,158,115,199,71,14,201,181,236,173,1,103,63,255,210,86,135,6,0,0,0,108,107,5,79,0,196,194,49,141,191,62,162,233,139,19,242,77,120,21,11,71,179,
110,163,229,100,187,118,127,96,95,114,59,226,11,43,236,143,40,26,204,252,233,253,124,255,172,222,252,139,243,146,36,107,141,93,39,254,205,169,172,227,40,85,33,119,64,103,254,159,151,51,58,214,104,49,201,
217,90,165,198,35,45,106,59,217,33,131,217,88,224,232,74,131,103,216,173,137,179,99,90,24,152,85,112,62,168,88,22,51,63,26,246,55,106,239,143,30,145,193,24,95,247,253,242,235,205,64,241,141,123,116,225,
127,190,150,220,206,245,253,157,165,102,189,247,193,215,236,170,211,193,159,62,150,220,54,90,76,178,213,173,46,126,103,113,89,151,246,175,200,205,5,231,2,58,251,249,165,239,120,37,245,159,36,25,205,70,
89,107,237,170,221,85,167,230,227,237,114,117,86,111,77,96,0,0,0,216,86,10,154,0,8,185,131,234,251,235,139,242,141,123,54,62,56,11,163,47,13,105,248,133,155,121,109,179,82,196,194,81,121,134,220,242,12,
185,53,117,118,84,251,126,252,78,89,107,182,111,37,242,88,56,170,254,127,184,170,169,75,227,171,6,149,217,170,223,219,164,123,62,253,206,228,246,224,83,215,53,246,242,80,114,251,200,39,78,202,217,238,
146,36,69,130,17,189,246,95,79,231,118,65,224,45,177,72,76,129,105,159,2,211,62,141,191,62,162,166,59,91,181,251,209,125,50,90,42,35,129,7,0,0,128,252,40,88,2,32,30,137,229,125,240,31,94,8,202,59,225,
83,112,54,177,246,221,217,82,37,139,203,42,239,240,130,34,193,136,230,111,206,203,236,176,36,143,197,250,188,99,94,93,249,155,11,58,252,241,147,219,114,38,64,44,28,213,27,127,118,46,239,111,121,136,6,
34,10,121,195,101,189,254,188,152,162,161,88,242,119,88,146,98,161,212,89,65,33,119,64,241,236,39,10,85,142,184,52,117,126,92,129,41,191,14,126,244,88,81,147,0,38,171,73,209,16,63,44,0,0,128,173,96,178,
173,255,134,187,76,20,44,1,48,246,218,72,222,159,252,207,94,157,81,255,19,87,146,219,29,239,232,82,211,145,86,189,241,165,51,90,184,237,214,245,47,95,206,235,245,42,129,119,204,171,241,215,71,213,118,
79,103,177,67,201,187,254,39,174,22,228,21,143,19,231,198,116,243,169,235,121,111,183,82,204,92,158,208,204,229,137,53,63,191,244,165,179,10,205,147,192,219,136,103,216,173,254,39,175,106,207,135,247,
23,45,6,107,173,77,254,73,95,209,174,15,0,0,80,73,108,181,235,23,200,206,68,193,18,0,211,23,83,255,192,175,63,208,164,221,143,238,149,165,202,154,115,219,85,29,213,170,106,171,150,189,222,145,104,123,
95,147,28,205,46,77,93,28,83,44,156,88,219,109,178,153,212,120,168,85,206,102,167,36,169,118,119,253,182,91,55,188,200,90,99,207,248,222,194,158,144,6,158,188,162,153,190,233,228,190,233,139,227,219,46,
1,224,25,94,208,212,197,241,148,125,206,118,151,186,31,218,173,234,238,186,77,61,53,13,123,195,242,142,121,20,152,242,75,146,236,141,78,217,106,109,242,141,123,20,246,134,181,48,236,86,200,23,150,164,
228,247,48,121,237,86,215,182,253,254,73,153,173,201,55,59,204,170,233,169,83,216,19,146,127,106,105,208,232,104,114,202,226,178,202,100,79,253,207,81,77,79,157,172,174,196,242,20,91,93,230,223,241,114,
180,209,189,197,194,49,185,111,206,233,214,211,253,242,45,123,93,226,212,133,49,181,223,211,169,170,142,226,212,4,168,235,109,32,1,0,0,0,176,69,106,123,27,114,110,163,96,9,0,255,164,55,101,59,95,131,127,
73,106,56,208,164,206,119,116,39,183,59,238,239,146,36,205,93,155,82,40,156,120,199,184,165,202,170,221,31,220,155,151,235,109,39,22,151,85,61,143,238,211,76,223,139,201,125,190,137,237,247,7,252,228,
217,209,148,53,255,85,237,213,58,244,51,199,115,154,46,189,112,219,173,171,127,119,49,185,221,118,87,135,218,238,221,161,43,127,119,73,179,125,83,26,120,242,106,46,33,111,123,206,54,151,14,126,244,152,
38,207,142,233,198,55,250,146,251,59,238,239,86,243,177,214,85,199,31,252,232,177,85,251,42,149,209,98,84,221,158,6,213,116,215,233,210,151,206,44,37,1,226,210,196,153,49,237,42,82,2,160,249,68,155,198,
94,25,46,251,55,170,0,0,0,148,58,131,81,106,57,209,150,115,59,5,75,0,172,92,23,154,143,193,191,171,179,90,59,31,218,165,136,55,172,235,95,185,172,214,187,119,168,122,231,210,107,195,218,239,239,74,174,
39,54,59,202,234,13,135,91,202,234,74,253,89,68,67,219,111,45,187,123,96,54,101,187,235,161,93,121,91,43,237,104,174,82,245,206,90,57,90,171,36,73,117,123,234,101,113,90,53,211,55,161,136,47,209,151,70,
147,65,77,71,219,101,173,205,79,210,171,156,69,3,17,141,190,180,84,44,209,59,150,186,52,104,182,111,66,193,89,127,114,187,174,183,81,241,120,230,111,105,168,36,70,139,81,93,239,222,165,190,191,90,74,68,
205,15,206,174,115,70,97,57,91,92,106,57,217,161,241,215,134,139,22,3,0,0,64,37,104,189,171,83,142,230,170,156,219,41,171,81,178,179,205,37,103,155,75,183,159,25,208,212,197,9,213,237,109,76,77,0,220,
179,163,136,209,161,148,4,221,169,107,200,171,187,235,242,214,118,221,238,122,117,191,111,79,114,187,245,174,196,242,9,207,136,91,17,95,98,112,107,48,27,153,129,242,150,136,63,162,161,231,6,215,252,124,
166,111,58,101,73,202,241,199,239,77,251,154,64,36,212,172,248,46,23,187,94,66,207,35,189,242,79,121,229,30,156,43,106,28,0,0,0,219,85,205,174,58,117,191,183,55,47,109,149,85,2,96,246,234,148,70,94,184,
165,224,91,127,240,14,61,123,83,227,175,14,107,215,7,246,202,217,226,210,213,191,187,168,176,63,170,67,31,99,234,112,165,91,185,6,63,31,79,255,29,205,206,196,12,20,95,68,215,191,114,89,77,71,219,84,183,
103,105,29,78,219,221,157,10,123,19,75,80,140,166,237,247,86,5,148,6,163,37,181,250,107,44,92,220,42,252,6,179,81,7,126,226,78,13,254,211,117,77,188,62,34,38,111,0,0,0,228,135,193,152,120,216,216,253,
222,94,25,242,52,190,40,171,4,64,120,33,172,133,219,238,228,118,226,189,216,82,52,152,248,3,216,51,188,160,176,55,92,172,240,176,205,57,26,29,234,124,71,183,70,95,30,210,232,75,183,229,234,168,145,150,
37,0,90,78,180,23,49,58,160,120,12,102,163,118,189,127,175,90,223,214,169,137,51,163,154,191,49,171,208,124,128,87,4,2,0,0,100,201,100,53,201,86,103,87,77,111,189,90,79,180,231,101,218,255,114,101,149,
0,88,212,113,255,78,181,223,179,67,253,223,186,166,217,55,167,54,223,144,177,188,159,210,26,77,134,98,135,80,81,22,110,205,235,214,183,111,40,228,73,60,229,31,125,101,72,211,151,39,212,245,238,196,155,
5,110,124,189,79,129,105,159,246,255,228,157,50,89,51,251,213,50,90,76,69,127,130,187,89,38,107,102,239,33,181,184,172,58,248,209,227,201,237,185,235,211,26,57,125,75,205,199,219,212,124,116,41,105,114,
243,169,171,242,142,121,211,53,177,166,74,232,191,114,226,108,169,82,207,35,123,54,62,16,0,0,160,66,21,251,205,86,101,153,0,48,217,204,178,84,219,100,50,231,54,128,183,84,89,100,169,178,148,237,172,1,
71,75,126,179,65,88,95,216,23,73,153,129,18,156,11,40,56,23,72,22,254,243,142,121,18,213,217,179,24,143,214,116,215,106,238,250,76,190,67,221,18,53,61,153,213,85,48,90,140,170,233,169,77,110,47,22,252,
179,213,218,83,246,27,109,150,236,99,168,128,254,3,0,0,0,242,165,188,31,129,231,200,96,48,168,253,222,157,197,14,99,83,140,38,131,118,60,216,189,241,129,200,187,150,19,237,58,249,111,239,85,203,201,220,
167,252,119,61,180,91,198,28,19,89,197,96,180,152,212,245,222,226,63,233,165,255,0,0,0,128,204,149,223,95,206,146,194,190,176,252,211,126,69,131,137,106,83,161,249,160,252,211,126,109,230,85,212,237,111,
223,169,142,183,239,148,193,88,62,211,233,205,78,139,246,124,228,160,170,218,139,243,238,239,74,103,178,152,100,169,182,173,42,198,182,25,206,118,151,14,253,204,113,85,119,213,201,96,40,253,239,160,193,
96,80,117,119,157,14,125,236,152,28,141,142,220,27,140,47,251,223,38,84,124,255,1,0,0,0,89,40,203,37,0,99,47,13,105,108,217,123,197,175,125,249,114,242,223,217,14,228,13,6,131,186,222,211,171,182,83,59,
229,29,118,43,22,221,228,72,100,139,152,108,70,85,119,213,102,188,198,28,165,175,170,163,90,135,126,230,152,226,145,216,170,183,23,148,26,163,197,40,67,158,158,184,15,61,59,168,161,103,7,115,110,167,82,
251,15,0,0,0,200,214,182,26,69,86,119,213,201,100,221,220,31,215,214,106,171,172,251,155,242,28,17,182,163,112,32,146,152,129,18,72,172,253,15,121,66,137,25,40,145,220,6,159,6,179,49,231,186,22,229,192,
100,51,202,86,103,87,36,16,73,246,161,36,89,93,86,25,204,70,25,55,57,177,162,82,250,15,0,0,0,216,172,109,149,0,216,251,67,7,100,169,182,21,59,12,108,115,83,231,199,52,117,126,44,185,61,240,205,171,69,
140,166,252,52,28,108,81,195,193,22,13,125,103,80,67,207,13,38,247,239,249,200,161,148,162,128,0,0,0,0,242,107,91,37,0,70,78,223,150,209,110,210,206,119,237,42,118,40,168,64,174,29,53,137,87,187,241,122,
198,117,5,102,252,90,184,57,47,239,152,167,216,161,0,0,0,0,21,101,91,37,0,70,95,25,146,193,104,32,1,128,162,216,253,254,189,114,182,187,138,29,70,201,91,184,57,175,27,223,232,43,118,24,0,0,0,64,197,97,
193,44,144,39,99,223,27,214,237,103,6,74,190,16,93,177,4,231,2,26,250,206,160,102,250,166,210,126,62,121,110,68,67,223,25,84,36,24,73,251,57,0,0,0,128,220,108,171,25,0,64,49,77,156,25,149,36,117,220,183,
83,178,144,91,91,41,56,27,72,89,243,191,210,228,185,113,73,82,243,241,118,153,109,252,167,9,0,0,0,200,183,178,250,43,187,126,95,163,14,181,28,95,243,243,43,127,123,41,165,170,56,128,210,83,221,85,167,
150,19,237,154,237,155,208,76,223,180,90,78,182,171,122,103,157,134,79,223,84,96,202,87,236,240,0,0,0,128,109,171,172,18,0,22,151,85,22,151,117,205,207,141,38,131,162,91,24,15,128,236,217,27,236,106,62,
214,170,224,172,95,51,125,211,170,222,89,167,230,99,173,154,56,59,74,2,0,0,0,0,40,160,178,74,0,0,197,84,211,93,163,67,63,187,246,12,148,254,175,247,201,63,237,223,194,136,0,0,0,0,32,115,229,149,0,136,
75,177,88,188,216,81,160,66,153,29,22,85,239,92,251,61,245,6,139,105,11,163,1,0,0,0,128,236,148,85,2,96,226,204,168,250,159,184,178,238,49,6,35,239,96,7,202,201,205,127,190,166,219,223,233,87,216,27,46,
118,40,0,0,0,192,182,86,86,9,128,141,216,234,237,50,154,168,190,142,2,97,6,74,110,12,43,254,255,91,34,190,136,164,165,226,157,6,114,120,0,0,0,64,65,108,171,4,192,225,159,57,46,75,181,173,216,97,96,155,
154,185,50,173,171,127,119,177,216,97,148,173,154,158,58,157,250,236,131,107,126,126,240,163,199,85,211,179,246,18,11,0,0,0,0,185,41,139,4,64,120,33,168,217,171,51,10,206,6,84,187,187,62,185,223,63,225,
85,200,19,42,98,100,192,18,107,141,93,70,179,65,98,25,202,186,66,158,144,2,147,62,5,230,2,197,14,5,0,0,0,168,40,101,145,0,240,78,248,212,255,196,21,181,156,232,208,129,159,58,154,220,127,253,43,151,53,
117,113,162,136,145,1,75,246,255,216,97,57,219,93,197,14,163,228,205,95,155,209,141,111,244,21,59,12,0,0,0,160,226,148,69,2,96,165,185,27,179,90,24,156,147,119,204,155,178,127,228,244,109,25,237,38,237,
124,215,174,34,69,134,237,40,226,15,107,230,242,148,66,11,193,212,25,40,211,62,133,230,131,69,140,172,188,132,60,33,205,95,155,209,194,173,249,180,159,207,93,159,86,112,214,175,198,195,205,50,242,70,5,
0,0,0,32,239,202,50,1,176,48,56,167,225,23,110,174,218,63,250,202,144,12,70,3,9,0,228,85,112,62,164,254,39,174,168,126,95,83,202,12,148,193,167,174,107,236,229,161,34,70,86,94,2,147,190,117,159,252,143,
156,190,37,73,170,217,85,47,91,29,9,0,0,0,0,32,223,202,50,1,176,168,245,109,29,170,238,90,42,26,54,240,173,107,138,5,163,69,140,8,149,96,97,200,173,185,43,211,242,220,118,167,236,31,251,222,176,44,85,
86,117,62,208,45,163,133,183,81,172,197,217,230,82,195,254,38,185,7,103,229,30,156,87,253,129,38,85,181,186,52,121,110,84,193,57,102,84,0,0,0,0,133,82,214,163,148,234,174,90,53,29,105,77,254,207,100,46,
235,219,65,153,240,12,185,53,252,194,77,121,134,83,19,0,19,103,70,53,252,194,77,197,35,177,34,69,86,30,170,218,92,218,241,96,143,106,186,19,203,41,26,246,53,107,199,131,61,178,214,58,138,28,25,0,0,0,176,
189,149,245,12,0,160,152,154,238,108,85,221,29,13,201,237,219,207,244,243,4,27,0,0,0,64,201,34,1,0,108,146,171,189,90,77,71,90,147,219,35,223,189,45,137,4,0,0,0,0,128,210,84,86,9,128,169,139,99,154,187,
54,165,232,91,235,252,7,190,117,77,183,254,249,70,242,243,176,39,44,241,10,118,160,172,12,159,190,169,137,179,163,242,143,121,138,29,10,0,0,0,176,173,149,69,2,192,96,144,12,70,131,226,209,152,66,11,161,
228,254,168,63,162,149,37,255,12,6,50,0,64,57,9,76,249,20,152,242,21,59,12,0,0,0,96,219,43,139,4,64,237,238,122,221,243,233,119,106,226,245,81,245,63,113,165,216,225,160,66,205,223,152,209,153,223,123,
81,177,80,162,200,223,208,179,131,26,121,241,86,242,243,136,47,92,172,208,202,66,245,206,26,29,127,252,94,153,172,233,139,117,222,241,145,67,114,237,168,145,181,198,182,197,145,1,0,0,0,149,161,44,18,0,
139,76,54,179,236,13,14,133,253,97,69,253,145,85,159,219,234,237,50,154,120,19,0,242,203,96,136,39,102,160,196,82,103,160,68,130,17,150,252,103,193,96,54,202,86,103,83,52,20,85,112,54,32,73,178,213,217,
20,241,69,20,13,69,101,173,182,200,86,199,224,31,0,0,0,40,148,178,74,0,52,30,110,86,227,225,102,221,126,102,64,195,47,220,92,245,249,225,159,57,46,75,53,3,8,228,151,179,213,165,123,62,253,78,205,244,77,
235,234,223,93,44,118,56,101,111,230,141,73,221,248,70,95,114,187,247,177,3,106,62,214,186,206,25,0,0,0,0,242,161,172,30,151,7,166,124,154,120,125,84,222,177,133,180,159,79,94,152,208,196,153,209,45,142,
10,149,194,100,53,202,222,224,144,217,105,73,251,185,181,198,46,123,131,67,50,82,135,34,157,104,32,34,247,192,156,252,211,222,148,253,129,41,175,220,3,115,137,25,21,0,0,0,0,10,166,172,102,0,184,111,206,
175,91,3,224,214,183,111,200,96,52,168,229,68,251,22,70,133,74,81,187,187,94,199,126,229,30,141,190,60,164,155,79,93,95,245,249,254,31,59,44,103,187,171,8,145,149,7,239,168,71,151,255,252,220,170,253,
195,167,111,105,248,244,45,29,252,232,113,213,244,212,22,33,50,228,139,123,228,170,110,190,252,117,77,92,125,89,190,153,81,69,67,254,98,135,4,0,0,80,86,76,86,135,156,13,29,106,217,119,74,221,167,30,83,
77,251,29,121,109,191,172,18,0,139,234,122,235,85,221,83,167,153,55,38,228,29,243,170,229,174,118,217,106,237,26,57,125,75,177,112,172,216,225,97,155,10,206,5,53,127,99,70,158,33,119,218,207,167,251,38,
229,25,89,80,243,177,86,25,168,69,177,38,123,131,67,213,93,75,3,253,133,91,243,10,204,48,80,44,103,177,72,72,23,190,250,59,186,249,210,87,21,143,243,223,96,0,0,128,205,138,134,252,90,24,187,161,133,177,
27,234,127,254,111,213,115,223,71,116,228,195,191,38,163,217,154,151,246,203,50,1,80,221,83,167,206,119,116,203,63,225,149,119,204,171,230,163,109,170,222,89,171,241,87,135,73,0,160,96,188,99,158,117,
103,160,12,63,151,168,75,209,120,176,89,38,7,9,128,181,84,119,213,170,247,177,253,201,237,235,95,235,35,1,80,198,98,145,144,94,252,227,95,208,212,245,215,139,29,10,0,0,192,182,18,143,199,52,240,221,191,
215,194,120,191,238,251,249,63,202,75,18,128,81,10,144,165,234,29,53,218,249,208,46,85,239,172,145,36,53,29,105,209,206,135,118,201,234,202,79,86,14,40,39,23,190,250,59,12,254,1,0,0,10,104,234,250,107,
186,248,245,255,158,151,182,72,0,0,89,114,117,214,168,243,29,221,170,234,76,36,0,26,15,182,168,243,29,221,50,147,0,64,133,113,143,92,213,205,151,190,90,236,48,0,0,0,182,189,193,23,191,44,247,232,234,58,
100,217,42,203,37,0,43,13,60,113,77,38,155,81,97,31,85,196,129,82,183,112,107,94,215,191,182,244,26,64,207,237,121,73,210,240,233,155,154,56,155,72,162,24,12,113,245,62,118,160,40,241,33,115,131,47,127,
141,53,255,0,0,0,91,32,30,139,233,230,203,95,211,145,15,255,187,156,218,217,22,9,0,223,132,39,249,111,3,175,96,3,74,90,96,198,159,118,205,255,252,245,153,148,109,18,0,165,111,242,234,43,197,14,1,0,0,160,
98,76,92,121,57,231,54,202,42,1,208,116,103,171,234,247,54,200,104,75,31,246,145,159,59,41,75,181,109,139,163,66,165,187,245,76,191,70,94,188,165,192,52,133,236,80,89,252,179,99,197,14,1,0,0,160,98,228,
227,111,175,178,74,0,24,45,70,25,45,203,6,248,70,99,202,19,127,75,181,77,214,106,214,97,99,107,249,167,124,197,14,1,40,138,72,144,239,62,0,0,192,86,137,4,189,57,183,81,86,9,128,149,246,124,120,191,246,
124,120,255,198,7,2,121,80,215,91,175,147,255,246,94,25,172,166,180,159,31,248,137,163,114,182,58,101,178,151,245,175,85,193,84,239,172,209,241,199,239,205,232,88,3,43,121,0,0,0,128,188,99,164,2,100,104,
229,12,20,131,209,144,58,3,197,101,97,9,202,58,12,102,163,108,117,244,15,0,0,0,80,44,36,0,128,77,234,126,184,87,221,15,247,22,59,12,0,0,0,0,200,136,177,216,1,0,0,0,0,0,128,194,35,1,0,0,0,0,0,64,5,32,1,
0,0,0,0,0,64,5,32,1,0,0,0,0,0,64,5,32,1,0,0,0,0,0,64,5,32,1,0,0,0,0,0,64,5,32,1,0,0,0,0,0,64,5,32,1,0,0,0,65,157,100,170,0,0,32,0,73,68,65,84,0,0,64,5,32,1,0,0,0,0,0,64,5,48,23,170,97,91,157,189,80,77,
3,0,0,0,0,128,44,21,44,1,112,252,241,83,133,106,26,0,0,0,0,0,100,41,239,9,128,224,92,96,227,139,58,45,50,89,77,249,190,116,201,162,79,0,0,0,0,0,197,150,247,4,192,217,207,191,188,225,49,189,143,237,87,
243,177,182,124,95,186,100,209,39,0,0,0,0,128,98,43,216,18,0,73,50,219,204,114,182,87,37,183,131,115,1,5,231,130,242,79,249,228,30,156,83,85,155,75,38,123,34,4,247,224,220,210,121,118,179,156,109,174,
180,109,250,198,60,138,4,34,201,237,154,158,186,77,197,22,11,199,228,25,118,39,183,45,46,171,28,77,206,77,181,149,141,108,250,164,24,138,213,47,0,0,0,0,128,194,42,232,72,211,217,94,165,131,31,61,158,220,
30,122,118,80,67,207,14,106,228,244,45,141,156,190,165,131,31,61,150,28,192,95,254,223,231,146,199,213,244,212,166,156,183,220,224,83,215,228,30,156,79,110,159,250,236,131,155,138,45,236,13,165,92,179,
249,88,171,122,31,59,176,169,182,178,145,77,159,20,67,177,250,5,0,0,0,0,80,88,197,123,212,188,66,243,177,214,228,191,237,77,75,79,200,125,99,30,121,199,60,201,237,144,39,156,114,222,228,185,177,228,191,
45,46,171,234,246,52,164,61,111,165,98,14,178,51,181,252,222,86,170,106,115,37,103,73,204,93,159,81,216,19,90,183,45,123,131,67,213,93,181,201,237,29,15,246,228,37,70,0,0,0,0,64,121,40,153,4,192,90,79,
153,103,250,166,52,244,236,224,154,231,221,248,122,95,242,223,53,61,181,201,4,192,70,231,149,195,91,10,150,223,219,74,59,30,236,73,38,0,70,78,223,76,153,21,145,78,243,177,86,18,0,0,0,0,0,80,193,10,154,
0,8,206,5,82,6,225,238,193,89,73,82,195,254,70,57,219,170,101,171,179,107,236,229,161,148,53,253,146,100,171,179,39,11,226,213,244,212,165,12,86,39,207,141,42,56,23,76,110,47,255,204,86,103,151,111,204,
163,153,190,169,85,215,218,136,111,204,147,54,97,208,124,172,77,182,58,251,134,231,103,42,219,62,49,219,204,106,187,119,199,178,56,23,52,211,55,45,247,224,172,134,158,149,26,246,55,173,186,198,242,62,
9,206,249,53,121,110,60,121,127,53,61,117,201,217,15,147,231,198,86,189,161,32,186,226,103,129,37,158,97,183,134,95,184,149,213,57,182,122,187,122,222,187,167,64,17,1,0,0,0,64,230,10,156,0,8,166,29,84,
215,239,111,78,14,240,71,95,190,157,50,160,151,18,79,242,151,39,0,150,79,215,119,15,206,174,153,0,144,18,131,218,229,215,92,126,173,212,216,82,7,190,222,49,175,188,99,222,85,199,213,244,212,165,36,0,206,
126,254,229,140,94,235,39,165,175,79,144,109,159,152,28,166,21,9,144,177,183,18,0,243,114,15,206,167,77,78,44,63,222,61,56,167,201,115,227,201,251,219,241,96,207,178,4,192,232,134,51,7,176,36,180,16,214,
108,223,84,86,231,56,91,211,23,179,4,0,0,0,128,173,86,208,4,128,189,201,169,206,251,187,86,237,95,62,21,189,251,225,94,69,67,177,180,211,221,131,115,65,77,158,27,149,36,53,31,107,151,173,206,182,230,181,
102,250,166,213,176,191,113,221,207,125,99,11,50,217,205,106,63,181,99,213,231,213,59,107,213,114,178,61,185,61,241,250,168,22,110,207,107,248,244,45,77,158,27,85,247,195,123,100,118,90,214,108,63,83,
43,251,100,182,111,82,51,125,211,154,120,125,84,238,193,89,117,220,223,157,114,124,216,27,209,141,175,191,153,220,14,76,103,150,124,88,207,196,153,17,45,220,154,151,127,202,47,73,234,126,79,175,204,85,
137,123,139,120,195,186,249,237,27,57,95,3,0,0,0,0,80,90,10,154,0,176,186,44,27,190,219,190,225,96,139,164,244,235,221,151,79,151,175,233,169,95,55,1,48,219,55,185,110,2,96,182,111,82,147,231,198,100,
171,179,167,77,0,216,27,237,41,177,186,7,103,181,112,123,94,243,215,103,36,73,59,30,220,149,151,4,192,202,62,9,206,5,52,211,55,173,133,219,243,90,184,61,175,230,99,237,41,199,199,194,81,77,158,27,207,
249,186,203,45,220,154,79,105,179,225,80,115,114,38,65,112,46,64,2,96,139,5,102,253,26,250,151,1,185,7,230,20,141,198,138,29,206,186,76,38,163,106,118,213,107,231,67,187,242,186,52,38,23,33,79,72,35,207,
223,212,252,192,172,226,145,120,177,195,89,151,193,108,84,237,238,58,117,190,163,91,22,151,181,216,225,0,0,0,160,194,108,73,17,192,168,63,172,177,87,71,20,116,7,20,143,38,254,64,239,126,184,119,195,1,
117,245,142,106,29,127,252,94,205,92,158,216,240,26,221,15,247,110,248,249,142,7,119,201,104,202,60,238,82,96,113,89,117,199,71,14,174,249,185,189,201,153,156,37,129,173,209,114,87,135,186,31,218,189,
238,49,145,96,84,103,63,255,210,134,109,5,102,252,186,244,197,51,138,248,194,27,30,91,10,162,146,166,46,254,255,237,221,105,112,28,233,125,231,249,95,101,214,141,2,80,56,136,131,4,9,144,4,111,178,155,
100,179,213,183,212,214,225,150,198,154,157,238,85,135,195,187,214,132,101,171,237,25,207,120,34,122,99,28,227,112,204,188,208,139,217,216,23,187,27,211,27,142,152,112,196,72,35,107,119,102,66,182,101,
75,246,200,54,71,162,108,203,221,82,83,82,119,147,45,222,36,136,131,184,65,0,85,168,42,20,234,174,125,129,70,145,96,161,112,17,168,172,68,126,63,17,140,102,230,147,79,214,191,10,0,27,249,203,39,159,103,
82,115,253,179,58,241,198,89,249,155,2,150,214,147,137,165,117,245,171,31,40,19,75,175,125,112,141,88,184,63,175,217,27,51,58,245,155,103,228,169,175,28,106,2,0,0,0,91,173,42,1,128,25,240,104,207,39,186,
215,62,240,17,46,183,33,95,216,167,206,231,247,174,121,236,90,97,130,59,232,145,59,184,225,18,202,84,123,245,0,195,237,178,197,146,133,78,226,146,84,52,36,211,109,200,101,26,101,237,249,116,94,46,99,125,
119,162,239,93,24,176,205,197,255,195,178,243,89,13,255,160,95,135,94,63,97,105,29,247,46,244,219,234,226,127,73,38,150,210,208,133,1,245,190,118,212,234,82,0,0,0,224,32,150,47,3,120,237,107,151,148,137,
47,127,174,61,62,18,215,165,183,222,85,243,241,182,178,59,251,189,175,159,80,49,87,208,213,175,93,82,54,158,94,118,151,53,212,213,168,3,255,211,17,53,244,132,53,113,113,68,227,23,71,52,244,189,62,141,
252,253,64,217,235,30,255,210,153,237,121,67,107,88,122,111,75,242,11,121,73,139,207,225,55,159,216,37,79,157,87,39,126,227,172,138,133,162,46,189,117,81,153,88,122,197,59,201,157,207,238,85,199,10,143,
50,172,71,247,47,246,170,235,229,253,186,243,173,235,74,140,196,116,245,107,151,74,35,35,10,249,77,157,210,81,38,223,27,211,228,123,99,234,121,165,119,217,10,13,75,62,248,15,239,174,123,53,133,216,221,
217,173,46,175,106,162,125,17,171,75,80,228,206,140,213,37,108,90,244,206,198,38,148,4,0,0,0,30,151,229,1,64,38,158,42,91,5,160,152,43,40,29,77,43,151,204,148,29,239,253,232,185,217,165,11,214,135,251,
250,194,105,153,94,115,241,143,127,241,173,229,146,57,229,146,181,179,180,221,210,123,123,148,187,206,83,122,166,218,235,121,48,44,184,88,208,138,199,63,186,116,226,70,44,142,134,240,200,112,187,36,73,
217,184,253,238,160,90,193,237,55,21,108,15,41,151,204,40,19,207,40,157,72,175,184,114,132,10,146,203,229,82,160,173,78,129,214,213,135,200,231,210,181,243,189,185,81,181,176,100,100,126,193,250,26,54,
171,150,254,93,2,0,0,128,51,184,94,125,235,114,109,207,154,5,108,194,197,175,252,253,178,237,149,150,100,220,172,241,139,35,26,58,223,183,234,49,166,207,212,211,191,255,210,154,231,122,180,78,187,217,
202,207,117,51,156,250,249,109,231,247,247,70,124,231,205,211,150,188,46,0,0,128,83,189,250,214,229,199,234,111,249,8,0,187,113,21,165,162,203,234,42,96,37,127,115,64,77,71,90,181,48,53,175,84,100,161,
172,61,220,219,34,183,159,31,45,0,0,0,0,181,133,171,148,13,226,226,31,77,135,91,212,116,184,69,131,231,251,52,113,113,164,172,253,208,23,142,201,12,240,163,5,0,0,0,160,182,112,149,34,41,29,77,105,248,
111,7,20,235,143,212,252,58,236,134,105,168,177,39,172,174,79,238,151,191,217,218,37,216,156,174,177,39,44,87,113,113,34,186,212,236,130,90,79,182,203,83,231,145,203,83,190,50,0,0,0,0,0,88,205,241,1,64,
58,154,210,213,175,126,160,108,162,124,194,193,90,148,151,52,125,117,74,145,187,179,58,245,229,179,242,183,110,193,218,134,216,148,166,163,173,106,58,218,170,212,92,74,169,217,5,237,126,97,175,130,157,
33,171,203,2,0,0,0,128,21,217,42,0,40,230,11,202,110,112,214,111,195,112,201,29,244,84,108,31,254,65,191,109,46,254,31,150,95,200,233,222,133,187,58,252,43,167,172,46,197,49,18,163,49,141,190,125,175,
108,255,252,72,76,146,52,248,189,62,153,62,183,14,125,225,152,12,143,89,237,242,0,0,0,0,96,85,182,10,0,226,247,98,186,254,141,141,205,122,232,11,251,117,230,205,103,43,182,207,245,71,31,183,44,203,68,
251,34,82,81,18,243,18,84,69,38,158,85,228,102,229,181,219,99,3,139,223,75,197,92,81,170,156,57,1,0,0,0,128,37,28,255,176,178,157,215,97,47,228,10,42,214,248,156,5,78,116,237,235,151,117,237,63,63,222,
242,28,0,0,0,0,176,213,108,53,2,0,176,131,228,84,66,166,143,71,0,0,0,0,0,212,150,109,15,0,10,217,130,38,223,31,211,204,149,41,37,167,230,85,200,230,55,124,142,134,253,97,29,255,181,211,242,132,188,106,
57,217,86,218,159,156,156,215,194,253,249,210,118,227,254,38,185,235,30,140,189,158,185,58,85,250,123,58,154,210,165,183,46,150,182,159,249,119,31,151,203,189,115,6,64,252,228,223,255,131,138,185,181,
71,3,24,30,83,193,246,58,181,156,106,83,199,83,187,119,212,103,176,221,194,135,154,245,244,239,189,88,182,191,239,207,111,40,114,103,70,39,126,253,180,130,109,33,93,122,235,162,138,42,90,80,33,0,0,0,0,
84,182,173,1,64,38,150,214,205,255,122,69,201,201,196,150,156,47,176,43,168,67,175,31,47,109,143,252,221,160,70,126,248,32,0,216,243,137,30,53,244,52,46,110,20,151,7,0,88,84,200,230,149,24,137,41,49,18,
211,244,165,113,29,249,95,159,144,183,193,103,117,89,182,96,152,46,41,176,194,143,140,185,56,9,131,233,117,203,12,184,85,116,73,92,255,3,0,0,0,168,53,219,118,251,183,152,43,108,233,197,255,195,146,83,
9,141,190,115,79,241,225,185,45,63,183,147,204,79,204,235,214,127,251,249,186,70,14,96,123,152,94,251,62,42,96,122,173,127,130,200,240,216,119,4,11,43,69,0,0,0,160,218,182,237,183,231,137,247,198,182,
229,226,95,146,230,71,19,26,190,208,175,185,254,200,182,156,223,73,230,39,230,53,249,254,184,213,101,216,74,42,178,160,217,155,51,74,69,22,36,73,190,38,191,130,237,33,185,62,186,24,13,182,213,41,216,22,
90,215,185,26,122,194,219,86,231,118,107,56,104,125,237,13,251,26,173,46,97,211,26,186,173,255,252,0,0,0,224,44,219,118,11,111,230,202,242,225,247,77,199,90,117,224,243,135,229,169,243,110,250,156,169,
153,164,198,222,29,81,106,58,185,120,206,195,45,10,31,110,209,244,229,9,197,71,98,26,127,119,88,211,87,39,87,236,235,11,251,245,236,87,94,222,244,107,215,186,103,254,221,199,215,117,92,54,145,209,192,
119,111,105,246,230,76,105,223,204,149,73,117,60,179,103,187,74,219,113,34,183,102,52,116,190,79,61,175,244,170,227,185,46,245,188,210,187,172,253,196,111,156,89,247,185,246,126,250,128,98,131,81,229,
51,27,159,27,195,74,166,207,44,123,223,86,232,250,228,1,205,13,93,178,221,40,22,195,109,168,251,179,7,173,46,3,0,0,0,14,179,109,1,192,195,147,243,73,122,236,139,127,73,202,196,50,154,122,111,172,180,93,
183,187,94,237,231,118,43,62,28,83,124,36,166,200,173,202,107,180,99,145,39,228,85,207,231,143,104,246,230,143,75,251,146,83,73,11,43,178,143,84,100,65,145,91,51,138,15,45,62,122,50,55,20,85,209,181,24,
68,249,155,3,154,190,58,169,108,34,171,142,115,235,159,92,49,216,86,167,19,95,62,163,161,239,247,43,62,16,81,33,95,219,147,7,24,166,75,141,7,154,213,253,185,94,249,194,126,171,203,81,104,79,189,142,255,
218,147,26,58,223,167,196,104,220,234,114,214,165,190,171,65,61,159,63,162,64,107,208,234,82,0,0,0,224,48,219,22,0,60,122,71,243,113,47,254,31,22,62,216,164,142,231,246,202,223,28,144,36,237,126,161,75,
173,167,218,116,239,123,253,74,78,61,120,236,224,232,23,159,144,105,227,103,132,183,139,55,180,252,107,145,207,228,44,170,196,94,146,147,73,13,157,239,43,109,71,110,78,43,114,115,90,254,70,191,252,205,
1,141,189,51,172,228,68,66,109,79,118,200,220,192,234,10,193,246,144,142,125,241,9,21,139,69,21,82,181,61,18,192,240,155,114,185,92,86,151,177,76,253,222,70,157,252,205,167,148,75,231,148,75,102,173,46,
103,85,238,160,71,110,159,245,115,39,0,0,0,192,153,108,249,155,168,167,222,167,112,111,115,105,59,216,22,82,176,77,26,125,251,222,178,227,30,62,6,216,42,245,221,97,181,28,109,213,236,173,251,138,13,110,
221,68,148,46,151,75,230,74,171,12,96,93,220,62,55,23,215,0,0,0,192,42,108,245,219,114,168,171,65,79,254,206,199,20,185,57,163,159,252,251,127,80,215,39,186,181,231,165,238,82,251,161,255,249,152,242,
217,197,59,168,181,117,143,18,59,73,168,35,164,142,231,186,148,154,75,109,105,0,0,0,0,0,0,219,201,86,1,128,203,144,76,191,91,46,183,75,197,92,65,185,84,78,153,68,70,110,159,91,134,199,144,225,53,36,211,
37,79,157,167,230,134,41,3,0,0,0,0,96,37,91,5,0,241,123,49,93,255,198,229,210,246,248,143,134,53,254,163,97,29,124,245,152,118,157,110,215,173,111,94,83,124,40,170,51,111,62,39,95,216,183,198,217,138,
146,92,50,189,134,114,54,155,65,124,137,203,109,200,101,50,199,1,0,0,0,0,96,109,182,10,0,150,120,234,60,242,53,5,148,158,75,43,27,79,111,242,44,139,35,4,26,122,154,52,123,253,254,214,21,87,69,141,251,
195,60,235,96,129,233,171,147,154,27,138,150,190,247,6,191,215,167,225,31,14,150,150,167,4,0,0,0,128,90,100,203,219,199,225,67,45,58,249,198,89,181,159,237,124,236,115,237,251,228,126,91,78,28,102,120,
76,117,127,246,144,213,101,56,82,118,62,171,228,68,66,217,249,197,25,231,211,145,148,146,19,9,21,108,58,146,4,0,0,0,128,51,216,239,202,119,139,249,91,131,58,241,198,89,221,251,222,93,69,7,34,42,214,248,
69,156,97,186,84,191,63,172,125,159,238,85,160,37,96,117,57,120,200,137,95,63,173,96,91,72,166,223,241,63,86,0,0,0,0,106,16,87,42,146,2,187,130,58,242,171,167,36,73,249,133,156,197,213,172,206,244,187,
25,246,111,17,195,116,201,244,153,42,230,139,43,222,237,207,196,51,50,124,105,5,125,110,49,7,37,0,0,0,128,90,99,203,0,32,57,53,175,209,119,238,41,62,188,184,4,91,244,206,180,50,137,180,50,177,212,99,159,
155,117,216,81,73,248,80,179,158,254,253,151,52,126,113,68,67,231,251,202,218,239,124,235,186,36,233,233,223,123,145,239,35,0,0,0,0,53,199,150,87,41,243,99,113,205,143,197,75,219,51,215,238,107,230,154,
61,39,242,131,125,100,18,25,37,70,226,90,152,98,178,63,0,0,0,0,246,99,203,0,160,146,206,231,246,202,223,18,144,59,184,163,222,22,106,68,98,36,174,219,223,188,98,117,25,0,0,0,0,176,41,59,234,74,185,233,
72,171,26,122,26,173,46,3,59,92,176,35,164,198,238,112,197,118,151,199,150,139,107,0,0,0,0,216,225,118,84,0,208,247,237,235,50,60,166,142,255,218,105,121,235,189,86,151,131,29,170,177,59,172,238,207,245,
90,93,6,0,0,0,0,108,200,142,10,0,50,115,105,73,82,49,95,180,184,18,0,0,0,0,0,106,11,99,149,1,0,0,0,0,112,0,91,141,0,112,185,13,121,66,149,135,246,231,23,178,42,112,247,31,219,44,114,103,70,169,185,202,
75,78,30,250,194,49,25,30,179,138,21,1,0,0,0,192,218,108,21,0,212,239,109,208,83,191,251,124,197,246,107,95,191,172,248,80,180,138,21,193,137,82,179,11,74,205,46,84,108,47,230,138,146,167,138,5,1,0,0,
0,192,58,240,8,0,0,0,0,0,0,14,64,0,0,108,177,92,58,175,124,58,111,117,25,0,0,0,0,176,140,173,30,1,200,206,103,52,55,80,121,136,127,110,62,83,197,106,224,84,109,231,118,171,251,83,7,42,182,95,122,235,162,
138,42,234,233,223,127,169,138,85,1,0,0,0,192,234,108,21,0,44,76,37,213,247,173,235,86,151,1,135,43,164,115,74,125,180,228,228,74,138,69,73,174,234,213,3,0,0,0,0,235,97,171,0,96,45,173,167,218,228,109,
244,203,237,103,6,118,108,159,233,43,83,154,190,50,181,234,49,166,143,239,65,0,0,0,0,181,101,71,5,0,109,79,237,81,67,79,163,213,101,0,0,0,0,0,80,115,108,17,0,100,19,25,245,125,231,166,60,65,143,246,127,
254,112,105,127,244,214,140,34,119,102,44,172,12,0,0,0,0,0,123,176,69,0,80,200,22,52,215,55,171,134,158,176,218,207,237,46,237,207,198,51,4,0,168,186,96,71,72,141,221,225,85,143,113,121,88,96,3,0,0,0,
64,109,177,69,0,240,168,200,141,105,13,253,160,95,185,228,242,89,255,251,190,125,93,134,199,212,241,95,59,45,111,189,215,162,234,176,211,53,118,135,213,253,185,94,171,203,0,0,0,0,128,13,177,101,0,144,
75,229,148,154,78,150,237,207,124,52,51,123,49,95,172,118,73,112,128,96,123,80,61,175,244,42,216,25,90,177,125,232,127,220,85,42,178,160,67,95,56,38,195,195,36,128,0,0,0,0,106,139,45,3,128,37,123,62,222,
173,61,47,117,151,182,111,252,127,63,87,252,94,212,194,138,176,147,249,155,2,234,120,174,171,98,251,220,64,68,201,137,132,138,185,162,228,169,98,97,0,0,0,0,176,14,182,14,0,92,134,75,198,195,207,90,179,
246,58,0,0,0,0,0,43,98,166,50,0,0,0,0,0,28,192,86,35,0,242,233,188,226,35,49,165,34,11,146,164,76,44,163,248,72,236,65,123,38,103,85,105,112,144,169,247,198,52,116,161,191,108,127,225,163,239,191,75,111,
93,148,25,48,117,230,205,231,170,93,26,0,0,0,0,84,100,171,0,96,126,60,174,107,95,253,160,180,61,245,193,152,166,62,24,179,176,34,56,73,177,80,84,62,155,87,46,149,83,62,85,57,108,202,165,115,42,138,137,
40,1,0,0,0,212,22,91,4,0,134,215,84,203,201,54,101,231,51,138,13,48,201,31,172,17,185,61,171,219,223,188,98,117,25,0,0,0,0,176,41,182,8,0,60,117,30,29,122,253,184,98,3,81,93,31,184,108,117,57,112,56,119,
208,35,111,189,175,108,127,106,38,169,66,174,160,192,174,58,185,253,182,248,209,2,0,0,0,224,32,182,186,74,241,134,125,218,253,226,62,37,39,19,138,222,153,45,107,111,61,213,38,111,163,95,110,63,107,176,
99,251,236,58,213,174,238,207,245,150,237,255,249,31,190,167,228,68,66,39,127,227,140,204,128,173,126,180,0,0,0,0,56,128,173,174,82,252,77,1,237,251,244,1,221,191,52,177,98,0,208,246,212,30,53,244,52,
90,80,25,0,0,0,0,0,181,205,86,1,64,114,50,161,161,239,247,43,27,75,175,216,126,239,251,119,101,6,220,234,125,237,168,60,117,222,42,87,7,0,0,0,0,64,237,178,85,0,144,75,230,52,215,87,126,231,127,73,98,116,
113,73,192,66,150,25,216,177,245,252,205,126,117,62,211,165,250,10,163,76,90,79,181,43,219,29,150,203,99,84,185,50,0,0,0,0,88,155,173,2,128,37,77,199,90,181,239,83,7,52,249,147,81,77,252,108,84,123,63,
125,64,205,71,91,117,247,219,55,148,24,141,91,93,30,118,168,96,91,221,138,207,254,47,217,253,194,222,42,86,3,0,0,0,0,27,99,203,91,149,110,159,91,129,214,160,220,65,143,36,201,27,242,41,208,26,148,203,
205,228,127,0,0,0,0,0,172,196,150,1,0,0,0,0,0,0,216,152,29,17,0,228,210,89,101,18,25,41,95,176,186,20,0,0,0,0,0,106,146,45,231,0,120,212,208,223,244,105,232,111,250,172,46,3,0,0,0,0,128,154,101,171,0,
192,244,155,10,117,53,200,223,28,88,177,61,176,43,40,211,231,150,203,237,170,114,101,0,0,0,0,0,212,54,91,5,0,117,157,245,58,249,198,217,138,237,251,127,233,136,26,42,44,209,6,0,0,0,0,128,147,217,42,0,
120,84,176,61,168,150,147,109,165,109,79,200,99,97,53,0,0,0,0,0,212,46,91,7,0,205,199,219,212,124,188,109,237,3,1,0,0,0,0,112,184,29,177,10,0,0,0,0,0,0,88,29,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,
0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,184,173,46,0,176,139,196,104,76,163,111,223,219,80,31,95,147,95,61,175,244,110,83,69,0,0,0,0,176,126,4,0,192,58,101,226,89,69,110,
78,111,168,79,176,61,180,77,213,0,0,0,0,192,198,240,8,0,0,0,0,0,0,14,192,8,0,192,98,169,200,130,70,254,118,64,177,129,168,242,249,130,213,229,172,202,52,13,53,236,111,210,222,79,237,151,47,236,183,186,
28,0,0,0,0,27,64,0,0,108,80,219,185,221,234,254,212,129,85,143,201,165,243,186,244,214,187,107,158,43,53,187,160,171,95,253,64,185,100,118,171,202,219,86,121,73,211,87,38,53,215,63,171,19,111,156,149,
191,41,96,117,73,0,0,0,0,214,137,71,0,128,13,114,73,42,26,146,225,53,100,6,220,101,127,100,184,228,50,138,235,58,215,189,11,3,182,185,248,127,88,118,62,171,225,31,244,91,93,6,0,0,0,128,13,96,4,0,176,65,
147,239,141,105,242,189,49,245,188,210,171,142,231,186,202,218,63,248,15,239,42,159,202,173,235,92,177,187,179,91,93,94,213,68,251,34,86,151,0,0,0,0,96,3,8,0,128,117,114,251,77,5,219,67,202,37,51,202,
196,51,74,39,210,154,159,152,47,63,176,32,185,92,46,5,218,234,20,104,93,125,136,124,46,189,190,160,160,22,173,55,228,0,0,0,0,80,27,8,0,128,117,106,232,9,235,137,223,62,167,241,139,35,26,58,223,167,241,
31,13,107,252,71,195,43,30,107,250,76,61,241,219,231,170,92,33,0,0,0,0,84,70,0,0,108,144,191,57,160,166,35,173,90,152,154,87,42,178,80,214,30,238,109,145,219,207,143,22,0,0,0,128,218,194,85,10,176,65,
77,135,91,212,116,184,69,131,231,251,52,113,113,164,172,253,208,23,142,45,78,6,8,0,0,0,0,53,132,171,20,96,131,226,67,81,205,220,152,86,108,40,186,108,127,235,201,118,121,234,60,114,121,88,92,3,0,0,0,64,
237,33,0,112,168,222,215,142,90,93,130,109,37,198,19,43,222,249,223,253,194,94,5,59,67,22,84,4,0,0,0,0,107,35,0,144,148,142,166,52,252,183,3,138,245,71,148,207,23,172,46,103,85,134,105,168,177,39,172,
174,79,238,151,191,121,245,25,230,87,211,250,100,199,22,86,229,12,137,209,152,70,223,190,167,244,108,106,197,246,193,239,245,201,244,185,117,232,11,199,100,120,204,42,87,7,0,0,0,0,171,115,124,0,144,142,
166,116,245,171,31,40,155,200,88,93,202,186,228,37,77,95,157,82,228,238,172,78,125,249,172,252,173,193,117,247,141,223,139,106,242,253,137,85,143,113,185,138,58,248,234,177,199,172,114,103,202,196,179,
138,220,156,174,216,30,27,88,124,36,160,152,43,74,158,106,85,5,0,0,0,0,235,227,248,0,96,248,7,253,182,185,248,127,88,126,33,167,123,23,238,234,240,175,156,90,119,159,212,76,74,211,31,174,30,0,72,34,0,
88,67,235,201,118,237,126,97,175,198,126,60,172,233,43,147,234,126,229,160,26,123,154,116,251,207,174,43,53,157,180,186,60,0,0,0,0,88,145,227,3,128,185,254,232,218,7,213,168,104,95,68,42,74,114,173,126,
92,114,60,161,129,243,125,202,206,175,47,232,184,246,245,203,242,214,123,117,232,245,227,143,95,228,14,228,169,243,40,216,25,146,187,110,241,54,191,63,28,80,176,51,36,195,205,228,127,0,0,0,0,106,151,227,
3,128,92,58,103,117,9,155,86,200,21,84,204,23,228,90,227,194,51,151,202,41,62,180,254,160,35,62,20,149,47,236,127,220,242,0,0,0,0,0,53,196,241,1,128,147,180,156,216,165,125,159,233,93,243,184,75,111,189,
91,133,106,118,142,124,46,191,24,36,21,173,174,4,0,0,0,0,42,35,0,112,16,195,99,202,23,246,173,126,16,23,177,27,214,247,103,55,54,221,215,244,154,202,103,242,91,88,77,245,152,94,254,249,0,0,0,0,236,132,
135,150,29,108,226,221,17,93,122,235,93,101,227,105,171,75,177,5,183,223,84,176,61,36,79,253,202,33,138,191,37,168,96,123,72,218,192,10,128,13,61,225,45,170,174,250,26,14,218,183,118,0,0,0,192,137,184,
133,231,32,249,76,65,233,72,74,238,128,91,166,223,173,92,58,167,116,52,173,98,97,177,61,19,75,169,104,207,155,209,85,209,208,19,214,19,191,125,174,98,251,225,215,143,43,216,25,218,208,57,247,126,250,128,
98,131,81,219,141,2,48,125,166,122,94,89,251,113,18,0,0,0,0,181,131,0,192,65,102,175,79,105,246,250,148,186,94,238,81,215,203,61,101,237,87,191,118,73,153,57,70,3,84,146,138,44,40,114,107,70,161,206,144,
234,187,195,10,182,215,169,233,72,107,169,221,244,47,254,56,77,189,55,166,162,164,246,115,187,215,60,103,176,173,78,39,190,124,70,67,223,239,87,124,32,162,66,190,182,159,193,48,76,151,26,15,52,171,251,
115,189,76,20,9,0,0,0,216,12,1,128,3,184,3,110,53,244,132,149,77,100,180,240,208,58,245,13,61,77,234,250,5,201,240,47,31,179,222,208,19,150,55,180,198,92,1,14,148,156,76,106,232,124,159,58,159,233,82,
125,119,88,109,103,58,213,118,166,179,236,184,161,11,253,82,177,184,174,0,64,146,130,237,33,29,251,226,19,42,22,139,42,164,106,123,36,128,225,55,229,114,173,177,238,36,0,0,0,128,154,68,0,224,0,193,142,
144,142,127,233,180,238,95,154,208,221,191,184,89,218,223,208,211,168,134,158,198,178,227,143,127,233,116,53,203,179,157,185,161,168,6,207,247,85,108,47,228,10,50,204,141,95,36,187,92,46,153,1,126,36,
1,0,0,0,108,15,174,54,28,40,54,24,209,200,223,61,216,222,117,166,83,190,176,79,45,39,219,148,75,102,173,43,204,38,146,19,9,37,39,18,171,31,100,110,96,38,64,0,0,0,0,168,2,2,0,7,138,13,206,41,54,56,87,218,
110,216,223,36,95,216,167,238,207,28,180,176,42,0,0,0,0,192,118,34,0,112,128,133,233,164,70,223,190,167,244,236,194,138,237,163,239,12,105,234,146,87,61,175,28,148,59,232,169,114,117,0,0,0,0,128,106,32,
0,112,128,108,60,163,233,15,39,42,182,207,245,205,74,146,246,254,194,126,185,131,213,170,202,190,90,79,182,107,247,11,123,87,63,200,168,78,45,0,0,0,0,176,94,14,14,0,138,146,92,50,189,134,114,185,130,213,
197,108,138,203,109,200,101,174,255,74,51,220,219,162,221,47,238,211,253,203,99,186,127,121,82,123,94,236,86,99,111,179,134,206,223,214,252,196,252,54,86,186,179,152,126,83,222,102,191,204,13,126,254,
0,0,0,0,96,37,7,95,189,44,206,210,222,208,211,100,113,29,155,215,184,63,188,244,54,214,197,19,242,168,161,167,81,190,198,128,36,201,223,26,84,67,79,163,12,31,195,254,215,35,124,168,89,79,255,222,139,242,
134,253,122,239,255,120,71,147,63,29,179,186,36,0,0,0,0,88,55,7,7,0,139,246,125,114,191,220,62,251,13,132,48,60,166,186,63,123,200,234,50,28,165,152,43,40,53,151,86,62,181,184,82,66,58,145,214,252,196,
188,242,233,188,36,41,53,147,212,252,196,188,138,246,28,80,2,0,0,0,96,135,115,124,0,224,111,13,234,196,27,103,213,116,168,69,46,119,237,127,28,134,233,82,99,111,147,78,124,249,172,2,45,129,199,63,97,241,
241,79,225,20,115,3,81,93,249,195,159,105,236,157,97,73,210,248,143,134,117,229,15,127,166,88,127,68,146,116,251,79,175,235,202,31,254,76,133,116,206,202,50,1,0,0,0,96,69,246,187,245,189,13,2,187,130,
58,242,171,167,36,73,249,133,218,190,120,51,253,238,13,13,251,95,205,221,239,220,208,221,239,220,216,154,147,57,136,191,41,160,64,91,157,22,166,230,149,138,172,188,178,2,0,0,0,0,212,26,2,128,71,152,129,
157,247,145,184,60,134,124,97,191,60,117,43,63,235,239,13,121,229,114,27,50,204,42,23,102,83,77,135,91,212,253,185,94,13,158,239,211,196,197,17,171,203,1,0,0,0,128,117,217,121,87,187,40,83,223,213,160,
51,111,62,91,177,189,247,245,19,106,232,105,172,98,69,0,0,0,0,128,106,35,0,112,128,76,34,163,185,59,179,165,237,249,137,196,178,246,104,223,140,210,145,5,181,156,220,37,195,195,48,0,0,0,0,0,216,137,8,
0,28,32,117,63,169,187,127,113,179,98,251,216,59,247,36,73,13,251,155,228,11,19,0,172,101,110,40,170,193,243,125,138,13,69,37,73,83,151,38,52,55,20,85,54,158,182,184,50,0,0,0,0,168,140,0,0,216,160,228,
68,66,201,135,70,81,68,110,79,91,88,13,0,0,0,0,172,15,1,0,176,69,186,95,57,40,127,56,32,151,151,81,20,0,0,0,0,106,15,1,128,3,248,119,5,117,240,213,99,21,219,71,223,25,82,106,58,89,197,138,118,166,198,
158,38,5,59,67,86,151,1,0,0,0,0,43,34,0,112,0,111,200,171,93,167,219,43,182,79,93,26,39,0,88,197,194,253,121,93,253,218,37,53,236,109,212,19,255,236,92,105,255,216,143,135,53,125,101,178,180,125,237,235,
151,37,67,58,243,191,61,43,183,143,31,45,0,0,0,0,181,133,171,20,96,13,133,188,148,79,229,36,195,165,96,103,72,197,124,65,249,92,65,166,127,249,80,255,124,38,39,73,114,21,172,168,18,0,0,0,0,86,71,0,0,108,
208,196,207,198,52,116,190,207,234,50,0,0,0,0,96,67,8,0,28,32,62,18,211,157,63,189,86,177,61,59,159,173,98,53,59,135,183,222,43,119,208,91,222,192,28,128,0,0,0,0,106,16,1,128,3,20,179,5,101,230,214,94,
163,222,229,170,66,49,59,200,238,231,247,169,227,185,46,171,203,0,0,0,0,128,117,33,0,128,142,127,233,140,26,122,26,173,46,163,230,101,19,25,205,222,156,209,194,20,19,38,2,0,0,0,176,31,2,0,7,112,121,12,
249,194,254,138,237,169,233,121,169,88,84,253,222,6,185,220,70,21,43,179,151,196,104,76,183,191,121,197,234,50,0,0,0,0,96,83,8,0,28,160,190,171,65,103,222,124,182,98,251,181,175,95,86,124,40,170,51,111,
62,39,95,216,87,197,202,236,193,83,231,81,231,51,93,74,69,22,20,185,61,83,218,63,55,20,85,113,133,199,38,58,206,237,38,72,1,0,0,0,80,115,8,0,128,53,120,235,189,234,254,92,175,102,111,206,44,11,0,34,55,
167,21,185,57,93,118,124,219,147,29,50,9,0,0,0,0,0,212,24,174,82,128,117,10,182,7,213,243,74,175,154,142,182,90,93,10,0,0,0,0,108,24,35,0,28,36,57,145,208,236,141,242,59,214,153,185,5,73,210,196,197,97,
153,126,183,186,94,238,169,114,101,246,224,111,10,168,227,185,46,21,93,90,241,206,63,0,0,0,0,212,50,2,0,7,153,31,79,104,228,135,131,21,219,199,47,142,72,18,1,192,26,154,14,183,200,223,88,121,82,69,151,
215,172,98,53,0,0,0,0,176,62,4,0,14,176,48,157,212,232,219,247,148,158,93,176,186,148,29,193,223,28,144,191,57,96,117,25,0,0,0,0,176,33,4,0,14,144,141,103,52,253,225,132,213,101,0,0,0,0,0,44,68,0,224,
32,225,222,22,237,126,113,95,217,254,161,243,183,53,63,49,175,67,175,159,144,183,222,99,65,101,0,0,0,0,128,237,70,0,224,32,158,144,71,13,61,141,101,251,13,223,226,69,127,168,171,65,190,176,175,218,101,
1,0,0,0,0,170,128,101,0,1,0,0,0,0,112,0,70,0,56,129,107,241,63,133,108,94,233,72,170,172,185,152,47,44,30,230,170,102,81,0,0,0,0,128,106,34,0,112,128,134,158,176,158,253,202,203,186,127,105,66,151,254,
159,139,101,237,199,191,116,102,197,71,3,0,0,0,0,0,59,7,1,128,3,228,83,57,205,143,39,180,48,51,191,98,123,114,34,46,21,139,170,223,219,32,151,155,167,66,0,0,0,0,96,39,34,0,112,128,249,241,132,174,127,
227,114,197,246,193,243,125,146,164,51,111,62,199,36,128,0,0,0,0,176,67,113,187,215,65,252,205,1,237,58,221,161,96,71,72,146,84,191,47,172,93,167,59,228,9,121,45,174,12,0,0,0,0,176,221,8,0,28,164,126,
95,163,14,190,122,84,205,71,90,37,73,109,103,59,117,240,213,163,242,183,4,45,174,12,0,0,0,0,176,221,8,0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,73,0,29,108,234,253,49,205,13,68,148,154,73,90,93,10,0,0,0,
0,96,155,17,0,56,88,124,120,78,241,225,57,171,203,0,0,0,0,0,84,1,1,128,3,4,119,135,116,252,75,103,228,13,121,86,108,239,254,92,175,234,218,235,43,182,3,0,0,0,0,236,143,0,192,1,220,62,183,26,186,27,23,
55,138,229,237,117,237,245,139,237,174,234,214,5,0,0,0,0,168,30,2,0,7,136,13,68,117,253,27,151,43,182,95,255,163,75,146,164,51,111,62,39,95,216,87,173,178,96,115,197,98,81,133,108,161,180,109,152,46,185,
204,7,243,138,22,178,5,21,139,15,18,39,211,107,86,181,62,0,0,0,0,203,17,0,96,71,50,60,198,195,55,201,89,0,0,23,221,73,68,65,84,178,139,211,66,182,32,195,195,162,23,91,105,126,44,161,171,255,233,253,210,
118,231,11,123,213,253,153,131,165,237,219,127,114,85,209,59,179,165,237,143,253,219,151,100,120,8,1,30,87,33,155,95,182,205,103,10,0,0,128,245,34,0,192,142,228,109,240,47,91,221,32,54,20,85,184,183,217,
194,138,176,164,144,43,40,53,187,80,218,246,4,61,242,132,188,146,164,116,52,173,124,38,87,106,11,238,170,171,169,71,83,50,137,140,114,201,108,105,59,208,28,144,203,93,221,96,41,54,184,124,226,78,111,35,
163,118,0,0,0,176,62,4,0,14,224,14,184,213,208,19,174,216,158,28,79,40,151,206,85,108,183,163,198,253,225,101,1,192,189,11,253,106,232,14,51,10,160,6,36,39,231,43,142,28,24,248,171,91,53,61,106,96,244,
135,131,154,252,217,88,105,251,201,127,249,180,2,187,234,170,246,250,133,108,94,247,46,244,47,219,215,184,191,242,207,54,0,0,0,240,48,2,0,7,8,118,132,116,252,75,167,43,182,95,251,250,101,197,135,162,85,
172,104,251,237,58,211,169,201,247,199,74,147,30,38,39,18,186,250,181,15,180,239,211,251,63,10,2,106,231,162,210,105,76,191,91,77,135,90,74,219,193,214,205,95,64,39,167,230,149,142,166,86,61,198,237,119,
171,126,95,227,186,251,185,76,67,225,131,77,146,22,239,248,207,143,197,75,109,153,104,122,217,177,177,193,57,165,34,169,53,251,61,170,161,39,188,161,57,17,10,217,188,98,131,115,186,119,161,95,201,201,
196,67,197,74,109,103,58,215,125,30,0,0,0,56,27,1,0,118,164,208,158,122,181,62,209,161,233,15,39,74,251,146,19,9,221,252,47,87,44,172,106,103,8,237,169,215,201,223,124,106,211,253,3,45,1,29,249,213,83,
91,82,203,228,207,70,151,221,145,95,73,221,238,122,157,250,173,229,245,174,214,207,29,244,232,220,191,121,65,146,20,31,154,211,157,63,189,86,241,220,3,127,117,123,83,253,30,29,57,240,211,255,253,237,178,
103,251,215,99,215,147,29,170,219,93,191,225,126,0,0,0,112,38,2,0,236,88,7,62,127,88,169,233,164,18,163,49,171,75,129,22,39,98,156,186,52,81,182,191,174,179,94,245,123,27,86,236,51,249,222,216,178,149,
5,36,201,223,28,168,56,159,67,235,201,118,185,3,139,255,172,21,242,5,77,125,48,174,236,124,70,19,63,29,93,214,175,161,187,73,174,21,38,23,152,124,127,76,197,92,65,19,63,29,149,167,206,171,64,115,64,29,
79,239,41,181,199,134,230,148,156,122,112,7,254,225,215,51,125,166,178,243,25,205,92,187,175,228,248,226,49,193,206,144,26,186,30,140,62,136,220,153,86,58,154,214,244,207,167,228,169,247,170,253,220,110,
185,140,205,77,114,16,234,106,208,254,95,58,188,169,190,0,0,0,112,38,2,0,7,139,220,152,214,252,68,66,153,185,133,181,15,182,33,195,99,232,248,151,78,171,255,187,183,53,253,243,137,210,227,0,176,70,62,
147,215,224,95,223,41,219,223,249,194,222,138,1,192,208,255,184,91,182,175,249,120,91,197,0,96,207,39,246,149,238,172,103,231,179,154,250,96,92,153,185,180,6,255,250,206,178,126,45,39,119,169,229,228,
174,178,254,83,151,199,75,117,46,141,28,232,249,165,67,165,246,129,191,186,189,44,0,120,248,245,36,41,49,26,95,246,30,27,15,52,45,91,25,33,245,95,23,148,142,166,53,250,246,144,36,169,237,76,135,92,198,
6,31,71,113,73,187,78,119,104,255,63,58,204,156,22,0,0,0,216,16,2,0,7,155,185,57,189,108,136,252,78,100,120,12,245,190,118,84,157,207,236,209,212,7,19,154,27,140,40,51,151,90,182,68,32,170,195,244,154,
234,254,204,65,101,226,105,141,95,28,89,87,159,189,159,218,47,195,88,188,200,93,234,151,156,76,104,232,123,119,87,157,216,82,90,188,35,255,240,197,183,127,87,160,244,247,200,141,105,197,134,231,202,250,
20,243,229,41,81,118,62,163,236,124,70,193,182,80,197,215,154,235,143,168,241,64,211,154,239,103,179,12,143,33,111,163,95,141,61,77,106,59,203,176,127,0,0,0,108,14,1,0,180,231,197,110,249,91,131,242,212,
237,220,111,135,186,221,245,218,207,69,147,165,12,143,161,206,23,246,42,49,26,95,119,0,208,249,108,87,105,194,198,165,126,169,153,164,198,127,156,92,115,121,64,195,189,248,122,43,137,246,207,174,57,119,
192,18,79,157,87,158,58,239,170,199,60,238,197,255,199,254,237,75,143,213,31,0,0,0,88,143,157,123,197,135,117,107,236,109,86,67,79,227,218,7,2,15,9,52,7,116,248,151,143,43,62,28,215,248,187,195,138,220,
156,81,58,242,96,102,253,165,231,224,123,62,219,43,111,131,87,46,211,250,149,23,34,183,166,117,255,195,73,37,39,22,107,219,243,98,183,234,118,63,24,194,127,231,207,111,170,152,99,116,8,0,0,0,118,38,2,
0,7,235,122,105,159,218,206,116,42,216,89,189,117,204,177,115,152,1,183,154,143,183,169,88,92,188,21,159,154,73,42,53,147,44,59,174,241,96,211,178,231,228,173,180,48,189,160,217,235,247,75,219,161,238,
134,101,75,18,186,190,125,147,169,34,0,0,0,176,99,17,0,56,152,191,53,40,127,171,213,85,192,238,194,7,154,116,234,183,158,210,244,135,147,26,255,201,131,161,253,221,159,237,85,195,190,70,249,194,139,207,
222,231,83,57,93,255,127,63,84,33,179,124,185,187,233,15,39,21,27,136,106,247,11,251,202,206,125,245,63,95,146,203,181,24,48,44,245,107,60,208,164,125,159,62,32,79,200,91,154,76,111,189,118,61,217,174,
198,253,97,141,253,232,158,102,174,221,215,208,223,244,105,228,239,6,75,237,197,220,234,151,255,123,94,236,86,219,153,78,13,254,77,159,226,195,115,186,253,39,215,75,19,241,185,253,110,29,249,95,78,233,
212,111,61,165,185,254,136,238,93,232,47,189,183,37,233,153,197,9,55,15,189,126,66,254,102,191,92,110,38,241,3,0,0,64,245,16,0,56,212,245,63,186,180,108,251,248,151,206,88,84,9,236,206,12,184,85,23,168,
215,220,67,23,186,146,228,111,9,44,155,172,174,144,47,106,126,44,94,214,63,155,200,44,254,73,102,202,218,150,30,35,88,246,122,126,207,166,39,193,243,132,188,242,132,188,114,7,61,146,164,212,236,198,86,
192,240,54,250,228,109,244,201,244,47,62,206,176,112,127,190,212,230,14,122,100,120,12,213,237,174,87,234,163,71,33,150,222,219,163,130,237,193,154,25,21,1,0,0,0,231,32,0,112,168,216,96,249,12,232,192,
227,232,120,102,143,218,206,116,148,182,13,223,242,127,94,60,65,143,206,253,155,23,42,246,55,60,166,118,61,209,161,98,126,245,103,240,93,238,7,179,255,117,255,226,65,237,253,133,253,165,109,211,239,89,
87,173,143,246,91,145,89,121,150,193,67,175,159,40,175,243,161,195,155,143,182,172,250,94,215,91,39,0,0,0,176,149,8,0,0,108,9,195,109,200,88,109,72,187,75,165,59,239,171,91,255,100,129,134,199,44,173,
18,176,17,155,237,183,196,244,153,90,173,78,151,105,200,29,100,120,63,0,0,0,106,11,191,161,2,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,182,90,5,32,19,
207,40,114,235,254,134,250,152,62,183,90,79,181,111,83,69,0,0,0,0,0,216,131,173,2,128,212,116,82,3,223,189,179,161,62,190,176,159,0,0,0,0,0,0,224,120,182,10,0,182,75,58,154,210,240,223,14,40,214,31,81,
62,95,176,186,156,85,25,166,161,198,158,176,186,62,185,95,254,230,128,213,229,0,0,0,0,0,108,194,241,1,64,58,154,210,213,175,126,160,108,34,99,117,41,235,146,151,52,125,117,74,145,187,179,58,245,229,179,
242,183,6,173,46,9,0,0,0,0,96,3,182,12,0,26,122,194,106,63,183,123,205,227,238,124,235,250,154,199,12,255,160,223,54,23,255,15,203,47,228,116,239,194,93,29,254,149,83,86,151,2,0,0,0,0,176,1,91,6,0,190,
176,95,45,39,219,86,63,168,184,190,0,96,174,63,186,69,85,85,95,180,47,34,21,37,185,172,174,4,0,0,0,0,80,235,108,25,0,68,110,207,232,234,127,250,64,109,79,117,170,237,108,103,89,251,237,111,94,81,38,158,
93,215,185,114,233,220,86,151,87,53,133,92,65,197,124,65,46,55,171,57,2,0,0,0,0,86,103,203,0,32,151,204,42,145,204,42,124,168,121,197,246,196,120,66,153,185,116,149,171,2,0,0,0,0,160,118,217,42,0,8,237,
107,212,83,191,251,188,166,175,78,105,232,124,159,198,126,52,172,201,159,141,149,29,151,75,46,222,253,127,234,119,159,151,203,96,124,60,0,0,0,0,0,182,10,0,12,211,37,35,228,149,39,224,145,225,54,84,204,
23,148,157,207,151,29,231,114,27,50,228,146,39,228,181,160,74,0,0,0,0,0,106,143,173,2,128,37,173,79,182,171,245,201,118,141,252,221,160,70,126,56,88,214,126,250,119,158,145,47,236,171,126,97,0,0,0,0,0,
212,40,91,6,0,75,220,117,30,5,90,131,202,198,51,202,165,115,242,54,250,100,122,76,185,76,134,253,3,0,0,0,0,240,48,91,7,0,29,31,219,163,142,143,237,81,223,183,111,106,250,195,9,245,190,118,92,13,61,141,
86,151,5,0,0,0,0,64,205,177,85,0,144,137,103,20,185,117,191,108,127,122,38,41,73,154,189,117,95,11,211,9,181,62,209,33,211,107,86,187,60,0,0,0,0,0,106,150,173,2,128,212,116,82,3,223,189,83,177,125,226,
221,17,73,82,184,183,149,0,0,0,0,0,0,128,135,24,86,23,176,29,198,222,25,210,189,11,253,86,151,1,0,0,0,0,64,205,216,145,1,192,228,123,99,26,123,231,158,213,101,0,0,0,0,0,80,51,108,245,8,64,160,45,168,67,
175,31,47,219,63,241,179,49,197,135,162,234,122,185,71,129,214,160,6,254,250,142,114,201,172,5,21,2,0,0,0,0,80,155,108,21,0,120,234,188,106,57,217,86,182,63,114,103,86,241,33,169,161,167,73,13,61,141,
26,250,254,221,117,156,173,40,201,37,211,107,40,151,43,108,121,173,213,224,114,27,114,153,59,114,16,7,0,0,0,0,96,139,57,248,234,209,37,105,49,52,176,171,198,253,225,165,183,1,0,0,0,0,192,170,108,25,0,
20,11,82,33,87,80,177,80,124,236,115,237,251,228,126,185,125,182,26,8,33,73,50,60,166,186,63,123,200,234,50,0,0,0,0,0,54,97,191,43,95,73,211,31,78,232,238,95,220,84,215,203,61,234,122,185,71,251,255,209,
33,117,127,230,128,204,128,71,146,244,196,63,59,167,98,113,125,225,128,191,53,168,19,111,156,213,189,239,221,85,116,32,162,98,141,63,14,96,152,46,213,239,15,107,223,167,123,21,104,9,88,93,14,0,0,0,0,192,
38,108,21,0,20,178,5,165,231,82,202,36,210,146,164,92,50,171,133,233,164,60,245,94,121,66,94,101,230,210,202,103,243,242,55,7,228,50,214,63,54,62,176,43,168,35,191,122,74,146,148,95,200,109,75,237,91,
197,244,187,25,246,15,0,0,0,0,216,48,91,5,0,137,145,152,174,127,227,114,105,123,226,167,163,154,248,233,168,14,190,122,76,187,78,183,235,206,159,223,80,124,40,170,51,111,62,39,95,216,183,169,215,48,3,
182,250,72,0,0,0,0,0,88,23,91,206,1,224,169,247,41,220,219,44,127,51,67,224,1,0,0,0,0,88,15,91,6,0,225,131,77,58,250,197,39,212,122,170,221,234,82,0,0,0,0,0,176,5,91,6,0,0,0,0,0,0,96,99,8,0,0,0,0,0,0,
112,0,91,206,120,55,63,150,208,189,11,119,21,31,138,73,146,102,174,77,106,97,58,161,116,36,101,113,101,0,0,0,0,0,212,38,91,6,0,201,169,132,146,83,137,210,118,244,206,172,162,119,102,45,172,8,0,0,0,0,128,
218,102,203,0,160,146,174,151,123,20,104,13,202,83,231,177,186,20,0,0,0,0,0,106,202,142,10,0,26,122,154,212,208,211,104,117,25,0,0,0,0,0,212,28,91,77,2,88,183,39,164,147,111,156,213,158,143,119,175,216,
126,235,143,175,232,253,255,243,199,202,196,210,85,174,12,0,0,0,0,128,218,102,171,17,0,134,199,84,176,35,164,228,196,252,138,237,249,133,156,242,146,138,133,234,214,5,0,0,0,0,64,173,179,85,0,16,31,156,
211,245,111,92,182,186,12,0,0,0,0,0,108,199,86,1,192,18,183,207,45,79,189,183,98,187,203,116,85,177,26,0,0,0,0,0,106,159,45,3,128,166,99,173,58,248,234,81,171,203,0,0,0,0,0,192,54,108,53,9,32,0,0,0,0,
0,216,28,2,0,0,0,0,0,0,28,192,150,143,0,164,166,147,154,124,111,180,98,123,235,19,29,50,189,102,21,43,2,0,0,0,0,160,182,217,50,0,136,143,196,20,31,137,85,108,15,247,182,18,0,0,0,0,0,0,240,16,30,1,0,0,
0,0,0,192,1,8,0,0,0,0,0,0,112,0,91,62,2,208,208,19,86,251,185,221,21,219,251,255,242,166,242,153,188,78,190,113,182,138,85,1,0,0,0,0,80,187,108,25,0,248,194,126,181,156,108,171,216,62,244,253,187,202,
204,165,171,88,17,0,0,0,0,0,181,205,150,1,192,204,213,41,69,239,204,86,108,207,37,179,85,172,6,0,0,0,0,128,218,103,203,0,160,144,43,168,144,203,88,93,6,0,0,0,0,0,182,193,36,128,0,0,0,0,0,56,128,45,71,
0,184,125,110,121,234,189,86,151,1,0,0,0,0,128,109,216,50,0,104,58,214,170,131,175,30,181,186,12,0,0,0,0,0,108,195,86,143,0,184,131,110,133,123,155,85,215,30,90,177,125,246,230,140,38,223,27,85,62,147,
175,114,101,0,0,0,0,0,212,54,91,141,0,8,182,135,116,244,139,79,84,108,31,127,119,88,241,161,168,194,189,173,50,189,102,21,43,3,0,0,0,0,160,182,217,106,4,0,0,0,0,0,0,216,28,2,0,0,0,0,0,0,28,192,86,143,
0,44,137,13,70,53,249,222,104,217,254,212,244,188,36,105,240,175,111,203,240,154,58,244,250,241,106,151,6,0,0,0,0,64,77,178,101,0,144,142,164,52,115,245,126,197,246,200,237,25,73,34,0,0,0,0,0,0,224,35,
182,10,0,230,199,226,26,248,171,59,202,37,179,86,151,2,0,0,0,0,128,173,216,42,0,200,167,243,74,140,198,172,46,3,0,0,0,0,0,219,177,85,0,176,164,245,100,155,186,63,219,91,182,255,246,55,175,42,62,18,211,
169,223,122,74,222,70,159,5,149,1,0,0,0,0,80,155,108,25,0,184,220,134,60,33,111,121,131,185,184,168,129,59,232,149,167,110,133,118,0,0,0,0,0,28,138,101,0,1,0,0,0,0,112,0,91,141,0,48,188,134,2,173,65,121,
235,87,30,222,239,11,251,148,155,15,202,101,186,170,92,25,0,0,0,0,0,181,205,86,1,64,104,79,131,158,252,157,143,85,108,239,125,237,88,21,171,1,0,0,0,0,192,62,120,4,0,0,0,0,0,0,7,32,0,0,0,0,0,0,192,1,8,
0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,0,0,0,0,0,0,0,7,32,0,0,0,0,0,0,192,1,8,0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,0,0,0,0,0,0,0,7,32,0,0,0,0,0,0,192,1,8,0,0,0,0,0,0,112,128,109,11,0,206,188,249,172,
122,95,59,182,93,167,7,0,0,0,0,0,27,176,109,1,128,47,236,151,59,228,221,174,211,3,0,0,0,0,128,13,112,111,180,195,208,249,62,205,222,156,94,245,152,250,238,70,245,190,118,76,225,131,77,122,246,43,47,107,
234,189,241,77,23,104,39,183,255,228,154,230,199,226,146,36,151,105,232,244,191,250,88,217,49,211,87,167,52,124,161,191,180,221,243,185,94,53,29,105,173,90,141,75,158,253,202,203,186,251,157,27,58,248,
42,163,52,0,0,0,0,192,9,54,28,0,100,19,89,165,163,169,85,143,9,180,4,150,109,27,126,103,76,53,144,141,165,75,159,141,97,186,86,60,166,144,202,47,251,252,242,153,66,85,106,91,137,59,200,8,13,0,0,0,0,112,
138,13,7,0,143,58,251,175,159,151,247,163,161,254,169,217,164,46,255,193,79,21,189,27,209,197,175,252,189,218,206,117,234,192,231,143,168,245,100,251,186,207,55,245,254,184,250,255,251,173,178,253,39,
222,56,171,250,174,134,199,45,183,166,125,240,127,255,88,153,120,70,146,228,111,9,174,56,130,96,51,253,134,127,48,160,209,183,135,74,219,75,159,101,247,47,30,148,36,45,204,44,232,195,63,248,73,169,125,
233,235,6,0,0,0,0,216,57,30,59,0,144,36,173,124,179,91,42,74,249,84,78,185,84,190,180,203,27,242,200,229,126,48,34,32,29,77,151,254,110,120,92,50,124,134,188,141,62,229,83,57,229,211,249,101,231,90,118,
234,66,81,153,88,102,205,210,30,126,189,135,95,235,81,238,128,91,166,207,92,243,124,219,201,219,224,147,140,197,15,211,91,191,158,187,243,69,73,174,101,159,141,75,69,21,178,5,101,231,179,165,125,249,84,
110,89,175,92,60,83,250,44,92,174,197,62,101,167,5,0,0,0,0,236,40,91,19,0,172,98,236,157,97,141,190,243,208,221,231,47,159,85,253,222,197,59,249,197,124,65,151,222,122,183,212,22,62,216,164,163,255,244,
73,181,158,108,215,240,133,129,101,253,30,149,142,44,232,242,31,252,116,205,215,95,122,189,71,95,235,81,123,63,181,95,123,94,234,46,109,247,253,217,117,77,95,153,90,243,252,210,214,141,78,56,249,155,79,
149,237,91,152,89,208,236,141,41,237,121,177,123,133,30,43,39,47,241,161,57,221,248,47,31,86,124,157,91,127,124,181,244,119,195,116,233,137,127,241,244,134,107,5,0,0,0,0,216,203,99,7,0,137,145,57,185,
3,139,119,171,51,241,197,103,219,205,128,91,193,182,144,2,205,65,229,22,114,171,117,223,184,162,20,27,154,43,123,173,74,220,126,83,241,145,152,10,153,197,209,4,134,219,80,221,158,7,23,235,185,68,90,11,
51,11,74,71,83,138,13,206,41,176,43,32,79,221,214,61,27,95,200,21,148,24,137,203,29,52,43,214,153,156,72,44,27,37,33,73,134,199,80,104,79,189,220,190,7,253,210,209,212,138,163,24,10,133,229,243,8,184,
131,110,213,119,135,75,219,233,232,130,50,115,15,250,5,59,66,50,125,139,95,250,149,230,42,200,198,51,138,13,206,149,237,175,235,12,89,62,74,2,0,0,0,0,176,57,143,29,0,220,254,227,107,101,251,234,119,215,
235,232,63,125,82,146,52,124,97,224,113,95,98,153,98,161,160,235,127,116,105,197,215,170,228,131,255,235,199,202,36,22,31,23,240,53,250,116,226,215,79,151,218,166,222,27,87,255,119,111,105,234,253,113,
77,189,63,174,222,47,28,87,235,169,182,45,171,55,51,151,210,245,63,186,84,26,221,176,146,129,239,222,86,124,36,182,108,95,160,37,160,39,255,213,51,242,132,188,106,58,220,82,170,117,181,81,17,75,234,118,
215,47,123,143,143,142,166,216,255,75,135,75,163,48,36,41,53,147,92,214,63,114,123,70,145,219,51,101,231,125,120,244,6,0,0,0,0,192,94,30,59,0,104,57,177,75,46,247,242,187,194,117,109,117,143,123,218,202,
92,134,90,159,236,80,62,157,83,228,230,180,50,241,140,238,95,158,44,59,172,161,187,81,190,38,127,217,254,92,58,191,236,248,248,72,249,157,238,173,80,44,22,117,255,242,164,178,31,5,15,75,117,174,244,122,
225,195,45,242,181,4,53,123,109,74,133,92,249,170,0,11,51,11,74,12,199,148,156,74,72,146,234,247,133,151,189,183,149,250,21,114,5,229,230,179,242,54,250,54,92,123,160,37,160,186,174,198,210,118,252,94,
84,233,72,74,209,59,51,74,205,44,168,229,228,46,25,110,103,172,236,0,0,0,0,0,59,197,99,7,0,221,159,61,180,206,9,235,182,134,203,144,122,95,59,170,212,76,82,145,155,211,74,78,205,235,238,119,110,148,29,
215,251,133,227,43,6,0,217,68,102,197,227,87,234,223,251,133,227,155,174,179,88,208,178,215,169,84,167,36,237,249,248,226,243,253,31,220,157,45,141,84,120,88,124,32,170,254,239,62,88,25,161,253,233,221,
203,70,41,172,212,207,112,27,155,186,248,151,164,250,158,176,14,252,227,7,171,0,244,125,235,134,210,145,148,70,255,97,113,20,65,227,193,166,170,126,205,1,0,0,0,0,143,111,219,39,1,220,46,238,128,71,93,
159,232,41,219,63,55,16,81,252,222,156,102,111,220,87,106,38,169,182,179,157,101,253,58,62,182,167,226,121,131,237,193,45,175,179,227,99,123,148,138,44,104,250,231,229,35,21,0,0,0,0,0,168,6,251,6,0,65,
143,186,126,161,167,108,127,49,95,92,12,0,174,223,215,236,245,251,106,60,216,188,172,221,19,116,175,216,111,187,44,189,222,92,95,132,0,0,0,0,0,0,96,153,109,15,0,154,79,180,202,223,18,208,228,251,99,74,
140,196,52,246,15,67,114,215,121,36,73,197,21,214,155,143,13,206,233,254,229,113,205,143,39,150,237,95,234,215,253,139,7,53,244,189,187,21,95,111,169,95,219,185,221,170,223,211,32,127,115,64,221,159,237,
85,62,147,83,255,95,222,86,38,145,209,221,239,220,92,161,206,93,106,58,212,242,24,239,116,57,151,33,29,248,199,71,101,250,23,231,71,8,180,215,233,224,63,57,170,216,80,164,108,206,130,209,183,135,148,154,
89,80,46,245,96,197,132,165,58,131,109,117,106,58,210,162,131,255,228,168,102,175,223,87,228,206,140,38,223,27,211,220,221,217,210,177,15,247,91,201,106,95,3,151,97,104,247,11,93,91,245,182,1,0,0,0,0,
53,106,219,3,128,186,206,122,213,117,214,107,238,110,68,137,145,152,34,119,202,103,151,127,88,106,58,169,251,151,39,202,246,47,245,235,122,185,103,197,246,71,53,116,135,75,207,201,183,156,108,83,49,95,
80,255,95,222,86,62,157,95,177,191,191,37,176,181,1,128,203,165,93,103,58,74,219,222,122,175,118,157,233,80,49,95,44,11,0,162,183,102,202,86,1,88,170,51,124,176,73,157,207,239,149,191,37,168,212,204,130,
34,119,102,20,31,138,42,190,246,98,0,37,171,125,13,12,211,69,0,0,0,0,0,0,14,224,122,245,173,203,43,220,135,175,108,225,126,178,52,179,189,36,213,239,107,144,203,92,123,70,248,71,251,173,196,12,120,228,
9,121,148,186,159,172,120,76,168,171,65,137,71,46,150,87,18,104,11,202,83,247,208,68,117,69,41,54,24,173,120,188,191,57,176,233,73,243,150,204,143,199,149,79,229,23,55,92,46,53,244,52,150,29,147,73,100,
150,189,191,64,91,80,153,88,250,65,191,71,152,1,143,234,58,22,87,85,72,69,22,148,137,166,87,173,193,240,24,10,117,173,188,84,223,138,95,3,151,75,161,174,122,37,134,31,124,166,222,122,175,252,173,193,138,
253,214,251,53,7,176,179,125,231,205,211,107,31,4,0,0,128,45,243,234,91,151,31,171,255,134,3,0,0,0,36,2,0,0,0,128,106,123,220,0,128,219,184,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,
0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,
0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,
0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,0,0,0,224,0,4,0,0,0,0,0,0,56,0,1,0,0,0,0,0,0,14,64,0,0,0,0,0,0,128,3,16,0,0,0,54,197,237,11,90,93,2,0,0,128,99,184,253,117,143,125,14,
2,0,0,192,166,4,154,58,172,46,1,0,0,192,49,130,77,157,143,125,14,2,0,0,192,166,180,29,121,206,234,18,0,0,0,28,99,43,126,247,34,0,0,0,108,74,247,179,175,202,229,226,127,35,0,0,0,219,205,101,24,234,126,
246,213,199,62,15,191,185,1,0,54,165,161,243,144,122,158,127,221,234,50,0,0,0,118,188,253,47,252,178,234,59,14,62,246,121,8,0,0,0,155,118,234,181,223,85,107,239,57,171,203,0,0,0,216,177,90,15,61,173,147,
175,254,235,45,57,23,1,0,0,96,211,12,183,87,207,255,243,255,168,253,47,254,178,92,6,255,75,1,0,0,216,42,46,195,208,129,151,126,69,207,255,243,255,40,195,244,108,205,57,95,125,235,114,113,75,206,4,0,112,
180,216,120,159,134,46,126,91,83,183,46,106,33,50,174,92,58,105,117,73,0,0,0,182,226,246,5,21,108,222,173,93,71,158,85,207,179,175,109,201,176,255,135,17,0,0,0,0,0,0,224,0,140,215,4,0,0,0,0,192,1,8,0,
0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,0,0,0,0,0,0,0,7,32,0,0,0,0,0,0,192,1,8,0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,0,0,0,0,0,0,0,7,32,0,0,0,0,0,0,192,1,8,0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,128,0,0,0,0,
0,0,0,7,32,0,0,0,0,0,0,192,1,8,0,0,0,0,0,0,112,0,2,0,0,0,0,0,0,28,224,255,7,239,159,104,176,230,195,53,71,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::patchEditorBackdrop_png = (const char*) resource_PatchEditor_patchEditorBackdrop_png;
const int PatchEditor::patchEditorBackdrop_pngSize = 30947;

// JUCER_RESOURCE: liveModeButtonNormal_png, 1831, "../../UI/LiveModeButtonNormal.png"
static const unsigned char resource_PatchEditor_liveModeButtonNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,6,164,73,68,65,84,104,129,237,155,75,108,27,215,21,134,191,225,12,103,196,183,100,90,18,85,201,138,156,184,149,224,88,66,12,200,177,23,46,144,32,64,224,85,211,101,210,108,180,204,174,238,170,73,128,
2,89,37,89,218,187,236,138,46,2,100,217,184,45,106,160,112,82,3,46,106,203,73,93,195,142,35,25,182,245,100,68,147,20,105,138,143,33,135,243,232,130,226,136,148,72,75,150,72,145,82,249,173,230,224,222,
51,247,220,153,127,206,220,123,56,20,88,167,191,251,242,59,2,214,69,224,12,224,161,67,135,221,147,5,166,45,184,244,244,217,197,43,0,2,64,168,231,210,231,88,252,190,165,161,117,56,148,8,150,240,217,74,
234,183,31,11,235,153,236,207,130,36,240,210,219,39,232,157,232,71,236,146,90,29,95,135,3,140,145,215,137,222,141,176,248,143,199,88,186,133,37,152,191,18,125,93,23,190,0,70,70,46,252,156,208,235,131,
56,36,71,171,227,236,112,192,113,72,14,124,67,126,68,69,34,245,40,129,128,16,114,0,147,0,189,19,253,45,14,175,195,97,163,66,83,147,14,192,11,116,94,151,29,26,142,228,114,150,15,125,205,87,151,85,113,44,
52,125,180,214,178,211,185,90,59,232,115,200,104,170,208,140,188,206,237,207,111,216,246,145,177,32,191,120,119,188,153,67,182,140,228,76,156,217,175,238,219,246,200,133,19,132,206,13,109,233,247,221,
103,55,208,11,58,0,158,144,135,241,15,206,236,91,140,173,164,45,223,151,150,101,161,61,43,216,182,67,118,224,244,200,45,140,232,197,41,170,69,10,201,60,78,175,140,195,233,64,75,107,88,186,137,101,109,
239,187,167,113,179,26,166,102,218,182,220,173,32,8,173,79,157,109,41,52,179,96,112,231,242,77,219,62,136,153,48,124,125,129,240,245,5,70,223,61,69,207,216,81,102,191,188,75,54,146,109,250,184,115,127,
153,37,49,179,106,219,103,62,60,223,22,235,239,214,71,80,3,65,20,240,143,116,219,182,171,207,107,31,231,19,42,90,106,35,219,121,6,125,136,178,8,128,101,90,164,23,82,118,155,228,113,226,238,243,212,244,
219,60,158,111,56,208,208,57,148,201,69,179,136,138,132,81,145,101,106,161,173,21,200,175,170,117,219,125,47,5,16,28,187,207,76,134,102,144,13,167,235,182,187,251,61,72,110,103,221,246,189,210,150,66,
115,56,69,78,78,189,86,179,237,233,116,152,149,155,203,182,61,241,193,36,238,80,73,136,166,102,240,224,79,255,181,219,42,51,225,102,191,74,36,69,98,242,163,243,141,10,191,138,165,111,230,118,212,47,241,
32,198,252,213,71,117,219,247,154,153,10,9,181,234,218,108,166,156,121,155,69,219,9,45,126,47,138,165,87,63,253,114,183,66,224,120,207,174,206,167,198,114,100,150,215,80,99,165,215,86,224,120,15,114,64,
169,26,207,52,76,98,119,34,72,110,137,158,209,198,92,108,239,160,31,87,175,155,212,92,18,45,85,160,103,244,40,146,75,42,205,207,216,152,159,150,42,144,122,146,36,179,156,174,242,43,147,156,93,69,87,139,
196,239,69,17,187,36,142,142,247,85,249,109,38,191,41,107,155,134,73,226,78,132,194,90,30,0,57,80,125,45,51,225,53,212,88,142,212,92,18,93,213,233,25,11,86,150,37,26,70,219,9,109,254,175,15,237,93,89,
153,35,99,193,93,11,45,245,56,81,149,41,66,103,7,171,158,220,228,143,113,244,130,206,227,175,103,240,132,60,13,19,218,209,241,62,66,231,134,120,248,213,61,18,169,2,199,222,28,193,29,242,150,198,171,16,
90,118,37,205,227,175,103,182,248,149,185,247,197,109,116,181,200,220,223,30,34,41,27,66,219,236,87,15,179,104,86,245,243,14,120,121,229,215,99,182,189,112,245,17,106,44,71,228,86,24,128,137,129,201,255,
15,161,253,236,151,195,24,121,157,240,141,197,166,156,63,126,63,74,118,37,99,219,134,241,252,181,211,94,9,158,234,199,29,242,225,244,54,102,215,172,101,52,162,183,127,66,93,205,1,224,27,242,19,56,113,
196,110,95,189,31,69,141,231,234,250,231,226,42,203,223,206,219,118,122,121,173,33,113,109,71,251,9,237,124,115,133,182,122,63,218,148,243,214,35,120,170,175,161,231,211,51,26,203,215,231,109,219,59,228,
103,232,141,17,219,206,69,210,207,21,90,62,158,171,242,223,47,218,78,104,219,17,28,47,101,136,200,173,101,178,43,105,150,190,153,71,116,173,79,195,40,21,169,228,128,194,177,55,95,70,9,40,228,158,102,170,
252,7,206,14,225,30,240,213,60,183,228,22,155,26,123,59,224,25,240,17,58,187,181,144,92,70,9,116,53,101,220,3,39,52,239,160,15,239,160,143,228,76,148,236,10,36,31,198,183,244,113,186,36,122,95,43,253,
160,187,89,104,254,227,221,77,221,93,181,59,74,64,182,175,205,126,178,175,66,91,91,76,241,195,31,235,111,177,95,121,103,148,133,191,63,66,207,87,111,6,202,126,193,87,123,9,189,62,8,192,177,183,94,38,116,
110,152,39,87,102,200,39,74,245,39,81,22,25,253,205,4,162,188,241,169,83,240,213,222,82,6,156,14,147,120,16,101,241,218,28,63,253,187,186,204,33,201,34,163,239,183,166,32,236,27,14,112,114,234,52,137,
7,81,34,211,97,34,211,97,86,127,220,120,120,212,213,210,110,113,244,253,113,164,46,137,174,160,139,147,83,167,73,47,61,99,233,218,28,241,31,98,100,42,214,156,106,172,250,193,18,101,145,147,83,167,201,
39,114,60,185,50,91,247,30,12,191,117,188,105,181,68,216,103,161,233,57,157,244,194,179,186,237,166,102,144,94,76,109,217,117,150,253,188,3,27,133,91,87,175,7,87,47,85,162,18,4,1,255,72,245,197,114,250,
20,156,62,133,228,76,12,192,46,115,84,34,41,173,75,236,146,219,137,127,36,64,46,82,42,111,228,19,170,253,224,84,226,63,22,176,235,104,254,145,0,70,190,8,64,49,93,160,152,174,93,136,6,16,28,165,107,34,
117,149,150,5,245,238,129,158,43,238,121,46,207,67,8,117,95,178,0,206,125,242,70,227,207,110,65,161,78,53,190,22,78,159,140,158,45,96,153,181,43,224,146,34,110,172,199,214,209,50,26,150,94,90,155,9,14,
11,217,95,123,141,97,168,58,122,193,168,217,246,60,191,157,98,234,38,197,204,198,205,146,220,34,162,188,85,192,218,90,222,158,159,32,9,200,235,187,81,67,211,209,115,181,227,3,80,2,74,213,215,30,155,199,
219,206,207,52,44,138,105,173,110,63,167,215,217,148,143,94,111,126,242,79,160,148,209,210,128,207,200,235,141,255,77,76,0,165,91,217,190,95,5,47,122,195,229,29,150,13,68,151,180,69,164,141,196,33,57,
118,52,215,122,243,19,101,169,166,48,247,58,158,221,95,20,94,248,94,236,21,93,181,31,132,53,7,240,61,64,244,110,100,95,131,232,112,248,137,126,191,82,62,252,78,244,116,93,72,10,240,222,218,124,18,81,145,
112,7,221,56,156,157,255,13,116,216,61,186,90,36,114,43,204,210,183,243,96,89,166,32,152,83,2,192,64,224,242,167,150,96,125,212,226,248,58,28,62,76,75,224,15,79,147,23,63,21,1,50,133,171,215,60,174,183,
255,35,32,244,3,189,192,193,250,202,176,67,187,145,6,254,37,8,230,84,36,249,187,47,1,254,7,26,215,147,95,90,13,76,232,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::liveModeButtonNormal_png = (const char*) resource_PatchEditor_liveModeButtonNormal_png;
const int PatchEditor::liveModeButtonNormal_pngSize = 1831;

// JUCER_RESOURCE: liveModeButtonOver_png, 1880, "../../UI/LiveModeButtonOver.png"
static const unsigned char resource_PatchEditor_liveModeButtonOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
6,213,73,68,65,84,104,129,237,154,93,80,84,231,25,199,127,103,119,97,191,119,249,102,151,168,81,146,16,216,14,154,22,87,185,104,111,196,233,208,24,162,183,157,16,244,38,222,104,171,246,198,9,99,51,147,
204,4,58,147,139,66,82,28,109,47,218,225,99,218,201,69,36,13,58,82,48,185,72,219,208,32,153,17,167,43,166,32,46,90,119,1,23,220,79,96,63,123,177,238,129,5,22,169,217,133,149,236,239,234,60,243,190,207,
251,117,254,231,57,239,251,156,35,240,152,226,156,214,195,2,145,211,128,25,80,147,33,195,211,227,5,190,142,64,203,228,163,211,127,5,16,0,12,185,45,191,33,194,217,77,29,90,134,45,137,16,17,154,109,206,
83,141,194,227,72,214,157,149,29,230,236,217,9,14,215,77,163,213,133,54,123,124,25,158,97,220,46,41,151,62,45,228,131,15,118,16,240,75,136,8,225,215,165,90,69,237,5,96,103,99,163,149,250,55,236,200,229,
145,205,30,103,134,103,28,185,60,194,158,61,30,52,154,16,95,126,153,131,128,96,144,0,123,1,14,215,77,111,242,240,50,108,53,14,191,254,48,118,185,87,2,104,128,204,235,50,67,210,209,235,131,177,75,173,44,
213,157,69,34,130,120,45,8,91,251,181,188,222,185,198,234,109,245,245,88,74,74,133,230,118,73,49,239,51,139,118,77,205,12,109,109,223,166,178,203,77,227,90,127,46,39,78,190,44,218,141,111,223,165,225,
168,125,69,61,179,217,140,219,45,5,160,188,220,75,119,247,205,13,27,227,102,146,242,136,246,52,132,195,240,224,129,66,180,149,202,32,249,249,193,53,60,210,143,71,78,25,247,239,43,40,40,8,160,80,132,152,
154,202,198,239,151,16,14,167,182,95,135,67,198,220,220,226,109,45,41,153,71,34,73,109,159,235,33,45,133,230,245,72,57,120,240,21,209,126,22,35,225,249,243,219,56,127,126,27,109,191,187,77,205,193,89,
142,31,127,153,145,145,212,231,193,223,121,167,148,107,215,242,68,123,240,235,193,180,216,127,167,165,208,100,89,17,246,237,115,137,118,89,217,156,120,109,181,42,176,219,229,162,93,89,233,65,165,138,46,
100,48,40,48,52,164,19,203,242,242,2,188,244,146,111,85,191,165,100,201,194,252,168,202,157,212,57,196,248,246,63,42,52,218,48,62,159,116,205,122,147,147,217,220,189,171,76,88,94,85,229,66,38,123,250,
61,157,207,39,229,230,77,77,194,242,178,50,47,185,185,169,123,107,164,165,208,148,202,48,237,237,150,85,203,186,186,138,105,111,55,138,118,247,165,97,202,43,162,98,154,243,73,56,122,180,66,44,91,26,9,
151,251,45,69,171,13,49,56,56,152,172,225,199,209,218,186,125,93,245,122,175,230,209,212,188,51,97,249,119,141,76,19,86,121,220,218,44,39,22,121,83,69,218,9,237,179,158,2,2,254,248,77,69,73,201,60,213,
213,174,4,30,107,51,58,166,98,248,134,134,177,49,21,0,213,213,46,140,198,5,177,188,167,167,0,191,95,224,147,79,138,200,201,9,112,224,64,114,22,123,247,110,47,47,188,224,99,96,64,135,205,38,231,192,129,
89,244,250,32,61,61,5,4,2,139,167,83,155,77,206,87,95,233,25,30,214,198,249,197,248,252,243,92,156,78,25,159,93,46,64,171,13,81,247,218,195,56,191,229,60,176,197,71,109,127,32,58,55,155,45,27,0,163,113,
33,110,45,111,14,171,25,29,83,49,48,160,199,233,202,162,166,102,102,105,90,34,105,164,157,208,222,123,119,151,120,42,139,81,83,51,243,212,66,251,231,223,117,113,145,226,205,122,91,220,147,219,223,159,
135,219,45,165,177,177,148,242,114,111,210,132,246,218,161,105,26,142,218,57,113,162,12,155,77,206,47,127,113,143,242,10,31,253,253,121,4,2,139,243,179,252,91,69,99,99,233,10,191,24,71,142,84,226,116,
202,120,239,221,93,113,66,91,238,151,136,249,121,105,92,61,147,201,75,115,243,152,104,55,53,61,207,232,152,138,142,78,3,0,221,151,60,223,15,161,29,63,254,95,220,46,41,191,255,195,115,41,105,255,242,149,
2,44,183,22,55,229,11,11,194,26,181,191,59,135,14,57,168,168,240,81,80,24,72,74,123,211,15,179,249,203,159,139,24,31,143,238,231,94,217,227,230,199,63,113,138,229,87,46,231,115,103,60,241,94,239,206,29,
37,31,125,180,77,180,111,220,208,38,101,92,79,34,237,132,246,214,91,15,82,42,180,43,87,242,83,210,110,34,94,125,213,145,212,246,28,211,50,218,218,22,133,178,123,143,135,147,39,239,139,246,173,91,170,53,
133,54,62,174,140,243,223,40,210,78,104,79,162,174,206,129,201,228,163,189,221,128,197,162,166,245,195,29,232,244,209,104,17,10,68,247,118,70,227,2,167,78,221,199,104,244,115,123,36,126,209,27,222,180,
99,250,129,119,213,182,245,250,228,68,157,116,198,100,242,210,208,176,50,145,28,163,228,57,127,74,250,125,230,132,86,89,233,161,178,210,67,95,95,46,22,139,154,47,190,200,89,81,71,175,15,114,228,72,244,
39,129,229,66,219,191,223,153,210,211,85,186,99,52,46,136,107,179,145,108,168,208,134,134,116,212,215,155,18,150,191,255,254,29,154,155,118,226,90,118,24,136,249,213,254,108,134,250,55,162,79,227,153,
51,247,56,118,204,206,185,115,165,88,173,209,175,8,42,85,136,139,23,111,139,121,53,128,218,218,25,42,76,62,58,59,13,244,246,230,241,219,150,29,252,241,79,241,105,14,141,58,204,133,139,35,201,154,230,255,
69,213,94,55,29,29,22,122,175,230,209,217,101,160,179,203,192,223,250,22,19,174,86,107,244,65,185,112,113,4,157,54,196,243,59,231,233,232,176,48,52,164,165,165,101,59,87,123,243,177,88,22,247,156,163,
163,170,184,246,213,234,16,29,29,22,172,86,5,231,206,149,38,188,7,191,58,115,47,101,185,68,216,96,161,61,122,36,227,250,117,93,194,242,57,159,132,161,111,180,43,78,157,49,63,147,105,241,149,247,226,139,
115,192,28,74,229,162,168,164,82,48,155,227,79,167,69,197,126,138,138,253,244,245,229,2,48,58,170,4,226,163,156,86,187,121,153,243,156,156,32,102,179,139,91,150,168,64,38,38,20,76,76,40,86,212,171,250,
161,91,204,163,153,205,46,92,206,232,26,77,77,102,51,53,153,157,176,125,169,36,130,217,236,66,171,137,158,36,19,221,131,217,217,212,74,65,48,228,180,68,0,70,70,6,146,222,120,36,34,136,249,155,245,80,88,
232,199,225,200,34,28,94,253,36,168,209,132,208,233,226,143,222,83,211,89,4,31,239,205,36,146,8,6,195,234,123,12,151,75,134,199,179,122,118,126,45,191,245,178,176,32,193,225,200,18,109,189,62,136,90,189,
82,192,118,123,182,56,63,89,86,152,162,199,167,81,175,87,138,211,153,248,102,27,141,254,184,191,61,150,247,247,36,191,64,64,96,122,58,241,189,200,207,15,32,151,39,255,67,108,121,121,53,16,21,154,11,208,
166,203,55,177,12,91,7,167,83,198,254,253,123,1,92,18,96,8,224,210,167,133,155,58,168,12,91,143,143,63,46,138,93,94,151,170,21,181,179,2,252,124,224,95,58,52,154,16,187,118,205,167,36,132,102,248,254,
224,116,202,232,232,48,208,250,225,118,194,97,33,44,8,225,99,2,128,81,223,218,20,17,34,111,111,246,0,51,108,57,194,17,129,95,79,206,158,110,146,2,120,22,174,94,83,43,127,250,141,128,80,12,20,2,235,223,
193,103,200,176,18,55,240,15,65,8,31,179,207,158,233,2,248,31,200,126,135,133,170,1,244,46,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::liveModeButtonOver_png = (const char*) resource_PatchEditor_liveModeButtonOver_png;
const int PatchEditor::liveModeButtonOver_pngSize = 1880;

// JUCER_RESOURCE: liveModeButtonDown_png, 1685, "../../UI/LiveModeButtonDown.png"
static const unsigned char resource_PatchEditor_liveModeButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
6,18,73,68,65,84,104,129,237,154,79,108,27,199,21,135,191,217,93,238,114,249,71,20,41,146,166,66,217,146,108,195,82,28,27,137,1,219,73,1,23,70,19,160,72,208,196,190,6,232,161,237,173,183,196,167,164,5,
2,228,150,220,234,222,114,244,197,65,142,73,78,190,24,9,80,23,176,19,183,14,44,199,144,138,36,86,101,169,162,37,211,18,255,139,203,93,110,15,20,87,90,137,180,92,73,43,50,42,191,19,31,102,222,204,155,217,
223,62,206,60,82,176,202,129,254,191,94,20,216,239,2,103,128,32,61,122,108,159,18,240,141,13,151,31,45,191,251,37,128,0,72,69,47,127,140,205,123,29,13,173,199,190,68,216,226,163,249,220,59,127,22,171,
153,236,243,78,7,212,99,255,98,139,250,5,105,245,235,178,71,15,207,16,182,116,73,2,78,119,58,144,30,251,158,211,18,16,234,116,20,61,246,61,97,197,243,41,196,186,207,182,231,179,117,150,103,93,171,120,
134,62,251,12,79,133,38,251,21,206,188,127,206,177,159,76,102,249,215,103,19,94,78,217,49,162,227,113,198,222,62,225,216,211,215,126,32,115,115,118,83,191,211,127,58,135,162,53,182,189,148,41,49,241,201,
183,123,22,99,39,241,62,163,109,3,33,4,106,191,230,216,117,163,78,173,100,116,48,162,255,29,159,238,67,139,250,169,21,13,234,181,58,106,88,69,40,18,66,108,237,187,163,121,131,42,146,42,57,182,177,92,197,
182,59,159,58,187,82,104,146,38,115,234,157,87,28,251,231,152,9,211,231,135,73,159,31,102,234,179,123,44,77,62,102,236,183,47,18,76,121,95,7,31,125,107,140,216,248,128,99,127,251,241,13,172,21,211,243,
121,183,162,43,133,102,91,54,249,233,101,199,174,44,20,157,207,254,152,142,26,89,203,118,165,185,2,150,97,1,32,36,65,120,56,226,180,153,165,26,229,133,82,75,191,141,243,21,102,114,187,186,134,38,129,100,
16,171,106,34,175,203,50,173,80,251,52,252,3,122,219,246,194,191,115,216,245,237,103,38,89,149,9,166,195,109,219,203,143,74,152,229,218,182,199,223,138,174,20,90,189,102,113,255,202,119,45,219,14,156,
77,51,248,202,144,99,223,253,228,54,229,76,67,136,146,42,115,252,119,47,57,109,235,51,225,70,191,245,152,85,147,219,31,221,216,173,240,93,28,124,117,244,153,250,197,142,39,24,121,253,104,219,246,157,102,
38,45,166,187,246,102,35,205,204,235,21,93,39,180,248,201,36,66,113,191,253,198,114,149,220,131,165,109,141,167,39,2,132,134,250,208,19,141,175,173,220,131,37,140,92,213,53,159,36,75,36,78,165,48,203,
38,75,83,187,179,217,197,185,60,149,197,50,145,209,40,106,68,99,105,234,49,102,197,108,172,79,94,91,159,26,209,136,28,142,18,26,10,187,252,154,68,199,6,80,116,31,241,147,73,172,21,147,199,19,11,46,191,
141,248,55,100,109,73,150,136,157,74,161,245,249,1,48,114,238,189,12,165,251,208,19,1,34,163,81,20,93,97,105,50,139,89,217,253,204,214,117,66,27,121,243,152,115,43,107,242,100,50,187,109,161,69,142,196,
92,153,34,115,107,206,245,230,70,159,143,163,104,10,71,46,142,83,202,148,118,77,104,143,39,22,200,220,156,229,216,219,39,137,69,52,30,126,53,77,57,83,108,204,183,78,104,193,193,48,71,46,142,111,242,107,
114,242,143,103,80,116,31,163,191,57,134,89,93,19,218,70,191,118,72,62,201,213,175,56,95,228,199,207,39,29,123,248,245,163,232,137,0,169,151,211,0,220,157,191,253,255,33,180,255,252,109,6,217,175,144,
62,119,200,147,241,227,39,146,4,7,215,106,212,178,252,244,179,211,78,201,222,123,68,57,83,160,86,220,157,91,179,26,82,73,158,121,14,125,32,0,64,97,54,79,238,135,39,78,251,192,137,36,122,60,208,214,63,
16,215,25,250,213,136,99,135,135,250,118,37,174,173,232,62,161,221,240,86,104,3,39,146,158,140,219,142,236,189,133,93,29,79,9,169,12,157,31,113,236,226,108,158,217,175,167,29,59,144,10,63,85,104,254,120,
192,229,191,87,116,157,208,182,34,59,209,200,16,169,151,135,8,14,134,57,248,234,8,86,101,245,144,44,55,138,84,70,174,202,195,175,126,162,154,171,18,56,224,254,133,109,254,214,44,229,249,66,203,177,205,
178,229,105,236,221,64,105,190,64,230,214,230,66,114,147,106,110,197,147,121,127,118,66,43,206,21,40,206,21,136,142,39,9,14,66,244,88,124,83,159,90,197,100,241,187,71,0,155,132,150,127,176,236,233,237,
170,219,169,230,12,103,111,246,146,61,21,90,223,161,62,94,248,67,251,43,246,143,95,76,49,252,198,81,20,191,59,172,166,95,246,251,69,50,223,204,1,240,240,250,79,100,110,206,112,248,194,56,254,88,163,254,
100,25,22,83,159,222,197,50,234,142,111,246,251,197,70,6,60,155,38,118,60,201,161,215,70,121,238,23,238,50,135,105,88,76,93,237,76,65,184,48,179,204,253,43,119,136,29,79,146,58,155,38,117,54,205,192,243,
107,47,143,62,208,184,45,78,93,157,192,92,49,89,201,86,184,127,229,14,225,131,253,28,124,109,148,248,11,9,66,235,206,156,205,219,117,19,203,48,185,127,229,14,254,88,128,195,23,198,218,62,131,153,235,15,
60,171,37,194,30,11,77,9,248,8,15,247,183,109,151,84,153,240,161,200,166,91,103,211,175,56,191,86,184,173,44,150,168,44,226,18,149,109,219,228,167,221,155,85,43,84,169,21,170,68,199,19,192,230,7,1,141,
58,90,167,48,203,38,249,233,28,129,84,163,188,225,143,233,206,139,179,158,252,195,156,83,71,203,79,231,144,253,62,0,124,97,13,95,184,117,33,26,192,174,55,250,155,43,141,99,65,187,103,160,4,124,59,94,203,
211,16,169,254,203,222,253,16,38,64,107,83,141,111,69,173,96,160,4,53,132,212,58,36,179,106,173,157,199,86,81,67,42,66,105,156,205,236,186,192,200,183,62,99,200,186,130,162,201,45,219,158,230,247,172,
72,138,132,47,180,246,176,204,178,133,101,108,22,176,218,231,119,214,103,155,54,198,234,109,84,86,21,148,64,235,248,0,170,185,170,235,223,30,27,231,219,202,79,146,5,190,176,218,182,95,173,88,163,110,214,
219,182,239,20,145,234,191,156,7,218,255,54,209,163,199,206,201,75,192,63,58,29,69,143,125,207,109,201,134,191,116,58,138,30,251,154,186,16,245,15,229,210,202,181,169,176,246,134,134,224,151,157,142,168,
199,190,163,110,11,62,200,44,93,186,42,3,20,171,215,174,7,245,95,255,83,32,14,0,9,160,253,169,177,71,143,173,41,0,127,23,162,254,251,204,210,165,171,0,255,5,18,66,44,18,62,98,198,84,0,0,0,0,73,69,78,68,
174,66,96,130,0,0};

const char* PatchEditor::liveModeButtonDown_png = (const char*) resource_PatchEditor_liveModeButtonDown_png;
const int PatchEditor::liveModeButtonDown_pngSize = 1685;

// JUCER_RESOURCE: patchEditorButtonDown_png, 1806, "../../UI/PatchEditorButtonDown.png"
static const unsigned char resource_PatchEditor_patchEditorButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,6,139,73,68,65,84,104,129,237,154,207,107,219,102,24,199,191,146,101,201,63,100,91,113,162,68,249,81,199,37,9,180,233,161,118,233,160,131,148,117,135,141,238,178,238,208,227,96,221,95,208,246,52,24,
12,122,219,110,203,254,129,145,75,79,221,33,236,178,50,24,4,198,88,24,91,237,75,189,148,52,212,109,51,236,212,174,237,248,183,100,217,218,193,142,44,69,242,175,196,105,210,84,31,48,232,125,245,62,122,
30,61,239,163,87,207,163,215,4,90,76,112,63,220,32,160,220,1,240,30,0,55,44,44,14,78,9,192,95,10,176,188,147,187,243,51,0,16,0,32,140,44,127,7,5,95,29,171,105,22,167,18,66,33,190,77,236,222,254,154,104,
173,100,171,199,109,144,197,233,69,33,26,159,146,173,215,165,133,197,145,65,40,228,93,18,192,229,227,54,196,226,212,115,153,4,192,30,183,21,22,167,30,15,213,115,8,209,199,101,148,195,91,242,86,211,143,
143,128,119,218,79,93,3,141,15,9,152,251,236,92,207,139,172,223,91,27,150,61,111,29,115,159,157,7,31,154,232,107,108,42,186,131,173,213,127,143,216,162,147,73,239,21,77,131,92,174,161,46,213,213,54,237,
101,64,144,4,152,17,7,148,186,2,41,47,30,202,24,27,109,3,229,182,183,245,149,244,250,6,129,102,105,16,118,82,109,139,217,234,161,108,235,23,41,47,66,105,152,47,93,114,73,234,41,207,140,56,212,99,165,214,
128,84,108,202,216,28,20,40,103,123,186,106,5,9,13,185,97,144,39,41,18,118,15,221,214,89,145,81,175,202,125,219,127,84,12,20,104,207,127,221,66,42,154,84,219,225,59,239,131,225,24,132,111,95,129,152,19,
17,89,254,243,80,198,248,23,121,221,10,186,181,186,161,211,55,8,243,55,47,192,27,244,169,237,55,181,234,62,254,49,2,49,119,240,160,14,223,190,162,30,231,227,187,136,173,68,0,0,147,87,102,48,115,45,168,
158,139,173,68,145,143,231,12,242,236,140,23,139,183,66,106,123,123,45,142,237,181,248,129,237,25,22,3,5,90,191,208,44,13,7,239,234,120,190,248,50,143,134,220,0,73,145,96,207,120,213,126,231,152,94,198,
57,230,130,247,44,215,83,110,63,213,84,249,16,214,159,76,196,92,69,23,88,245,106,77,61,214,250,200,53,161,175,237,24,206,169,59,95,74,20,213,21,78,219,111,208,151,173,170,15,140,75,96,117,171,169,25,181,
130,132,74,186,179,223,143,36,208,124,243,254,174,185,93,100,121,29,98,174,10,59,75,99,241,139,80,199,113,83,75,1,76,45,5,6,150,219,90,221,56,152,225,39,152,84,116,7,169,232,142,233,185,110,190,224,67,
19,186,28,82,187,18,118,147,211,174,132,193,235,11,186,183,67,39,251,186,229,159,3,5,154,39,224,211,85,88,54,154,108,41,73,66,46,181,159,176,234,235,138,233,43,207,55,239,7,205,210,240,95,224,33,151,107,
200,62,73,235,198,57,252,206,166,142,22,133,23,187,168,102,42,106,187,46,201,224,195,2,40,87,51,143,147,138,18,118,159,102,12,122,170,175,43,134,62,62,44,152,142,43,188,216,237,118,203,3,179,119,111,0,
80,23,27,200,196,94,153,142,243,4,124,112,140,58,123,94,207,225,119,194,51,107,156,228,221,205,140,154,191,105,125,104,103,105,112,243,126,181,93,78,22,81,74,22,213,182,84,148,224,95,28,135,141,105,206,
93,93,170,35,19,75,233,245,5,124,112,9,30,240,97,1,133,231,70,255,152,233,115,140,58,192,135,5,148,18,69,148,53,250,246,24,40,208,198,47,77,98,252,210,164,161,127,255,10,82,120,185,139,194,75,163,129,
139,183,194,160,89,26,179,31,205,1,104,230,77,90,89,62,36,232,2,237,213,163,132,33,96,231,110,180,87,202,106,186,210,247,234,165,149,219,35,21,221,25,122,160,237,221,27,0,136,57,177,99,160,141,95,154,
234,171,90,245,4,124,166,182,199,86,162,106,160,105,125,224,13,114,186,64,203,108,164,13,57,218,249,207,47,130,225,24,0,128,92,150,77,231,192,127,110,20,254,115,163,166,254,53,211,231,57,227,131,231,140,
15,219,107,241,195,7,90,118,35,173,123,58,58,225,18,88,248,207,143,25,250,25,206,97,50,250,205,160,117,54,195,57,192,135,4,184,4,22,51,31,6,145,127,150,51,77,172,15,66,114,125,27,114,43,7,50,171,246,188,
65,14,222,179,28,92,66,51,151,74,69,147,186,226,65,155,240,3,64,57,89,192,246,90,188,41,23,236,156,83,29,23,98,174,162,243,109,62,158,53,29,55,80,160,101,54,210,125,85,129,110,129,197,204,7,193,65,46,
125,228,104,157,225,13,114,224,67,2,220,130,27,110,193,141,109,37,62,180,64,75,172,111,119,173,58,189,65,78,231,155,84,52,169,211,189,63,208,74,201,18,74,201,18,102,174,5,79,104,160,137,125,85,181,67,
45,6,156,99,46,76,95,13,128,241,55,115,143,236,70,26,153,141,246,251,127,106,105,214,80,89,90,188,27,12,53,208,236,44,141,177,139,237,164,187,148,44,234,42,37,62,52,5,167,241,141,106,241,14,48,212,64,
43,39,138,136,173,68,224,155,31,197,244,82,0,124,104,18,62,205,183,26,167,208,253,143,187,185,167,25,196,86,34,224,67,147,224,67,2,166,151,2,24,215,84,139,155,15,98,136,173,68,96,103,25,44,220,92,132,
107,210,141,11,95,26,75,244,255,126,127,49,188,155,26,144,133,155,139,80,234,198,47,246,0,144,219,204,32,21,77,32,31,207,98,106,105,22,220,188,31,179,215,23,208,16,107,166,227,1,128,155,247,99,250,106,
0,180,79,95,161,238,201,109,62,136,169,69,1,208,123,14,158,253,242,20,155,63,61,6,73,17,173,226,204,174,243,161,221,221,220,85,72,69,147,72,69,19,168,164,43,224,67,198,2,112,80,134,26,104,178,40,35,31,
223,5,195,53,157,194,112,140,90,221,244,67,173,40,161,86,148,224,13,142,0,0,28,99,46,56,52,175,90,130,34,91,215,111,22,21,20,67,193,51,107,204,91,236,145,131,237,38,12,3,118,166,203,135,228,172,8,49,215,
252,241,161,102,112,185,123,60,124,118,150,54,189,199,61,57,130,34,117,253,189,230,128,114,80,186,156,144,160,72,211,235,139,185,42,242,241,225,85,228,132,192,45,119,252,79,1,105,183,193,238,214,236,175,
149,100,52,106,189,247,30,247,203,117,66,204,153,239,141,82,12,5,155,211,102,232,111,238,35,2,4,217,220,103,237,68,173,36,195,198,216,64,82,237,143,126,90,93,4,69,130,102,219,123,170,245,74,29,178,120,
176,253,64,202,69,193,70,27,109,53,163,46,213,33,151,229,190,229,26,178,130,186,88,239,234,203,61,159,236,167,211,28,72,197,26,148,214,30,105,183,69,64,235,19,59,75,119,244,101,191,16,2,183,156,7,224,
25,88,210,194,162,127,242,36,128,127,142,219,10,139,83,207,223,164,2,124,127,220,86,88,156,106,26,4,209,184,103,43,85,31,62,241,48,159,48,32,112,245,184,45,178,56,117,52,20,2,223,36,179,119,239,219,0,
160,40,62,252,205,237,252,248,17,1,98,2,0,15,128,238,46,111,97,209,149,2,128,63,8,162,113,43,153,189,123,31,0,254,7,119,56,155,51,133,129,225,139,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::patchEditorButtonDown_png = (const char*) resource_PatchEditor_patchEditorButtonDown_png;
const int PatchEditor::patchEditorButtonDown_pngSize = 1806;

// JUCER_RESOURCE: downArrowNormal_png, 366, "../../UI/DownArrowNormal.png"
static const unsigned char resource_PatchEditor_downArrowNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,14,0,0,0,12,8,6,0,0,0,82,128,140,218,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,235,
73,68,65,84,40,145,149,210,189,78,2,65,20,197,241,255,25,191,18,159,196,70,151,68,158,130,6,223,131,130,85,11,136,54,68,163,53,139,47,224,71,105,98,112,19,30,194,130,16,75,18,122,67,165,132,106,201,102,
174,149,27,101,0,225,118,51,57,191,204,201,205,232,164,253,222,3,171,176,193,152,232,57,239,243,58,144,109,224,102,102,58,119,233,217,241,200,80,103,253,231,104,167,113,52,116,0,150,237,93,3,31,107,176,
241,78,150,223,2,56,128,180,113,48,197,236,226,63,37,89,227,185,89,158,20,16,160,27,151,30,128,183,21,174,31,125,150,158,126,14,5,68,50,228,106,128,95,128,204,80,173,213,146,15,33,208,173,31,245,129,199,
160,34,220,191,198,209,159,54,110,62,228,217,106,34,38,191,174,166,178,252,114,62,23,192,52,62,28,203,236,166,232,40,93,189,156,150,131,141,7,16,96,251,107,55,1,134,192,104,166,253,187,69,153,165,83,77,
6,149,106,50,88,250,21,191,1,80,196,76,238,104,162,65,116,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::downArrowNormal_png = (const char*) resource_PatchEditor_downArrowNormal_png;
const int PatchEditor::downArrowNormal_pngSize = 366;

// JUCER_RESOURCE: newRowNormal_png, 1627, "../../UI/NewRowNormal.png"
static const unsigned char resource_PatchEditor_newRowNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,216,73,
68,65,84,104,129,237,155,205,111,27,69,24,135,159,217,15,175,63,54,142,73,98,146,180,81,99,72,42,81,35,161,4,1,2,41,135,156,162,158,32,7,46,220,242,31,80,78,8,36,164,158,128,99,123,227,70,57,112,67,130,
114,170,64,168,65,2,41,32,104,210,3,86,165,38,224,6,183,113,157,16,59,182,227,248,99,189,203,33,241,198,118,236,124,184,110,188,169,252,156,118,60,51,187,239,140,127,243,238,251,206,216,130,61,6,3,215,
223,17,88,87,128,215,1,31,93,186,180,206,54,240,187,5,215,30,167,174,124,15,32,0,134,158,187,246,57,22,31,118,212,180,46,207,36,194,18,159,173,109,189,255,177,216,243,100,223,9,69,48,58,51,78,240,149,
65,100,183,210,105,251,186,156,97,202,121,131,196,221,56,171,63,174,96,25,22,150,48,223,150,123,220,151,191,0,66,161,203,23,25,122,227,60,146,34,117,218,206,46,103,28,73,145,232,25,241,35,107,10,91,203,
155,8,196,144,4,188,6,16,124,101,176,195,230,117,121,214,168,210,212,107,18,160,3,221,215,101,151,182,163,120,212,202,101,143,115,212,101,85,93,139,19,212,57,21,235,136,250,179,50,142,54,225,8,161,69,
110,44,146,142,110,217,229,55,175,78,219,215,233,104,138,200,141,37,187,60,50,29,98,100,58,116,138,214,157,156,216,124,148,216,124,244,208,54,90,64,99,242,202,91,167,99,144,3,112,132,208,234,41,36,243,
8,89,224,242,107,157,54,165,45,184,116,23,162,42,201,42,164,242,152,229,189,113,170,18,46,221,213,65,235,78,7,71,10,109,241,250,194,51,181,226,199,223,13,227,15,5,236,242,194,213,121,74,153,2,139,215,
23,240,135,122,9,207,77,118,208,186,211,193,145,66,3,48,13,139,244,63,41,114,143,179,77,219,228,226,89,140,29,163,97,157,226,81,240,14,233,192,174,7,41,36,243,118,157,111,88,63,144,252,152,37,147,108,
44,109,151,213,30,23,158,1,239,147,12,225,196,212,219,89,143,255,133,93,177,150,243,6,219,107,251,243,162,61,231,70,11,184,15,180,207,196,210,88,37,19,0,161,238,110,57,116,10,199,10,173,148,45,18,249,
106,233,208,54,209,91,247,107,98,187,106,170,61,197,250,82,188,38,102,10,207,77,212,120,24,128,210,118,237,243,130,19,131,140,205,94,106,209,250,214,168,183,179,158,74,236,186,29,207,214,216,218,44,110,
93,254,230,47,10,169,2,208,249,152,208,177,66,59,140,204,234,22,249,255,118,40,102,75,0,244,133,159,71,118,237,198,64,229,162,201,102,36,65,49,91,98,125,49,142,187,223,211,244,62,155,145,4,229,130,73,
112,114,232,169,218,155,90,222,60,224,169,100,151,76,95,56,136,103,192,75,126,115,135,204,131,45,114,241,12,0,61,23,122,113,247,237,219,189,25,89,167,92,44,179,190,24,71,214,36,20,111,227,152,174,50,47,
189,23,251,28,23,247,157,73,161,37,238,60,98,125,233,177,93,30,157,121,209,126,117,20,82,121,54,35,9,242,27,57,86,110,222,35,56,49,136,22,104,44,182,7,63,172,80,72,21,158,186,208,30,253,178,122,224,51,
197,171,48,54,251,18,176,235,201,86,110,222,179,235,158,127,117,152,224,196,190,77,233,104,146,114,177,204,202,205,123,104,1,173,169,167,173,204,75,120,110,162,43,180,227,48,50,29,194,200,27,196,23,98,
199,106,31,95,136,33,107,187,67,41,23,26,199,108,213,172,47,173,145,254,39,69,121,167,12,64,236,118,244,88,253,218,197,200,116,168,173,27,228,233,104,146,216,237,221,152,21,14,142,207,9,56,86,104,133,
84,254,216,66,91,59,102,187,10,213,222,16,32,246,115,244,68,253,159,148,118,239,3,166,163,91,53,177,106,253,248,156,128,35,133,6,160,250,84,198,102,47,145,223,216,230,97,131,87,79,53,163,51,99,77,227,
22,119,191,27,73,85,208,2,30,18,119,30,145,89,109,156,60,84,240,12,120,57,55,53,138,187,255,96,22,215,42,231,167,46,224,30,240,241,224,135,101,140,92,137,229,111,239,161,250,84,70,103,198,90,186,159,103,
192,203,216,236,37,50,171,91,36,238,60,58,178,253,216,236,37,59,134,237,20,142,21,154,164,202,4,39,6,73,71,83,71,10,173,47,28,108,152,222,87,227,27,242,145,142,110,30,41,52,85,87,9,78,180,247,7,6,189,
227,125,248,67,1,98,243,127,99,228,96,227,110,28,45,160,181,44,52,85,119,237,217,104,29,75,104,237,30,79,43,56,86,104,135,113,126,106,148,224,196,57,162,183,238,147,139,103,185,255,77,4,33,215,174,88,
125,88,103,244,242,248,161,247,185,248,110,24,85,215,136,220,88,124,154,230,86,61,239,101,76,195,34,114,99,145,98,182,196,95,95,46,161,15,235,156,155,186,64,120,110,146,245,165,53,214,151,226,60,252,101,
149,196,98,220,238,87,201,174,195,115,147,72,74,243,67,210,243,83,23,232,29,239,183,231,197,73,156,73,161,185,7,188,184,7,64,113,203,0,53,27,173,21,132,56,234,84,27,244,17,255,145,158,176,157,232,85,27,
166,150,97,146,121,144,66,8,11,85,119,161,234,46,210,209,36,0,249,141,28,249,141,220,129,254,254,80,239,161,247,119,15,120,241,135,122,237,121,113,18,98,40,112,205,130,218,131,236,211,166,148,45,98,26,
251,194,208,2,251,103,156,150,97,218,43,26,64,246,200,40,123,25,102,125,191,106,36,69,160,214,165,248,70,174,68,185,104,218,101,151,95,67,72,216,155,154,205,250,157,20,163,96,212,100,124,46,93,173,59,
235,108,252,188,250,126,245,84,207,11,128,89,42,83,218,222,207,150,85,159,130,164,202,135,206,231,105,179,112,117,30,216,245,104,25,160,167,156,55,58,246,155,180,195,190,88,161,72,77,39,234,164,130,80,
188,42,74,131,83,165,118,127,17,138,166,216,139,161,17,205,158,119,84,191,122,36,85,70,11,28,244,94,79,186,80,218,133,177,99,59,136,180,4,252,9,144,184,27,111,218,161,75,151,86,72,252,185,86,185,252,67,
246,185,47,39,5,188,151,142,38,145,53,5,111,191,23,73,237,254,111,160,75,235,24,59,37,226,191,61,228,223,219,81,176,44,83,8,115,78,0,12,247,94,255,212,18,214,71,29,182,175,203,179,135,105,9,62,121,156,
188,242,169,12,144,45,220,250,201,231,153,185,35,16,131,64,16,112,198,75,190,203,89,37,3,252,42,132,57,23,79,126,240,53,192,255,166,18,55,136,65,35,88,139,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newRowNormal_png = (const char*) resource_PatchEditor_newRowNormal_png;
const int PatchEditor::newRowNormal_pngSize = 1627;

// JUCER_RESOURCE: newRowOver_png, 1663, "../../UI/NewRowOver.png"
static const unsigned char resource_PatchEditor_newRowOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,252,73,
68,65,84,104,129,237,154,77,80,19,103,24,199,127,155,16,242,1,9,31,77,0,99,138,38,109,103,48,23,156,86,160,135,234,201,145,94,170,168,237,161,83,177,189,20,47,153,169,122,144,54,51,61,170,97,156,90,181,
118,166,163,39,97,122,209,17,180,167,114,168,23,167,51,6,196,234,5,232,88,74,233,4,170,146,49,38,129,64,18,216,237,33,178,36,1,194,135,145,44,76,126,167,247,221,125,118,243,127,223,252,243,236,243,190,
27,129,151,84,150,94,60,32,32,29,7,234,128,34,242,228,89,59,147,64,143,4,23,158,190,56,254,11,128,0,80,85,118,193,131,68,107,78,165,229,217,148,8,146,112,246,191,224,87,110,225,101,38,187,165,41,20,105,
109,253,151,3,31,141,99,52,205,230,90,95,158,13,76,56,164,166,235,182,133,115,231,170,137,199,84,72,130,184,95,109,212,125,248,19,176,221,237,30,225,200,103,79,208,106,165,92,235,204,179,193,209,106,37,
106,107,39,40,46,158,229,238,221,82,4,132,42,21,176,11,224,192,71,227,57,150,151,103,179,113,96,191,127,174,185,75,5,20,3,249,199,101,158,172,83,82,50,51,215,52,22,228,82,72,50,146,36,200,109,65,144,86,
124,78,169,36,107,94,140,141,50,142,108,161,8,163,53,55,59,233,237,53,201,253,193,193,123,114,187,167,199,196,209,163,78,185,239,114,249,112,185,124,235,170,111,181,92,190,108,227,242,101,91,198,24,171,
53,202,157,59,127,172,147,162,220,163,8,163,165,227,243,233,208,104,68,42,43,99,185,150,146,21,44,230,24,133,73,139,172,209,81,45,51,179,2,62,159,14,173,78,196,98,222,28,227,204,132,34,141,182,119,239,
206,77,245,139,255,238,252,95,212,215,135,228,126,77,205,251,60,123,90,200,222,189,59,169,171,11,209,209,209,159,67,117,235,131,34,141,6,16,139,169,240,122,75,248,115,80,191,100,204,224,128,129,96,72,
179,232,185,18,83,156,154,29,17,32,145,65,124,62,157,124,206,185,99,98,193,226,39,26,85,241,240,161,81,238,91,42,98,56,236,83,175,50,132,85,147,174,51,157,134,134,32,144,216,167,234,31,40,150,143,219,
108,211,108,221,26,93,16,255,240,145,145,232,180,10,0,173,78,100,103,109,56,203,138,87,142,98,141,230,247,107,248,252,243,29,25,99,78,159,217,158,82,219,37,147,156,41,186,186,44,41,53,83,123,123,127,74,
134,89,236,243,154,154,198,241,120,134,214,42,127,77,164,235,76,103,174,118,29,24,44,74,209,186,84,221,122,242,196,219,140,141,105,129,220,215,132,138,53,90,38,30,244,25,249,103,68,143,223,159,200,102,
141,141,207,49,24,18,25,42,18,81,211,221,93,142,223,175,161,179,179,130,237,219,150,206,74,221,221,229,76,78,22,112,232,208,179,215,170,247,238,221,210,5,153,202,96,152,165,177,241,57,14,199,20,35,35,
58,250,250,76,12,12,24,0,120,247,189,48,219,170,167,83,116,70,34,106,58,59,43,40,42,154,161,172,108,134,197,152,155,151,221,123,94,40,174,238,219,144,70,187,126,163,130,91,183,44,114,255,212,169,17,249,
209,49,58,170,165,187,187,156,225,97,61,110,183,131,166,166,113,108,182,133,143,21,128,182,182,109,140,141,105,95,187,209,174,94,181,46,56,86,90,58,195,217,179,137,140,217,213,101,193,237,118,200,231,
62,249,248,25,7,15,206,111,160,123,189,38,34,17,53,110,183,3,171,53,186,100,166,157,155,151,246,246,254,188,209,86,130,203,229,35,20,46,160,253,90,213,138,226,175,93,171,194,104,76,100,180,112,88,189,
108,124,103,167,5,175,215,68,56,156,24,254,15,63,216,86,116,93,182,112,185,124,152,178,184,65,238,245,154,144,36,27,131,131,137,140,152,62,62,37,160,28,37,73,184,92,62,70,71,181,43,54,90,123,251,150,85,
221,63,57,27,2,252,248,99,230,61,175,108,147,237,125,192,222,94,83,74,173,154,62,62,37,160,72,163,1,148,151,199,241,120,134,248,123,72,199,149,171,91,51,198,182,158,26,161,172,124,241,186,165,186,122,
26,131,65,196,102,139,114,253,70,5,15,250,140,139,198,205,225,176,79,209,114,108,140,234,164,26,233,85,105,249,114,20,199,91,211,180,181,109,35,16,40,160,245,235,183,40,47,159,161,245,212,200,154,238,
231,112,76,225,241,12,209,215,103,226,198,141,229,77,229,241,12,97,208,231,246,21,163,98,141,166,215,139,52,53,141,211,211,99,90,214,104,251,26,159,47,186,188,79,166,166,102,146,123,247,76,203,26,237,
13,115,156,166,166,236,254,193,224,131,221,65,234,235,67,92,186,100,35,16,40,224,246,45,11,86,107,116,205,70,51,191,212,40,73,172,200,104,217,30,207,90,80,172,209,50,113,236,216,24,135,15,143,115,250,
204,118,6,7,12,156,60,249,14,26,141,152,18,227,116,78,226,118,103,254,34,207,159,127,140,197,18,167,185,217,153,49,46,91,124,255,253,99,98,49,21,205,205,78,252,126,13,71,142,56,113,58,39,105,105,25,163,
163,163,159,206,78,11,93,93,22,174,92,177,114,243,230,188,129,230,86,215,29,29,253,20,22,138,75,221,158,150,47,71,217,189,39,40,207,139,146,216,144,70,179,219,167,176,219,167,48,22,39,30,151,143,30,21,
47,136,17,50,191,211,6,160,182,118,98,217,76,152,77,106,107,39,228,118,44,166,226,254,125,19,130,144,200,80,102,115,28,175,55,81,103,13,15,235,25,30,94,184,81,93,87,23,90,112,44,25,187,99,154,186,186,
144,60,47,74,66,168,42,189,32,65,234,139,236,245,198,239,215,16,139,169,228,190,213,58,255,229,199,98,42,249,23,13,96,52,206,200,43,204,244,235,146,41,44,20,49,155,227,41,199,94,188,40,32,18,153,95,93,
86,86,198,80,171,37,121,83,115,169,235,86,75,56,172,78,89,241,153,205,241,148,76,180,212,231,165,95,151,78,242,188,0,76,77,169,8,4,230,231,166,172,44,142,94,47,102,156,207,245,166,166,230,125,32,97,180,
16,96,236,237,233,205,255,39,45,79,86,9,6,11,104,104,216,5,16,82,1,125,0,93,183,149,183,36,206,179,177,185,126,189,98,174,121,95,93,164,251,48,32,192,167,247,188,38,138,139,103,177,219,167,209,106,151,
46,56,243,228,89,142,96,176,128,142,142,42,46,94,122,19,81,20,68,65,16,191,16,0,182,148,92,60,35,9,210,55,185,22,152,103,211,33,74,2,223,62,13,28,63,163,6,152,136,254,250,91,145,126,223,3,1,161,18,176,
0,133,185,213,151,103,131,19,6,126,23,4,241,139,39,129,19,63,3,252,15,242,249,57,220,20,157,60,109,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newRowOver_png = (const char*) resource_PatchEditor_newRowOver_png;
const int PatchEditor::newRowOver_pngSize = 1663;

// JUCER_RESOURCE: newRowDown_png, 1480, "../../UI/NewRowDown.png"
static const unsigned char resource_PatchEditor_newRowDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,69,73,
68,65,84,104,129,237,154,77,79,27,87,20,134,159,25,143,63,48,182,49,20,131,33,46,56,133,72,200,89,212,142,82,137,69,170,146,77,148,110,138,42,117,95,250,11,146,172,42,85,170,148,93,187,43,253,7,108,178,
203,2,117,21,69,170,196,130,170,85,213,6,111,106,90,5,90,131,72,128,216,16,219,140,63,198,99,123,186,0,6,99,27,243,17,96,6,203,207,106,174,231,222,59,239,189,122,231,204,57,51,22,216,163,223,251,227,164,
128,246,16,248,8,232,164,77,155,179,147,5,126,215,96,122,51,245,240,39,0,1,192,223,61,253,61,26,95,27,42,173,77,75,34,104,194,119,235,233,7,223,8,123,145,108,214,104,65,109,90,23,77,168,124,38,238,61,
46,219,180,185,48,4,77,124,36,2,183,141,22,210,166,229,185,45,2,46,163,85,180,105,121,220,146,209,10,116,132,170,99,237,20,231,204,138,112,204,249,171,178,142,115,194,20,70,11,77,69,240,4,187,244,246,
111,143,231,244,99,79,208,75,104,42,172,183,215,230,226,172,205,197,47,81,221,233,9,76,4,9,76,4,155,246,81,82,10,11,211,191,94,142,32,19,96,10,163,213,98,239,118,160,149,53,138,25,197,104,41,231,66,81,
46,162,149,42,122,219,238,117,32,90,246,214,169,86,40,202,69,3,213,93,14,166,52,90,228,193,120,75,221,241,75,79,99,100,226,41,189,61,254,120,2,171,219,78,228,193,56,153,120,154,216,204,130,129,234,46,
7,83,26,13,64,148,4,60,215,189,56,251,143,174,85,156,126,23,82,71,227,37,148,242,37,114,27,50,176,27,65,236,221,14,253,92,118,93,166,92,40,213,92,79,196,245,190,71,111,171,59,69,242,201,220,187,44,225,
212,212,234,172,37,243,223,174,89,45,14,137,206,129,131,125,81,222,22,80,82,133,186,254,238,128,7,193,42,2,160,169,21,118,214,50,231,172,248,228,152,214,104,86,151,141,208,151,225,166,125,130,247,111,
28,202,237,170,169,142,20,190,176,255,80,206,20,155,137,30,138,48,141,174,151,136,110,178,60,187,120,70,245,103,163,86,103,45,251,185,107,167,223,117,72,235,81,121,235,232,23,55,177,123,237,128,241,57,
161,105,141,214,12,247,80,23,142,247,58,176,185,172,0,108,199,222,80,46,238,230,64,22,155,72,79,168,15,155,203,138,47,226,167,176,149,63,114,158,158,80,31,22,187,72,98,97,227,66,245,122,71,123,234,34,
85,185,88,102,59,150,32,159,204,225,232,233,192,61,220,133,211,239,6,96,103,53,77,97,251,64,119,79,200,135,197,102,193,23,241,83,86,42,148,114,141,115,186,253,125,73,191,220,54,93,222,119,37,141,214,119,
107,16,95,184,95,111,175,60,255,87,127,116,216,189,14,122,66,125,56,122,157,140,76,142,145,136,110,162,164,26,155,109,248,222,8,118,175,253,194,141,54,120,103,168,238,183,82,174,196,242,236,223,192,110,
36,27,153,28,211,207,189,121,177,78,34,122,160,201,19,236,198,98,179,48,50,57,134,146,82,142,140,180,251,251,18,155,137,182,141,118,18,214,230,226,72,14,9,255,120,224,68,253,253,227,1,202,202,110,206,
101,177,31,191,36,95,120,0,207,117,47,150,14,11,0,129,187,193,19,141,59,47,214,230,226,117,57,226,187,224,9,118,19,184,187,155,179,66,253,250,204,128,105,141,102,247,58,78,108,180,129,19,246,219,167,58,
26,2,4,62,9,158,106,252,187,114,222,239,1,61,193,174,67,185,106,237,250,204,128,41,141,6,160,102,85,150,103,23,113,244,118,114,173,193,163,167,154,149,231,203,71,230,45,133,173,2,21,181,132,146,202,211,
119,107,16,247,80,227,226,97,159,124,50,199,235,249,21,10,91,245,85,220,89,121,53,191,74,33,153,101,248,222,40,146,211,202,232,231,99,168,89,149,149,231,203,103,154,47,159,204,177,60,187,136,123,168,139,
190,91,131,199,246,95,158,93,212,115,88,163,48,173,209,42,106,153,68,116,19,79,208,123,172,209,182,99,137,134,229,125,53,217,141,44,158,96,207,177,70,83,101,149,68,116,243,212,122,155,145,94,218,38,19,
79,17,152,248,0,201,9,189,31,250,81,82,202,153,141,166,202,197,61,141,194,137,140,118,222,235,57,11,166,53,90,51,94,205,175,144,136,190,38,120,255,6,78,191,139,27,95,132,208,202,135,239,88,121,93,102,
229,217,82,211,121,94,62,141,161,202,10,161,169,200,69,202,173,186,222,95,136,146,64,104,42,130,205,101,229,230,87,97,228,117,153,215,243,171,196,102,22,240,133,7,240,133,253,92,187,51,68,95,196,175,143,
219,175,174,99,51,11,84,74,71,127,36,125,53,191,74,122,105,75,223,23,51,113,37,141,86,72,230,40,36,161,84,40,3,224,10,120,234,250,104,218,113,95,181,65,94,203,28,27,9,207,19,185,234,133,169,32,137,184,
135,189,104,154,128,42,23,81,229,34,158,96,55,0,142,94,39,142,94,103,221,248,76,60,221,116,254,66,50,71,38,158,214,247,197,76,8,126,239,180,225,255,35,176,186,108,136,210,129,49,148,212,193,55,78,65,18,
245,59,26,160,156,47,83,218,171,48,107,199,85,83,41,105,168,53,37,190,228,148,176,216,14,42,177,98,70,65,171,160,191,212,60,106,220,105,145,236,210,161,138,175,40,171,53,223,58,27,95,175,118,92,45,213,
251,2,32,90,45,88,59,15,98,133,154,45,81,81,203,77,247,211,40,4,191,119,58,3,184,141,22,210,166,165,201,136,192,159,70,171,104,211,242,252,33,106,240,131,209,42,218,180,52,21,65,168,60,182,100,11,207,
254,113,219,63,181,35,240,177,209,138,218,180,28,21,77,224,219,141,183,143,158,88,0,100,229,217,207,157,29,247,94,8,8,253,128,15,176,25,171,175,205,21,103,7,248,69,16,42,83,27,111,31,61,1,248,31,81,60,
248,234,53,15,118,21,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newRowDown_png = (const char*) resource_PatchEditor_newRowDown_png;
const int PatchEditor::newRowDown_pngSize = 1480;

// JUCER_RESOURCE: newCommandNormal_png, 2065, "../../UI/NewCommandNormal.png"
static const unsigned char resource_PatchEditor_newCommandNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,7,142,
73,68,65,84,104,129,237,155,75,108,84,215,25,128,191,115,239,157,247,203,175,193,3,12,97,32,164,184,9,80,42,65,202,34,11,218,74,17,82,43,154,101,218,21,203,118,85,186,106,83,169,82,86,73,151,176,99,87,
117,65,213,101,161,141,26,169,2,90,41,85,29,32,165,193,132,218,9,246,56,126,192,48,30,123,60,158,247,220,87,23,227,185,243,158,177,135,161,142,201,124,146,229,123,124,206,127,238,127,255,243,159,115,254,
251,159,107,193,38,227,67,151,127,36,48,47,2,167,1,15,3,6,244,78,22,184,109,194,165,167,235,23,175,3,8,128,208,240,165,223,98,242,203,29,85,109,192,11,137,48,197,251,79,82,63,255,181,216,92,201,254,36,
20,193,193,55,143,16,60,49,142,236,84,118,90,191,1,187,24,189,160,17,255,52,198,194,223,102,49,53,19,83,24,231,101,159,243,220,21,32,18,57,247,10,161,215,247,35,41,210,78,235,57,96,151,35,41,18,190,176,
31,217,161,144,122,180,134,64,132,36,224,20,64,240,196,248,14,171,55,224,69,163,198,167,78,73,128,23,24,108,151,3,250,142,226,178,85,46,125,91,243,46,115,243,183,232,80,215,174,254,171,140,217,230,239,
187,237,57,118,1,93,29,237,238,251,31,161,21,53,0,60,33,15,199,127,122,218,170,139,77,46,49,255,225,35,171,124,244,237,99,12,79,140,61,7,53,251,207,212,149,59,100,99,217,150,117,35,19,163,124,227,237,
227,255,103,141,94,108,182,181,95,26,154,73,49,89,64,178,75,216,60,246,231,165,211,115,69,205,150,48,74,6,134,86,94,206,236,1,7,66,148,151,48,83,55,40,165,75,24,170,65,49,89,64,118,202,181,203,255,128,
22,84,236,89,193,62,84,181,103,45,219,114,180,124,34,199,189,203,147,187,122,198,71,255,60,195,218,244,170,85,254,214,207,78,91,241,105,46,150,225,254,149,187,172,207,38,185,119,121,146,189,103,194,28,
60,119,100,167,84,221,21,52,218,243,244,175,222,104,25,239,247,244,6,160,102,53,54,162,235,20,86,243,109,219,164,23,82,152,122,235,32,200,30,112,224,28,113,1,144,139,103,209,178,170,85,231,59,24,64,72,
245,51,66,203,169,228,158,86,183,57,231,168,11,187,223,209,139,234,29,145,236,50,254,200,144,85,118,140,186,172,235,70,61,107,145,29,50,158,125,62,0,74,27,197,58,187,184,199,61,40,238,234,170,88,107,151,
126,200,85,40,172,229,41,165,138,45,245,19,178,192,247,82,0,104,182,101,59,90,141,195,179,208,147,163,165,23,83,60,252,253,127,58,182,153,185,58,101,197,118,141,212,174,20,75,55,231,186,206,136,244,66,
138,153,63,62,176,202,145,115,71,8,157,9,247,162,122,71,156,35,46,94,189,112,178,101,93,163,158,181,212,198,174,107,15,87,58,198,173,181,118,233,135,92,133,167,183,151,121,50,185,212,82,63,197,161,112,
234,157,55,128,102,91,182,163,221,202,212,43,125,207,105,36,103,18,104,57,13,67,55,16,178,196,216,241,61,86,93,41,85,36,21,77,146,95,201,178,114,47,134,55,236,111,217,135,169,27,36,238,199,81,220,10,195,
71,119,246,229,34,179,188,65,62,158,163,176,185,90,12,31,29,67,113,149,205,102,234,6,137,169,56,106,78,103,229,94,12,251,80,243,42,155,138,38,209,242,213,9,103,232,213,120,166,31,114,129,67,195,0,120,
194,62,130,39,67,77,253,36,166,226,24,186,193,202,189,24,138,187,121,184,189,251,253,184,130,110,171,156,156,89,69,203,171,36,166,226,200,78,197,26,191,82,170,72,106,46,217,36,95,104,179,138,54,210,119,
71,91,186,21,181,222,230,20,135,194,203,111,77,88,117,201,233,4,169,104,146,245,217,242,79,164,77,252,99,168,6,179,215,166,241,132,60,59,238,104,171,83,241,186,149,226,192,119,35,184,67,94,160,124,212,
146,152,138,83,218,40,48,123,109,154,145,137,81,252,145,225,58,249,216,199,203,109,251,238,135,92,197,209,198,142,141,51,118,172,57,233,158,252,111,2,173,168,89,246,12,159,61,84,87,63,118,124,79,221,238,
48,117,229,14,90,94,37,250,193,231,40,142,170,163,101,159,164,153,189,54,221,86,167,110,108,203,209,236,94,59,123,78,237,163,144,200,145,120,16,239,218,94,215,13,150,110,205,91,229,252,106,174,171,204,
242,71,11,214,117,41,163,178,116,107,126,75,114,95,119,214,31,173,145,89,220,104,250,187,94,179,18,246,66,41,83,34,126,231,177,53,6,190,176,159,192,145,17,171,126,245,65,156,124,162,251,248,108,203,209,
108,94,27,225,179,17,146,211,137,45,57,154,169,25,44,253,99,126,59,183,224,113,141,163,169,153,210,182,229,191,174,164,30,173,181,141,209,158,5,173,97,12,188,97,63,225,179,17,171,156,139,165,251,239,104,
21,60,251,188,188,252,214,55,73,205,174,146,152,106,239,112,146,77,226,208,15,142,182,173,247,134,125,184,199,189,12,79,236,97,241,214,92,219,183,166,10,129,35,195,140,29,11,225,13,251,58,182,235,149,
82,170,200,194,205,168,85,30,170,153,185,189,178,247,59,97,220,123,125,214,243,29,250,225,43,0,68,255,242,69,95,228,82,143,146,172,76,61,37,187,188,81,39,87,33,250,193,12,134,250,108,171,90,63,232,201,
209,236,126,39,193,147,78,244,130,218,217,209,36,137,224,201,206,135,245,174,177,114,32,26,155,92,232,234,104,238,49,79,215,254,158,5,45,175,146,248,52,102,149,109,174,103,15,97,253,135,134,24,158,24,
179,158,175,18,71,117,115,180,173,202,229,19,217,58,157,43,114,21,190,252,235,23,24,236,82,71,235,196,225,243,19,232,37,131,153,63,220,71,87,53,62,251,93,115,26,100,244,181,32,161,215,247,183,237,67,182,
203,28,253,201,9,10,107,57,230,174,207,244,85,191,3,223,63,76,232,204,75,204,93,159,166,176,150,103,250,234,20,108,230,139,12,85,7,192,247,82,128,3,223,59,140,221,95,62,253,24,158,8,178,120,115,142,244,
66,138,217,235,51,72,54,185,220,153,81,206,107,57,71,92,28,62,63,129,205,163,144,154,109,126,51,131,170,93,36,187,130,81,106,157,246,233,69,110,244,181,32,238,144,143,216,237,101,214,30,198,89,184,17,
229,241,191,170,91,168,174,110,253,94,173,112,142,186,120,245,194,183,73,47,174,179,120,35,74,226,179,21,50,79,50,86,125,126,37,211,65,186,74,223,29,173,146,72,20,66,96,26,144,254,114,189,169,141,119,
175,183,99,31,66,8,252,145,0,138,83,238,183,122,184,130,30,92,65,144,237,229,239,238,210,139,169,166,54,54,183,130,63,18,176,202,206,17,23,182,205,212,64,246,113,186,169,189,108,151,172,246,237,28,173,
49,193,186,85,186,201,217,124,14,108,62,7,201,233,21,0,242,43,221,147,177,219,65,178,201,248,35,1,244,66,57,89,173,166,139,168,233,173,165,52,106,17,161,161,75,38,192,153,119,207,182,108,80,218,40,96,
26,229,25,47,20,129,221,91,61,227,212,75,26,90,78,183,202,54,175,205,250,112,178,86,174,17,197,33,35,55,108,75,165,76,9,115,243,252,81,72,38,118,191,19,67,55,81,211,165,142,114,189,82,123,191,70,36,155,
132,205,83,127,198,169,102,213,182,177,78,173,93,58,217,196,194,132,98,77,152,32,217,36,36,155,232,73,174,162,167,158,215,208,138,58,157,16,138,64,113,42,168,153,234,9,135,226,150,145,237,85,155,182,26,
7,0,67,51,234,228,218,225,8,56,234,190,126,153,124,247,239,229,251,0,105,192,167,23,180,150,153,224,202,141,90,33,219,149,58,37,183,42,215,178,189,183,249,144,94,146,5,142,22,201,204,126,208,234,126,157,
104,116,188,118,116,178,137,133,160,229,115,245,42,7,32,187,148,45,79,194,78,54,109,103,23,73,145,182,61,22,90,222,114,204,13,9,248,4,32,94,19,80,14,24,208,15,226,159,60,169,92,222,149,61,206,115,73,1,
63,222,152,79,34,59,20,220,163,110,36,219,224,255,6,6,244,142,150,87,137,125,188,204,226,173,121,48,77,67,8,227,130,0,216,27,184,252,158,41,204,119,118,88,191,1,47,30,134,41,248,205,211,228,197,247,100,
128,76,241,195,27,30,215,155,255,22,136,113,32,8,236,206,175,26,7,124,85,72,3,255,20,194,184,16,75,254,226,42,192,255,0,46,144,108,250,113,161,243,121,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newCommandNormal_png = (const char*) resource_PatchEditor_newCommandNormal_png;
const int PatchEditor::newCommandNormal_pngSize = 2065;

// JUCER_RESOURCE: newCommandOver_png, 2117, "../../UI/NewCommandOver.png"
static const unsigned char resource_PatchEditor_newCommandOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,7,194,
73,68,65,84,104,129,237,154,91,80,211,87,26,192,127,255,92,72,66,8,33,92,131,139,128,216,169,40,10,78,149,226,204,186,47,130,59,118,196,138,79,219,78,93,245,205,206,172,221,213,39,199,44,219,234,78,189,
204,244,161,160,235,204,118,125,88,215,203,236,78,31,168,10,118,116,170,190,80,182,88,133,233,184,235,165,22,20,86,102,19,174,33,129,144,144,144,100,31,98,254,73,200,13,98,86,138,205,239,233,156,156,243,
157,124,255,239,124,255,239,124,231,75,4,158,83,144,213,188,93,192,187,31,168,6,212,164,72,145,56,54,224,91,47,52,13,142,239,191,2,32,0,232,117,77,39,240,114,112,65,85,75,241,74,34,120,133,227,70,203,
239,12,194,243,72,118,73,158,230,225,224,193,255,176,125,219,48,154,76,247,66,235,151,98,17,51,97,149,242,197,229,60,62,249,164,24,151,83,130,87,240,188,45,213,40,183,252,25,40,53,24,250,217,249,158,9,
133,194,187,208,122,166,88,228,40,20,94,170,170,38,201,200,112,211,222,158,133,128,160,151,0,235,1,182,111,27,94,96,245,82,188,106,108,127,123,196,223,92,47,1,50,128,212,113,153,34,233,104,181,51,254,
166,70,54,23,1,175,87,0,64,16,194,143,85,255,88,180,241,31,51,193,186,7,179,216,158,99,49,16,215,209,170,171,171,153,152,144,2,80,94,110,227,210,165,127,137,99,231,254,166,231,216,241,82,177,127,250,79,
223,83,91,103,78,190,150,255,7,26,26,214,240,232,81,228,42,78,109,237,24,167,79,63,126,201,26,189,218,204,41,162,249,113,57,37,12,12,40,81,169,102,200,201,153,137,47,240,35,100,116,84,134,221,46,195,229,
148,0,80,88,56,141,196,215,196,229,18,24,26,74,195,225,144,50,48,160,68,163,153,9,14,255,41,34,224,183,167,159,37,75,28,162,61,131,153,151,163,245,62,81,81,87,183,118,81,191,241,31,126,88,198,205,155,
217,98,255,202,229,123,98,126,250,232,97,58,13,59,42,233,232,208,82,87,183,150,93,187,140,24,12,253,11,165,234,162,96,182,61,239,124,123,39,98,190,63,47,71,243,99,54,203,185,125,91,75,127,191,42,234,156,
238,46,13,174,153,8,174,13,232,245,211,148,148,56,0,248,225,135,116,198,198,228,226,216,186,117,86,100,178,208,28,201,108,150,241,248,113,224,152,43,45,181,83,80,224,76,68,245,152,164,171,61,188,249,166,
85,236,151,148,58,196,246,108,61,131,81,171,103,88,189,218,6,192,224,96,26,125,125,1,187,188,254,186,13,157,46,16,21,131,237,146,12,57,63,253,253,74,76,38,69,68,253,228,50,15,111,172,155,0,194,109,25,
141,72,251,240,34,36,228,104,221,221,26,118,239,94,25,115,206,222,247,203,197,220,110,54,193,145,162,169,169,40,238,27,209,221,165,225,55,251,86,136,125,195,161,62,118,237,54,37,162,122,76,138,139,29,
156,59,247,32,226,216,108,61,131,9,206,93,175,95,203,142,153,183,6,219,37,25,114,126,46,94,44,224,220,185,194,136,250,105,52,110,238,220,185,3,132,219,50,26,209,34,83,162,36,228,104,177,184,117,75,199,
248,184,28,167,83,64,46,247,82,95,47,214,82,48,26,21,116,118,102,210,219,155,78,75,75,62,149,85,147,17,215,112,185,4,90,91,243,200,202,114,177,105,211,194,94,46,238,221,83,211,211,163,230,191,70,95,180,
216,180,201,44,230,109,51,46,129,214,182,92,198,199,229,180,180,228,179,100,137,35,76,190,179,83,139,197,26,136,132,78,103,224,166,155,12,185,13,27,124,17,184,178,106,146,29,59,194,107,161,109,109,185,
56,157,2,45,45,249,100,101,185,194,198,43,43,109,44,95,62,37,246,111,221,210,97,177,200,104,189,154,139,70,227,102,219,243,253,51,26,21,124,243,141,54,76,222,111,151,120,36,221,209,78,158,44,18,111,115,
26,141,155,227,199,123,197,177,155,55,116,116,118,102,210,209,161,165,163,67,139,225,80,95,196,53,28,118,9,6,67,25,229,229,182,5,119,180,182,182,220,144,72,241,219,15,158,81,190,210,183,49,19,86,41,173,
109,185,152,76,105,24,12,101,212,214,142,81,19,116,244,2,156,191,160,143,186,118,50,228,252,142,86,191,117,148,250,173,163,97,115,111,220,200,102,98,66,42,218,243,131,125,3,33,227,245,91,135,67,78,135,
134,134,53,88,44,50,254,120,100,89,136,163,61,184,159,142,193,80,22,85,167,120,204,203,209,242,114,157,252,234,157,33,158,62,81,114,245,203,220,184,243,167,167,5,78,157,42,18,251,79,159,70,207,233,252,
252,229,204,207,196,246,200,72,26,167,78,21,205,73,238,167,78,123,123,22,223,125,151,17,246,249,244,116,228,90,225,92,25,30,73,227,31,127,207,23,247,96,109,213,4,27,127,97,17,199,191,188,154,195,147,57,
236,207,188,28,45,39,215,197,190,125,3,220,188,161,155,147,163,57,157,18,78,159,46,138,59,47,152,51,103,150,136,237,145,17,249,188,229,127,170,180,183,107,163,230,104,47,194,232,176,44,100,15,42,171,38,
217,23,20,21,31,62,76,79,190,163,249,169,88,109,227,196,137,94,58,190,214,210,218,22,221,225,148,74,55,135,15,247,69,29,95,83,57,201,138,114,59,155,55,155,105,110,46,194,24,231,188,255,249,198,113,182,
213,143,178,166,50,114,110,247,162,24,141,10,154,154,3,70,221,184,209,18,99,246,220,216,245,107,19,171,42,108,226,243,125,244,209,83,0,142,28,89,150,20,185,142,175,179,184,210,150,195,191,239,101,132,
200,249,57,124,184,20,135,35,242,165,236,101,146,144,163,233,245,78,26,26,134,177,90,164,49,29,77,46,135,134,134,216,63,214,47,47,179,3,112,246,172,62,174,163,45,47,179,199,93,239,69,176,140,75,185,124,
41,79,236,107,51,95,188,88,91,83,99,161,182,206,44,62,95,253,86,95,206,19,207,209,230,42,215,219,171,12,209,217,47,231,231,232,209,82,28,225,119,141,151,78,210,47,3,71,143,62,97,106,74,202,222,189,43,
152,154,146,176,115,231,170,176,57,91,222,26,99,231,123,209,203,19,233,233,110,62,251,236,123,250,251,149,52,54,38,158,128,70,226,192,129,103,236,217,99,162,177,177,140,254,126,37,123,223,47,71,34,241,
213,139,236,118,223,155,255,198,186,9,14,236,127,38,214,234,54,111,54,243,105,211,82,186,187,52,252,190,113,57,42,149,239,218,239,241,248,242,159,146,18,7,31,127,252,4,157,206,197,63,59,194,111,102,16,
176,75,186,218,195,148,45,114,125,49,17,185,45,91,198,88,185,106,138,11,23,244,92,191,158,205,167,77,197,252,245,108,224,8,157,154,154,251,119,69,162,164,212,193,249,243,15,232,234,210,208,212,180,148,
107,215,115,120,240,32,80,135,235,233,73,159,211,58,73,119,180,138,231,97,91,42,5,183,91,224,238,221,204,176,57,171,86,217,194,62,11,70,42,133,234,106,43,154,140,228,255,252,243,218,107,118,192,46,58,
75,119,183,38,108,142,46,203,69,117,117,224,22,88,92,236,64,247,188,52,112,255,126,120,177,83,165,114,139,243,163,57,90,69,69,236,103,142,70,60,185,252,2,39,249,5,78,190,250,74,7,64,79,143,10,72,222,229,
73,165,242,80,93,109,197,106,241,189,132,67,131,105,12,13,166,205,123,29,65,159,213,228,5,120,244,168,51,226,4,147,41,77,124,115,101,114,15,249,121,129,90,140,205,38,197,98,9,248,106,78,142,11,133,194,
19,38,55,155,140,12,55,153,179,142,165,161,97,57,51,46,223,219,39,145,120,209,235,157,184,92,2,195,195,105,49,229,18,37,248,251,102,163,84,122,200,206,14,173,57,141,141,201,113,56,34,207,15,182,75,44,
155,248,241,122,5,140,198,192,115,41,149,30,20,10,79,66,114,126,61,173,86,25,147,147,177,115,49,153,220,131,54,211,205,232,104,160,62,167,213,206,160,86,7,10,179,145,246,1,96,122,90,18,34,23,141,194,66,
103,200,191,95,202,203,55,0,62,71,179,2,154,100,87,130,83,164,176,88,100,212,212,172,7,176,74,128,46,128,47,46,231,197,20,74,145,98,190,124,254,121,190,191,121,87,170,86,110,49,11,240,110,231,237,76,50,
50,220,44,91,230,8,11,217,41,82,204,7,139,69,198,249,243,122,154,79,46,197,227,17,60,130,224,217,35,0,20,106,155,143,121,5,239,161,133,86,48,197,43,135,199,43,240,135,65,243,254,99,82,128,201,233,107,
55,213,170,95,118,11,8,5,64,30,48,255,107,69,138,20,1,38,128,14,65,240,236,49,153,15,92,4,248,31,2,133,74,237,72,213,205,218,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newCommandOver_png = (const char*) resource_PatchEditor_newCommandOver_png;
const int PatchEditor::newCommandOver_pngSize = 2117;

// JUCER_RESOURCE: newCommandDown_png, 1903, "../../UI/NewCommandDown.png"
static const unsigned char resource_PatchEditor_newCommandDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,6,236,
73,68,65,84,104,129,237,154,75,108,27,215,21,134,191,121,242,45,138,18,69,209,214,35,166,228,84,170,99,186,21,96,167,42,144,162,176,3,20,9,210,218,219,162,89,36,221,121,231,120,85,180,64,129,238,146,93,
221,85,187,204,38,69,150,134,209,2,222,164,245,34,5,220,216,109,221,218,73,165,214,177,24,155,177,40,139,18,197,247,107,56,211,5,197,225,75,124,136,162,203,72,225,7,8,226,229,189,231,242,159,115,207,156,
57,115,103,4,118,153,28,253,205,37,1,227,29,224,28,224,96,200,144,222,73,3,159,24,112,109,99,231,157,27,0,2,128,223,115,237,61,12,126,54,80,105,67,142,36,130,33,188,187,30,191,242,11,97,55,147,93,31,180,
160,33,71,23,67,208,47,138,187,151,203,33,67,158,27,130,33,94,21,129,179,131,22,50,228,200,115,86,4,156,131,86,49,228,200,227,146,187,26,38,236,254,55,218,244,181,234,255,42,35,180,248,254,176,29,199,
33,160,99,160,157,253,249,43,200,150,242,176,116,36,205,253,223,221,49,251,252,203,211,156,120,237,164,217,94,253,240,1,177,149,232,115,144,217,127,130,151,207,225,240,239,189,139,179,189,178,197,127,
62,188,255,127,86,116,180,233,46,163,237,34,202,2,22,143,21,189,160,83,76,23,158,151,166,231,138,226,80,17,85,17,81,46,167,179,66,60,143,97,148,83,152,32,137,168,46,21,81,17,177,120,172,148,114,37,180,
108,113,144,114,191,242,84,252,89,161,176,83,245,103,45,251,10,52,155,215,206,210,149,229,67,125,198,7,126,180,192,216,226,184,217,254,231,111,239,80,202,105,0,216,253,78,206,92,62,203,232,188,135,165,
43,203,172,223,14,243,197,205,135,131,146,122,40,104,244,231,157,247,62,54,253,89,203,190,2,173,130,226,144,25,9,140,98,29,183,181,28,227,154,117,35,72,123,23,65,133,120,158,220,118,22,0,187,207,129,236,
80,204,190,228,23,113,12,189,254,140,144,237,10,246,201,234,101,46,183,149,165,144,200,247,34,189,45,122,161,68,34,180,99,182,243,91,89,243,115,163,206,90,74,249,18,233,167,73,0,212,17,75,157,95,50,27,
105,180,76,53,43,214,250,165,31,118,21,172,99,54,84,183,101,79,125,70,201,32,249,56,14,52,251,178,21,123,173,195,65,232,41,208,92,51,110,78,189,245,237,182,99,22,222,12,154,181,93,35,181,153,98,250,194,
92,199,51,194,53,235,102,225,199,167,205,118,232,230,67,34,183,195,189,72,111,75,110,59,203,103,239,223,219,179,175,81,103,45,181,181,235,216,169,137,182,117,107,173,95,250,97,87,97,242,229,41,142,45,
79,239,169,79,203,107,220,125,247,99,160,217,151,173,104,149,153,122,165,167,64,107,135,103,193,139,108,151,17,37,17,163,164,19,189,255,204,236,83,221,22,220,1,15,182,9,7,19,75,126,82,225,196,158,115,
8,146,136,247,140,15,45,163,17,91,29,236,205,133,115,106,4,155,207,142,117,55,91,196,86,163,104,217,242,2,8,146,136,55,232,67,177,75,76,44,249,41,236,52,103,89,119,192,131,108,171,186,89,148,170,245,76,
63,236,226,107,49,0,210,225,36,155,247,34,77,243,120,131,62,68,73,100,98,201,143,150,105,14,156,212,151,9,178,155,25,179,237,89,24,71,182,41,120,131,62,74,57,205,92,63,213,109,193,61,231,105,178,183,182,
200,162,141,244,61,208,166,207,7,204,187,57,45,175,241,249,245,21,179,207,179,232,197,29,240,48,58,95,254,11,181,168,127,68,69,100,254,210,34,233,72,122,224,129,54,30,244,213,101,138,39,127,14,145,137,
164,0,144,172,50,222,160,15,117,196,202,252,165,69,182,87,182,72,132,98,117,246,254,239,76,181,156,187,31,118,149,64,139,62,216,32,250,96,163,105,172,231,155,94,100,139,108,250,51,124,107,173,174,63,122,
255,89,221,213,33,120,249,28,178,77,33,240,198,55,208,242,213,64,115,28,115,49,127,105,177,165,166,78,236,43,208,10,169,2,207,238,62,197,234,181,227,61,237,235,56,94,146,68,166,207,159,48,219,182,113,
123,71,155,169,87,102,205,207,170,83,97,250,252,137,174,236,190,238,140,158,28,195,57,51,210,244,189,84,147,9,123,65,117,170,248,206,29,55,215,32,25,78,16,127,184,109,246,143,159,246,97,243,118,94,159,
125,5,90,49,85,36,124,43,132,103,209,219,85,160,9,178,200,244,247,79,236,231,39,56,94,19,104,138,83,221,183,253,215,21,247,201,177,150,53,218,65,144,27,214,32,21,78,16,190,21,50,219,118,191,171,255,129,
86,33,253,52,197,231,215,255,141,123,126,28,111,176,117,192,233,69,157,181,63,174,182,236,79,133,147,100,54,82,196,86,158,49,115,126,174,229,93,83,133,248,195,24,209,7,17,82,225,100,219,113,189,162,186,
45,204,94,8,152,237,157,154,51,183,87,214,255,26,38,179,158,52,143,111,237,15,255,5,32,240,195,23,251,98,231,62,233,97,34,56,137,99,106,164,206,174,66,224,141,5,68,229,96,89,173,31,244,20,104,133,68,142,
205,123,57,36,171,210,62,208,116,157,205,123,205,117,67,45,217,104,185,16,245,47,207,118,12,180,76,52,221,113,190,131,32,219,20,188,223,242,155,237,98,246,224,119,93,137,181,29,98,43,81,243,248,42,117,
84,167,64,235,214,206,230,117,212,105,174,216,85,120,225,245,23,17,57,164,129,214,142,71,55,86,144,84,145,133,159,156,65,82,100,94,250,105,243,54,200,214,167,155,68,62,249,178,229,28,165,66,137,213,223,
255,11,235,152,157,185,139,11,125,213,247,228,163,71,68,110,63,102,238,226,34,214,49,27,139,111,6,97,119,191,72,84,36,0,146,143,227,60,249,211,35,10,137,242,211,143,216,202,38,51,23,230,112,205,186,153,
191,184,128,94,44,149,39,19,203,251,90,185,237,44,143,110,172,80,76,107,184,231,155,239,204,160,234,23,189,160,33,170,221,187,189,147,221,214,167,155,100,34,73,252,47,79,49,118,202,199,236,171,1,142,127,
183,122,9,149,148,131,45,113,110,43,203,103,239,255,3,215,204,40,51,175,6,240,190,52,129,243,88,245,61,12,219,68,119,47,99,247,61,208,42,27,137,134,97,32,136,224,122,97,180,105,76,106,61,213,118,14,195,
48,72,132,226,104,185,82,191,229,145,221,76,147,221,132,82,65,7,202,123,130,141,20,51,26,137,80,220,108,231,182,179,20,119,183,6,28,199,93,77,227,75,5,221,28,223,42,208,26,55,88,187,165,147,93,49,153,
167,152,204,227,89,156,0,186,95,248,110,209,139,37,18,161,56,146,181,188,89,173,184,44,40,174,238,182,52,106,17,252,163,215,218,110,255,170,35,86,4,177,60,196,208,12,10,169,234,51,78,73,149,145,237,146,
217,46,166,138,232,154,222,100,215,136,150,47,81,106,184,44,169,78,21,97,247,249,163,161,11,20,18,57,68,73,64,113,169,109,237,122,165,246,247,26,209,139,58,197,116,253,51,78,197,161,180,172,117,106,253,
210,206,39,38,2,88,106,202,4,189,168,163,23,141,158,236,42,58,37,155,140,108,145,104,135,161,25,104,57,13,197,89,125,194,161,101,74,148,10,85,159,238,181,14,0,162,44,214,217,181,34,31,207,239,249,246,
139,224,31,189,150,0,154,79,211,33,67,250,71,66,4,254,54,104,21,67,142,60,119,69,3,126,61,104,21,67,142,52,186,32,232,191,146,210,185,155,171,46,203,235,22,4,190,55,104,69,67,142,28,186,33,240,203,72,
236,234,7,18,64,42,127,243,35,135,237,7,127,23,16,38,129,9,64,109,111,63,100,72,91,146,192,95,4,65,127,59,18,187,250,1,192,255,0,40,71,226,9,199,234,230,107,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::newCommandDown_png = (const char*) resource_PatchEditor_newCommandDown_png;
const int PatchEditor::newCommandDown_pngSize = 1903;

// JUCER_RESOURCE: deleteNormal_png, 1552, "../../UI/DeleteNormal.png"
static const unsigned char resource_PatchEditor_deleteNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,141,73,
68,65,84,104,129,237,154,207,111,219,100,24,199,63,175,227,196,249,225,164,89,89,186,116,84,89,167,21,105,234,164,169,155,0,129,196,97,167,105,92,96,87,14,72,227,47,96,156,16,72,72,227,50,56,142,27,71,
56,112,227,48,56,77,32,68,145,134,40,136,177,238,176,209,67,171,165,33,91,188,165,75,210,252,180,19,59,230,208,198,141,105,147,117,109,215,54,197,159,147,95,191,126,158,247,113,252,205,243,62,239,107,
11,86,57,18,255,226,109,129,125,25,120,5,136,224,225,177,117,106,192,31,54,92,123,84,186,252,61,128,0,72,30,186,246,57,54,31,238,105,104,30,7,18,97,139,207,114,203,239,127,44,86,51,217,117,33,11,142,157,
159,32,113,250,8,190,160,188,215,241,121,12,48,150,110,242,248,142,70,230,199,5,108,211,198,22,237,183,124,209,224,133,47,129,241,241,11,47,145,124,245,69,36,89,218,235,56,61,6,28,73,150,136,142,197,240,
41,50,203,243,5,4,34,41,1,47,3,36,78,31,217,227,240,60,14,26,93,154,122,89,2,84,192,155,46,61,118,28,57,228,239,28,70,7,79,93,118,159,62,177,107,81,120,60,35,3,39,180,153,79,167,123,246,141,157,27,103,
236,220,248,174,197,226,177,121,6,78,104,221,72,178,132,95,13,96,53,45,204,122,11,75,55,49,138,58,114,196,143,47,224,219,146,207,102,181,137,221,106,187,206,9,159,32,16,83,118,34,100,44,221,196,108,152,
78,219,175,6,144,252,7,127,1,54,208,66,83,199,162,76,94,58,67,126,86,99,225,250,28,185,153,44,185,153,44,39,46,158,36,49,149,220,146,207,249,111,239,82,78,47,187,206,41,113,133,51,151,95,223,137,144,201,
205,100,201,78,167,157,246,228,165,41,98,227,241,29,241,189,159,25,104,161,117,8,168,1,98,227,113,140,146,142,81,210,105,44,213,41,223,47,17,25,85,157,69,78,249,126,169,167,189,114,40,136,18,15,2,16,78,
70,1,65,53,91,166,109,182,123,218,24,37,29,163,168,247,236,143,29,95,17,143,165,155,212,114,213,46,187,134,235,186,186,86,117,213,157,189,236,254,75,247,189,13,2,131,19,105,31,134,38,134,25,154,24,38,
59,157,38,59,157,230,225,205,12,15,111,102,92,217,226,222,215,179,61,237,187,107,187,241,11,19,0,220,190,246,27,70,201,232,105,147,159,213,92,153,233,191,188,118,229,28,0,53,173,218,119,236,244,141,249,
45,217,13,90,38,60,16,66,235,71,225,222,99,44,99,37,51,249,2,62,134,39,19,78,159,94,104,80,201,44,83,215,42,228,111,107,68,143,13,17,28,14,245,245,167,23,26,84,22,87,108,0,162,41,183,77,225,94,30,171,
105,145,191,173,225,83,36,194,35,170,107,26,175,105,213,149,44,182,74,124,98,24,191,26,112,218,86,211,162,112,55,79,227,73,29,128,224,112,136,104,106,200,233,175,100,150,209,11,13,74,243,5,140,162,206,
240,169,196,150,235,209,221,228,192,11,109,241,135,5,39,51,201,97,153,19,23,79,58,125,249,89,141,74,102,153,194,220,19,10,115,79,56,113,241,228,83,133,86,201,44,179,240,221,156,211,30,57,59,234,18,82,
57,93,196,106,90,44,124,55,231,212,118,221,99,102,167,211,46,161,29,125,35,229,202,76,70,73,119,249,143,166,98,46,251,133,235,127,163,23,26,60,188,153,1,86,166,90,79,104,251,12,171,97,145,253,57,237,180,
235,143,42,219,246,89,156,203,187,106,53,171,97,109,219,103,55,117,173,234,142,89,235,93,183,237,103,254,87,66,51,13,147,236,47,233,29,245,217,201,134,207,139,154,86,163,166,213,158,155,255,221,226,64,
8,173,146,89,230,209,173,28,141,213,12,53,114,246,40,209,212,16,161,195,97,215,117,114,216,207,177,243,19,61,253,68,83,177,103,30,187,51,214,70,248,2,219,223,31,139,166,134,24,57,123,180,103,191,63,226,
239,217,183,159,56,16,66,211,11,13,150,238,104,78,59,154,138,145,152,90,255,145,128,47,32,109,120,126,59,244,26,107,167,8,14,7,159,171,255,221,66,36,227,215,108,88,91,86,239,119,102,174,76,59,199,178,
34,19,74,170,180,106,77,244,165,58,137,169,36,137,169,81,66,135,67,206,74,110,101,63,204,230,222,87,183,17,178,132,250,226,250,172,53,114,38,233,20,244,139,55,230,169,230,170,84,31,148,177,87,247,209,
58,118,234,168,202,209,55,82,52,150,26,228,103,115,228,103,53,130,135,195,248,35,129,117,62,79,189,55,181,97,252,70,201,192,40,233,60,188,185,72,105,190,64,36,25,65,82,214,178,210,228,187,167,169,100,
43,212,180,10,139,55,230,241,171,1,130,47,132,215,249,57,254,230,4,225,164,186,249,31,110,143,232,60,175,129,206,104,166,97,82,89,92,219,136,85,226,65,98,227,238,105,76,29,91,19,150,109,182,93,215,119,
24,58,190,182,234,171,105,21,42,139,238,55,3,29,59,33,108,252,106,0,191,26,160,156,46,2,160,47,213,209,151,234,155,142,89,137,43,40,113,133,252,172,127,117,60,119,253,37,100,105,245,30,86,118,113,91,213,
38,173,106,115,157,31,83,55,215,157,219,207,12,92,70,235,183,137,234,11,249,144,149,141,255,59,155,181,107,85,155,180,205,141,63,17,145,100,225,100,74,211,48,251,174,48,149,120,255,119,163,102,189,133,
213,92,255,230,161,99,103,155,109,154,213,86,79,251,128,234,71,12,192,71,170,221,25,173,2,68,45,221,28,136,87,26,79,123,128,219,181,235,222,60,237,135,172,200,61,69,189,41,251,176,31,121,253,140,232,32,
100,105,203,247,186,95,48,27,206,31,165,44,1,183,0,30,119,21,211,30,30,59,193,227,91,185,206,225,159,190,72,240,66,81,192,59,229,116,17,159,34,19,126,33,252,191,248,108,197,227,249,97,54,90,104,191,63,
224,159,159,211,96,219,109,33,218,151,4,192,232,208,23,87,109,97,127,180,199,241,121,28,60,218,182,224,147,71,197,203,87,125,0,85,227,198,79,145,208,249,191,4,226,8,144,0,54,87,168,120,120,108,76,5,248,
85,136,246,37,173,248,193,55,0,255,2,44,236,41,184,177,161,17,203,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::deleteNormal_png = (const char*) resource_PatchEditor_deleteNormal_png;
const int PatchEditor::deleteNormal_pngSize = 1552;

// JUCER_RESOURCE: deleteOver_png, 1593, "../../UI/DeleteOver.png"
static const unsigned char resource_PatchEditor_deleteOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,182,73,
68,65,84,104,129,237,154,77,80,83,87,20,128,191,151,64,254,31,4,76,64,35,26,193,142,2,11,25,65,208,141,27,23,213,141,226,79,233,76,167,213,113,163,43,102,170,221,160,180,221,66,29,55,90,113,166,163,51,
206,20,236,162,118,4,237,74,102,196,13,211,25,163,66,139,11,146,46,52,141,19,168,10,22,200,131,64,18,72,186,8,121,16,224,33,98,48,4,243,173,222,189,231,158,115,207,123,57,57,247,220,251,158,192,52,249,
230,203,213,2,145,51,64,37,96,36,77,154,229,51,6,60,138,192,165,87,195,103,126,7,16,0,214,231,92,250,129,8,117,73,117,45,205,154,68,136,8,141,255,142,124,93,47,76,103,178,59,153,154,48,117,117,47,168,
62,56,128,152,53,149,108,255,210,164,48,146,79,77,219,93,43,23,47,110,38,20,84,17,17,194,135,212,162,238,192,79,192,150,250,122,15,95,125,249,18,173,54,146,108,63,211,164,56,90,109,132,178,178,81,76,166,
41,58,59,205,8,8,235,85,192,46,128,234,131,3,73,118,47,205,90,163,250,208,96,236,114,151,10,48,1,233,229,50,77,194,201,206,158,140,93,138,25,201,116,100,57,68,34,130,162,76,16,210,203,254,106,37,229,2,
173,164,100,183,162,172,182,214,75,109,173,247,3,122,147,102,169,164,92,160,205,70,171,9,99,177,134,240,251,213,12,13,101,224,243,169,241,122,117,228,230,134,48,24,150,87,10,12,12,106,8,76,168,226,250,
50,51,195,228,231,7,19,225,50,146,79,205,136,47,83,110,91,173,65,180,218,112,66,108,175,102,82,58,208,118,148,141,210,210,210,75,91,155,149,243,231,183,210,220,188,129,230,230,13,52,54,62,227,200,145,
229,109,110,190,57,251,9,143,31,103,197,245,217,108,1,30,60,248,51,17,46,243,115,243,6,154,154,10,228,118,115,115,47,85,85,190,132,216,94,205,164,116,160,197,176,90,130,84,85,249,232,235,211,210,215,167,
229,249,115,61,14,71,54,165,37,163,242,38,199,225,200,86,212,47,40,152,96,227,198,0,0,37,165,126,4,1,122,254,50,17,8,170,20,117,250,250,180,120,189,58,69,249,238,221,35,64,52,131,245,58,77,114,191,215,
171,141,27,231,114,26,226,234,78,37,189,185,204,190,183,84,64,88,111,190,20,1,112,185,30,38,219,151,37,81,92,188,71,190,174,172,244,209,210,210,43,183,155,154,10,20,179,197,108,189,185,44,84,219,237,219,
183,147,254,254,104,80,44,148,209,230,206,53,151,216,243,124,244,40,139,19,39,74,223,118,91,239,172,151,42,153,48,246,220,215,68,70,91,140,246,246,92,198,198,162,183,105,48,76,177,127,255,127,178,204,
243,66,71,119,151,136,211,105,160,181,53,143,138,10,31,118,251,196,162,246,60,30,29,93,93,89,56,157,6,0,202,43,36,236,155,103,116,218,219,115,241,251,213,180,182,230,97,52,78,178,109,219,120,220,50,238,
116,25,113,77,235,2,236,221,59,140,197,18,146,219,126,191,154,123,247,214,225,118,71,179,165,221,62,65,121,185,36,203,187,187,69,60,30,29,157,157,102,188,94,29,7,14,188,89,118,61,250,33,89,243,129,118,
225,130,93,206,76,102,243,36,141,141,207,100,89,91,155,149,238,46,145,142,142,92,58,58,114,105,108,124,246,214,64,235,238,22,169,175,47,146,219,53,159,189,142,11,36,135,35,11,191,95,77,125,125,145,156,
9,103,207,217,212,84,16,23,104,167,78,245,199,101,166,190,62,109,156,253,157,59,165,56,253,115,231,182,226,241,232,184,126,221,6,68,151,218,116,160,173,50,36,41,131,43,87,102,150,59,151,203,176,200,232,
165,113,255,126,78,92,221,37,73,137,125,164,46,151,33,225,62,39,131,143,44,208,212,92,189,170,92,87,45,135,88,54,92,41,92,46,35,46,87,234,127,181,181,38,2,173,187,75,228,215,223,242,248,123,250,223,94,
83,51,64,69,133,143,162,162,241,184,113,57,57,147,212,213,121,20,237,204,174,133,150,74,108,174,133,48,232,223,127,73,43,175,144,248,188,230,181,162,60,55,55,164,40,91,77,172,137,64,243,188,208,113,247,
142,85,110,151,151,251,56,124,120,254,57,154,94,63,181,96,255,251,160,52,87,162,216,188,105,98,69,237,127,40,82,250,120,67,20,167,216,190,125,140,55,111,50,113,187,245,28,57,50,192,209,163,3,20,22,142,
203,59,185,158,30,19,193,160,138,227,199,75,209,104,194,236,216,49,58,207,230,177,99,3,114,65,223,208,96,167,183,215,200,211,167,81,61,64,214,43,45,29,227,244,233,126,220,110,61,173,173,86,218,218,172,
20,22,142,179,110,221,252,172,114,243,102,239,188,62,128,254,254,232,89,223,181,107,54,58,59,205,20,23,143,97,50,205,100,190,27,55,92,244,244,152,112,58,141,52,52,216,177,88,66,108,217,50,62,207,206,119,
223,254,67,113,137,255,29,158,92,114,88,19,199,27,146,164,230,201,147,153,83,252,141,27,3,84,86,198,47,99,101,101,51,129,21,12,170,226,198,199,216,179,103,70,199,233,52,206,27,19,211,19,4,176,88,66,88,
44,33,28,142,232,24,183,91,143,219,173,95,178,207,54,91,0,155,45,192,237,219,209,12,60,183,254,210,104,194,84,86,250,136,76,127,31,48,56,152,201,224,96,230,92,51,248,18,188,233,88,105,82,46,163,197,142,
42,22,66,20,39,17,197,133,235,162,165,234,13,14,102,202,153,108,46,26,77,88,206,148,146,164,94,116,135,105,179,5,20,101,0,195,195,25,248,253,106,69,189,96,80,181,96,128,197,176,88,66,104,52,171,255,29,
233,236,140,38,1,162,228,83,167,196,43,141,183,253,128,239,171,55,251,240,116,49,68,113,74,49,168,151,130,217,60,137,217,60,169,40,215,104,194,203,190,215,213,194,200,136,252,71,244,169,128,46,128,182,
187,86,69,133,52,105,150,195,173,91,121,177,203,39,106,163,238,192,144,0,95,60,116,100,97,50,77,81,88,56,241,81,124,182,146,102,229,24,25,201,160,165,101,61,151,127,220,68,56,44,132,5,33,124,82,0,216,
144,125,185,33,34,68,206,39,219,193,52,107,142,112,68,224,251,87,67,103,26,212,0,163,129,123,29,70,253,167,221,2,66,62,96,5,52,201,245,47,77,138,35,1,127,8,66,248,228,203,161,179,191,0,252,15,67,171,43,
229,14,55,140,250,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::deleteOver_png = (const char*) resource_PatchEditor_deleteOver_png;
const int PatchEditor::deleteOver_pngSize = 1593;

// JUCER_RESOURCE: deleteDown_png, 1420, "../../UI/DeleteDown.png"
static const unsigned char resource_PatchEditor_deleteDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,9,73,
68,65,84,104,129,237,154,207,79,219,102,24,199,63,142,77,108,39,118,48,41,25,166,141,66,42,56,48,122,24,104,157,196,36,166,177,75,213,93,214,30,118,95,255,131,181,167,73,147,166,245,182,221,198,254,130,
85,154,122,71,187,172,154,52,169,135,78,155,166,141,162,73,69,157,68,85,26,181,144,66,151,230,135,19,98,39,177,119,0,2,46,132,81,160,164,201,252,57,229,245,235,231,121,31,59,95,125,253,190,175,45,176,
201,128,241,237,37,1,239,42,240,14,16,37,32,224,240,148,129,223,61,152,121,154,191,250,3,128,0,96,246,205,124,141,199,103,109,45,45,160,43,17,60,225,171,149,194,167,159,11,155,78,54,219,238,130,2,186,
23,79,112,63,10,109,62,46,3,2,94,25,130,23,186,22,2,206,183,187,144,128,174,231,124,8,208,218,93,69,64,215,163,75,237,174,224,165,17,246,233,243,78,172,138,128,151,164,227,132,54,249,229,116,203,190,199,
183,151,120,124,123,233,196,106,9,56,56,29,39,180,157,184,53,151,90,217,65,12,139,72,145,30,68,69,66,238,83,168,151,107,52,156,198,161,114,134,181,48,66,79,200,119,204,107,120,56,69,251,56,74,70,84,36,
36,117,251,182,215,74,14,110,221,61,150,220,175,51,29,45,52,235,73,137,133,27,119,73,140,155,12,95,30,101,112,50,201,224,100,146,7,179,247,89,155,207,30,42,231,200,199,231,136,165,123,125,199,236,188,
205,221,153,95,143,163,100,6,39,147,36,167,211,205,246,194,141,121,138,75,249,99,201,253,58,211,209,66,219,194,177,28,138,75,121,100,67,65,54,20,212,254,8,177,179,6,229,21,139,70,181,14,64,236,172,209,
50,222,126,94,197,206,87,1,168,100,75,128,135,118,38,70,232,5,103,219,137,108,40,200,125,74,203,254,226,195,13,241,136,138,68,116,112,123,189,37,27,170,239,188,136,169,249,230,157,173,226,94,100,231,181,
117,2,93,33,180,194,98,142,194,98,142,228,116,154,228,116,154,211,83,41,78,79,165,124,110,49,246,201,120,203,248,157,115,187,165,91,139,0,76,92,125,23,217,144,91,198,36,198,77,159,51,189,200,111,215,111,
3,16,53,181,125,199,78,95,28,57,84,92,167,57,97,87,8,109,63,226,99,111,32,202,27,206,212,112,26,228,22,214,154,125,74,92,69,79,245,18,49,117,18,19,38,165,71,5,170,185,245,125,243,41,113,21,125,104,35,
6,160,148,241,199,196,199,18,136,97,145,196,132,73,195,118,169,172,90,190,199,120,212,212,54,92,108,147,252,98,142,154,229,52,219,98,88,36,126,46,129,122,42,2,64,53,183,78,41,83,104,246,235,169,94,148,
184,138,49,18,71,238,83,200,221,91,59,244,124,244,36,233,122,161,13,93,24,110,58,83,189,82,231,193,236,253,102,95,98,220,68,79,245,18,31,61,69,124,244,20,15,102,239,255,167,208,244,84,47,195,151,70,155,
237,213,185,21,159,144,98,233,62,196,176,200,240,165,209,230,220,110,231,152,201,233,180,79,104,203,119,50,62,103,146,13,197,151,191,148,41,250,226,135,47,191,137,18,87,57,61,149,2,54,30,181,129,208,94,
51,68,85,36,249,65,186,217,142,12,232,71,206,217,55,154,240,205,213,68,85,60,114,206,157,68,76,205,95,179,217,153,251,235,255,43,161,73,178,68,242,253,244,177,230,220,114,195,87,69,212,140,18,53,59,255,
171,173,174,16,154,158,234,101,224,237,65,212,77,135,90,157,91,166,148,41,176,254,172,226,59,175,94,169,241,232,167,197,150,121,74,153,226,75,143,189,53,214,94,52,156,163,239,143,149,50,5,86,231,150,91,
246,215,202,181,35,143,113,18,116,133,208,148,184,74,255,91,102,179,93,202,20,89,155,127,186,235,188,134,227,238,121,252,40,180,26,235,184,168,230,170,175,52,255,73,33,152,198,76,71,189,33,156,188,62,
221,252,93,183,235,172,103,45,122,162,97,148,254,8,107,243,89,214,230,87,88,127,182,222,92,201,105,201,24,33,73,96,236,202,4,94,221,197,122,178,219,181,86,239,102,155,19,250,161,139,35,104,131,26,218,
153,24,130,180,177,90,221,138,179,86,44,150,239,100,80,251,85,18,227,131,36,198,77,170,207,42,212,202,206,174,156,247,190,155,223,179,126,217,144,145,13,133,211,83,67,24,35,113,202,217,50,174,189,237,
74,11,223,255,133,158,212,137,154,58,67,23,71,168,89,14,213,127,42,187,242,60,252,113,145,74,214,58,248,141,107,51,29,237,104,146,44,161,15,109,111,196,218,249,42,197,37,255,99,204,122,188,45,44,65,10,
249,206,223,162,240,112,123,213,23,53,117,244,33,255,155,129,173,56,207,19,168,89,14,53,203,33,150,238,3,64,233,143,160,244,71,14,92,179,157,183,177,243,54,137,241,218,230,120,254,249,151,87,119,55,175,
97,99,23,183,71,11,211,163,133,119,229,145,148,206,250,235,58,206,209,246,219,68,109,172,55,168,219,123,239,150,31,52,174,71,11,19,146,246,254,68,196,173,123,77,167,148,100,105,223,21,166,157,223,255,
221,168,20,145,16,195,187,227,183,226,4,41,68,88,235,105,25,239,88,53,188,14,122,71,42,152,198,76,17,56,250,58,63,32,160,53,197,16,240,103,187,171,8,232,122,254,8,121,240,77,187,171,8,232,106,92,65,112,
175,139,229,234,173,191,117,249,67,25,129,247,218,93,81,64,215,225,122,2,95,100,159,95,187,41,2,88,246,173,159,163,234,133,57,1,97,0,72,0,187,151,57,1,1,7,167,4,252,34,8,238,149,236,243,107,55,1,254,5,
158,227,211,178,248,255,197,249,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PatchEditor::deleteDown_png = (const char*) resource_PatchEditor_deleteDown_png;
const int PatchEditor::deleteDown_pngSize = 1420;


//[EndFile] You can add extra defines here...
//[/EndFile]

