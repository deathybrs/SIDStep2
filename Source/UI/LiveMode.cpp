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

//[Headers] You can add your own extra header files here...
#include "../SIDProgram.h"
#include "Patches.h"
#include "SIDStepLookAndFeel.h"
//[/Headers]

#include "LiveMode.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
LiveMode::LiveMode ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    look = new SIDStepLookAndFeel;
    setLookAndFeel (
                    look );
    armed = false;
    //[/Constructor_pre]

    volumeSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (volumeSlider.get());
    volumeSlider->setRange (0, 15, 1);
    volumeSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    volumeSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    volumeSlider->addListener (this);

    volumeSlider->setBounds (384, 32, 48, 48);

    volumeLabel.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (volumeLabel.get());
    volumeLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    volumeLabel->setJustificationType (juce::Justification::centred);
    volumeLabel->setEditable (false, false, false);
    volumeLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    volumeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    volumeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    volumeLabel->setBounds (384, 8, 48, 18);

    patch1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (patch1Slider.get());
    patch1Slider->setRange (1, 2, 1);
    patch1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    patch1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    patch1Slider->addListener (this);

    patch1Slider->setBounds (32, 120, 48, 48);

    attack1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (attack1Slider.get());
    attack1Slider->setRange (0, 15, 1);
    attack1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    attack1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    attack1Slider->addListener (this);

    attack1Slider->setBounds (144, 120, 48, 48);

    decay1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (decay1Slider.get());
    decay1Slider->setRange (0, 15, 1);
    decay1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    decay1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    decay1Slider->addListener (this);

    decay1Slider->setBounds (224, 120, 48, 48);

    sustain1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (sustain1Slider.get());
    sustain1Slider->setRange (0, 15, 1);
    sustain1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    sustain1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    sustain1Slider->addListener (this);

    sustain1Slider->setBounds (304, 120, 48, 48);

    release1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (release1Slider.get());
    release1Slider->setRange (0, 15, 1);
    release1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    release1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    release1Slider->addListener (this);

    release1Slider->setBounds (384, 120, 48, 48);

    pitchBend1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pitchBend1Slider.get());
    pitchBend1Slider->setRange (-100, 100, 1);
    pitchBend1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pitchBend1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pitchBend1Slider->addListener (this);

    pitchBend1Slider->setBounds (472, 120, 48, 48);

    vibratoAmount1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoAmount1Slider.get());
    vibratoAmount1Slider->setRange (0, 100, 1);
    vibratoAmount1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoAmount1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoAmount1Slider->addListener (this);

    vibratoAmount1Slider->setBounds (584, 120, 48, 48);

    vibratoSpeed1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoSpeed1Slider.get());
    vibratoSpeed1Slider->setRange (0, 100, 1);
    vibratoSpeed1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoSpeed1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoSpeed1Slider->addListener (this);

    vibratoSpeed1Slider->setBounds (664, 120, 48, 48);

    pulseWidth1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidth1Slider.get());
    pulseWidth1Slider->setRange (-100, 100, 1);
    pulseWidth1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidth1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidth1Slider->addListener (this);

    pulseWidth1Slider->setBounds (831, 120, 48, 48);

    vibratoDelay1Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDelay1Slider.get());
    vibratoDelay1Slider->setRange (0, 15, 1);
    vibratoDelay1Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDelay1Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDelay1Slider->addListener (this);

    vibratoDelay1Slider->setBounds (745, 120, 48, 48);

    patch2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (patch2Slider.get());
    patch2Slider->setRange (1, 2, 1);
    patch2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    patch2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    patch2Slider->addListener (this);

    patch2Slider->setBounds (32, 208, 48, 48);

    attack2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (attack2Slider.get());
    attack2Slider->setRange (0, 15, 1);
    attack2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    attack2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    attack2Slider->addListener (this);

    attack2Slider->setBounds (144, 208, 48, 48);

    decay2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (decay2Slider.get());
    decay2Slider->setRange (0, 15, 1);
    decay2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    decay2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    decay2Slider->addListener (this);

    decay2Slider->setBounds (224, 208, 48, 48);

    sustain2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (sustain2Slider.get());
    sustain2Slider->setRange (0, 15, 1);
    sustain2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    sustain2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    sustain2Slider->addListener (this);

    sustain2Slider->setBounds (304, 208, 48, 48);

    release2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (release2Slider.get());
    release2Slider->setRange (0, 15, 1);
    release2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    release2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    release2Slider->addListener (this);

    release2Slider->setBounds (384, 208, 48, 48);

    pitchBend2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pitchBend2Slider.get());
    pitchBend2Slider->setRange (-100, 100, 1);
    pitchBend2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pitchBend2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pitchBend2Slider->addListener (this);

    pitchBend2Slider->setBounds (472, 208, 48, 48);

    vibratoAmount2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoAmount2Slider.get());
    vibratoAmount2Slider->setRange (0, 100, 1);
    vibratoAmount2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoAmount2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoAmount2Slider->addListener (this);

    vibratoAmount2Slider->setBounds (584, 208, 48, 48);

    vibratoSpeed2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoSpeed2Slider.get());
    vibratoSpeed2Slider->setRange (0, 100, 1);
    vibratoSpeed2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoSpeed2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoSpeed2Slider->addListener (this);

    vibratoSpeed2Slider->setBounds (664, 208, 48, 48);

    pulseWidth2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidth2Slider.get());
    pulseWidth2Slider->setRange (-100, 100, 1);
    pulseWidth2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidth2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidth2Slider->addListener (this);

    pulseWidth2Slider->setBounds (831, 208, 48, 48);

    vibratoDelay2Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDelay2Slider.get());
    vibratoDelay2Slider->setRange (0, 15, 1);
    vibratoDelay2Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDelay2Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDelay2Slider->addListener (this);

    vibratoDelay2Slider->setBounds (745, 208, 48, 48);

    patch3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (patch3Slider.get());
    patch3Slider->setRange (1, 2, 1);
    patch3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    patch3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    patch3Slider->addListener (this);

    patch3Slider->setBounds (32, 296, 48, 48);

    attack3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (attack3Slider.get());
    attack3Slider->setRange (0, 15, 1);
    attack3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    attack3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    attack3Slider->addListener (this);

    attack3Slider->setBounds (144, 296, 48, 48);

    decay3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (decay3Slider.get());
    decay3Slider->setRange (0, 15, 1);
    decay3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    decay3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    decay3Slider->addListener (this);

    decay3Slider->setBounds (224, 296, 48, 48);

    sustain3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (sustain3Slider.get());
    sustain3Slider->setRange (0, 15, 1);
    sustain3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    sustain3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    sustain3Slider->addListener (this);

    sustain3Slider->setBounds (304, 296, 48, 48);

    release3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (release3Slider.get());
    release3Slider->setRange (0, 15, 1);
    release3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    release3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    release3Slider->addListener (this);

    release3Slider->setBounds (384, 296, 48, 48);

    pitchBend3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pitchBend3Slider.get());
    pitchBend3Slider->setRange (-100, 100, 1);
    pitchBend3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pitchBend3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pitchBend3Slider->addListener (this);

    pitchBend3Slider->setBounds (472, 296, 48, 48);

    vibratoAmount3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoAmount3Slider.get());
    vibratoAmount3Slider->setRange (0, 100, 1);
    vibratoAmount3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoAmount3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoAmount3Slider->addListener (this);

    vibratoAmount3Slider->setBounds (584, 296, 48, 48);

    vibratoSpeed3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoSpeed3Slider.get());
    vibratoSpeed3Slider->setRange (0, 100, 1);
    vibratoSpeed3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoSpeed3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoSpeed3Slider->addListener (this);

    vibratoSpeed3Slider->setBounds (664, 296, 48, 48);

    pulseWidth3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (pulseWidth3Slider.get());
    pulseWidth3Slider->setRange (-100, 100, 1);
    pulseWidth3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    pulseWidth3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    pulseWidth3Slider->addListener (this);

    pulseWidth3Slider->setBounds (831, 296, 48, 48);

    vibratoDelay3Slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (vibratoDelay3Slider.get());
    vibratoDelay3Slider->setRange (0, 15, 1);
    vibratoDelay3Slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    vibratoDelay3Slider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    vibratoDelay3Slider->addListener (this);

    vibratoDelay3Slider->setBounds (743, 296, 48, 48);

    cutoffSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (cutoffSlider.get());
    cutoffSlider->setRange (0, 2047, 1);
    cutoffSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    cutoffSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    cutoffSlider->addListener (this);

    cutoffSlider->setBounds (32, 384, 48, 48);

    resonanceSlider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (resonanceSlider.get());
    resonanceSlider->setRange (0, 15, 1);
    resonanceSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    resonanceSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    resonanceSlider->addListener (this);

    resonanceSlider->setBounds (32, 472, 48, 48);

    patch1Label.reset (new juce::Label ("new label",
                                        TRANS("1")));
    addAndMakeVisible (patch1Label.get());
    patch1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    patch1Label->setJustificationType (juce::Justification::centred);
    patch1Label->setEditable (false, false, false);
    patch1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    patch1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    patch1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    patch1Label->setBounds (32, 96, 48, 18);

    attack1Label.reset (new juce::Label ("new label",
                                         TRANS("0")));
    addAndMakeVisible (attack1Label.get());
    attack1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack1Label->setJustificationType (juce::Justification::centred);
    attack1Label->setEditable (false, false, false);
    attack1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    attack1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack1Label->setBounds (144, 96, 48, 18);

    decay1Label.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (decay1Label.get());
    decay1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay1Label->setJustificationType (juce::Justification::centred);
    decay1Label->setEditable (false, false, false);
    decay1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    decay1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay1Label->setBounds (224, 96, 48, 18);

    sustain1Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (sustain1Label.get());
    sustain1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain1Label->setJustificationType (juce::Justification::centred);
    sustain1Label->setEditable (false, false, false);
    sustain1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    sustain1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain1Label->setBounds (304, 96, 48, 18);

    release1Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (release1Label.get());
    release1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release1Label->setJustificationType (juce::Justification::centred);
    release1Label->setEditable (false, false, false);
    release1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    release1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release1Label->setBounds (384, 96, 48, 18);

    pitchBend1Label.reset (new juce::Label ("new label",
                                            TRANS("0%")));
    addAndMakeVisible (pitchBend1Label.get());
    pitchBend1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pitchBend1Label->setJustificationType (juce::Justification::centred);
    pitchBend1Label->setEditable (false, false, false);
    pitchBend1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pitchBend1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pitchBend1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pitchBend1Label->setBounds (472, 96, 48, 18);

    vibratoAmount1Label.reset (new juce::Label ("new label",
                                                TRANS("0%")));
    addAndMakeVisible (vibratoAmount1Label.get());
    vibratoAmount1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoAmount1Label->setJustificationType (juce::Justification::centred);
    vibratoAmount1Label->setEditable (false, false, false);
    vibratoAmount1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoAmount1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoAmount1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoAmount1Label->setBounds (584, 96, 48, 18);

    vibratoSpeed1Label.reset (new juce::Label ("new label",
                                               TRANS("0%")));
    addAndMakeVisible (vibratoSpeed1Label.get());
    vibratoSpeed1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoSpeed1Label->setJustificationType (juce::Justification::centred);
    vibratoSpeed1Label->setEditable (false, false, false);
    vibratoSpeed1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoSpeed1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoSpeed1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoSpeed1Label->setBounds (664, 96, 48, 18);

    pulseWidth1Label.reset (new juce::Label ("new label",
                                             TRANS("0%")));
    addAndMakeVisible (pulseWidth1Label.get());
    pulseWidth1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidth1Label->setJustificationType (juce::Justification::centred);
    pulseWidth1Label->setEditable (false, false, false);
    pulseWidth1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidth1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidth1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pulseWidth1Label->setBounds (831, 96, 48, 18);

    vibratoDelay1Label.reset (new juce::Label ("new label",
                                               TRANS("0")));
    addAndMakeVisible (vibratoDelay1Label.get());
    vibratoDelay1Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDelay1Label->setJustificationType (juce::Justification::centred);
    vibratoDelay1Label->setEditable (false, false, false);
    vibratoDelay1Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDelay1Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDelay1Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoDelay1Label->setBounds (745, 96, 48, 18);

    patch2Label.reset (new juce::Label ("new label",
                                        TRANS("1")));
    addAndMakeVisible (patch2Label.get());
    patch2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    patch2Label->setJustificationType (juce::Justification::centred);
    patch2Label->setEditable (false, false, false);
    patch2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    patch2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    patch2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    patch2Label->setBounds (32, 184, 48, 18);

    attack2Label.reset (new juce::Label ("new label",
                                         TRANS("0")));
    addAndMakeVisible (attack2Label.get());
    attack2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack2Label->setJustificationType (juce::Justification::centred);
    attack2Label->setEditable (false, false, false);
    attack2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    attack2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack2Label->setBounds (144, 184, 48, 18);

    decay2Label.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (decay2Label.get());
    decay2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay2Label->setJustificationType (juce::Justification::centred);
    decay2Label->setEditable (false, false, false);
    decay2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    decay2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay2Label->setBounds (224, 184, 48, 18);

    sustain2Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (sustain2Label.get());
    sustain2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain2Label->setJustificationType (juce::Justification::centred);
    sustain2Label->setEditable (false, false, false);
    sustain2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    sustain2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain2Label->setBounds (304, 184, 48, 18);

    release2Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (release2Label.get());
    release2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release2Label->setJustificationType (juce::Justification::centred);
    release2Label->setEditable (false, false, false);
    release2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    release2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release2Label->setBounds (384, 184, 48, 18);

    pitchBend2Label.reset (new juce::Label ("new label",
                                            TRANS("0%")));
    addAndMakeVisible (pitchBend2Label.get());
    pitchBend2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pitchBend2Label->setJustificationType (juce::Justification::centred);
    pitchBend2Label->setEditable (false, false, false);
    pitchBend2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pitchBend2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pitchBend2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pitchBend2Label->setBounds (472, 184, 48, 18);

    vibratoAmount2Label.reset (new juce::Label ("new label",
                                                TRANS("0%")));
    addAndMakeVisible (vibratoAmount2Label.get());
    vibratoAmount2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoAmount2Label->setJustificationType (juce::Justification::centred);
    vibratoAmount2Label->setEditable (false, false, false);
    vibratoAmount2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoAmount2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoAmount2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoAmount2Label->setBounds (584, 184, 48, 18);

    vibratoSpeed2Label.reset (new juce::Label ("new label",
                                               TRANS("0%")));
    addAndMakeVisible (vibratoSpeed2Label.get());
    vibratoSpeed2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoSpeed2Label->setJustificationType (juce::Justification::centred);
    vibratoSpeed2Label->setEditable (false, false, false);
    vibratoSpeed2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoSpeed2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoSpeed2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoSpeed2Label->setBounds (664, 184, 48, 18);

    pulseWidth2Label.reset (new juce::Label ("new label",
                                             TRANS("0%")));
    addAndMakeVisible (pulseWidth2Label.get());
    pulseWidth2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidth2Label->setJustificationType (juce::Justification::centred);
    pulseWidth2Label->setEditable (false, false, false);
    pulseWidth2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidth2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidth2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pulseWidth2Label->setBounds (831, 184, 48, 18);

    vibratoDelay2Label.reset (new juce::Label ("new label",
                                               TRANS("0")));
    addAndMakeVisible (vibratoDelay2Label.get());
    vibratoDelay2Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDelay2Label->setJustificationType (juce::Justification::centred);
    vibratoDelay2Label->setEditable (false, false, false);
    vibratoDelay2Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDelay2Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDelay2Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoDelay2Label->setBounds (745, 184, 48, 18);

    patch3Label.reset (new juce::Label ("new label",
                                        TRANS("1")));
    addAndMakeVisible (patch3Label.get());
    patch3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    patch3Label->setJustificationType (juce::Justification::centred);
    patch3Label->setEditable (false, false, false);
    patch3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    patch3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    patch3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    patch3Label->setBounds (32, 272, 48, 18);

    attack3Label.reset (new juce::Label ("new label",
                                         TRANS("0")));
    addAndMakeVisible (attack3Label.get());
    attack3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack3Label->setJustificationType (juce::Justification::centred);
    attack3Label->setEditable (false, false, false);
    attack3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    attack3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack3Label->setBounds (144, 272, 48, 18);

    decay3Label.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (decay3Label.get());
    decay3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay3Label->setJustificationType (juce::Justification::centred);
    decay3Label->setEditable (false, false, false);
    decay3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    decay3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay3Label->setBounds (224, 272, 48, 18);

    sustain3Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (sustain3Label.get());
    sustain3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain3Label->setJustificationType (juce::Justification::centred);
    sustain3Label->setEditable (false, false, false);
    sustain3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    sustain3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain3Label->setBounds (304, 272, 48, 18);

    release3Label.reset (new juce::Label ("new label",
                                          TRANS("0")));
    addAndMakeVisible (release3Label.get());
    release3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release3Label->setJustificationType (juce::Justification::centred);
    release3Label->setEditable (false, false, false);
    release3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    release3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release3Label->setBounds (384, 272, 48, 18);

    pitchBend3Label.reset (new juce::Label ("new label",
                                            TRANS("0%")));
    addAndMakeVisible (pitchBend3Label.get());
    pitchBend3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pitchBend3Label->setJustificationType (juce::Justification::centred);
    pitchBend3Label->setEditable (false, false, false);
    pitchBend3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pitchBend3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pitchBend3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pitchBend3Label->setBounds (472, 272, 48, 18);

    vibratoAmount3Label.reset (new juce::Label ("new label",
                                                TRANS("0%")));
    addAndMakeVisible (vibratoAmount3Label.get());
    vibratoAmount3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoAmount3Label->setJustificationType (juce::Justification::centred);
    vibratoAmount3Label->setEditable (false, false, false);
    vibratoAmount3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoAmount3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoAmount3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoAmount3Label->setBounds (584, 272, 48, 18);

    vibratoSpeed3Label.reset (new juce::Label ("new label",
                                               TRANS("0%")));
    addAndMakeVisible (vibratoSpeed3Label.get());
    vibratoSpeed3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoSpeed3Label->setJustificationType (juce::Justification::centred);
    vibratoSpeed3Label->setEditable (false, false, false);
    vibratoSpeed3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoSpeed3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoSpeed3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoSpeed3Label->setBounds (664, 272, 48, 18);

    pulseWidth3Label.reset (new juce::Label ("new label",
                                             TRANS("0%")));
    addAndMakeVisible (pulseWidth3Label.get());
    pulseWidth3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    pulseWidth3Label->setJustificationType (juce::Justification::centred);
    pulseWidth3Label->setEditable (false, false, false);
    pulseWidth3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    pulseWidth3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    pulseWidth3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    pulseWidth3Label->setBounds (831, 272, 48, 18);

    vibratoDelay3Label.reset (new juce::Label ("new label",
                                               TRANS("0")));
    addAndMakeVisible (vibratoDelay3Label.get());
    vibratoDelay3Label->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    vibratoDelay3Label->setJustificationType (juce::Justification::centred);
    vibratoDelay3Label->setEditable (false, false, false);
    vibratoDelay3Label->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    vibratoDelay3Label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    vibratoDelay3Label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    vibratoDelay3Label->setBounds (745, 272, 48, 18);

    cutoffLabel.reset (new juce::Label ("new label",
                                        TRANS("0")));
    addAndMakeVisible (cutoffLabel.get());
    cutoffLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    cutoffLabel->setJustificationType (juce::Justification::centred);
    cutoffLabel->setEditable (false, false, false);
    cutoffLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    cutoffLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    cutoffLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    cutoffLabel->setBounds (32, 360, 48, 18);

    resonanceLabel.reset (new juce::Label ("new label",
                                           TRANS("0")));
    addAndMakeVisible (resonanceLabel.get());
    resonanceLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    resonanceLabel->setJustificationType (juce::Justification::centred);
    resonanceLabel->setEditable (false, false, false);
    resonanceLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    resonanceLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    resonanceLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    resonanceLabel->setBounds (32, 448, 48, 18);

    titleLabel.reset (new juce::Label ("new label",
                                       juce::String()));
    addAndMakeVisible (titleLabel.get());
    titleLabel->setFont (juce::Font ("C64 Pro", 14.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    titleLabel->setJustificationType (juce::Justification::centredLeft);
    titleLabel->setEditable (true, true, false);
    titleLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    titleLabel->setColour (juce::TextEditor::textColourId, juce::Colour (0xff5090d0));
    titleLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    titleLabel->addListener (this);

    titleLabel->setBounds (632, 8, 368, 32);

    artistLabel.reset (new juce::Label ("new label",
                                        juce::String()));
    addAndMakeVisible (artistLabel.get());
    artistLabel->setFont (juce::Font ("C64 Pro", 14.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    artistLabel->setJustificationType (juce::Justification::centredLeft);
    artistLabel->setEditable (true, true, false);
    artistLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    artistLabel->setColour (juce::TextEditor::textColourId, juce::Colour (0xff5090d0));
    artistLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    artistLabel->addListener (this);

    artistLabel->setBounds (632, 48, 368, 32);

    exportButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (exportButton.get());
    exportButton->addListener (this);

    exportButton->setImages (false, true, true,
                             juce::ImageCache::getFromMemory (recordnormal_png, recordnormal_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (recordover_png, recordover_pngSize), 1.000f, juce::Colour (0x00000000),
                             juce::ImageCache::getFromMemory (recorddown_png, recorddown_pngSize), 1.000f, juce::Colour (0x00000000));
    exportButton->setBounds (480, 40, 32, 32);

    patchesViewport.reset (new juce::Viewport ("new viewport"));
    addAndMakeVisible (patchesViewport.get());
    patchesViewport->setScrollBarsShown (true, false);
    patchesViewport->setScrollBarThickness (16);

    patchesViewport->setBounds (496, 368, 512, 192);

    filter1Checkbox.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (filter1Checkbox.get());
    filter1Checkbox->setButtonText (juce::String());
    filter1Checkbox->addListener (this);

    filter1Checkbox->setBounds (120, 376, 48, 48);

    filter2Checkbox.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (filter2Checkbox.get());
    filter2Checkbox->setButtonText (juce::String());
    filter2Checkbox->addListener (this);

    filter2Checkbox->setBounds (240, 376, 48, 48);

    filter3Checkbox.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (filter3Checkbox.get());
    filter3Checkbox->setButtonText (juce::String());
    filter3Checkbox->addListener (this);

    filter3Checkbox->setBounds (352, 376, 48, 48);

    filterLowPassCheckbox.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (filterLowPassCheckbox.get());
    filterLowPassCheckbox->setButtonText (juce::String());
    filterLowPassCheckbox->addListener (this);

    filterLowPassCheckbox->setBounds (120, 456, 48, 48);

    filterBandPassCheckbox.reset (new juce::ToggleButton ("new toggle button"));
    addAndMakeVisible (filterBandPassCheckbox.get());
    filterBandPassCheckbox->setButtonText (juce::String());
    filterBandPassCheckbox->addListener (this);

    filterBandPassCheckbox->setBounds (240, 456, 48, 48);

    filterHighPassCheckbox.reset (new juce::ToggleButton ("high"));
    addAndMakeVisible (filterHighPassCheckbox.get());
    filterHighPassCheckbox->setButtonText (juce::String());
    filterHighPassCheckbox->addListener (this);

    filterHighPassCheckbox->setBounds (352, 456, 48, 48);

    patchEditorButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (patchEditorButton.get());
    patchEditorButton->addListener (this);

    patchEditorButton->setImages (false, true, true,
                                  juce::ImageCache::getFromMemory (patchEditorButtonNormal_png, patchEditorButtonNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                                  juce::ImageCache::getFromMemory (patchEditorButtonOver_png, patchEditorButtonOver_pngSize), 1.000f, juce::Colour (0x00000000),
                                  juce::ImageCache::getFromMemory (patchEditorButtonDown_png, patchEditorButtonDown_pngSize), 1.000f, juce::Colour (0x00000000));
    patchEditorButton->setBounds (208, 544, 154, 26);

    addPatchButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (addPatchButton.get());
    addPatchButton->addListener (this);

    addPatchButton->setImages (false, true, true,
                               juce::ImageCache::getFromMemory (addButtonNormal_png, addButtonNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                               juce::ImageCache::getFromMemory (addButtonOver_png, addButtonOver_pngSize), 1.000f, juce::Colour (0x00000000),
                               juce::ImageCache::getFromMemory (addButtonDown_png, addButtonDown_pngSize), 1.000f, juce::Colour (0x00000000));
    addPatchButton->setBounds (488, 544, 154, 26);

    replacePatchButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (replacePatchButton.get());
    replacePatchButton->addListener (this);

    replacePatchButton->setImages (false, true, true,
                                   juce::ImageCache::getFromMemory (replaceButtonNormal_png, replaceButtonNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                                   juce::ImageCache::getFromMemory (replaceButtonOver_png, replaceButtonOver_pngSize), 1.000f, juce::Colour (0x00000000),
                                   juce::ImageCache::getFromMemory (replaceButtonDown_png, replaceButtonDown_pngSize), 1.000f, juce::Colour (0x00000000));
    replacePatchButton->setBounds (656, 544, 154, 26);

    removePatchButton.reset (new juce::ImageButton ("new button"));
    addAndMakeVisible (removePatchButton.get());
    removePatchButton->addListener (this);

    removePatchButton->setImages (false, true, true,
                                  juce::ImageCache::getFromMemory (removeButtonNormal_png, removeButtonNormal_pngSize), 1.000f, juce::Colour (0x00000000),
                                  juce::ImageCache::getFromMemory (removeButtonOver_png, removeButtonOver_pngSize), 1.000f, juce::Colour (0x00000000),
                                  juce::ImageCache::getFromMemory (removeButtonDown_png, removeButtonDown_pngSize), 1.000f, juce::Colour (0x00000000));
    removePatchButton->setBounds (824, 544, 154, 26);

    patchSelector.reset (new PatchSelector());
    addAndMakeVisible (patchSelector.get());
    patchSelector->setBounds (488, 368, 322, 176);

    cachedImage_liveModeBackdrop_png_1 = juce::ImageCache::getFromMemory (liveModeBackdrop_png, liveModeBackdrop_pngSize);
    cachedImage_recordIndicator_png_2 = juce::ImageCache::getFromMemory (recordIndicator_png, recordIndicator_pngSize);
    cachedImage_liveModeButtonDown_png_3 = juce::ImageCache::getFromMemory (liveModeButtonDown_png, liveModeButtonDown_pngSize);
    cachedImage_recordIndicatorblink_png_4 = juce::ImageCache::getFromMemory (recordIndicatorblink_png, recordIndicatorblink_pngSize);

    //[UserPreSize]
    volumeSlider -> setValue (
                              15
                            , dontSendNotification );
    volumeLabel -> setText (
                            "15"
                          , dontSendNotification );

    //cutoffSlider -> setSkewFactorFromMidPoint (
    //                                           32
    //                                          );

    patches = new Patches ();
    patchesViewport -> setViewedComponent (
                                           patches );
    patchesViewport -> getVerticalScrollBar () -> setAutoHide (
                                                               false );
    patchSelector -> setVisible (
                                 false );
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < AttackParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < DecayParameterChanged > > () -> add (
                                                                                this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> add (
                                                                                      this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < PitchBendParameterChanged > > () -> add (
                                                                                    this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < PulseWidthParameterChanged > > () -> add (
                                                                                     this );
    SharedResourcePointer < ListenerList < ReleaseParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> add (
                                                                                    this );
    SharedResourcePointer < ListenerList < SustainParameterChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> add (
                                                                                        this );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> add (
                                                                                       this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > > () -> add (
                                                                                     this );
    SharedResourcePointer < ListenerList < LivePatchListChanged > > () -> add (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> add (
                                                                           this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> add (
                                                                          this );
    //[/UserPreSize]

    setSize (1024, 576);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

LiveMode::~LiveMode()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < AttackParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < BandPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < CutoffParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < DecayParameterChanged > > () -> remove (
                                                                                   this );
    SharedResourcePointer < ListenerList < FilterVoiceParameterChanged > > () -> remove (
                                                                                         this );
    SharedResourcePointer < ListenerList < HighPassParameterChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < LowPassParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < PitchBendParameterChanged > > () -> remove (
                                                                                       this );
    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < PulseWidthParameterChanged > > () -> remove (
                                                                                        this );
    SharedResourcePointer < ListenerList < ReleaseParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < ResonanceParameterChanged > > () -> remove (
                                                                                       this );
    SharedResourcePointer < ListenerList < SustainParameterChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < VibratoAmountParameterChanged > > () -> remove (
                                                                                           this );
    SharedResourcePointer < ListenerList < VibratoSpeedParameterChanged > > () -> remove (
                                                                                          this );
    SharedResourcePointer < ListenerList < VolumeParameterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < PatchEditorLiveModeClicked > > () -> remove (
                                                                                        this );
    SharedResourcePointer < ListenerList < LivePatchListChanged > > () -> remove (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> remove (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < QuarterNoteTick > > () -> remove (
                                                                             this );
    patches = nullptr;
    //[/Destructor_pre]

    volumeSlider = nullptr;
    volumeLabel = nullptr;
    patch1Slider = nullptr;
    attack1Slider = nullptr;
    decay1Slider = nullptr;
    sustain1Slider = nullptr;
    release1Slider = nullptr;
    pitchBend1Slider = nullptr;
    vibratoAmount1Slider = nullptr;
    vibratoSpeed1Slider = nullptr;
    pulseWidth1Slider = nullptr;
    vibratoDelay1Slider = nullptr;
    patch2Slider = nullptr;
    attack2Slider = nullptr;
    decay2Slider = nullptr;
    sustain2Slider = nullptr;
    release2Slider = nullptr;
    pitchBend2Slider = nullptr;
    vibratoAmount2Slider = nullptr;
    vibratoSpeed2Slider = nullptr;
    pulseWidth2Slider = nullptr;
    vibratoDelay2Slider = nullptr;
    patch3Slider = nullptr;
    attack3Slider = nullptr;
    decay3Slider = nullptr;
    sustain3Slider = nullptr;
    release3Slider = nullptr;
    pitchBend3Slider = nullptr;
    vibratoAmount3Slider = nullptr;
    vibratoSpeed3Slider = nullptr;
    pulseWidth3Slider = nullptr;
    vibratoDelay3Slider = nullptr;
    cutoffSlider = nullptr;
    resonanceSlider = nullptr;
    patch1Label = nullptr;
    attack1Label = nullptr;
    decay1Label = nullptr;
    sustain1Label = nullptr;
    release1Label = nullptr;
    pitchBend1Label = nullptr;
    vibratoAmount1Label = nullptr;
    vibratoSpeed1Label = nullptr;
    pulseWidth1Label = nullptr;
    vibratoDelay1Label = nullptr;
    patch2Label = nullptr;
    attack2Label = nullptr;
    decay2Label = nullptr;
    sustain2Label = nullptr;
    release2Label = nullptr;
    pitchBend2Label = nullptr;
    vibratoAmount2Label = nullptr;
    vibratoSpeed2Label = nullptr;
    pulseWidth2Label = nullptr;
    vibratoDelay2Label = nullptr;
    patch3Label = nullptr;
    attack3Label = nullptr;
    decay3Label = nullptr;
    sustain3Label = nullptr;
    release3Label = nullptr;
    pitchBend3Label = nullptr;
    vibratoAmount3Label = nullptr;
    vibratoSpeed3Label = nullptr;
    pulseWidth3Label = nullptr;
    vibratoDelay3Label = nullptr;
    cutoffLabel = nullptr;
    resonanceLabel = nullptr;
    titleLabel = nullptr;
    artistLabel = nullptr;
    exportButton = nullptr;
    patchesViewport = nullptr;
    filter1Checkbox = nullptr;
    filter2Checkbox = nullptr;
    filter3Checkbox = nullptr;
    filterLowPassCheckbox = nullptr;
    filterBandPassCheckbox = nullptr;
    filterHighPassCheckbox = nullptr;
    patchEditorButton = nullptr;
    addPatchButton = nullptr;
    replacePatchButton = nullptr;
    removePatchButton = nullptr;
    patchSelector = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    look = nullptr;
    //[/Destructor]
}

//==============================================================================
void LiveMode::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colours::white);

    {
        int x = 0, y = 0, width = 1024, height = 576;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_liveModeBackdrop_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_liveModeBackdrop_png_1.getWidth(), cachedImage_liveModeBackdrop_png_1.getHeight());
    }

    {
        int x = 472, y = 6, width = 50, height = 22;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_recordIndicator_png_2,
                     x, y, width, height,
                     0, 0, cachedImage_recordIndicator_png_2.getWidth(), cachedImage_recordIndicator_png_2.getHeight());
    }

    {
        int x = 32, y = 544, width = 154, height = 26;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_liveModeButtonDown_png_3,
                     x, y, width, height,
                     0, 0, cachedImage_liveModeButtonDown_png_3.getWidth(), cachedImage_liveModeButtonDown_png_3.getHeight());
    }

    {
        int x = 472, y = 6, width = 50, height = 22;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black.withAlpha (0.001f));
        g.drawImage (cachedImage_recordIndicatorblink_png_4,
                     x, y, width, height,
                     0, 0, cachedImage_recordIndicatorblink_png_4.getWidth(), cachedImage_recordIndicatorblink_png_4.getHeight());
    }

    //[UserPaint] Add your own custom painting code here..
    if ( armed && quarterNoteTicked )
    {
        g . setColour (
                       Colours::black );
        g . drawImage (
                       cachedImage_recordIndicatorblink_png_4
                     , 472
                     , 6
                     , 50
                     , 22
                     , 0
                     , 0
                     , cachedImage_recordIndicatorblink_png_4 . getWidth ()
                     , cachedImage_recordIndicatorblink_png_4 . getHeight () );
    }
    //[/UserPaint]
}

void LiveMode::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void LiveMode::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volumeSlider.get())
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        volumeLabel -> setText (
                                volumeSlider -> getTextFromValue (
                                                                  volumeSlider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> call (
                                                                                 &LiveVolumeChanged::onLiveVolumeChanged
                                                                               , static_cast < unsigned int > ( volumeSlider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportVolumeChanged > > () -> call (
                                                                                   &ExportVolumeChanged::onExportVolumeChanged
                                                                                 , static_cast < unsigned int > ( volumeSlider -> getValue () ) );
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == patch1Slider.get())
    {
        //[UserSliderCode_patch1Slider] -- add your slider handling code here..
        patch1Label -> setText (
                                patch1Slider -> getTextFromValue (
                                                                  patch1Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePatchChanged > > () -> call (
                                                                                &LivePatchChanged::onLivePatchChanged
                                                                              , SID_VOICE_1
                                                                              , static_cast < unsigned int > ( patch1Slider -> getValue () ) - 1 );
        SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                  &ExportPatchChanged::onExportPatchChanged
                                                                                , SID_VOICE_1
                                                                                , static_cast < unsigned int > ( patch1Slider -> getValue () ) - 1 );
        //[/UserSliderCode_patch1Slider]
    }
    else if (sliderThatWasMoved == attack1Slider.get())
    {
        //[UserSliderCode_attack1Slider] -- add your slider handling code here..
        attack1Label -> setText (
                                 attack1Slider -> getTextFromValue (
                                                                    attack1Slider -> getValue () )
                               , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveAttackChanged > > () -> call (
                                                                                 &LiveAttackChanged::onLiveAttackChanged
                                                                               , SID_VOICE_1
                                                                               , static_cast < unsigned int > ( attack1Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                   &ExportAttackChanged::onExportAttackChanged
                                                                                 , SID_VOICE_1
                                                                                 , static_cast < unsigned int > ( attack1Slider -> getValue () ) );
        //[/UserSliderCode_attack1Slider]
    }
    else if (sliderThatWasMoved == decay1Slider.get())
    {
        //[UserSliderCode_decay1Slider] -- add your slider handling code here..
        decay1Label -> setText (
                                decay1Slider -> getTextFromValue (
                                                                  decay1Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveDecayChanged > > () -> call (
                                                                                &LiveDecayChanged::onLiveDecayChanged
                                                                              , SID_VOICE_1
                                                                              , static_cast < unsigned int > ( decay1Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                  &ExportDecayChanged::onExportDecayChanged
                                                                                , SID_VOICE_1
                                                                                , static_cast < unsigned int > ( decay1Slider -> getValue () ) );
        //[/UserSliderCode_decay1Slider]
    }
    else if (sliderThatWasMoved == sustain1Slider.get())
    {
        //[UserSliderCode_sustain1Slider] -- add your slider handling code here..
        sustain1Label -> setText (
                                  sustain1Slider -> getTextFromValue (
                                                                      sustain1Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveSustainChanged > > () -> call (
                                                                                  &LiveSustainChanged::onLiveSustainChanged
                                                                                , SID_VOICE_1
                                                                                , static_cast < unsigned int > ( sustain1Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                    &ExportSustainChanged::onExportSustainChanged
                                                                                  , SID_VOICE_1
                                                                                  , static_cast < unsigned int > ( sustain1Slider -> getValue () ) );
        //[/UserSliderCode_sustain1Slider]
    }
    else if (sliderThatWasMoved == release1Slider.get())
    {
        //[UserSliderCode_release1Slider] -- add your slider handling code here..
        release1Label -> setText (
                                  release1Slider -> getTextFromValue (
                                                                      release1Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveReleaseChanged > > () -> call (
                                                                                  &LiveReleaseChanged::onLiveReleaseChanged
                                                                                , SID_VOICE_1
                                                                                , static_cast < unsigned int > ( release1Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                    &ExportReleaseChanged::onExportReleaseChanged
                                                                                  , SID_VOICE_1
                                                                                  , static_cast < unsigned int > ( release1Slider -> getValue () ) );
        //[/UserSliderCode_release1Slider]
    }
    else if (sliderThatWasMoved == pitchBend1Slider.get())
    {
        //[UserSliderCode_pitchBend1Slider] -- add your slider handling code here..
        pitchBend1Label -> setText (
                                    pitchBend1Slider -> getTextFromValue (
                                                                          pitchBend1Slider -> getValue () ) + "%"
                                  , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePitchBendChanged > > () -> call (
                                                                                    &LivePitchBendChanged::onLivePitchBendChanged
                                                                                  , SID_VOICE_1
                                                                                  , static_cast < float > ( pitchBend1Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                      &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                    , SID_VOICE_1
                                                                                    , static_cast < float > ( pitchBend1Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pitchBend1Slider]
    }
    else if (sliderThatWasMoved == vibratoAmount1Slider.get())
    {
        //[UserSliderCode_vibratoAmount1Slider] -- add your slider handling code here..
        vibratoAmount1Label -> setText (
                                        vibratoAmount1Slider -> getTextFromValue (
                                                                                  vibratoAmount1Slider -> getValue () ) + "%"
                                      , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> call (
                                                                                        &LiveVibratoAmountChanged::onLiveVibratoAmountChanged
                                                                                      , SID_VOICE_1
                                                                                      , static_cast < float > ( vibratoAmount1Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                          &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                        , SID_VOICE_1
                                                                                        , static_cast < float > ( vibratoAmount1Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoAmount1Slider]
    }
    else if (sliderThatWasMoved == vibratoSpeed1Slider.get())
    {
        //[UserSliderCode_vibratoSpeed1Slider] -- add your slider handling code here..
        vibratoSpeed1Label -> setText (
                                       vibratoSpeed1Slider -> getTextFromValue (
                                                                                vibratoSpeed1Slider -> getValue () ) + "%"
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> call (
                                                                                       &LiveVibratoSpeedChanged::onLiveVibratoSpeedChanged
                                                                                     , SID_VOICE_1
                                                                                     , static_cast < float > ( vibratoSpeed1Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                         &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                       , SID_VOICE_1
                                                                                       , static_cast < float > ( vibratoSpeed1Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoSpeed1Slider]
    }
    else if (sliderThatWasMoved == pulseWidth1Slider.get())
    {
        //[UserSliderCode_pulseWidth1Slider] -- add your slider handling code here..
        pulseWidth1Label -> setText (
                                     pulseWidth1Slider -> getTextFromValue (
                                                                            pulseWidth1Slider -> getValue () ) + "%"
                                   , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePulseWidthChanged > > () -> call (
                                                                                     &LivePulseWidthChanged::onLivePulseWidthChanged
                                                                                   , SID_VOICE_1
                                                                                   , static_cast < float > ( pulseWidth1Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                       &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                     , SID_VOICE_1
                                                                                     , static_cast < float > ( pulseWidth1Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pulseWidth1Slider]
    }
    else if (sliderThatWasMoved == vibratoDelay1Slider.get())
    {
        //[UserSliderCode_vibratoDelay1Slider] -- add your slider handling code here..
        vibratoDelay1Label -> setText (
                                       vibratoDelay1Slider -> getTextFromValue (
                                                                                vibratoDelay1Slider -> getValue () )
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> call (
                                                                                       &LiveVibratoDelayChanged::onLiveVibratoDelayChanged
                                                                                     , SID_VOICE_1
                                                                                     , static_cast < unsigned int > ( vibratoAmount1Slider -> getValue () ) );
        //[/UserSliderCode_vibratoDelay1Slider]
    }
    else if (sliderThatWasMoved == patch2Slider.get())
    {
        //[UserSliderCode_patch2Slider] -- add your slider handling code here..
        patch2Label -> setText (
                                patch2Slider -> getTextFromValue (
                                                                  patch2Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePatchChanged > > () -> call (
                                                                                &LivePatchChanged::onLivePatchChanged
                                                                              , SID_VOICE_2
                                                                              , static_cast < unsigned int > ( patch2Slider -> getValue () ) - 1 );
        SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                  &ExportPatchChanged::onExportPatchChanged
                                                                                , SID_VOICE_2
                                                                                , static_cast < unsigned int > ( patch2Slider -> getValue () ) - 1 );
        //[/UserSliderCode_patch2Slider]
    }
    else if (sliderThatWasMoved == attack2Slider.get())
    {
        //[UserSliderCode_attack2Slider] -- add your slider handling code here..
        attack2Label -> setText (
                                 attack2Slider -> getTextFromValue (
                                                                    attack2Slider -> getValue () )
                               , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveAttackChanged > > () -> call (
                                                                                 &LiveAttackChanged::onLiveAttackChanged
                                                                               , SID_VOICE_2
                                                                               , static_cast < unsigned int > ( attack2Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                   &ExportAttackChanged::onExportAttackChanged
                                                                                 , SID_VOICE_2
                                                                                 , static_cast < unsigned int > ( attack2Slider -> getValue () ) );
        //[/UserSliderCode_attack2Slider]
    }
    else if (sliderThatWasMoved == decay2Slider.get())
    {
        //[UserSliderCode_decay2Slider] -- add your slider handling code here..
        decay2Label -> setText (
                                decay2Slider -> getTextFromValue (
                                                                  decay2Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveDecayChanged > > () -> call (
                                                                                &LiveDecayChanged::onLiveDecayChanged
                                                                              , SID_VOICE_2
                                                                              , static_cast < unsigned int > ( decay2Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                  &ExportDecayChanged::onExportDecayChanged
                                                                                , SID_VOICE_2
                                                                                , static_cast < unsigned int > ( decay2Slider -> getValue () ) );
        //[/UserSliderCode_decay2Slider]
    }
    else if (sliderThatWasMoved == sustain2Slider.get())
    {
        //[UserSliderCode_sustain2Slider] -- add your slider handling code here..
        sustain2Label -> setText (
                                  sustain2Slider -> getTextFromValue (
                                                                      sustain2Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveSustainChanged > > () -> call (
                                                                                  &LiveSustainChanged::onLiveSustainChanged
                                                                                , SID_VOICE_2
                                                                                , static_cast < unsigned int > ( sustain2Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                    &ExportSustainChanged::onExportSustainChanged
                                                                                  , SID_VOICE_2
                                                                                  , static_cast < unsigned int > ( sustain2Slider -> getValue () ) );
        //[/UserSliderCode_sustain2Slider]
    }
    else if (sliderThatWasMoved == release2Slider.get())
    {
        //[UserSliderCode_release2Slider] -- add your slider handling code here..
        release2Label -> setText (
                                  release2Slider -> getTextFromValue (
                                                                      release2Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveReleaseChanged > > () -> call (
                                                                                  &LiveReleaseChanged::onLiveReleaseChanged
                                                                                , SID_VOICE_2
                                                                                , static_cast < unsigned int > ( release2Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                    &ExportReleaseChanged::onExportReleaseChanged
                                                                                  , SID_VOICE_2
                                                                                  , static_cast < unsigned int > ( release2Slider -> getValue () ) );
        //[/UserSliderCode_release2Slider]
    }
    else if (sliderThatWasMoved == pitchBend2Slider.get())
    {
        //[UserSliderCode_pitchBend2Slider] -- add your slider handling code here..
        pitchBend2Label -> setText (
                                    pitchBend2Slider -> getTextFromValue (
                                                                          pitchBend2Slider -> getValue () ) + "%"
                                  , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePitchBendChanged > > () -> call (
                                                                                    &LivePitchBendChanged::onLivePitchBendChanged
                                                                                  , SID_VOICE_2
                                                                                  , static_cast < float > ( pitchBend2Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                      &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                    , SID_VOICE_2
                                                                                    , static_cast < float > ( pitchBend2Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pitchBend2Slider]
    }
    else if (sliderThatWasMoved == vibratoAmount2Slider.get())
    {
        //[UserSliderCode_vibratoAmount2Slider] -- add your slider handling code here..
        vibratoAmount2Label -> setText (
                                        vibratoAmount2Slider -> getTextFromValue (
                                                                                  vibratoAmount2Slider -> getValue () ) + "%"
                                      , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> call (
                                                                                        &LiveVibratoAmountChanged::onLiveVibratoAmountChanged
                                                                                      , SID_VOICE_2
                                                                                      , static_cast < float > ( vibratoAmount2Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                          &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                        , SID_VOICE_2
                                                                                        , static_cast < float > ( vibratoAmount2Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoAmount2Slider]
    }
    else if (sliderThatWasMoved == vibratoSpeed2Slider.get())
    {
        //[UserSliderCode_vibratoSpeed2Slider] -- add your slider handling code here..
        vibratoSpeed2Label -> setText (
                                       vibratoSpeed2Slider -> getTextFromValue (
                                                                                vibratoSpeed2Slider -> getValue () ) + "%"
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> call (
                                                                                       &LiveVibratoSpeedChanged::onLiveVibratoSpeedChanged
                                                                                     , SID_VOICE_2
                                                                                     , static_cast < float > ( vibratoSpeed2Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                         &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                       , SID_VOICE_2
                                                                                       , static_cast < float > ( vibratoSpeed2Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoSpeed2Slider]
    }
    else if (sliderThatWasMoved == pulseWidth2Slider.get())
    {
        //[UserSliderCode_pulseWidth2Slider] -- add your slider handling code here..
        pulseWidth2Label -> setText (
                                     pulseWidth2Slider -> getTextFromValue (
                                                                            pulseWidth2Slider -> getValue () ) + "%"
                                   , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePulseWidthChanged > > () -> call (
                                                                                     &LivePulseWidthChanged::onLivePulseWidthChanged
                                                                                   , SID_VOICE_2
                                                                                   , static_cast < float > ( pulseWidth2Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                       &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                     , SID_VOICE_2
                                                                                     , static_cast < float > ( pulseWidth2Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pulseWidth2Slider]
    }
    else if (sliderThatWasMoved == vibratoDelay2Slider.get())
    {
        //[UserSliderCode_vibratoDelay2Slider] -- add your slider handling code here..
        vibratoDelay2Label -> setText (
                                       vibratoDelay2Slider -> getTextFromValue (
                                                                                vibratoDelay2Slider -> getValue () )
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> call (
                                                                                       &LiveVibratoDelayChanged::onLiveVibratoDelayChanged
                                                                                     , SID_VOICE_2
                                                                                     , static_cast < unsigned int > ( vibratoAmount2Slider -> getValue () ) );
        //[/UserSliderCode_vibratoDelay2Slider]
    }
    else if (sliderThatWasMoved == patch3Slider.get())
    {
        //[UserSliderCode_patch3Slider] -- add your slider handling code here..
        patch3Label -> setText (
                                patch3Slider -> getTextFromValue (
                                                                  patch3Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePatchChanged > > () -> call (
                                                                                &LivePatchChanged::onLivePatchChanged
                                                                              , SID_VOICE_3
                                                                              , static_cast < unsigned int > ( patch3Slider -> getValue () ) - 1 );
        SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                  &ExportPatchChanged::onExportPatchChanged
                                                                                , SID_VOICE_3
                                                                                , static_cast < unsigned int > ( patch3Slider -> getValue () ) - 1 );
        //[/UserSliderCode_patch3Slider]
    }
    else if (sliderThatWasMoved == attack3Slider.get())
    {
        //[UserSliderCode_attack3Slider] -- add your slider handling code here..
        attack3Label -> setText (
                                 attack3Slider -> getTextFromValue (
                                                                    attack3Slider -> getValue () )
                               , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveAttackChanged > > () -> call (
                                                                                 &LiveAttackChanged::onLiveAttackChanged
                                                                               , SID_VOICE_3
                                                                               , static_cast < unsigned int > ( attack3Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                   &ExportAttackChanged::onExportAttackChanged
                                                                                 , SID_VOICE_3
                                                                                 , static_cast < unsigned int > ( attack3Slider -> getValue () ) );
        //[/UserSliderCode_attack3Slider]
    }
    else if (sliderThatWasMoved == decay3Slider.get())
    {
        //[UserSliderCode_decay3Slider] -- add your slider handling code here..
        decay3Label -> setText (
                                decay3Slider -> getTextFromValue (
                                                                  decay3Slider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveDecayChanged > > () -> call (
                                                                                &LiveDecayChanged::onLiveDecayChanged
                                                                              , SID_VOICE_3
                                                                              , static_cast < unsigned int > ( decay3Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                  &ExportDecayChanged::onExportDecayChanged
                                                                                , SID_VOICE_3
                                                                                , static_cast < unsigned int > ( decay3Slider -> getValue () ) );
        //[/UserSliderCode_decay3Slider]
    }
    else if (sliderThatWasMoved == sustain3Slider.get())
    {
        //[UserSliderCode_sustain3Slider] -- add your slider handling code here..
        sustain3Label -> setText (
                                  sustain3Slider -> getTextFromValue (
                                                                      sustain3Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveSustainChanged > > () -> call (
                                                                                  &LiveSustainChanged::onLiveSustainChanged
                                                                                , SID_VOICE_3
                                                                                , static_cast < unsigned int > ( sustain3Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                    &ExportSustainChanged::onExportSustainChanged
                                                                                  , SID_VOICE_3
                                                                                  , static_cast < unsigned int > ( sustain3Slider -> getValue () ) );
        //[/UserSliderCode_sustain3Slider]
    }
    else if (sliderThatWasMoved == release3Slider.get())
    {
        //[UserSliderCode_release3Slider] -- add your slider handling code here..
        release3Label -> setText (
                                  release3Slider -> getTextFromValue (
                                                                      release3Slider -> getValue () )
                                , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveReleaseChanged > > () -> call (
                                                                                  &LiveReleaseChanged::onLiveReleaseChanged
                                                                                , SID_VOICE_3
                                                                                , static_cast < unsigned int > ( release3Slider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                    &ExportReleaseChanged::onExportReleaseChanged
                                                                                  , SID_VOICE_3
                                                                                  , static_cast < unsigned int > ( release3Slider -> getValue () ) );
        //[/UserSliderCode_release3Slider]
    }
    else if (sliderThatWasMoved == pitchBend3Slider.get())
    {
        //[UserSliderCode_pitchBend3Slider] -- add your slider handling code here..
        pitchBend3Label -> setText (
                                    pitchBend3Slider -> getTextFromValue (
                                                                          pitchBend3Slider -> getValue () ) + "%"
                                  , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePitchBendChanged > > () -> call (
                                                                                    &LivePitchBendChanged::onLivePitchBendChanged
                                                                                  , SID_VOICE_3
                                                                                  , static_cast < float > ( pitchBend3Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                      &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                    , SID_VOICE_3
                                                                                    , static_cast < float > ( pitchBend3Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pitchBend3Slider]
    }
    else if (sliderThatWasMoved == vibratoAmount3Slider.get())
    {
        //[UserSliderCode_vibratoAmount3Slider] -- add your slider handling code here..
        vibratoAmount3Label -> setText (
                                        vibratoAmount3Slider -> getTextFromValue (
                                                                                  vibratoAmount3Slider -> getValue () ) + "%"
                                      , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> call (
                                                                                        &LiveVibratoAmountChanged::onLiveVibratoAmountChanged
                                                                                      , SID_VOICE_3
                                                                                      , static_cast < float > ( vibratoAmount3Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                          &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                        , SID_VOICE_3
                                                                                        , static_cast < float > ( vibratoAmount3Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoAmount3Slider]
    }
    else if (sliderThatWasMoved == vibratoSpeed3Slider.get())
    {
        //[UserSliderCode_vibratoSpeed3Slider] -- add your slider handling code here..
        vibratoSpeed3Label -> setText (
                                       vibratoSpeed3Slider -> getTextFromValue (
                                                                                vibratoSpeed3Slider -> getValue () ) + "%"
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> call (
                                                                                       &LiveVibratoSpeedChanged::onLiveVibratoSpeedChanged
                                                                                     , SID_VOICE_3
                                                                                     , static_cast < float > ( vibratoSpeed3Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                         &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                       , SID_VOICE_3
                                                                                       , static_cast < float > ( vibratoSpeed3Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_vibratoSpeed3Slider]
    }
    else if (sliderThatWasMoved == pulseWidth3Slider.get())
    {
        //[UserSliderCode_pulseWidth3Slider] -- add your slider handling code here..
        pulseWidth3Label -> setText (
                                     pulseWidth3Slider -> getTextFromValue (
                                                                            pulseWidth3Slider -> getValue () ) + "%"
                                   , dontSendNotification );
        SharedResourcePointer < ListenerList < LivePulseWidthChanged > > () -> call (
                                                                                     &LivePulseWidthChanged::onLivePulseWidthChanged
                                                                                   , SID_VOICE_3
                                                                                   , static_cast < float > ( pulseWidth3Slider -> getValue () / 100.0 ) );
        SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                       &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                     , SID_VOICE_3
                                                                                     , static_cast < float > ( pulseWidth3Slider -> getValue () / 100.0 ) );
        //[/UserSliderCode_pulseWidth3Slider]
    }
    else if (sliderThatWasMoved == vibratoDelay3Slider.get())
    {
        //[UserSliderCode_vibratoDelay3Slider] -- add your slider handling code here..
        vibratoDelay3Label -> setText (
                                       vibratoDelay3Slider -> getTextFromValue (
                                                                                vibratoDelay3Slider -> getValue () )
                                     , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> call (
                                                                                       &LiveVibratoDelayChanged::onLiveVibratoDelayChanged
                                                                                     , SID_VOICE_3
                                                                                     , static_cast < unsigned int > ( vibratoAmount3Slider -> getValue () ) );
        //[/UserSliderCode_vibratoDelay3Slider]
    }
    else if (sliderThatWasMoved == cutoffSlider.get())
    {
        //[UserSliderCode_cutoffSlider] -- add your slider handling code here..
        cutoffLabel -> setText (
                                cutoffSlider -> getTextFromValue (
                                                                  cutoffSlider -> getValue () )
                              , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveCutoffChanged > > () -> call (
                                                                                 &LiveCutoffChanged::onLiveCutoffChanged
                                                                               , static_cast < unsigned int > ( cutoffSlider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportCutoffChanged > > () -> call (
                                                                                   &ExportCutoffChanged::onExportCutoffChanged
                                                                                 , static_cast < unsigned int > ( cutoffSlider -> getValue () ) );
        //[/UserSliderCode_cutoffSlider]
    }
    else if (sliderThatWasMoved == resonanceSlider.get())
    {
        //[UserSliderCode_resonanceSlider] -- add your slider handling code here..
        resonanceLabel -> setText (
                                   resonanceSlider -> getTextFromValue (
                                                                        resonanceSlider -> getValue () )
                                 , dontSendNotification );
        SharedResourcePointer < ListenerList < LiveResonanceChanged > > () -> call (
                                                                                    &LiveResonanceChanged::onLiveResonanceChanged
                                                                                  , static_cast < unsigned int > ( resonanceSlider -> getValue () ) );
        SharedResourcePointer < ListenerList < ExportResonanceChanged > > () -> call (
                                                                                      &ExportResonanceChanged::onExportResonanceChanged
                                                                                    , static_cast < unsigned int > ( resonanceSlider -> getValue () ) );
        //[/UserSliderCode_resonanceSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void LiveMode::labelTextChanged (juce::Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == titleLabel.get())
    {
        //[UserLabelCode_titleLabel] -- add your label text handling code here..
        SharedResourcePointer < ListenerList < LiveTitleChanged > > () -> call (
                                                                                &LiveTitleChanged::onLiveTitleChanged
                                                                              , titleLabel -> getText () );
        //[/UserLabelCode_titleLabel]
    }
    else if (labelThatHasChanged == artistLabel.get())
    {
        //[UserLabelCode_artistLabel] -- add your label text handling code here..
        SharedResourcePointer < ListenerList < LiveArtistChanged > > () -> call (
                                                                                 &LiveArtistChanged::onLiveArtistChanged
                                                                               , artistLabel -> getText () );
        //[/UserLabelCode_artistLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void LiveMode::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == exportButton.get())
    {
        //[UserButtonCode_exportButton] -- add your button handler code here..
        // arm for recording
        armed             = true;
        quarterNoteTicked = true;
        SharedResourcePointer < ListenerList < LiveExportArmed > > () -> call (
                                                                               &LiveExportArmed::onLiveExportArmed );
        SendInit ();
        repaint ();
        //[/UserButtonCode_exportButton]
    }
    else if (buttonThatWasClicked == filter1Checkbox.get())
    {
        //[UserButtonCode_filter1Checkbox] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> call (
                                                                                      &LiveVoiceFilterChanged::onLiveVoiceFilterChanged
                                                                                    , SID_VOICE_1
                                                                                    , filter1Checkbox -> getToggleState () );
        SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                        &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                      , SID_VOICE_1
                                                                                      , filter1Checkbox -> getToggleState () );
        //[/UserButtonCode_filter1Checkbox]
    }
    else if (buttonThatWasClicked == filter2Checkbox.get())
    {
        //[UserButtonCode_filter2Checkbox] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> call (
                                                                                      &LiveVoiceFilterChanged::onLiveVoiceFilterChanged
                                                                                    , SID_VOICE_2
                                                                                    , filter2Checkbox -> getToggleState () );
        SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                        &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                      , SID_VOICE_2
                                                                                      , filter2Checkbox -> getToggleState () );
        //[/UserButtonCode_filter2Checkbox]
    }
    else if (buttonThatWasClicked == filter3Checkbox.get())
    {
        //[UserButtonCode_filter3Checkbox] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> call (
                                                                                      &LiveVoiceFilterChanged::onLiveVoiceFilterChanged
                                                                                    , SID_VOICE_3
                                                                                    , filter3Checkbox -> getToggleState () );
        SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                        &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                      , SID_VOICE_3
                                                                                      , filter3Checkbox -> getToggleState () );
        //[/UserButtonCode_filter3Checkbox]
    }
    else if (buttonThatWasClicked == filterLowPassCheckbox.get())
    {
        //[UserButtonCode_filterLowPassCheckbox] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveLowPassChanged > > () -> call (
                                                                                  &LiveLowPassChanged::onLiveLowPassChanged
                                                                                , filterLowPassCheckbox -> getToggleState () );
        SharedResourcePointer < ListenerList < ExportLowPassChanged > > () -> call (
                                                                                    &ExportLowPassChanged::onExportLowPassChanged
                                                                                  , filterLowPassCheckbox -> getToggleState () );
        //[/UserButtonCode_filterLowPassCheckbox]
    }
    else if (buttonThatWasClicked == filterBandPassCheckbox.get())
    {
        //[UserButtonCode_filterBandPassCheckbox] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveBandPassChanged > > () -> call (
                                                                                   &LiveBandPassChanged::onLiveBandPassChanged
                                                                                 , filterBandPassCheckbox -> getToggleState () * 2 );
        SharedResourcePointer < ListenerList < ExportBandPassChanged > > () -> call (
                                                                                     &ExportBandPassChanged::onExportBandPassChanged
                                                                                   , filterBandPassCheckbox -> getToggleState () * 2 );
        //[/UserButtonCode_filterBandPassCheckbox]
    }
    else if (buttonThatWasClicked == filterHighPassCheckbox.get())
    {
        //[UserButtonCode_filterHighPassCheckbox] -- add your button handler code here..
        //[/UserButtonCode_filterHighPassCheckbox]
    }
    else if (buttonThatWasClicked == patchEditorButton.get())
    {
        //[UserButtonCode_patchEditorButton] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LivePatchEditorModeClicked > > () -> call (
                                                                                          &LivePatchEditorModeClicked::onLivePatchEditorModeClicked );
        setVisible (
                    false );
        //[/UserButtonCode_patchEditorButton]
    }
    else if (buttonThatWasClicked == addPatchButton.get())
    {
        //[UserButtonCode_addPatchButton] -- add your button handler code here..
        if ( !patchSelector -> isVisible () )
        {
            patchSelector -> setVisible (
                                         true );
            SharedResourcePointer < ListenerList < LivePatchListMode > > () -> call (
                                                                                     &LivePatchListMode::onLivePatchListMode
                                                                                   , 1 );
            //patchListMode = 1;
        }
        else
        {
            patchSelector -> setVisible (
                                         false );
            SharedResourcePointer < ListenerList < LivePatchListMode > > () -> call (
                                                                                     &LivePatchListMode::onLivePatchListMode
                                                                                   , -1 );
            //patchListMode = -1;
        }
        //[/UserButtonCode_addPatchButton]
    }
    else if (buttonThatWasClicked == replacePatchButton.get())
    {
        //[UserButtonCode_replacePatchButton] -- add your button handler code here..
        if ( !patchSelector -> isVisible () )
        {
            patchSelector -> setVisible (
                                         true );
            SharedResourcePointer < ListenerList < LivePatchListMode > > () -> call (
                                                                                     &LivePatchListMode::onLivePatchListMode
                                                                                   , 2 );
            //patchListMode = 2;
        }
        else
        {
            patchSelector -> setVisible (
                                         false );
            SharedResourcePointer < ListenerList < LivePatchListMode > > () -> call (
                                                                                     &LivePatchListMode::onLivePatchListMode
                                                                                   , -1 );
            //patchListMode = -1;
        }
        //[/UserButtonCode_replacePatchButton]
    }
    else if (buttonThatWasClicked == removePatchButton.get())
    {
        //[UserButtonCode_removePatchButton] -- add your button handler code here..
        SharedResourcePointer < ListenerList < LiveRemovePatchClicked > > () -> call (
                                                                                      &LiveRemovePatchClicked::onLiveRemovePatchClicked );
        //refreshPatches();
        //[/UserButtonCode_removePatchButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    LiveMode::onProgramParameterChanged (
            unsigned int voice
          , unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           patch1Slider -> setValue (
                                                                     value + 1
                                                                   , dontSendNotification );
                                           patch1Label -> setText (
                                                                   patch1Slider -> getTextFromValue (
                                                                                                     patch1Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                                                     &ExportPatchChanged::onExportPatchChanged
                                                                                                                   , SID_VOICE_1
                                                                                                                   , static_cast < unsigned int > ( patch1Slider -> getValue () ) - 1 );
                                           break;
                                       case SID_VOICE_2:
                                           patch2Slider -> setValue (
                                                                     value + 1
                                                                   , dontSendNotification );
                                           patch2Label -> setText (
                                                                   patch2Slider -> getTextFromValue (
                                                                                                     patch2Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                                                     &ExportPatchChanged::onExportPatchChanged
                                                                                                                   , SID_VOICE_2
                                                                                                                   , static_cast < unsigned int > ( patch2Slider -> getValue () ) - 1 );
                                           break;
                                       case SID_VOICE_3:
                                           patch3Slider -> setValue (
                                                                     value + 1
                                                                   , dontSendNotification );
                                           patch3Label -> setText (
                                                                   patch3Slider -> getTextFromValue (
                                                                                                     patch3Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPatchChanged > > () -> call (
                                                                                                                     &ExportPatchChanged::onExportPatchChanged
                                                                                                                   , SID_VOICE_3
                                                                                                                   , static_cast < unsigned int > ( patch3Slider -> getValue () ) - 1 );
                                           break;
                                   }
                               } );
}


//int LiveMode::getPatchListMode() const {
//	return patchListMode;
//}

void
    LiveMode::HidePatchSelector () const
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   patchSelector -> setVisible (
                                                                false );
                               } );
}


// TODO: Need to figure out what to do about this
void
    LiveMode::RefreshPatches ()
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   //patch1Slider->setRange(1, core->getPatchListSize(), 1);
                                   //patch2Slider->setRange(1, core->getPatchListSize(), 1);
                                   //patch3Slider->setRange(1, core->getPatchListSize(), 1);
                                   //patches->refresh();
                                   repaint ();
                               } );
}

int
    LiveMode::GetPatchListIndex () const { return patches -> getSelectedIndex (); }

void
    LiveMode::SendInit () const
{
    // send volume, patches, etc., here
    // patches
    // filter voices
    SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                    &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                  , SID_VOICE_1
                                                                                  , filter1Checkbox -> getToggleState () );
    SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                    &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                  , SID_VOICE_2
                                                                                  , filter2Checkbox -> getToggleState () );
    SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                    &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                  , SID_VOICE_3
                                                                                  , filter3Checkbox -> getToggleState () );

    // volume
    SharedResourcePointer < ListenerList < ExportVolumeChanged > > () -> call (
                                                                               &ExportVolumeChanged::onExportVolumeChanged
                                                                             , static_cast < unsigned int > ( volumeSlider -> getValue () ) );
    // cutoff
    SharedResourcePointer < ListenerList < ExportCutoffChanged > > () -> call (
                                                                               &ExportCutoffChanged::onExportCutoffChanged
                                                                             , static_cast < unsigned int > ( cutoffSlider -> getValue () ) );
    // resonance
    SharedResourcePointer < ListenerList < ExportResonanceChanged > > () -> call (
                                                                                  &ExportResonanceChanged::onExportResonanceChanged
                                                                                , static_cast < unsigned int > ( resonanceSlider -> getValue () ) );
    // filter type
    SharedResourcePointer < ListenerList < ExportLowPassChanged > > () -> call (
                                                                                &ExportLowPassChanged::onExportLowPassChanged
                                                                              , filterLowPassCheckbox -> getToggleState () );
    SharedResourcePointer < ListenerList < ExportBandPassChanged > > () -> call (
                                                                                 &ExportBandPassChanged::onExportBandPassChanged
                                                                               , filterBandPassCheckbox -> getToggleState () );
    SharedResourcePointer < ListenerList < ExportHighPassChanged > > () -> call (
                                                                                 &ExportHighPassChanged::onExportHighPassChanged
                                                                               , filterHighPassCheckbox -> getToggleState () );
}

void
    LiveMode::onPulseWidthParameterChanged (
            unsigned int voice
          , float        value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           pulseWidth1Slider -> setValue (
                                                                          value * 100.0f
                                                                        , dontSendNotification );
                                           pulseWidth1Label -> setText (
                                                                        pulseWidth1Slider -> getTextFromValue (
                                                                                                               pulseWidth1Slider -> getValue () ) + "%"
                                                                      , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                                                          &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                                                        , SID_VOICE_1
                                                                                                                        , static_cast < float > ( pulseWidth1Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_2:
                                           pulseWidth2Slider -> setValue (
                                                                          value * 100.0f
                                                                        , dontSendNotification );
                                           pulseWidth2Label -> setText (
                                                                        pulseWidth2Slider -> getTextFromValue (
                                                                                                               pulseWidth2Slider -> getValue () ) + "%"
                                                                      , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                                                          &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                                                        , SID_VOICE_2
                                                                                                                        , static_cast < float > ( pulseWidth2Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_3:
                                           pulseWidth3Slider -> setValue (
                                                                          value * 100.0f
                                                                        , dontSendNotification );
                                           pulseWidth3Label -> setText (
                                                                        pulseWidth3Slider -> getTextFromValue (
                                                                                                               pulseWidth3Slider -> getValue () ) + "%"
                                                                      , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPulseWidthChanged > > () -> call (
                                                                                                                          &ExportPulseWidthChanged::onExportPulseWidthChanged
                                                                                                                        , SID_VOICE_3
                                                                                                                        , static_cast < float > ( pulseWidth3Slider -> getValue () / 100.0 ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onAttackParameterChanged (
            unsigned int voice
          , unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           attack1Slider -> setValue (
                                                                      value
                                                                    , dontSendNotification );
                                           attack1Label -> setText (
                                                                    attack1Slider -> getTextFromValue (
                                                                                                       attack1Slider -> getValue () )
                                                                  , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                                                      &ExportAttackChanged::onExportAttackChanged
                                                                                                                    , SID_VOICE_1
                                                                                                                    , static_cast < unsigned int > ( attack1Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_2:
                                           attack2Slider -> setValue (
                                                                      value
                                                                    , dontSendNotification );
                                           attack2Label -> setText (
                                                                    attack2Slider -> getTextFromValue (
                                                                                                       attack2Slider -> getValue () )
                                                                  , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                                                      &ExportAttackChanged::onExportAttackChanged
                                                                                                                    , SID_VOICE_2
                                                                                                                    , static_cast < unsigned int > ( attack2Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_3:
                                           attack3Slider -> setValue (
                                                                      value
                                                                    , dontSendNotification );
                                           attack3Label -> setText (
                                                                    attack3Slider -> getTextFromValue (
                                                                                                       attack3Slider -> getValue () )
                                                                  , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportAttackChanged > > () -> call (
                                                                                                                      &ExportAttackChanged::onExportAttackChanged
                                                                                                                    , SID_VOICE_3
                                                                                                                    , static_cast < unsigned int > ( attack3Slider -> getValue () ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onDecayParameterChanged (
            unsigned int voice
          , unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           decay1Slider -> setValue (
                                                                     value
                                                                   , dontSendNotification );
                                           decay1Label -> setText (
                                                                   decay1Slider -> getTextFromValue (
                                                                                                     decay1Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                                                     &ExportDecayChanged::onExportDecayChanged
                                                                                                                   , SID_VOICE_1
                                                                                                                   , static_cast < unsigned int > ( decay1Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_2:
                                           decay2Slider -> setValue (
                                                                     value
                                                                   , dontSendNotification );
                                           decay2Label -> setText (
                                                                   decay2Slider -> getTextFromValue (
                                                                                                     decay2Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                                                     &ExportDecayChanged::onExportDecayChanged
                                                                                                                   , SID_VOICE_2
                                                                                                                   , static_cast < unsigned int > ( decay2Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_3:
                                           decay3Slider -> setValue (
                                                                     value
                                                                   , dontSendNotification );
                                           decay3Label -> setText (
                                                                   decay3Slider -> getTextFromValue (
                                                                                                     decay3Slider -> getValue () )
                                                                 , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportDecayChanged > > () -> call (
                                                                                                                     &ExportDecayChanged::onExportDecayChanged
                                                                                                                   , SID_VOICE_3
                                                                                                                   , static_cast < unsigned int > ( decay3Slider -> getValue () ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onSustainParameterChanged (
            unsigned int voice
          , unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           sustain1Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           sustain1Label -> setText (
                                                                     sustain1Slider -> getTextFromValue (
                                                                                                         sustain1Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                                                       &ExportSustainChanged::onExportSustainChanged
                                                                                                                     , SID_VOICE_1
                                                                                                                     , static_cast < unsigned int > ( sustain1Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_2:
                                           sustain2Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           sustain2Label -> setText (
                                                                     sustain2Slider -> getTextFromValue (
                                                                                                         sustain2Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                                                       &ExportSustainChanged::onExportSustainChanged
                                                                                                                     , SID_VOICE_2
                                                                                                                     , static_cast < unsigned int > ( sustain2Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_3:
                                           sustain3Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           sustain3Label -> setText (
                                                                     sustain3Slider -> getTextFromValue (
                                                                                                         sustain3Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportSustainChanged > > () -> call (
                                                                                                                       &ExportSustainChanged::onExportSustainChanged
                                                                                                                     , SID_VOICE_3
                                                                                                                     , static_cast < unsigned int > ( sustain3Slider -> getValue () ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onReleaseParameterChanged (
            unsigned int voice
          , unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           release1Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           release1Label -> setText (
                                                                     release1Slider -> getTextFromValue (
                                                                                                         release1Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                                                       &ExportReleaseChanged::onExportReleaseChanged
                                                                                                                     , SID_VOICE_1
                                                                                                                     , static_cast < unsigned int > ( release1Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_2:
                                           release2Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           release2Label -> setText (
                                                                     release2Slider -> getTextFromValue (
                                                                                                         release2Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                                                       &ExportReleaseChanged::onExportReleaseChanged
                                                                                                                     , SID_VOICE_2
                                                                                                                     , static_cast < unsigned int > ( release2Slider -> getValue () ) );
                                           break;
                                       case SID_VOICE_3:
                                           release3Slider -> setValue (
                                                                       value
                                                                     , dontSendNotification );
                                           release3Label -> setText (
                                                                     release3Slider -> getTextFromValue (
                                                                                                         release3Slider -> getValue () )
                                                                   , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportReleaseChanged > > () -> call (
                                                                                                                       &ExportReleaseChanged::onExportReleaseChanged
                                                                                                                     , SID_VOICE_3
                                                                                                                     , static_cast < unsigned int > ( release3Slider -> getValue () ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onFilterVoiceParameterChanged (
            unsigned int voice
          , bool         value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           filter1Checkbox -> setToggleState (
                                                                              value
                                                                            , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                                                           &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                                                         , SID_VOICE_1
                                                                                                                         , filter1Checkbox -> getToggleState () );
                                           break;
                                       case SID_VOICE_2:
                                           filter2Checkbox -> setToggleState (
                                                                              value
                                                                            , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                                                           &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                                                         , SID_VOICE_2
                                                                                                                         , filter2Checkbox -> getToggleState () );
                                           break;
                                       case SID_VOICE_3:
                                           filter3Checkbox -> setToggleState (
                                                                              value
                                                                            , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVoiceFilterChanged > > () -> call (
                                                                                                                           &ExportVoiceFilterChanged::onExportVoiceFilterChanged
                                                                                                                         , SID_VOICE_3
                                                                                                                         , filter3Checkbox -> getToggleState () );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onCutoffParameterChanged (
            unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   cutoffSlider -> setValue (
                                                             value
                                                           , dontSendNotification );
                                   cutoffLabel -> setText (
                                                           cutoffSlider -> getTextFromValue (
                                                                                             cutoffSlider -> getValue () )
                                                         , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportCutoffChanged > > () -> call (
                                                                               &ExportCutoffChanged::onExportCutoffChanged
                                                                             , static_cast < unsigned int > ( cutoffSlider -> getValue () ) );
}

void
    LiveMode::onVolumeParameterChanged (
            unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   volumeSlider -> setValue (
                                                             value
                                                           , dontSendNotification );
                                   volumeLabel -> setText (
                                                           volumeSlider -> getTextFromValue (
                                                                                             volumeSlider -> getValue () )
                                                         , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportVolumeChanged > > () -> call (
                                                                               &ExportVolumeChanged::onExportVolumeChanged
                                                                             , static_cast < unsigned int > ( volumeSlider -> getValue () ) );
}

void
    LiveMode::onPitchBendParameterChanged (
            unsigned int voice
          , float        value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           pitchBend1Slider -> setValue (
                                                                         value * 100.0f
                                                                       , dontSendNotification );
                                           pitchBend1Label -> setText (
                                                                       pitchBend1Slider -> getTextFromValue (
                                                                                                             pitchBend1Slider -> getValue () ) + "%"
                                                                     , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                                                         &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                                                       , SID_VOICE_1
                                                                                                                       , static_cast < float > ( pitchBend1Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_2:
                                           pitchBend2Slider -> setValue (
                                                                         value * 100.0f
                                                                       , dontSendNotification );
                                           pitchBend2Label -> setText (
                                                                       pitchBend2Slider -> getTextFromValue (
                                                                                                             pitchBend2Slider -> getValue () ) + "%"
                                                                     , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                                                         &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                                                       , SID_VOICE_2
                                                                                                                       , static_cast < float > ( pitchBend2Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_3:
                                           pitchBend3Slider -> setValue (
                                                                         value * 100.0f
                                                                       , dontSendNotification );
                                           pitchBend3Label -> setText (
                                                                       pitchBend3Slider -> getTextFromValue (
                                                                                                             pitchBend3Slider -> getValue () ) + "%"
                                                                     , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportPitchBendChanged > > () -> call (
                                                                                                                         &ExportPitchBendChanged::onExportPitchBendChanged
                                                                                                                       , SID_VOICE_3
                                                                                                                       , static_cast < float > ( pitchBend3Slider -> getValue () / 100.0 ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onVibratoAmountParameterChanged (
            unsigned int voice
          , float        value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           vibratoAmount1Slider -> setValue (
                                                                             value * 100.0f
                                                                           , dontSendNotification );
                                           vibratoAmount1Label -> setText (
                                                                           vibratoAmount1Slider -> getTextFromValue (
                                                                                                                     vibratoAmount1Slider -> getValue () ) + "%"
                                                                         , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                                                             &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                                                           , SID_VOICE_1
                                                                                                                           , static_cast < float > ( vibratoAmount1Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_2:
                                           vibratoAmount2Slider -> setValue (
                                                                             value * 100.0f
                                                                           , dontSendNotification );
                                           vibratoAmount2Label -> setText (
                                                                           vibratoAmount2Slider -> getTextFromValue (
                                                                                                                     vibratoAmount2Slider -> getValue () ) + "%"
                                                                         , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                                                             &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                                                           , SID_VOICE_2
                                                                                                                           , static_cast < float > ( vibratoAmount2Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_3:
                                           vibratoAmount3Slider -> setValue (
                                                                             value * 100.0f
                                                                           , dontSendNotification );
                                           vibratoAmount3Label -> setText (
                                                                           vibratoAmount3Slider -> getTextFromValue (
                                                                                                                     vibratoAmount3Slider -> getValue () ) + "%"
                                                                         , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoAmountChanged > > () -> call (
                                                                                                                             &ExportVibratoAmountChanged::onExportVibratoAmountChanged
                                                                                                                           , SID_VOICE_3
                                                                                                                           , static_cast < float > ( vibratoAmount3Slider -> getValue () / 100.0 ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onVibratoDelayParameterChanged (
            const unsigned voice
          , unsigned       value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           vibratoDelay1Slider -> setValue (
                                                                            value
                                                                          , dontSendNotification );
                                           vibratoDelay1Label -> setText (
                                                                          vibratoDelay1Slider -> getTextFromValue (
                                                                                                                   vibratoDelay1Slider -> getValue () )
                                                                        , dontSendNotification );
                                           //SharedResourcePointer < ListenerList < ExportVibratoDelayChanged > > () -> call (
                                           //                                                                                  &ExportVibratoDelayChanged::
                                           //                                                                                  onExportVibratoDelayChanged
                                           //                                                                                , SID_VOICE_1
                                           //                                                                                , static_cast < float > (
                                           //                                                                                      vibratoDelay1Slider ->
                                           //                                                                                      getValue () / 100.0 )
                                           //                                                                                 );
                                           break;
                                       case SID_VOICE_2:
                                           vibratoDelay2Slider -> setValue (
                                                                            value
                                                                          , dontSendNotification );
                                           vibratoDelay2Label -> setText (
                                                                          vibratoDelay2Slider -> getTextFromValue (
                                                                                                                   vibratoDelay2Slider -> getValue () )
                                                                        , dontSendNotification );
                                           //SharedResourcePointer < ListenerList < ExportVibratoDelayChanged > > () -> call (
                                           //                                                                                  &ExportVibratoDelayChanged::
                                           //                                                                                  onExportVibratoDelayChanged
                                           //                                                                                , SID_VOICE_2
                                           //                                                                                , static_cast < float > (
                                           //                                                                                      vibratoDelay2Slider ->
                                           //                                                                                      getValue () / 100.0 )
                                           //                                                                                 );
                                           break;
                                       case SID_VOICE_3:
                                           vibratoDelay3Slider -> setValue (
                                                                            value
                                                                          , dontSendNotification );
                                           vibratoDelay3Label -> setText (
                                                                          vibratoDelay3Slider -> getTextFromValue (
                                                                                                                   vibratoDelay3Slider -> getValue () )
                                                                        , dontSendNotification );
                                           //SharedResourcePointer < ListenerList < ExportVibratoDelayChanged > > () -> call (
                                           //                                                                                  &ExportVibratoDelayChanged::
                                           //                                                                                  onExportVibratoDelayChanged
                                           //                                                                                , SID_VOICE_3
                                           //                                                                                , static_cast < float > (
                                           //                                                                                      vibratoDelay3Slider ->
                                           //                                                                                      getValue () / 100.0 )
                                           //                                                                                 );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onVibratoSpeedParameterChanged (
            unsigned int voice
          , float        value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   switch ( voice )
                                   {
                                       case SID_VOICE_1:
                                           vibratoSpeed1Slider -> setValue (
                                                                            value * 100.0f
                                                                          , dontSendNotification );
                                           vibratoSpeed1Label -> setText (
                                                                          vibratoSpeed1Slider -> getTextFromValue (
                                                                                                                   vibratoSpeed1Slider -> getValue () ) + "%"
                                                                        , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                                                            &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                                                          , SID_VOICE_1
                                                                                                                          , static_cast < float > ( vibratoSpeed1Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_2:
                                           vibratoSpeed2Slider -> setValue (
                                                                            value * 100.0f
                                                                          , dontSendNotification );
                                           vibratoSpeed2Label -> setText (
                                                                          vibratoSpeed2Slider -> getTextFromValue (
                                                                                                                   vibratoSpeed2Slider -> getValue () ) + "%"
                                                                        , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                                                            &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                                                          , SID_VOICE_2
                                                                                                                          , static_cast < float > ( vibratoSpeed2Slider -> getValue () / 100.0 ) );
                                           break;
                                       case SID_VOICE_3:
                                           vibratoSpeed3Slider -> setValue (
                                                                            value * 100.0f
                                                                          , dontSendNotification );
                                           vibratoSpeed3Label -> setText (
                                                                          vibratoSpeed3Slider -> getTextFromValue (
                                                                                                                   vibratoSpeed3Slider -> getValue () ) + "%"
                                                                        , dontSendNotification );
                                           SharedResourcePointer < ListenerList < ExportVibratoSpeedChanged > > () -> call (
                                                                                                                            &ExportVibratoSpeedChanged::onExportVibratoSpeedChanged
                                                                                                                          , SID_VOICE_3
                                                                                                                          , static_cast < float > ( vibratoSpeed3Slider -> getValue () / 100.0 ) );
                                           break;
                                   }
                               } );
}

void
    LiveMode::onPatchEditorLiveModeClicked ()
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   setVisible (
                                               true );
                               } );
}

void
    LiveMode::onBankProgramChanged (
            String                                   old_id
          , ReferenceCountedObjectPtr < SidProgram > program
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   patchSelector -> setVisible (
                                                                false );
                                   RefreshPatches ();
                               } );
}

void
    LiveMode::onLivePatchListChanged (
            Array < String > names
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   int listSize = names . size ();
                                   if ( listSize < 2 )
                                       listSize = 2;
                                   patch1Slider -> setRange (
                                                             1
                                                           , listSize
                                                           , 1 );
                                   patch2Slider -> setRange (
                                                             1
                                                           , listSize
                                                           , 1 );
                                   patch3Slider -> setRange (
                                                             1
                                                           , listSize
                                                           , 1 );
                               } );
}

void
    LiveMode::onLiveTitleChanged (
            String value
            )
{
    titleLabel -> setText (
                           value
                         , dontSendNotification );
}

void
    LiveMode::onLiveArtistChanged (
            String value
            )
{
    artistLabel -> setText (
                            value
                          , dontSendNotification );
}

void
    LiveMode::onQuarterNoteTick (
            unsigned ppq
            )
{
    quarterNoteTicked = true;
    startTimer (
                125 );
    // queue for display thread
    MessageManager::callAsync (
                               [=] () { repaint (); } );
}

void
    LiveMode::timerCallback ()
{
    stopTimer ();
    quarterNoteTicked = false;
    // queue for display thread
    MessageManager::callAsync (
                               [=] () { repaint (); } );
}

void
    LiveMode::onLiveDoneExporting ()
{
    armed = false;
    MessageManager::callAsync (
                               [=] () { repaint (); } );
}

void
    LiveMode::onResonanceParameterChanged (
            unsigned int value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   resonanceSlider -> setValue (
                                                                value
                                                              , dontSendNotification );
                                   resonanceLabel -> setText (
                                                              resonanceSlider -> getTextFromValue (
                                                                                                   resonanceSlider -> getValue () )
                                                            , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportResonanceChanged > > () -> call (
                                                                                  &ExportResonanceChanged::onExportResonanceChanged
                                                                                , static_cast < unsigned int > ( resonanceSlider -> getValue () ) );
}

void
    LiveMode::onLowPassParameterChanged (
            bool value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   filterLowPassCheckbox -> setToggleState (
                                                                            value
                                                                          , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportLowPassChanged > > () -> call (
                                                                                &ExportLowPassChanged::onExportLowPassChanged
                                                                              , filterLowPassCheckbox -> getToggleState () );
}

void
    LiveMode::onBandPassParameterChanged (
            bool value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   filterBandPassCheckbox -> setToggleState (
                                                                             value
                                                                           , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportBandPassChanged > > () -> call (
                                                                                 &ExportBandPassChanged::onExportBandPassChanged
                                                                               , filterBandPassCheckbox -> getToggleState () * 2 );
}

void
    LiveMode::onHighPassParameterChanged (
            bool value
            )
{
    MessageManager::callAsync (
                               [=] ()
                               {
                                   filterHighPassCheckbox -> setToggleState (
                                                                             value
                                                                           , dontSendNotification );
                               } );
    SharedResourcePointer < ListenerList < ExportHighPassChanged > > () -> call (
                                                                                 &ExportHighPassChanged::onExportHighPassChanged
                                                                               , filterHighPassCheckbox -> getToggleState () * 4 );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LiveMode" componentName=""
                 parentClasses="public Component, public ProgramParameterChanged, public PulseWidthParameterChanged, public AttackParameterChanged, public DecayParameterChanged, public SustainParameterChanged, public ReleaseParameterChanged, public FilterVoiceParameterChanged, public CutoffParameterChanged, public ResonanceParameterChanged, public LowPassParameterChanged, public BandPassParameterChanged, public HighPassParameterChanged, public VolumeParameterChanged, public PitchBendParameterChanged, public VibratoAmountParameterChanged, public VibratoSpeedParameterChanged, public TremoloAmountParameterChanged, public TremoloSpeedParameterChanged, public PatchEditorLiveModeClicked, public BankProgramChanged, public LivePatchListChanged"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="1024"
                 initialHeight="576">
  <BACKGROUND backgroundColour="ffffffff">
    <IMAGE pos="0 0 1024 576" resource="liveModeBackdrop_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="472 6 50 22" resource="recordIndicator_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="32 544 154 26" resource="liveModeButtonDown_png" opacity="1.0"
           mode="0"/>
    <IMAGE pos="472 6 50 22" resource="recordIndicatorblink_png" opacity="0.001"
           mode="0"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="2cd41b7a823a6bbf" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="384 32 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="77267ab013a4c949" memberName="volumeLabel"
         virtualName="" explicitFocusOrder="0" pos="384 8 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="ea2554994a1bd489" memberName="patch1Slider"
          virtualName="" explicitFocusOrder="0" pos="32 120 48 48" min="1.0"
          max="2.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4e8cc26315306594" memberName="attack1Slider"
          virtualName="" explicitFocusOrder="0" pos="144 120 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="1ad24ac7e382596a" memberName="decay1Slider"
          virtualName="" explicitFocusOrder="0" pos="224 120 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="86ceaac8aeaf564e" memberName="sustain1Slider"
          virtualName="" explicitFocusOrder="0" pos="304 120 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="67a02650e3bf1cea" memberName="release1Slider"
          virtualName="" explicitFocusOrder="0" pos="384 120 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b6be2677655f033e" memberName="pitchBend1Slider"
          virtualName="" explicitFocusOrder="0" pos="472 120 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="a1b1f8045265aad5" memberName="vibratoAmount1Slider"
          virtualName="" explicitFocusOrder="0" pos="584 120 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="3ebe6e33921f6639" memberName="vibratoSpeed1Slider"
          virtualName="" explicitFocusOrder="0" pos="664 120 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="d7186db8daf701a8" memberName="pulseWidth1Slider"
          virtualName="" explicitFocusOrder="0" pos="831 120 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b29eeec624d1b516" memberName="vibratoDelay1Slider"
          virtualName="" explicitFocusOrder="0" pos="745 120 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="97a610ec74d92c88" memberName="patch2Slider"
          virtualName="" explicitFocusOrder="0" pos="32 208 48 48" min="1.0"
          max="2.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="329c507dbfd0dced" memberName="attack2Slider"
          virtualName="" explicitFocusOrder="0" pos="144 208 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6fcccad9eed35e93" memberName="decay2Slider"
          virtualName="" explicitFocusOrder="0" pos="224 208 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="5a0d208faa663bf6" memberName="sustain2Slider"
          virtualName="" explicitFocusOrder="0" pos="304 208 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="af92bd99b2e6de2a" memberName="release2Slider"
          virtualName="" explicitFocusOrder="0" pos="384 208 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="acc7bbe5ca61970e" memberName="pitchBend2Slider"
          virtualName="" explicitFocusOrder="0" pos="472 208 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="cf2cea10f5929ac1" memberName="vibratoAmount2Slider"
          virtualName="" explicitFocusOrder="0" pos="584 208 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="ec8efa74f5789c53" memberName="vibratoSpeed2Slider"
          virtualName="" explicitFocusOrder="0" pos="664 208 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6ab11e645d2801bf" memberName="pulseWidth2Slider"
          virtualName="" explicitFocusOrder="0" pos="831 208 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4480da81b8994903" memberName="vibratoDelay2Slider"
          virtualName="" explicitFocusOrder="0" pos="745 208 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="4d24c12777705e65" memberName="patch3Slider"
          virtualName="" explicitFocusOrder="0" pos="32 296 48 48" min="1.0"
          max="2.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7f7c4495f4d6895c" memberName="attack3Slider"
          virtualName="" explicitFocusOrder="0" pos="144 296 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="84360ec912119f72" memberName="decay3Slider"
          virtualName="" explicitFocusOrder="0" pos="224 296 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="9bef2d94e5c3a910" memberName="sustain3Slider"
          virtualName="" explicitFocusOrder="0" pos="304 296 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="276013a08dade830" memberName="release3Slider"
          virtualName="" explicitFocusOrder="0" pos="384 296 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="6e6a25b54f111656" memberName="pitchBend3Slider"
          virtualName="" explicitFocusOrder="0" pos="472 296 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="c31a583785ff0dc0" memberName="vibratoAmount3Slider"
          virtualName="" explicitFocusOrder="0" pos="584 296 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="3bf9a0f3188151dc" memberName="vibratoSpeed3Slider"
          virtualName="" explicitFocusOrder="0" pos="664 296 48 48" min="0.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="974c411ac8bb2af9" memberName="pulseWidth3Slider"
          virtualName="" explicitFocusOrder="0" pos="831 296 48 48" min="-100.0"
          max="100.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="c7830b5a236c22e6" memberName="vibratoDelay3Slider"
          virtualName="" explicitFocusOrder="0" pos="743 296 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="7fa0ae86ee59819c" memberName="cutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="32 384 48 48" min="0.0"
          max="2047.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="183ad90c22c4f346" memberName="resonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="32 472 48 48" min="0.0"
          max="15.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a1ff0c7a442565c9" memberName="patch1Label"
         virtualName="" explicitFocusOrder="0" pos="32 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a0efcf827ce8ad6a" memberName="attack1Label"
         virtualName="" explicitFocusOrder="0" pos="144 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="9bd6cba61fa1fdc2" memberName="decay1Label"
         virtualName="" explicitFocusOrder="0" pos="224 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="cc83b81ae4f4a06d" memberName="sustain1Label"
         virtualName="" explicitFocusOrder="0" pos="304 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8e5f365d5a5dbc70" memberName="release1Label"
         virtualName="" explicitFocusOrder="0" pos="384 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="36c38db480f36919" memberName="pitchBend1Label"
         virtualName="" explicitFocusOrder="0" pos="472 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c1f6bec301b79d7d" memberName="vibratoAmount1Label"
         virtualName="" explicitFocusOrder="0" pos="584 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8ac23fb12f7740db" memberName="vibratoSpeed1Label"
         virtualName="" explicitFocusOrder="0" pos="664 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="801f7bd6e8c5db47" memberName="pulseWidth1Label"
         virtualName="" explicitFocusOrder="0" pos="831 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="3ca85f4d30376c25" memberName="vibratoDelay1Label"
         virtualName="" explicitFocusOrder="0" pos="745 96 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a18c101f1ead4881" memberName="patch2Label"
         virtualName="" explicitFocusOrder="0" pos="32 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="3b6cfe32d1875e27" memberName="attack2Label"
         virtualName="" explicitFocusOrder="0" pos="144 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="57219cc5c63e5624" memberName="decay2Label"
         virtualName="" explicitFocusOrder="0" pos="224 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="71a378b31ff055b1" memberName="sustain2Label"
         virtualName="" explicitFocusOrder="0" pos="304 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1b040fd48b548bc9" memberName="release2Label"
         virtualName="" explicitFocusOrder="0" pos="384 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="65cd3aa3e4e183fb" memberName="pitchBend2Label"
         virtualName="" explicitFocusOrder="0" pos="472 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="77cc0c2042855281" memberName="vibratoAmount2Label"
         virtualName="" explicitFocusOrder="0" pos="584 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e7cf4bf7d0abed90" memberName="vibratoSpeed2Label"
         virtualName="" explicitFocusOrder="0" pos="664 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="60d0eee2414147f1" memberName="pulseWidth2Label"
         virtualName="" explicitFocusOrder="0" pos="831 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="cc3838342446bcd3" memberName="vibratoDelay2Label"
         virtualName="" explicitFocusOrder="0" pos="745 184 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="82d95c5b75237c6d" memberName="patch3Label"
         virtualName="" explicitFocusOrder="0" pos="32 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bb59839849758374" memberName="attack3Label"
         virtualName="" explicitFocusOrder="0" pos="144 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="990a2c8aa54fa5f2" memberName="decay3Label"
         virtualName="" explicitFocusOrder="0" pos="224 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d179107269de0e38" memberName="sustain3Label"
         virtualName="" explicitFocusOrder="0" pos="304 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="464a7f5e2f57d037" memberName="release3Label"
         virtualName="" explicitFocusOrder="0" pos="384 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d71ada89c225de12" memberName="pitchBend3Label"
         virtualName="" explicitFocusOrder="0" pos="472 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8312d101bcac31ee" memberName="vibratoAmount3Label"
         virtualName="" explicitFocusOrder="0" pos="584 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="4e70428a209b410c" memberName="vibratoSpeed3Label"
         virtualName="" explicitFocusOrder="0" pos="664 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="47ffecc2d27d0c1a" memberName="pulseWidth3Label"
         virtualName="" explicitFocusOrder="0" pos="831 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0%" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ebb82d923a4a2092" memberName="vibratoDelay3Label"
         virtualName="" explicitFocusOrder="0" pos="745 272 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="99fa4a6e9be5a0ee" memberName="cutoffLabel"
         virtualName="" explicitFocusOrder="0" pos="32 360 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="73084e88377a7883" memberName="resonanceLabel"
         virtualName="" explicitFocusOrder="0" pos="32 448 48 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="a259e531a424fe3" memberName="titleLabel"
         virtualName="" explicitFocusOrder="0" pos="632 8 368 32" textCol="ff5090d0"
         edTextCol="ff5090d0" edBkgCol="0" labelText="" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8d681682ea3ad367" memberName="artistLabel"
         virtualName="" explicitFocusOrder="0" pos="632 48 368 32" textCol="ff5090d0"
         edTextCol="ff5090d0" edBkgCol="0" labelText="" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="14.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <IMAGEBUTTON name="new button" id="e01b6ace04149779" memberName="exportButton"
               virtualName="" explicitFocusOrder="0" pos="480 40 32 32" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="recordnormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="recordover_png" opacityOver="1.0" colourOver="0"
               resourceDown="recorddown_png" opacityDown="1.0" colourDown="0"/>
  <VIEWPORT name="new viewport" id="ec68b886c6fdbc2a" memberName="patchesViewport"
            virtualName="" explicitFocusOrder="0" pos="496 368 512 192" vscroll="1"
            hscroll="0" scrollbarThickness="16" contentType="0" jucerFile="Patches.cpp"
            contentClass="Patches" constructorParams=""/>
  <TOGGLEBUTTON name="new toggle button" id="c2576d71c6341609" memberName="filter1Checkbox"
                virtualName="" explicitFocusOrder="0" pos="120 376 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="d32fb3f5c8b325e2" memberName="filter2Checkbox"
                virtualName="" explicitFocusOrder="0" pos="240 376 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="95c3935c0cfae206" memberName="filter3Checkbox"
                virtualName="" explicitFocusOrder="0" pos="352 376 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="fd523681e6f4bf8e" memberName="filterLowPassCheckbox"
                virtualName="" explicitFocusOrder="0" pos="120 456 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="34fbe61fda3da3c2" memberName="filterBandPassCheckbox"
                virtualName="" explicitFocusOrder="0" pos="240 456 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="high" id="44949d14634c5eb6" memberName="filterHighPassCheckbox"
                virtualName="" explicitFocusOrder="0" pos="352 456 48 48" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <IMAGEBUTTON name="new button" id="dba00e71872790ac" memberName="patchEditorButton"
               virtualName="" explicitFocusOrder="0" pos="208 544 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="patchEditorButtonNormal_png" opacityNormal="1.0"
               colourNormal="0" resourceOver="patchEditorButtonOver_png" opacityOver="1.0"
               colourOver="0" resourceDown="patchEditorButtonDown_png" opacityDown="1.0"
               colourDown="0"/>
  <IMAGEBUTTON name="new button" id="3e22abc9adc07fe1" memberName="addPatchButton"
               virtualName="" explicitFocusOrder="0" pos="488 544 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="addButtonNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="addButtonOver_png" opacityOver="1.0" colourOver="0"
               resourceDown="addButtonDown_png" opacityDown="1.0" colourDown="0"/>
  <IMAGEBUTTON name="new button" id="1ea2fca1deb37c93" memberName="replacePatchButton"
               virtualName="" explicitFocusOrder="0" pos="656 544 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="replaceButtonNormal_png" opacityNormal="1.0"
               colourNormal="0" resourceOver="replaceButtonOver_png" opacityOver="1.0"
               colourOver="0" resourceDown="replaceButtonDown_png" opacityDown="1.0"
               colourDown="0"/>
  <IMAGEBUTTON name="new button" id="5f49d1e41c452392" memberName="removePatchButton"
               virtualName="" explicitFocusOrder="0" pos="824 544 154 26" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="removeButtonNormal_png" opacityNormal="1.0" colourNormal="0"
               resourceOver="removeButtonOver_png" opacityOver="1.0" colourOver="0"
               resourceDown="removeButtonDown_png" opacityDown="1.0" colourDown="0"/>
  <JUCERCOMP name="" id="c8fb9e3b4a2b8f0e" memberName="patchSelector" virtualName=""
             explicitFocusOrder="0" pos="488 368 322 176" sourceFile="PatchSelector.cpp"
             constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: liveModeBackdrop_png, 64009, "../../UI/Live Mode Backdrop.png"
static const unsigned char resource_LiveMode_liveModeBackdrop_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,4,0,0,0,2,64,8,6,0,0,0,19,149,20,213,0,0,0,9,112,72,89,115,0,0,14,195,0,0,14,195,
1,199,111,168,100,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,99,116,69,88,116,67,111,112,121,114,105,103,104,
116,0,67,67,32,65,116,116,114,105,98,117,116,105,111,110,45,78,111,110,67,111,109,109,101,114,99,105,97,108,45,83,104,97,114,101,65,108,105,107,101,32,104,116,116,112,58,47,47,99,114,101,97,116,105,118,
101,99,111,109,109,111,110,115,46,111,114,103,47,108,105,99,101,110,115,101,115,47,98,121,45,110,99,45,115,97,47,52,46,48,47,67,211,34,92,0,0,32,0,73,68,65,84,120,156,236,221,119,152,36,87,125,47,252,
111,85,117,78,147,243,236,236,236,236,236,206,134,89,109,208,74,90,73,139,44,16,40,128,192,178,77,190,96,50,182,113,146,239,203,107,252,114,31,99,95,240,197,247,250,154,7,217,248,114,129,43,124,49,6,27,
48,65,24,1,178,44,25,37,148,181,57,239,204,206,204,78,206,211,57,87,191,127,244,116,79,87,199,234,52,29,230,251,121,30,61,218,174,58,117,234,212,233,234,158,62,167,206,249,29,225,129,135,78,69,64,68,68,
68,68,68,68,68,117,77,172,116,1,136,136,136,136,136,136,136,168,252,216,1,64,68,68,68,68,68,68,180,5,176,3,128,136,136,136,136,136,136,104,11,208,168,77,232,156,187,134,11,63,253,91,44,94,121,5,33,191,
187,164,133,208,26,44,232,216,119,28,251,238,255,3,152,154,187,55,229,124,214,206,1,56,102,71,55,229,90,212,218,236,58,38,202,101,43,126,14,137,136,136,136,136,234,149,160,38,8,160,99,118,4,207,252,205,
7,16,242,149,246,71,122,50,189,181,5,191,242,71,223,66,200,239,222,148,243,149,83,236,90,76,205,93,170,210,111,118,29,171,45,23,109,93,155,117,79,150,19,239,119,34,34,34,34,162,13,170,166,0,156,255,215,
47,110,74,35,192,239,92,198,197,159,127,121,211,206,87,78,177,107,81,107,179,235,152,40,151,173,248,57,36,34,34,34,34,170,103,57,167,0,68,34,50,22,175,188,180,25,101,1,0,44,92,122,30,65,143,125,211,206,
87,78,139,151,95,80,149,110,179,235,88,109,185,104,235,218,236,123,178,156,120,191,231,230,158,113,194,187,232,134,28,172,226,85,97,69,64,215,96,64,195,246,6,8,26,134,175,33,34,34,34,42,68,206,14,0,57,
232,135,28,14,197,95,27,141,18,102,174,189,163,100,5,240,120,66,232,217,249,253,248,107,191,115,89,177,191,156,231,43,247,181,4,85,62,61,221,236,58,86,91,46,218,186,54,243,158,228,253,94,57,33,79,16,87,
255,229,2,236,99,171,149,46,138,106,250,70,61,118,189,99,63,44,61,182,74,23,133,168,38,132,252,33,172,93,89,134,99,108,13,158,121,23,252,107,62,132,125,33,200,225,42,238,240,35,34,170,99,162,36,64,50,
104,160,111,52,192,212,97,133,109,71,35,154,118,183,64,210,75,155,114,254,180,29,0,217,2,127,9,130,0,65,40,93,1,68,49,123,102,229,60,95,185,175,37,28,240,226,145,7,15,229,29,228,176,146,229,74,167,144,
64,112,12,194,86,95,106,249,115,72,153,93,253,126,109,53,254,1,192,191,230,199,165,111,159,193,161,223,187,5,26,147,182,210,197,33,170,90,222,37,15,102,158,187,142,229,115,11,144,67,114,165,139,67,68,
68,235,228,112,4,178,59,136,160,59,8,215,180,19,11,39,102,32,106,68,180,28,104,71,207,237,125,48,180,154,202,122,254,148,14,128,122,8,252,85,109,130,62,23,166,78,60,134,197,171,175,84,85,144,195,228,114,
165,11,148,86,232,253,160,38,111,34,170,28,247,156,27,246,107,181,213,248,143,9,121,66,88,56,57,135,238,219,183,85,186,40,68,85,71,14,202,152,124,242,26,230,94,158,70,68,230,83,126,34,162,90,32,135,100,
44,158,156,195,210,233,121,116,220,210,131,190,187,6,32,150,105,202,99,74,174,245,16,248,171,90,85,107,144,195,108,129,210,138,45,43,131,176,17,85,39,223,82,245,124,7,21,194,91,227,229,39,42,135,128,51,
128,11,223,56,137,217,23,167,216,248,39,34,170,65,17,57,130,185,23,166,112,238,225,19,8,216,253,101,57,135,162,3,160,158,2,127,85,171,133,75,207,87,101,29,167,11,148,86,170,251,129,65,216,136,170,79,173,
55,14,34,156,191,76,164,224,158,117,226,220,87,95,133,107,218,89,233,162,16,17,81,145,60,115,46,156,123,248,53,184,103,75,255,157,174,152,2,80,104,224,47,175,55,172,8,186,149,137,209,40,97,122,244,237,
41,219,86,103,223,173,216,150,24,196,203,227,9,161,185,251,187,57,243,81,91,174,72,36,255,31,141,233,242,41,228,90,128,194,131,28,150,179,142,129,244,129,210,10,189,31,24,132,173,246,137,90,61,68,73,19,
127,255,203,249,57,44,247,103,92,107,48,231,204,167,94,132,3,33,32,156,61,141,160,17,32,106,55,39,200,204,102,136,132,35,144,3,57,46,122,157,160,17,33,106,243,31,78,39,7,195,112,77,57,17,244,4,243,62,
118,43,17,4,64,107,211,195,210,109,133,192,88,28,155,42,224,240,227,242,183,207,34,224,10,84,186,40,68,68,84,34,1,103,0,151,190,117,6,251,63,124,24,134,150,210,197,5,200,186,10,64,62,193,185,100,21,79,
147,50,181,189,147,207,145,28,196,43,57,239,124,218,240,106,202,85,72,62,133,94,75,106,250,234,168,227,88,96,192,108,212,150,53,159,188,243,13,144,88,172,205,62,159,218,50,84,27,65,16,209,186,235,102,
44,92,122,62,190,173,156,159,195,114,230,221,54,116,76,125,102,53,200,62,178,138,217,23,167,224,152,88,131,28,204,221,16,110,189,161,3,131,191,190,119,19,74,182,57,150,207,47,96,228,135,23,85,167,215,
24,181,104,220,217,132,238,227,125,48,117,90,178,166,13,7,66,152,124,114,12,11,175,205,50,136,90,30,52,38,13,186,111,223,142,174,91,183,65,224,138,141,101,39,135,100,92,249,238,121,54,254,137,136,234,
80,208,29,196,229,239,156,199,129,143,223,88,208,67,140,116,114,46,3,72,84,78,155,29,32,177,26,2,50,214,74,128,196,225,183,61,136,103,198,78,111,74,167,72,185,232,45,77,216,123,223,39,42,93,140,242,136,
0,19,255,54,130,217,23,167,42,93,146,154,18,242,6,177,116,110,1,203,23,22,209,255,230,65,116,28,237,73,155,46,236,13,225,252,55,78,193,51,239,218,228,18,214,190,144,39,132,235,255,62,10,231,148,29,187,
223,49,204,78,128,50,155,124,226,26,92,211,142,74,23,131,136,136,202,196,187,232,198,244,51,19,216,118,215,142,146,228,199,63,203,84,21,54,59,64,98,53,4,100,172,246,0,137,182,238,221,184,227,193,127,64,
231,190,215,65,210,25,74,158,191,70,111,70,227,182,125,101,203,187,251,224,155,112,199,31,253,99,213,142,178,40,214,204,47,175,179,241,95,132,136,28,193,216,79,175,98,245,202,82,218,253,163,63,185,204,
198,127,145,86,47,46,97,230,151,19,101,61,71,68,142,192,191,230,83,253,95,173,199,190,72,230,93,242,96,238,229,233,74,23,131,136,136,202,108,246,197,73,4,156,165,25,233,85,150,17,0,146,206,136,183,254,
213,11,8,7,188,248,201,31,223,90,142,83,108,121,245,88,199,11,151,158,71,208,99,175,219,243,165,83,237,1,18,109,93,131,56,246,241,47,1,64,201,238,181,216,189,155,168,156,121,215,163,160,59,136,169,167,
83,27,86,146,78,3,228,152,222,47,234,234,103,254,63,0,8,162,0,201,168,238,79,89,36,36,67,14,38,12,229,143,0,19,143,141,162,113,87,11,132,132,249,77,158,5,55,86,46,44,42,142,213,55,25,96,233,182,150,164,
204,245,42,34,3,142,137,85,132,60,27,177,99,102,158,187,142,174,91,183,149,109,41,163,128,195,143,147,15,189,168,58,253,225,7,143,65,223,88,250,78,199,74,153,121,110,162,238,58,53,136,136,40,149,28,148,
49,245,244,24,6,238,31,42,58,175,178,78,1,80,19,72,44,157,228,32,94,26,131,185,170,150,205,3,212,7,46,83,19,128,175,24,165,168,99,181,193,253,212,74,119,205,233,148,42,64,162,90,155,125,62,53,101,96,128,
68,42,196,234,149,37,197,124,127,173,69,135,61,239,61,0,243,22,108,160,182,12,183,163,101,184,93,117,250,149,75,203,184,250,47,231,17,9,71,59,2,124,43,94,184,103,156,176,244,216,226,105,214,174,172,40,
142,177,246,218,176,247,3,135,74,54,247,174,158,5,92,1,156,253,202,171,8,174,207,71,15,251,195,112,94,183,163,97,160,169,44,231,19,52,34,108,253,13,9,231,15,194,183,228,137,191,54,180,154,160,179,104,
21,233,129,232,15,169,196,97,243,90,139,14,198,214,244,1,150,156,83,14,68,214,99,64,8,26,17,214,94,155,98,127,108,116,65,50,75,143,173,172,247,76,216,31,198,242,185,197,220,9,137,136,168,46,44,157,158,
199,246,187,119,70,31,248,20,161,44,29,0,217,130,190,21,18,148,175,125,247,49,204,156,121,178,216,98,149,92,185,2,3,170,81,202,58,206,39,16,161,250,60,115,167,41,101,128,68,53,54,251,124,106,202,16,123,
31,107,33,48,32,85,143,196,6,14,0,116,220,212,189,37,27,255,133,104,222,211,130,230,189,45,138,134,147,111,201,163,232,0,8,56,149,141,185,230,3,237,108,252,171,164,179,232,208,56,216,140,197,83,115,241,
109,126,123,106,227,184,148,231,219,247,193,195,241,215,139,167,230,48,250,200,165,248,235,158,227,125,104,59,212,153,114,92,208,29,192,133,111,156,138,191,110,59,212,129,157,15,164,15,142,57,242,253,
243,240,175,69,215,98,214,55,234,113,248,65,229,104,165,197,83,115,152,122,106,60,229,184,114,143,54,88,189,178,196,224,148,68,68,91,136,28,148,177,118,101,37,175,7,31,233,84,125,16,64,189,165,9,123,223,
252,137,170,236,0,32,42,149,90,9,12,72,213,65,14,40,127,244,107,76,218,12,41,41,29,173,81,167,120,29,74,90,70,48,18,86,118,162,138,18,27,255,249,72,30,238,159,92,159,213,64,210,73,104,59,212,17,127,109,
237,219,24,69,224,188,110,135,111,197,27,127,29,78,184,63,194,129,176,162,115,195,208,108,132,185,211,130,182,67,29,112,94,119,40,142,75,22,112,5,96,31,89,201,184,191,97,176,25,58,139,46,227,254,100,142,
177,53,213,105,137,136,168,62,216,199,87,235,183,3,64,163,55,163,125,207,109,216,255,182,63,132,193,218,82,233,226,40,9,2,36,173,30,225,64,249,158,106,208,214,20,11,12,120,227,127,250,92,165,139,66,68,
84,183,52,38,109,198,39,254,11,39,102,176,120,106,62,237,190,144,39,164,24,97,16,27,57,208,180,167,21,163,143,92,204,218,1,224,91,242,40,142,77,182,239,131,135,242,234,0,112,207,49,72,37,17,209,86,227,
153,43,126,250,112,213,117,0,24,108,173,184,247,179,79,40,182,133,3,153,255,160,86,130,164,53,212,116,0,190,106,140,169,64,27,170,61,48,32,17,81,45,75,55,92,223,220,105,65,211,158,86,0,64,243,158,54,232,
27,141,241,125,115,47,76,33,228,143,198,217,209,232,53,232,188,181,87,113,92,46,97,95,8,179,47,78,193,191,230,93,63,198,140,166,61,109,241,253,171,151,22,225,158,115,99,241,212,44,28,227,107,232,58,214,
11,201,144,251,231,89,186,184,3,68,68,84,223,252,171,197,127,247,43,254,194,168,9,40,167,54,208,157,90,91,61,40,90,37,234,56,18,14,21,20,56,48,93,185,210,241,122,195,170,130,28,22,18,136,80,109,222,229,
12,200,88,238,50,108,181,207,0,85,72,185,3,94,148,91,173,151,159,42,38,93,7,64,219,161,142,120,7,64,211,158,214,248,191,1,96,241,212,108,188,3,64,50,74,232,189,179,63,175,243,133,124,33,197,57,77,157,
22,69,30,254,53,239,122,7,192,252,122,89,58,85,117,0,132,253,225,156,105,136,136,168,190,196,254,30,21,67,241,23,70,16,68,180,238,186,25,11,151,158,143,111,43,52,208,157,90,106,130,162,233,45,229,137,
30,92,45,54,189,142,131,254,156,101,72,39,83,185,210,41,103,32,194,98,202,90,170,128,140,213,80,6,162,98,232,27,212,15,53,174,70,250,6,125,165,139,64,53,106,231,3,123,16,114,7,49,241,239,163,21,57,191,
243,186,3,163,143,92,84,188,38,34,34,218,44,41,145,141,134,223,246,32,52,122,115,37,202,162,16,11,138,246,244,23,223,15,207,202,108,165,139,67,68,84,87,44,189,13,48,180,164,95,246,172,218,137,146,128,
214,27,58,114,39,36,74,163,237,80,39,154,247,183,229,78,88,38,190,21,47,22,79,205,199,255,203,22,55,32,27,73,47,149,184,100,68,68,84,237,52,250,226,103,240,167,228,96,235,222,141,59,30,252,7,92,248,201,
223,96,113,228,149,138,7,186,139,5,69,35,34,162,210,17,68,1,187,222,177,31,151,191,117,26,129,245,53,219,107,129,168,21,49,112,255,80,198,53,219,137,170,93,195,96,51,122,142,247,101,220,175,53,171,27,
157,99,104,50,192,229,9,150,170,88,68,68,84,3,12,77,197,47,47,155,182,11,193,214,53,136,99,31,255,18,0,84,69,160,187,5,6,69,43,187,76,193,23,75,241,222,75,58,35,222,250,87,202,247,176,26,238,171,82,137,
93,95,61,93,19,109,13,230,78,51,14,254,222,205,88,60,61,15,239,162,7,17,84,247,154,226,58,171,30,173,55,116,192,208,100,204,157,152,168,74,233,44,90,216,250,27,139,206,199,212,97,133,107,218,89,130,18,
17,17,81,173,48,118,22,63,82,63,231,24,2,53,129,1,213,42,52,40,90,189,71,172,151,180,122,68,228,112,69,235,184,86,2,207,21,19,12,145,136,82,73,6,13,58,111,233,169,116,49,136,54,205,201,135,94,128,156,
20,63,111,249,252,18,28,227,47,160,235,216,54,116,30,235,85,236,219,255,225,35,136,200,17,156,124,232,69,4,28,126,156,124,104,163,67,187,121,95,59,244,54,61,102,95,156,68,208,173,12,204,116,238,235,39,
33,74,192,161,63,56,134,195,15,30,131,115,202,129,145,239,95,136,159,43,217,224,219,247,195,218,107,83,125,29,182,29,141,88,56,49,163,58,61,17,17,213,190,134,254,230,162,243,72,219,1,224,156,187,134,11,
63,253,91,44,94,121,5,33,127,106,195,48,223,0,111,49,245,18,20,45,28,244,225,209,79,221,158,182,110,10,203,175,176,160,124,233,212,75,29,103,83,109,193,191,99,129,43,137,136,168,250,249,215,210,252,205,
13,134,225,95,11,35,228,75,141,174,172,179,109,4,156,140,200,202,227,67,158,0,36,157,148,54,207,160,51,186,77,16,5,232,27,13,241,101,251,98,231,74,22,9,229,55,2,167,105,119,11,68,173,8,57,88,221,35,119,
136,136,168,52,68,173,136,198,221,101,232,0,112,204,142,224,153,191,249,64,221,63,117,47,74,36,82,178,198,63,17,17,17,149,70,219,161,78,180,29,234,204,154,230,216,159,223,89,80,222,217,142,83,179,52,160,
173,191,177,224,115,167,35,233,37,180,12,183,99,241,228,92,201,242,36,34,162,234,213,118,176,19,146,174,248,0,176,41,171,0,156,255,215,47,178,241,79,68,68,68,84,229,122,110,239,131,80,195,35,250,136,136,
72,29,81,43,161,71,69,103,179,170,188,18,95,68,34,50,22,175,188,84,116,166,6,91,43,30,120,232,84,74,224,55,42,29,214,49,17,17,209,214,102,104,53,161,131,49,60,136,136,234,94,215,109,189,208,89,212,173,
18,147,139,98,10,128,28,244,199,3,209,1,209,128,107,51,215,222,145,51,147,90,13,40,87,12,181,117,227,245,134,21,117,3,0,145,132,137,250,172,227,252,164,171,207,98,68,50,5,77,200,162,152,64,132,185,238,
7,0,208,26,138,143,238,73,68,68,91,67,223,27,6,224,186,238,128,107,218,81,233,162,16,17,81,25,152,218,205,232,57,190,189,100,249,101,93,5,64,16,4,85,1,215,146,3,202,109,133,160,104,106,235,6,200,30,208,
111,43,212,113,169,203,90,104,128,196,82,42,38,16,97,174,242,183,13,29,43,60,243,18,203,21,16,180,16,177,251,65,107,176,192,218,57,0,199,236,104,89,242,238,216,119,28,251,238,255,3,152,154,187,75,146,
55,17,81,53,18,181,34,134,222,189,31,103,191,246,26,2,206,64,165,139,67,68,68,37,164,53,107,177,251,221,195,16,181,41,51,247,11,86,186,156,136,168,104,122,75,19,246,222,247,137,74,23,3,64,52,32,232,211,
15,189,31,179,103,159,42,75,208,203,160,207,133,149,241,51,101,203,123,234,196,99,120,250,139,239,135,103,101,182,228,249,19,17,85,19,173,85,143,161,247,30,128,198,164,173,116,81,136,136,168,68,180,102,
45,246,188,239,6,24,154,141,37,205,151,29,0,68,85,64,163,55,163,251,224,155,112,199,31,253,99,213,60,177,174,135,128,160,126,231,50,46,254,252,203,149,46,6,17,81,217,153,187,172,24,254,200,97,152,218,
57,141,140,136,168,214,153,218,45,216,255,145,35,48,119,89,75,158,119,214,41,0,68,245,76,99,48,87,188,129,43,233,140,85,25,200,177,84,1,65,171,193,226,229,234,171,95,34,162,114,48,180,152,48,252,177,27,
49,253,204,4,102,95,156,132,28,148,43,93,36,34,34,202,131,168,149,208,117,107,47,122,238,216,14,81,83,158,103,245,138,14,0,81,171,135,40,105,226,129,0,61,158,16,154,187,191,171,56,192,104,148,48,61,250,
246,148,109,229,10,138,166,54,72,94,58,233,202,149,28,76,175,208,124,210,81,19,224,77,111,105,70,208,235,168,170,58,6,210,7,158,43,247,253,144,248,94,108,70,61,36,191,247,133,54,254,139,9,68,88,43,1,255,
10,13,8,154,78,174,207,97,185,63,227,91,53,96,38,17,109,77,162,86,196,182,187,118,160,227,230,30,76,61,61,142,165,211,115,236,8,32,34,170,114,162,86,68,219,193,78,244,220,217,95,178,104,255,153,40,58,
0,4,65,68,235,174,155,177,112,233,249,248,182,228,128,101,153,130,166,151,43,40,90,62,193,246,210,31,175,124,157,28,76,175,208,124,50,201,21,224,173,125,239,109,240,59,87,170,170,142,129,244,129,231,202,
125,63,36,191,23,229,174,135,66,223,251,116,74,21,136,176,154,2,254,101,83,206,207,97,181,124,198,137,136,234,137,206,170,195,192,253,187,177,253,238,1,172,93,89,129,125,124,21,158,57,55,252,171,94,132,
124,97,68,194,236,20,32,34,170,4,65,18,161,49,104,160,111,50,192,212,105,65,67,127,19,26,119,55,67,210,73,155,114,254,148,41,0,195,111,123,16,207,140,157,46,75,96,174,173,46,22,224,45,228,115,85,85,29,
103,11,60,199,251,161,124,170,41,224,31,17,17,213,39,73,167,65,203,112,59,90,134,219,43,93,20,34,34,170,2,41,19,11,108,221,187,113,199,131,255,128,206,125,175,131,164,51,84,162,76,117,39,57,192,91,181,
212,177,154,192,115,213,82,214,122,82,141,1,255,136,136,136,136,136,168,254,165,13,2,104,235,26,196,177,143,127,9,64,116,93,237,159,252,241,173,155,90,168,122,145,45,192,91,37,235,56,223,192,115,133,148,
245,197,151,22,241,153,207,157,198,149,171,142,148,125,130,0,28,62,212,140,63,251,244,65,245,133,174,98,146,206,136,183,124,254,105,156,127,244,111,49,125,242,113,132,131,190,148,52,90,131,5,253,183,253,
6,118,223,245,225,226,230,114,148,128,28,10,228,44,107,223,205,111,83,108,243,122,67,232,31,250,97,74,90,155,77,139,15,190,127,39,254,232,247,247,85,250,178,136,136,136,136,136,40,135,156,171,0,168,9,
4,87,140,66,130,228,149,234,124,229,190,22,181,1,222,54,187,142,139,9,60,167,182,172,185,230,200,255,199,83,115,248,143,167,230,20,219,54,243,189,7,74,187,10,192,153,31,254,15,140,63,255,131,140,251,131,
30,7,46,60,250,37,8,130,136,93,119,125,168,36,231,44,148,154,178,94,122,236,43,16,68,17,17,57,58,71,52,18,1,214,236,129,148,180,107,246,0,62,251,249,51,248,220,95,158,205,171,3,160,26,63,135,68,68,68,
68,68,245,46,103,7,128,154,64,112,165,164,38,72,94,41,149,51,111,181,1,222,54,187,142,139,9,60,87,206,178,110,246,123,223,190,251,24,102,206,60,89,146,188,174,191,252,19,85,233,70,159,249,103,0,2,128,
220,215,37,8,34,154,7,14,163,185,255,134,232,134,72,4,11,151,95,132,125,250,114,94,199,155,154,187,49,123,246,23,8,249,92,121,149,85,16,53,136,200,169,141,254,116,34,145,72,198,160,141,106,84,235,253,
78,68,68,68,68,84,79,114,118,0,0,155,23,8,174,90,131,228,21,34,223,0,111,155,93,199,197,200,167,172,159,253,204,33,124,236,67,187,20,219,254,244,191,158,194,195,223,184,154,182,92,155,245,222,235,45,77,
216,251,230,79,148,168,3,32,2,57,20,109,40,55,52,232,112,233,212,175,42,246,174,173,5,176,247,240,143,1,0,62,251,2,206,255,228,161,188,114,31,184,227,61,56,240,192,255,139,151,254,254,63,99,238,220,83,
121,151,46,113,196,70,162,92,101,141,93,147,154,180,213,138,129,22,137,136,136,136,136,54,164,4,1,76,167,220,129,224,54,59,72,158,70,111,70,227,182,125,155,114,45,106,109,118,29,23,35,159,178,234,116,
34,140,70,73,241,159,70,187,49,86,92,212,232,82,222,251,161,187,63,86,84,249,178,41,119,0,62,1,72,185,94,147,169,184,37,61,174,61,243,207,56,247,227,47,20,212,248,7,144,182,241,15,228,87,214,114,92,87,
57,49,208,34,17,17,17,17,81,42,85,35,0,0,101,32,184,205,176,217,231,171,6,181,116,205,217,202,122,246,71,255,19,163,79,127,91,85,62,130,40,98,241,234,75,120,234,11,239,141,111,147,131,254,248,191,239,
56,222,129,67,55,52,41,142,121,250,217,121,156,62,187,170,216,150,43,221,193,183,127,26,59,142,191,83,177,63,28,240,170,42,99,76,44,176,225,229,164,192,134,225,132,242,170,145,174,172,233,36,150,255,218,
179,255,92,212,241,122,157,136,223,250,232,110,197,126,163,49,181,1,175,215,75,248,131,79,236,81,108,243,251,101,124,247,251,227,217,79,38,8,208,26,173,202,77,16,16,240,216,51,158,223,239,151,241,213,
175,95,81,158,63,71,58,189,165,9,247,253,197,47,178,151,133,136,136,136,136,136,210,82,221,1,16,51,253,236,4,38,159,28,75,217,110,221,102,195,254,143,28,41,73,161,40,183,171,223,63,143,229,115,139,41,
219,59,110,234,198,142,183,108,52,160,46,126,235,52,236,35,171,41,233,122,94,183,29,219,238,218,17,127,125,238,255,156,128,107,58,53,98,127,223,27,119,162,251,248,54,197,182,181,171,43,184,244,237,51,
0,0,99,155,9,7,127,247,230,130,175,35,28,240,33,28,72,141,68,31,243,230,123,123,240,219,73,13,194,63,249,211,19,41,29,0,185,210,201,225,96,74,222,249,6,95,204,56,79,61,207,201,239,233,202,154,78,98,249,
99,193,248,10,61,222,104,212,224,179,159,57,148,243,24,131,65,74,73,103,183,7,114,119,0,68,34,8,122,82,239,159,152,116,231,183,219,3,41,29,0,185,210,201,114,56,199,21,16,17,81,162,144,63,132,181,43,203,
112,140,173,193,51,239,130,127,205,135,176,47,4,57,92,190,216,43,68,68,148,153,40,9,144,12,26,232,27,13,48,117,88,97,219,209,136,166,221,45,144,244,155,51,186,86,117,7,64,68,142,96,241,196,28,92,211,78,
0,64,235,193,14,136,218,232,12,130,213,139,203,8,186,131,88,120,117,22,182,157,141,48,52,25,203,83,218,18,90,189,180,132,160,43,218,40,204,183,204,206,235,107,240,46,68,159,30,155,186,44,176,244,88,115,
28,1,184,166,28,240,204,69,231,181,27,219,77,176,246,53,20,80,106,32,232,10,96,245,210,50,124,43,62,136,90,17,173,7,59,226,251,22,95,155,131,119,209,141,133,87,103,97,233,179,194,117,221,137,128,221,15,
201,168,65,203,254,182,104,162,48,176,112,114,22,238,89,151,34,93,208,29,128,214,162,67,211,158,22,0,128,28,144,177,116,102,30,174,105,7,22,94,157,69,219,141,157,16,234,108,157,183,205,14,190,72,68,68,
180,89,188,75,30,204,60,119,29,203,231,22,32,135,228,220,7,16,17,209,166,144,195,17,200,238,32,130,238,32,92,211,78,44,156,152,129,168,17,209,114,160,29,61,183,247,193,208,106,42,235,249,213,119,0,132,
35,184,246,232,229,248,235,237,119,239,132,214,172,3,0,156,155,141,62,61,190,246,232,101,236,122,251,254,154,232,0,152,126,246,122,252,137,119,190,101,94,60,51,143,133,87,103,1,68,159,164,171,233,0,88,
185,180,136,153,231,38,1,68,159,210,23,218,1,224,91,245,197,223,7,157,85,135,129,251,135,54,202,117,114,30,142,113,59,28,227,118,244,223,59,136,241,199,70,0,68,159,210,199,210,201,65,25,11,39,103,177,
54,178,140,181,145,101,69,58,235,54,91,60,93,192,25,192,210,153,121,172,92,92,196,202,197,69,180,29,238,0,164,210,116,0,124,246,51,135,240,103,159,62,152,118,223,102,7,150,43,36,248,98,186,192,134,185,
36,6,209,211,174,119,156,217,237,1,236,61,252,175,73,233,180,184,120,242,87,227,231,249,179,79,31,76,169,147,207,252,215,83,248,236,231,207,100,56,79,230,227,187,7,190,159,49,109,76,186,50,69,34,17,232,
117,169,61,146,13,13,58,204,142,189,35,227,53,167,11,246,72,68,68,229,37,7,101,76,62,121,13,115,47,79,35,194,78,109,34,162,154,32,135,100,44,158,156,195,210,233,121,116,220,210,131,190,187,6,32,106,84,
133,235,203,91,222,83,0,210,25,122,247,126,132,215,123,151,117,150,104,167,192,204,115,215,177,240,218,108,74,90,91,127,35,6,126,117,8,190,21,47,46,253,99,250,70,12,0,52,14,181,160,255,222,65,184,103,
157,184,250,189,11,0,0,173,89,139,253,31,221,152,102,112,234,239,94,6,214,135,176,245,220,177,29,211,207,76,100,204,175,227,104,55,186,110,223,24,202,158,174,204,233,242,77,166,111,49,64,223,168,46,72,
223,248,207,174,98,237,234,10,0,32,232,221,24,130,190,116,102,62,62,44,63,86,31,106,153,59,45,56,244,135,183,0,136,62,193,206,199,228,147,99,88,58,55,175,216,214,56,212,130,67,67,209,167,254,162,38,247,
176,147,139,223,60,13,239,66,113,17,250,117,90,17,208,166,223,23,8,108,110,96,185,88,64,195,11,63,249,27,44,142,188,146,117,58,66,76,44,176,97,62,98,65,244,146,121,60,202,0,125,58,173,168,252,183,54,181,
78,2,65,25,129,96,250,167,57,217,142,207,118,174,108,101,2,144,182,3,0,72,127,77,49,137,193,30,137,136,168,252,2,206,0,174,124,231,108,124,180,38,17,17,213,150,136,28,193,220,11,83,112,140,173,97,207,
123,14,64,215,160,47,249,57,74,210,1,160,181,234,227,237,185,72,72,134,253,218,42,220,115,78,248,86,189,104,216,209,20,109,253,0,112,78,218,225,89,112,195,126,109,21,162,70,132,111,53,58,140,94,16,1,91,
255,70,80,51,199,132,29,222,249,104,186,136,28,137,167,147,67,202,249,191,254,85,31,34,225,104,67,40,236,15,197,211,137,90,9,214,109,182,104,121,34,17,56,198,214,224,158,117,193,126,109,21,198,22,19,188,
203,30,69,62,146,86,130,168,149,224,93,246,34,96,247,193,191,226,133,214,162,131,113,125,248,69,208,19,132,103,46,186,134,186,160,17,20,29,0,254,85,31,236,215,148,243,209,45,61,54,72,122,9,90,139,14,250,
38,195,122,57,100,132,125,209,134,149,164,215,196,183,107,147,58,31,114,17,181,98,202,104,133,88,185,17,137,64,103,211,195,216,106,130,168,221,104,152,201,193,48,236,215,86,33,135,101,232,27,13,240,175,
110,52,114,37,157,20,31,201,17,227,89,112,193,187,16,173,35,99,139,17,186,6,3,176,62,252,95,103,211,35,232,9,34,224,82,183,62,124,58,207,60,55,143,211,103,146,130,248,189,174,3,7,15,52,41,130,208,61,253,
236,124,186,195,75,46,83,64,195,144,223,131,71,63,117,27,0,101,112,186,67,7,162,247,170,63,32,227,107,15,43,231,176,235,244,34,126,235,35,185,231,231,3,233,3,238,169,233,88,200,22,4,48,223,142,137,98,
228,186,254,95,57,222,1,157,86,84,23,68,144,136,136,138,226,158,117,226,242,183,207,22,245,247,153,136,136,170,131,103,206,133,115,15,191,134,161,247,30,128,185,43,247,104,243,124,148,164,3,32,81,208,
27,194,197,111,158,142,191,222,243,190,3,16,164,232,147,198,83,95,122,25,174,105,7,46,126,243,52,250,239,29,140,167,17,36,17,123,127,115,99,72,248,107,255,243,121,216,199,86,97,31,91,85,164,83,75,223,
168,143,231,39,7,101,188,252,223,158,193,210,185,121,44,157,155,87,12,121,143,217,245,246,253,104,25,110,195,226,201,153,248,48,253,166,161,150,120,48,189,196,160,119,201,98,249,38,26,254,216,17,88,122,
108,232,185,99,59,122,238,216,14,0,184,254,196,104,218,188,75,33,93,185,99,35,15,0,192,191,230,199,197,111,158,198,192,253,67,216,246,250,29,120,249,191,61,147,53,191,233,103,38,226,1,6,219,14,119,43,
130,0,238,124,96,79,214,250,80,227,103,255,54,141,175,252,31,101,195,241,191,255,197,17,28,60,208,164,8,66,247,39,127,122,162,224,115,148,66,36,97,249,188,116,193,233,124,222,16,254,244,179,167,20,219,
26,27,116,170,59,0,210,5,220,83,67,109,16,192,114,203,117,253,247,221,211,131,251,238,233,81,23,68,144,136,136,10,22,112,248,217,248,39,34,170,51,1,103,0,151,190,117,6,251,63,124,24,134,150,210,197,5,
40,121,7,64,181,73,238,92,48,182,152,96,108,55,99,236,103,87,225,91,242,100,57,82,157,214,225,14,180,29,233,4,0,56,174,173,97,250,185,9,140,255,108,4,214,94,27,182,223,151,127,231,133,90,211,207,76,192,
49,190,6,0,176,237,104,140,95,163,206,150,58,76,68,223,168,199,192,219,246,192,212,150,249,198,25,255,233,213,248,200,136,166,61,173,104,63,18,93,59,221,208,92,222,32,20,68,68,68,84,56,57,36,227,202,119,
207,179,241,79,68,84,135,130,238,32,46,127,231,60,14,124,252,198,120,0,254,98,149,164,3,32,232,244,199,231,211,71,10,9,52,27,65,124,248,62,16,29,46,31,27,154,46,233,53,48,52,25,17,112,5,16,145,149,233,
4,68,144,43,188,141,32,2,13,3,202,225,210,186,6,61,52,250,212,75,215,24,180,48,52,25,225,91,243,34,236,15,199,207,21,112,101,94,231,93,223,100,136,231,31,116,71,231,249,187,166,29,200,115,122,190,106,
114,80,70,192,229,135,115,210,14,199,248,42,244,13,70,104,247,233,82,174,49,145,168,149,226,251,229,164,185,227,225,64,24,225,128,23,206,201,53,120,151,188,208,89,245,48,52,25,179,230,183,153,98,1,239,
210,5,183,75,164,45,209,7,98,51,165,11,184,151,78,36,18,41,40,136,96,53,89,179,7,226,65,8,63,251,153,131,248,232,7,119,229,12,34,72,68,68,185,77,62,113,45,237,50,190,68,68,84,31,188,139,110,76,63,51,161,
88,194,189,24,37,233,0,184,252,157,243,241,63,62,133,12,217,151,67,50,78,253,205,75,138,109,173,7,218,49,248,27,251,0,0,109,135,59,227,235,222,39,167,43,165,238,227,125,232,62,222,135,151,62,247,12,150,
206,204,99,233,204,230,204,65,207,135,123,206,133,243,95,143,14,141,215,89,117,241,128,128,133,90,187,188,172,88,5,96,255,71,142,228,56,98,115,197,2,222,165,11,110,87,15,210,5,220,75,71,175,147,242,14,
34,88,109,98,101,13,133,54,186,237,54,51,102,1,17,85,63,57,40,35,232,222,120,146,173,49,104,32,25,234,126,176,98,193,188,75,30,204,189,60,93,233,98,16,17,81,153,205,190,56,137,142,155,123,160,179,230,
23,63,46,29,213,127,85,5,73,192,192,253,67,88,29,89,198,234,165,37,76,60,62,26,31,134,224,95,243,193,208,108,68,247,109,125,176,244,89,49,112,255,16,150,47,45,194,62,178,130,177,159,142,0,98,244,7,127,
200,21,128,169,221,140,206,155,123,21,129,244,4,73,196,142,251,148,203,170,233,91,148,145,246,219,143,116,163,161,191,25,0,226,121,3,128,173,191,1,173,195,157,16,13,234,26,62,174,105,7,22,78,206,194,191,
182,17,8,111,225,196,12,220,115,14,244,189,113,39,0,96,199,91,6,1,121,35,130,185,103,209,133,185,151,138,251,3,219,188,167,13,134,70,19,198,126,118,5,142,241,181,248,82,126,166,54,11,58,111,233,41,40,
207,144,47,164,88,154,49,81,199,145,110,12,220,63,132,217,151,38,17,112,5,54,210,173,199,81,108,28,108,65,243,158,86,32,161,253,149,184,196,96,178,150,125,237,88,190,176,0,0,8,172,109,252,56,75,204,91,
20,69,244,191,57,247,242,120,177,224,112,137,210,5,214,59,149,16,40,208,231,15,227,75,95,190,164,56,38,93,192,189,76,199,11,82,254,63,32,5,113,163,114,18,207,159,46,96,97,76,166,6,173,218,227,19,61,253,
236,60,78,159,93,45,201,249,55,174,73,68,68,150,243,202,179,212,65,252,158,126,118,30,193,128,114,36,74,236,252,137,98,193,34,61,222,141,224,159,249,174,124,65,68,181,197,53,237,192,133,111,108,196,22,
233,189,179,31,189,119,246,87,174,64,85,110,230,185,9,46,245,71,68,180,5,200,65,25,83,79,143,41,150,128,47,148,250,14,0,81,64,251,209,46,200,193,48,28,19,107,88,189,178,172,216,111,106,182,160,253,104,
87,244,223,237,22,4,92,126,184,166,29,88,190,184,176,145,72,4,140,237,38,180,31,237,130,119,209,147,144,55,226,199,38,139,200,17,200,254,48,44,93,86,88,214,35,32,122,23,221,176,143,172,64,50,106,96,238,
177,161,253,104,23,214,70,87,33,25,163,151,147,110,120,127,76,192,238,195,242,249,104,128,187,88,122,215,172,19,1,135,31,189,119,238,64,36,40,163,101,111,187,226,24,105,84,131,185,151,166,33,233,36,104,
244,26,136,26,41,126,108,226,250,140,162,180,145,167,152,84,6,75,175,13,150,94,27,38,159,26,67,192,21,136,151,33,188,51,148,87,7,128,32,110,156,3,64,60,159,100,221,183,245,173,215,203,138,226,124,177,
235,182,110,139,214,219,202,133,133,120,126,114,88,206,152,159,185,211,154,146,71,114,25,36,141,186,14,128,88,112,184,116,210,5,150,3,0,159,47,172,42,224,94,166,227,109,157,249,143,76,209,24,204,48,53,
119,193,179,50,171,56,127,186,128,133,185,20,114,252,159,252,233,137,141,14,128,34,207,191,113,77,22,104,13,230,188,174,169,212,65,252,126,254,111,211,248,249,191,41,59,212,98,231,79,148,46,88,164,173,
171,124,113,53,136,168,114,228,160,12,215,180,35,190,226,78,140,127,205,11,199,248,26,12,173,166,148,37,123,11,21,139,159,3,68,71,24,152,58,45,105,211,121,230,92,8,249,54,70,89,217,250,27,75,114,254,128,
43,160,136,65,84,232,181,133,253,225,120,192,94,34,34,170,127,75,167,231,177,253,238,157,144,116,197,141,140,203,251,232,206,91,123,209,121,107,111,206,116,165,234,181,119,77,59,227,67,222,147,29,253,
228,109,241,21,6,26,119,54,225,166,79,29,207,153,95,243,190,118,52,239,107,79,187,47,49,82,127,58,187,223,57,140,134,193,104,35,37,221,84,135,108,121,199,220,248,201,219,114,150,49,27,75,143,77,213,117,
198,236,126,215,254,172,251,213,148,57,166,227,104,183,234,243,86,147,222,35,247,161,117,240,198,130,142,189,225,215,63,133,151,255,239,39,33,178,74,64,117,0,0,32,0,73,68,65,84,135,213,13,213,175,5,181,
122,77,26,131,25,251,223,246,71,149,46,6,17,149,65,208,29,80,60,249,143,89,60,53,143,197,83,243,216,249,192,30,180,29,234,44,201,185,18,207,99,235,111,192,190,15,30,78,155,110,252,177,171,112,140,219,
227,175,143,253,249,157,37,57,191,125,100,5,163,143,108,140,104,43,244,218,86,175,44,65,14,21,18,120,137,136,136,106,145,28,148,177,118,101,5,45,195,234,218,110,153,84,108,98,157,198,164,65,247,241,62,
0,209,209,5,153,232,172,250,120,186,20,37,30,14,28,237,221,207,82,150,38,67,198,125,180,65,107,216,120,154,18,11,226,167,86,36,162,28,202,248,217,207,28,194,199,62,148,123,84,193,103,62,123,10,15,127,
99,68,113,188,222,210,140,67,239,250,12,58,135,239,80,125,254,100,157,195,119,226,245,127,252,47,56,255,175,95,196,220,249,232,242,137,197,94,147,218,227,3,129,141,161,239,134,134,54,248,236,139,69,159,
95,107,180,230,125,77,145,72,4,94,111,56,30,196,47,93,190,49,137,193,254,18,211,37,6,49,76,39,93,96,195,196,235,239,187,229,87,177,247,190,223,129,177,177,52,13,0,34,170,30,139,167,230,16,90,15,162,171,
181,232,208,56,184,49,26,200,51,231,130,123,206,13,231,245,104,67,188,97,176,25,174,235,107,8,7,178,55,124,205,157,150,248,147,253,181,145,21,4,51,68,200,15,184,130,88,60,53,151,246,184,134,193,22,197,
116,197,100,190,21,111,188,92,217,52,239,107,195,202,133,141,39,245,201,199,36,191,110,222,215,6,73,151,59,62,138,99,108,45,103,26,34,34,170,47,246,241,213,218,237,0,208,154,117,232,123,227,64,206,116,
250,70,189,170,116,165,208,56,216,130,198,193,150,77,57,87,61,235,57,124,55,174,60,241,117,200,225,80,60,136,95,161,116,58,81,85,160,184,64,80,78,9,136,215,127,235,175,163,235,192,157,5,159,59,198,218,
177,3,251,223,250,135,88,184,244,124,73,174,41,223,227,181,70,43,142,190,255,47,241,252,255,254,237,162,207,191,237,200,125,0,10,187,166,108,1,11,117,230,70,4,220,107,25,211,101,10,98,168,230,60,90,163,
21,251,223,250,32,244,150,234,88,153,130,136,74,43,241,105,184,177,213,136,157,15,236,141,191,158,122,106,28,238,57,55,22,78,204,98,225,196,44,246,125,240,16,38,30,31,133,127,45,243,234,60,64,116,20,98,
172,33,63,243,220,132,226,73,126,34,223,146,71,113,254,196,227,122,50,61,124,88,231,188,110,87,28,155,137,173,191,49,107,186,216,181,37,166,87,211,1,224,78,154,46,65,68,68,245,207,51,231,46,58,15,134,
214,165,146,179,118,238,196,205,31,250,107,156,125,228,11,112,47,101,158,82,161,70,186,128,113,233,36,6,252,211,232,77,216,126,236,215,48,116,239,111,23,117,238,68,197,94,147,70,111,66,215,13,111,192,
202,216,233,188,142,111,232,25,194,193,119,252,23,52,247,223,80,244,249,147,235,164,20,239,83,60,223,187,63,142,179,63,252,31,152,57,243,36,194,193,212,31,230,233,130,56,166,147,24,240,15,216,184,126,
54,254,137,182,6,255,154,15,83,79,141,199,95,59,198,87,51,39,70,52,230,79,226,180,68,207,156,19,43,151,150,225,24,95,197,212,83,64,243,158,86,180,29,234,130,173,127,227,59,36,49,127,125,163,30,109,135,
54,98,16,217,250,27,177,122,105,41,109,227,58,54,173,209,191,230,195,226,169,57,120,230,156,235,199,52,40,242,79,41,163,65,163,152,18,25,43,99,76,243,158,22,152,58,173,138,244,106,36,6,51,38,34,162,173,
193,191,90,252,119,63,59,0,168,44,58,135,239,68,231,240,157,8,249,61,136,228,49,215,92,144,36,204,156,122,2,39,254,249,207,0,164,15,24,151,203,177,143,125,169,224,57,255,217,20,122,77,64,244,41,54,132,
232,244,18,181,199,75,122,19,196,132,213,11,138,169,83,141,222,156,118,159,154,60,5,73,130,164,53,32,228,115,167,108,79,204,247,198,247,127,30,71,228,176,34,221,47,254,250,93,41,1,7,213,106,29,60,138,
227,191,247,112,94,199,16,81,109,243,175,249,21,13,244,92,36,163,164,104,92,47,158,154,91,239,0,176,195,49,110,135,190,209,144,50,191,94,217,1,96,72,137,87,52,250,200,69,44,158,74,93,6,56,177,3,32,49,
15,91,127,83,206,152,71,233,202,24,211,180,167,173,160,24,0,97,127,56,119,34,34,34,170,43,33,127,241,49,188,216,1,64,101,165,209,155,242,62,166,247,232,155,49,241,210,143,177,124,45,125,240,199,172,199,
22,17,240,79,173,66,174,169,154,142,47,52,79,173,201,150,51,141,32,74,138,116,133,6,28,100,192,63,162,173,201,208,106,82,12,189,95,189,180,168,104,44,231,98,237,107,192,206,7,246,40,94,231,171,253,72,
55,108,253,77,152,126,238,186,34,90,127,98,25,119,62,176,7,206,235,118,44,156,152,197,234,165,69,248,215,188,41,233,182,223,61,8,141,73,155,247,249,137,136,136,202,137,29,0,84,117,68,73,139,219,127,247,
171,152,62,245,239,112,204,92,85,117,140,32,136,104,218,126,160,168,128,127,84,122,177,128,131,51,167,159,64,200,159,250,67,58,29,157,169,1,189,55,222,203,128,127,68,91,144,206,162,85,60,13,247,175,249,
242,234,0,48,52,27,97,104,54,22,85,6,107,95,3,172,125,13,88,60,53,11,223,82,186,50,234,226,101,92,56,49,11,247,156,27,238,52,115,50,123,239,220,81,214,14,0,73,47,33,228,225,42,0,68,68,91,73,182,229,238,
85,231,81,130,114,16,149,156,40,105,177,237,198,55,3,229,125,152,79,155,192,218,177,3,67,119,127,172,210,197,32,34,42,169,134,193,102,236,251,224,161,148,237,19,143,93,133,123,206,141,171,223,191,0,81,
35,100,92,102,176,88,134,38,3,92,158,96,89,242,38,34,162,234,100,40,193,170,116,236,0,32,34,34,34,202,147,206,162,131,206,162,75,217,46,173,7,241,115,77,57,202,122,126,83,135,21,174,105,103,89,207,65,
68,68,213,197,216,153,62,174,87,62,216,1,64,68,68,68,91,198,225,7,143,33,224,240,227,252,223,159,132,115,202,137,147,15,189,16,223,215,117,108,27,252,14,63,86,46,44,32,224,82,62,93,63,249,208,11,208,89,
13,232,187,103,39,70,190,127,62,99,254,177,227,246,127,248,48,116,54,125,202,254,230,125,109,176,245,55,98,238,197,41,204,190,56,133,137,199,71,48,245,212,88,124,255,254,15,31,73,123,92,50,219,142,70,
44,156,152,201,153,142,136,136,234,71,67,127,115,209,121,176,3,128,136,136,136,182,12,125,227,198,240,201,72,72,134,127,109,99,233,210,144,47,132,144,39,160,216,22,19,219,150,124,76,38,58,155,94,113,174,
24,73,39,69,255,91,31,41,16,242,132,16,242,108,4,74,141,200,17,85,215,209,180,187,5,162,86,132,28,100,28,0,34,162,173,64,212,138,104,220,205,14,0,34,34,34,170,97,199,254,252,206,140,251,122,239,236,79,
89,98,239,240,131,183,22,125,78,125,163,33,235,121,119,62,176,55,235,241,217,142,85,43,221,181,229,67,210,75,104,25,110,199,226,201,185,162,203,66,68,68,213,175,237,96,39,36,157,84,116,62,98,9,202,66,
68,68,68,68,155,172,231,246,62,8,162,80,233,98,16,17,81,153,137,90,9,61,69,116,26,43,242,42,73,46,68,68,68,68,180,169,12,173,38,116,220,210,83,233,98,16,17,81,153,117,221,214,155,54,240,108,33,216,1,64,
68,68,68,84,163,250,222,48,0,75,143,173,210,197,32,34,162,50,49,181,155,209,115,124,123,201,242,99,7,0,17,17,17,81,141,18,181,34,134,222,189,31,58,107,105,158,12,17,17,81,245,208,154,181,216,253,238,97,
136,218,210,53,219,217,1,64,68,68,68,84,195,180,86,61,134,222,123,0,26,147,182,210,69,33,34,162,18,209,154,181,216,243,190,27,96,104,54,150,52,95,118,0,16,17,17,17,213,56,115,151,21,195,31,57,12,83,187,
185,210,69,33,34,162,34,153,218,45,216,255,145,35,48,119,89,75,158,55,151,1,36,34,34,202,194,186,173,161,210,69,32,82,197,208,98,194,240,199,110,196,244,51,19,152,125,113,18,114,80,174,116,145,136,136,
40,15,162,86,66,215,173,189,232,185,99,59,68,77,121,158,213,179,3,128,136,136,40,11,173,153,195,170,169,118,136,90,17,219,238,218,129,142,155,123,48,245,244,56,150,78,207,177,35,128,136,168,202,137,90,
17,109,7,59,209,115,103,127,201,162,253,103,194,14,0,34,162,58,178,116,118,30,65,119,16,0,32,105,36,180,31,237,138,239,243,173,120,177,122,101,57,254,218,214,223,4,115,39,135,11,171,53,254,216,8,124,139,
110,85,105,91,15,119,162,117,184,163,204,37,34,202,76,103,213,97,224,254,221,216,126,247,0,214,174,172,192,62,190,10,207,156,27,254,85,47,66,190,48,34,97,118,10,16,17,85,130,32,137,208,24,52,208,55,25,
96,234,180,160,161,191,9,141,187,155,33,233,164,77,57,63,59,0,136,136,234,200,204,179,215,225,89,136,54,82,53,70,173,162,3,192,51,231,194,196,99,35,241,215,253,247,237,98,7,64,30,220,211,14,56,39,29,170,
210,90,251,27,203,92,26,34,117,36,157,6,45,195,237,104,25,110,175,116,81,136,136,168,10,176,3,128,136,136,84,91,185,184,8,199,132,61,101,251,246,55,14,64,40,211,92,181,106,36,136,2,14,254,238,77,25,247,
215,99,52,246,229,115,139,152,250,197,181,248,235,190,123,118,162,105,119,107,74,58,201,176,57,79,48,136,136,136,40,127,236,0,32,34,34,213,28,99,107,152,123,121,58,101,251,182,55,244,67,218,98,11,203,
24,90,76,149,46,194,166,10,251,67,240,46,123,19,94,135,51,164,20,54,167,64,68,68,68,148,55,118,0,16,17,17,38,30,27,129,111,205,151,118,159,181,183,1,221,199,183,1,0,218,111,236,66,195,142,38,76,61,59,
1,247,140,51,37,173,111,213,139,137,127,27,141,191,110,222,211,138,182,67,157,241,215,211,207,78,192,53,189,113,220,192,91,135,112,237,39,151,211,158,11,0,22,78,204,96,245,202,74,252,245,142,251,118,65,
215,160,207,120,190,100,189,119,108,135,185,59,223,37,116,74,211,128,29,249,209,37,172,156,155,143,191,62,244,224,173,208,89,163,129,125,124,43,94,156,249,95,47,199,247,181,29,238,130,214,172,195,204,
115,19,89,243,212,55,27,113,240,119,111,86,108,155,250,197,120,230,227,68,1,55,255,151,59,0,0,246,107,171,184,252,237,51,57,203,29,43,103,114,25,35,145,136,34,221,232,143,46,226,218,35,151,82,175,47,41,
157,192,14,1,34,34,162,170,193,14,0,34,162,26,35,233,149,67,172,131,142,64,209,121,218,175,173,198,99,7,36,19,132,141,6,156,169,195,2,83,135,5,11,39,103,145,46,117,216,27,194,234,165,165,248,107,67,147,
81,177,223,53,233,80,4,34,148,239,29,84,164,79,60,23,0,120,230,220,138,253,219,222,208,15,29,54,58,0,146,207,151,172,253,72,39,204,80,118,0,248,237,126,197,107,141,94,249,167,48,57,234,127,216,31,134,
214,146,154,119,192,185,81,239,162,70,128,198,168,60,78,163,147,160,49,106,17,242,6,33,135,35,8,186,54,206,27,116,7,32,135,35,16,52,34,180,6,13,68,189,132,136,28,129,28,222,104,60,107,76,90,136,226,70,
125,4,92,1,200,33,25,1,103,0,162,70,128,168,145,16,242,133,16,246,133,32,135,35,144,12,26,72,9,211,48,130,238,32,16,137,32,224,12,64,16,163,237,242,196,252,37,157,6,146,110,35,189,162,156,66,244,189,72,
188,38,57,40,35,228,15,109,92,179,78,121,190,88,59,223,53,167,188,51,184,138,2,17,17,81,245,96,7,0,17,81,141,49,118,40,91,163,115,47,79,161,235,248,182,148,134,172,26,19,143,141,192,62,190,6,223,74,116,
104,247,254,143,28,134,164,137,118,48,120,150,60,24,249,193,5,56,174,173,226,204,87,94,69,219,193,14,116,221,186,45,91,118,69,139,157,43,38,224,80,54,214,175,126,239,2,4,141,136,61,239,187,1,151,190,117,
6,114,40,26,201,188,97,160,9,219,223,180,51,158,110,230,151,215,177,116,110,1,19,63,31,197,228,127,140,99,247,59,247,195,208,108,196,226,153,5,172,94,85,118,24,24,219,149,245,105,221,102,83,188,14,122,
130,48,180,40,59,50,34,114,4,39,190,240,124,252,117,195,64,19,246,254,230,65,4,93,65,68,194,50,116,13,122,244,191,101,23,250,223,178,11,231,191,126,2,206,73,7,206,126,245,181,148,235,181,245,53,96,239,
111,30,4,0,76,62,57,166,216,55,244,158,97,88,183,53,0,136,54,220,95,254,220,211,240,175,250,112,226,11,207,163,97,160,9,45,251,219,21,163,39,118,188,101,23,90,15,108,172,60,112,226,11,207,35,224,12,224,
196,23,158,135,161,217,136,254,183,236,86,228,223,253,186,109,232,121,221,246,248,235,196,114,10,162,128,91,62,243,43,56,242,201,219,226,251,23,94,155,205,122,190,24,111,66,71,146,32,8,176,36,213,39,17,
17,17,85,14,59,0,136,136,106,76,227,238,230,248,147,101,32,250,132,58,96,247,67,211,158,255,87,186,111,197,11,207,156,43,254,218,212,97,134,164,139,230,19,27,242,29,242,135,16,154,115,33,176,163,169,4,
165,207,46,118,174,76,188,75,158,104,217,66,178,162,220,146,94,3,83,215,70,67,62,22,132,207,183,26,237,216,144,67,209,249,234,179,207,93,7,18,70,168,91,123,109,41,43,33,216,6,154,97,108,51,195,155,109,
201,63,1,176,246,108,52,108,77,237,209,60,60,11,46,120,151,61,104,222,219,6,141,81,11,81,18,162,29,54,17,192,53,235,138,47,189,38,106,68,152,59,45,241,227,170,65,172,156,0,0,49,97,100,128,63,148,181,115,
41,236,11,33,28,218,88,82,78,72,152,2,208,50,220,6,109,153,215,51,38,34,34,34,245,216,1,64,68,84,99,52,122,13,250,238,30,192,181,31,95,206,157,120,139,88,187,178,132,87,254,251,115,241,215,114,40,247,
26,231,162,70,196,192,3,123,82,182,11,34,48,248,107,123,112,254,239,79,102,204,71,16,4,236,255,232,145,180,251,198,127,122,21,227,63,189,138,253,31,57,2,235,54,27,6,238,143,62,121,143,61,145,7,0,157,77,
159,241,248,74,137,149,51,81,68,142,224,250,227,163,24,120,235,80,198,227,198,126,122,21,75,103,231,83,182,235,26,244,216,126,239,96,73,203,72,68,68,68,197,97,7,0,17,81,13,106,63,220,133,176,39,132,235,
79,142,34,146,208,70,149,116,18,36,189,132,176,63,140,8,34,138,57,219,114,48,154,80,144,196,232,28,114,169,250,162,246,11,162,0,81,43,34,18,142,64,14,201,16,53,34,4,73,128,28,148,17,145,35,25,143,139,
68,148,79,158,69,73,0,164,141,88,9,130,160,188,86,157,69,135,129,7,134,96,108,77,31,201,223,220,109,197,190,15,29,194,232,15,47,230,85,126,125,163,33,62,172,94,111,139,198,42,88,27,93,69,200,19,84,60,
37,15,7,194,88,58,187,0,157,69,7,219,142,198,180,121,217,71,87,225,95,91,159,2,177,126,237,146,78,131,166,221,45,48,118,150,110,5,130,128,221,15,191,211,159,126,167,156,187,35,165,105,168,21,250,70,67,
252,245,220,75,83,104,24,108,198,142,183,236,130,214,204,167,255,68,68,68,213,132,29,0,68,68,53,170,235,246,109,104,220,221,140,217,23,167,32,172,55,230,99,79,149,95,249,252,179,8,123,67,120,245,47,159,
75,57,174,243,230,30,108,191,39,58,95,126,245,74,230,0,122,149,208,52,212,138,221,239,218,143,217,231,39,49,241,248,40,250,222,180,19,157,183,244,224,242,63,157,85,4,15,204,116,92,46,134,22,35,26,119,
53,161,251,120,95,74,208,190,100,150,30,27,14,124,226,102,68,2,153,150,187,75,147,127,179,17,219,238,218,161,216,54,253,212,24,156,147,14,197,182,160,43,128,145,31,92,64,195,64,83,198,14,128,169,167,198,
83,182,105,45,90,12,190,125,47,128,232,156,252,82,112,78,218,177,114,113,49,227,254,134,129,236,83,63,90,134,219,208,50,220,22,127,221,56,212,2,107,47,231,253,19,17,17,85,35,118,0,16,17,213,48,99,155,
57,237,240,108,83,187,25,33,127,88,49,143,93,163,215,64,215,104,136,47,69,7,0,250,38,3,76,29,22,248,150,61,144,67,50,60,11,30,136,235,65,0,189,235,129,1,19,143,11,56,3,8,186,131,8,37,173,1,239,89,240,
64,163,151,32,234,36,152,58,44,8,251,131,240,175,249,17,244,4,224,78,136,10,159,124,92,38,90,179,14,166,14,11,52,25,34,200,11,162,0,83,135,5,145,80,24,222,101,47,194,254,144,226,60,49,134,38,131,98,213,
4,53,157,4,137,68,73,0,140,105,254,84,70,162,75,26,102,98,235,111,66,200,19,128,103,193,13,255,122,32,195,206,91,122,32,105,163,121,133,124,65,204,191,58,3,255,154,15,211,207,78,192,220,149,186,204,64,
235,193,14,232,173,6,197,54,141,121,163,44,230,46,11,122,142,111,135,99,98,21,206,73,7,86,47,47,193,159,176,148,99,56,16,134,32,8,232,190,189,79,113,92,178,150,225,118,180,12,183,103,220,175,246,124,157,
183,244,66,210,73,108,252,19,17,17,85,49,118,0,16,17,213,161,253,31,61,130,144,39,136,87,255,234,151,241,109,182,129,166,148,6,112,255,125,187,0,0,103,190,252,10,60,11,110,156,127,248,68,74,94,137,199,
141,255,236,42,230,94,158,78,73,115,254,225,19,208,24,181,56,250,169,219,113,195,239,28,197,202,133,69,92,249,222,121,44,157,158,199,210,233,212,249,225,185,180,30,236,64,235,193,212,8,243,49,146,65,194,
13,191,115,20,238,25,39,206,126,237,53,216,175,173,226,236,87,94,73,73,55,244,222,97,52,237,110,205,251,252,185,68,34,145,148,168,253,137,182,221,21,141,134,191,116,118,33,190,173,231,120,31,180,214,232,
180,0,239,178,23,243,175,206,192,183,226,197,228,147,99,104,63,210,157,178,92,94,199,209,238,248,42,0,233,152,187,173,48,119,91,49,249,36,224,156,116,96,249,220,34,150,207,41,159,228,11,162,128,109,111,
140,142,72,88,27,93,205,251,58,243,57,95,251,161,78,72,58,41,75,14,68,68,68,84,105,236,0,32,34,170,83,130,70,64,211,208,70,227,215,210,99,205,152,182,97,71,19,244,77,198,180,251,18,143,51,117,88,20,121,
38,74,124,210,174,181,233,51,166,75,36,106,69,85,101,180,108,179,1,130,16,127,29,155,211,47,25,52,89,207,163,53,235,115,150,65,173,238,227,125,8,58,131,170,210,90,122,172,176,246,54,192,182,125,99,248,
188,100,216,104,224,235,44,58,12,220,191,49,114,195,216,110,196,218,213,194,26,232,205,123,91,161,111,48,164,223,41,110,196,69,48,183,155,20,231,204,118,63,20,114,190,196,235,35,34,34,162,234,36,60,240,
208,169,204,81,149,136,136,136,104,83,76,62,57,166,152,86,176,255,35,135,179,142,0,32,34,34,34,202,23,71,0,16,17,17,4,68,0,8,57,211,109,22,25,209,210,40,75,20,65,4,2,4,33,26,245,191,38,196,46,32,146,187,
126,219,14,119,194,182,125,35,32,160,169,205,188,126,108,250,67,35,17,197,160,136,194,85,215,91,79,68,68,68,101,196,14,0,34,34,66,164,202,90,128,241,118,115,154,173,53,211,248,7,18,46,32,119,253,26,154,
141,48,52,167,153,134,145,225,208,146,52,254,179,228,79,68,68,68,245,39,239,14,128,215,13,156,193,111,222,248,120,198,253,159,252,201,111,195,238,75,141,102,156,139,253,218,42,236,163,43,138,53,171,171,
145,168,149,96,219,222,132,166,161,102,8,37,251,245,85,219,66,222,32,230,95,155,133,123,218,137,112,53,191,127,162,0,157,85,135,230,125,109,104,218,213,82,233,210,196,177,254,138,195,250,43,14,235,175,
188,212,212,175,214,170,131,206,154,57,86,129,111,201,131,112,30,75,17,22,164,70,235,183,220,248,249,40,14,235,175,56,206,41,7,150,78,205,195,111,247,34,18,174,222,158,79,81,43,193,212,102,70,199,77,221,
208,53,148,46,238,74,185,241,254,164,173,42,239,24,0,175,31,60,133,15,28,125,44,227,254,7,127,252,251,88,243,154,85,231,23,145,129,209,31,93,80,68,74,174,5,13,3,77,24,122,239,1,136,26,177,210,69,169,40,
239,178,23,23,190,113,10,65,167,191,210,69,201,75,251,209,46,69,48,172,74,97,253,21,135,245,87,28,214,95,121,177,126,107,27,223,191,226,176,254,138,51,251,194,36,38,30,31,77,30,6,85,213,36,157,6,67,239,
29,134,173,191,49,119,226,10,227,253,73,91,89,197,167,0,204,189,52,89,115,141,127,32,58,98,97,242,201,49,108,191,103,103,165,139,82,148,177,71,175,34,236,139,70,181,214,88,117,232,191,103,48,175,227,175,
61,114,177,230,190,60,1,96,225,213,89,52,236,104,70,203,254,182,188,142,155,123,121,26,174,235,246,180,251,88,127,234,77,253,98,28,190,101,79,218,125,198,78,51,122,142,111,87,149,207,86,171,191,108,247,
95,12,235,175,122,176,126,55,215,202,197,69,248,87,125,89,211,24,218,76,170,159,160,109,213,247,111,241,228,28,66,222,32,58,143,109,195,250,98,27,8,184,2,88,62,179,177,156,167,165,215,10,107,95,246,70,
222,86,170,191,176,63,140,133,215,102,242,62,87,215,109,219,210,110,247,204,187,112,253,241,107,53,213,248,7,128,112,32,132,145,31,92,192,161,63,56,6,81,91,221,15,200,182,210,253,73,148,172,226,29,0,139,
167,242,95,31,186,90,44,158,154,171,249,14,128,213,75,139,8,184,2,0,0,99,139,17,200,163,1,27,112,248,224,156,116,148,171,104,101,183,124,110,33,239,47,80,215,117,7,150,206,165,239,176,98,253,169,103,31,
93,129,115,42,253,181,55,122,155,0,21,13,216,173,88,127,217,238,191,24,214,95,117,96,253,110,190,249,215,102,97,31,89,201,154,166,101,184,93,69,7,64,4,1,135,127,203,190,127,211,191,188,14,223,146,7,29,
55,245,64,16,163,141,56,255,154,47,250,52,122,93,247,241,190,172,29,0,91,237,254,15,121,131,138,250,81,43,83,7,192,242,185,69,68,106,42,216,201,134,128,51,0,231,132,29,13,131,77,185,19,87,200,86,187,63,
137,146,85,188,3,192,239,200,222,91,95,205,66,222,32,194,129,16,36,93,197,171,49,111,215,30,189,12,239,156,27,33,239,198,154,214,126,187,31,231,31,62,1,75,175,13,219,239,205,221,144,13,56,3,229,44,98,
217,149,162,231,119,232,189,195,208,24,52,56,255,247,167,88,127,42,76,253,98,28,246,209,21,120,22,220,0,214,235,207,164,3,0,4,214,252,184,250,253,243,112,77,57,113,254,225,19,104,218,211,138,238,227,125,
25,243,218,138,245,151,140,245,87,189,88,191,213,201,51,235,196,248,207,174,162,97,103,19,154,134,90,51,164,18,182,228,251,55,255,234,52,188,11,30,4,221,27,215,30,14,132,48,249,196,152,98,27,16,29,5,57,
254,179,171,104,57,208,158,118,169,202,173,88,127,37,61,191,187,182,235,47,224,170,238,239,15,222,159,180,213,85,188,229,42,200,149,46,65,113,106,180,131,22,222,57,119,202,19,88,57,36,195,57,229,128,164,
151,212,101,82,163,215,30,83,138,226,155,187,108,208,154,162,31,35,214,95,110,190,101,175,226,190,51,119,217,160,179,70,27,176,62,99,116,74,64,200,31,130,115,202,1,99,71,142,88,34,91,176,254,146,177,254,
170,88,213,23,48,187,26,47,126,70,222,101,47,188,203,211,16,117,82,150,14,0,212,124,5,20,82,252,149,75,203,41,35,40,194,1,25,115,47,79,167,164,117,207,56,225,158,113,194,216,110,78,219,1,176,21,235,175,
190,10,80,156,170,31,189,80,229,197,203,165,198,139,79,85,160,108,29,0,142,137,181,172,17,75,173,253,141,16,197,250,137,162,239,24,91,83,253,133,39,233,53,48,181,155,32,106,213,53,20,157,215,215,176,114,
121,25,190,21,47,100,127,97,145,160,123,238,216,14,91,127,35,198,126,122,5,171,23,151,226,79,254,111,248,237,163,208,88,162,13,8,255,170,23,231,191,126,18,246,113,59,78,252,245,243,104,61,216,129,190,
55,237,196,234,213,21,204,189,48,25,207,203,216,106,66,255,155,119,21,84,142,106,228,91,242,96,236,103,87,179,166,137,213,95,58,130,36,226,200,39,111,99,253,101,145,173,254,98,244,77,38,28,249,228,109,
241,215,177,249,131,172,63,117,245,151,9,235,111,157,40,64,107,214,193,210,107,69,235,254,118,104,76,218,188,206,227,93,246,34,232,240,231,252,158,23,68,192,214,95,189,67,95,243,21,9,71,224,152,88,83,
157,94,99,208,192,212,110,134,160,50,64,174,103,214,133,197,115,243,240,45,122,32,135,10,123,34,176,237,174,29,176,244,216,176,237,206,126,116,222,220,173,216,23,246,134,49,242,163,139,48,180,154,176,
253,238,1,56,39,236,152,249,229,36,86,46,44,194,187,224,70,199,205,61,104,28,108,198,252,75,211,88,185,188,4,65,16,176,231,253,55,20,84,142,106,20,1,112,233,155,167,179,166,137,213,95,204,142,251,119,
67,103,211,65,208,8,192,250,131,198,88,253,197,172,92,88,84,76,225,140,213,31,0,180,29,238,130,161,201,80,186,139,168,176,197,83,115,88,58,147,126,186,170,206,172,195,206,223,216,27,127,109,106,55,99,
219,27,119,228,204,243,218,143,175,40,158,242,95,76,120,143,118,191,107,127,17,165,173,62,87,191,119,30,33,95,238,8,251,162,70,132,177,221,132,150,225,78,152,59,213,7,19,7,128,136,28,81,247,251,88,20,
212,63,164,169,1,17,25,144,85,174,94,32,25,52,92,242,149,226,114,118,0,152,181,62,252,202,206,141,47,166,157,45,234,130,156,140,252,203,133,248,220,242,116,142,254,127,199,33,234,43,62,0,161,100,174,124,
231,92,94,75,24,138,26,17,45,7,218,177,237,174,1,232,214,27,224,201,66,158,16,70,126,120,1,107,57,230,52,170,209,118,164,19,64,244,199,80,226,251,34,25,52,208,26,162,239,67,120,253,255,145,176,140,128,
43,16,255,194,14,58,252,176,95,91,141,31,83,246,229,168,54,89,200,23,82,92,95,58,177,250,203,68,103,209,197,191,132,89,127,169,226,245,39,9,16,36,17,17,89,6,34,209,186,138,36,252,232,215,26,52,136,8,2,
68,105,227,175,20,235,47,243,253,151,88,127,17,121,189,97,42,0,130,40,66,88,239,96,101,253,41,45,157,158,195,212,19,99,232,127,243,32,90,15,102,255,92,3,209,185,184,83,79,141,193,187,148,62,104,101,50,
141,73,139,163,127,124,187,234,242,84,187,176,63,164,104,156,168,33,233,36,180,29,233,194,182,215,239,200,248,99,59,18,146,49,246,243,171,88,56,49,91,244,227,172,216,60,106,75,175,45,101,95,236,239,157,
198,160,65,211,238,86,132,3,209,207,139,111,197,11,223,138,23,141,187,163,241,0,60,139,110,216,175,173,214,223,242,190,145,72,206,207,71,242,60,116,91,127,35,140,173,38,197,182,88,253,197,120,22,148,159,
135,88,253,197,142,175,167,14,0,223,138,55,99,29,234,27,149,215,169,49,41,235,41,19,81,171,236,180,76,204,191,154,151,251,43,132,125,124,13,33,79,48,119,66,0,171,87,150,49,243,203,73,116,220,216,141,254,
251,6,33,72,153,59,18,195,222,16,102,158,159,196,202,133,5,120,87,188,170,190,71,76,93,22,220,240,91,71,213,22,189,234,121,231,93,56,243,213,87,85,165,21,68,1,198,14,51,218,15,118,162,227,104,183,234,
78,90,170,79,57,91,224,54,131,27,239,60,244,139,205,40,203,150,34,135,100,44,158,156,195,218,200,42,246,127,224,32,12,73,127,108,229,96,24,23,190,121,10,158,57,87,89,203,113,242,161,23,203,154,63,81,162,
193,95,219,131,193,95,219,131,243,15,159,128,115,202,145,246,254,107,220,217,132,61,239,63,88,129,210,213,158,180,245,55,192,250,203,37,228,15,97,228,71,151,16,145,129,182,195,153,59,1,38,159,184,134,
233,231,174,111,98,201,234,67,56,16,198,220,139,83,176,143,174,96,223,7,15,65,107,78,234,228,142,0,35,143,92,196,242,185,197,202,20,144,168,76,92,211,46,156,249,242,43,104,218,211,138,109,111,72,29,9,
48,250,227,75,112,79,59,17,172,241,57,232,101,21,1,230,95,157,65,216,23,198,224,219,247,166,77,226,89,112,225,210,183,206,34,224,224,92,120,181,34,114,4,158,89,23,198,103,71,176,120,102,30,67,239,61,144,
241,1,36,213,63,118,255,84,88,208,233,199,229,239,156,131,156,212,227,59,253,204,245,178,55,254,1,192,208,108,132,161,197,4,67,139,9,250,58,234,177,167,234,166,111,52,196,239,187,228,251,47,28,144,225,
91,242,32,152,101,4,17,165,18,37,1,134,22,19,116,182,245,207,113,108,132,133,92,95,79,147,74,105,252,231,87,51,222,103,203,231,22,216,248,47,146,119,209,131,145,31,92,76,217,190,122,105,137,141,127,170,
75,114,48,12,207,130,27,129,12,1,174,253,171,94,120,22,220,41,191,249,40,213,210,185,121,172,174,79,43,73,20,242,132,216,248,47,146,123,198,137,171,223,57,135,72,141,199,97,163,194,149,109,12,190,117,
123,163,34,194,124,50,161,142,230,255,3,209,33,111,225,160,186,161,181,254,53,31,124,43,222,248,107,239,146,7,203,103,231,209,118,40,250,36,42,34,3,243,73,235,201,90,183,55,162,243,230,30,104,140,133,
189,101,198,118,83,218,237,251,62,116,120,35,136,216,178,7,167,190,244,114,74,154,134,221,205,216,251,155,27,79,20,165,58,154,186,1,0,198,54,147,226,250,210,166,201,80,127,106,176,254,82,235,111,240,237,
251,82,210,196,238,63,231,164,29,167,254,238,101,180,223,216,133,129,183,14,177,254,160,238,254,211,55,26,112,240,247,111,142,191,14,249,66,112,207,58,97,104,49,110,249,250,3,0,200,17,184,231,92,152,122,
122,28,114,48,250,171,39,28,8,99,241,244,60,186,111,79,93,138,107,234,23,99,138,215,130,70,132,181,215,26,95,22,45,19,141,161,190,234,87,144,4,52,12,168,143,105,224,93,242,40,126,152,219,175,173,194,49,
110,135,173,127,35,80,220,92,210,223,55,99,171,9,189,119,238,128,198,84,88,221,153,59,45,0,128,203,223,61,7,199,168,114,168,118,44,100,131,123,218,137,87,62,255,108,188,67,172,243,214,94,108,123,125,63,
4,41,58,69,161,235,88,47,154,247,181,161,238,38,201,10,200,249,249,136,213,95,204,217,175,190,26,159,10,145,28,242,98,229,194,34,70,31,185,148,210,128,221,168,63,192,208,100,64,208,173,110,200,119,45,
104,59,212,153,57,6,208,250,48,106,125,131,1,55,125,250,56,156,215,237,184,244,173,179,88,58,179,128,149,11,169,141,87,57,20,253,157,120,240,119,111,130,174,65,31,223,94,207,223,209,187,223,185,79,85,
67,51,228,9,98,242,23,227,240,45,111,76,47,153,127,117,38,37,88,231,204,243,19,41,141,127,65,20,32,170,152,219,95,79,243,255,1,0,34,32,169,108,23,132,125,33,197,52,9,231,148,3,203,103,231,209,122,176,
163,76,133,163,106,150,243,174,89,241,218,240,197,167,223,25,127,125,160,123,20,111,220,245,90,206,140,119,189,35,245,7,126,61,219,253,158,97,213,105,35,145,8,70,31,185,140,165,211,115,241,109,171,87,
150,227,29,0,190,21,143,98,190,148,214,172,197,222,247,221,16,15,138,182,217,244,86,61,244,86,125,238,132,53,74,210,107,242,250,129,155,34,18,93,215,222,191,190,44,139,198,164,129,185,219,10,99,91,52,
136,13,235,111,131,103,222,165,24,250,104,235,111,204,57,15,141,245,151,153,173,191,1,162,36,98,109,116,21,161,128,12,251,200,10,52,38,45,204,221,86,104,140,69,222,215,53,34,159,250,107,24,108,134,160,
17,49,241,216,72,124,155,115,202,14,64,217,1,224,93,242,192,187,188,209,73,43,106,68,236,255,232,141,121,7,166,170,7,146,94,163,174,131,101,93,36,36,227,210,63,157,85,204,105,94,189,186,164,232,0,112,
37,173,64,179,251,221,195,41,115,206,11,33,7,229,140,49,46,34,145,8,194,129,48,4,73,132,198,168,133,214,160,85,44,225,107,104,53,165,76,197,171,7,2,212,119,224,104,244,18,52,70,45,194,190,16,228,88,139,
77,0,52,70,45,36,67,180,225,36,203,209,122,20,53,34,36,163,22,226,250,247,119,114,253,213,83,7,128,161,217,8,67,179,49,123,34,1,144,116,26,72,122,13,52,70,45,228,80,250,123,81,210,75,16,68,17,146,94,82,
220,127,245,252,93,157,79,80,84,99,155,9,103,254,247,198,156,118,215,180,51,37,205,210,217,5,197,235,206,155,122,208,119,207,206,248,189,184,149,152,58,44,184,233,83,199,85,165,141,198,21,187,136,181,
145,229,248,182,165,115,236,0,216,170,114,118,0,248,67,90,156,158,221,136,252,218,108,118,100,73,77,106,8,130,128,206,155,123,20,29,0,254,213,141,225,98,201,35,39,12,205,166,138,53,254,41,183,136,44,227,
226,183,206,196,95,91,186,172,216,243,62,206,193,78,103,230,217,73,44,157,219,136,166,124,228,255,185,45,62,2,133,242,55,248,27,251,161,53,105,240,210,231,158,65,208,233,199,197,111,157,97,12,133,28,44,
221,202,167,157,33,119,106,240,214,192,154,242,233,146,181,175,97,75,54,254,11,33,104,68,180,31,233,86,116,0,248,87,55,234,51,18,137,68,159,68,197,210,11,66,73,26,255,106,53,239,109,197,174,52,35,144,
8,216,245,142,104,244,249,83,127,247,50,124,235,65,47,181,102,29,110,76,88,157,37,166,243,88,47,250,222,56,144,178,125,171,179,110,107,192,209,79,221,142,197,83,115,24,125,228,82,202,254,161,247,28,40,
120,69,151,173,192,212,158,244,253,156,244,123,88,14,202,8,216,55,190,79,68,141,136,237,247,236,100,64,59,21,52,38,13,182,223,179,83,209,1,160,54,184,45,213,159,250,26,103,84,67,36,157,242,203,74,177,
252,81,242,212,176,58,27,145,88,79,150,78,207,199,135,148,105,244,26,52,31,104,131,177,53,214,80,136,128,111,158,146,109,160,17,162,65,196,234,165,101,4,93,1,44,157,158,135,102,253,201,82,236,137,145,
206,166,71,227,238,102,216,250,248,35,73,21,65,68,251,209,46,132,125,97,44,159,91,128,223,238,199,194,171,51,48,182,155,96,101,29,166,145,252,153,76,157,139,43,203,202,39,119,162,166,206,134,141,150,153,
168,83,214,113,164,192,229,253,242,101,108,54,34,212,101,205,154,198,208,152,227,73,46,193,212,110,134,180,190,76,177,198,172,252,153,168,53,104,97,238,178,66,103,171,223,81,89,165,160,49,69,235,41,153,
164,227,119,73,86,57,190,158,147,71,85,72,122,137,141,255,60,36,47,127,43,215,217,170,64,164,30,59,0,136,138,112,253,137,209,248,191,181,22,45,6,238,31,74,216,203,198,127,178,246,35,93,104,63,210,133,
243,115,39,16,116,5,29,130,60,117,0,0,32,0,73,68,65,84,20,245,23,99,106,51,37,213,35,101,35,136,192,192,253,67,240,45,123,176,124,110,1,222,37,15,174,61,122,5,237,55,118,177,3,128,182,148,150,3,237,57,
159,174,38,206,187,166,40,207,172,11,190,213,141,41,47,173,195,237,138,253,43,23,54,2,54,234,26,244,56,240,91,55,110,90,217,106,77,200,19,132,99,124,13,0,208,243,186,190,248,118,115,183,13,250,70,222,
123,68,84,29,216,1,176,197,180,28,104,131,177,115,99,184,101,98,64,20,173,73,135,109,111,220,88,182,198,220,153,253,73,202,86,148,92,127,137,180,6,109,218,237,148,170,227,166,30,52,238,105,73,187,143,
79,232,50,227,231,151,40,179,169,167,39,96,31,89,201,154,166,101,184,157,83,0,146,204,189,54,131,133,87,103,114,39,4,235,47,23,207,130,27,87,190,119,62,101,251,206,7,246,196,227,60,17,17,85,90,229,59,
0,164,218,126,74,42,230,136,8,93,109,154,134,90,83,34,170,198,72,70,13,122,142,111,87,157,151,40,213,214,181,39,19,10,40,127,182,250,203,215,86,172,191,152,82,4,157,217,138,245,199,207,239,134,98,238,
191,205,192,250,173,109,124,255,138,179,213,234,47,236,15,99,225,181,25,248,86,210,47,255,103,31,89,65,200,19,68,203,112,187,170,233,19,66,173,255,54,174,242,97,249,91,237,254,36,74,86,241,14,0,99,139,
9,78,143,189,210,197,40,136,190,81,191,165,131,243,25,90,141,16,53,162,50,126,65,13,169,116,80,47,214,95,113,88,127,197,97,253,149,23,235,183,182,241,253,43,206,86,171,191,144,55,136,137,199,83,167,180,
197,44,157,91,192,210,185,5,152,187,213,197,79,48,213,248,231,111,99,105,201,234,140,133,180,213,238,79,162,100,21,111,189,118,223,150,186,254,114,173,232,189,115,71,238,68,117,76,212,74,232,186,181,54,
223,63,73,167,65,231,177,222,138,150,129,245,87,28,214,95,113,88,127,229,197,250,221,124,157,55,117,163,255,190,93,241,255,4,113,163,225,161,111,52,160,255,190,93,104,87,57,12,123,43,189,127,173,195,237,
138,122,211,154,163,43,179,244,223,51,24,223,150,111,93,108,165,250,75,100,104,54,162,255,190,93,104,61,16,29,229,214,56,216,130,254,251,118,193,210,107,203,43,159,214,27,58,107,54,102,64,235,193,206,
248,50,200,213,216,248,7,182,238,253,73,20,83,241,17,0,77,123,91,209,127,239,32,174,63,113,173,102,122,226,4,73,68,239,157,219,57,159,11,64,239,235,119,64,14,203,152,127,105,10,114,56,53,154,118,53,50,
182,154,176,243,215,246,192,208,84,249,185,230,172,191,226,176,254,138,195,250,43,47,214,239,230,74,158,30,51,241,239,163,128,28,173,119,173,69,135,206,91,122,242,202,111,171,188,127,182,254,70,69,240,
196,185,87,166,17,116,7,208,126,180,59,62,202,209,57,229,192,236,11,147,121,149,101,171,212,95,34,157,45,122,159,45,234,37,44,157,157,135,165,215,138,206,91,122,224,158,117,192,53,165,126,25,109,73,39,
97,207,251,15,97,228,7,23,224,158,113,22,84,150,77,39,68,3,253,110,191,103,176,210,37,81,101,43,222,159,68,49,21,239,0,0,162,235,201,182,28,104,135,99,204,174,88,31,184,26,137,6,17,182,190,6,232,108,134,
74,23,165,42,8,34,176,253,238,157,232,57,222,7,207,188,27,145,72,117,127,137,106,12,26,152,58,173,16,42,62,246,37,138,245,87,28,214,95,113,88,127,229,197,250,173,140,177,71,175,32,224,240,3,69,254,168,
231,251,87,28,214,95,113,140,45,70,28,248,248,141,240,44,184,17,116,5,42,93,156,156,140,173,166,154,90,30,146,247,39,109,101,85,209,1,0,0,90,179,14,45,195,109,149,46,6,21,72,99,210,194,182,131,75,142,
21,138,245,87,28,214,95,113,88,127,229,197,250,221,92,246,241,53,248,150,60,37,203,143,239,95,113,88,127,197,49,181,155,129,118,206,249,46,23,222,159,180,21,165,237,0,184,107,240,36,244,154,244,189,141,
59,91,178,47,21,243,134,193,215,224,11,166,239,1,188,190,214,142,115,115,91,123,222,60,17,17,17,149,207,208,123,14,32,18,14,227,236,87,79,32,18,142,78,45,244,204,185,112,230,203,175,160,113,87,51,250,
222,180,179,194,37,172,13,103,191,246,26,132,245,41,220,181,50,69,179,218,204,191,50,131,149,11,139,240,59,252,149,46,10,17,81,92,218,14,128,183,13,255,18,13,6,87,65,25,190,109,255,243,25,247,61,53,122,
136,29,0,68,68,68,84,54,198,150,245,249,177,9,241,199,228,144,12,207,130,27,70,62,73,85,205,187,232,174,116,17,106,94,208,29,64,208,93,253,195,247,137,104,107,169,154,41,0,68,68,68,68,133,186,252,221,
115,112,140,174,198,95,71,248,212,186,32,55,252,214,81,68,34,50,94,253,171,231,227,117,104,233,177,98,239,7,14,66,224,4,228,180,244,13,6,220,244,233,227,16,196,244,245,179,227,254,221,104,189,161,29,162,
134,63,187,137,168,242,248,77,68,68,68,68,53,79,14,202,8,7,194,105,247,9,162,0,73,175,129,164,227,207,158,92,162,145,255,69,104,141,26,200,161,104,96,52,201,200,186,203,74,128,162,126,4,141,8,141,81,27,
127,45,25,88,127,68,84,61,210,126,27,125,229,133,183,66,39,166,255,35,90,140,37,143,181,228,121,18,17,17,17,101,99,238,182,98,248,163,71,42,93,140,154,224,93,116,67,14,202,24,122,207,129,248,54,73,39,
85,176,68,213,47,18,150,225,153,119,67,210,75,48,180,152,208,58,220,142,214,225,246,148,116,190,101,15,194,254,48,76,29,102,8,18,71,83,16,81,101,164,237,0,184,56,191,125,179,203,65,68,68,68,84,48,99,179,
17,161,174,244,15,26,140,173,92,55,91,173,203,223,61,159,178,138,130,165,215,198,14,148,44,2,206,0,206,126,237,53,216,250,27,176,239,131,135,51,166,187,246,147,203,112,140,219,113,248,193,99,208,55,114,
57,105,34,170,140,130,199,35,249,237,94,140,61,122,53,254,90,223,104,192,142,183,236,46,73,161,136,136,136,136,242,209,255,230,93,0,0,251,200,42,194,129,144,98,159,198,164,77,119,8,37,112,78,218,17,116,
6,16,246,167,142,0,13,123,131,88,185,176,8,93,131,30,150,30,91,5,74,87,27,130,238,16,86,46,44,102,221,79,68,84,105,5,119,0,200,1,25,107,87,87,226,175,141,109,140,172,75,68,68,68,149,53,246,216,85,62,193,
46,192,212,211,19,176,143,172,164,221,231,93,246,226,202,247,206,163,101,184,29,187,222,190,111,147,75,86,59,188,139,110,92,249,222,249,74,23,131,136,40,43,70,36,33,34,34,162,154,183,114,113,17,254,85,
31,194,222,212,167,172,1,167,31,179,207,79,194,208,102,66,211,174,150,10,148,174,118,180,29,238,132,198,160,197,220,75,147,16,36,17,29,71,123,16,116,6,176,116,110,190,210,69,35,34,162,18,96,4,18,34,34,
34,170,121,243,175,205,98,226,241,209,180,235,174,7,236,126,76,60,62,138,165,211,108,196,230,210,125,123,31,182,223,179,19,16,69,72,122,13,182,223,179,19,29,199,122,42,93,44,34,34,42,17,142,0,32,34,34,
162,186,209,115,199,118,104,205,58,197,54,255,154,15,179,47,76,86,168,68,180,85,24,154,141,232,188,165,55,103,58,141,137,63,191,137,168,114,248,13,68,68,68,68,117,163,245,134,14,24,91,77,138,109,206,41,
7,59,0,168,236,116,54,29,58,111,225,104,9,34,170,110,236,0,32,34,34,34,162,20,33,95,8,151,255,233,44,66,62,70,175,207,70,107,209,97,232,189,195,208,152,116,185,19,19,17,85,24,99,0,16,17,17,17,81,138,72,
72,198,234,149,101,56,175,219,43,93,148,170,38,106,68,52,237,110,133,40,10,56,243,229,87,48,249,31,99,149,46,18,17,81,70,28,1,64,68,68,68,117,227,202,63,159,133,32,41,159,111,200,33,185,66,165,169,29,
3,247,239,70,56,16,130,161,209,144,178,207,212,97,193,224,111,236,129,198,192,159,141,217,132,3,97,120,22,220,48,119,91,42,93,20,34,162,140,248,77,78,68,68,68,117,195,187,236,173,116,17,106,146,62,77,
195,63,70,212,138,48,181,179,81,155,73,192,238,199,233,255,245,50,34,114,4,0,176,116,102,1,43,23,150,208,125,71,31,122,142,111,199,216,163,87,176,116,102,30,123,222,119,3,172,125,13,21,46,45,17,109,117,
236,0,32,34,34,162,154,55,244,238,97,68,100,25,231,190,250,90,74,39,128,165,199,138,189,31,56,8,65,224,204,199,92,194,190,16,34,114,4,135,126,239,22,0,209,6,173,160,97,189,101,19,137,68,16,14,132,33,136,
2,52,70,45,228,144,140,112,32,140,72,40,90,127,114,40,28,125,189,222,65,64,68,84,73,236,0,32,34,34,162,154,39,106,68,0,34,52,70,45,52,70,101,208,58,201,168,129,164,227,79,30,53,206,62,124,2,190,37,143,
98,155,165,215,134,225,143,30,169,80,137,106,135,181,207,134,125,31,60,140,197,83,115,24,125,228,82,165,139,67,68,148,22,255,26,18,17,17,81,221,24,248,213,33,200,193,212,57,255,238,25,39,52,70,45,244,
77,153,135,186,111,101,190,21,111,244,233,127,154,120,9,114,32,204,250,35,34,170,19,236,0,32,34,34,162,186,113,249,187,231,83,158,96,199,180,12,183,99,215,219,247,109,114,137,106,195,216,207,174,194,62,
178,146,118,159,103,193,141,179,95,123,141,245,71,68,84,7,216,1,64,68,68,68,53,207,57,105,71,208,25,64,216,31,174,116,81,106,90,195,96,19,36,173,6,171,151,150,0,73,64,211,174,22,132,188,65,56,198,215,
42,93,180,170,23,116,135,176,114,97,17,238,25,39,0,192,187,228,198,202,133,69,248,215,252,21,46,25,17,209,6,118,0,16,17,17,81,205,155,122,122,34,227,19,108,82,175,255,222,93,48,182,154,240,210,95,60,3,
141,65,131,221,239,218,15,231,148,3,231,31,62,81,233,162,85,61,239,162,27,87,190,119,62,254,122,249,220,34,150,207,45,86,176,68,68,68,169,216,1,64,68,68,68,117,163,237,112,39,52,6,109,218,125,230,46,46,
101,71,155,175,97,176,25,166,54,51,116,54,125,165,139,66,68,196,14,0,34,34,34,170,31,221,183,247,193,216,106,170,116,49,136,226,90,135,219,209,118,168,179,210,197,32,34,2,192,14,0,34,34,34,34,74,35,236,
15,97,252,103,87,17,116,7,42,93,148,170,166,49,105,208,127,223,174,140,251,45,189,182,77,44,13,17,81,118,236,0,32,34,34,34,162,20,114,80,198,220,203,211,149,46,70,85,187,252,79,103,161,181,232,48,240,
182,161,248,54,251,181,85,204,189,56,181,241,122,52,26,155,98,219,27,7,96,106,55,111,122,25,137,136,18,177,3,128,136,136,136,234,198,216,163,87,254,127,246,238,60,184,177,235,190,19,253,247,46,216,1,18,
36,64,112,223,215,238,102,239,173,150,186,37,219,178,45,89,114,44,217,74,162,68,142,172,56,78,141,19,165,42,126,25,207,139,223,203,44,53,83,121,149,76,82,227,120,166,60,21,39,83,86,148,87,142,227,81,44,
143,242,34,103,218,153,140,35,71,182,44,201,82,139,221,106,53,201,110,54,151,38,187,185,147,0,65,236,219,93,222,31,32,46,120,113,177,145,96,19,0,249,251,84,169,236,139,187,224,224,16,125,113,238,239,156,
243,59,224,244,92,214,125,182,78,59,90,30,108,223,231,18,85,135,246,135,187,208,116,190,37,235,60,117,163,211,140,206,79,244,64,111,163,57,236,153,188,147,30,24,236,234,122,137,251,99,240,78,122,52,199,
54,95,164,239,30,33,164,252,40,0,64,8,33,132,144,3,35,223,114,117,108,142,192,0,201,63,76,157,55,242,168,27,112,238,99,105,170,83,104,41,128,153,87,39,32,68,133,114,23,133,16,66,114,162,0,0,33,132,16,
66,8,81,57,241,252,89,200,178,12,0,96,121,10,156,20,67,140,139,8,175,133,202,93,12,66,8,201,139,2,0,132,16,66,8,33,4,0,48,250,205,43,136,122,194,0,0,157,85,143,83,191,115,127,153,75,84,125,156,199,27,
209,253,164,54,41,32,203,83,179,155,16,82,126,116,39,34,132,16,66,72,213,235,123,106,8,146,32,229,61,134,213,81,79,118,46,98,92,128,44,200,144,226,2,196,184,8,0,96,99,34,132,112,2,12,199,130,51,80,221,
229,34,75,12,132,112,2,98,44,57,244,159,225,0,78,79,77,108,66,72,101,162,187,19,33,132,16,66,170,222,244,171,19,240,77,111,228,61,198,49,236,66,255,211,71,247,169,68,213,101,242,123,55,52,245,151,8,197,
49,242,213,183,96,109,171,193,240,23,207,148,169,100,149,47,238,143,98,228,171,111,149,187,24,132,16,82,20,10,0,16,66,8,33,132,16,0,128,169,193,2,150,103,1,0,178,36,35,188,26,44,115,137,42,155,165,217,
6,89,148,84,115,255,133,176,128,208,82,64,115,172,209,105,206,185,66,5,33,132,236,23,10,0,16,66,8,33,132,16,0,192,192,51,199,96,114,154,1,0,241,96,28,87,191,246,118,153,75,84,217,142,63,127,22,177,205,
40,222,255,250,59,202,107,222,73,79,214,101,0,143,126,225,20,106,186,236,251,89,60,66,8,209,160,0,0,33,132,16,66,170,94,77,71,45,184,28,115,252,133,72,34,239,242,128,132,148,130,213,113,168,63,210,128,
68,56,129,192,29,250,158,17,66,42,27,5,0,8,33,132,16,82,245,90,63,220,153,115,95,96,193,143,241,23,175,238,99,105,200,97,162,179,232,48,240,204,49,248,231,54,113,227,91,215,202,93,28,66,8,201,139,2,0,
132,16,66,8,33,4,0,176,126,109,25,58,179,30,0,148,213,0,226,129,24,150,223,158,87,142,177,182,217,96,235,160,161,236,153,244,53,6,52,95,104,207,187,159,16,66,202,141,2,0,132,16,66,8,33,4,0,176,244,230,
188,230,181,184,47,134,59,63,156,81,182,91,30,234,160,0,64,22,198,122,19,58,31,235,45,119,49,8,33,36,47,10,0,16,66,8,33,164,234,173,142,44,34,178,22,206,186,47,17,138,239,115,105,8,33,132,144,202,68,1,
0,66,8,33,132,84,189,141,9,143,102,29,123,66,8,33,132,168,81,0,128,16,66,8,33,7,154,209,105,70,231,39,122,160,183,209,28,236,92,218,31,238,66,211,249,150,162,142,53,214,155,239,113,105,8,33,132,220,43,
20,0,32,132,16,66,200,129,198,27,121,212,13,56,203,93,140,138,102,109,171,41,119,17,8,33,132,236,3,10,0,16,66,8,33,164,234,245,60,49,0,49,46,100,221,199,242,220,62,151,134,16,66,8,169,76,20,0,32,132,16,
66,72,213,51,216,141,57,247,5,23,3,120,239,143,126,138,250,163,13,232,125,106,104,31,75,69,8,33,132,84,22,182,220,5,32,132,16,66,8,185,151,100,89,134,24,23,33,9,82,185,139,66,8,33,132,148,21,5,0,8,33,
132,16,66,8,33,132,144,67,128,166,0,16,66,8,33,228,192,136,172,135,32,37,212,61,253,81,119,4,0,32,68,19,8,45,5,160,183,233,161,163,21,1,8,33,132,28,66,20,0,32,132,16,66,200,129,113,235,229,113,68,221,
225,172,251,124,211,94,140,78,95,65,203,67,29,232,120,164,103,159,75,70,8,33,132,148,31,5,0,8,33,132,16,82,245,2,243,62,36,2,113,136,49,177,220,69,33,132,16,66,42,22,5,0,8,33,132,16,82,245,22,126,114,
7,190,233,141,114,23,131,16,66,8,169,104,251,22,0,8,173,132,176,252,230,221,130,199,117,63,57,0,206,64,235,245,18,66,8,169,126,129,121,63,164,2,61,210,250,58,35,76,14,211,62,149,232,224,107,56,221,4,222,
168,83,189,150,8,196,225,30,91,133,209,105,70,93,191,3,53,157,246,50,149,142,84,179,152,55,138,133,159,204,42,219,246,62,39,28,195,13,202,246,202,207,22,16,90,13,40,219,61,79,14,130,225,40,223,54,33,164,
178,236,91,0,32,17,140,194,61,182,90,240,184,206,199,123,41,0,64,8,169,24,113,127,20,11,111,220,41,250,248,174,199,250,193,234,168,193,71,146,110,127,127,2,145,28,243,209,83,90,30,106,71,199,35,189,251,
84,162,131,175,229,193,14,152,156,102,213,107,129,5,63,220,99,171,176,52,89,209,249,24,213,53,217,157,68,56,142,245,107,233,182,172,206,162,87,5,0,54,103,188,216,156,246,40,219,221,159,26,4,67,77,218,
3,193,123,203,141,152,63,150,247,24,147,195,140,218,158,58,0,128,127,110,19,225,245,144,178,207,121,162,17,188,65,253,216,21,15,198,177,113,115,93,217,182,54,219,96,109,171,217,195,82,19,146,93,217,166,
0,52,158,107,133,243,100,163,178,125,251,239,39,16,89,15,99,226,165,81,112,122,14,71,191,112,170,164,235,7,22,252,184,251,143,211,233,247,59,223,10,231,137,198,60,103,228,54,255,250,44,252,51,94,101,123,
232,115,39,192,153,104,246,4,33,135,65,34,148,192,218,200,114,209,199,119,62,218,119,15,75,67,170,25,203,179,170,223,189,152,55,10,223,109,47,66,43,33,172,141,44,195,214,85,171,121,112,221,111,107,239,
47,3,91,3,22,116,86,29,234,134,156,101,45,15,33,7,65,196,29,198,236,165,91,202,182,115,184,17,174,115,45,0,128,187,175,221,70,112,193,167,236,59,242,220,73,48,124,229,4,145,87,222,89,192,198,68,250,33,
181,247,169,163,48,216,15,223,10,26,43,239,46,194,119,219,155,247,24,231,113,151,18,0,112,95,95,195,218,213,37,101,95,109,79,189,38,0,16,243,70,48,247,131,41,101,187,245,67,157,20,0,32,251,162,108,79,
177,6,187,1,182,246,244,151,156,211,39,139,18,90,10,128,221,131,27,159,24,77,32,176,224,87,182,75,105,196,68,61,97,213,181,36,81,2,5,116,9,57,156,234,143,52,160,241,108,115,206,253,172,174,242,239,14,
11,63,158,67,96,91,131,19,0,56,189,14,3,191,124,180,76,37,58,28,56,3,143,158,39,7,149,109,207,216,26,124,183,189,240,77,111,192,55,189,129,238,39,250,203,30,0,152,251,193,20,36,33,185,132,158,181,181,
134,2,0,132,236,1,49,38,192,63,151,190,231,90,91,211,237,223,240,74,72,181,79,150,1,102,95,75,151,95,196,29,81,149,79,74,80,146,77,0,201,85,68,152,228,95,42,182,25,193,234,123,75,8,45,7,113,231,159,102,
80,219,93,87,230,210,17,146,95,9,1,128,204,219,147,92,82,65,114,241,207,110,98,250,111,111,228,220,63,244,185,19,48,55,91,33,37,36,92,251,175,239,40,175,75,162,186,60,139,111,220,197,202,59,11,5,207,203,
212,250,145,174,221,23,62,15,57,163,186,152,109,213,201,112,234,186,77,53,198,8,33,229,167,183,27,80,219,87,95,238,98,148,36,180,20,132,111,90,221,147,113,88,70,53,137,25,235,195,179,89,231,231,238,207,
239,91,62,43,239,44,32,17,76,100,221,103,106,178,192,57,236,2,0,108,76,120,16,218,22,160,206,70,111,215,163,241,92,43,146,159,99,31,30,45,50,171,107,251,239,27,24,48,28,11,89,148,182,14,149,33,37,164,
61,153,54,211,254,112,23,154,206,183,64,95,163,237,157,52,59,205,24,124,118,24,122,219,225,235,185,36,229,103,105,178,226,244,151,31,80,182,51,123,130,119,98,254,159,103,225,190,190,82,240,253,6,62,123,
188,232,243,120,179,30,199,127,243,44,0,192,59,229,193,220,15,38,149,125,66,88,253,192,127,243,219,215,148,118,106,190,243,50,29,249,252,41,24,235,243,231,58,201,12,46,84,210,72,136,76,77,23,218,193,110,
213,67,96,222,135,213,247,150,16,113,135,17,113,135,193,178,149,91,110,66,128,18,2,0,124,70,99,49,238,139,65,136,9,69,223,212,100,89,86,26,0,91,175,0,0,88,142,81,61,0,203,162,4,33,162,109,4,201,82,242,
26,162,32,38,175,195,64,117,92,230,3,182,36,8,144,197,244,117,37,73,134,36,202,144,37,25,241,96,92,121,239,76,82,92,27,233,148,165,204,178,3,96,24,48,108,241,13,171,240,74,80,181,205,155,211,245,102,168,
53,38,27,76,114,234,216,0,2,243,126,213,136,9,66,72,229,18,98,2,198,94,184,90,240,184,238,39,250,85,61,5,163,223,188,2,113,235,158,99,114,153,49,248,204,176,178,111,253,218,10,22,127,122,183,168,115,51,
53,156,110,66,235,67,29,202,118,207,147,253,16,99,61,152,248,155,49,68,61,249,231,167,103,190,111,166,19,191,117,86,25,245,16,89,15,227,214,119,199,242,94,15,0,134,158,29,134,209,161,238,233,46,116,110,
230,231,221,13,73,148,177,122,121,81,245,154,193,110,212,28,199,155,213,9,228,194,235,33,72,162,156,245,55,226,94,89,29,89,202,153,59,192,49,220,160,4,0,124,211,30,172,142,44,101,61,46,197,218,90,179,
21,0,216,159,242,7,151,2,170,237,237,191,111,96,146,117,174,124,239,100,96,249,157,121,180,126,168,179,228,247,205,55,116,150,51,242,168,27,160,209,12,164,60,24,142,205,122,175,217,13,33,44,32,182,153,
127,46,186,206,162,223,209,121,210,182,192,168,20,147,242,94,63,30,136,239,234,60,89,44,28,72,93,122,115,94,181,109,204,168,51,78,207,169,218,199,66,84,132,148,16,171,98,228,93,37,136,251,163,170,109,
174,132,64,20,169,110,187,254,203,235,172,122,24,234,140,136,121,147,95,38,49,46,226,214,95,95,71,243,197,118,112,198,244,101,121,19,15,75,179,77,115,254,252,143,102,49,255,163,89,205,235,167,255,213,
5,232,172,233,27,87,109,95,61,206,255,251,143,104,142,155,122,101,28,158,177,117,140,255,229,251,0,128,179,95,185,168,58,110,115,218,131,137,239,140,42,219,237,31,235,65,203,182,6,48,0,92,249,147,183,
145,8,37,111,100,38,167,25,39,191,116,62,235,103,157,122,101,92,181,125,245,191,252,76,115,140,189,175,30,67,207,157,80,182,99,254,40,162,238,72,214,235,69,214,195,152,127,93,253,217,109,109,181,202,255,
215,89,245,176,182,216,16,92,76,54,162,100,9,184,249,173,247,97,105,171,221,215,6,40,33,135,153,209,97,70,247,167,250,139,62,126,254,245,57,68,215,66,232,127,230,24,32,201,5,31,172,1,109,128,49,234,137,
64,140,11,0,0,86,175,238,65,16,34,9,213,53,243,157,155,41,117,159,75,209,217,12,208,217,114,245,126,171,101,190,111,38,121,91,44,84,18,196,226,62,119,150,81,77,133,206,205,252,188,179,151,166,16,221,40,
252,94,219,69,189,17,229,55,43,165,110,200,161,57,206,210,104,5,203,179,74,57,99,222,40,38,191,59,138,198,179,45,96,245,197,53,52,173,109,53,201,198,234,54,98,76,192,244,43,55,149,237,152,47,89,150,186,
1,39,28,199,93,176,182,218,176,244,230,60,194,43,65,196,3,201,134,116,239,83,71,148,160,120,108,35,130,249,215,103,17,152,247,99,250,149,155,176,103,41,123,231,163,189,208,109,245,128,139,49,1,179,151,
38,17,245,134,49,253,202,77,88,219,107,208,116,127,43,0,96,253,253,21,248,102,180,243,89,101,73,251,183,17,227,34,130,5,70,25,0,0,36,32,176,224,211,52,226,183,255,190,1,64,221,160,3,203,111,167,255,118,
243,63,154,133,251,131,213,172,61,247,197,48,187,172,154,78,9,0,8,46,5,193,114,50,204,141,218,54,136,16,78,168,18,116,17,146,143,201,97,65,215,167,118,158,223,37,17,138,227,253,175,107,71,153,182,60,216,
142,142,71,179,39,163,188,252,31,223,208,188,230,56,214,128,254,95,58,150,245,248,147,191,125,30,166,6,179,242,126,87,254,228,109,4,23,3,120,231,247,127,172,58,175,251,137,126,116,63,161,253,77,187,252,
135,111,32,17,74,224,157,223,255,49,172,173,54,12,255,198,89,56,134,31,86,246,207,94,154,194,234,72,58,112,186,253,253,0,32,184,232,199,216,95,164,3,222,153,159,109,226,59,163,216,156,246,224,131,63,187,
12,0,56,255,239,62,12,86,199,98,226,111,70,33,111,11,32,196,252,49,68,51,130,158,245,71,26,84,219,172,142,133,169,222,132,136,39,217,190,150,69,9,51,223,159,64,199,35,125,224,239,81,2,113,206,192,1,59,
232,224,219,11,114,66,218,243,209,191,241,96,12,179,151,166,84,175,153,92,150,61,125,15,82,61,74,10,253,52,158,109,197,221,215,102,148,237,192,130,31,129,239,169,31,150,237,125,14,12,61,119,60,243,84,
240,102,29,116,89,126,176,51,123,209,165,132,164,137,88,1,128,152,99,89,37,89,2,152,60,109,218,66,251,129,244,244,1,134,5,24,70,251,143,222,88,103,82,174,33,137,201,136,167,152,144,16,245,132,193,25,121,
232,44,122,108,78,110,96,246,82,238,161,80,219,49,28,139,134,51,234,57,197,237,31,237,198,205,255,126,93,137,114,74,162,140,192,157,205,162,174,71,8,41,157,16,201,254,48,189,250,238,2,86,47,167,123,92,
7,62,123,12,117,253,14,132,87,130,8,220,245,101,61,167,126,200,129,254,167,211,141,183,185,255,61,141,213,247,150,48,249,242,56,192,48,56,254,252,89,152,119,249,67,60,250,194,21,132,87,67,144,69,9,156,
137,199,185,223,189,168,236,219,152,240,96,234,149,113,165,204,93,143,247,161,241,190,150,162,174,187,49,225,193,212,255,24,87,158,240,187,30,83,159,59,250,194,21,132,215,66,24,249,234,91,208,153,120,
156,249,202,69,205,53,154,239,111,67,199,163,61,202,246,228,203,227,240,78,121,48,246,194,21,200,96,112,238,247,46,2,34,48,242,181,183,193,108,221,236,138,173,171,192,188,15,225,213,160,230,61,119,162,
174,223,129,186,65,109,175,48,171,99,209,112,170,89,213,232,221,156,218,192,230,84,241,107,204,159,252,210,121,205,124,126,73,144,178,174,134,99,114,153,224,60,158,236,209,247,207,121,177,185,109,45,123,
199,112,131,146,23,39,184,224,199,252,235,179,136,251,98,112,251,86,161,183,107,123,249,236,131,14,229,125,19,193,56,102,47,77,66,8,11,112,143,173,66,134,164,4,0,130,139,254,162,86,230,1,128,200,122,8,
55,191,253,65,81,199,102,50,216,141,112,28,87,55,226,91,46,182,99,253,253,21,213,168,189,212,208,217,221,40,148,152,203,115,195,189,171,235,18,146,146,171,205,89,8,195,38,115,94,201,66,122,180,105,33,
250,90,131,50,45,52,117,158,20,151,16,219,140,22,28,101,203,48,140,42,65,159,206,156,190,71,8,145,196,174,63,199,189,224,191,237,85,141,32,200,100,172,55,161,229,67,29,154,215,157,39,154,84,157,104,158,
177,117,120,198,214,53,199,237,149,35,159,63,169,36,246,219,110,252,47,211,65,143,84,128,218,222,87,143,182,143,118,195,80,163,199,252,235,217,87,15,26,127,241,42,56,19,143,161,207,157,200,186,31,0,150,
222,153,207,218,73,186,215,26,207,22,215,30,32,7,79,73,1,128,230,7,90,225,157,88,87,37,200,43,86,203,197,118,77,143,124,54,254,59,94,85,79,126,33,183,255,126,2,189,79,13,229,220,63,255,207,183,209,124,
161,45,235,240,40,32,217,8,249,224,27,201,40,101,255,211,199,84,203,187,164,28,251,23,167,149,81,10,169,227,3,119,54,113,237,79,47,163,241,92,11,186,159,24,40,186,188,0,208,254,177,110,205,188,168,218,
190,122,180,127,188,59,121,3,216,255,233,167,132,144,28,24,142,83,245,52,176,133,34,138,0,100,134,81,205,101,76,5,58,101,73,6,32,107,231,44,237,128,44,108,155,146,36,3,137,104,58,112,33,38,132,173,247,
1,0,9,82,150,222,221,220,23,150,84,83,157,100,54,115,62,230,214,103,16,37,136,153,83,162,114,157,179,213,170,77,6,89,101,64,102,32,35,249,62,169,26,144,4,245,103,72,13,27,221,139,186,218,206,232,52,163,
251,211,131,57,247,119,124,188,27,254,217,13,165,167,105,47,112,38,30,67,207,166,27,125,254,219,94,204,191,158,236,253,14,204,249,208,242,160,246,55,241,198,183,174,41,3,247,197,120,233,61,66,238,235,
171,88,189,188,136,232,102,50,176,222,249,88,47,172,219,122,232,111,124,235,154,118,138,219,110,49,64,239,103,134,148,36,191,41,58,171,30,3,207,28,195,173,151,198,114,142,90,33,228,32,224,77,122,156,254,
242,5,77,47,121,62,167,190,116,191,146,19,35,117,158,119,202,3,239,215,61,104,121,176,61,255,251,153,117,56,253,229,11,89,247,205,255,104,78,21,212,204,39,184,24,64,104,217,191,53,117,40,187,153,87,243,
183,183,75,193,27,120,244,254,194,17,205,40,42,0,104,186,208,6,247,232,234,174,3,134,123,37,148,49,213,9,72,142,122,182,182,106,71,28,109,23,92,10,64,103,209,229,61,102,63,52,156,106,132,189,191,186,243,
25,145,221,43,41,0,192,240,44,6,127,245,4,102,254,110,2,222,137,221,69,216,133,112,2,137,109,61,109,44,199,194,96,55,64,74,136,8,220,241,35,180,156,236,225,209,215,24,96,222,54,228,40,180,26,66,162,200,
104,234,118,214,86,91,222,100,67,156,145,135,235,92,178,55,222,88,191,55,243,181,114,190,151,137,71,247,227,253,170,101,161,182,107,125,168,19,102,151,21,243,175,205,34,188,86,90,79,23,33,100,111,184,
206,53,163,235,177,202,92,234,79,140,10,184,250,181,183,203,93,140,146,108,78,123,238,233,103,96,121,22,141,247,181,162,253,227,221,121,87,156,225,76,60,142,124,225,52,166,94,185,177,103,163,175,88,150,
85,229,114,137,111,77,1,136,7,226,201,255,66,218,249,179,69,13,189,223,129,184,63,166,10,218,155,26,204,170,50,49,204,222,196,156,13,118,3,122,62,61,132,154,110,123,214,253,53,93,118,28,127,254,12,238,
190,54,11,239,164,103,239,130,14,132,220,67,156,129,71,77,87,45,18,161,4,34,235,97,196,125,49,248,231,210,247,7,33,154,28,213,146,106,107,102,25,68,122,207,196,3,113,213,60,123,222,192,129,51,241,136,
251,163,136,110,68,145,8,38,239,55,102,151,21,188,57,253,96,29,184,227,135,188,139,192,170,173,163,182,240,65,59,196,112,44,234,6,157,232,120,68,219,49,150,194,233,57,12,61,119,2,183,94,26,69,120,173,
124,211,120,206,124,229,162,102,148,48,171,203,253,7,31,123,241,10,24,134,129,44,201,72,4,19,24,249,234,91,91,129,237,253,87,219,87,143,174,79,238,172,179,146,28,44,37,103,127,224,13,60,6,63,59,140,192,
188,15,27,55,220,136,122,34,144,132,244,16,35,75,75,254,72,216,198,77,55,60,227,107,202,182,161,214,128,158,207,12,33,230,139,225,230,119,210,67,14,235,6,28,170,158,245,84,14,128,76,219,231,37,101,147,
57,159,40,147,222,170,71,207,19,185,123,133,138,165,175,49,100,29,50,4,36,35,180,150,38,27,156,167,26,161,183,102,31,137,144,82,55,224,64,221,128,35,57,119,117,51,74,163,1,8,217,39,217,122,30,242,233,
254,100,47,196,120,105,255,64,173,109,54,8,81,1,161,165,0,164,184,164,122,80,139,111,37,87,50,216,141,208,91,245,224,77,218,30,4,134,101,96,205,115,207,213,91,247,55,3,186,16,136,171,62,67,170,113,108,
110,180,130,211,177,96,88,70,149,67,0,0,120,147,14,38,71,238,76,209,169,100,79,221,79,12,236,120,57,42,86,207,37,231,247,23,153,113,94,111,211,227,216,175,159,194,230,140,23,190,73,15,162,222,168,234,
247,45,239,123,237,81,82,170,83,255,242,126,176,124,246,107,113,6,22,119,127,120,123,79,222,39,31,206,200,229,252,61,83,97,1,157,37,185,196,175,243,120,99,114,238,108,30,70,135,25,3,207,28,131,24,75,230,
127,16,162,52,26,128,84,166,212,239,129,201,105,198,209,47,156,134,103,108,29,83,175,140,195,61,182,6,247,216,154,230,248,222,167,142,20,108,143,238,181,216,102,68,53,164,94,95,107,128,201,196,195,125,
125,93,53,93,183,227,209,30,85,207,239,229,63,124,3,178,160,254,237,50,58,205,208,217,242,183,79,93,103,114,47,135,91,140,193,207,157,0,182,61,0,243,38,30,70,135,73,51,98,40,27,131,221,136,227,207,159,
197,218,213,21,184,71,215,16,219,8,231,28,137,86,170,92,185,114,120,147,110,71,121,185,196,173,206,78,86,199,2,114,178,3,52,23,142,103,247,124,101,30,150,231,96,109,178,194,121,170,9,142,163,13,149,181,
214,36,217,119,123,246,237,178,181,215,194,214,190,243,104,160,235,108,51,92,89,214,212,230,140,60,92,103,155,17,247,197,176,57,189,129,136,59,132,181,145,101,101,127,116,67,155,23,0,128,50,132,210,80,
107,132,235,108,51,34,235,97,4,238,250,16,92,12,168,206,175,59,226,132,243,100,35,196,136,128,181,247,151,33,70,5,213,254,20,75,158,172,194,249,164,30,220,247,138,177,206,4,99,93,254,229,83,8,33,229,163,
183,151,254,239,243,200,231,79,66,136,36,48,242,159,222,66,212,19,198,248,139,218,33,163,77,23,218,208,124,127,91,214,243,89,3,135,99,95,60,83,114,57,246,74,174,198,113,223,47,12,193,220,104,5,0,205,3,
181,173,171,86,181,250,65,46,251,185,42,138,189,183,14,246,222,189,89,215,89,53,173,98,171,237,203,48,76,50,231,12,88,48,44,11,150,99,148,92,52,58,179,30,44,159,209,82,99,216,130,185,108,114,97,24,6,44,
199,40,43,233,100,93,213,38,131,201,97,193,145,207,159,220,221,27,22,129,51,112,5,59,11,8,169,36,134,58,35,26,78,53,34,188,22,86,13,5,175,237,169,131,190,70,175,36,195,150,18,18,60,227,107,154,228,163,
225,213,48,214,175,173,192,150,165,141,233,254,96,21,204,214,191,249,212,121,6,187,17,53,93,181,176,52,215,168,70,28,108,151,171,13,110,110,50,163,225,84,35,2,11,1,68,221,97,108,222,222,80,37,134,205,
214,249,207,27,210,83,221,108,237,53,144,4,1,155,51,155,72,4,98,216,152,88,135,126,49,25,76,102,121,22,214,214,26,52,156,106,68,108,51,10,255,156,79,249,108,41,169,132,166,117,67,78,240,70,78,185,119,
213,118,101,31,29,84,44,134,99,209,120,95,75,209,121,109,42,197,185,127,253,33,136,225,56,174,252,103,109,66,241,148,166,11,237,104,186,144,127,186,7,33,165,168,216,245,31,244,86,61,122,158,28,196,230,
180,7,155,211,27,240,207,249,224,159,203,158,96,43,27,83,131,5,61,79,14,98,117,100,17,129,187,62,108,220,92,199,198,205,244,136,129,225,38,11,58,63,209,11,73,144,176,246,254,50,226,193,56,110,95,186,165,
185,78,199,35,61,154,215,8,33,135,87,212,29,206,155,60,205,113,212,85,210,245,89,158,133,115,216,133,68,84,128,111,91,50,56,163,211,12,107,147,21,230,140,229,243,236,3,245,48,187,204,240,220,88,135,44,
200,89,203,102,118,88,96,110,182,42,219,129,187,155,136,249,99,16,98,219,150,78,221,58,87,103,212,161,182,175,30,250,26,35,156,195,46,132,61,97,132,151,131,8,47,7,84,215,78,157,91,127,212,5,222,152,253,
167,36,85,230,76,188,49,61,122,33,243,243,38,252,177,172,159,161,182,211,14,93,149,175,225,158,8,197,241,238,31,104,66,20,106,195,0,0,32,0,73,68,65,84,51,124,55,63,216,134,142,71,146,89,179,83,83,208,
62,248,198,101,68,220,97,188,247,199,63,213,28,239,24,110,80,37,74,220,137,230,7,219,209,252,96,59,102,47,77,98,117,100,9,183,94,42,188,108,35,33,68,205,218,106,131,181,245,8,150,222,156,87,5,0,154,47,
180,171,122,215,197,184,128,153,87,39,52,231,39,219,182,30,116,127,74,59,12,59,91,91,212,218,106,67,239,83,71,0,32,103,0,32,23,123,159,3,246,62,71,114,229,20,119,24,43,63,91,216,209,249,206,147,141,112,
158,108,76,102,243,15,196,84,201,233,116,22,29,206,254,95,15,162,247,169,35,240,140,173,195,63,231,83,62,91,166,142,143,247,236,251,168,136,74,98,172,55,129,225,152,228,180,16,150,129,169,193,12,73,144,
52,193,33,66,246,195,190,5,0,140,14,51,218,63,222,173,108,219,138,140,252,101,158,151,75,174,181,44,173,173,53,89,207,215,215,38,231,247,51,44,147,247,250,182,46,59,76,78,179,210,91,149,249,94,58,179,
78,117,190,53,203,146,135,132,144,131,163,80,54,248,186,127,83,218,90,227,172,142,67,223,211,71,17,90,14,96,116,91,0,192,222,95,159,53,247,64,42,72,233,253,163,55,33,198,213,203,204,165,52,93,104,67,87,
115,250,220,165,55,23,224,157,84,231,109,145,18,34,166,95,185,9,115,179,21,39,250,234,97,109,181,161,239,233,163,88,254,217,60,238,44,7,177,126,109,21,235,215,180,15,230,189,159,25,204,57,212,59,87,153,
243,125,222,224,98,32,235,103,24,252,149,97,212,13,86,95,0,192,96,55,22,76,92,168,51,105,135,218,230,59,79,183,109,42,135,206,170,87,77,153,96,182,13,73,101,88,70,181,47,223,121,217,164,126,39,9,33,217,
217,58,107,208,246,112,151,178,109,200,152,183,206,233,57,213,254,76,150,22,27,56,35,7,107,91,254,182,163,169,33,189,74,140,125,176,30,58,107,58,136,202,155,139,75,40,151,121,94,54,250,60,65,86,231,73,
151,166,156,219,167,58,153,27,205,121,63,107,177,229,60,168,6,63,119,66,185,231,234,44,122,156,252,237,243,8,204,251,148,229,204,9,217,79,204,83,95,191,118,79,103,149,51,216,229,180,117,153,1,152,221,
156,185,235,119,36,132,144,109,146,247,18,89,148,149,100,109,197,48,108,77,213,137,121,211,217,227,89,61,167,172,28,2,0,190,153,13,248,103,211,189,56,141,15,180,105,242,129,196,3,113,172,190,155,238,169,
177,117,218,243,102,236,93,248,241,28,228,28,235,6,103,158,235,254,96,21,145,173,53,208,13,181,70,24,93,22,240,38,30,28,207,130,225,89,213,122,236,98,84,200,59,87,209,80,103,82,230,18,102,174,23,111,168,
53,194,232,48,229,191,45,111,237,43,84,207,58,155,126,207,230,213,87,52,25,52,55,147,16,178,103,24,134,217,85,146,191,180,195,125,83,98,192,64,134,140,152,55,10,49,150,206,83,98,222,26,221,166,173,223,
228,143,90,220,31,83,253,118,154,26,44,201,0,45,195,128,145,101,200,72,78,17,137,122,210,171,25,232,172,250,100,91,129,97,246,108,197,27,66,178,185,231,1,128,164,220,55,143,234,253,142,51,201,101,178,
88,22,76,117,126,0,66,8,33,247,136,12,25,12,216,100,32,187,26,127,34,100,25,251,154,194,156,16,146,198,48,0,36,64,98,170,242,217,91,102,0,182,74,111,125,132,28,6,5,167,0,52,218,188,248,15,159,248,171,
93,93,124,45,80,135,255,231,135,191,134,124,119,175,212,179,179,239,182,23,190,153,13,8,177,202,206,2,204,234,56,212,116,214,161,110,176,62,153,184,137,30,254,33,68,18,88,189,178,140,208,98,64,21,29,173,
56,44,3,189,77,143,250,163,13,168,235,223,187,4,141,165,162,250,43,77,85,215,95,209,3,150,228,109,129,82,70,243,92,150,173,119,39,115,121,162,92,170,186,254,42,24,179,245,199,21,194,85,90,191,244,240,
15,128,254,125,148,138,234,111,151,228,100,199,89,96,209,15,247,181,85,196,124,17,213,18,127,149,134,213,113,48,55,88,208,120,95,11,244,181,134,170,137,123,210,247,147,28,86,5,71,0,52,219,60,248,227,79,
253,197,174,46,190,28,112,224,223,252,224,55,242,30,35,75,192,204,223,221,128,123,84,155,41,186,146,213,246,212,97,240,217,227,121,215,145,62,12,34,158,8,110,124,235,26,18,1,237,250,213,149,204,117,174,
121,79,150,123,44,21,213,95,105,168,254,74,67,245,119,111,81,253,86,55,250,251,149,134,234,175,52,203,63,155,199,157,31,206,84,199,147,244,22,78,207,99,240,217,97,212,148,152,225,127,63,208,247,147,28,
102,101,95,5,96,229,221,249,170,123,248,7,146,35,22,230,127,52,139,206,199,122,203,93,148,146,204,94,154,130,184,181,54,55,111,211,23,76,216,149,233,246,171,55,171,238,230,9,0,107,35,203,168,237,174,135,
227,88,195,142,206,91,185,188,136,224,221,236,171,81,80,253,21,111,225,245,57,213,188,183,237,76,77,22,180,62,212,89,212,117,14,91,253,229,251,254,165,80,253,85,14,170,223,253,181,113,115,189,96,70,109,
99,131,185,232,30,180,195,250,247,91,127,127,5,66,36,129,166,7,218,149,37,219,226,193,56,60,215,211,73,64,173,109,54,216,58,242,63,228,29,166,250,19,99,34,214,174,44,237,248,189,154,47,102,95,234,45,188,
26,196,221,31,222,174,170,135,127,32,185,234,193,244,223,222,192,169,223,121,32,185,222,125,5,59,76,223,79,66,50,101,13,0,180,219,215,192,49,201,100,82,14,171,186,177,25,136,153,225,9,231,94,127,185,189,
118,13,28,155,60,87,207,37,208,85,151,94,11,52,219,185,217,178,74,87,139,245,107,43,85,31,0,240,78,172,35,30,76,174,7,107,114,152,128,29,60,192,198,253,81,4,230,253,133,15,172,80,158,177,181,29,223,64,
131,119,253,89,215,53,7,168,254,118,194,55,179,129,192,66,246,207,110,143,212,1,69,60,192,30,198,250,203,247,253,75,161,250,171,12,84,191,251,111,245,202,178,106,233,204,108,28,195,174,34,2,0,201,4,94,
135,245,239,183,248,214,93,68,221,97,52,222,215,10,134,77,62,196,197,54,163,201,222,232,45,45,15,117,228,13,0,28,182,239,191,16,73,168,234,167,88,185,2,0,158,177,245,18,19,247,149,79,60,16,71,224,142,
15,181,125,117,229,46,74,78,135,237,251,73,72,166,172,1,128,223,253,200,203,176,155,66,89,79,24,153,31,192,95,141,60,158,243,130,95,255,204,159,42,231,58,204,126,252,254,99,223,82,246,189,62,125,74,115,
110,204,95,189,235,95,10,145,4,196,184,0,78,95,246,129,20,59,118,251,210,45,68,86,66,16,34,233,12,165,49,95,12,227,47,94,133,181,173,6,157,143,23,126,144,141,7,226,247,178,136,247,220,94,68,126,7,159,
29,6,111,228,49,254,255,94,163,250,43,194,194,235,115,240,205,108,32,188,150,188,71,12,62,59,12,222,156,204,126,31,223,140,97,234,149,113,4,23,2,24,127,241,42,234,134,156,104,121,168,35,231,181,14,99,
253,101,162,250,171,92,84,191,149,41,188,28,192,220,63,76,161,182,183,14,117,131,185,150,236,100,14,229,223,111,117,100,17,145,181,48,18,161,244,103,23,227,2,230,95,155,85,189,6,36,71,65,206,253,195,20,
28,199,93,176,181,215,106,174,117,24,235,111,79,223,63,84,221,245,23,15,86,246,253,131,190,159,228,176,43,251,147,43,147,125,213,170,170,81,165,1,90,68,86,66,154,30,88,73,144,16,88,240,231,92,211,91,163,
74,63,123,202,94,20,223,210,92,3,157,57,249,207,136,234,175,176,168,39,162,250,222,89,154,107,160,183,37,31,96,163,166,228,148,0,33,38,32,176,224,135,169,209,146,245,26,37,21,160,130,236,213,247,143,234,
175,66,85,124,1,243,171,242,226,231,20,241,68,16,241,44,130,213,115,121,2,0,168,250,10,216,77,241,55,38,60,154,17,20,98,92,194,202,229,69,205,177,161,165,0,66,75,1,152,92,150,172,1,128,195,88,127,7,171,
0,165,169,248,209,11,21,94,188,66,170,188,248,164,2,148,37,0,16,15,196,192,91,244,96,217,131,147,101,216,63,187,89,244,13,143,51,240,48,187,204,69,175,105,29,184,187,137,141,91,30,68,55,34,144,98,226,
174,202,215,250,225,78,212,116,217,49,251,131,73,120,111,186,149,158,255,19,191,117,14,252,214,250,227,49,111,4,227,127,249,62,124,115,62,92,253,218,219,112,158,108,68,199,163,189,240,78,109,96,229,103,
243,202,181,76,78,51,186,126,174,127,87,229,168,68,81,119,24,179,255,48,149,247,152,84,253,101,195,112,44,206,124,229,34,213,95,30,249,234,47,197,80,103,198,153,175,92,84,182,83,243,7,169,254,138,171,
191,92,168,254,182,176,12,116,22,61,172,109,54,56,143,185,192,155,117,59,122,159,136,39,130,132,63,86,240,62,207,176,64,77,87,229,14,125,221,41,89,148,225,191,179,89,244,241,188,145,135,217,101,1,83,100,
130,220,240,114,16,235,99,171,136,174,135,33,9,187,235,17,104,255,120,55,172,173,53,104,127,184,11,77,231,91,84,251,196,136,136,233,191,187,9,163,211,140,206,79,244,32,112,199,135,165,183,230,177,113,
99,29,145,181,16,26,207,183,194,222,87,143,213,119,23,177,113,203,13,134,97,48,244,171,39,118,85,142,74,36,3,152,248,246,7,121,143,73,213,95,74,247,19,3,208,215,232,193,240,12,176,213,209,152,170,191,
148,141,27,235,170,41,156,169,250,3,128,134,211,205,48,214,25,247,238,67,148,217,250,181,21,184,175,103,159,174,170,183,232,209,251,139,71,148,109,179,203,130,246,71,186,11,94,243,246,247,39,85,189,252,
55,183,253,141,6,158,57,86,66,105,43,207,212,247,198,33,68,11,103,216,103,121,22,38,151,25,142,225,38,88,154,10,4,176,51,200,146,92,92,251,152,101,138,239,164,169,2,178,4,72,69,174,94,192,25,249,170,92,
82,146,220,27,89,3,0,63,154,62,11,35,159,125,120,204,109,79,139,230,53,255,220,38,204,46,43,120,115,113,241,132,205,91,30,212,31,119,129,53,148,125,0,194,158,153,252,238,216,142,150,48,100,121,22,142,
227,46,180,127,188,7,250,173,7,240,76,66,88,192,244,255,119,3,155,5,230,52,22,163,225,76,19,128,100,99,40,53,231,31,72,222,16,116,198,228,223,65,220,250,95,89,148,16,15,198,149,27,118,194,31,131,239,182,
87,57,71,140,239,46,8,81,169,132,168,160,250,124,217,164,234,47,23,189,85,175,220,132,169,254,180,148,250,227,24,48,28,11,89,146,0,57,89,87,242,182,70,191,206,200,67,102,24,176,92,250,87,138,234,47,247,
247,111,123,253,201,210,214,131,41,3,48,44,11,102,43,192,74,245,167,230,254,96,5,11,175,205,162,235,231,250,224,60,153,255,223,53,144,156,139,187,240,227,89,68,220,217,147,86,102,226,205,58,156,251,191,
31,44,186,60,149,78,140,9,170,135,147,98,112,122,14,13,103,154,209,254,209,238,156,141,109,89,144,48,251,191,166,176,118,117,185,228,238,172,212,60,106,107,155,54,63,81,234,247,142,55,242,168,27,112,66,
140,39,255,189,68,55,34,136,110,68,96,31,72,230,3,8,175,135,224,187,237,45,122,249,204,170,33,203,5,255,125,100,206,67,175,233,178,195,228,52,171,94,75,213,95,74,120,77,253,239,33,85,127,169,243,15,82,
0,32,186,17,201,89,135,6,187,250,115,242,102,117,61,229,194,234,212,65,203,237,215,175,228,229,254,118,195,55,183,9,33,156,40,124,32,0,239,164,7,75,111,205,163,241,108,11,186,62,217,7,134,203,29,72,20,
35,2,150,222,158,199,198,141,53,68,54,34,69,221,71,204,205,86,156,120,254,92,177,69,175,120,145,213,32,174,127,115,164,168,99,25,150,129,169,209,2,215,201,38,52,158,107,41,58,72,75,14,166,172,79,224,255,
115,252,98,182,151,179,90,187,178,140,217,31,220,194,233,255,179,248,115,72,114,184,248,250,251,43,216,156,246,226,216,175,157,132,49,227,199,86,74,136,184,241,237,107,8,175,4,239,105,57,222,255,250,59,
247,244,250,132,108,215,247,243,67,232,251,249,33,140,191,120,21,129,5,127,214,239,159,189,183,14,67,191,122,178,12,165,171,62,89,235,175,135,234,175,16,33,38,96,250,239,38,32,75,64,195,233,220,65,128,
249,215,110,99,241,205,187,251,88,178,131,65,140,139,88,121,103,1,190,153,13,28,253,194,41,232,44,25,65,110,25,152,126,245,38,60,99,235,229,41,32,33,247,72,112,49,136,235,127,254,30,234,134,156,104,255,
152,118,36,192,204,247,39,16,90,12,32,81,229,115,208,239,41,25,88,29,89,130,24,21,209,247,244,145,172,135,132,215,130,152,248,206,40,226,126,154,11,95,44,89,146,17,94,14,98,110,121,26,235,215,87,49,248,
236,241,156,29,144,228,224,43,41,252,35,198,4,24,234,77,24,122,238,164,210,139,76,118,38,17,136,225,214,119,199,32,101,68,124,23,223,184,123,207,31,254,1,192,88,111,130,209,97,134,209,97,134,225,0,69,
236,73,101,51,216,141,202,247,46,243,251,39,198,37,68,221,97,36,130,212,64,218,9,150,99,96,116,152,161,175,217,250,119,156,26,97,33,29,172,222,164,189,52,247,191,166,114,126,207,60,99,107,244,240,95,162,
200,122,24,211,127,123,83,243,186,119,194,77,15,255,228,64,146,18,34,194,107,33,196,115,36,184,142,121,35,8,175,133,52,109,62,162,229,30,91,133,119,107,90,201,118,66,88,160,135,255,18,133,150,2,152,250,
238,24,228,42,207,195,70,118,175,164,167,118,206,192,163,182,123,231,243,82,117,53,6,101,120,234,65,81,211,101,135,152,40,110,104,109,108,51,138,232,70,68,217,142,184,195,240,140,174,162,225,84,178,39,
74,150,128,213,140,245,100,109,157,118,52,157,111,5,111,218,221,159,204,228,50,103,125,253,232,175,159,78,39,17,243,132,113,237,79,47,107,142,169,29,168,199,145,207,167,123,20,185,3,52,117,3,0,76,13,102,
213,231,203,122,76,142,250,43,6,213,159,182,254,250,158,62,170,57,38,245,253,11,204,251,112,237,27,151,225,58,219,140,158,39,7,169,254,80,220,247,207,96,55,226,228,255,113,94,217,22,162,2,66,203,1,24,
29,166,67,95,127,0,0,73,70,104,37,136,133,159,204,65,74,36,91,61,98,92,196,250,7,171,104,121,80,187,20,215,194,235,179,170,109,134,103,97,107,179,41,203,162,229,194,31,176,96,56,195,49,168,237,41,62,167,
65,196,29,86,53,204,125,183,189,240,207,249,80,211,149,78,20,183,146,241,251,102,114,154,209,246,112,119,209,211,8,51,89,154,172,0,128,91,47,143,193,63,163,30,170,157,74,217,16,90,12,224,189,63,250,169,
18,16,107,186,208,134,246,143,118,129,225,146,83,20,154,31,104,67,253,209,6,28,184,73,178,12,10,254,251,72,213,95,202,232,55,71,148,169,16,153,41,47,54,110,172,99,230,213,9,205,3,108,186,254,0,99,157,
17,137,80,113,67,190,171,65,195,169,166,220,57,128,182,134,81,27,106,141,184,239,223,62,132,192,93,31,38,190,51,10,247,245,53,108,220,208,62,188,74,66,178,157,120,242,183,239,131,190,214,160,188,126,144,
239,209,3,191,124,180,168,7,77,33,156,192,252,235,115,136,122,210,211,75,86,71,150,52,201,58,151,222,190,163,121,248,103,88,6,108,17,115,251,15,210,252,127,0,0,11,112,69,62,23,136,81,65,53,77,34,176,224,
135,103,116,21,206,147,141,247,168,112,164,146,237,250,46,35,203,50,24,134,193,147,71,223,198,144,43,221,75,98,49,164,255,81,122,35,54,188,248,238,167,210,219,97,27,0,160,110,160,208,26,188,213,103,224,
87,134,139,62,86,150,101,204,188,122,11,238,15,86,148,215,188,147,30,37,0,16,221,8,171,230,75,233,44,58,28,121,238,132,146,20,109,191,25,108,6,24,108,134,194,7,86,41,206,192,239,168,129,171,33,39,215,
181,143,109,45,203,194,155,121,88,90,108,48,53,36,147,216,80,253,165,133,87,131,170,161,143,53,93,246,130,243,208,168,254,114,171,233,170,5,203,177,216,156,241,66,136,75,240,77,111,128,55,235,96,105,177,
129,55,149,248,189,174,18,59,169,191,218,190,122,48,60,139,59,255,56,173,188,22,88,240,1,80,7,0,34,238,48,34,158,116,144,150,229,89,28,251,226,217,29,39,166,58,8,56,3,95,92,128,101,139,44,72,152,120,105,
84,53,167,217,59,229,86,5,0,130,25,43,208,12,124,118,88,51,231,124,55,164,132,148,51,199,133,44,203,16,227,34,24,142,5,111,210,65,103,212,169,150,240,53,58,205,154,169,120,7,1,131,226,3,56,188,129,3,111,
210,65,140,10,144,82,79,108,12,192,155,116,224,140,201,7,39,73,74,214,35,203,179,224,76,58,176,91,247,239,204,250,59,72,1,0,99,189,9,198,122,83,254,131,24,128,211,243,224,12,60,120,147,14,146,144,253,
187,200,25,56,48,44,11,206,192,169,190,127,7,249,94,189,147,164,168,166,6,51,174,255,183,244,156,246,224,98,64,115,140,123,116,77,181,221,116,95,43,58,30,235,85,190,139,135,137,185,209,138,251,126,239,
161,162,142,77,230,21,187,137,205,105,143,242,154,123,140,2,0,135,213,174,3,0,82,66,4,167,231,209,90,235,198,177,166,185,172,199,68,5,61,198,87,186,118,251,22,7,22,195,48,104,58,223,170,10,0,196,188,233,
225,98,169,12,253,41,198,122,115,217,30,254,73,97,178,36,225,230,119,174,43,219,214,102,27,134,158,163,57,216,217,44,253,116,30,238,177,116,54,229,51,191,123,81,25,129,66,118,174,239,23,143,65,103,230,
241,238,31,188,129,68,32,134,155,223,185,78,57,20,10,176,182,168,123,59,133,144,54,121,107,124,83,221,187,100,235,168,61,148,15,255,187,193,240,44,92,103,90,84,1,128,152,55,93,159,178,44,39,123,162,82,
199,51,204,158,60,252,23,171,254,136,19,253,89,70,32,17,160,255,151,146,217,231,175,125,227,50,162,91,73,47,117,22,61,206,126,69,155,227,169,233,129,54,116,60,210,163,121,253,176,179,181,215,226,220,239,
61,136,245,107,43,152,121,117,66,179,127,240,87,142,239,122,69,151,195,192,236,202,184,63,103,180,135,165,132,132,184,47,125,63,97,121,22,157,143,245,82,66,187,34,240,102,30,157,143,245,170,2,0,197,38,
183,37,7,207,174,3,0,219,35,151,100,231,56,189,250,102,165,90,254,40,115,106,216,1,27,145,120,144,184,63,88,85,134,148,241,6,30,245,199,27,96,114,166,30,20,100,208,31,79,173,166,199,14,214,200,194,59,
225,65,34,24,135,251,131,85,240,91,61,75,169,30,35,125,141,1,246,129,122,212,116,80,35,169,40,12,11,215,185,102,136,81,17,158,177,53,196,124,49,172,141,44,193,228,50,195,70,117,152,69,230,191,73,237,92,
92,73,82,247,220,177,252,1,27,54,122,143,177,122,117,29,203,187,92,222,111,167,76,245,38,8,205,182,188,199,24,237,5,122,114,9,204,46,11,184,173,101,138,121,139,186,173,167,51,234,96,105,182,65,95,115,
112,71,101,237,5,222,156,172,167,76,156,158,238,37,121,21,184,61,103,142,170,224,12,28,61,252,239,64,230,242,183,210,1,91,21,136,20,143,158,226,9,41,193,221,215,102,148,255,175,179,234,208,243,196,224,
182,189,244,240,159,201,117,166,25,174,51,205,24,95,185,138,68,48,174,170,191,20,115,131,57,163,30,73,62,12,11,244,60,49,136,168,39,12,207,216,26,34,238,48,110,95,154,132,235,108,51,5,0,200,161,226,56,
238,42,216,187,186,125,222,53,73,10,47,7,17,245,166,167,188,56,135,93,170,253,27,55,210,9,27,245,181,6,28,127,254,236,190,149,173,218,8,225,4,252,115,155,0,128,214,15,117,40,175,91,90,106,96,176,211,119,
143,16,82,25,10,6,0,26,109,94,252,135,79,252,85,206,253,47,93,253,56,254,122,228,19,89,247,73,165,45,50,64,238,1,199,241,6,152,154,210,195,45,183,39,68,209,153,245,104,127,36,189,108,141,165,41,127,79,
202,97,148,89,127,219,233,140,186,172,175,19,173,198,251,90,97,31,202,158,11,132,122,232,114,163,127,191,132,228,182,240,147,59,240,77,111,228,61,198,49,236,162,41,0,25,86,174,44,97,109,100,169,240,129,
160,250,43,36,188,22,194,228,247,198,53,175,247,62,53,164,228,121,34,132,144,114,43,24,0,96,33,193,162,203,190,156,9,0,136,18,135,80,162,132,229,227,184,234,238,37,101,11,100,132,174,52,117,131,78,77,
70,213,20,206,196,163,245,161,206,162,175,197,114,213,245,217,51,49,187,40,127,190,250,219,169,195,88,127,41,123,145,116,230,48,214,31,253,251,77,43,229,251,183,31,168,126,171,27,253,253,74,115,216,234,
79,140,137,88,187,178,132,232,70,246,246,178,111,122,3,66,56,1,199,176,171,168,233,19,76,181,183,141,43,124,88,254,97,251,126,18,146,105,207,190,65,243,175,207,237,234,60,147,163,122,179,238,26,236,134,
67,157,156,207,232,52,85,252,77,62,159,114,39,245,162,250,43,13,213,95,105,168,254,238,45,170,223,234,70,127,191,210,28,182,250,19,34,9,220,249,225,12,86,71,22,179,238,119,143,173,225,206,15,103,84,75,
64,231,99,174,242,127,127,233,165,37,181,57,86,42,193,97,251,126,18,146,41,235,183,191,221,190,134,174,186,21,116,213,173,160,197,174,94,199,52,16,51,99,206,219,164,252,23,138,39,123,255,229,196,238,146,
252,180,92,212,174,191,92,45,218,30,238,46,124,208,1,198,234,56,52,95,168,206,191,31,167,231,209,244,64,91,89,203,64,245,87,26,170,191,210,80,253,221,91,84,191,251,175,233,190,22,116,125,178,95,249,143,
97,211,189,168,6,187,17,93,159,236,135,171,200,97,216,135,233,239,231,28,118,169,234,77,103,73,174,204,210,245,88,159,242,218,78,235,226,48,213,223,118,198,122,19,186,62,217,15,231,241,228,40,55,123,159,
3,93,159,236,135,181,173,102,71,215,113,158,104,170,218,156,1,206,147,77,202,50,200,149,154,11,233,176,126,63,9,73,201,58,5,224,119,63,242,50,236,166,80,214,19,70,230,7,240,87,35,143,239,89,1,234,142,
56,209,245,120,31,238,190,118,91,157,9,191,130,49,28,139,182,135,59,105,62,23,128,182,143,118,67,18,37,172,190,187,0,73,172,204,72,111,38,147,211,140,222,159,31,130,177,174,252,115,205,169,254,74,67,245,
87,26,170,191,123,139,234,119,127,101,78,143,185,243,79,51,128,148,172,119,157,85,143,166,251,91,119,116,189,195,242,247,171,233,178,171,146,39,174,188,183,136,68,40,14,215,185,22,101,148,99,96,193,143,
229,159,205,239,168,44,135,165,254,182,211,215,36,191,103,235,6,14,238,209,85,88,219,108,104,186,191,21,161,101,63,130,11,254,162,175,195,233,57,12,253,234,41,76,255,237,13,132,150,2,187,42,203,190,99,
146,137,126,59,31,235,43,119,73,138,114,24,191,159,132,164,236,217,42,0,53,221,181,187,62,183,233,129,54,56,142,187,224,159,245,169,214,7,174,68,172,145,69,77,71,45,244,53,37,228,61,56,64,24,22,232,252,
68,47,90,31,234,64,120,53,4,89,174,236,155,40,111,228,97,110,178,129,169,144,145,95,84,127,165,161,250,43,13,213,223,189,69,245,91,30,179,151,38,17,247,199,128,18,27,245,244,247,43,13,213,95,105,76,14,
19,142,255,230,89,132,215,66,72,4,227,229,46,78,65,38,167,185,170,150,135,164,239,39,57,204,246,44,0,96,239,207,158,209,187,88,58,139,30,142,225,134,61,42,13,217,111,188,89,135,154,110,90,114,108,183,
168,254,74,67,245,87,26,170,191,123,139,234,119,127,249,230,54,17,117,135,247,236,122,244,247,43,13,213,95,105,204,46,11,224,162,57,223,247,10,125,63,201,97,180,227,0,64,71,221,26,62,117,228,157,93,189,
217,221,77,23,70,151,123,118,117,46,33,132,16,66,72,33,131,191,114,28,178,40,98,244,155,87,33,139,201,169,133,225,149,32,174,255,249,123,176,247,215,163,227,209,222,50,151,176,58,140,190,112,5,204,214,
20,238,106,153,162,89,105,86,223,91,194,198,141,117,196,252,177,114,23,133,16,66,20,59,14,0,244,58,150,208,235,40,110,189,216,76,175,79,159,162,0,0,33,132,16,66,238,25,147,99,107,126,236,182,252,99,146,
32,33,188,22,130,137,122,82,139,22,89,207,158,11,138,20,47,17,138,35,17,170,252,225,251,132,144,195,101,207,166,0,16,66,8,33,132,148,203,173,151,199,224,159,241,42,219,50,245,90,239,202,137,231,207,65,
150,37,140,124,245,109,165,14,173,173,54,28,249,181,147,96,104,2,114,86,134,90,35,238,251,183,15,129,97,179,215,79,247,19,3,112,158,112,129,229,169,217,77,8,41,63,186,19,17,66,8,33,164,234,73,9,9,98,92,
204,186,143,97,25,112,6,30,156,158,154,61,133,36,51,255,179,208,153,120,72,66,50,49,26,103,162,186,203,139,129,170,126,24,158,5,111,210,41,219,156,145,234,143,16,82,57,178,222,141,254,252,237,167,160,
227,178,255,136,150,194,27,182,237,249,53,9,33,132,16,66,242,177,180,216,48,252,197,51,229,46,70,85,136,172,135,32,37,36,12,254,202,113,229,53,78,207,149,177,68,149,79,22,37,132,87,67,224,12,28,140,14,
51,156,195,46,56,135,93,154,227,162,158,48,196,152,8,115,163,5,12,71,163,41,8,33,229,145,53,0,48,185,222,190,223,229,32,132,16,66,8,217,53,83,189,9,66,115,246,142,6,147,147,214,205,46,214,173,151,199,
53,171,40,88,219,106,40,128,146,71,60,16,199,232,11,87,80,211,85,139,163,95,56,157,243,184,219,255,243,22,252,115,62,156,254,242,3,48,216,105,57,105,66,72,121,236,122,60,82,108,51,130,219,127,63,169,108,
27,236,70,244,124,122,112,79,10,69,8,33,132,16,178,19,93,63,215,15,0,240,77,123,33,198,5,213,62,222,172,203,118,10,217,38,48,239,67,34,16,135,24,211,142,0,21,35,9,108,220,88,135,190,214,0,107,107,77,25,
74,87,29,18,33,1,27,55,214,243,238,39,132,144,114,219,117,0,64,74,72,240,221,78,39,219,49,53,80,102,93,66,8,33,132,148,215,236,63,78,81,15,246,46,44,252,228,14,124,211,27,89,247,69,60,17,76,126,111,28,
142,97,23,250,159,62,186,207,37,171,30,145,245,16,38,191,55,94,238,98,16,66,72,94,148,145,132,16,66,8,33,85,111,227,230,58,98,222,40,196,136,182,151,53,30,136,97,249,237,121,24,27,204,168,235,119,148,
161,116,213,163,225,116,19,120,163,14,43,239,206,131,225,88,52,158,107,69,34,16,135,123,108,181,220,69,35,132,16,178,7,40,3,9,33,132,16,66,170,222,234,149,101,220,249,225,76,214,117,215,227,190,24,238,
252,112,6,238,15,232,33,182,144,150,7,59,208,249,88,47,192,178,224,12,60,58,31,235,69,227,3,173,229,46,22,33,132,144,61,66,35,0,8,33,132,16,114,96,180,126,184,19,58,139,94,245,90,108,51,138,229,159,205,
151,169,68,228,176,48,214,155,208,116,127,91,193,227,120,51,53,191,9,33,229,67,119,32,66,8,33,132,28,24,206,19,141,48,57,205,170,215,2,11,126,10,0,144,123,78,95,163,71,211,253,52,90,130,16,82,217,40,0,
64,8,33,132,16,66,52,132,168,128,91,47,141,66,136,82,246,250,124,116,86,61,6,159,29,6,111,214,23,62,152,16,66,202,140,114,0,16,66,8,33,132,16,13,89,144,224,157,244,32,112,215,87,238,162,84,52,150,103,
81,55,224,4,203,50,184,254,231,239,97,254,159,103,203,93,36,66,8,201,137,70,0,16,66,8,33,228,192,152,252,155,81,48,156,186,127,67,18,164,50,149,166,122,244,60,49,0,49,46,192,104,55,106,246,153,27,173,
232,251,197,33,240,70,106,54,230,35,198,69,132,215,66,176,180,88,203,93,20,66,8,201,137,238,228,132,16,66,8,57,48,34,158,72,185,139,80,149,12,89,30,252,83,88,29,11,179,139,30,106,115,137,251,98,248,224,
207,46,67,150,100,0,128,251,250,26,54,110,184,209,242,225,14,180,62,212,137,217,75,147,112,95,95,197,208,115,39,96,235,168,45,115,105,9,33,135,29,5,0,8,33,132,16,82,245,6,63,59,12,89,146,48,246,205,43,
154,32,128,181,213,134,35,191,118,18,12,67,51,31,11,17,163,2,100,73,198,169,47,221,15,32,249,64,203,240,84,111,249,200,178,12,49,46,130,97,25,240,38,29,36,65,130,24,23,33,11,201,250,147,4,49,185,189,21,
32,32,132,144,114,162,0,0,33,132,16,66,170,30,203,179,0,88,240,38,29,120,147,58,105,29,103,226,193,233,169,201,83,140,209,23,175,34,234,14,171,94,179,182,213,96,248,139,103,202,84,162,234,97,235,168,193,
209,47,156,198,250,181,21,204,188,58,81,238,226,16,66,72,86,244,107,72,8,33,132,144,3,163,231,51,131,144,18,218,57,255,161,165,0,120,147,14,134,186,220,67,221,15,179,232,70,36,217,251,159,37,95,130,20,
23,169,254,8,33,228,128,160,0,0,33,132,16,66,14,140,91,47,143,107,122,176,83,28,195,46,244,63,125,116,159,75,84,29,102,255,97,10,190,233,141,172,251,194,107,33,140,190,112,133,234,143,16,66,14,0,10,0,
16,66,8,33,164,234,5,230,125,72,4,226,16,99,98,185,139,82,213,106,251,234,192,233,120,120,39,220,0,199,160,174,223,1,33,146,128,127,110,179,220,69,171,120,137,144,128,141,27,235,8,45,5,0,0,17,119,8,27,
55,214,17,219,140,149,185,100,132,16,146,70,1,0,66,8,33,132,84,189,133,159,220,201,217,131,77,138,215,245,120,63,76,78,51,222,253,195,55,192,27,121,12,60,115,12,129,5,63,198,95,188,90,238,162,85,188,200,
122,8,147,223,27,87,182,61,99,235,240,140,173,151,177,68,132,16,162,69,1,0,66,8,33,132,28,24,13,167,155,192,27,117,89,247,89,154,105,41,59,178,255,106,251,234,97,110,176,64,95,99,40,119,81,8,33,132,2,
0,132,16,66,8,57,56,90,30,236,128,201,105,46,119,49,8,81,56,135,93,104,56,213,84,238,98,16,66,8,0,10,0,16,66,8,33,132,144,44,196,152,128,185,127,152,66,34,20,47,119,81,42,26,111,230,209,245,201,254,156,
251,173,109,53,251,88,26,66,8,201,143,2,0,132,16,66,8,33,68,67,74,72,88,185,188,88,238,98,84,180,91,47,141,66,103,213,163,231,211,131,202,107,190,219,94,172,188,179,144,222,158,73,230,166,104,127,164,
7,102,151,101,223,203,72,8,33,219,81,0,128,16,66,8,33,7,198,236,165,73,112,122,46,235,62,91,167,29,45,15,182,239,115,137,170,67,251,195,93,104,58,223,146,117,158,186,209,105,70,231,39,122,160,183,209,
28,246,76,222,73,15,12,118,117,189,196,253,49,120,39,61,154,99,155,47,210,119,143,16,82,126,20,0,32,132,16,66,200,129,145,111,185,58,54,71,96,128,228,31,166,206,27,121,212,13,56,247,177,52,213,41,180,
20,192,204,171,19,16,162,66,185,139,66,8,33,57,81,0,128,16,66,8,33,132,168,156,120,254,44,100,89,6,0,176,60,5,78,138,33,198,69,132,215,66,229,46,6,33,132,228,69,1,0,66,8,33,132,16,2,0,24,253,230,21,68,
61,97,0,128,206,170,199,169,223,185,191,204,37,170,62,206,227,141,232,126,82,155,20,144,229,169,217,77,8,41,63,186,19,17,66,8,33,164,234,245,61,53,4,73,144,242,30,195,234,168,39,59,23,49,46,64,22,100,
72,113,1,98,92,4,0,176,49,17,66,56,1,134,99,193,25,168,238,114,145,37,6,66,56,1,49,150,28,250,207,112,0,167,167,38,54,33,164,50,209,221,137,16,66,8,33,85,111,250,213,9,248,166,55,242,30,227,24,118,161,
255,233,163,251,84,162,234,50,249,189,27,154,250,75,132,226,24,249,234,91,176,182,213,96,248,139,103,202,84,178,202,23,247,71,49,242,213,183,202,93,12,66,8,41,10,5,0,8,33,132,16,66,8,0,192,212,96,1,203,
179,0,0,89,146,17,94,13,150,185,68,149,205,210,108,131,44,74,170,185,255,66,88,64,104,41,160,57,214,232,52,231,92,161,130,16,66,246,11,5,0,8,33,132,16,66,8,0,96,224,153,99,48,57,205,0,128,120,48,142,171,
95,123,187,204,37,170,108,199,159,63,139,216,102,20,239,127,253,29,229,53,239,164,39,235,50,128,71,191,112,10,53,93,246,253,44,30,33,132,104,80,0,128,16,66,8,33,85,175,166,163,22,92,142,57,254,66,36,145,
119,121,64,66,74,193,234,56,212,31,105,64,34,156,64,224,14,125,207,8,33,149,141,2,0,132,16,66,8,169,122,173,31,238,204,185,47,176,224,199,248,139,87,247,177,52,228,48,209,89,116,24,120,230,24,252,115,
155,184,241,173,107,229,46,14,33,132,228,69,1,0,66,8,33,132,16,2,0,88,191,182,12,157,89,15,0,202,106,0,241,64,12,203,111,207,43,199,88,219,108,176,117,208,80,246,76,250,26,3,154,47,180,231,221,79,8,33,
229,70,1,0,66,8,33,132,16,2,0,88,122,115,94,243,90,220,23,195,157,31,206,40,219,45,15,117,80,0,32,11,99,189,9,157,143,245,150,187,24,132,16,146,23,5,0,8,33,132,16,82,245,86,71,22,17,89,11,103,221,151,
8,197,247,185,52,132,16,66,72,101,162,0,0,33,132,16,66,170,222,198,132,71,179,142,61,33,132,16,66,212,40,0,64,8,33,132,144,3,205,232,52,163,243,19,61,208,219,104,14,118,46,237,15,119,161,233,124,75,81,
199,26,235,205,247,184,52,132,16,66,238,21,10,0,16,66,8,33,228,64,227,141,60,234,6,156,229,46,70,69,179,182,213,148,187,8,132,16,66,246,1,5,0,8,33,132,16,82,245,122,158,24,128,24,23,178,238,99,121,110,
159,75,67,8,33,132,84,38,10,0,16,66,8,33,164,234,25,236,198,156,251,130,139,1,188,247,71,63,69,253,209,6,244,62,53,180,143,165,34,132,16,66,42,11,91,238,2,16,66,8,33,132,220,75,178,44,67,140,139,144,4,
169,220,69,33,132,16,66,202,138,2,0,132,16,66,8,33,132,16,66,200,33,64,83,0,8,33,132,16,114,96,68,214,67,144,18,234,158,254,168,59,2,0,16,162,9,132,150,2,208,219,244,208,209,138,0,132,16,66,14,33,10,0,
16,66,8,33,228,192,184,245,242,56,162,238,112,214,125,190,105,47,70,167,175,160,229,161,14,116,60,210,179,207,37,35,132,16,66,202,143,2,0,132,16,66,8,169,122,129,121,31,18,129,56,196,152,88,238,162,16,
66,8,33,21,139,2,0,132,16,66,8,169,122,11,63,185,3,223,244,70,185,139,65,8,33,132,84,180,125,11,0,132,86,66,88,126,243,110,193,227,186,159,28,0,103,160,245,122,9,33,132,84,191,192,188,31,82,129,30,105,
125,157,17,38,135,105,159,74,116,240,53,156,110,2,111,212,169,94,75,4,226,112,143,173,194,232,52,163,174,223,129,154,78,123,153,74,71,170,89,204,151,28,25,88,0,0,32,0,73,68,65,84,27,197,194,79,102,149,
109,123,159,19,142,225,6,101,123,229,103,11,8,173,6,148,237,158,39,7,193,112,148,111,155,16,82,89,246,45,0,144,8,70,225,30,91,45,120,92,231,227,189,20,0,32,132,84,140,184,63,138,133,55,238,20,125,124,
215,99,253,96,117,212,224,35,73,183,191,63,129,72,142,249,232,41,45,15,181,163,227,145,222,125,42,209,193,215,242,96,7,76,78,179,234,181,192,130,31,238,177,85,88,154,172,232,124,140,234,154,236,78,34,
28,199,250,181,116,91,86,103,209,171,2,0,155,51,94,108,78,123,148,237,238,79,13,130,161,38,237,129,224,189,229,70,204,31,203,123,140,201,97,70,109,79,29,0,192,63,183,137,240,122,72,217,231,60,209,8,222,
160,126,236,138,7,227,216,184,185,174,108,91,155,109,176,182,213,236,97,169,9,201,174,108,83,0,26,207,181,194,121,178,81,217,190,253,247,19,136,172,135,49,241,210,40,56,61,135,163,95,56,85,210,245,3,11,
126,220,253,199,233,244,251,157,111,133,243,68,99,158,51,114,155,127,125,22,254,25,175,178,61,244,185,19,224,76,52,123,130,144,195,32,17,74,96,109,100,185,232,227,59,31,237,187,135,165,33,213,140,229,
89,213,239,94,204,27,133,239,182,23,161,149,16,214,70,150,97,235,170,213,60,184,238,183,181,247,151,129,173,1,11,58,171,14,117,67,206,178,150,135,144,131,32,226,14,99,246,210,45,101,219,57,220,8,215,185,
22,0,192,221,215,110,35,184,224,83,246,29,121,238,36,24,190,114,130,200,43,239,44,96,99,34,253,144,218,251,212,81,24,236,135,111,5,141,149,119,23,225,187,237,205,123,140,243,184,75,9,0,184,175,175,97,
237,234,146,178,175,182,167,94,19,0,136,121,35,152,251,193,148,178,221,250,161,78,10,0,144,125,81,182,167,88,131,221,0,91,123,250,75,206,233,147,69,9,45,5,192,238,193,141,79,140,38,16,88,240,43,219,165,
52,98,162,158,176,234,90,146,40,129,2,186,132,28,78,245,71,26,208,120,182,57,231,126,86,87,249,119,135,133,31,207,33,176,173,193,9,0,156,94,135,129,95,62,90,166,18,29,14,156,129,71,207,147,131,202,182,
103,108,13,190,219,94,248,166,55,224,155,222,64,247,19,253,101,15,0,204,253,96,10,146,144,92,66,207,218,90,67,1,0,66,246,128,24,19,224,159,75,223,115,173,173,233,246,111,120,37,164,218,39,203,0,179,175,
165,203,47,226,142,168,202,39,37,40,201,38,128,228,42,34,76,242,47,21,219,140,96,245,189,37,132,150,131,184,243,79,51,168,237,174,43,115,233,8,201,175,132,0,64,230,237,73,46,169,32,185,248,103,55,49,253,
183,55,114,238,31,250,220,9,152,155,173,144,18,18,174,253,215,119,148,215,37,81,93,158,197,55,238,98,229,157,133,130,231,101,106,253,72,215,238,11,159,135,156,81,93,204,182,234,100,56,117,221,166,26,99,
132,144,242,211,219,13,168,237,171,47,119,49,74,18,90,10,194,55,173,238,201,56,44,163,154,196,140,245,225,217,172,243,115,247,231,247,45,159,149,119,22,144,8,38,178,238,51,53,89,224,28,118,1,0,54,38,60,
8,109,11,80,103,163,183,235,209,120,174,21,201,207,177,15,143,22,153,213,181,253,247,13,12,24,142,133,44,74,91,135,202,144,18,210,158,76,155,105,127,184,11,77,231,91,160,175,209,246,78,154,157,102,12,
62,59,12,189,237,240,245,92,146,242,179,52,89,113,250,203,15,40,219,153,61,193,59,49,255,207,179,112,95,95,41,248,126,3,159,61,94,244,121,188,89,143,227,191,121,22,0,224,157,242,96,238,7,147,202,62,33,
172,126,224,191,249,237,107,74,59,53,223,121,153,142,124,254,20,140,245,249,115,157,100,6,23,42,105,36,68,166,166,11,237,96,183,234,33,48,239,195,234,123,75,136,184,195,136,184,195,96,217,202,45,55,33,
64,9,1,0,62,163,177,24,247,197,32,196,132,162,111,106,178,44,43,13,128,173,87,0,0,44,199,168,30,128,101,81,130,16,209,54,130,100,41,121,13,81,16,147,215,97,160,58,46,243,1,91,18,4,200,98,250,186,146,36,
67,18,101,200,146,140,120,48,174,188,119,38,41,174,141,116,202,82,102,217,1,48,12,24,182,248,134,85,120,37,168,218,230,205,233,122,51,212,26,147,13,38,57,117,108,0,129,121,191,106,196,4,33,164,114,9,49,
1,99,47,92,45,120,92,247,19,253,170,158,130,209,111,94,129,184,117,207,49,185,204,24,124,102,88,217,183,126,109,5,139,63,189,91,212,185,153,26,78,55,161,245,161,14,101,187,231,201,126,136,177,30,76,252,
205,24,162,158,252,243,211,51,223,55,211,137,223,58,171,140,122,136,172,135,113,235,187,99,121,175,7,0,67,207,14,195,232,80,247,116,23,58,55,243,243,238,134,36,202,88,189,188,168,122,205,96,55,106,142,
227,205,234,4,114,225,245,16,36,81,206,250,27,113,175,172,142,44,229,204,29,224,24,110,80,2,0,190,105,15,86,71,150,178,30,151,98,109,173,217,10,0,236,79,249,131,75,1,213,246,246,223,55,48,201,58,87,190,
119,50,176,252,206,60,90,63,212,89,242,251,230,27,58,203,25,121,212,13,208,104,6,82,30,12,199,102,189,215,236,134,16,22,16,219,204,63,23,93,103,209,239,232,60,105,91,96,84,138,73,121,175,31,15,196,119,
117,158,44,22,14,164,46,189,57,175,218,54,102,212,25,167,231,84,237,99,33,42,66,74,136,85,49,242,174,18,196,253,81,213,54,87,66,32,138,84,183,93,255,229,117,86,61,12,117,70,196,188,201,47,147,24,23,113,
235,175,175,163,249,98,59,56,99,250,178,188,137,135,165,217,166,57,127,254,71,179,152,255,209,172,230,245,211,255,234,2,116,214,244,141,171,182,175,30,231,255,253,71,52,199,77,189,50,14,207,216,58,198,
255,242,125,0,192,217,175,92,84,29,183,57,237,193,196,119,70,149,237,246,143,245,160,101,91,3,24,0,174,252,201,219,72,132,146,55,50,147,211,140,147,95,58,159,245,179,78,189,50,174,218,190,250,95,126,166,
57,198,222,87,143,161,231,78,40,219,49,127,20,81,119,36,235,245,34,235,97,204,191,174,254,236,182,182,90,229,255,235,172,122,88,91,108,8,46,38,27,81,178,4,220,252,214,251,176,180,213,238,107,3,148,144,
195,204,232,48,163,251,83,253,69,31,63,255,250,28,162,107,33,244,63,115,12,144,228,130,15,214,128,54,192,24,245,68,32,198,5,0,0,171,87,247,32,8,145,132,234,154,249,206,205,148,186,207,165,232,108,6,232,
108,185,122,191,213,50,223,55,147,188,45,22,42,9,98,113,159,59,203,168,166,66,231,102,126,222,217,75,83,136,110,20,126,175,237,162,222,136,242,155,149,82,55,228,208,28,103,105,180,130,229,89,165,156,49,
111,20,147,223,29,69,227,217,22,176,250,226,26,154,214,182,154,100,99,117,27,49,38,96,250,149,155,202,118,204,151,44,75,221,128,19,142,227,46,88,91,109,88,122,115,30,225,149,32,226,129,100,67,186,247,
169,35,74,80,60,182,17,193,252,235,179,8,204,251,49,253,202,77,216,179,148,189,243,209,94,232,182,122,192,197,152,128,217,75,147,136,122,195,152,126,229,38,172,237,53,104,186,191,21,0,176,254,254,10,124,
51,218,249,172,178,164,253,219,136,113,17,193,2,163,12,0,0,18,16,88,240,105,26,241,219,127,223,0,160,110,208,129,229,183,211,127,187,249,31,205,194,253,193,106,214,158,251,98,152,93,86,77,167,4,0,4,151,
130,96,57,25,230,70,109,27,68,8,39,84,9,186,8,201,199,228,176,160,235,83,59,207,239,146,8,197,241,254,215,181,163,76,91,30,108,71,199,163,217,147,81,94,254,143,111,104,94,115,28,107,64,255,47,29,203,122,
252,201,223,62,15,83,131,89,121,191,43,127,242,54,130,139,1,188,243,251,63,86,157,215,253,68,63,186,159,208,254,166,93,254,195,55,144,8,37,240,206,239,255,24,214,86,27,134,127,227,44,28,195,15,43,251,
103,47,77,97,117,36,29,56,221,254,126,0,16,92,244,99,236,47,210,1,239,204,207,54,241,157,81,108,78,123,240,193,159,93,6,0,156,255,119,31,6,171,99,49,241,55,163,144,183,5,16,98,254,24,162,25,65,207,250,
35,13,170,109,86,199,194,84,111,66,196,147,108,95,203,162,132,153,239,79,160,227,145,62,240,247,40,129,56,103,224,128,29,116,240,237,5,57,33,237,249,232,223,120,48,134,217,75,83,170,215,76,46,203,158,
190,7,169,30,37,133,126,26,207,182,226,238,107,51,202,118,96,193,143,192,247,212,15,203,246,62,7,134,158,59,158,121,42,120,179,14,186,44,63,216,153,189,232,82,66,210,68,172,0,64,204,177,172,146,44,1,76,
158,54,109,161,253,64,122,250,0,195,2,12,163,253,71,111,172,51,41,215,144,196,100,196,83,76,72,136,122,194,224,140,60,116,22,61,54,39,55,48,123,41,247,80,168,237,24,142,69,195,25,245,156,226,246,143,118,
227,230,127,191,174,68,57,37,81,70,224,206,102,81,215,35,132,148,78,136,100,127,152,94,125,119,1,171,151,211,61,174,3,159,61,134,186,126,7,194,43,65,4,238,250,178,158,83,63,228,64,255,211,233,198,219,
220,255,158,198,234,123,75,152,124,121,28,96,24,28,127,254,44,204,187,252,33,30,125,225,10,194,171,33,200,162,4,206,196,227,220,239,94,84,246,109,76,120,48,245,202,184,82,230,174,199,251,208,120,95,75,
81,215,221,152,240,96,234,127,140,43,79,248,93,143,169,207,29,125,225,10,194,107,33,140,124,245,45,232,76,60,206,124,229,162,230,26,205,247,183,161,227,209,30,101,123,242,229,113,120,167,60,24,123,225,
10,100,48,56,247,123,23,1,17,24,249,218,219,96,182,110,118,197,214,85,96,222,135,240,106,80,243,158,59,81,215,239,64,221,160,182,87,152,213,177,104,56,213,172,106,244,110,78,109,96,115,170,248,53,230,
79,126,233,188,102,62,191,36,72,89,87,195,49,185,76,112,30,79,246,232,251,231,188,216,220,182,150,189,99,184,65,201,139,19,92,240,99,254,245,89,196,125,49,184,125,171,208,219,181,189,124,246,65,135,242,
190,137,96,28,179,151,38,33,132,5,184,199,86,33,67,82,2,0,193,69,127,81,43,243,0,64,100,61,132,155,223,254,160,168,99,51,25,236,70,56,142,171,27,241,45,23,219,177,254,254,138,106,212,94,106,232,236,110,
20,74,204,229,185,225,222,213,117,9,73,201,213,230,44,132,97,147,57,175,100,33,61,218,180,16,125,173,65,153,22,154,58,79,138,75,136,109,70,11,142,178,101,24,70,149,160,79,103,78,223,35,132,72,98,215,159,
227,94,240,223,246,170,70,16,100,50,214,155,208,242,161,14,205,235,206,19,77,170,78,52,207,216,58,60,99,235,154,227,246,202,145,207,159,84,18,251,109,55,254,151,233,160,71,42,64,109,239,171,71,219,71,
187,97,168,209,99,254,245,236,171,7,141,191,120,21,156,137,199,208,231,78,100,221,15,0,75,239,204,103,237,36,221,107,141,103,139,107,15,144,131,167,164,0,64,243,3,173,240,78,172,171,18,228,21,171,229,
98,187,166,71,62,27,255,29,175,170,39,191,144,219,127,63,129,222,167,134,114,238,159,255,231,219,104,190,208,150,117,120,20,144,108,132,124,240,141,100,148,178,255,233,99,170,229,93,82,142,253,139,211,
202,40,133,212,241,129,59,155,184,246,167,151,209,120,174,5,221,79,12,20,93,94,0,104,255,88,183,102,94,84,109,95,61,218,63,222,157,188,1,236,255,244,83,66,72,14,12,199,169,122,26,216,66,17,69,0,50,195,
168,230,50,166,2,157,178,36,3,144,181,115,150,118,64,22,182,77,73,146,129,68,52,29,184,16,19,194,214,251,0,128,4,41,75,239,110,238,11,75,170,169,78,50,155,57,31,115,235,51,136,18,196,204,41,81,185,206,
217,106,213,38,131,172,50,32,51,144,145,124,159,84,13,72,130,250,51,164,134,141,238,69,93,109,103,116,154,209,253,233,193,156,251,59,62,222,13,255,236,134,210,211,180,23,56,19,143,161,103,211,141,62,255,
109,47,230,95,79,246,126,7,230,124,104,121,80,251,155,120,227,91,215,148,129,251,98,188,244,30,33,247,245,85,172,94,94,68,116,51,25,88,239,124,172,23,214,109,61,244,55,190,117,77,59,197,109,183,24,160,
247,51,67,74,146,223,20,157,85,143,129,103,142,225,214,75,99,57,71,173,16,114,16,240,38,61,78,127,249,130,166,151,60,159,83,95,186,95,201,137,145,58,207,59,229,129,247,235,30,180,60,216,158,255,253,204,
58,156,254,242,133,172,251,230,127,52,167,10,106,230,19,92,12,32,180,236,223,154,58,148,221,204,171,249,219,219,165,224,13,60,122,127,225,136,102,20,21,0,52,93,104,131,123,116,117,215,1,195,189,18,202,
152,234,4,36,71,61,91,91,181,35,142,182,11,46,5,160,179,232,242,30,179,31,26,78,53,194,222,95,221,249,140,200,238,149,20,0,96,120,22,131,191,122,2,51,127,55,1,239,196,238,34,236,66,56,129,196,182,158,
54,150,99,97,176,27,32,37,68,4,238,248,17,90,78,246,240,232,107,12,48,111,27,114,20,90,13,33,81,100,52,117,59,107,171,45,111,178,33,206,200,195,117,46,217,27,111,172,223,155,249,90,57,223,203,196,163,
251,241,126,213,178,80,219,181,62,212,9,179,203,138,249,215,102,17,94,43,173,167,139,16,178,55,92,231,154,209,245,88,101,46,245,39,70,5,92,253,218,219,229,46,70,73,54,167,61,247,244,51,176,60,139,198,
251,90,209,254,241,238,188,43,206,112,38,30,71,190,112,26,83,175,220,216,179,209,87,44,203,170,114,185,196,183,166,0,196,3,241,228,127,33,237,252,217,162,134,222,239,64,220,31,83,5,237,77,13,102,85,153,
24,102,111,98,206,6,187,1,61,159,30,66,77,183,61,235,254,154,46,59,142,63,127,6,119,95,155,133,119,210,179,119,65,7,66,238,33,206,192,163,166,171,22,137,80,2,145,245,48,226,190,24,252,115,233,251,131,
16,77,142,106,73,181,53,179,12,34,189,103,226,129,184,106,158,61,111,224,192,153,120,196,253,81,68,55,162,72,4,147,247,27,179,203,10,222,156,126,176,14,220,241,67,222,69,96,213,214,81,91,248,160,29,98,
56,22,117,131,78,116,60,162,237,24,75,225,244,28,134,158,59,129,91,47,141,34,188,86,190,105,60,103,190,114,81,51,74,152,213,229,254,131,143,189,120,5,12,195,64,150,100,36,130,9,140,124,245,173,173,192,
246,254,171,237,171,71,215,39,119,214,89,73,14,150,146,179,63,240,6,30,131,159,29,70,96,222,135,141,27,110,68,61,17,72,66,122,136,145,165,37,127,36,108,227,166,27,158,241,53,101,219,80,107,64,207,103,
134,16,243,197,112,243,59,233,33,135,117,3,14,85,207,122,42,7,64,166,237,243,146,178,201,156,79,148,73,111,213,163,231,137,220,189,66,197,210,215,24,178,14,25,2,146,17,90,75,147,13,206,83,141,208,91,179,
143,68,72,169,27,112,160,110,192,145,156,187,186,25,165,209,0,132,236,147,108,61,15,249,116,127,178,23,98,188,180,127,160,214,54,27,132,168,128,208,82,0,82,92,82,61,168,197,183,146,43,25,236,70,232,173,
122,240,38,109,15,2,195,50,176,230,185,231,234,173,251,155,1,93,8,196,85,159,33,213,56,54,55,90,193,233,88,48,44,163,202,33,0,0,188,73,7,147,35,119,166,232,84,178,167,238,39,6,118,188,28,21,171,231,146,
243,251,139,204,56,175,183,233,113,236,215,79,97,115,198,11,223,164,7,81,111,84,245,251,150,247,189,246,40,41,213,169,127,121,63,88,62,251,181,56,3,139,187,63,188,189,39,239,147,15,103,228,114,254,158,
169,176,128,206,146,92,226,215,121,188,49,57,119,54,15,163,195,140,129,103,142,65,140,37,243,63,8,81,26,13,64,42,83,234,247,192,228,52,227,232,23,78,195,51,182,142,169,87,198,225,30,91,131,123,108,77,
115,124,239,83,71,10,182,71,247,90,108,51,162,26,82,175,175,53,192,100,226,225,190,190,174,154,174,219,241,104,143,170,231,247,242,31,190,1,89,80,255,118,25,157,102,232,108,249,219,167,174,51,185,151,
195,45,198,224,231,78,0,219,30,128,121,19,15,163,195,164,25,49,148,141,193,110,196,241,231,207,98,237,234,10,220,163,107,136,109,132,115,142,68,43,85,174,92,57,188,73,183,163,188,92,226,86,103,39,171,
99,1,57,217,1,154,11,199,179,123,190,50,15,203,115,176,54,89,225,60,213,4,199,209,134,202,90,107,146,236,187,61,251,118,217,218,107,97,107,223,121,52,208,117,182,25,174,44,107,106,115,70,30,174,179,205,
136,251,98,216,156,222,64,196,29,194,218,200,178,178,63,186,161,205,11,0,64,25,66,105,168,53,194,117,182,25,145,245,48,2,119,125,8,46,6,84,231,215,29,113,194,121,178,17,98,68,192,218,251,203,16,163,130,
106,127,138,37,79,86,225,124,82,15,238,123,197,88,103,130,177,46,255,242,41,132,144,242,209,219,75,255,247,121,228,243,39,33,68,18,24,249,79,111,33,234,9,99,252,69,237,144,209,166,11,109,104,190,191,45,
235,249,172,129,195,177,47,158,41,185,28,123,37,87,227,184,239,23,134,96,110,180,2,128,230,129,218,214,85,171,90,253,32,151,253,92,21,197,222,91,7,123,239,222,172,235,172,154,86,177,213,246,101,24,38,
153,115,6,44,24,150,5,203,49,74,46,26,157,89,15,150,207,104,169,49,108,193,92,54,185,48,12,3,150,99,148,149,116,178,174,106,147,193,228,176,224,200,231,79,238,238,13,139,192,25,184,130,157,5,132,84,18,
67,157,17,13,167,26,17,94,11,171,134,130,215,246,212,65,95,163,87,146,97,75,9,9,158,241,53,77,242,209,240,106,24,235,215,86,96,203,210,198,116,127,176,10,102,235,223,124,234,60,131,221,136,154,174,90,
88,154,107,84,35,14,182,203,213,6,55,55,153,209,112,170,17,129,133,0,162,238,48,54,111,111,168,18,195,102,235,252,231,13,233,169,110,182,246,26,72,130,128,205,153,77,36,2,49,108,76,172,67,191,152,12,38,
179,60,11,107,107,13,26,78,53,34,182,25,133,127,206,167,124,182,148,84,66,211,186,33,39,120,35,167,220,187,106,187,178,143,14,42,22,195,177,104,188,175,165,232,188,54,149,226,220,191,254,16,196,112,28,
87,254,179,54,161,120,74,211,133,118,52,93,200,63,221,131,144,82,84,236,250,15,122,171,30,61,79,14,98,115,218,131,205,233,13,248,231,124,240,207,101,79,176,149,141,169,193,130,158,39,7,177,58,178,136,
192,93,31,54,110,174,99,227,102,122,196,192,112,147,5,157,159,232,133,36,72,88,123,127,25,241,96,28,183,47,221,210,92,167,227,145,30,205,107,132,144,195,43,234,14,231,77,158,230,56,234,42,233,250,44,207,
194,57,236,66,34,42,192,183,45,25,156,209,105,134,181,201,10,115,198,242,121,246,129,122,152,93,102,120,110,172,67,22,228,172,101,51,59,44,48,55,91,149,237,192,221,77,196,252,49,8,177,109,75,167,110,157,
171,51,234,80,219,87,15,125,141,17,206,97,23,194,158,48,194,203,65,132,151,3,170,107,167,206,173,63,234,2,111,204,254,83,146,42,115,38,222,152,30,189,144,249,121,19,254,88,214,207,80,219,105,135,174,202,
215,112,79,132,226,120,247,15,180,25,190,155,31,108,67,199,35,201,172,217,169,41,104,31,124,227,50,34,238,48,222,251,227,159,106,142,119,12,55,168,18,37,238,68,243,131,237,104,126,176,29,179,151,38,177,
58,178,132,91,47,21,94,182,145,16,162,102,109,181,193,218,122,4,75,111,206,171,2,0,205,23,218,85,189,235,98,92,192,204,171,19,154,243,147,109,91,15,186,63,165,29,134,157,173,45,106,109,181,161,247,169,
35,0,144,51,0,144,203,255,207,222,157,7,55,146,221,119,130,255,102,34,113,3,36,64,128,247,125,21,235,96,221,213,213,167,164,150,187,165,110,89,45,171,109,183,173,211,178,60,211,99,77,132,229,181,189,214,
216,51,49,49,27,142,24,141,39,214,246,236,200,49,218,67,114,219,171,241,202,178,164,105,175,101,109,75,150,228,110,247,161,86,159,117,54,201,58,89,36,171,120,147,0,65,220,55,176,127,128,0,153,64,226,224,
133,131,248,126,34,58,186,18,121,224,225,37,152,200,252,189,247,126,207,50,100,131,101,200,150,154,57,197,17,192,210,155,115,219,218,223,126,178,21,246,147,173,169,108,254,222,176,44,57,157,218,168,198,
217,127,243,48,6,159,62,2,231,248,42,60,51,238,204,103,203,214,243,216,64,217,123,69,84,19,93,147,30,130,74,72,13,11,17,5,232,155,13,72,196,18,57,193,33,162,114,40,91,0,64,103,51,160,251,177,254,204,178,
185,196,200,95,246,126,249,228,155,203,210,212,217,160,184,191,166,49,53,190,95,16,133,130,199,55,247,89,160,183,27,50,173,85,217,239,165,54,168,101,251,155,20,166,60,36,162,131,163,88,54,120,235,191,
219,221,92,227,162,90,133,161,103,142,194,191,232,197,216,150,0,128,101,184,73,49,247,64,58,72,233,250,227,215,17,143,200,167,153,75,107,123,176,11,125,237,155,251,46,188,62,7,215,45,121,222,150,68,52,
142,201,231,175,195,208,110,194,137,161,38,152,58,205,24,122,230,40,22,223,156,197,221,69,31,86,175,44,99,245,74,238,131,249,224,199,71,242,118,245,206,87,230,66,159,215,55,239,85,252,12,35,159,26,133,
117,164,246,2,0,90,139,174,104,226,66,181,62,183,171,109,161,253,212,91,134,114,168,77,26,217,144,9,97,75,151,84,65,20,100,235,10,237,167,36,253,59,73,68,202,204,189,13,232,122,180,47,179,172,205,26,183,
174,210,168,100,235,179,25,59,204,80,233,84,48,117,21,190,119,212,55,111,206,18,99,25,105,130,218,180,25,68,149,12,165,37,148,203,222,79,137,166,64,144,213,126,178,37,167,156,91,135,58,25,90,13,5,63,107,
169,229,60,168,70,62,115,34,115,205,85,27,53,56,249,91,231,225,157,117,103,166,51,39,42,39,225,233,175,92,217,223,81,229,73,236,108,156,73,82,0,132,157,20,77,0,7,202,19,209,238,165,174,37,201,120,50,147,
172,173,20,218,141,161,58,97,215,102,246,120,81,163,202,204,28,2,0,238,59,107,240,76,111,182,226,180,62,208,149,147,15,36,226,141,96,249,237,205,150,26,115,175,165,96,198,222,185,87,102,144,204,51,111,
112,246,190,142,171,203,8,110,204,129,174,109,212,65,215,98,132,164,151,160,146,68,8,146,40,155,143,61,30,138,21,28,171,168,181,234,51,215,248,236,249,226,181,141,58,232,108,250,194,151,229,141,117,197,
234,89,109,214,236,217,184,250,170,182,211,223,76,34,34,218,115,2,4,36,145,68,216,21,66,60,188,153,167,196,176,209,187,77,16,132,172,36,138,169,31,181,136,39,44,251,237,212,55,27,83,1,90,65,128,144,76,
34,137,212,16,145,144,115,115,54,3,181,73,147,186,87,16,132,61,155,241,134,72,201,254,7,0,138,21,160,102,191,227,66,106,154,44,81,132,80,155,31,128,136,136,246,73,18,73,8,16,83,129,236,90,252,137,72,38,
81,214,20,230,68,180,33,185,209,8,86,233,114,236,80,18,72,10,73,8,53,251,1,136,14,190,162,67,0,90,205,46,124,249,201,191,220,209,193,151,188,77,248,15,63,250,23,5,183,73,63,59,187,167,92,112,223,89,67,
44,92,221,89,128,69,181,10,13,189,86,88,71,154,82,137,155,248,240,143,88,48,138,229,139,139,240,207,123,101,209,209,170,35,10,208,152,53,104,58,218,12,235,240,222,37,104,220,45,214,223,238,212,116,253,
149,220,97,41,185,37,80,42,228,60,151,41,77,225,148,61,61,81,62,53,93,127,85,76,216,56,185,177,64,141,214,47,31,254,1,240,239,99,183,88,127,59,33,32,232,12,96,246,197,59,112,79,185,17,143,84,113,189,1,
80,105,36,52,12,88,208,251,248,0,116,118,3,32,160,102,30,254,249,253,164,122,85,180,7,64,187,217,137,255,252,209,191,216,209,193,151,60,77,248,183,63,252,205,130,219,36,19,192,157,191,191,6,199,88,110,
166,232,106,214,56,96,197,200,167,143,23,156,71,186,30,4,157,65,92,251,198,21,68,189,185,243,87,87,179,150,115,237,123,50,221,227,110,177,254,118,135,245,183,59,172,191,253,197,250,173,109,60,127,187,
195,250,219,153,160,35,128,241,231,46,33,94,99,211,98,170,116,18,142,63,123,38,21,4,168,1,252,126,82,61,171,248,44,0,75,111,207,214,220,195,63,144,234,177,48,251,210,52,122,159,24,172,116,81,118,101,250,
133,219,136,111,204,205,45,153,53,69,19,118,101,155,250,222,245,154,187,120,2,192,202,133,69,52,246,55,193,118,172,121,91,251,45,189,51,15,223,61,229,217,40,88,127,165,155,123,121,70,54,238,109,43,125,
155,17,157,143,244,150,116,156,122,171,191,66,223,191,52,214,95,245,96,253,150,215,218,245,213,162,25,181,117,205,134,146,91,208,234,245,252,173,94,94,66,44,24,69,219,3,221,153,41,219,34,190,8,156,239,
109,38,1,53,117,153,97,238,41,156,204,185,94,234,111,245,202,146,108,218,187,82,88,134,109,232,120,88,121,154,183,217,23,239,212,220,195,63,144,202,23,115,239,165,105,28,250,196,206,102,40,41,183,122,
249,126,18,41,81,12,0,244,88,87,32,137,169,185,153,109,6,249,205,166,55,108,128,195,175,60,215,40,0,244,88,150,161,18,83,137,168,212,82,12,3,182,197,204,58,79,40,119,95,165,172,210,181,98,245,202,82,205,
7,0,92,55,86,17,241,165,230,131,213,219,244,192,54,30,96,35,158,16,188,179,158,226,27,86,41,231,248,202,182,47,160,190,123,30,197,121,205,1,214,223,118,184,239,172,193,59,167,252,217,45,65,43,80,194,3,
108,61,214,95,161,239,95,26,235,175,58,176,126,203,111,249,226,162,108,234,76,37,182,209,150,18,2,0,169,4,94,245,122,254,230,127,118,15,33,71,0,173,247,117,66,16,83,17,128,240,122,8,119,127,114,39,179,
77,199,35,61,5,3,0,245,244,253,15,185,130,219,158,154,79,107,205,63,195,134,123,170,244,41,175,171,141,123,170,240,223,95,181,168,167,239,39,145,18,197,0,192,239,127,224,187,104,212,249,20,119,184,56,
119,8,223,120,247,201,188,7,252,243,167,191,154,217,215,102,240,224,127,249,208,127,207,172,123,229,206,169,156,125,195,158,218,157,255,50,22,140,34,30,137,65,165,169,120,71,138,109,155,122,225,38,130,
75,126,196,130,155,25,74,195,238,48,38,158,187,4,83,87,3,122,159,44,254,32,27,241,70,246,179,136,251,110,47,34,191,35,159,30,133,164,147,48,241,87,87,88,127,37,152,123,121,6,238,59,107,8,172,164,50,208,
143,124,122,20,146,33,149,253,62,178,30,198,237,231,39,224,155,243,98,226,185,75,176,30,182,163,227,145,158,188,199,170,199,250,203,198,250,171,94,172,223,234,20,88,244,98,230,135,183,209,56,104,133,117,
36,223,148,157,66,93,158,191,229,11,243,8,174,4,16,245,111,126,246,120,36,134,217,23,167,101,175,1,169,94,144,51,63,188,13,219,241,22,152,187,115,27,133,234,177,254,246,74,181,143,249,47,36,30,142,87,
186,8,37,225,247,147,234,93,197,159,92,5,229,89,171,106,70,173,230,0,12,46,249,115,90,96,19,177,4,188,115,158,188,115,122,231,168,209,207,158,182,23,197,55,182,55,64,109,72,253,25,177,254,138,11,57,131,
178,239,157,177,189,1,26,115,234,1,54,164,79,13,9,136,133,99,240,206,121,160,111,53,42,30,99,87,5,168,34,123,245,253,99,253,85,169,170,47,96,97,53,94,252,188,130,206,32,130,206,121,136,26,85,129,0,0,106,
190,2,118,82,252,181,27,206,156,30,20,241,72,2,75,239,204,231,108,235,95,240,194,191,224,133,190,197,168,24,0,168,199,250,163,26,82,227,39,184,198,139,79,85,160,34,1,128,136,39,12,201,164,129,40,214,70,
150,208,82,120,166,215,21,51,113,43,81,105,37,24,90,12,37,207,105,237,189,183,142,181,155,78,132,214,130,72,236,48,186,218,249,254,94,52,244,89,48,253,131,91,112,93,119,100,90,254,79,252,235,115,144,54,
230,31,15,187,130,152,248,203,203,112,207,184,113,233,207,222,128,253,100,43,122,62,52,8,215,237,53,44,189,57,155,57,150,222,110,64,223,207,15,239,168,28,213,40,228,8,96,250,135,183,11,110,147,174,63,
37,130,74,196,153,47,61,196,250,43,160,80,253,165,105,173,6,156,249,210,67,153,101,81,157,234,122,202,250,43,173,254,242,97,253,109,16,5,168,141,26,152,186,204,176,31,107,129,100,80,111,235,125,130,206,
32,162,158,112,209,235,188,32,2,13,125,214,109,29,187,154,37,227,73,120,238,150,222,189,89,210,73,48,180,24,33,148,152,32,55,176,232,195,234,248,50,66,171,1,36,98,59,107,17,232,126,172,31,166,206,6,116,
63,218,135,182,243,29,178,117,241,96,28,147,127,127,29,58,187,1,189,31,30,128,247,174,27,11,63,155,197,218,181,85,4,87,252,104,61,223,9,203,80,19,150,223,158,199,218,77,7,4,65,192,225,95,59,177,163,114,
84,163,36,128,27,127,125,181,224,54,233,250,75,235,127,234,16,52,13,26,8,146,0,108,52,52,166,235,47,109,237,218,170,108,8,103,186,254,0,160,249,116,59,116,5,186,184,215,154,213,43,75,112,188,151,59,92,
181,249,84,27,236,39,90,51,203,67,191,120,24,246,19,109,5,143,229,158,113,225,250,127,223,60,31,235,119,214,176,248,179,212,245,217,220,213,128,174,159,235,223,163,82,87,158,111,222,131,217,151,166,75,
222,94,148,68,232,91,12,176,141,182,193,216,86,36,128,157,37,153,72,150,118,127,44,10,165,55,210,212,128,100,2,72,148,56,123,129,74,39,213,238,212,146,180,231,20,3,0,47,221,62,3,189,90,185,123,201,164,
179,35,231,53,207,204,58,12,45,198,146,111,168,214,111,173,161,233,120,51,68,109,197,59,32,236,153,91,223,30,223,214,20,134,162,36,194,118,188,5,221,143,13,64,179,241,0,158,45,22,136,97,242,255,189,134,
245,34,99,26,75,209,124,38,245,163,20,15,198,51,99,254,129,212,5,65,173,75,157,135,248,198,255,147,241,4,34,190,8,98,27,73,104,162,158,48,220,83,174,204,62,241,72,109,116,241,42,85,44,20,147,125,62,37,
233,250,203,71,99,210,100,46,194,172,191,92,153,250,83,9,16,84,34,146,137,68,106,174,224,120,2,201,45,55,253,106,157,132,164,32,64,84,109,254,74,177,254,242,127,255,182,214,95,50,177,241,96,42,0,130,40,
66,216,8,176,178,254,228,28,87,151,48,247,226,52,250,126,126,8,246,147,133,255,174,1,192,57,190,138,185,87,166,17,116,40,39,173,204,38,25,212,56,247,7,15,151,92,158,106,23,15,199,112,189,200,3,100,54,
149,70,133,230,51,237,232,254,96,127,222,155,237,100,44,129,233,127,188,141,149,75,139,187,110,206,106,127,40,149,76,205,212,213,144,179,46,253,123,39,233,36,88,15,217,17,143,164,254,94,66,107,65,132,
214,130,176,28,74,229,3,8,172,250,225,158,114,149,60,125,102,205,72,38,139,254,125,164,235,47,173,161,207,2,125,86,38,247,116,253,165,5,86,228,127,15,233,250,75,239,127,144,2,0,161,181,160,98,29,154,123,
229,61,31,98,129,24,194,238,48,52,38,117,78,0,44,153,72,34,226,137,228,12,165,136,108,185,62,139,210,193,121,48,5,128,168,63,178,173,107,51,0,184,110,57,177,240,179,89,180,158,237,64,223,71,134,32,168,
242,7,18,227,193,24,22,222,152,197,218,181,21,4,215,130,37,93,71,12,237,38,156,248,194,185,109,149,169,154,5,151,125,120,239,107,23,74,218,86,16,5,232,91,141,104,57,217,134,214,115,29,37,7,105,233,96,
82,124,2,255,254,196,67,74,47,43,90,185,184,136,233,31,220,196,233,255,185,244,125,40,213,93,124,245,242,18,214,39,93,56,246,235,39,115,166,77,73,68,227,184,246,215,87,16,88,82,206,197,176,87,46,127,229,
173,125,61,62,209,86,67,191,120,24,67,191,120,24,19,207,93,130,119,206,163,248,253,179,12,90,113,248,215,78,86,160,116,181,71,177,254,6,88,127,197,196,194,49,76,254,253,13,36,19,64,243,233,252,65,128,
217,23,167,48,255,250,189,50,150,236,96,136,71,226,88,122,107,14,238,59,107,56,250,249,83,80,27,179,130,220,73,96,242,123,215,225,28,95,173,76,1,137,246,193,204,143,39,49,243,227,73,28,251,141,83,48,247,
202,123,108,133,221,33,92,249,243,183,43,84,178,26,147,4,150,47,44,32,30,138,99,232,153,35,138,155,4,86,124,184,241,205,49,68,60,28,11,95,170,100,34,137,192,162,15,51,139,147,88,125,111,25,35,159,62,158,
183,1,146,14,190,93,133,127,98,161,40,52,22,45,70,62,125,60,211,138,76,219,19,245,134,113,243,219,227,72,196,229,161,203,249,215,238,237,251,195,63,0,232,154,244,208,217,12,208,217,12,5,179,210,18,237,
37,173,69,151,249,222,101,127,255,226,145,4,66,142,0,162,190,218,78,210,83,110,162,74,128,206,102,128,166,97,227,239,56,221,195,34,193,209,130,249,204,252,227,237,188,223,51,231,248,10,31,254,119,41,184,
26,192,228,223,93,207,121,221,117,195,193,135,127,58,48,180,22,29,204,189,22,168,55,30,166,252,75,126,120,102,220,178,255,124,243,94,0,169,94,151,230,94,11,244,54,67,161,67,18,0,199,248,50,92,27,195,74,
182,138,5,98,124,248,223,37,255,130,23,183,191,61,142,100,141,231,97,163,157,219,213,83,187,164,83,195,50,216,180,237,253,212,13,154,76,247,212,131,162,161,207,130,120,180,180,174,181,225,245,16,66,107,
193,204,114,208,17,128,115,108,25,205,167,82,45,81,201,4,176,124,113,65,182,143,185,215,130,182,243,157,144,244,59,59,101,250,22,229,31,155,163,191,113,122,51,137,152,51,128,43,255,237,157,156,109,26,
15,53,225,200,231,54,91,20,85,7,104,232,6,0,232,155,13,178,207,167,184,77,158,250,43,5,235,47,183,254,134,158,57,154,179,77,250,251,231,157,117,227,202,87,223,65,203,217,118,12,124,108,132,245,135,210,
190,127,90,139,14,39,127,251,124,102,57,22,138,193,191,232,133,206,166,175,251,250,3,0,36,146,240,47,249,48,247,234,12,18,209,212,93,79,60,18,199,234,213,101,197,249,184,231,94,150,143,93,21,36,17,230,
46,115,102,90,180,124,164,3,22,12,23,84,2,26,7,74,207,105,16,116,4,100,55,230,238,41,23,60,51,110,52,244,109,118,151,94,202,250,125,211,219,13,232,122,180,31,146,97,103,117,103,108,51,1,0,110,126,103,
28,158,59,242,46,199,233,148,13,254,121,47,222,253,227,159,102,2,98,109,15,118,161,251,131,125,16,84,169,110,215,237,15,116,161,233,104,51,14,220,32,89,1,69,255,62,210,245,151,54,246,181,11,153,161,16,
217,41,47,214,174,173,226,206,247,110,228,52,90,108,214,31,160,179,234,16,245,71,113,80,52,159,106,83,204,193,146,14,90,183,156,110,71,203,233,118,64,181,221,193,0,0,32,0,73,68,65,84,76,254,253,117,56,
174,46,99,230,31,243,231,36,49,182,155,112,244,215,79,101,150,45,195,182,204,249,73,207,232,114,80,152,187,26,74,187,54,111,136,5,162,152,125,121,6,33,231,230,240,146,229,11,11,57,201,58,23,222,184,155,
243,240,47,136,2,196,18,198,246,31,164,241,255,0,0,17,80,149,248,92,16,15,197,100,195,36,188,115,30,56,199,150,97,63,217,154,127,39,58,176,182,253,107,123,162,253,14,30,63,116,41,239,122,131,102,115,90,
63,87,192,140,111,188,251,145,204,178,35,96,6,0,88,15,21,155,131,183,246,28,250,212,104,201,219,38,147,73,220,249,222,77,56,174,46,101,94,115,221,114,102,2,0,161,181,0,98,129,205,31,79,181,81,141,35,159,
61,145,73,138,86,110,90,179,22,90,179,182,34,239,93,14,42,173,180,173,27,220,28,201,212,188,246,225,141,105,89,36,131,4,99,135,25,250,230,84,18,27,214,223,166,192,178,15,209,45,211,239,52,244,89,138,142,
67,99,253,229,215,208,215,8,81,37,98,253,142,11,177,72,2,238,201,53,72,6,53,140,29,102,72,250,93,126,175,107,196,118,234,175,113,168,9,130,36,226,238,143,38,51,175,121,231,220,0,228,1,128,160,35,128,160,
115,51,72,43,74,34,142,61,123,118,219,137,169,14,2,149,86,218,214,77,124,50,150,192,141,111,141,201,198,254,186,110,59,100,1,0,95,214,12,52,135,62,57,154,51,230,124,39,18,209,68,222,28,23,201,100,18,241,
72,28,130,74,132,164,87,67,173,83,203,166,240,213,217,13,57,67,241,14,2,1,165,7,112,36,173,10,146,94,141,120,40,134,68,186,105,80,0,36,189,26,42,93,234,193,41,145,72,213,163,40,137,80,233,213,16,55,174,
223,217,245,119,144,2,0,186,38,61,116,77,250,162,219,53,244,88,0,8,112,223,89,203,233,89,164,210,168,96,61,210,12,67,179,252,59,166,49,105,14,108,55,108,201,160,65,227,192,246,62,155,190,217,128,247,254,
207,205,49,237,233,158,19,91,57,198,86,100,203,109,247,117,162,231,137,193,204,119,177,158,24,90,77,184,239,15,31,41,105,219,84,94,177,235,88,159,116,102,94,115,140,51,0,80,175,182,29,0,176,25,189,56,
209,126,167,164,109,195,49,53,174,46,14,20,223,176,206,8,130,128,182,243,157,178,0,64,216,181,25,56,73,103,232,79,211,53,25,42,246,240,79,197,37,19,9,92,255,230,123,153,101,83,187,25,135,63,203,49,216,
74,22,126,58,11,199,248,102,54,229,51,191,255,80,166,7,10,109,223,208,47,31,131,218,32,225,237,255,248,26,162,222,48,174,127,243,61,230,80,40,194,212,33,111,237,140,249,115,147,183,70,214,229,173,75,230,
158,198,186,124,248,223,9,65,18,209,114,166,67,22,0,8,187,54,235,51,153,76,166,90,162,210,219,11,194,158,60,252,151,170,233,136,29,195,10,61,144,8,24,254,149,99,0,128,43,95,125,7,161,141,164,151,106,163,
6,103,191,148,155,227,169,237,129,46,244,60,206,251,187,173,90,206,182,163,229,108,59,38,254,234,74,78,0,64,50,170,49,244,139,135,43,84,178,218,97,104,201,186,62,103,221,15,39,162,9,68,220,155,215,19,
81,18,209,251,196,32,19,218,149,64,50,72,232,125,98,80,22,0,40,53,185,45,29,60,7,171,175,98,13,81,105,228,23,43,217,244,71,217,67,118,15,88,143,196,131,196,113,117,57,211,165,76,210,74,104,58,222,12,189,
61,253,160,144,4,79,158,92,195,128,5,162,78,132,235,134,19,81,95,4,142,171,203,144,54,90,150,210,45,70,154,6,45,44,135,154,54,90,83,168,40,65,68,203,185,118,196,67,113,56,199,87,16,118,135,177,114,97,
1,250,22,3,204,172,67,5,217,127,147,185,57,18,18,9,121,43,242,65,203,206,189,223,68,141,188,142,147,59,156,222,111,187,244,77,122,196,218,205,5,183,209,89,138,183,228,214,59,67,139,17,170,141,105,138,
37,163,252,54,81,173,83,195,216,110,134,166,225,224,246,202,218,173,150,211,109,104,236,151,95,123,75,237,166,93,247,138,92,158,179,123,248,168,180,42,62,252,111,67,246,108,109,137,3,54,43,16,149,142,
87,36,162,93,184,247,226,102,111,24,181,73,141,129,167,70,182,172,229,195,127,182,150,51,237,104,57,211,142,137,165,75,136,250,34,178,250,75,51,52,27,178,234,145,10,17,68,96,224,169,17,132,156,1,56,199,
87,16,116,4,48,245,194,45,180,156,109,103,0,128,234,138,237,120,139,226,88,237,173,52,141,124,112,205,22,88,244,33,228,218,28,242,98,31,109,145,173,95,187,182,153,176,81,211,168,197,241,47,156,45,91,217,
106,201,202,165,5,120,239,201,135,183,8,130,128,129,143,243,247,140,136,170,203,182,3,0,175,77,157,192,207,166,143,229,93,255,167,31,251,26,26,117,169,236,245,173,13,46,252,197,175,252,89,102,221,171,
83,39,241,205,139,31,218,65,49,105,175,216,142,55,67,223,182,217,221,114,107,66,20,181,65,131,238,199,251,51,203,198,182,194,45,41,245,40,187,254,182,82,235,212,138,175,83,174,214,251,58,97,57,172,156,
11,132,45,116,249,241,239,151,40,191,185,87,239,194,61,185,86,112,27,219,104,11,135,0,100,89,186,184,128,149,11,11,197,55,4,235,175,16,207,93,55,28,87,151,229,47,10,96,0,128,136,170,206,182,3,0,241,132,
136,120,137,179,7,10,72,66,173,218,28,235,39,137,10,93,77,84,181,221,74,42,22,201,8,93,109,172,35,246,156,140,170,105,42,189,132,206,71,122,75,62,150,168,170,173,207,158,77,216,65,249,11,213,223,118,213,
99,253,165,237,69,210,153,122,172,63,254,253,110,218,205,247,175,28,88,191,181,141,231,111,119,234,169,254,86,175,44,97,245,202,146,242,120,234,36,112,237,27,87,160,49,107,48,244,203,165,5,78,84,26,9,
241,72,110,110,146,90,32,213,200,44,51,245,244,253,36,82,178,227,191,212,88,40,138,75,255,229,205,204,242,233,223,125,0,106,227,246,147,121,233,109,6,120,3,238,157,22,163,162,180,22,109,93,39,231,211,
217,245,16,37,81,158,191,160,134,84,58,169,23,235,111,119,88,127,187,195,250,219,95,172,223,218,198,243,183,59,245,84,127,33,87,16,158,153,245,188,235,61,51,235,153,41,3,75,209,48,96,129,235,134,163,228,
237,171,73,227,112,109,204,60,83,79,223,79,34,37,138,1,128,30,235,138,114,107,61,0,79,200,0,135,191,17,66,82,200,204,165,188,27,29,15,117,227,230,119,106,51,0,208,245,104,127,241,141,14,48,81,173,66,251,
131,221,152,255,233,221,74,23,101,219,84,26,9,109,15,116,85,180,12,172,191,221,97,253,237,14,235,111,127,177,126,203,175,237,190,14,88,135,55,135,22,221,253,241,36,146,137,84,22,49,173,69,135,246,7,187,
161,183,149,54,196,168,158,206,159,125,180,5,134,230,205,7,138,249,215,238,34,234,143,160,239,137,33,64,76,245,210,12,175,135,176,248,230,108,201,199,172,167,250,75,235,125,98,16,77,135,155,113,251,249,
107,240,205,123,112,236,95,158,134,218,164,193,149,63,127,123,123,199,121,124,0,158,153,117,217,108,25,181,64,50,72,232,253,240,80,165,139,81,146,122,252,126,18,109,165,24,0,248,253,15,124,55,51,142,63,
219,43,119,78,225,27,239,62,185,103,5,176,30,177,163,239,201,33,220,123,113,170,102,34,113,130,74,68,215,163,189,104,62,213,86,233,162,84,92,215,7,251,145,136,39,176,252,246,28,18,241,220,108,218,213,
72,111,55,96,240,23,15,67,103,173,252,88,115,214,223,238,176,254,118,135,245,183,191,88,191,229,149,61,60,230,238,63,221,1,54,2,0,106,147,6,109,247,119,110,235,120,245,114,254,26,250,44,178,228,137,75,
239,206,35,234,143,160,229,92,71,166,151,163,119,206,179,173,0,0,80,63,245,151,166,54,168,161,181,234,50,221,179,181,13,58,168,27,182,223,51,86,103,55,224,248,179,103,112,247,165,41,120,166,92,136,135,
171,59,83,187,74,171,130,101,184,9,189,31,30,170,169,217,33,234,237,251,73,180,213,142,135,0,8,106,17,29,143,116,103,150,85,154,157,79,147,212,246,64,23,108,199,91,224,153,118,87,125,196,83,212,137,104,
232,105,132,166,161,244,238,92,7,153,32,2,189,31,30,68,231,35,61,8,44,251,145,76,86,247,69,84,210,73,48,180,153,33,84,201,200,13,214,223,238,176,254,118,135,245,183,191,88,191,149,49,253,194,45,68,60,
97,96,151,55,245,60,127,187,195,250,219,57,157,221,128,145,79,140,86,186,24,7,26,191,159,84,207,118,28,0,16,37,17,61,143,15,238,89,65,212,70,13,108,163,205,123,118,60,42,47,201,160,70,67,63,167,28,219,
41,214,223,238,176,254,118,135,245,183,191,88,191,229,229,158,89,71,72,41,33,219,14,241,252,237,78,189,214,95,216,27,174,250,135,74,170,223,239,39,213,55,197,0,192,75,183,207,64,175,14,3,0,12,234,16,62,
48,120,53,179,174,219,178,130,159,63,156,127,60,147,86,21,205,252,219,31,213,225,181,59,39,51,203,147,206,142,93,23,152,136,136,136,40,159,145,79,29,71,50,30,199,216,215,46,33,25,79,13,45,12,44,249,240,
222,255,241,46,44,195,77,232,249,208,222,53,94,28,100,99,95,191,8,97,99,162,166,90,25,162,89,77,38,158,187,84,233,34,16,17,41,82,12,0,124,127,226,161,204,191,219,205,78,89,0,96,208,182,128,65,91,105,243,
197,122,131,6,124,231,202,7,119,89,68,34,34,34,162,210,100,18,253,109,153,101,56,17,75,32,176,226,135,190,133,217,179,75,21,92,245,87,186,8,53,65,107,209,193,220,107,129,218,168,60,254,221,220,107,129,
214,188,253,92,0,68,68,251,165,54,38,236,36,34,34,34,42,224,230,119,198,225,185,227,202,44,39,217,106,189,35,39,190,112,14,201,100,2,23,254,228,141,76,29,154,58,205,56,242,235,39,33,112,0,114,142,150,
211,237,104,57,221,174,188,82,0,142,253,198,169,242,22,136,136,168,8,6,0,136,136,136,168,230,37,162,9,196,35,202,25,211,5,81,128,74,43,65,165,225,109,79,49,169,204,255,34,212,122,9,137,88,106,12,187,74,
207,186,43,149,101,216,10,173,53,149,40,90,16,138,108,76,68,84,1,69,175,230,107,193,6,252,215,87,127,117,71,7,15,197,248,99,65,68,68,68,149,101,236,48,99,244,217,51,149,46,70,77,8,174,250,145,136,38,48,
242,169,227,153,215,118,51,211,211,65,231,153,89,135,103,102,29,77,71,236,48,180,154,208,249,190,222,156,109,226,161,24,22,223,154,131,206,170,131,253,36,167,144,38,162,202,42,250,132,30,142,169,113,117,
113,160,28,101,33,34,34,34,218,17,125,147,30,177,118,179,242,58,59,231,205,46,213,205,239,76,228,204,162,96,234,106,96,0,37,15,247,180,11,243,175,222,133,206,170,131,161,213,164,184,77,52,24,197,220,43,
51,104,232,183,48,0,64,68,21,183,227,38,250,176,59,136,233,23,110,103,150,181,22,29,250,63,122,104,79,10,69,68,68,68,180,29,125,63,63,12,0,112,79,186,16,143,196,100,235,36,131,186,18,69,170,41,222,89,
55,162,222,8,226,225,220,97,20,241,96,20,107,215,86,161,105,212,194,212,217,80,129,210,85,191,229,139,75,112,79,175,43,174,139,71,152,143,130,136,170,199,142,3,0,137,72,2,235,183,215,50,203,250,102,102,
214,37,34,34,162,202,154,254,209,109,182,96,239,192,220,171,119,225,158,92,83,92,23,116,6,113,235,187,19,176,141,182,96,248,153,163,101,46,89,109,240,222,91,135,247,94,165,75,65,68,84,28,7,233,19,17,17,
81,205,91,187,190,138,176,43,132,120,48,150,179,46,226,13,99,241,141,89,232,154,13,176,14,219,42,80,186,218,209,124,186,13,146,78,141,165,183,103,33,168,68,180,158,235,68,212,27,129,99,124,185,210,69,
35,34,162,61,192,249,92,136,136,136,168,230,45,95,92,196,221,159,220,65,212,31,201,89,23,113,135,113,247,39,119,224,184,202,135,216,98,58,30,238,65,239,19,131,128,40,66,165,149,208,251,196,32,90,31,232,
172,116,177,136,136,104,143,176,7,0,17,17,17,29,24,157,239,239,133,218,168,145,189,22,94,15,97,241,205,217,10,149,136,234,65,239,19,131,104,58,220,92,112,27,65,205,118,55,34,170,60,6,0,136,136,136,232,
192,176,159,104,133,222,110,144,189,230,157,243,48,0,64,251,74,109,80,67,107,213,85,186,24,68,68,69,49,0,64,68,68,68,68,57,98,161,24,110,126,107,12,177,80,110,94,5,74,233,254,96,63,186,31,237,71,44,24,
69,120,61,12,141,73,13,65,98,75,63,17,85,47,94,161,136,136,136,136,40,71,50,150,128,235,150,19,222,123,238,74,23,165,186,9,192,204,143,39,113,249,43,111,194,55,239,169,116,105,136,136,10,98,15,0,34,34,
34,58,48,110,253,237,24,4,149,188,125,35,17,227,60,236,197,12,60,117,8,241,72,12,58,75,110,55,118,67,171,9,67,191,124,24,146,142,183,141,217,194,235,97,132,215,67,153,228,147,254,37,63,146,73,1,230,46,
51,4,73,132,103,198,13,81,45,192,212,217,80,225,146,18,17,165,240,74,78,68,68,68,7,70,208,25,172,116,17,106,146,86,225,193,63,77,84,139,48,180,152,202,88,154,218,177,114,121,1,243,175,222,205,44,207,252,
227,109,0,192,153,223,123,16,234,6,13,174,125,227,50,180,86,29,78,255,206,3,149,42,34,17,145,12,3,0,68,68,68,84,243,70,62,57,138,100,34,129,241,175,93,204,9,2,152,58,205,56,242,235,39,33,8,28,249,88,76,
60,20,67,50,145,196,169,47,222,15,32,9,0,28,211,94,2,115,79,35,180,86,61,220,119,214,16,245,229,78,69,73,68,84,45,24,0,32,34,34,162,154,39,74,34,0,17,146,94,13,73,47,79,90,167,210,75,80,105,120,203,83,
138,177,231,46,33,228,8,200,94,51,117,53,96,244,217,51,21,42,81,109,104,61,219,14,251,201,54,76,252,213,21,6,0,136,168,170,241,215,144,136,136,136,14,140,129,143,143,32,17,205,29,243,239,95,240,66,210,
115,170,182,124,66,107,193,84,235,191,66,190,132,68,36,206,250,35,34,58,32,24,0,32,34,34,162,3,227,230,119,38,114,90,176,211,108,163,45,24,126,230,104,153,75,84,27,166,127,120,27,238,201,53,197,117,129,
21,63,198,190,126,145,245,71,68,116,0,48,0,64,68,68,68,53,207,59,235,70,212,27,65,60,28,175,116,81,106,90,227,144,21,42,181,4,215,13,7,160,18,96,29,182,33,22,140,194,51,179,94,233,162,85,181,229,139,75,
112,79,175,35,180,150,10,62,221,253,201,36,68,181,170,194,165,34,34,202,197,0,0,17,17,17,213,188,185,87,239,230,109,193,166,210,245,61,57,12,189,221,128,183,191,252,26,36,157,132,67,159,56,6,239,156,7,
19,207,93,170,116,209,170,154,247,222,58,188,247,54,151,157,19,171,149,43,12,17,81,1,12,0,16,17,17,209,129,209,124,186,13,146,78,173,184,206,216,206,169,236,168,140,4,224,232,231,78,65,80,115,22,5,34,
170,30,12,0,16,17,17,209,129,209,241,112,15,244,118,67,165,139,65,4,0,104,232,183,84,186,8,68,68,50,12,0,16,17,17,17,81,142,120,56,134,153,31,222,70,212,207,105,237,242,233,120,176,27,45,167,218,149,87,
10,229,45,11,17,81,41,24,0,32,34,34,34,162,28,137,104,2,75,239,204,87,186,24,85,105,245,242,18,238,252,195,13,116,127,176,31,157,31,232,205,188,62,241,127,95,129,247,174,60,97,162,206,170,199,169,223,
185,191,220,69,36,34,82,196,0,0,17,17,17,29,24,211,47,220,130,74,163,156,125,221,220,107,65,199,195,221,101,46,81,109,232,126,180,15,109,231,59,160,105,208,230,172,211,217,13,232,253,240,0,52,230,220,
117,245,42,137,164,236,255,177,64,20,241,72,2,201,88,34,239,182,68,68,213,128,1,0,34,34,34,58,48,10,77,87,39,230,9,12,16,96,234,106,200,187,78,210,73,176,30,178,151,177,52,181,103,230,199,147,112,92,93,
174,116,49,136,136,138,98,0,128,136,136,136,136,100,78,124,225,44,146,201,84,203,181,40,49,112,82,42,99,155,17,162,86,62,11,133,214,172,169,80,105,136,136,114,49,0,64,68,68,68,68,0,128,177,175,93,68,200,
25,0,0,168,77,26,156,250,159,56,118,125,59,250,62,50,12,115,47,51,255,19,81,245,98,0,128,136,136,136,106,222,208,211,135,145,80,24,127,189,149,168,102,75,118,62,241,72,12,201,88,18,137,72,12,241,72,28,
0,32,134,227,136,5,162,16,84,34,84,90,214,157,18,255,146,15,171,87,150,17,94,11,85,186,40,68,68,37,97,0,128,136,136,136,106,222,228,247,110,192,61,185,86,112,27,219,104,11,134,159,57,90,166,18,213,150,
91,223,189,150,83,127,81,127,4,23,254,228,103,48,117,53,96,244,217,51,21,42,89,117,115,93,119,192,117,221,81,233,98,16,17,149,140,1,0,34,34,34,34,2,0,232,155,141,16,37,17,0,144,76,36,17,88,246,85,184,
68,213,201,212,102,70,215,7,250,224,158,89,151,77,251,183,114,101,9,238,105,121,34,74,149,94,66,251,253,93,229,46,34,17,145,34,6,0,136,136,136,136,8,0,112,232,19,199,160,183,27,0,0,17,95,4,151,254,236,
141,10,151,168,58,25,218,77,48,180,155,144,124,121,90,22,0,88,189,188,148,179,173,214,170,99,0,128,136,170,6,3,0,68,68,68,84,243,26,122,26,161,202,51,198,63,22,140,22,156,30,144,104,167,108,135,155,161,
179,232,177,114,105,1,222,89,79,165,139,67,68,84,20,3,0,68,68,68,84,243,58,223,223,155,119,157,119,206,131,137,231,46,149,177,52,84,47,210,61,1,220,51,46,6,0,136,168,38,48,0,64,68,68,68,68,0,128,213,43,
139,80,27,82,243,214,167,103,3,136,120,195,88,124,99,54,179,141,169,203,12,115,15,167,186,219,170,243,125,189,104,57,213,174,184,78,80,139,101,46,13,17,81,126,12,0,16,17,17,17,17,0,96,225,245,217,156,
215,34,238,48,238,254,228,78,102,185,227,145,30,6,0,178,232,237,134,76,238,4,34,162,106,198,0,0,17,17,17,213,188,229,11,243,8,174,4,20,215,69,253,145,50,151,134,136,136,168,58,49,0,64,68,68,68,53,111,
237,134,51,103,30,123,34,34,34,146,99,0,128,136,136,136,14,52,157,221,128,222,15,15,64,99,214,86,186,40,85,171,251,209,62,180,157,239,40,105,91,93,19,187,186,19,17,213,42,6,0,136,136,136,232,64,147,116,
18,172,135,236,149,46,70,85,51,117,53,84,186,8,68,68,84,6,12,0,16,17,17,81,205,27,120,234,16,226,145,152,226,58,81,82,149,185,52,68,68,68,213,137,1,0,34,34,34,170,121,90,139,46,239,58,223,188,23,239,254,
241,79,209,116,180,25,131,79,31,46,99,169,136,136,136,170,11,39,38,37,34,34,162,3,45,153,76,34,30,137,35,17,75,84,186,40,68,68,68,21,197,0,0,17,17,17,17,17,17,81,29,224,16,0,34,34,34,58,48,130,171,126,
36,162,242,150,254,144,35,8,0,136,133,162,240,47,120,161,49,107,160,230,140,0,68,68,84,135,24,0,32,34,34,162,3,227,230,119,38,16,114,4,20,215,185,39,93,24,155,188,136,142,71,122,208,243,248,64,153,75,
70,68,68,84,121,12,0,16,17,17,81,205,243,206,186,17,245,70,16,15,199,43,93,20,34,34,162,170,197,0,0,17,17,17,213,188,185,87,239,194,61,185,86,233,98,16,17,17,85,181,178,5,0,252,75,126,44,190,126,175,232,
118,253,31,59,4,149,150,243,245,18,17,81,237,243,206,122,144,40,210,34,173,177,234,160,183,233,203,84,162,131,175,249,116,27,36,157,90,246,90,212,27,129,99,124,25,58,187,1,214,97,27,26,122,45,21,42,29,
213,178,176,43,132,185,87,167,51,203,150,33,59,108,163,205,153,229,165,55,231,224,95,246,102,150,7,62,54,2,65,197,124,219,68,84,93,202,22,0,136,250,66,112,140,47,23,221,174,247,201,65,6,0,136,168,106,
68,60,33,204,189,118,183,228,237,251,158,24,134,168,230,13,31,165,76,253,195,13,4,243,140,71,79,235,120,164,27,61,143,15,150,169,68,7,95,199,195,61,208,219,13,178,215,188,115,30,56,198,151,97,108,51,161,
247,9,214,53,237,76,52,16,193,234,149,205,123,89,181,81,35,11,0,172,223,113,97,125,210,153,89,238,255,232,8,4,222,210,30,8,174,155,14,132,61,225,130,219,232,109,6,52,14,88,1,0,158,153,117,4,86,253,153,
117,246,19,173,144,180,242,199,174,136,47,130,181,235,171,153,101,83,187,25,166,174,134,61,44,53,145,178,138,13,1,104,61,215,9,251,201,214,204,242,212,247,111,32,184,26,192,141,111,141,65,165,81,225,232,
231,79,237,234,248,222,57,15,238,253,104,114,243,253,206,119,194,126,162,181,192,30,249,205,190,60,13,207,29,87,102,249,240,103,78,64,165,231,232,9,162,122,16,245,71,177,114,97,177,228,237,123,63,52,180,
143,165,161,90,38,74,162,236,119,47,236,10,193,61,229,130,127,201,143,149,11,139,48,247,53,230,60,184,150,219,202,229,69,96,163,195,130,218,164,134,245,176,189,162,229,33,58,8,130,142,0,166,95,184,153,
89,182,143,182,162,229,92,7,0,224,222,139,83,240,205,185,51,235,142,124,246,36,4,169,122,130,200,75,111,205,97,237,198,230,67,234,224,211,71,161,181,212,223,12,26,75,111,207,195,61,229,42,184,141,253,
120,75,38,0,224,120,111,5,43,151,22,50,235,26,7,154,114,2,0,97,87,16,51,63,184,157,89,238,124,95,47,3,0,84,22,21,123,138,213,90,180,48,119,111,126,201,85,154,84,81,252,11,94,136,123,112,225,139,135,162,
240,206,121,50,203,187,185,137,9,57,3,178,99,37,226,9,48,160,75,84,159,154,142,52,163,245,108,123,222,245,162,186,250,175,14,115,175,204,192,187,229,134,19,0,84,26,53,14,253,234,209,10,149,168,62,168,
180,18,6,62,54,146,89,118,142,175,192,61,229,130,123,114,13,238,201,53,244,63,53,92,241,0,192,204,15,110,35,17,75,77,161,103,234,108,96,0,128,104,15,196,195,49,120,102,54,175,185,166,206,205,251,223,192,
146,95,182,46,153,4,132,178,150,174,176,160,35,40,43,95,34,202,36,155,0,82,179,136,8,169,51,21,94,15,98,249,221,5,248,23,125,184,251,79,119,208,216,111,173,112,233,136,10,219,69,0,32,251,242,148,220,85,
65,242,241,76,175,99,242,239,174,229,93,127,248,51,39,96,104,55,33,17,77,224,202,159,191,149,121,61,17,151,151,103,254,181,123,88,122,107,174,232,126,217,58,63,208,183,243,194,23,144,204,170,46,97,75,
117,10,42,121,221,166,111,198,136,168,242,52,22,45,26,135,154,42,93,140,93,241,47,248,224,158,148,183,100,212,75,175,166,120,214,252,240,162,226,248,220,242,252,190,21,178,244,214,28,162,190,168,226,58,
125,155,17,246,209,22,0,192,218,13,39,252,91,2,212,74,52,22,13,90,207,117,34,245,57,202,240,104,145,93,93,91,127,223,32,64,80,137,72,198,19,27,155,38,145,136,38,246,100,216,76,247,163,125,104,59,223,1,
77,67,110,235,164,193,110,192,200,167,71,161,49,215,95,203,37,85,158,177,205,132,211,191,251,64,102,57,187,37,120,59,102,255,121,26,142,247,150,138,190,223,161,79,30,47,121,63,201,160,193,241,223,60,11,
0,112,221,118,98,230,7,183,50,235,98,1,249,3,255,245,191,190,146,185,79,45,180,95,182,35,159,59,5,93,83,225,92,39,217,193,133,106,234,9,145,173,237,193,110,136,27,245,224,157,117,99,249,221,5,4,29,1,4,
29,1,136,98,245,150,155,8,216,69,0,64,202,186,89,140,184,195,136,133,99,37,95,212,146,201,100,230,6,96,227,21,0,128,168,18,100,15,192,201,120,2,177,96,238,77,80,50,145,58,70,60,22,79,29,71,128,108,187,
236,7,236,68,44,134,100,124,243,184,137,68,18,137,120,18,201,68,18,17,95,36,243,222,217,18,145,220,72,103,50,145,93,118,0,130,0,65,44,253,198,42,176,228,147,45,75,134,205,122,211,54,234,82,55,76,201,244,
182,94,120,103,61,178,30,19,68,84,189,98,225,24,198,191,126,169,232,118,253,79,13,203,90,10,198,190,118,17,241,141,107,142,190,197,128,145,79,140,102,214,173,94,89,194,252,79,239,149,180,111,182,230,211,
109,232,124,164,39,179,60,240,177,97,196,195,3,184,241,183,227,8,57,11,143,79,207,126,223,108,39,254,245,217,76,175,135,224,106,0,55,191,61,94,240,120,0,112,248,211,163,208,217,228,45,221,197,246,205,
254,188,59,145,136,39,177,252,206,188,236,53,173,69,151,179,157,100,144,39,144,11,172,250,145,136,39,21,127,35,246,203,242,133,133,188,185,3,108,163,205,153,0,128,123,210,137,229,11,11,138,219,165,153,
58,27,54,2,0,229,41,191,111,193,43,91,222,250,251,6,33,85,231,153,239,93,18,88,124,107,22,157,239,235,221,245,251,22,234,58,171,210,73,176,30,98,111,6,170,12,65,37,42,94,107,118,34,22,136,33,188,94,120,
44,186,218,168,217,214,126,137,45,129,209,68,56,81,240,248,17,111,100,71,251,37,227,197,3,169,11,175,207,202,150,117,89,117,166,210,168,100,247,199,177,80,28,137,104,188,38,122,222,85,131,136,39,36,91,
86,237,34,16,69,181,109,199,103,94,109,210,64,107,213,33,236,74,125,153,226,145,56,110,254,63,239,161,253,161,110,168,116,155,135,149,244,18,140,237,230,156,253,103,95,154,198,236,75,211,57,175,159,254,
189,7,161,54,109,94,184,26,135,154,112,254,63,124,32,103,187,219,207,79,192,57,190,138,137,191,188,12,0,56,251,165,135,100,219,173,79,58,113,227,155,99,153,229,238,159,27,64,199,150,27,96,0,184,248,167,
111,32,234,79,93,200,244,118,3,78,126,241,188,226,103,189,253,252,132,108,249,210,255,246,102,206,54,150,161,38,28,254,236,137,204,114,216,19,66,200,17,84,60,94,112,53,128,217,151,229,159,221,220,213,
152,249,183,218,164,129,169,195,12,223,124,234,38,42,153,0,174,127,227,50,140,93,141,101,189,1,37,170,103,58,155,1,253,31,29,46,121,251,217,151,103,16,90,241,99,248,19,199,128,68,178,232,131,53,144,27,
96,12,57,131,136,71,98,0,0,81,35,111,65,136,5,163,178,99,22,218,55,91,250,58,151,166,54,107,161,54,231,107,253,150,203,126,223,108,201,45,177,208,68,44,94,218,231,86,232,213,84,108,223,236,207,59,253,
194,109,132,214,138,191,215,86,33,87,48,243,155,149,102,61,108,203,217,206,216,106,130,40,137,153,114,134,93,33,220,250,246,24,90,207,118,64,212,148,118,163,105,234,106,72,221,172,110,17,15,199,48,249,
252,245,204,114,216,157,42,139,245,144,29,182,227,45,48,117,154,177,240,250,44,2,75,62,68,188,169,27,233,193,167,143,100,130,226,225,181,32,102,95,158,134,119,214,131,201,231,175,195,162,80,246,222,15,
13,66,189,209,2,30,15,199,48,253,194,45,132,92,1,76,62,127,29,166,238,6,180,221,223,9,0,88,189,188,4,247,157,220,241,172,201,68,238,185,137,71,226,240,21,233,101,0,0,72,0,222,57,119,206,77,252,214,223,
55,0,176,142,216,176,248,198,230,185,155,125,105,26,142,171,203,138,45,247,165,48,180,152,114,26,37,0,192,183,224,131,168,74,194,208,154,123,15,18,11,68,101,9,186,136,10,209,219,140,232,251,232,246,243,
187,68,253,17,92,254,74,110,47,211,142,135,187,209,243,33,229,100,148,239,252,167,215,114,94,179,29,107,198,240,175,28,83,220,254,228,111,157,135,190,217,144,121,191,139,127,250,6,124,243,94,188,245,71,
175,200,246,235,127,106,24,253,79,229,254,166,189,243,229,215,16,245,71,241,214,31,189,2,83,167,25,163,255,234,44,108,163,143,102,214,79,191,112,27,203,23,54,3,167,91,223,15,0,124,243,30,140,255,197,102,
192,59,251,179,221,248,230,24,214,39,157,184,250,191,191,3,0,56,255,239,223,15,81,45,226,198,223,142,33,185,37,128,16,246,132,17,202,10,122,54,29,105,150,45,139,106,17,250,38,61,130,206,212,253,117,50,
158,192,157,127,184,129,158,199,135,32,237,83,2,113,149,86,5,108,163,129,111,47,36,163,137,61,239,253,27,241,133,49,253,194,109,217,107,250,22,227,158,190,7,213,142,93,133,126,90,207,118,226,222,139,119,
50,203,222,57,15,188,223,149,63,44,91,134,108,56,252,217,227,217,187,66,50,168,161,86,248,193,206,110,69,79,68,19,57,17,43,0,136,231,153,86,41,153,0,132,2,247,180,197,214,3,155,195,7,4,17,16,132,220,63,
122,157,85,159,57,70,34,158,138,120,198,163,9,132,156,1,168,116,18,212,70,13,214,111,173,97,250,133,252,93,161,182,18,84,34,154,207,200,199,20,119,127,176,31,215,255,230,189,76,148,51,17,79,194,123,119,
189,164,227,17,209,238,197,130,202,15,211,203,111,207,97,249,157,205,22,215,67,159,60,6,235,176,13,129,37,31,188,247,220,138,251,52,29,182,97,248,153,205,155,183,153,31,79,98,249,221,5,220,250,206,4,32,
8,56,254,133,179,48,236,240,135,120,236,235,23,17,88,246,35,25,79,64,165,151,112,238,247,31,202,172,91,187,225,196,237,231,39,50,101,238,123,114,8,173,247,117,148,116,220,181,27,78,220,254,31,19,153,39,
252,190,39,228,251,142,125,253,34,2,43,126,92,248,147,159,65,173,151,112,230,75,15,229,28,163,253,254,46,244,124,104,32,179,124,235,59,19,112,221,118,98,252,235,23,145,132,128,115,127,248,16,16,7,46,252,
217,27,16,54,46,118,165,214,149,119,214,141,192,178,47,231,61,183,195,58,108,131,117,36,183,85,88,84,139,104,62,213,46,187,233,93,191,189,134,245,219,165,207,49,127,242,139,231,115,198,243,39,98,9,197,
217,112,244,45,122,216,143,167,90,244,61,51,46,172,111,153,203,222,54,218,156,201,139,227,155,243,96,246,229,105,68,220,97,56,220,203,208,88,114,91,249,44,35,182,204,251,70,125,17,76,191,112,11,177,64,
12,142,241,101,36,145,200,4,0,124,243,158,146,102,230,1,128,224,170,31,215,255,250,106,73,219,102,211,90,116,176,29,151,223,196,119,60,212,141,213,203,75,178,94,123,233,174,179,59,81,44,49,151,243,154,
99,71,199,37,74,203,119,207,89,140,32,166,114,94,37,99,155,189,77,139,209,52,106,51,195,66,211,251,37,34,9,132,215,67,69,123,217,10,130,32,75,208,167,54,108,94,35,98,193,232,142,63,199,126,240,76,185,
100,61,8,178,233,154,244,232,120,95,79,206,235,246,19,109,178,70,52,231,248,42,156,227,171,57,219,237,149,35,159,59,153,73,236,183,213,196,95,110,6,61,210,1,106,203,80,19,186,62,216,15,109,131,6,179,47,
43,207,30,52,241,220,37,168,244,18,14,127,230,132,226,122,0,88,120,107,86,177,145,116,175,181,158,45,237,126,128,14,158,93,5,0,218,31,232,132,235,198,170,44,65,94,169,58,30,234,206,105,145,87,226,185,
235,146,181,228,23,51,245,253,27,24,124,250,112,222,245,179,255,60,133,246,7,187,20,187,71,1,169,155,144,171,95,77,69,41,135,159,57,38,155,222,37,237,216,191,60,157,233,165,144,222,222,123,119,29,87,254,
219,59,104,61,215,129,254,167,14,149,92,94,0,232,254,185,254,156,113,81,141,67,77,232,126,172,63,117,1,40,255,240,83,34,202,67,80,169,100,45,13,98,177,136,34,128,164,32,200,198,50,166,3,157,201,68,18,
64,50,119,204,210,54,36,99,91,134,36,37,129,104,104,51,112,17,143,198,54,222,7,0,18,72,40,180,238,230,63,112,66,54,212,41,41,102,143,199,220,248,12,241,4,226,217,67,162,242,237,179,113,87,155,10,178,38,
129,164,128,36,82,239,147,174,129,68,76,254,25,210,221,70,247,162,174,182,210,217,13,232,255,133,145,188,235,123,30,235,135,103,122,45,211,210,180,23,84,122,9,135,63,189,121,211,231,153,114,97,246,229,
84,235,183,119,198,141,142,135,115,127,19,175,125,227,74,166,227,126,60,178,251,22,33,199,123,203,88,126,103,30,161,245,84,96,189,247,137,65,152,182,180,208,95,251,198,149,220,33,110,59,37,0,131,31,63,
156,73,242,155,166,54,105,112,232,19,199,112,243,91,227,121,123,173,16,29,4,146,94,131,211,191,251,96,78,43,121,33,167,190,120,127,38,39,70,122,63,215,109,39,92,95,113,162,227,225,238,194,239,103,80,227,
244,239,62,168,184,110,246,165,25,89,80,179,16,223,188,23,254,69,207,198,208,33,101,119,190,87,248,126,123,55,36,173,132,193,95,58,146,211,139,10,0,218,30,236,130,99,108,121,199,1,195,189,226,207,26,234,
4,164,122,61,155,58,115,123,28,109,229,91,240,66,109,84,23,220,166,28,154,79,181,194,50,92,219,249,140,104,231,118,21,0,16,36,17,35,191,118,2,119,254,254,6,92,55,118,22,97,143,5,162,136,110,105,105,19,
85,34,180,22,45,18,209,56,188,119,61,240,47,166,90,120,52,13,90,24,182,116,57,242,47,251,17,45,49,154,186,149,169,211,92,48,217,144,74,39,161,229,92,170,53,94,215,180,55,227,181,242,190,151,94,66,255,
147,195,178,105,161,182,234,124,164,23,134,22,19,102,95,156,70,96,101,119,45,93,68,180,55,90,206,181,163,239,137,234,156,234,47,30,138,225,210,159,189,81,233,98,236,202,250,164,115,95,63,131,40,137,104,
189,175,19,221,143,245,23,156,113,70,165,151,112,228,243,167,113,251,249,107,123,214,251,74,20,69,89,46,151,200,198,16,128,136,55,146,250,207,159,59,126,182,164,174,247,219,16,241,132,101,65,123,125,179,
65,86,38,65,216,155,152,179,214,162,197,192,47,28,70,67,191,69,113,125,67,159,5,199,191,112,6,247,94,156,134,235,150,115,239,130,14,68,251,72,165,149,208,208,215,136,168,63,138,224,106,0,17,119,24,158,
153,205,235,67,44,148,234,213,146,190,215,84,232,68,186,111,34,222,136,108,156,189,164,85,65,165,151,16,241,132,16,90,11,33,234,75,93,111,12,45,38,72,134,205,7,107,239,93,15,146,59,8,172,154,123,26,139,
111,180,77,130,74,132,117,196,142,158,199,115,27,198,210,84,26,21,14,127,246,4,110,126,107,12,129,149,202,13,227,57,243,165,135,114,122,9,139,234,252,39,124,252,185,139,16,4,1,201,68,18,81,95,20,23,254,
228,103,27,129,237,242,107,28,106,66,223,71,182,215,88,73,7,203,174,179,63,72,90,9,35,159,28,133,119,214,141,181,107,14,132,156,65,36,98,155,93,140,140,29,133,35,97,107,215,29,112,78,172,100,150,181,141,
90,12,124,252,48,194,238,48,174,127,115,179,203,161,245,144,77,214,178,158,206,1,144,109,235,184,36,37,217,227,137,178,105,76,26,12,60,149,191,85,168,84,154,6,173,98,151,33,32,21,161,53,182,153,97,63,
213,10,141,73,185,39,71,122,150,127,0,0,32,0,73,68,65,84,66,154,245,144,13,214,67,182,212,216,213,245,16,123,3,16,149,137,82,203,67,33,253,31,25,68,60,178,187,63,80,83,151,25,177,80,12,254,5,47,18,145,
132,236,65,45,178,145,92,73,107,209,65,99,210,64,210,231,182,32,8,162,0,83,129,107,174,198,84,222,12,232,49,111,68,246,25,210,55,199,134,86,19,84,106,17,130,40,200,114,8,0,128,164,87,67,111,203,159,41,
58,157,236,169,255,169,67,219,158,142,74,212,168,82,227,251,75,204,56,175,49,107,112,236,55,78,97,253,142,11,238,91,78,132,92,33,217,239,91,193,247,218,163,164,84,167,126,231,126,136,146,242,177,84,90,
17,247,126,50,181,39,239,83,136,74,167,202,251,123,38,35,2,106,99,106,138,95,251,241,214,212,216,217,2,116,54,3,14,125,226,24,226,225,84,254,135,88,136,189,1,168,58,165,127,15,244,118,3,142,126,254,52,
156,227,171,184,253,252,4,28,227,43,112,140,175,228,108,63,248,244,145,162,247,163,123,45,188,30,148,117,169,215,52,106,161,215,75,112,188,183,42,27,174,219,243,161,1,89,203,239,59,95,126,13,201,152,252,
183,75,103,55,64,109,46,124,127,218,114,38,255,116,184,165,24,249,204,9,96,203,3,176,164,151,160,179,233,115,122,12,41,209,90,116,56,254,133,179,88,185,180,4,199,216,10,194,107,129,188,61,209,118,43,95,
174,28,73,175,222,86,94,174,248,70,99,167,168,22,129,100,170,1,52,31,149,36,238,249,204,60,162,164,130,169,205,4,251,169,54,216,142,54,87,215,92,147,84,118,123,246,237,50,119,55,194,220,189,253,104,96,
203,217,118,180,40,204,169,173,210,73,104,57,219,142,136,59,140,245,201,53,4,29,126,172,92,88,204,172,15,173,229,230,5,0,144,233,66,169,109,212,161,229,108,59,130,171,1,120,239,185,225,155,247,202,246,
183,30,177,195,126,178,21,241,96,12,43,151,23,17,15,197,100,235,211,140,5,178,10,23,146,126,112,223,43,58,171,30,58,107,225,233,83,136,168,114,52,150,221,255,125,30,249,220,73,196,130,81,92,248,95,127,
134,144,51,128,137,231,114,187,140,182,61,216,133,246,251,187,20,247,23,181,42,28,123,246,204,174,203,177,87,242,221,28,15,253,210,97,24,90,77,0,144,243,64,109,238,107,148,205,126,144,79,57,103,69,177,
12,90,97,25,220,155,121,157,101,195,42,54,238,125,5,65,72,229,156,129,8,65,20,33,170,132,76,46,26,181,65,3,81,202,186,83,19,196,162,185,108,242,17,4,1,162,74,200,204,164,163,56,171,77,22,189,205,136,35,
159,59,185,179,55,44,129,74,171,42,218,88,64,84,77,180,86,29,154,79,181,34,176,18,144,117,5,111,28,176,66,211,160,201,36,195,78,68,19,112,78,172,228,36,31,13,44,7,176,122,101,9,102,133,123,76,199,213,
101,8,27,127,243,233,253,180,22,29,26,250,26,97,108,111,144,245,56,216,42,223,61,184,161,205,128,230,83,173,240,206,121,17,114,4,176,62,181,38,75,12,171,212,248,47,105,55,135,186,153,187,27,144,136,197,
176,126,103,29,81,111,24,107,55,86,161,153,79,5,147,69,73,132,169,179,1,205,167,90,17,94,15,193,51,227,206,124,182,180,116,66,83,235,97,59,36,157,42,115,237,106,236,83,238,29,84,42,65,37,162,245,190,142,
146,243,218,84,139,115,255,246,125,136,7,34,184,248,95,114,19,138,167,181,61,216,141,182,7,11,15,247,32,218,141,170,157,255,65,99,210,96,224,99,35,88,159,116,98,125,114,13,158,25,55,60,51,202,9,182,148,
232,155,141,24,248,216,8,150,47,204,195,123,207,141,181,235,171,88,187,190,217,99,96,180,205,136,222,15,15,34,17,75,96,229,242,34,34,190,8,166,94,184,153,115,156,158,199,7,114,94,35,162,250,21,114,4,10,
38,79,179,29,109,217,213,241,69,73,132,125,180,5,209,80,12,238,45,201,224,116,118,3,76,109,38,24,178,166,207,179,28,106,130,161,197,0,231,181,85,36,99,73,197,178,25,108,70,24,218,77,153,101,239,189,117,
132,61,97,196,194,91,166,78,221,216,87,173,83,163,113,168,9,154,6,29,236,163,45,8,56,3,8,44,250,16,88,244,202,142,157,222,183,233,104,11,36,157,242,79,73,186,204,217,36,221,102,239,133,236,207,27,245,
132,21,63,67,99,175,5,234,26,159,195,61,234,143,224,237,255,152,155,225,187,253,225,46,244,60,158,202,154,157,30,130,118,245,171,239,32,232,8,224,221,255,252,211,156,237,109,163,205,178,68,137,219,209,
254,112,55,218,31,238,198,244,11,183,176,124,97,1,55,191,85,124,218,70,34,146,51,117,154,97,234,60,130,133,215,103,101,1,128,246,7,187,101,173,235,241,72,12,119,190,119,35,103,255,212,189,173,19,253,31,
205,237,134,173,116,47,106,234,52,99,240,233,35,0,144,55,0,144,143,101,200,6,203,144,45,53,115,138,35,128,165,55,231,182,181,191,253,100,43,236,39,91,83,217,252,189,97,89,114,58,181,81,141,179,255,230,
97,12,62,125,4,206,241,85,120,102,220,153,207,150,173,231,177,129,178,247,138,168,38,186,38,61,4,149,144,26,22,34,10,208,55,27,144,136,37,114,130,67,68,229,80,182,0,128,206,102,64,247,99,253,153,101,115,
137,145,191,236,253,242,201,55,151,165,169,179,65,113,127,77,99,106,124,191,32,10,5,143,111,238,179,64,111,55,100,90,171,178,223,75,109,80,203,246,55,41,76,121,72,68,7,71,177,108,240,214,127,183,187,185,
198,69,181,10,67,207,28,133,127,209,139,177,45,1,0,203,112,147,98,238,129,116,144,210,245,199,175,35,30,145,79,51,151,214,246,96,23,250,218,55,247,93,120,125,14,174,91,242,188,45,137,104,28,147,207,95,
135,161,221,132,19,67,77,48,117,154,49,244,204,81,44,190,57,139,187,139,62,172,94,89,198,234,149,220,7,243,193,143,143,228,237,234,157,175,204,133,62,175,111,222,171,248,25,70,62,53,10,235,72,237,5,0,
180,22,93,209,196,133,106,125,110,87,219,66,251,169,183,12,229,80,155,52,178,33,19,194,150,46,169,130,40,200,214,21,218,79,73,250,119,146,136,148,153,123,27,208,245,104,95,102,89,155,53,110,93,165,81,
201,214,103,51,118,152,161,210,169,96,234,42,124,239,168,111,222,156,37,198,50,210,4,181,105,51,136,42,25,74,75,40,151,189,159,18,77,129,32,171,253,100,75,78,57,183,14,117,50,180,26,10,126,214,82,203,
121,80,141,124,230,68,230,154,171,54,106,112,242,183,206,195,59,235,206,76,103,78,84,78,194,211,95,185,194,81,229,68,68,121,68,188,17,44,191,93,122,139,73,215,163,125,72,2,152,127,101,38,243,154,190,213,
8,251,241,205,100,159,174,91,78,248,182,76,25,216,250,64,87,78,62,144,236,247,53,247,90,10,102,236,157,123,101,6,201,60,243,6,103,239,235,184,186,140,96,158,57,208,213,13,90,180,157,223,204,252,236,189,
231,198,250,173,220,214,156,180,174,71,251,50,153,254,253,139,94,140,125,237,98,102,93,219,131,93,37,39,76,44,86,207,246,83,109,57,211,234,17,17,17,149,195,236,75,211,240,47,109,246,246,24,249,212,137,
130,67,177,150,222,158,151,245,132,24,248,133,195,208,100,229,85,8,58,2,184,251,227,201,204,178,125,180,5,246,147,109,123,87,104,162,60,42,30,0,16,112,0,242,218,29,136,15,65,68,180,59,187,9,0,16,17,17,
17,209,254,171,120,14,128,244,115,115,96,197,135,123,63,153,134,123,198,149,183,21,171,90,8,146,136,198,126,11,122,63,60,152,234,150,197,135,127,34,34,104,27,117,24,216,50,91,139,94,97,252,63,17,17,17,
17,85,78,197,123,0,0,64,96,197,143,137,231,46,35,30,169,173,41,128,84,90,21,70,159,61,91,215,73,77,136,136,136,136,136,136,168,54,236,112,34,161,189,53,251,226,84,205,61,252,3,64,60,28,199,236,75,119,
138,111,72,68,68,68,68,68,68,84,97,85,17,0,216,238,148,38,213,196,61,85,250,212,132,68,68,68,68,68,68,68,149,82,21,1,128,120,36,94,233,34,236,88,45,246,92,32,34,34,34,34,34,162,250,83,21,1,0,34,34,34,
34,34,34,34,218,95,187,158,5,32,17,77,96,249,226,2,156,99,43,8,172,248,145,136,150,222,154,255,192,31,61,186,219,183,175,42,111,253,209,43,69,183,17,213,42,24,90,141,176,29,111,65,219,217,142,204,252,
217,249,236,166,126,137,136,104,239,108,247,250,77,68,68,68,84,109,118,21,0,136,120,194,184,241,55,99,8,44,251,246,170,60,7,94,34,26,135,111,206,3,223,156,7,142,203,139,24,249,244,9,104,26,180,138,219,
178,126,137,136,170,199,118,174,223,59,225,158,116,193,121,109,21,158,123,235,136,184,195,12,248,18,17,17,29,0,231,254,224,97,72,6,53,46,254,233,207,16,245,71,139,110,47,170,85,208,54,106,97,238,177,160,
233,88,51,44,131,214,61,45,207,142,3,0,201,88,130,15,167,187,228,95,242,227,230,183,222,195,232,179,103,115,90,146,88,191,68,68,213,171,208,245,123,187,130,142,0,166,190,127,19,222,123,76,42,75,68,68,
84,239,18,209,56,130,142,0,130,142,0,86,46,45,192,220,99,193,224,47,28,130,206,190,55,83,207,239,248,174,101,233,194,2,31,78,247,128,127,201,143,229,139,139,57,175,179,126,137,136,170,91,190,235,247,118,
120,102,214,49,254,220,37,62,252,19,17,17,145,34,239,189,117,140,61,119,9,158,153,189,185,87,216,113,15,0,231,216,138,108,217,122,196,142,129,167,14,65,109,212,236,186,80,181,170,148,156,6,81,95,4,211,
47,220,196,218,13,103,230,53,231,216,50,218,238,239,148,109,199,250,37,34,170,46,165,94,191,75,21,116,4,112,243,219,227,136,135,56,155,12,17,17,17,229,23,15,197,112,243,59,99,56,254,236,25,232,108,187,
235,9,176,227,30,0,193,85,191,108,153,15,167,165,81,155,52,232,123,106,68,246,90,96,37,144,179,29,235,151,136,168,186,148,122,253,46,213,212,247,111,242,225,159,136,136,136,74,18,15,198,48,245,255,221,
220,245,113,118,28,0,136,71,228,201,137,248,112,90,58,141,73,94,87,241,72,238,13,32,235,151,136,168,250,148,114,253,46,197,250,29,23,187,253,19,17,17,209,182,120,102,220,112,79,185,118,117,12,206,97,68,
68,68,84,102,107,19,171,149,46,2,17,17,17,213,32,231,196,74,241,141,10,96,0,128,136,136,168,204,60,247,214,43,93,4,34,34,34,170,65,222,187,187,235,65,200,0,0,17,17,81,153,69,61,225,74,23,129,136,136,136,
106,80,100,151,247,16,59,158,5,96,47,73,90,9,177,112,109,38,66,82,233,170,162,10,137,136,168,134,28,253,252,169,156,215,38,254,234,50,18,177,68,5,74,67,68,68,68,181,34,59,87,220,118,85,197,211,107,195,
160,21,107,215,106,115,60,164,117,200,86,233,34,16,17,81,141,49,118,152,115,95,20,132,242,23,132,136,136,136,234,74,85,12,1,232,121,124,0,146,161,42,98,17,219,162,54,106,208,243,196,96,165,139,65,68,68,
85,204,113,117,25,99,95,191,8,103,86,226,191,219,207,79,96,236,235,23,145,136,166,90,253,207,254,254,131,56,249,219,247,87,162,136,68,68,68,84,39,170,226,169,91,215,164,199,232,179,103,49,247,207,51,112,
79,187,16,245,71,42,93,164,130,212,70,13,26,135,172,232,249,208,96,206,148,80,68,68,68,91,69,124,17,248,23,188,136,6,228,191,109,129,101,63,130,171,1,0,73,0,169,33,101,82,60,89,129,18,18,17,17,81,189,
168,138,0,0,144,10,2,12,61,115,164,210,197,32,34,34,218,87,147,207,95,199,250,148,19,241,80,42,247,205,165,255,250,38,36,131,6,167,190,120,190,194,37,35,34,34,162,131,174,106,2,0,84,94,142,177,21,44,190,
49,139,208,122,176,162,229,144,180,42,88,71,236,232,121,124,0,162,90,85,209,178,28,36,60,191,181,141,231,239,96,139,133,163,136,5,98,16,37,17,130,74,64,44,16,3,192,241,255,68,68,68,180,255,24,0,168,67,
107,215,86,49,249,119,215,42,93,12,0,64,60,24,195,210,219,243,136,184,67,56,244,201,227,21,43,135,115,124,5,81,95,241,161,39,77,163,45,85,63,236,163,222,207,175,227,234,50,34,222,189,155,98,205,126,178,
13,26,115,249,206,121,189,159,191,82,255,22,75,85,205,127,179,199,191,112,22,250,102,35,222,249,79,175,85,186,40,68,68,68,84,39,24,0,168,67,43,23,23,42,93,132,28,107,55,157,136,248,34,21,187,81,95,124,
107,14,190,57,79,209,237,140,93,13,85,251,48,145,86,239,231,119,249,221,121,120,75,56,151,165,50,247,89,202,26,0,168,247,243,87,234,223,98,169,106,225,111,150,136,136,136,168,92,24,0,168,67,91,147,44,
30,253,252,41,232,155,141,21,43,203,181,111,92,78,37,193,74,2,81,95,148,55,234,123,128,231,183,182,241,252,17,17,17,17,209,126,97,0,160,206,73,122,9,106,163,186,98,239,47,170,56,238,117,63,241,252,214,
54,158,191,131,37,184,236,135,235,150,19,81,127,180,210,69,33,34,34,162,58,197,0,0,17,17,81,25,44,95,88,192,242,133,234,27,226,65,68,68,68,245,131,1,0,34,170,89,74,9,255,194,10,9,0,237,39,91,161,49,107,
75,56,222,18,34,222,72,206,107,222,153,245,172,227,149,55,49,224,65,165,148,240,47,234,203,61,127,182,18,19,249,57,199,87,16,201,58,158,115,124,5,254,172,156,2,229,78,12,104,108,55,161,237,190,78,120,
238,186,17,88,241,193,122,200,6,109,163,14,42,125,229,122,119,16,17,17,81,125,98,0,128,136,106,86,169,9,255,90,239,235,132,185,171,161,232,118,222,153,245,156,0,192,242,187,185,45,182,229,78,12,120,80,
149,154,240,175,237,129,174,210,206,223,156,39,39,0,176,244,214,92,206,118,229,78,12,216,56,96,69,227,128,21,211,63,184,133,192,138,15,45,247,117,192,58,108,43,219,251,19,17,17,17,165,49,0,64,68,68,84,
6,77,71,154,161,179,232,97,176,203,19,59,118,63,54,0,81,37,86,168,84,68,68,68,84,79,24,0,32,34,34,42,131,240,122,16,222,121,15,188,243,169,94,15,125,79,14,65,211,160,69,251,3,93,21,46,25,17,17,17,213,
11,6,0,136,136,136,202,192,191,232,195,218,181,213,204,114,247,7,251,0,20,207,77,65,68,68,68,180,87,24,0,160,186,83,106,226,49,170,126,246,147,109,48,247,89,138,110,167,45,33,1,32,149,159,125,180,165,
164,177,253,26,83,109,159,63,199,213,101,44,190,61,135,136,59,164,184,126,226,175,46,67,148,68,28,249,220,201,50,151,140,136,136,136,234,13,3,0,84,119,74,77,60,70,213,175,245,190,142,74,23,129,118,161,
173,78,186,190,71,124,17,248,23,188,121,215,251,23,189,16,213,170,50,150,136,136,136,136,234,21,179,14,17,17,17,149,65,207,227,131,56,247,7,15,195,50,104,173,116,81,136,136,136,168,78,49,0,64,68,68,84,
6,162,86,132,100,80,3,162,80,233,162,16,17,17,81,157,98,0,128,136,136,136,136,136,136,168,14,48,7,0,213,29,165,196,99,206,241,21,68,178,18,3,210,193,230,184,186,140,136,87,158,252,49,236,205,77,6,105,
63,217,10,77,86,18,65,38,21,44,47,165,196,157,74,148,146,121,218,70,91,160,49,105,100,175,85,42,169,96,212,19,65,96,197,143,120,36,1,0,8,58,67,72,38,1,36,43,82,28,34,34,34,170,67,12,0,80,221,81,74,60,
230,157,243,48,0,80,103,150,223,157,135,183,132,100,144,173,247,117,150,148,169,158,246,207,110,18,119,182,61,208,85,53,231,111,254,167,119,49,255,211,187,153,229,91,223,30,203,252,91,212,48,9,32,17,17,
17,237,63,6,0,136,136,136,246,145,174,73,7,235,176,13,129,85,31,194,235,185,189,20,44,67,77,144,244,252,57,38,34,34,162,253,199,59,14,34,34,162,125,212,116,164,25,77,71,154,49,253,131,91,88,126,119,33,
103,253,161,79,28,227,52,128,68,68,68,84,22,12,0,16,17,17,149,65,67,175,21,2,114,103,0,16,56,43,0,17,17,17,149,9,3,0,68,116,160,40,37,247,83,210,208,111,133,185,207,82,116,59,38,252,171,60,165,196,157,
74,148,146,121,58,199,87,224,207,202,31,208,164,144,24,176,28,108,163,205,176,141,54,99,229,242,34,130,171,129,204,235,247,94,154,134,74,163,66,215,163,125,101,47,19,17,17,17,213,23,6,0,136,232,64,41,
53,185,223,177,103,207,84,77,114,56,42,76,41,113,167,18,165,100,158,75,111,205,229,108,103,236,106,168,72,0,32,109,237,218,42,214,111,175,201,94,147,12,106,6,0,136,136,136,104,223,49,0,64,68,68,84,6,43,
151,22,176,62,233,66,96,209,87,233,162,16,17,17,81,157,98,0,128,136,136,168,12,252,139,62,172,93,91,173,116,49,136,136,136,168,142,49,0,64,68,68,84,70,189,79,14,161,161,167,81,254,162,40,86,166,48,68,
68,68,84,87,24,0,32,162,154,165,148,240,47,172,144,0,208,126,178,21,154,172,100,126,76,238,87,121,206,241,21,68,179,198,236,43,169,84,210,190,253,162,179,233,97,236,48,87,186,24,68,68,68,84,135,24,0,32,
162,154,85,106,194,191,214,251,58,153,240,175,10,45,190,53,7,95,9,231,175,210,73,251,136,136,136,136,14,10,6,0,136,136,136,246,65,50,1,36,98,241,45,203,201,212,255,163,9,196,35,113,217,182,130,0,136,106,
85,89,203,71,68,68,68,245,135,1,0,34,34,162,125,176,118,125,21,183,255,199,68,206,235,183,190,155,251,154,100,80,227,220,31,60,92,142,98,17,17,17,81,29,99,214,33,34,34,34,34,34,34,162,58,192,30,0,116,
160,149,154,100,44,234,203,77,28,151,239,120,254,18,198,44,31,180,164,101,181,206,113,117,9,222,153,245,61,59,158,253,100,27,52,102,158,223,221,178,143,182,228,228,102,112,142,175,32,146,245,55,91,234,
223,157,210,223,177,77,225,111,81,99,98,2,72,34,34,34,170,79,12,0,208,129,86,106,146,177,82,45,189,53,87,210,118,76,90,86,93,150,223,93,216,211,227,153,251,44,12,0,236,129,182,7,186,114,94,243,206,121,
114,2,0,165,254,221,229,123,143,74,37,128,212,52,104,96,29,182,149,180,173,74,199,241,255,68,68,68,180,255,24,0,32,34,34,218,7,230,238,70,140,124,230,56,2,139,62,120,102,221,104,232,107,132,161,197,148,
179,221,202,133,5,64,20,42,80,66,34,34,34,170,55,204,1,64,68,68,180,143,214,167,92,152,249,225,109,120,238,186,51,175,185,167,92,72,38,82,255,158,249,241,36,238,189,56,85,161,210,17,17,17,81,61,97,15,
128,58,36,106,212,153,127,79,124,227,10,68,177,114,113,160,88,48,154,249,183,164,101,23,216,189,192,243,91,219,120,254,234,195,245,191,190,138,243,255,254,125,16,68,214,43,17,17,17,149,15,3,0,117,200,
54,218,12,239,189,84,66,180,120,48,134,120,145,237,203,193,212,105,134,214,170,219,243,227,42,37,25,43,135,74,38,25,171,171,243,123,178,13,230,62,203,158,31,183,24,173,121,255,206,111,61,157,63,37,123,
253,55,203,132,127,68,68,68,68,155,24,0,168,67,173,247,117,32,234,141,96,241,173,89,36,162,137,202,22,70,0,26,122,45,24,250,165,195,251,114,120,165,36,99,7,93,61,157,223,214,251,58,246,229,184,149,84,
79,231,79,73,189,252,205,30,255,205,179,16,36,142,194,35,34,34,162,242,98,0,160,14,9,130,128,238,199,250,209,249,104,31,146,145,202,182,47,10,146,0,81,205,46,176,123,137,231,183,182,241,252,213,7,99,135,
185,210,69,32,34,34,162,58,196,0,64,29,19,85,2,160,231,87,224,160,226,249,173,109,60,127,7,207,194,235,247,176,122,121,41,231,245,100,44,9,168,21,118,32,34,34,34,218,99,188,187,36,34,34,42,131,136,59,
140,136,59,92,233,98,16,17,17,81,29,99,0,128,136,136,104,31,181,221,223,137,150,211,109,184,247,79,83,88,185,188,152,179,254,204,239,61,8,81,195,124,0,68,68,68,180,255,24,0,32,34,34,218,71,162,36,166,
254,211,169,20,115,42,72,6,53,68,53,3,0,68,68,68,180,255,24,0,32,162,154,179,62,233,68,60,84,90,130,60,99,135,25,186,38,253,62,151,168,118,248,23,188,8,173,5,51,203,150,67,77,80,105,82,63,5,201,88,2,107,
55,28,153,117,26,139,174,34,211,104,30,52,177,64,20,17,95,4,93,239,239,69,223,19,67,57,235,131,171,1,64,0,244,118,67,5,74,71,68,68,68,245,132,1,0,34,170,57,119,127,116,7,65,71,160,164,109,251,159,26,134,
174,169,115,159,75,84,59,86,46,45,98,249,194,66,102,249,228,23,207,67,111,79,253,20,196,66,49,220,126,254,90,102,157,109,180,25,230,103,142,149,189,140,7,205,202,229,37,220,251,167,59,232,251,232,48,218,
238,75,125,23,227,193,24,84,58,9,16,128,177,175,95,128,168,86,225,220,31,60,92,225,146,18,17,17,209,65,199,0,0,17,213,52,81,45,162,237,254,252,15,248,134,182,205,233,214,86,46,45,34,22,136,166,246,211,
168,208,118,62,181,95,208,17,128,107,75,203,119,154,237,88,11,180,86,93,206,235,17,95,4,142,43,155,217,220,77,93,141,104,232,107,220,241,103,56,136,124,115,30,120,102,214,51,203,249,234,178,94,221,125,
233,14,250,159,28,134,32,177,235,63,17,17,17,149,15,3,0,68,84,211,84,26,9,61,143,15,150,180,237,226,27,179,153,158,3,106,163,38,19,0,8,44,249,112,239,197,169,156,237,13,109,70,229,0,192,122,72,182,125,
199,35,221,12,0,100,241,204,172,203,234,40,95,93,214,171,129,167,70,42,93,4,34,34,34,170,67,12,0,84,41,149,70,66,60,18,203,44,71,125,17,168,77,154,10,150,136,168,246,117,62,218,135,120,104,163,7,128,180,
121,249,51,118,152,209,255,212,48,214,39,93,138,61,1,0,224,238,63,78,34,17,79,0,0,162,254,168,108,221,250,164,11,241,208,173,204,114,219,253,157,208,55,27,115,246,203,102,25,106,130,245,176,29,0,176,244,
238,60,130,203,254,130,229,55,118,152,209,114,166,189,224,54,251,197,49,190,12,239,140,91,113,157,74,167,202,9,194,88,134,154,160,210,109,38,188,51,180,24,101,235,227,145,24,238,253,36,55,232,146,102,
63,209,2,115,143,5,0,48,247,234,12,162,222,136,226,118,74,117,178,159,117,25,201,42,71,58,127,130,146,208,90,16,235,147,107,240,206,166,234,205,123,119,29,72,230,110,151,84,254,122,16,17,17,17,237,57,
6,0,170,148,190,197,0,223,156,39,179,60,245,194,45,244,63,117,8,26,6,1,136,118,204,62,218,162,248,186,174,73,15,93,83,39,226,161,120,222,0,192,242,197,5,36,98,202,79,106,129,37,31,2,75,190,204,178,245,
176,45,19,0,40,180,159,74,167,202,4,0,214,111,58,177,62,185,86,176,252,182,209,230,138,5,0,188,51,110,89,238,128,173,212,70,77,78,0,192,208,102,130,161,205,148,247,120,137,72,34,239,241,82,251,27,51,1,
0,231,216,74,222,156,15,74,117,178,95,117,25,241,69,48,245,15,55,229,229,108,201,159,184,207,191,232,195,204,15,111,103,150,157,227,171,112,142,175,230,217,58,119,118,0,34,34,34,162,189,198,0,64,149,178,
29,111,145,5,0,92,55,28,121,31,76,136,234,69,42,97,157,252,129,43,22,138,225,198,55,223,203,44,155,251,44,232,124,164,7,206,241,85,168,116,42,88,134,154,48,251,242,52,252,243,94,217,126,146,78,141,161,
103,142,32,30,137,193,51,181,158,121,16,207,103,228,147,199,145,68,234,65,62,228,8,98,230,71,147,153,117,182,99,205,104,62,221,150,89,54,117,52,96,234,133,155,136,172,135,145,140,39,161,210,73,24,126,
230,72,102,189,119,198,141,249,215,239,193,57,177,138,192,146,31,173,10,57,12,14,125,242,56,196,141,43,116,250,253,188,51,110,220,248,230,123,176,29,107,65,243,233,54,44,188,62,139,123,47,222,41,82,107,
41,253,79,29,66,235,185,142,146,182,221,202,57,177,138,213,203,139,8,172,164,30,192,187,63,216,15,99,231,230,131,253,205,191,157,200,156,3,157,221,0,219,17,59,230,127,122,47,231,56,221,63,215,15,99,71,
42,31,195,173,111,143,33,30,78,213,165,206,110,64,223,147,185,67,56,12,45,198,204,121,11,187,195,0,138,215,73,60,22,199,250,77,39,124,11,169,115,61,240,212,8,52,22,229,160,169,198,164,77,125,190,241,85,
220,126,126,98,219,245,146,214,124,166,173,248,70,69,116,63,214,15,73,167,222,245,113,136,136,136,136,138,41,75,0,32,30,137,35,153,167,5,76,16,133,84,38,100,146,105,59,219,129,213,203,75,178,86,69,34,
202,149,140,39,100,173,189,91,187,157,167,249,231,189,57,45,194,106,99,234,193,48,17,77,192,59,231,41,26,0,104,28,178,102,254,237,211,121,100,235,180,86,29,44,67,54,217,107,222,25,119,166,213,90,84,137,
178,245,233,41,12,195,174,16,194,174,16,172,135,229,251,2,128,101,200,10,113,35,65,92,250,253,34,190,8,34,147,107,48,180,25,115,182,223,47,97,87,80,86,119,198,78,147,236,179,8,2,144,136,165,206,129,41,
24,131,185,171,65,177,245,189,237,129,205,32,199,250,164,43,211,43,66,210,74,57,117,151,150,125,222,138,213,73,60,20,151,109,111,238,107,220,215,169,245,26,7,172,104,57,189,253,160,74,182,246,7,186,32,
170,217,3,128,136,136,136,246,95,89,158,188,167,191,127,19,142,241,21,197,117,58,155,1,167,126,251,124,57,138,81,83,4,73,196,225,79,31,199,141,111,141,49,8,64,84,128,100,144,112,236,95,156,217,92,214,
230,62,72,13,252,194,33,196,35,9,220,252,155,49,132,92,193,109,191,71,170,37,218,7,157,93,143,190,39,115,231,113,79,115,78,172,194,220,109,134,166,65,158,236,46,22,140,224,234,87,223,217,92,14,199,183,
245,254,134,86,19,78,126,113,243,58,41,233,171,183,181,216,114,168,9,39,191,120,30,43,151,22,177,248,198,108,201,251,133,28,1,204,252,40,213,155,161,251,231,250,50,189,5,182,122,239,255,186,0,97,227,223,
74,195,42,58,31,237,67,219,3,93,152,250,254,45,120,239,173,227,230,223,140,65,80,9,178,109,12,109,38,12,63,115,180,244,15,148,71,227,128,21,131,191,116,4,16,242,111,211,208,211,128,67,191,122,20,107,55,
157,112,92,93,70,203,153,14,88,134,44,57,219,9,170,212,119,118,246,229,105,196,67,177,156,245,68,68,68,68,123,101,95,3,0,17,111,4,81,111,24,209,141,27,26,157,221,0,213,70,43,71,18,73,4,22,125,72,198,227,
240,47,120,161,210,73,208,53,233,247,228,253,210,244,205,134,61,109,85,137,135,227,8,57,115,199,161,234,172,122,168,244,91,170,50,9,248,23,189,57,219,169,141,26,104,26,181,37,191,159,166,65,139,227,255,
234,12,150,47,46,194,249,222,50,2,43,126,196,35,219,123,112,32,58,232,4,65,44,218,202,155,126,32,207,126,24,76,237,47,64,165,41,124,157,8,59,67,240,47,121,17,15,71,11,110,23,245,71,16,143,230,102,121,
75,38,144,119,12,123,41,68,117,241,207,88,45,84,26,9,122,187,4,181,97,123,65,138,120,52,14,255,82,234,186,25,11,43,63,4,135,138,212,161,198,164,1,76,26,168,52,169,94,2,74,193,30,149,118,231,63,123,42,
141,4,67,139,1,205,103,218,82,45,255,5,30,254,1,64,109,214,162,233,104,11,66,174,48,128,101,24,218,141,104,58,170,156,135,2,0,22,223,152,67,34,202,107,60,17,17,17,237,159,125,13,0,44,191,61,135,249,215,
55,199,130,14,62,125,24,230,174,6,0,64,50,150,192,219,95,126,13,225,245,48,198,190,126,17,141,67,86,28,249,236,201,61,125,191,99,207,158,201,188,223,94,240,205,186,113,125,203,88,227,180,161,103,142,192,
62,218,154,89,78,198,19,24,251,250,197,156,237,90,206,181,111,123,234,39,65,37,162,237,124,103,102,186,50,34,202,39,137,173,79,100,182,209,230,146,246,146,12,106,116,190,191,183,224,54,67,91,198,239,23,
146,239,239,84,109,212,224,244,239,61,144,119,63,65,20,225,186,225,44,233,61,182,234,120,164,27,29,143,116,111,107,159,222,143,12,163,247,201,33,220,252,246,24,220,147,46,89,171,122,154,169,211,140,163,
191,113,26,16,4,44,189,89,122,43,254,110,24,219,205,56,251,165,135,10,110,115,223,31,62,2,65,45,42,174,19,196,205,79,49,242,169,81,36,179,226,48,81,95,20,151,191,242,38,124,11,30,188,243,229,215,208,116,
180,25,67,191,116,4,182,209,102,216,70,31,221,109,241,183,109,234,133,155,57,175,253,255,237,221,89,108,92,217,157,223,241,223,189,183,238,173,157,59,41,82,212,66,73,212,190,116,75,106,247,54,61,142,157,
216,177,141,52,60,19,219,176,29,199,73,198,131,118,18,24,9,50,15,99,63,4,9,224,135,4,9,48,6,226,135,65,48,200,12,2,63,120,58,206,184,157,192,131,30,196,211,233,56,30,199,110,119,183,37,171,187,181,52,
37,81,27,197,93,220,89,44,22,107,205,67,137,69,22,107,97,145,170,98,145,188,223,207,19,111,221,115,238,57,117,142,22,222,255,217,44,199,148,97,25,204,2,0,0,0,53,83,191,197,247,166,161,150,147,43,191,160,
7,59,67,90,154,142,229,141,156,135,246,53,200,105,88,25,49,159,185,61,149,27,29,177,28,143,2,157,65,205,15,172,28,75,21,93,51,58,63,119,127,90,137,185,236,140,0,195,52,114,107,124,19,145,120,94,190,181,
26,14,53,229,77,177,77,197,83,154,237,159,210,194,88,118,42,190,183,217,167,96,231,202,244,84,239,170,233,190,51,183,167,148,122,60,122,101,57,150,26,143,180,172,124,159,206,194,41,173,0,170,165,244,112,
108,42,150,204,78,25,95,245,86,152,201,100,148,136,196,101,88,134,44,219,82,50,150,44,152,97,147,140,37,149,136,196,229,9,56,50,86,189,119,26,150,33,59,232,40,147,76,43,185,148,84,58,158,86,34,178,114,
60,156,199,239,145,39,96,203,14,58,74,44,196,149,201,100,138,190,212,153,142,181,238,236,131,106,51,45,67,146,33,219,231,200,14,58,74,46,198,149,126,60,155,222,48,178,223,203,227,119,114,107,237,77,199,
146,29,116,148,90,202,182,225,114,155,172,102,24,134,60,1,91,30,191,157,109,147,117,218,210,14,217,74,197,211,74,70,19,202,164,51,5,207,147,36,203,231,145,199,103,231,234,152,73,103,151,78,152,107,142,
84,52,108,83,158,199,163,250,169,120,182,47,138,73,39,146,185,186,90,94,143,76,167,120,32,97,171,20,13,6,191,124,92,137,133,132,46,255,209,47,183,190,66,0,0,192,21,234,22,0,48,76,67,199,190,116,58,239,
179,241,75,195,186,251,250,202,89,218,107,71,214,239,254,184,79,241,199,191,40,250,90,3,58,244,153,94,221,250,139,210,187,55,63,124,243,222,74,121,150,169,231,254,237,71,37,101,143,236,42,151,47,59,115,
96,37,0,144,152,91,202,75,223,120,164,185,228,72,254,234,58,218,97,111,193,119,4,176,245,110,191,118,163,96,99,186,100,52,161,203,223,121,75,161,238,6,117,189,176,79,183,95,187,81,144,175,255,181,15,37,
21,158,62,16,236,10,235,226,55,95,212,228,181,113,221,126,237,134,70,223,29,210,232,187,67,185,251,39,190,122,86,167,127,255,188,36,233,221,127,247,243,92,89,107,237,125,105,127,193,241,121,91,101,121,
86,195,251,127,252,110,110,121,130,39,96,235,226,55,243,71,225,151,103,32,221,123,253,150,198,46,13,231,218,100,53,59,232,228,242,45,183,201,90,171,219,242,252,31,188,160,68,36,174,203,223,121,75,11,35,
243,69,219,230,208,203,71,11,234,120,229,187,191,42,72,215,122,166,93,71,191,144,253,119,118,224,141,187,101,143,22,148,178,125,119,230,235,23,202,166,169,182,206,231,186,213,113,190,83,178,140,146,203,
184,12,67,108,4,8,0,0,106,110,71,111,191,239,109,242,169,235,133,149,233,175,243,3,179,138,12,173,236,206,221,118,102,143,236,112,118,167,111,195,146,82,139,73,141,95,25,209,226,227,153,2,129,61,33,53,
30,94,217,217,123,250,246,164,98,19,81,77,94,29,83,100,96,86,29,23,247,106,252,242,176,18,209,252,117,191,139,163,11,121,155,91,53,31,107,85,100,116,94,137,185,184,82,171,70,159,82,177,68,94,186,64,103,
126,121,0,54,39,208,25,202,173,229,174,100,67,60,95,91,64,161,197,226,211,170,3,29,65,121,2,182,66,221,165,151,11,45,143,134,175,85,42,159,181,234,72,183,96,119,67,201,83,80,156,198,149,217,67,107,235,
184,206,242,242,170,169,180,45,189,77,254,146,109,180,58,95,165,109,105,88,70,217,116,203,167,52,172,173,227,90,190,230,149,192,76,185,58,230,158,213,177,117,39,40,44,51,61,166,76,143,169,123,127,117,
75,99,191,46,30,160,240,4,108,61,243,173,223,218,226,154,1,0,0,183,217,209,1,0,95,91,64,7,63,181,50,122,246,240,205,187,121,1,128,61,207,119,231,237,1,16,155,136,234,193,27,43,103,102,135,246,135,243,
242,39,230,151,20,155,136,106,244,157,236,72,94,203,169,246,188,244,203,230,7,231,52,63,184,82,142,221,224,104,236,237,161,188,207,36,41,177,144,200,203,223,241,76,23,1,0,160,10,54,186,139,123,185,157,
251,151,109,230,239,102,227,225,230,117,243,157,254,218,211,21,61,171,146,58,214,66,165,109,89,233,126,3,149,180,137,148,13,26,84,58,18,95,237,58,110,181,100,52,161,120,36,174,84,137,32,20,0,0,192,86,
217,209,1,128,90,51,45,67,61,159,57,170,196,66,92,67,63,127,144,251,60,188,191,81,173,103,86,118,114,14,118,53,168,235,69,67,173,243,9,61,252,233,93,165,30,31,241,101,7,157,188,205,197,234,49,242,4,0,
168,175,241,43,163,26,248,223,133,193,100,0,0,128,173,70,0,160,140,140,97,168,243,185,110,197,38,162,121,1,0,255,158,128,58,159,203,223,237,219,223,154,61,194,112,248,255,61,200,5,0,44,159,167,32,29,0,
192,157,2,29,65,121,27,125,138,12,207,43,177,16,87,67,79,163,44,219,163,153,59,27,63,1,2,0,0,96,51,234,22,0,200,164,51,186,245,131,107,185,235,96,87,88,78,216,41,147,3,0,128,157,171,227,35,123,213,249,
145,110,245,253,249,7,154,185,61,165,67,127,239,152,252,237,65,189,251,239,127,94,239,170,1,0,0,151,168,223,12,128,116,70,211,183,86,70,61,210,233,180,90,79,84,118,110,55,0,0,0,0,0,216,152,154,6,0,58,
159,223,167,214,115,29,26,120,227,158,102,250,39,117,231,71,31,202,180,179,59,64,47,31,199,237,109,242,233,248,87,206,200,114,60,178,188,150,66,7,26,52,250,246,144,198,127,51,162,129,55,238,105,248,231,
3,185,231,173,221,141,127,35,229,25,150,169,51,175,156,215,185,111,46,169,49,101,0,0,24,211,73,68,65,84,60,163,200,192,156,238,190,126,75,83,215,39,20,25,88,217,184,47,62,187,36,73,234,253,252,73,5,246,
4,101,7,214,223,93,28,0,0,0,0,128,157,160,166,1,0,59,228,200,14,57,242,248,178,103,27,199,166,23,11,210,24,150,169,64,71,104,165,66,126,59,247,226,29,159,139,41,62,87,144,101,83,229,25,150,153,43,43,49,
23,151,36,37,23,19,74,46,22,6,21,188,205,254,188,58,1,0,80,109,195,191,124,40,79,192,86,38,149,145,136,55,3,0,128,45,176,37,75,0,14,255,206,9,29,250,236,177,162,247,12,163,240,180,235,125,31,239,209,222,
143,30,40,251,204,98,249,202,151,183,146,190,225,112,139,62,242,175,95,42,153,223,180,173,188,107,95,107,32,47,189,105,22,63,19,92,146,158,254,87,207,41,243,120,122,67,185,58,2,0,220,237,209,123,163,245,
174,2,0,0,112,153,45,9,0,100,167,225,151,126,105,206,202,72,25,67,50,178,163,245,150,181,94,250,205,151,103,152,146,229,108,224,171,27,149,167,95,27,60,120,82,233,68,90,99,151,135,53,121,117,92,209,241,
5,165,19,169,170,62,31,0,80,25,211,182,20,216,19,84,235,217,14,117,94,220,43,195,83,217,255,83,45,39,90,229,107,246,42,208,25,150,36,117,127,244,160,58,206,119,234,254,79,238,40,62,183,164,222,207,159,
148,229,173,238,255,29,0,0,0,197,108,131,99,0,13,25,146,50,217,31,177,74,124,110,73,125,127,126,85,209,177,72,189,171,2,0,174,151,78,164,20,25,156,83,100,112,78,19,87,70,116,252,43,231,228,52,120,215,
205,231,107,13,200,215,26,200,93,135,247,55,74,146,30,254,223,251,146,164,150,19,109,85,15,30,3,0,0,20,179,13,2,0,25,101,36,69,199,35,26,120,227,158,102,239,79,43,147,76,215,187,82,101,25,30,83,141,135,
154,116,240,239,30,145,191,61,88,147,50,50,201,52,47,255,0,176,77,45,140,46,232,230,171,31,232,204,43,23,43,158,9,176,214,177,47,158,86,58,145,206,229,239,255,31,31,42,181,196,44,47,0,0,80,59,219,32,0,
32,69,199,23,116,253,207,222,83,42,158,172,119,85,42,146,73,166,53,115,123,74,243,3,179,58,243,202,69,249,219,3,235,103,218,160,209,75,195,188,252,3,192,54,182,48,186,160,177,203,35,234,124,174,187,232,
253,233,155,19,186,243,227,190,220,245,129,79,30,81,199,249,174,220,245,218,0,242,212,135,19,44,243,2,0,0,53,181,45,2,0,15,223,188,187,99,94,254,87,75,45,165,244,240,255,220,209,177,47,159,173,250,179,
39,175,142,231,93,55,159,108,211,225,151,143,201,14,58,85,47,11,0,176,190,68,36,174,123,175,223,212,84,223,100,238,179,201,171,99,5,1,128,76,38,163,116,34,173,84,44,165,100,116,229,255,182,116,44,165,
84,60,37,211,99,201,48,165,7,63,233,215,220,192,236,74,190,109,62,251,13,0,0,236,124,219,34,0,48,119,127,166,222,85,216,180,217,187,179,235,39,218,132,197,71,11,121,215,188,252,3,64,125,217,33,71,61,47,
31,215,84,223,91,185,207,162,227,209,130,116,11,195,17,93,251,211,203,5,159,223,255,235,126,221,255,235,126,29,255,135,103,213,124,180,85,177,201,69,45,12,207,215,180,206,0,0,0,171,109,139,0,64,42,190,
115,167,60,214,106,230,194,218,54,225,229,31,0,234,207,9,229,255,91,92,238,255,0,203,107,201,105,240,229,174,19,145,184,146,139,137,154,213,13,0,0,96,61,219,34,0,0,0,192,110,211,120,164,85,199,190,120,
42,119,125,239,175,110,105,236,215,195,117,172,17,0,0,112,59,2,0,0,0,212,65,227,209,22,217,141,249,51,10,210,137,140,38,222,31,173,83,141,0,0,192,110,71,0,0,0,128,58,232,124,182,240,244,128,196,66,130,
0,0,0,0,168,25,2,0,0,0,212,64,108,58,170,209,119,135,114,215,209,177,236,134,129,51,55,39,181,52,29,203,75,107,122,76,117,92,232,18,0,0,64,45,17,0,0,0,160,6,162,35,17,221,31,185,93,240,249,216,165,194,
125,0,60,1,155,0,0,0,0,168,57,179,222,21,0,0,0,0,0,0,181,71,0,0,0,0,0,0,0,23,96,9,0,0,0,85,228,111,241,231,29,255,87,9,195,67,60,30,0,0,212,30,1,0,151,154,184,58,174,145,183,30,42,54,179,88,215,122,120,
188,150,154,143,183,233,192,39,14,203,180,173,186,214,101,55,161,127,119,54,250,111,103,179,252,30,181,156,234,168,119,53,0,0,0,10,16,0,112,161,169,27,143,212,255,163,27,245,174,134,36,41,181,152,212,
232,59,67,138,207,198,116,236,203,103,235,93,157,93,129,254,221,217,232,63,119,184,253,195,235,69,63,79,39,51,91,92,19,0,0,224,38,4,0,92,104,252,114,225,14,212,245,54,117,115,82,241,72,92,78,200,169,119,
85,118,60,250,119,103,163,255,220,97,242,250,163,122,87,1,0,0,184,208,182,8,0,120,188,30,37,151,146,245,174,198,166,88,190,109,209,132,27,146,88,136,231,126,62,245,123,79,203,223,30,172,91,93,110,124,
239,138,22,31,69,165,140,148,136,36,120,193,168,2,250,119,103,163,255,0,0,0,80,43,219,226,237,181,225,72,179,166,110,236,204,209,144,230,222,214,122,87,225,137,120,252,30,217,65,187,110,229,155,150,81,
183,178,221,128,254,221,217,232,63,0,0,0,84,211,182,216,118,248,192,39,14,203,19,216,22,177,136,13,177,131,142,14,124,234,72,189,171,1,0,0,0,0,192,186,182,197,91,183,175,197,175,51,175,92,212,224,79,239,
107,246,222,116,222,20,216,237,200,14,58,106,236,109,214,129,79,30,97,74,236,54,145,78,101,212,255,195,107,37,239,183,61,213,169,150,147,237,53,47,103,35,2,93,97,237,251,91,61,85,121,214,110,183,85,237,
78,255,214,198,147,252,253,220,72,94,250,15,0,0,160,188,109,17,0,144,178,65,128,222,47,156,172,119,53,176,83,165,51,154,234,155,44,121,59,184,175,113,75,202,217,136,20,187,125,87,110,171,218,157,254,173,
141,39,249,251,185,145,188,244,31,0,0,64,89,219,98,9,0,0,0,0,0,0,168,45,2,0,0,0,0,0,0,184,192,182,89,2,0,236,6,251,62,214,163,174,231,247,21,189,151,78,166,117,249,59,111,229,174,231,238,78,235,210,127,
248,197,74,222,143,247,168,179,68,94,148,183,85,237,78,255,238,108,244,31,0,0,112,59,2,0,64,21,25,30,83,150,175,248,95,43,35,145,206,187,206,164,51,74,46,37,115,215,169,100,122,109,22,84,104,171,218,157,
254,221,217,232,63,0,0,224,118,44,1,0,0,0,0,0,192,5,8,0,0,0,0,0,0,224,2,4,0,0,0,0,0,0,112,1,2,0,0,0,0,0,0,184,0,1,0,0,0,0,0,0,92,128,83,0,128,42,138,12,204,106,244,237,193,162,247,50,169,76,222,181,183,
201,171,150,19,237,185,235,208,222,112,77,235,182,155,109,85,187,211,191,181,177,145,118,221,170,114,232,63,0,0,176,27,17,0,0,170,104,250,214,164,166,111,77,86,148,214,215,22,212,193,79,247,214,184,70,
238,176,85,237,78,255,214,198,70,218,117,171,202,161,255,0,0,192,110,196,18,0,0,0,0,0,0,92,128,0,0,0,0,0,0,0,46,192,18,0,160,138,218,158,218,163,214,147,237,235,39,148,228,9,57,53,174,141,123,148,107,
247,116,42,163,219,63,188,158,187,142,142,68,116,235,7,87,87,229,237,84,75,133,125,70,255,214,198,70,250,175,86,229,172,69,255,1,0,128,221,136,0,0,80,69,254,246,160,154,79,180,213,187,26,174,83,174,221,
211,137,116,222,117,98,33,174,169,190,149,117,224,193,125,141,85,41,7,155,183,145,254,171,85,57,0,0,0,110,192,18,0,0,0,0,0,0,92,128,0,0,0,0,0,0,0,46,64,0,0,0,0,0,0,0,23,32,0,0,0,0,0,0,128,11,16,0,0,0,
0,0,0,192,5,56,5,0,174,144,156,143,43,58,26,217,84,94,59,236,200,14,114,36,216,118,86,174,127,211,169,252,93,228,45,199,35,95,139,55,119,237,208,183,0,0,0,112,9,2,0,112,133,145,119,6,53,242,206,224,166,
242,238,255,196,97,117,191,116,160,202,53,66,53,109,164,127,67,7,26,116,242,171,231,106,92,35,0,0,0,96,251,97,9,0,0,0,0,0,0,46,64,0,0,0,0,0,0,0,23,96,9,0,118,5,195,50,212,245,252,190,154,60,59,180,55,
92,113,57,171,211,162,122,170,217,191,254,182,192,166,203,161,127,55,231,73,218,117,35,121,233,63,0,0,128,242,8,0,96,87,48,76,67,7,63,221,187,107,202,65,62,250,119,103,123,146,118,221,72,94,250,15,0,0,
160,60,150,0,0,0,0,0,0,224,2,204,0,112,33,211,177,115,63,95,255,222,123,50,205,250,197,129,146,139,137,220,207,30,175,85,183,122,236,38,244,239,206,70,255,1,0,0,160,86,8,0,184,80,235,153,118,205,15,204,
72,146,82,139,73,165,234,92,31,73,10,117,135,229,109,246,213,187,26,187,2,253,187,179,209,127,0,0,0,168,21,150,0,184,208,158,143,236,85,247,111,31,148,105,111,131,238,55,164,134,158,38,29,251,210,233,
122,215,100,215,160,127,119,54,250,15,0,0,0,181,194,12,0,23,50,12,67,251,255,206,33,117,127,172,71,153,120,125,199,23,13,143,33,211,102,106,113,53,209,191,59,27,253,7,0,0,128,90,33,0,224,98,166,101,72,
126,254,8,236,86,244,239,206,70,255,1,0,0,160,218,182,193,28,83,0,0,0,0,0,80,107,4,0,0,0,0,0,0,112,1,2,0,0,0,0,0,0,184,0,11,76,1,184,78,38,153,214,84,223,68,197,233,155,142,181,200,114,248,231,114,217,
76,255,164,82,177,202,54,40,12,238,13,203,215,226,175,113,141,0,0,0,80,9,126,163,5,224,58,201,88,82,183,95,187,81,113,250,167,254,197,179,242,183,241,207,229,178,7,63,185,163,197,137,104,69,105,15,189,
124,84,190,150,238,26,215,8,0,0,0,149,224,55,90,0,174,231,111,11,168,249,68,107,201,251,30,191,45,73,74,39,210,26,125,103,112,37,95,123,64,205,199,219,36,73,179,253,211,90,24,157,47,200,219,245,226,126,
25,166,81,240,121,100,112,78,115,247,103,114,215,173,167,59,228,109,246,109,250,59,108,165,142,11,93,74,68,227,146,164,116,60,173,209,119,135,114,247,214,182,101,160,51,188,229,245,3,0,0,64,113,4,0,0,
184,94,160,51,168,3,159,56,178,110,186,212,82,82,3,111,222,205,93,183,158,105,207,5,0,166,250,30,105,236,210,112,65,158,206,231,247,21,13,0,204,221,159,201,123,86,160,51,184,99,2,0,93,47,238,207,253,156,
136,196,243,2,0,149,182,37,0,0,0,182,30,1,128,109,202,114,60,74,197,147,185,235,68,36,46,59,228,212,177,70,0,44,159,71,135,94,62,154,187,246,54,7,114,63,183,157,235,80,160,51,168,209,119,134,181,248,104,
161,32,239,210,76,76,195,191,24,200,93,71,71,35,121,247,199,222,25,214,116,223,100,238,250,224,103,142,202,180,140,130,124,107,117,62,215,45,127,123,80,146,244,224,127,245,43,157,74,151,253,14,109,231,
58,20,62,208,84,54,77,181,141,254,122,72,139,99,43,109,178,252,221,164,194,118,105,234,109,81,42,153,210,252,253,217,178,207,244,54,249,181,247,165,253,121,159,77,92,27,43,153,207,242,89,85,9,76,196,231,
227,249,207,101,111,8,0,0,176,131,240,155,203,54,229,239,8,40,50,56,151,187,190,251,250,45,29,122,249,152,28,130,0,64,221,152,30,83,123,158,41,190,158,61,124,160,73,225,3,77,154,238,155,44,26,0,72,68,
226,69,103,8,44,155,190,61,153,119,125,240,211,189,146,140,117,243,53,159,104,205,5,0,198,46,15,43,157,44,31,0,8,116,6,183,60,0,48,115,115,82,51,253,83,185,235,229,239,38,21,182,139,229,179,148,138,165,
202,126,103,73,10,117,55,20,4,0,230,239,207,150,204,103,7,157,39,14,0,196,35,113,221,253,241,205,188,207,2,29,129,18,169,1,0,0,182,31,2,0,219,84,235,217,142,188,0,192,116,223,132,166,55,176,107,57,128,
66,118,200,209,197,63,124,177,224,243,249,251,179,234,251,254,7,185,235,61,207,117,171,249,104,171,238,189,126,91,7,63,117,68,166,109,234,214,15,174,42,157,204,228,229,11,247,52,169,251,165,3,90,24,158,
151,105,155,185,23,241,98,124,237,1,157,248,234,217,220,245,228,245,71,122,116,101,52,119,189,255,227,135,20,236,14,229,174,211,241,148,110,253,224,154,82,177,236,76,160,240,193,38,117,255,246,202,11,
239,216,59,195,154,190,61,169,135,63,189,175,209,183,135,116,248,179,199,242,203,107,11,168,231,211,43,47,188,203,229,141,62,158,105,176,255,111,31,82,112,111,88,125,223,191,170,153,254,252,224,67,37,
74,181,101,174,188,107,143,100,249,44,53,245,182,108,248,217,107,29,126,249,184,156,166,108,240,51,25,75,170,255,181,15,21,155,136,170,239,251,31,40,220,211,36,95,179,95,143,174,140,40,58,158,221,152,
112,109,91,222,252,111,215,149,140,37,213,247,253,15,30,183,75,175,34,67,115,186,246,167,191,121,226,186,181,95,232,124,226,103,0,0,0,108,21,2,0,219,84,231,197,189,122,116,101,180,96,154,48,128,234,139,
71,226,138,175,26,161,46,182,33,224,76,255,116,193,232,186,229,179,36,73,177,169,152,44,159,85,54,0,224,241,122,212,212,187,242,220,232,104,254,44,129,96,119,40,239,126,34,18,207,27,53,119,194,118,222,
253,229,229,2,11,195,217,141,7,83,241,252,186,149,42,111,241,209,130,22,31,45,168,243,249,157,179,51,127,184,167,81,254,182,236,72,123,34,146,157,130,159,92,74,106,166,127,74,150,207,146,33,229,181,213,
218,182,52,12,41,157,76,107,166,127,74,161,197,164,170,165,241,112,179,58,206,239,173,218,243,0,0,0,106,141,0,192,54,101,120,76,157,248,202,89,245,189,122,149,32,0,80,99,77,189,173,58,184,106,180,188,
216,82,155,115,255,252,25,37,162,9,93,255,175,87,54,85,70,118,6,129,212,122,186,93,237,231,75,143,26,143,252,234,161,186,94,216,95,240,249,204,173,105,189,255,199,239,230,174,227,145,120,65,154,114,58,
46,116,169,249,68,91,238,218,219,232,221,80,254,157,228,238,95,222,150,229,220,201,93,175,183,47,194,102,52,30,110,214,145,207,157,92,94,201,0,0,0,176,35,16,0,216,198,156,6,175,206,126,253,130,198,46,
143,104,242,131,49,69,199,23,148,138,167,234,93,45,96,215,177,124,102,110,132,185,20,95,91,64,86,137,151,110,195,99,202,176,202,191,9,46,140,70,148,138,167,21,232,44,61,75,64,146,226,51,75,69,63,79,197,
147,90,156,216,252,232,181,39,96,203,19,176,55,157,127,39,137,207,197,106,242,92,203,241,40,208,17,80,251,133,206,236,200,63,47,255,0,0,96,135,33,0,176,205,25,150,169,206,103,187,213,249,236,206,153,174,
11,236,22,171,119,252,47,167,165,200,146,129,181,206,255,193,11,21,61,235,224,103,122,139,151,113,170,93,189,159,59,89,50,159,105,153,21,61,127,173,213,251,18,84,83,235,153,246,220,207,199,255,193,25,
101,50,210,7,127,114,73,177,137,168,46,253,199,95,228,238,101,138,101,94,227,131,63,185,84,240,174,29,234,14,235,212,215,206,75,134,161,209,95,61,204,187,119,236,203,103,213,212,219,92,244,89,203,207,
9,117,55,232,249,111,127,172,130,210,1,0,0,118,15,2,0,0,80,129,196,66,92,201,197,68,222,103,153,100,90,137,72,92,166,99,73,202,40,29,79,43,147,202,127,165,77,68,18,178,28,179,96,244,221,116,44,217,65,
71,169,165,164,210,201,180,146,177,100,110,125,187,36,201,48,100,7,29,101,210,153,108,185,233,116,110,67,192,213,60,126,143,140,77,190,252,111,21,195,50,101,72,178,3,182,82,193,236,242,138,76,38,163,100,
116,165,61,13,143,41,143,215,147,61,2,53,150,63,211,201,114,76,25,198,202,119,180,188,146,199,239,200,244,100,63,91,219,150,233,100,178,160,173,12,211,112,205,12,8,0,0,128,82,8,0,0,64,5,174,252,167,183,
11,54,1,156,234,155,212,84,223,91,218,251,210,254,146,71,215,93,249,238,175,100,7,29,93,252,102,254,142,249,203,51,123,238,189,126,75,99,151,134,213,255,218,135,121,247,159,253,55,31,213,197,111,190,168,
200,224,156,174,253,217,111,114,101,173,117,226,171,103,243,54,188,219,206,78,255,254,249,220,207,137,72,92,151,191,179,242,125,90,78,180,234,232,23,78,75,146,238,189,126,107,77,190,11,101,151,104,172,
215,150,146,138,246,1,0,0,128,219,108,58,0,224,9,120,148,73,102,215,165,2,192,78,98,88,134,66,221,13,185,107,95,243,250,103,185,7,187,27,148,73,22,223,76,206,105,244,41,237,75,231,61,115,53,143,191,244,
200,179,183,201,95,52,223,242,84,117,203,107,149,124,174,36,89,190,149,103,175,174,99,160,163,252,94,3,213,82,73,91,198,38,162,74,174,25,145,79,198,178,163,255,166,109,41,208,17,172,168,15,178,11,6,74,
47,188,47,213,150,82,249,62,0,0,0,112,139,77,7,0,158,249,214,75,154,237,159,214,135,223,127,191,154,245,1,128,154,243,248,109,157,249,250,133,13,229,57,253,181,167,215,77,179,247,165,194,221,251,43,201,
83,46,159,191,61,88,113,93,43,169,99,181,85,210,150,247,127,210,159,119,76,223,106,129,142,202,191,223,122,187,238,173,215,150,0,0,0,110,87,16,0,72,197,83,37,71,185,150,25,30,67,150,227,145,233,179,20,
220,27,86,98,97,99,199,81,1,0,220,35,220,211,36,203,103,21,189,87,108,228,63,184,55,156,183,137,160,199,91,60,47,0,0,0,54,166,32,0,112,239,47,111,106,226,218,120,217,76,141,189,205,58,249,213,167,20,222,
215,160,179,255,244,162,198,47,141,212,172,130,0,128,157,173,251,165,3,27,74,223,113,161,75,29,23,186,106,84,27,0,0,0,247,90,119,9,64,96,79,72,134,153,157,118,153,78,166,181,248,104,65,233,88,74,11,195,
243,178,131,142,156,70,175,156,102,95,205,43,186,219,180,156,106,95,63,17,0,0,0,0,0,85,178,110,0,224,196,63,58,39,39,148,61,182,41,54,17,213,123,127,252,174,230,7,231,116,245,191,92,86,199,51,93,58,252,
242,113,53,29,41,126,222,50,74,59,246,197,211,245,174,2,0,0,0,0,192,69,170,118,12,96,100,104,78,241,217,165,162,247,44,199,163,198,222,252,32,193,226,163,5,45,62,138,150,125,230,234,124,75,211,49,45,140,
204,151,76,219,116,180,85,166,109,42,21,79,105,182,196,102,83,171,53,28,106,202,219,21,122,189,124,161,125,13,114,26,188,146,164,153,219,83,74,39,82,37,211,74,217,141,173,124,107,142,173,42,151,207,215,
236,87,160,43,36,105,227,109,9,0,0,0,0,192,122,170,22,0,24,253,213,96,201,189,3,124,173,1,61,253,47,159,205,251,108,226,253,49,13,253,98,160,236,51,87,231,155,189,51,165,187,107,206,134,94,237,194,31,
190,40,199,118,148,152,91,210,173,191,184,190,110,125,79,191,114,65,225,125,43,1,128,245,242,245,126,225,164,218,206,236,145,36,221,253,113,159,226,145,242,27,31,238,255,196,33,117,191,116,48,239,179,
114,249,150,103,83,72,27,111,75,0,0,0,0,0,214,179,110,0,96,252,210,176,44,39,187,3,115,34,154,61,183,217,219,228,85,203,201,14,133,247,135,53,63,48,171,200,224,156,162,147,217,209,252,182,51,123,100,135,
179,75,6,148,201,104,228,237,65,165,98,9,141,188,245,80,222,38,159,124,173,126,205,222,153,86,100,40,59,154,223,124,180,181,96,164,124,153,29,180,181,52,179,164,169,27,227,154,31,204,166,15,31,104,204,
59,231,121,242,234,152,226,145,120,182,158,62,143,154,123,91,242,158,17,216,19,82,227,225,149,17,243,233,219,147,138,77,68,53,121,117,76,145,129,89,237,249,200,94,153,182,37,203,111,171,235,133,194,227,
163,230,7,102,21,25,154,211,204,205,41,37,230,226,106,61,183,39,239,190,229,247,168,227,233,149,205,170,162,99,17,205,222,157,214,252,131,89,141,152,15,213,124,172,85,145,209,121,37,230,226,74,197,211,
50,76,169,243,185,194,114,54,211,150,236,35,0,0,0,0,0,168,212,186,1,128,193,159,221,47,248,204,215,22,208,193,79,29,145,36,61,124,243,110,222,72,254,158,231,187,21,222,151,125,65,207,36,211,26,121,123,
80,137,133,132,30,188,113,71,141,189,205,106,61,209,174,7,111,220,201,165,111,125,170,35,55,178,94,204,108,255,84,94,250,166,99,45,121,35,235,145,135,179,138,71,226,26,252,217,125,25,150,89,16,0,8,237,
15,231,234,42,73,137,249,37,197,38,162,26,125,103,40,91,254,185,61,114,108,75,118,208,206,75,183,236,225,155,119,21,25,154,211,196,213,49,77,92,29,83,232,64,99,222,125,59,224,228,229,27,191,52,172,217,
187,211,154,185,61,165,153,219,83,178,27,28,141,189,61,164,249,193,57,73,146,97,153,69,203,89,46,107,35,109,73,0,0,0,0,0,0,80,169,13,45,1,176,131,142,186,63,122,80,222,38,111,201,52,35,111,13,106,50,148,
157,90,159,201,100,10,238,135,15,54,170,231,51,71,53,115,107,66,51,119,166,245,232,189,49,69,6,230,242,19,89,134,122,62,213,187,145,170,61,177,196,66,92,67,127,243,160,224,243,229,23,247,106,203,164,165,
209,119,30,202,105,244,170,245,84,71,209,52,235,181,37,0,0,0,0,0,149,218,80,0,192,242,121,212,249,92,119,217,52,83,55,138,175,93,95,230,111,15,202,223,30,84,98,126,73,51,119,166,53,219,63,165,217,53,105,
12,203,220,242,0,64,106,49,169,209,119,135,182,174,192,76,90,51,183,167,116,228,115,39,75,38,89,175,45,1,0,0,0,0,168,212,186,1,128,222,191,127,66,150,227,209,205,255,126,77,241,185,37,221,124,245,170,
130,93,97,237,251,120,79,209,244,7,63,121,68,190,118,127,209,123,118,192,201,253,220,246,116,167,66,7,26,10,210,244,255,207,62,165,99,41,221,124,245,170,156,6,175,90,78,180,85,246,77,54,43,157,214,205,
87,175,42,245,120,119,254,64,87,72,251,63,222,147,187,253,232,189,241,154,188,136,27,150,169,147,255,248,169,178,105,42,109,75,0,0,0,0,0,214,179,110,0,160,225,72,139,108,95,54,89,58,145,210,244,173,73,
165,211,233,146,233,67,7,27,115,235,214,203,241,183,5,228,47,178,249,159,101,153,74,101,146,154,190,53,41,95,107,160,230,1,128,76,90,154,190,53,153,187,182,131,182,154,143,173,148,89,176,60,97,11,85,218,
150,0,0,0,0,0,172,167,162,37,0,134,101,234,220,55,158,209,210,76,76,55,95,189,166,200,192,156,62,248,207,191,86,203,233,118,117,62,191,79,173,231,58,52,240,198,61,205,244,79,234,206,143,62,148,105,155,
121,249,189,77,126,29,255,202,25,73,217,105,237,131,63,43,92,107,191,44,17,77,200,180,12,157,249,103,23,101,90,166,236,176,87,231,190,241,140,166,174,79,104,240,111,238,107,244,237,33,77,126,176,50,34,
31,155,94,148,36,157,250,39,79,203,14,217,165,30,187,225,239,150,171,207,66,249,227,254,42,113,228,243,39,149,78,164,116,227,123,239,43,185,152,200,123,254,178,205,180,37,0,0,0,0,0,149,170,108,15,0,67,
10,116,132,100,154,217,151,209,84,60,165,232,248,130,66,7,26,100,135,28,217,33,71,30,95,246,168,192,229,23,242,213,210,169,149,13,236,146,209,164,162,227,11,229,203,179,76,5,58,66,185,203,64,71,40,55,
18,159,136,196,149,136,20,190,148,251,218,3,114,66,142,98,19,209,138,190,210,122,223,173,154,124,205,217,105,252,166,105,72,25,21,125,254,102,218,18,0,0,0,0,128,74,25,191,251,221,247,242,222,40,211,137,
180,50,153,149,41,254,150,237,145,140,199,23,25,41,149,72,230,238,153,166,41,195,99,22,205,151,87,136,97,200,180,179,47,181,233,84,70,153,84,106,189,106,201,114,172,188,79,214,203,151,171,103,153,58,150,
253,126,107,242,149,98,218,150,50,201,116,110,87,254,213,223,173,88,61,77,143,37,195,52,30,151,157,42,185,155,255,102,218,18,0,176,51,189,253,237,159,213,187,10,0,0,96,11,60,243,173,223,146,39,96,235,
242,31,253,82,137,133,68,85,158,249,252,183,63,182,233,188,5,51,0,178,83,206,205,34,73,37,25,146,229,20,159,52,80,54,223,234,116,150,33,89,27,58,124,96,99,249,202,212,81,42,83,207,117,242,229,37,45,243,
2,94,174,158,149,190,184,87,218,150,0,0,0,0,0,84,138,183,76,0,0,0,0,0,92,128,0,0,0,0,0,0,0,46,64,0,0,0,0,0,0,0,23,32,0,0,0,0,0,0,128,11,16,0,0,0,0,0,0,192,5,8,0,0,0,0,0,0,224,2,4,0,0,0,0,0,0,112,1,2,0,
0,0,0,0,0,184,0,1,0,0,0,0,0,0,92,128,0,0,0,0,0,0,0,46,64,0,0,0,0,0,0,0,23,32,0,0,0,0,0,0,128,11,16,0,0,0,0,0,0,192,5,8,0,0,0,0,0,0,224,2,4,0,0,0,0,0,0,112,1,2,0,0,0,0,0,0,184,0,1,0,0,0,0,0,0,92,128,0,
0,0,0,91,204,114,172,122,87,1,0,0,236,64,150,247,201,126,135,32,0,0,0,192,22,179,27,188,245,174,2,0,0,216,129,156,240,147,253,14,65,0,0,0,128,45,214,112,160,169,222,85,0,0,0,59,80,184,167,241,137,242,
19,0,0,0,96,139,181,156,110,175,119,21,0,0,192,14,212,122,170,227,137,242,19,0,0,0,96,139,53,29,105,86,152,89,0,0,0,96,3,26,122,154,212,120,184,249,137,158,65,0,0,0,128,58,56,242,59,199,100,249,60,245,
174,6,0,0,216,1,44,191,71,135,63,123,252,137,159,67,0,0,0,128,58,240,181,6,116,252,203,103,101,249,9,2,0,0,128,210,44,191,71,199,191,116,86,190,22,255,19,63,139,0,0,0,0,117,210,208,211,168,179,175,92,
80,195,19,110,232,3,0,0,118,167,134,158,38,157,121,229,98,213,126,87,96,216,1,0,128,58,242,181,6,116,234,247,206,107,246,238,180,38,175,143,107,254,193,172,226,115,75,74,197,83,245,174,26,0,0,120,66,177,
233,152,60,75,73,101,210,149,165,183,28,75,78,131,87,225,158,70,181,158,234,120,226,53,255,107,25,191,251,221,247,50,85,125,34,0,0,0,0,0,216,118,88,2,0,0,0,0,0,128,11,16,0,0,0,0,0,0,192,5,8,0,0,0,0,0,
0,224,2,4,0,0,0,0,0,0,112,1,2,0,0,0,0,0,0,184,0,1,0,0,0,0,0,0,92,128,0,0,0,0,0,0,0,46,64,0,0,0,0,0,0,0,23,32,0,0,0,0,0,0,128,11,16,0,0,0,0,0,0,192,5,8,0,0,0,0,0,0,224,2,4,0,0,0,0,0,0,112,1,2,0,0,0,0,0,
0,184,0,1,0,0,0,0,0,0,92,224,255,3,135,110,244,247,114,98,109,236,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::liveModeBackdrop_png = (const char*) resource_LiveMode_liveModeBackdrop_png;
const int LiveMode::liveModeBackdrop_pngSize = 64009;

// JUCER_RESOURCE: recordnormal_png, 732, "../../UI/Record-Normal.png"
static const unsigned char resource_LiveMode_recordnormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,89,73,
68,65,84,88,133,197,151,189,79,83,81,24,135,159,247,165,88,40,4,29,52,193,4,99,105,192,69,35,126,178,203,100,172,113,112,114,50,241,47,48,49,161,96,52,228,38,18,181,29,8,255,132,98,98,226,132,26,7,48,
49,49,16,23,17,211,193,144,180,85,81,152,140,104,11,165,45,231,56,208,202,151,181,87,108,123,127,211,185,231,156,123,158,103,56,159,130,203,56,93,180,249,11,132,213,210,103,133,30,32,8,236,43,54,127,7,
82,88,102,16,38,197,207,211,129,15,252,116,51,174,84,234,112,55,196,17,53,12,0,87,128,128,75,223,101,132,49,21,162,145,4,115,187,18,24,233,160,57,223,200,29,107,184,142,224,115,9,222,158,188,88,70,87,
132,33,39,69,214,181,64,44,68,183,93,227,137,21,142,237,18,188,61,211,107,150,203,183,62,178,80,81,224,222,97,78,138,240,2,56,80,37,248,122,44,243,13,74,184,63,201,108,89,129,88,136,110,99,120,93,117,
248,38,9,21,206,70,82,44,150,170,180,84,112,130,52,25,195,227,154,193,1,132,14,35,140,143,116,208,188,67,160,89,24,6,122,106,6,47,197,114,58,231,99,112,195,137,226,82,91,35,254,31,179,253,95,37,210,42,
116,71,82,44,42,128,26,6,234,6,7,16,90,13,12,1,136,211,69,91,83,129,5,220,111,50,213,74,70,252,28,84,127,129,176,7,112,128,22,179,202,5,85,75,159,7,112,0,20,250,180,120,176,120,18,11,199,21,75,167,87,
2,64,72,17,218,60,20,216,171,149,251,212,54,138,229,135,135,252,37,69,72,122,40,144,80,44,51,30,10,188,83,132,73,175,232,86,152,208,108,11,227,64,198,3,126,102,53,192,115,117,226,164,17,30,213,29,111,
121,232,196,73,175,159,134,66,20,200,215,17,159,179,150,251,80,188,144,68,18,204,137,101,180,142,2,35,55,63,145,248,45,0,176,34,12,1,211,181,38,11,76,5,124,56,155,190,55,18,11,210,110,225,141,133,67,53,
226,127,45,20,232,189,61,207,151,82,197,150,173,56,146,98,81,133,139,88,230,171,77,22,248,140,114,126,51,124,135,0,64,127,146,89,211,200,41,224,85,21,225,83,2,189,131,9,222,111,111,107,248,211,15,19,223,
88,190,180,159,177,188,193,0,103,128,61,187,100,231,44,196,2,62,174,221,72,176,84,70,238,239,137,5,105,47,94,32,175,2,45,46,193,25,129,7,198,16,45,205,246,114,169,40,80,138,115,148,86,127,134,176,192,
57,224,4,208,201,214,231,121,82,224,173,21,94,102,3,60,115,226,164,221,140,251,11,10,101,179,122,157,223,109,52,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::recordnormal_png = (const char*) resource_LiveMode_recordnormal_png;
const int LiveMode::recordnormal_pngSize = 732;

// JUCER_RESOURCE: recordover_png, 781, "../../UI/Record-Over.png"
static const unsigned char resource_LiveMode_recordover_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,138,73,
68,65,84,88,133,197,151,205,75,84,81,24,135,159,247,220,153,154,73,81,55,129,65,65,5,182,138,236,203,65,36,130,113,17,145,173,90,181,234,15,8,52,70,24,178,205,112,233,67,29,7,82,11,252,15,250,128,160,
149,21,45,82,8,210,201,77,101,180,10,52,200,82,8,204,106,70,71,199,123,223,22,206,12,147,38,51,153,51,243,91,221,123,206,225,60,207,226,156,247,190,87,40,50,113,187,189,70,82,86,27,208,234,66,163,129,
253,10,117,0,2,11,46,124,18,149,183,192,200,170,122,159,156,234,235,251,85,204,190,82,104,193,235,107,157,135,84,221,171,192,69,96,87,145,190,139,170,242,64,92,39,218,28,187,243,113,75,2,99,161,144,223,
236,116,111,128,92,1,60,69,130,215,39,13,50,176,228,171,141,4,109,59,85,180,64,60,220,209,160,150,121,44,112,120,139,224,117,209,184,199,200,133,147,221,3,179,5,5,198,186,58,143,89,184,207,21,118,111,
15,60,151,25,140,182,53,119,15,78,110,42,16,15,119,52,136,101,94,149,0,158,147,48,142,183,41,16,139,205,101,7,76,246,97,212,182,125,88,230,81,9,225,0,123,93,107,117,120,44,20,242,111,16,240,167,190,223,
4,26,75,8,207,68,79,24,31,93,217,55,129,220,85,251,192,214,79,251,191,38,97,28,111,67,32,22,155,51,0,153,123,94,46,56,64,181,122,210,17,0,137,219,237,53,164,172,89,138,47,50,219,149,228,170,187,99,143,
201,148,215,114,195,1,170,44,179,124,206,0,173,21,128,3,32,72,171,113,203,114,242,55,139,30,49,2,7,42,39,32,7,13,80,83,49,60,212,154,194,203,74,27,3,252,172,20,92,225,135,81,152,174,148,0,232,148,201,
180,81,149,137,200,59,3,140,84,140,175,250,194,44,249,151,135,129,100,5,248,201,69,95,250,153,9,218,67,9,85,121,88,118,188,202,253,160,61,148,48,0,226,58,81,32,93,70,252,138,37,244,66,166,33,89,107,157,
101,160,108,120,209,219,77,189,253,83,57,1,128,37,95,109,4,52,94,6,252,248,124,194,181,115,46,249,51,19,225,112,189,107,165,39,128,125,37,130,127,117,45,9,180,220,234,255,146,29,248,163,20,7,98,177,57,
140,158,7,102,74,0,255,236,170,156,205,135,111,16,0,104,238,30,156,92,17,231,56,240,114,27,225,227,198,241,6,90,162,253,239,215,79,252,245,99,116,186,231,238,183,249,164,115,6,145,235,252,95,141,88,1,
122,230,147,78,48,255,95,32,63,5,127,78,39,194,225,122,245,164,35,170,92,2,170,138,4,39,129,123,22,18,205,158,246,205,82,80,32,155,81,251,114,181,47,229,109,19,145,32,202,81,214,26,153,186,204,244,2,48,
173,232,27,212,140,166,252,203,79,131,246,80,162,152,125,127,3,129,221,221,195,90,166,91,141,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::recordover_png = (const char*) resource_LiveMode_recordover_png;
const int LiveMode::recordover_pngSize = 781;

// JUCER_RESOURCE: recorddown_png, 756, "../../UI/Record-Down.png"
static const unsigned char resource_LiveMode_recorddown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,6,0,0,0,115,122,122,244,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,
0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,2,113,73,
68,65,84,88,133,197,151,205,107,19,65,24,135,159,119,118,107,191,210,110,145,102,219,130,130,21,234,73,172,34,122,20,218,131,136,241,84,8,22,11,226,127,224,81,79,65,84,168,189,72,255,4,15,154,10,43,30,
164,42,30,172,39,105,241,98,21,60,21,90,33,213,150,148,96,211,124,84,147,236,174,135,102,107,236,7,89,107,146,253,157,118,103,134,125,158,133,153,119,102,4,159,73,165,198,58,245,162,19,113,113,134,65,
6,129,99,64,87,185,123,29,248,10,204,11,238,76,65,219,124,25,14,191,200,248,249,174,84,27,176,177,118,245,132,99,203,45,96,20,104,243,233,155,7,166,68,169,9,195,140,47,28,72,32,145,136,182,118,232,234,
30,34,55,1,221,39,120,103,138,136,76,26,249,230,152,244,63,250,233,91,32,157,188,54,224,58,206,115,224,228,1,193,59,51,215,164,233,35,237,225,199,43,85,5,126,36,71,207,136,195,27,32,92,35,184,71,90,118,
144,200,225,158,169,207,251,10,148,255,252,125,205,225,21,18,186,216,231,66,166,181,234,53,41,239,193,93,186,209,226,58,142,85,55,56,128,203,145,146,171,77,39,18,209,214,93,2,233,150,205,251,192,96,221,
224,127,36,206,134,116,253,182,247,42,176,189,212,190,112,240,217,254,175,201,234,202,30,8,153,214,170,2,40,175,243,70,193,1,66,37,91,139,1,72,42,53,214,169,21,237,21,252,23,153,90,37,87,212,242,125,74,
47,58,145,0,224,0,237,77,118,219,101,181,85,219,3,203,176,42,111,44,65,229,148,2,250,3,20,56,174,128,206,0,5,12,85,125,76,125,163,128,141,0,249,105,5,44,5,40,176,168,128,249,224,248,238,39,37,184,51,193,
241,121,171,126,41,103,26,200,5,128,207,21,52,231,181,50,77,43,11,60,13,64,32,110,154,86,86,1,136,82,19,64,177,129,240,2,162,30,64,249,64,98,152,241,5,68,38,27,199,151,135,93,61,241,197,109,1,0,35,223,
28,3,230,26,64,159,53,50,235,119,182,85,42,123,178,201,104,111,201,209,62,0,71,235,65,22,248,94,212,237,243,221,221,214,55,175,237,175,82,28,50,173,85,71,228,10,194,114,29,248,9,27,237,82,37,188,44,181,
59,153,149,104,216,86,250,51,92,247,66,141,224,179,186,178,71,42,143,227,94,246,220,140,58,250,172,53,99,99,253,162,235,202,93,254,175,70,20,128,113,35,147,30,218,11,14,62,46,167,217,100,180,183,100,107,
49,132,235,64,187,79,112,14,120,130,168,9,111,182,239,151,170,2,94,146,201,104,232,144,163,69,192,29,2,57,205,214,65,166,242,122,190,132,203,71,144,119,5,173,244,170,92,224,170,230,55,166,247,204,54,162,
255,71,70,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::recorddown_png = (const char*) resource_LiveMode_recorddown_png;
const int LiveMode::recorddown_pngSize = 756;

// JUCER_RESOURCE: recordIndicator_png, 475, "../../UI/RecordIndicator.png"
static const unsigned char resource_LiveMode_recordIndicator_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,50,0,0,0,22,8,6,0,0,0,130,2,207,145,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,1,88,73,
68,65,84,88,133,237,215,177,106,20,81,20,6,224,239,206,140,25,193,141,110,32,209,109,212,177,75,35,54,177,21,33,177,10,196,214,116,121,4,65,48,90,216,198,88,105,33,226,11,136,157,136,169,183,146,88,132,
40,22,129,148,73,180,177,8,152,184,10,43,102,103,45,204,130,133,168,44,194,92,97,190,234,148,255,207,185,197,61,193,161,229,194,85,92,199,69,28,19,183,47,88,11,193,131,197,45,47,32,133,123,133,101,60,
68,129,145,202,226,253,189,17,156,195,252,116,83,222,222,211,14,135,155,120,94,166,71,188,187,116,195,238,228,172,131,124,180,226,156,191,151,125,237,24,223,92,113,230,229,125,73,239,27,193,92,58,211,
244,24,197,206,229,155,62,92,184,166,204,242,170,115,254,81,153,229,62,183,206,235,229,13,205,237,85,104,37,250,166,96,119,114,182,218,116,67,248,41,243,84,34,104,32,250,231,244,43,7,71,79,12,198,209,
164,202,32,255,82,93,36,54,117,145,216,212,69,98,83,23,137,77,93,36,54,9,58,252,248,26,255,111,178,238,254,96,252,148,224,53,140,111,174,84,22,104,88,39,55,158,13,198,245,244,202,152,143,152,63,254,126,
77,47,111,232,54,207,70,127,147,100,221,125,173,183,79,157,126,245,72,232,151,101,18,44,4,184,91,88,10,220,174,58,224,16,74,125,119,110,237,88,74,161,189,167,61,51,230,13,78,233,155,16,162,191,219,59,
88,77,130,133,197,109,79,224,59,101,136,82,67,53,26,67,20,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::recordIndicator_png = (const char*) resource_LiveMode_recordIndicator_png;
const int LiveMode::recordIndicator_pngSize = 475;

// JUCER_RESOURCE: recordIndicatorblink_png, 360, "../../UI/RecordIndicator-Blink.png"
static const unsigned char resource_LiveMode_recordIndicatorblink_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,50,0,0,0,22,8,6,0,0,0,130,2,207,145,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,0,229,
73,68,65,84,88,133,237,215,33,78,3,65,24,134,225,103,102,147,86,0,73,17,4,187,220,161,72,84,209,160,113,28,1,84,21,9,178,40,16,92,161,158,160,89,137,33,128,71,209,35,108,104,176,93,68,27,130,4,178,201,
76,147,125,78,240,126,153,49,127,176,50,41,29,227,12,251,216,144,183,79,60,133,224,102,252,238,30,10,184,42,77,112,139,18,189,100,121,191,215,195,30,78,70,3,253,170,86,133,213,75,220,53,8,105,227,254,
236,187,57,56,138,150,223,105,237,70,240,163,185,113,30,53,134,41,99,90,50,140,130,205,212,21,45,216,138,169,11,218,210,13,201,77,55,36,55,221,144,220,116,67,114,211,13,201,77,196,60,117,68,11,62,34,94,
82,87,180,224,57,134,224,154,229,145,178,166,22,49,184,44,30,106,111,163,129,126,224,32,117,209,63,44,52,46,198,51,211,2,170,90,117,184,237,21,187,26,59,66,246,119,251,28,143,49,56,29,207,76,225,11,40,
144,41,174,11,244,148,201,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::recordIndicatorblink_png = (const char*) resource_LiveMode_recordIndicatorblink_png;
const int LiveMode::recordIndicatorblink_pngSize = 360;

// JUCER_RESOURCE: bigCheck_png, 2060, "../../UI/BigCheck.png"
static const unsigned char resource_LiveMode_bigCheck_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,45,0,0,0,47,8,6,0,0,0,119,210,67,145,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,0,0,
0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,7,137,73,68,
65,84,104,129,205,154,105,108,84,215,21,199,127,231,189,153,241,110,207,24,47,128,1,111,216,44,38,140,161,208,32,154,180,9,66,21,13,97,49,97,137,146,20,69,180,165,18,9,96,72,80,69,219,72,86,65,173,26,
42,176,73,91,53,164,164,74,213,180,137,40,241,18,10,36,13,33,95,162,146,196,4,47,49,212,198,96,199,128,49,198,198,43,96,143,231,189,219,15,3,4,195,188,193,216,99,211,255,135,209,140,222,255,222,243,211,
213,189,231,158,119,52,194,255,145,114,118,148,39,152,118,22,136,98,158,136,57,67,33,113,10,98,5,20,80,135,146,191,101,119,76,255,173,60,104,80,128,69,191,43,141,179,233,250,207,148,200,58,32,60,144,87,
80,191,126,224,208,139,118,150,101,233,26,135,129,113,40,232,56,115,133,182,51,87,232,62,215,137,167,171,23,227,186,23,16,162,38,68,51,249,185,233,128,52,216,30,36,240,210,130,138,111,161,204,127,3,174,
174,175,219,169,59,84,203,181,166,110,191,94,101,170,155,223,46,62,48,232,197,249,149,137,40,163,8,112,181,126,117,153,218,194,83,40,195,244,235,213,29,58,41,11,51,125,63,148,122,71,27,57,204,111,180,
246,245,82,187,38,198,62,96,92,215,185,142,128,192,0,41,79,100,18,54,42,12,224,75,123,135,227,143,15,4,186,249,186,61,31,197,163,158,206,30,106,222,169,10,8,60,102,238,120,226,179,19,1,58,77,228,153,125,
121,89,158,17,135,94,146,95,190,26,212,58,179,207,164,230,221,42,250,174,122,44,189,209,169,78,38,204,79,3,80,32,107,74,114,221,213,0,35,10,189,108,119,249,28,65,237,1,168,63,120,154,238,11,93,150,94,
71,116,40,25,203,179,16,77,64,177,189,40,215,189,255,230,179,17,131,206,217,81,158,96,154,106,63,16,210,116,236,60,205,39,46,90,122,53,155,70,230,170,44,236,17,118,64,14,102,119,184,243,250,61,31,94,212,
27,82,74,148,93,237,5,198,118,214,183,243,245,135,103,2,218,83,23,102,18,153,20,5,80,47,182,158,213,121,121,210,111,211,143,8,116,78,65,217,203,192,147,125,87,251,168,253,231,201,219,114,238,221,26,61,
59,137,248,25,163,1,174,138,200,162,194,23,31,110,189,211,51,236,121,122,241,206,47,103,41,100,59,10,206,22,87,227,233,182,62,120,81,227,162,73,94,144,14,160,20,252,168,104,163,251,43,127,190,97,93,233,
21,127,168,138,212,116,237,109,192,113,241,63,231,104,171,105,177,244,58,34,29,100,174,202,66,116,13,20,59,138,115,179,223,181,242,14,43,180,199,219,247,39,20,153,87,27,187,104,56,82,103,233,19,77,200,
88,153,133,61,42,4,224,72,123,71,219,47,2,205,59,108,208,57,187,202,214,136,226,89,195,99,112,122,127,224,27,111,220,188,20,162,38,196,0,210,96,120,189,79,127,146,247,184,55,208,220,195,2,253,84,193,137,
12,37,236,6,168,59,80,67,79,235,53,75,111,116,170,147,177,115,147,1,188,154,50,159,121,255,229,89,214,123,232,134,130,14,157,151,167,52,3,217,11,68,180,148,55,209,82,113,201,210,235,136,116,144,177,124,
42,162,129,8,175,188,183,105,198,167,3,137,17,116,232,114,103,217,75,40,30,237,235,234,165,238,112,173,165,79,68,72,95,54,5,123,132,3,224,3,119,155,251,213,129,198,8,42,116,206,174,227,83,76,228,87,40,
56,83,92,125,163,128,247,175,164,239,37,19,147,230,2,184,100,183,219,159,191,243,2,9,164,160,65,63,150,119,212,166,68,127,75,32,244,210,241,11,180,215,94,177,244,70,37,59,73,250,110,10,128,169,148,249,
220,190,23,178,154,238,39,86,208,160,93,78,215,207,129,217,189,109,61,52,124,104,157,222,236,17,118,50,151,79,65,52,64,169,109,197,155,102,126,116,191,177,130,2,189,116,215,137,108,5,191,84,74,113,166,
248,20,134,199,98,91,8,164,45,153,116,51,31,127,98,79,58,189,109,48,241,134,12,189,34,175,202,33,194,91,128,253,210,103,23,232,172,239,176,244,142,253,206,120,92,153,113,0,151,77,221,124,118,223,202,149,
198,96,98,14,25,186,207,229,221,170,144,233,61,45,215,104,248,232,172,165,47,124,76,36,227,31,79,5,48,69,100,117,201,250,153,141,131,141,121,87,193,244,212,174,138,52,67,51,95,0,30,65,145,166,160,22,97,
79,241,198,236,191,220,229,125,173,98,178,97,152,91,125,219,162,26,211,235,63,1,104,54,141,140,101,83,125,117,5,178,187,112,163,251,240,96,129,225,182,149,94,177,179,42,54,39,191,236,77,67,204,26,20,155,
81,124,27,136,19,152,35,138,55,151,20,148,111,239,55,82,41,49,13,227,117,32,164,249,120,35,93,231,172,183,197,248,249,105,132,197,135,35,80,229,140,137,222,58,20,96,0,1,95,195,196,166,241,129,130,36,229,
53,105,169,108,166,185,172,137,222,214,107,68,167,58,73,95,58,25,209,53,211,52,205,135,75,54,207,44,5,88,178,171,252,199,34,234,13,79,183,135,138,215,62,199,219,235,255,240,197,164,185,152,242,67,55,8,
30,83,99,78,201,134,236,19,67,133,182,229,236,40,79,80,154,58,170,32,190,171,161,131,179,197,255,229,122,235,245,91,134,150,202,102,194,18,35,72,122,36,89,211,68,127,17,120,126,113,126,101,162,96,188,
10,80,127,176,214,18,88,15,179,145,190,116,178,111,105,148,228,149,108,112,15,25,24,64,83,54,181,13,136,239,168,109,227,228,95,203,251,1,223,212,165,47,26,81,74,129,168,21,63,216,125,44,90,48,242,1,87,
91,77,11,87,78,54,91,78,158,250,68,38,142,232,16,20,124,106,79,170,30,240,53,125,79,104,132,249,0,245,135,106,80,22,7,201,211,209,75,199,217,118,128,240,16,51,116,143,192,211,134,199,75,221,1,235,218,
34,110,90,2,113,15,37,0,116,217,148,182,122,176,233,205,63,52,196,162,192,211,213,23,208,216,82,118,235,166,93,5,112,254,72,61,158,206,30,191,94,123,84,8,169,55,219,88,200,166,253,155,166,91,231,194,65,
72,67,168,68,32,60,49,34,160,241,202,169,203,24,61,190,189,219,125,161,139,166,47,206,251,55,10,164,47,201,68,15,179,129,146,226,162,92,247,222,96,2,3,104,10,42,0,34,198,68,6,52,154,94,147,166,210,70,
12,143,193,217,146,106,148,69,77,54,122,118,18,206,137,163,0,154,197,203,218,32,243,2,96,19,83,149,34,66,76,186,139,166,207,47,4,52,159,63,90,79,115,105,35,189,237,254,183,69,136,51,148,241,190,54,22,
38,242,147,146,45,110,235,83,58,4,105,226,213,14,2,70,76,122,44,154,93,15,104,86,134,105,9,12,144,246,228,36,116,135,142,18,222,46,201,117,151,4,153,245,150,180,194,45,238,102,5,199,52,155,134,51,221,
57,232,137,18,102,140,33,102,162,11,224,178,217,231,205,13,26,161,31,105,190,15,85,12,224,156,20,55,168,73,28,145,14,146,191,159,14,128,130,245,3,121,57,29,138,124,181,135,33,197,0,174,204,81,190,226,
252,62,149,186,208,151,45,4,85,18,168,201,18,44,105,0,133,47,101,215,8,84,217,35,28,68,167,184,238,107,130,81,211,226,113,77,137,3,161,163,207,148,117,195,66,121,135,110,173,171,137,252,29,32,110,122,
226,128,7,219,194,236,164,44,200,0,64,148,218,114,96,115,118,224,244,19,36,125,3,173,243,15,64,197,78,141,71,15,29,88,95,50,101,65,58,246,72,7,192,199,133,27,179,255,60,60,136,119,235,22,244,251,235,221,
117,32,135,116,135,78,226,172,49,247,28,232,156,24,75,156,123,52,192,53,52,125,45,34,214,253,219,32,171,255,177,19,118,2,140,157,59,1,91,184,221,114,144,45,220,70,218,162,73,190,33,138,87,138,54,60,20,
184,75,30,100,245,131,46,218,232,62,162,132,127,217,194,237,100,174,204,34,124,116,36,122,152,13,221,161,35,186,134,35,58,132,184,105,137,100,173,153,137,35,198,87,114,218,146,106,10,70,18,24,110,188,
185,220,174,69,5,165,19,116,165,127,12,146,126,143,145,149,70,159,119,222,112,231,100,255,161,253,40,231,247,159,141,50,189,161,191,209,80,115,21,140,5,98,240,253,19,160,21,168,84,168,247,18,195,140,55,
246,252,116,86,224,122,118,152,244,63,182,79,196,73,153,18,101,111,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::bigCheck_png = (const char*) resource_LiveMode_bigCheck_png;
const int LiveMode::bigCheck_pngSize = 2060;

// JUCER_RESOURCE: liveModeButtonDown_png, 1685, "../../UI/LiveModeButtonDown.png"
static const unsigned char resource_LiveMode_liveModeButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,6,18,
73,68,65,84,104,129,237,154,79,108,27,199,21,135,191,217,93,238,114,249,71,20,41,146,166,66,217,146,108,195,82,28,27,137,1,219,73,1,23,70,19,160,72,208,196,190,6,232,161,237,173,183,196,167,164,5,2,228,
150,220,234,222,114,244,197,65,142,73,78,190,24,9,80,23,176,19,183,14,44,199,144,138,36,86,101,169,162,37,211,18,255,139,203,93,110,15,20,87,90,137,180,92,73,43,50,42,191,19,31,102,222,204,155,217,223,
62,206,60,82,176,202,129,254,191,94,20,216,239,2,103,128,32,61,122,108,159,18,240,141,13,151,31,45,191,251,37,128,0,72,69,47,127,140,205,123,29,13,173,199,190,68,216,226,163,249,220,59,127,22,171,153,
236,243,78,7,212,99,255,98,139,250,5,105,245,235,178,71,15,207,16,182,116,73,2,78,119,58,144,30,251,158,211,18,16,234,116,20,61,246,61,97,197,243,41,196,186,207,182,231,179,117,150,103,93,171,120,134,
62,251,12,79,133,38,251,21,206,188,127,206,177,159,76,102,249,215,103,19,94,78,217,49,162,227,113,198,222,62,225,216,211,215,126,32,115,115,118,83,191,211,127,58,135,162,53,182,189,148,41,49,241,201,183,
123,22,99,39,241,62,163,109,3,33,4,106,191,230,216,117,163,78,173,100,116,48,162,255,29,159,238,67,139,250,169,21,13,234,181,58,106,88,69,40,18,66,108,237,187,163,121,131,42,146,42,57,182,177,92,197,182,
59,159,58,187,82,104,146,38,115,234,157,87,28,251,231,152,9,211,231,135,73,159,31,102,234,179,123,44,77,62,102,236,183,47,18,76,121,95,7,31,125,107,140,216,248,128,99,127,251,241,13,172,21,211,243,121,
183,162,43,133,102,91,54,249,233,101,199,174,44,20,157,207,254,152,142,26,89,203,118,165,185,2,150,97,1,32,36,65,120,56,226,180,153,165,26,229,133,82,75,191,141,243,21,102,114,187,186,134,38,129,100,16,
171,106,34,175,203,50,173,80,251,52,252,3,122,219,246,194,191,115,216,245,237,103,38,89,149,9,166,195,109,219,203,143,74,152,229,218,182,199,223,138,174,20,90,189,102,113,255,202,119,45,219,14,156,77,
51,248,202,144,99,223,253,228,54,229,76,67,136,146,42,115,252,119,47,57,109,235,51,225,70,191,245,152,85,147,219,31,221,216,173,240,93,28,124,117,244,153,250,197,142,39,24,121,253,104,219,246,157,102,
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

const char* LiveMode::liveModeButtonDown_png = (const char*) resource_LiveMode_liveModeButtonDown_png;
const int LiveMode::liveModeButtonDown_pngSize = 1685;

// JUCER_RESOURCE: patchEditorButtonNormal_png, 1956, "../../UI/PatchEditorButtonNormal.png"
static const unsigned char resource_LiveMode_patchEditorButtonNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,
8,100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,
0,7,33,73,68,65,84,104,129,237,154,203,111,219,86,22,135,127,124,235,109,73,177,106,25,85,19,21,137,49,174,10,20,242,160,83,100,22,3,120,21,100,54,211,44,218,69,119,70,255,129,241,172,138,14,48,64,87,
237,44,147,93,119,109,129,118,151,69,102,86,1,138,65,51,168,7,147,22,109,172,44,226,4,136,141,202,138,31,180,105,203,148,68,61,248,16,217,5,45,154,52,169,167,229,218,73,248,1,2,116,47,239,225,61,60,247,
220,123,207,225,37,129,67,166,226,183,222,37,96,44,2,248,3,128,48,124,124,70,167,14,224,71,3,184,185,35,46,254,27,0,8,0,72,39,110,254,19,6,62,58,83,213,124,94,72,8,131,248,108,187,242,215,191,19,135,43,
217,29,130,38,112,233,218,21,164,222,154,2,21,160,207,90,63,159,231,152,118,75,195,238,67,30,165,111,215,96,104,6,12,66,255,11,21,13,92,255,28,64,54,123,125,6,233,119,94,5,73,147,103,173,167,207,115,14,
73,147,136,102,98,160,56,26,149,213,50,8,16,105,18,192,219,0,144,122,107,234,140,213,243,121,209,176,249,212,219,36,128,8,0,127,187,244,25,59,116,144,233,252,141,246,247,46,99,128,59,18,39,81,231,5,96,
16,27,1,47,181,157,122,58,154,80,224,177,118,231,73,223,155,92,253,100,126,92,250,60,119,172,221,121,12,161,176,51,80,219,84,126,10,151,111,188,113,202,26,157,79,134,218,47,233,16,3,138,165,172,178,82,
149,97,232,6,228,131,22,8,138,0,27,227,78,164,76,91,105,67,171,171,71,253,133,157,253,13,131,34,41,48,84,221,42,115,137,192,137,116,27,20,54,198,129,32,189,151,46,58,204,246,149,151,15,90,214,127,130,
33,193,70,76,153,118,75,131,214,212,172,107,76,132,5,201,184,19,55,93,213,161,74,202,81,159,65,250,92,132,69,67,105,112,233,218,101,164,242,105,171,188,124,243,255,144,69,25,203,183,238,131,139,115,152,
91,252,227,137,148,41,175,8,142,21,244,242,141,89,71,127,195,176,122,251,17,170,197,138,85,254,173,86,221,55,63,156,3,23,31,221,169,151,111,221,183,254,199,178,19,200,45,204,1,0,182,239,111,96,227,94,
209,186,150,91,200,35,150,141,187,228,165,205,42,86,190,44,88,229,204,124,22,153,249,236,200,250,140,139,83,113,117,69,82,208,18,26,93,175,71,50,49,144,12,9,93,213,33,109,84,173,250,230,158,83,166,185,
215,64,245,23,177,175,220,113,2,169,208,9,180,63,159,112,241,160,195,177,168,128,21,104,59,108,212,216,145,28,114,178,216,116,92,15,79,71,172,21,206,94,239,234,47,17,176,38,76,131,151,28,171,169,23,76,
148,69,112,178,187,221,79,197,209,42,171,229,158,177,221,220,226,85,112,241,0,212,186,130,149,175,10,93,219,109,45,149,176,181,84,26,90,238,242,141,217,209,20,63,199,164,242,83,72,229,189,95,65,245,178,
133,80,216,113,196,144,246,149,176,151,156,125,37,44,222,125,234,216,29,186,233,215,43,254,28,202,209,106,165,138,35,195,106,43,237,195,78,210,160,195,71,51,44,112,33,232,185,229,85,86,203,80,36,5,229,
71,2,232,16,131,196,239,46,56,218,181,202,77,179,143,67,162,23,39,16,72,6,173,50,197,82,16,150,121,104,13,51,142,99,35,44,38,174,36,93,253,4,46,4,93,117,194,50,239,217,46,122,113,162,215,35,15,77,231,
217,0,128,226,72,36,115,175,120,182,171,149,42,104,237,55,251,222,175,85,110,162,182,238,30,228,137,153,164,21,191,217,109,168,74,10,196,213,178,85,14,165,35,8,167,35,86,153,141,176,40,175,236,162,45,
155,241,43,197,82,72,230,82,206,254,74,21,52,248,26,132,101,30,209,75,110,251,120,245,215,218,111,65,88,230,17,158,142,32,100,235,175,195,80,142,182,251,96,27,187,15,182,93,245,199,87,144,232,107,19,136,
190,230,86,112,229,203,101,40,146,130,245,111,215,0,152,113,147,93,86,40,240,14,71,123,229,247,211,46,135,93,251,215,209,74,25,152,12,14,188,122,217,229,58,164,242,83,99,119,180,206,179,1,0,23,231,186,
58,218,238,131,173,129,178,213,90,169,226,169,123,110,33,111,57,154,221,6,213,162,232,112,180,228,236,164,43,70,123,252,245,67,200,162,12,0,160,67,180,231,24,148,159,236,163,252,100,223,211,190,94,253,
213,158,85,80,123,86,65,102,62,123,114,71,75,204,78,58,102,71,55,26,188,132,242,227,61,87,189,44,182,60,90,255,54,216,141,45,139,45,8,5,30,13,94,194,198,119,69,196,94,143,123,6,214,163,144,190,154,1,125,
24,3,121,101,123,213,162,136,234,47,34,26,188,25,75,165,242,105,71,242,96,15,248,1,32,148,142,34,51,159,53,229,138,221,99,170,179,130,139,7,29,182,141,101,19,158,237,134,114,180,228,236,228,64,89,96,157,
151,176,241,223,226,48,183,62,117,236,198,168,22,69,8,5,30,117,190,142,58,95,71,134,200,142,205,209,166,175,102,122,102,157,213,162,232,176,77,42,159,118,244,125,220,209,194,233,48,194,233,48,54,238,21,
207,169,163,113,3,101,181,99,77,6,154,123,13,108,126,95,130,92,54,99,143,196,236,36,146,179,71,251,255,214,210,186,43,179,244,121,57,24,171,163,169,146,130,189,135,71,65,119,56,29,113,100,74,66,97,11,
77,247,142,234,243,18,48,86,71,11,77,71,144,91,152,67,101,117,31,155,75,37,8,133,109,84,108,239,106,154,124,189,167,124,252,74,18,185,133,57,8,133,109,8,5,30,155,75,37,236,218,178,197,153,247,115,200,
45,204,65,149,100,60,189,189,130,198,118,29,143,190,112,167,232,175,254,233,226,248,30,106,72,158,222,94,1,65,121,127,106,21,159,73,34,149,159,70,44,155,192,214,210,58,196,213,50,214,239,62,5,201,49,158,
237,1,64,92,45,99,243,251,18,148,138,51,67,237,200,205,188,159,179,146,2,160,255,24,188,254,231,43,152,121,239,77,232,154,113,152,156,169,14,27,170,117,243,84,33,149,79,35,149,159,70,112,50,8,161,224,
78,0,135,101,172,142,70,115,52,98,217,9,200,162,105,20,89,148,173,236,102,16,152,8,11,38,194,162,90,60,0,0,180,246,26,104,217,182,90,67,211,15,239,111,38,21,154,172,161,182,238,142,91,212,185,209,78,19,
198,65,207,23,201,9,14,92,220,252,9,5,211,185,234,125,38,159,42,41,158,207,216,145,51,52,221,81,223,111,12,180,150,230,136,9,13,77,247,188,63,23,15,32,150,29,95,70,78,164,227,55,13,192,251,136,70,87,219,
80,235,182,243,181,48,13,146,233,127,246,120,92,174,27,92,220,251,108,84,147,53,180,155,109,87,189,121,142,8,24,186,121,206,218,13,38,76,163,45,183,161,107,71,47,253,236,125,25,154,14,69,58,58,83,165,
130,20,104,110,180,57,167,53,84,180,21,189,127,67,0,20,75,90,239,216,6,145,35,105,2,20,71,245,180,101,199,38,199,233,54,6,108,132,1,113,248,113,107,175,69,192,110,19,85,82,186,218,178,31,247,63,185,7,
192,92,209,106,0,162,237,150,230,74,199,73,134,2,23,31,254,80,123,84,185,14,52,71,247,28,120,130,236,255,176,189,38,4,65,147,67,25,171,23,116,136,1,61,194,137,215,48,114,167,53,6,131,218,128,137,244,255,
24,192,11,173,105,77,230,42,9,224,103,0,216,125,232,126,115,238,227,115,18,118,127,182,98,187,159,168,112,224,250,1,1,124,80,45,30,128,226,104,132,46,132,60,63,63,241,241,25,20,173,169,130,255,97,19,207,
190,43,2,134,161,19,132,190,64,0,192,244,196,173,79,13,194,248,248,140,245,243,121,241,208,13,2,255,216,57,88,252,148,2,0,73,190,251,159,112,240,218,3,2,196,20,128,20,128,209,54,101,31,31,147,26,128,255,
17,132,190,192,31,252,237,27,0,248,21,182,244,243,145,168,167,223,238,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::patchEditorButtonNormal_png = (const char*) resource_LiveMode_patchEditorButtonNormal_png;
const int LiveMode::patchEditorButtonNormal_pngSize = 1956;

// JUCER_RESOURCE: patchEditorButtonOver_png, 2004, "../../UI/PatchEditorButtonOver.png"
static const unsigned char resource_LiveMode_patchEditorButtonOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
7,81,73,68,65,84,104,129,237,154,79,80,27,215,29,199,191,43,33,9,36,173,16,10,11,206,162,26,99,55,51,18,151,184,216,10,61,212,233,140,173,54,185,36,6,167,61,116,234,63,153,201,33,23,102,234,112,136,99,
218,30,11,158,250,96,220,56,51,5,78,69,211,28,92,91,194,61,133,105,201,161,74,103,140,108,148,248,80,88,79,99,8,84,38,38,187,225,143,100,1,187,250,215,131,172,213,174,119,245,15,148,128,241,126,102,52,
179,111,247,253,246,253,246,247,126,239,247,126,239,61,17,120,66,179,253,234,73,2,153,243,0,60,0,44,208,208,216,58,113,0,161,12,48,184,180,122,254,239,0,64,0,192,190,134,193,75,200,224,194,142,170,166,
177,39,33,50,196,192,215,107,191,233,35,158,68,178,49,131,49,141,11,23,22,112,242,13,22,164,45,181,211,250,105,60,195,196,162,122,4,110,81,184,124,121,63,18,130,14,25,34,253,166,158,172,125,253,207,0,
14,244,245,205,227,244,175,31,193,100,202,236,180,158,26,207,56,38,83,6,47,191,252,24,86,107,10,193,160,29,4,136,125,58,0,71,1,224,228,27,236,14,171,167,177,215,56,249,38,151,187,60,170,3,96,5,160,77,
151,26,85,167,190,62,153,187,36,107,74,85,206,100,136,146,47,36,136,231,123,186,45,199,70,192,243,109,167,162,142,22,8,80,184,120,241,80,201,151,48,204,237,170,41,244,172,241,193,7,135,48,54,70,149,85,
183,171,139,197,165,75,15,190,99,141,118,39,37,35,154,148,134,134,36,204,230,252,20,187,180,100,68,50,73,32,18,169,133,193,144,70,115,179,176,45,101,214,215,245,88,94,54,136,101,135,35,33,107,175,18,88,
206,8,126,83,39,150,157,206,205,109,233,86,46,205,205,2,106,106,212,35,151,227,133,68,73,249,72,164,86,188,54,213,166,65,53,102,109,26,139,234,177,22,205,219,134,162,4,152,76,105,133,60,207,235,192,178,
70,177,92,111,75,236,138,180,168,34,71,123,255,253,121,116,119,231,23,13,199,143,255,8,139,139,38,120,189,135,65,211,60,62,253,244,243,109,41,51,62,238,144,69,208,129,129,7,178,246,42,161,247,189,31,226,
206,29,155,88,254,190,162,238,199,31,255,7,45,45,252,150,229,189,222,195,226,181,199,19,133,207,55,13,0,248,203,232,139,184,118,205,41,62,27,29,157,198,43,175,68,21,242,247,238,89,113,246,108,187,88,238,
233,137,160,167,39,178,101,125,170,69,69,142,86,46,44,103,196,236,131,186,130,207,15,31,142,193,100,74,131,231,117,248,226,11,82,188,63,59,43,151,153,157,173,195,228,100,125,73,185,167,57,120,104,99,27,
218,239,78,156,78,94,230,88,54,73,148,146,218,232,62,35,183,97,36,98,146,61,111,119,63,22,35,156,244,190,178,189,77,113,192,48,51,102,89,52,85,131,106,18,112,176,173,176,221,191,19,71,251,44,88,95,52,
183,155,152,248,28,45,45,60,56,206,128,115,231,220,5,235,141,140,208,24,25,161,43,150,27,24,216,123,121,80,87,23,139,174,46,245,232,94,204,22,99,99,148,44,135,148,70,194,98,114,210,72,248,135,254,3,178,
217,161,144,126,197,242,207,138,28,109,106,138,148,173,176,214,215,245,0,128,238,110,22,13,142,124,254,209,218,186,169,58,229,125,22,172,7,203,25,49,254,201,11,176,55,36,113,252,248,178,172,222,252,66,
45,194,83,249,72,213,113,36,134,214,253,249,220,202,98,73,193,239,111,194,234,74,86,109,170,81,192,79,142,173,41,218,105,109,85,230,99,126,127,147,226,222,129,214,13,116,28,137,21,253,230,74,201,125,91,
86,223,36,94,123,109,89,181,94,120,138,196,87,243,133,163,126,142,249,249,90,76,77,41,59,249,216,171,171,98,254,38,181,33,199,25,16,12,218,197,178,203,189,14,183,43,46,150,41,42,129,241,113,7,226,241,
172,13,205,230,148,76,199,92,31,204,204,152,225,247,55,225,200,17,229,244,172,214,222,194,66,45,252,254,38,180,187,31,195,229,94,87,200,84,228,104,55,110,52,225,198,13,101,135,61,29,65,58,58,98,232,232,
80,118,224,153,51,237,96,57,35,254,120,121,63,0,128,97,190,145,201,6,2,148,204,209,126,249,139,111,20,14,219,215,119,80,188,62,208,182,89,118,244,146,202,229,232,234,98,171,238,104,185,111,3,0,154,230,
11,58,218,245,191,53,149,181,90,13,135,73,85,221,71,71,167,69,71,147,218,32,20,178,201,28,205,123,98,89,145,163,189,243,142,11,139,139,38,0,128,221,158,84,237,131,137,9,7,38,38,28,170,246,85,107,47,28,
38,17,14,147,232,233,137,108,223,209,78,120,87,100,163,163,16,204,140,25,255,248,167,67,113,255,225,67,83,37,205,85,21,169,177,31,62,52,33,16,160,192,48,102,124,248,161,19,157,157,81,213,196,122,43,156,
61,247,8,54,50,27,209,108,42,171,189,80,200,134,201,73,27,24,198,12,32,27,29,164,139,7,105,194,15,0,110,247,58,122,122,34,8,133,108,8,133,138,79,95,59,129,211,201,203,108,219,217,169,110,199,138,28,205,
123,98,185,172,85,224,12,99,193,71,31,57,75,214,251,62,145,26,35,20,178,61,113,52,11,24,198,2,130,136,84,205,209,206,157,253,186,232,170,51,20,178,201,108,211,221,205,202,218,126,218,209,92,174,56,92,
174,56,174,93,115,238,74,71,163,105,190,172,85,109,85,23,3,179,115,117,24,26,162,241,191,133,236,94,208,9,239,10,126,230,205,79,29,195,67,52,102,231,74,231,37,26,123,143,170,58,26,199,26,112,75,146,119,
184,93,113,217,74,233,230,77,74,115,180,231,148,170,58,154,219,29,135,207,55,141,224,191,234,49,60,210,2,191,159,194,237,219,249,112,127,255,126,241,63,238,30,59,182,10,159,111,26,126,63,133,64,128,194,
240,48,141,155,55,243,142,123,101,240,75,248,124,211,96,89,3,122,123,95,2,195,88,112,250,116,187,226,61,239,190,187,88,189,143,170,144,222,222,151,96,48,40,119,236,1,224,213,159,174,225,212,41,22,157,
157,81,12,15,211,8,6,237,232,239,111,133,213,90,120,231,62,24,180,99,104,136,22,147,247,28,57,185,43,131,95,138,139,2,160,116,31,252,238,183,95,225,202,149,255,66,16,116,56,115,166,29,28,103,144,217,240,
219,111,179,251,101,221,221,44,78,157,98,209,214,182,1,191,191,188,35,182,98,84,213,209,72,50,5,143,39,138,72,36,107,148,197,69,147,194,64,197,104,108,76,160,177,49,129,201,201,172,97,230,230,234,48,39,
137,128,2,79,192,227,137,138,139,138,88,76,143,187,119,149,121,203,91,111,237,220,95,158,238,221,179,22,124,230,116,242,160,233,236,47,55,128,24,166,248,224,227,56,131,234,55,230,228,4,94,126,160,95,170,
15,162,177,26,89,78,40,8,58,213,247,183,180,240,240,120,170,147,183,2,0,177,207,62,152,201,42,174,60,162,217,216,208,97,101,37,191,35,220,208,144,64,93,157,250,104,45,38,87,8,154,86,79,154,99,49,61,98,
49,229,24,104,110,22,160,215,103,144,74,17,88,90,50,170,72,230,245,140,199,245,16,132,252,89,167,180,45,65,208,129,227,242,250,145,100,18,36,185,181,243,192,213,213,26,113,63,177,20,102,115,10,118,123,
178,108,57,163,49,13,139,37,85,212,150,57,155,60,77,161,62,104,108,76,192,104,204,246,97,177,32,32,181,9,199,25,10,218,178,20,46,215,143,1,100,29,45,10,128,188,19,186,179,43,14,95,53,246,14,107,107,53,
232,236,60,10,0,81,29,128,41,0,8,220,218,254,60,172,161,33,229,250,117,113,115,255,174,222,82,251,250,10,1,252,234,246,164,13,86,107,10,109,109,155,170,127,63,209,208,40,151,181,181,26,248,124,251,112,
245,79,63,64,58,77,164,9,34,253,54,1,0,47,214,95,237,207,16,153,139,59,173,160,198,158,35,157,33,240,251,165,149,243,253,122,0,120,204,127,50,97,169,251,121,152,0,209,12,128,2,80,56,211,214,208,40,77,
12,192,191,9,34,253,246,163,149,247,254,10,0,255,7,245,5,236,241,0,6,12,109,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::patchEditorButtonOver_png = (const char*) resource_LiveMode_patchEditorButtonOver_png;
const int LiveMode::patchEditorButtonOver_pngSize = 2004;

// JUCER_RESOURCE: patchEditorButtonDown_png, 1806, "../../UI/PatchEditorButtonDown.png"
static const unsigned char resource_LiveMode_patchEditorButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,
100,136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,
6,139,73,68,65,84,104,129,237,154,207,107,219,102,24,199,191,146,101,201,63,100,91,113,162,68,249,81,199,37,9,180,233,161,118,233,160,131,148,117,135,141,238,178,238,208,227,96,221,95,208,246,52,24,12,
122,219,110,203,254,129,145,75,79,221,33,236,178,50,24,4,198,88,24,91,237,75,189,148,52,212,109,51,236,212,174,237,248,183,100,217,218,193,142,44,69,242,175,196,105,210,84,31,48,232,125,245,62,122,30,
61,239,163,87,207,163,215,4,90,76,112,63,220,32,160,220,1,240,30,0,55,44,44,14,78,9,192,95,10,176,188,147,187,243,51,0,16,0,32,140,44,127,7,5,95,29,171,105,22,167,18,66,33,190,77,236,222,254,154,104,173,
100,171,199,109,144,197,233,69,33,26,159,146,173,215,165,133,197,145,65,40,228,93,18,192,229,227,54,196,226,212,115,153,4,192,30,183,21,22,167,30,15,213,115,8,209,199,101,148,195,91,242,86,211,143,143,
128,119,218,79,93,3,141,15,9,152,251,236,92,207,139,172,223,91,27,150,61,111,29,115,159,157,7,31,154,232,107,108,42,186,131,173,213,127,143,216,162,147,73,239,21,77,131,92,174,161,46,213,213,54,237,101,
64,144,4,152,17,7,148,186,2,41,47,30,202,24,27,109,3,229,182,183,245,149,244,250,6,129,102,105,16,118,82,109,139,217,234,161,108,235,23,41,47,66,105,152,47,93,114,73,234,41,207,140,56,212,99,165,214,128,
84,108,202,216,28,20,40,103,123,186,106,5,9,13,185,97,144,39,41,18,118,15,221,214,89,145,81,175,202,125,219,127,84,12,20,104,207,127,221,66,42,154,84,219,225,59,239,131,225,24,132,111,95,129,152,19,17,
89,254,243,80,198,248,23,121,221,10,186,181,186,161,211,55,8,243,55,47,192,27,244,169,237,55,181,234,62,254,49,2,49,119,240,160,14,223,190,162,30,231,227,187,136,173,68,0,0,147,87,102,48,115,45,168,158,
139,173,68,145,143,231,12,242,236,140,23,139,183,66,106,123,123,45,142,237,181,248,129,237,25,22,3,5,90,191,208,44,13,7,239,234,120,190,248,50,143,134,220,0,73,145,96,207,120,213,126,231,152,94,198,57,
230,130,247,44,215,83,110,63,213,84,249,16,214,159,76,196,92,69,23,88,245,106,77,61,214,250,200,53,161,175,237,24,206,169,59,95,74,20,213,21,78,219,111,208,151,173,170,15,140,75,96,117,171,169,25,181,
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

const char* LiveMode::patchEditorButtonDown_png = (const char*) resource_LiveMode_patchEditorButtonDown_png;
const int LiveMode::patchEditorButtonDown_pngSize = 1806;

// JUCER_RESOURCE: addButtonNormal_png, 1087, "../../UI/AddButtonNormal.png"
static const unsigned char resource_LiveMode_addButtonNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,3,188,73,
68,65,84,104,129,237,154,77,108,19,71,24,134,159,217,93,255,199,205,175,177,73,80,224,64,171,72,37,156,2,226,192,161,39,148,83,123,109,123,226,216,91,211,83,213,74,149,56,1,199,228,82,113,237,129,123,
133,84,169,82,5,109,165,84,4,26,74,3,18,130,54,144,200,113,18,199,4,59,254,89,59,246,254,76,15,118,12,14,73,156,70,37,46,187,251,72,43,205,236,124,179,251,106,245,234,155,153,157,17,52,136,247,76,125,
36,144,19,192,25,32,130,135,199,193,209,129,187,18,38,215,54,38,110,0,8,128,68,239,228,85,36,95,118,84,154,135,35,17,82,92,89,205,127,254,181,104,100,178,239,133,38,56,126,225,36,177,211,113,212,160,214,
105,125,30,111,49,214,166,73,102,46,77,242,167,167,72,83,34,133,253,161,26,13,142,95,3,78,156,24,127,151,196,217,33,20,77,233,180,78,143,183,28,69,83,136,30,123,7,53,160,145,159,207,34,16,9,5,24,3,136,
157,142,119,88,158,135,211,120,197,83,99,10,208,5,120,195,165,199,127,142,22,242,109,21,163,222,56,9,32,27,151,199,27,195,245,105,108,246,202,52,102,213,4,32,146,136,48,250,217,153,14,43,114,38,174,53,
90,173,88,67,154,54,242,149,76,102,155,146,106,110,19,197,175,224,139,248,219,62,67,74,73,109,163,218,172,239,167,95,45,95,69,218,245,151,10,77,193,31,109,255,30,39,224,90,163,61,185,62,135,158,214,91,
238,85,214,203,220,159,154,161,111,164,159,247,62,30,109,251,12,187,106,113,127,106,166,89,223,79,191,7,223,254,238,202,12,234,58,163,149,51,58,166,110,96,213,108,0,162,195,221,8,69,0,96,213,44,244,149,
34,134,110,82,88,216,192,223,29,32,216,23,234,164,92,199,224,58,163,165,110,61,35,251,248,69,179,62,242,233,104,115,197,93,78,151,120,112,109,150,226,82,158,71,223,253,201,209,115,199,56,62,126,178,83,
82,29,133,235,140,182,157,245,135,153,230,79,234,106,97,115,215,184,252,66,174,101,62,6,96,155,246,174,241,165,229,2,149,76,249,181,251,182,181,123,31,39,227,122,163,45,252,240,215,190,226,214,238,164,
90,50,97,59,94,60,204,176,58,147,58,168,44,199,225,122,163,13,157,31,70,52,50,154,81,170,177,54,187,210,210,190,49,159,165,180,84,160,188,94,1,32,62,54,136,175,171,190,82,148,166,205,242,116,178,37,190,
152,42,144,255,59,75,49,85,0,96,224,212,17,130,3,225,102,251,202,116,114,207,76,232,84,92,111,180,193,243,195,45,115,180,237,70,203,207,103,91,50,83,124,108,144,112,162,11,168,111,30,111,55,154,158,42,
144,250,117,177,89,239,63,117,132,222,145,129,102,61,125,59,229,74,163,121,59,3,30,135,130,103,52,143,67,193,245,67,103,59,226,103,135,232,29,137,177,116,235,25,197,100,158,167,55,158,160,248,212,122,
163,253,250,6,105,255,251,49,194,137,40,233,187,203,100,31,101,72,222,92,96,229,246,203,161,215,50,204,195,146,254,191,194,51,90,27,130,125,33,130,125,33,124,225,250,167,210,87,138,123,198,251,162,1,124,
209,0,185,199,207,1,168,60,215,247,140,119,11,34,209,51,41,1,206,93,250,160,195,82,14,7,67,55,176,141,151,147,241,64,119,160,113,160,29,108,75,98,20,107,205,54,45,160,162,134,180,29,251,237,132,226,83,
240,69,234,71,99,172,138,137,89,181,246,140,23,154,192,223,229,236,189,206,153,75,191,0,245,140,86,4,162,214,166,233,138,51,105,91,70,216,9,69,21,4,122,2,255,186,223,78,168,33,173,105,82,183,98,86,140,
173,98,65,1,238,1,100,230,210,29,19,228,225,76,50,247,86,183,138,179,106,36,56,158,19,240,73,97,49,135,26,208,8,247,135,81,124,222,98,212,227,224,152,21,131,244,157,101,150,126,94,4,41,109,33,236,139,
2,224,104,247,212,101,41,228,87,29,214,231,225,60,108,41,248,102,45,55,113,89,5,40,85,127,188,25,9,93,248,67,32,226,64,12,112,246,12,213,227,77,83,4,126,19,194,190,152,206,125,113,29,224,31,89,225,91,
148,179,33,69,87,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::addButtonNormal_png = (const char*) resource_LiveMode_addButtonNormal_png;
const int LiveMode::addButtonNormal_pngSize = 1087;

// JUCER_RESOURCE: addButtonOver_png, 1141, "../../UI/AddButtonOver.png"
static const unsigned char resource_LiveMode_addButtonOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,3,242,73,
68,65,84,104,129,237,154,93,76,91,101,24,199,127,111,75,191,214,79,24,148,130,91,39,122,33,120,177,45,58,18,239,97,134,96,6,122,37,70,178,237,6,110,135,87,68,212,11,189,152,38,187,88,49,33,234,118,161,
27,51,89,118,51,166,51,113,89,184,177,49,1,227,8,176,45,54,14,73,102,54,58,6,182,66,75,211,158,210,115,188,104,105,211,241,81,36,186,51,122,206,239,234,188,237,251,52,255,147,254,207,243,190,207,243,30,
65,142,90,207,96,167,64,233,3,154,1,59,58,58,59,103,5,248,69,129,192,252,223,125,223,1,8,0,95,101,224,51,20,250,85,149,166,83,150,8,69,124,26,94,58,53,32,114,153,108,196,100,150,233,239,255,147,206,99,
11,56,93,25,181,245,233,236,98,98,203,70,174,94,171,225,204,25,63,105,201,128,34,228,14,163,211,218,246,37,240,252,192,192,125,186,223,125,132,197,162,168,173,83,103,151,99,177,40,28,58,20,199,225,200,
16,12,122,16,8,159,1,56,2,208,121,108,65,101,121,58,229,70,103,199,226,218,229,17,3,224,0,244,229,82,231,63,199,237,94,93,187,116,26,212,20,242,172,160,40,2,69,17,106,203,40,107,42,212,22,160,54,205,205,
205,196,98,70,0,26,27,87,24,25,185,173,178,162,242,68,179,70,123,252,216,140,36,25,144,229,194,103,105,201,192,131,7,86,108,182,85,246,238,93,221,60,56,135,44,195,220,156,53,63,222,78,92,56,108,33,147,
201,102,79,179,89,198,235,149,118,118,3,187,12,205,26,173,183,247,37,66,161,226,190,244,31,179,54,90,91,15,211,210,18,97,104,232,247,146,191,177,18,55,210,218,122,56,63,222,78,92,71,199,65,77,102,80,205,
25,237,222,189,61,68,34,38,18,137,236,159,253,202,171,49,42,140,217,150,78,34,97,228,206,29,59,209,168,137,241,113,55,62,95,138,3,7,146,106,202,45,27,52,103,180,64,96,31,163,163,85,249,241,87,95,132,242,
21,119,232,183,61,188,249,214,65,38,38,156,156,56,209,196,241,227,97,6,6,238,171,37,181,172,208,156,209,158,228,251,31,170,177,230,154,212,225,176,121,211,121,99,99,174,162,253,24,64,50,181,121,165,58,
61,109,103,102,102,253,145,177,36,105,179,186,213,188,209,62,249,184,97,91,243,134,135,125,69,153,176,20,215,175,87,115,241,98,221,78,101,149,29,154,55,90,111,207,67,204,185,140,182,184,104,226,242,229,
218,162,239,131,65,15,147,147,14,102,103,109,0,116,117,205,83,93,157,6,64,74,9,206,157,127,174,104,254,228,148,147,224,79,110,166,166,156,0,188,209,190,72,195,11,133,125,222,249,115,245,164,36,237,181,
47,53,111,180,158,158,185,162,61,218,122,163,185,139,50,83,215,219,243,52,54,37,128,236,225,241,147,70,155,158,180,51,52,180,47,63,110,111,255,139,150,214,104,126,124,225,66,29,41,109,116,52,138,208,222,
163,165,163,10,186,209,116,158,10,154,95,58,75,209,221,61,207,209,163,81,206,6,246,51,113,203,201,7,31,190,136,205,150,93,106,101,121,125,5,217,214,22,161,233,229,4,151,46,249,184,113,163,138,179,1,63,
95,127,83,88,122,19,9,109,62,219,186,209,74,224,247,39,241,251,147,84,122,178,5,192,221,187,91,191,229,238,173,149,240,214,74,220,188,89,9,192,204,140,13,176,253,223,50,159,121,132,207,19,80,0,66,161,
49,181,181,60,21,34,17,19,201,100,33,171,212,213,73,8,145,173,58,211,105,193,194,66,161,151,230,112,100,112,185,86,55,140,219,8,171,85,166,170,42,107,200,229,229,10,226,113,227,150,243,43,76,50,222,154,
244,142,238,99,183,208,216,248,26,144,205,104,49,192,25,91,54,106,226,157,180,53,35,108,132,201,164,80,95,159,250,215,113,27,225,114,173,230,77,170,85,150,150,242,11,230,178,1,184,5,112,245,90,141,106,
130,116,202,147,43,87,188,107,151,191,26,237,214,182,168,128,119,198,198,93,56,28,25,26,26,146,88,44,242,86,241,58,58,91,178,180,84,193,240,176,143,193,207,247,35,203,66,22,66,62,41,0,234,220,131,167,
21,161,188,175,182,64,157,178,67,86,4,31,205,71,251,78,27,1,226,169,31,71,237,182,215,39,4,162,22,168,1,54,63,93,214,209,41,77,12,248,89,8,249,228,163,232,123,223,2,252,3,77,29,67,181,182,56,151,43,0,
0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::addButtonOver_png = (const char*) resource_LiveMode_addButtonOver_png;
const int LiveMode::addButtonOver_pngSize = 1141;

// JUCER_RESOURCE: addButtonDown_png, 968, "../../UI/AddButtonDown.png"
static const unsigned char resource_LiveMode_addButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,3,69,73,
68,65,84,104,129,237,154,79,111,27,69,24,135,159,153,93,175,227,172,215,118,220,198,49,142,19,53,165,45,85,165,32,14,14,80,17,132,84,36,36,132,84,62,2,28,115,107,115,162,69,66,226,70,111,13,55,190,64,
17,199,170,167,92,184,21,9,149,180,151,20,41,32,46,68,52,117,218,252,105,112,28,123,189,246,46,7,27,131,83,215,110,42,149,69,59,243,72,62,140,103,222,221,223,142,126,251,206,188,30,11,58,76,100,190,254,
88,16,92,6,230,0,27,141,230,197,169,2,119,2,88,218,124,114,249,22,128,0,200,143,45,93,35,224,179,80,165,105,34,137,8,196,87,15,247,46,125,46,58,153,236,102,216,130,52,209,37,16,254,69,217,89,46,53,154,
151,134,8,228,162,4,74,97,11,209,68,158,146,4,146,97,171,208,68,30,71,134,173,224,127,129,232,124,52,47,13,51,108,1,97,83,186,58,143,25,111,79,67,181,92,101,245,155,159,66,86,20,77,148,53,154,229,88,8,
83,34,254,149,201,164,41,136,143,141,224,55,124,188,106,99,232,53,132,16,88,153,120,183,253,60,113,86,58,142,144,237,155,6,77,159,70,101,248,125,162,128,200,103,150,130,176,69,132,193,236,194,28,118,190,
255,239,210,59,107,219,252,250,221,234,208,107,24,35,38,115,87,230,143,20,167,106,6,85,46,163,141,230,108,76,59,134,97,181,183,167,149,245,61,2,191,253,174,25,150,129,93,112,136,217,38,169,153,12,141,
61,151,250,78,45,76,185,145,65,57,163,21,47,156,36,123,246,88,183,189,246,237,42,173,122,19,128,209,124,146,215,23,74,56,83,105,206,125,242,6,15,127,252,131,223,151,127,11,75,106,164,80,206,104,135,57,
62,155,195,111,250,0,196,83,35,207,28,151,158,25,235,217,143,1,72,243,217,69,123,114,50,69,34,55,250,212,247,210,80,179,208,87,222,104,51,31,157,121,174,113,19,111,21,123,50,225,48,142,205,230,120,229,
237,226,139,202,138,28,202,27,237,193,237,117,130,78,70,139,37,45,38,74,133,158,254,204,169,44,201,169,20,163,199,19,0,108,174,108,224,237,183,43,69,97,74,38,231,167,123,198,59,197,20,233,211,89,156,98,
10,128,173,251,143,168,111,29,116,251,11,239,76,35,99,234,101,53,229,141,182,113,123,189,103,143,118,216,104,233,83,217,158,204,180,185,178,193,65,121,31,104,87,157,135,141,102,23,83,20,223,59,209,109,
111,223,127,196,238,218,86,183,157,63,95,68,162,158,209,212,123,98,77,40,104,163,105,254,19,148,95,58,135,177,121,231,1,187,107,143,153,186,112,18,103,58,205,171,23,95,195,247,90,237,78,249,244,1,233,
246,207,143,57,40,87,200,191,57,73,246,92,142,233,247,103,40,156,255,103,233,53,98,106,78,185,154,79,125,4,234,59,53,234,59,53,188,131,246,62,206,46,56,3,199,123,21,23,175,226,50,118,118,28,128,196,184,
254,87,60,40,120,4,21,179,99,61,85,159,187,231,66,103,6,164,33,136,57,86,183,175,233,182,104,213,154,125,227,250,225,123,62,94,213,3,192,72,152,152,113,99,224,248,160,25,208,216,87,227,172,211,4,42,192,
224,215,52,66,252,109,132,126,248,173,0,247,137,123,228,184,126,180,106,205,174,73,53,252,41,129,187,97,171,208,68,158,21,25,192,245,176,85,104,34,141,47,132,255,165,81,173,47,255,226,196,63,140,35,120,
55,108,69,154,200,225,7,130,47,202,187,139,55,12,128,125,119,249,123,59,241,193,61,129,152,0,198,1,107,112,188,70,51,144,10,240,131,16,254,167,229,221,197,27,0,127,1,110,47,239,210,133,73,97,13,0,0,0,
0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::addButtonDown_png = (const char*) resource_LiveMode_addButtonDown_png;
const int LiveMode::addButtonDown_pngSize = 968;

// JUCER_RESOURCE: replaceButtonNormal_png, 1625, "../../UI/ReplaceButtonNormal.png"
static const unsigned char resource_LiveMode_replaceButtonNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,214,
73,68,65,84,104,129,237,155,207,79,27,87,30,192,63,111,102,236,49,102,252,35,14,14,134,32,199,21,68,114,89,169,130,170,187,77,165,84,202,169,202,105,203,161,61,244,198,127,80,122,90,109,165,74,57,181,
61,210,91,111,85,15,123,139,180,233,158,162,93,85,77,165,172,182,187,106,130,115,72,138,20,179,53,132,212,3,38,254,109,240,216,99,79,15,6,131,177,29,12,9,177,141,252,57,205,123,239,251,125,243,253,250,
125,245,157,55,223,55,22,236,50,234,253,234,125,129,181,0,252,17,24,102,192,128,147,83,0,254,103,193,226,70,122,225,31,0,2,32,112,110,241,75,44,254,210,85,211,6,156,73,132,37,190,136,103,62,254,84,236,
102,178,91,66,17,92,122,111,10,255,27,163,200,14,165,219,246,13,232,99,42,69,147,205,7,58,107,255,90,193,50,45,44,81,253,179,236,114,92,255,26,8,133,174,95,38,240,167,139,72,138,212,109,59,7,244,57,146,
34,225,154,112,35,171,10,153,104,18,129,8,72,192,91,0,254,55,70,187,108,222,128,179,198,129,152,122,75,2,52,96,240,184,28,240,210,81,134,108,123,151,174,222,142,46,171,3,25,113,234,86,12,120,9,244,108,
160,25,233,34,75,139,63,29,41,55,61,63,131,59,228,125,5,22,13,120,17,122,54,208,14,35,219,101,20,103,61,21,99,110,151,169,148,42,148,242,37,140,84,17,187,71,69,72,167,155,222,74,249,18,86,185,218,208,
39,100,129,221,173,158,234,125,207,2,125,19,104,190,233,17,38,231,94,175,183,87,110,253,66,34,178,65,244,230,35,0,102,23,174,160,122,29,167,106,67,244,230,67,178,177,76,67,159,234,85,153,93,120,231,84,
239,123,22,232,155,64,235,148,106,185,74,126,61,219,118,220,225,119,98,215,236,0,228,214,179,77,25,234,48,234,57,71,61,128,157,1,23,32,200,175,103,169,154,237,245,140,116,17,35,85,108,59,238,126,173,241,
81,95,202,151,40,38,182,219,202,107,19,110,36,155,116,44,223,122,141,51,23,104,229,66,137,71,223,70,218,142,79,206,133,241,207,4,128,90,134,50,210,198,115,231,155,184,22,98,226,90,8,128,208,245,41,0,150,
22,255,243,92,189,68,68,103,253,78,172,237,248,149,27,215,26,218,153,104,146,149,91,203,109,229,247,178,245,113,124,235,53,250,38,208,138,207,138,36,150,244,134,54,128,119,202,135,77,179,35,219,101,18,
75,58,230,118,25,0,187,102,199,51,229,171,203,23,244,60,219,122,158,220,90,6,44,240,92,246,53,204,47,219,101,124,211,254,253,249,147,59,228,214,50,108,235,57,18,75,58,174,75,30,28,190,161,142,108,117,
6,92,45,23,60,249,40,65,165,84,33,177,164,35,171,18,90,208,75,230,113,146,220,147,204,174,158,198,112,64,107,210,59,137,111,189,150,217,250,38,208,114,79,50,245,5,57,200,248,213,96,253,173,115,229,187,
253,172,224,24,25,98,114,46,92,111,175,223,137,177,173,231,217,188,31,103,243,126,156,233,249,153,134,121,20,167,210,32,159,136,232,228,214,50,36,151,159,145,92,126,198,228,92,184,227,64,243,133,207,227,
11,159,111,234,207,198,82,84,74,21,86,190,91,70,245,170,76,206,189,222,96,179,47,60,82,207,158,135,57,174,111,131,64,123,73,156,11,143,48,28,208,80,189,173,23,223,72,23,89,255,33,86,111,103,87,83,175,
200,50,200,198,210,100,127,77,55,245,87,118,42,47,101,254,110,250,118,82,250,54,208,124,225,145,231,238,71,140,180,193,250,143,177,87,103,208,1,178,177,244,169,222,187,155,190,157,148,190,9,52,87,208,
195,133,55,199,73,46,39,72,45,111,177,121,47,78,230,215,52,23,223,13,50,52,226,108,146,31,26,113,50,126,245,82,219,249,14,235,148,11,38,209,191,239,63,158,140,228,14,80,203,156,190,176,31,87,208,125,164,
141,185,181,12,27,247,226,236,108,228,0,184,240,230,56,174,160,167,62,190,250,207,104,125,159,245,34,28,215,183,94,160,111,2,205,225,115,224,159,25,197,72,239,144,90,222,170,239,217,46,204,6,90,254,176,
54,205,134,127,166,243,15,5,170,229,10,91,15,244,166,254,225,128,214,241,60,197,228,78,195,28,174,160,187,65,119,253,206,255,49,219,87,49,58,230,184,190,245,2,125,19,104,123,248,103,198,112,135,206,241,
219,221,85,210,209,36,171,183,31,35,169,54,46,127,56,205,244,252,44,229,188,193,227,155,143,216,142,23,120,248,77,115,41,224,226,187,65,188,83,190,166,126,187,102,103,234,131,63,52,245,31,44,2,175,222,
142,146,143,231,41,229,247,179,82,41,95,230,225,55,17,180,49,141,241,171,65,166,231,103,73,68,226,36,34,58,79,239,174,177,121,224,77,249,160,30,128,115,76,99,122,126,150,76,244,25,79,239,174,145,136,212,
178,244,97,94,212,183,94,160,239,2,77,245,170,168,94,149,68,164,118,28,85,208,11,0,88,102,21,119,200,131,145,174,149,61,76,195,36,183,218,188,104,229,217,214,251,58,161,8,220,33,79,203,177,61,10,122,142,
220,106,227,155,175,101,86,201,173,166,17,194,194,166,217,177,105,118,178,177,218,230,188,184,181,77,113,171,125,10,83,84,101,215,230,218,99,218,72,27,45,235,115,47,234,91,47,32,2,222,69,11,154,139,136,
221,198,170,66,41,187,255,163,203,118,169,197,89,231,126,117,222,238,86,17,82,179,222,97,108,195,10,146,77,6,26,11,175,157,28,37,149,243,37,170,102,235,79,74,36,69,96,219,45,41,152,134,121,228,27,166,
36,131,205,85,59,35,173,150,43,148,11,102,91,217,147,248,214,43,252,116,227,14,80,203,104,57,192,85,41,154,61,245,77,154,144,106,139,223,14,197,105,67,105,177,231,61,74,239,144,116,155,235,214,216,58,
172,77,41,170,130,162,118,254,91,74,54,25,213,123,116,128,28,207,183,238,99,238,212,183,10,89,5,184,7,92,219,124,160,51,246,246,68,247,172,234,2,179,11,87,186,109,194,153,102,243,94,124,239,242,103,121,
216,113,61,37,224,163,108,44,133,172,42,56,207,59,145,108,131,255,13,12,56,57,230,78,25,253,191,79,121,242,67,12,44,171,42,68,117,94,0,140,121,190,250,220,18,214,95,187,108,223,128,179,71,213,18,124,182,
145,90,248,92,6,200,27,183,191,31,30,122,239,190,64,140,2,126,160,183,14,202,6,244,27,57,224,223,66,84,231,245,212,39,127,3,248,29,23,67,114,157,140,181,137,230,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::replaceButtonNormal_png = (const char*) resource_LiveMode_replaceButtonNormal_png;
const int LiveMode::replaceButtonNormal_pngSize = 1625;

// JUCER_RESOURCE: replaceButtonOver_png, 1710, "../../UI/ReplaceButtonOver.png"
static const unsigned char resource_LiveMode_replaceButtonOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,6,43,
73,68,65,84,104,129,237,154,77,80,91,85,20,128,191,75,72,30,249,121,33,180,73,192,128,182,208,58,66,23,254,128,168,11,113,28,131,213,77,91,106,167,206,56,254,117,211,178,233,140,45,46,218,50,227,182,224,
56,163,109,173,51,78,221,213,113,161,173,161,184,210,177,113,81,116,166,80,72,127,22,37,206,136,88,76,98,107,24,2,164,4,18,154,60,23,129,64,8,41,63,45,38,97,242,173,222,189,247,220,123,207,121,57,57,247,
220,123,159,96,134,82,211,201,93,2,229,16,80,15,232,201,147,103,245,76,0,61,10,156,184,51,122,232,7,0,1,80,86,114,162,29,133,35,25,85,45,207,186,68,40,162,237,159,177,15,90,197,76,36,187,160,214,196,56,
114,100,136,93,59,252,200,198,104,166,245,203,147,195,4,199,85,116,116,90,248,228,147,199,152,142,20,160,136,216,78,149,92,244,250,151,192,230,214,214,91,188,243,246,109,36,73,201,180,158,121,114,28,73,
82,120,234,169,187,24,12,81,186,186,76,8,68,89,1,240,44,192,174,29,254,12,171,151,103,189,177,107,231,240,236,227,179,5,128,1,200,47,151,121,30,58,197,197,247,102,31,229,194,76,42,178,20,138,34,150,148,
17,34,191,212,231,2,89,235,104,94,175,132,221,254,204,146,114,103,207,222,228,185,231,198,255,7,141,242,60,8,89,235,104,11,209,233,162,148,148,36,66,49,129,64,33,161,144,10,255,176,6,143,167,136,178,178,
48,133,133,107,27,221,252,195,26,194,83,5,73,117,106,117,140,210,210,200,154,206,187,30,200,25,71,219,190,125,132,246,246,129,68,249,232,209,45,92,184,96,225,195,150,173,0,56,157,87,41,47,15,175,169,14,
45,135,183,114,229,138,49,169,206,102,11,243,203,47,87,215,116,222,245,64,206,56,218,114,9,135,11,184,118,77,78,219,94,181,101,18,139,57,30,129,174,93,151,83,34,212,66,42,42,166,18,14,92,179,45,132,16,
112,253,154,129,112,36,125,63,175,87,194,227,41,74,219,254,252,243,99,73,101,255,176,134,63,7,180,105,229,159,126,58,136,36,197,86,100,91,182,177,238,28,109,120,88,205,251,239,215,164,109,111,107,27,96,
247,238,248,81,78,203,225,173,248,124,210,125,199,59,120,208,195,193,131,30,0,90,143,253,5,192,43,175,60,115,223,126,29,29,22,78,159,174,72,219,238,118,95,78,42,255,218,85,204,177,99,91,210,202,207,70,
235,149,216,150,109,228,140,163,13,13,21,225,112,88,147,202,0,13,13,163,152,205,211,232,245,81,28,14,43,163,129,184,73,22,115,132,23,27,230,34,71,191,91,143,187,95,71,95,159,140,162,8,26,94,26,77,26,95,
167,139,242,218,107,35,137,242,173,161,34,92,125,50,253,253,58,28,14,43,117,117,227,108,218,52,181,44,93,107,106,66,139,254,224,63,253,180,129,80,72,133,195,97,69,175,191,71,109,221,93,186,46,153,112,
185,12,0,84,215,132,168,169,158,72,233,183,26,219,178,45,178,229,140,163,185,92,50,46,87,234,178,177,127,191,47,177,235,108,109,173,74,212,111,174,156,162,173,109,46,167,59,125,186,2,119,191,142,243,231,
173,156,63,111,229,236,217,155,73,227,152,76,247,146,228,59,58,44,184,250,100,156,206,13,56,157,27,104,107,27,88,182,163,217,237,35,216,237,35,41,245,221,221,70,66,33,21,173,173,85,216,108,97,218,219,
7,146,116,110,180,143,36,162,231,66,86,106,91,222,209,30,18,246,198,0,53,213,19,84,84,44,190,1,240,122,37,62,255,124,110,249,234,233,49,46,42,183,22,244,244,24,233,238,78,157,47,24,124,56,175,59,147,182,
173,150,156,117,180,70,251,200,125,243,17,159,79,226,139,47,210,231,73,107,73,79,143,113,77,231,206,164,109,171,37,103,28,173,182,46,200,155,123,255,229,231,139,27,112,94,44,225,220,57,43,151,187,141,
52,55,251,168,170,156,76,145,175,170,156,228,64,179,47,237,120,85,85,201,125,2,1,53,71,142,206,37,228,127,207,228,128,246,198,0,175,54,142,80,91,27,92,82,71,87,159,204,183,231,172,252,238,214,1,176,119,
175,159,186,186,185,195,228,143,63,222,68,32,240,224,175,124,165,182,101,3,57,227,104,143,61,58,69,83,147,31,143,71,194,121,177,36,145,179,237,121,195,191,168,163,109,52,79,211,212,180,252,29,216,228,
100,1,157,23,44,41,245,53,213,19,203,30,231,214,80,81,210,24,181,181,227,73,125,79,157,170,120,40,142,182,82,219,178,1,81,102,58,161,64,234,150,59,211,44,188,130,106,106,242,211,222,62,128,207,39,225,
245,74,156,57,99,163,171,203,68,117,245,4,6,67,148,207,78,252,193,95,131,69,248,253,106,90,90,30,71,150,163,60,241,68,234,14,174,185,217,71,67,67,124,199,57,255,152,194,98,142,240,233,103,127,164,200,
151,151,135,177,217,226,121,224,241,227,155,184,121,83,207,141,27,6,34,51,231,104,26,77,140,39,159,188,203,182,109,19,28,56,224,99,112,80,139,195,97,161,163,195,66,101,229,36,27,55,78,39,198,154,223,207,
102,11,211,217,121,3,183,91,79,215,165,98,206,124,85,142,205,54,55,215,124,86,99,91,182,80,93,253,2,144,67,17,109,150,217,31,227,251,239,227,145,195,237,142,127,117,30,9,11,234,235,199,241,122,227,142,
19,12,170,232,237,77,77,146,247,236,89,60,18,168,53,10,245,245,247,191,51,237,239,215,167,140,25,137,20,208,219,107,68,8,48,155,167,49,155,167,19,27,129,193,65,45,131,131,233,15,98,101,57,74,125,253,56,
30,79,92,103,159,79,90,244,124,238,65,109,203,6,178,54,162,69,163,130,59,119,52,137,178,78,23,197,100,154,187,235,28,29,141,223,117,206,82,90,26,65,165,82,82,250,45,164,164,100,26,173,54,6,36,71,180,229,
92,37,13,15,171,19,17,105,33,26,77,12,179,57,30,189,130,65,213,146,59,204,66,149,130,117,230,142,116,114,178,128,64,64,157,86,118,53,182,101,11,243,35,90,16,144,131,227,170,172,250,38,77,165,82,22,93,
70,102,49,153,238,37,57,222,114,251,205,71,136,197,159,211,49,235,72,75,33,203,81,100,121,249,239,82,171,141,161,213,46,173,243,74,108,203,6,198,198,18,127,182,241,66,160,15,120,185,163,211,194,123,239,
222,206,156,86,25,192,233,204,95,134,175,37,223,125,151,184,201,233,85,233,139,94,15,8,120,235,114,183,17,131,33,74,101,229,20,146,148,93,225,55,79,110,49,54,86,200,215,95,151,113,242,212,163,196,98,34,
38,68,108,159,0,120,164,248,228,113,69,40,199,50,173,96,158,117,71,76,17,124,116,39,112,232,184,10,224,110,248,71,167,94,187,221,37,16,165,128,5,72,159,113,230,201,179,52,65,224,55,33,98,251,110,7,14,
127,3,240,31,221,35,133,43,147,103,174,107,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::replaceButtonOver_png = (const char*) resource_LiveMode_replaceButtonOver_png;
const int LiveMode::replaceButtonOver_pngSize = 1710;

// JUCER_RESOURCE: replaceButtonDown_png, 1522, "../../UI/ReplaceButtonDown.png"
static const unsigned char resource_LiveMode_replaceButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,111,
73,68,65,84,104,129,237,154,75,111,27,101,20,134,159,177,199,30,223,61,113,226,102,66,211,196,37,174,20,194,130,164,45,18,72,69,132,77,5,27,90,164,238,225,31,144,174,144,144,144,186,131,29,97,197,182,
155,174,96,17,177,234,6,168,212,34,42,144,154,72,136,212,168,137,72,77,155,58,141,235,248,50,118,60,246,120,134,133,83,39,190,37,78,218,212,23,249,89,249,187,157,121,143,231,248,124,55,11,236,48,44,127,
119,73,192,156,3,222,6,220,244,233,115,116,178,192,31,38,204,111,36,231,126,2,16,0,148,129,249,111,48,249,162,173,210,250,244,36,130,41,124,253,36,245,249,151,194,78,38,91,104,183,160,62,189,139,41,24,
31,91,118,166,203,62,125,142,13,193,180,92,181,0,231,219,45,164,79,207,115,222,2,120,218,173,162,79,207,227,21,219,173,96,95,132,22,250,152,199,174,162,207,75,160,99,3,77,146,29,204,204,189,115,96,191,
229,235,75,164,215,146,175,64,81,159,23,161,99,3,173,150,82,161,132,158,43,86,202,162,203,134,213,110,197,238,177,35,13,56,40,164,52,76,227,120,211,155,221,99,71,176,89,170,234,204,146,73,33,173,29,235,
115,123,129,174,9,180,196,114,156,213,133,251,149,242,196,229,55,8,78,15,19,190,50,5,192,226,252,93,180,100,254,88,53,132,175,188,137,47,228,175,170,211,146,26,139,243,191,31,235,115,123,129,174,9,180,
86,177,136,22,60,167,124,77,219,243,155,57,10,106,1,0,239,168,175,46,67,213,162,109,229,43,1,156,139,101,0,19,207,73,31,150,125,198,73,178,3,105,192,209,180,61,253,111,245,84,111,247,216,113,4,93,77,251,
171,255,165,49,116,227,80,190,117,26,61,23,104,54,143,157,169,79,167,155,182,175,46,68,216,92,138,1,229,12,37,201,210,190,246,30,221,90,227,209,173,53,0,214,110,174,0,48,51,247,238,190,227,130,211,10,
163,179,161,166,237,119,175,221,170,42,251,195,1,38,46,79,54,237,255,60,91,31,198,183,78,163,107,2,205,49,232,32,56,163,84,149,1,146,43,9,138,106,129,82,65,39,56,163,32,186,108,0,20,212,2,169,149,68,165,
191,91,241,224,82,60,120,199,252,32,64,234,65,162,202,126,169,80,34,177,188,185,107,63,224,196,59,230,199,165,120,9,206,40,100,30,166,200,39,182,91,210,154,139,101,26,190,240,192,84,16,171,221,74,112,
70,161,164,25,168,209,36,254,51,1,188,167,252,59,227,84,178,49,181,110,220,81,124,235,180,204,214,53,129,230,61,229,175,188,144,189,172,223,137,86,118,157,19,151,118,179,66,62,190,205,234,66,164,82,30,
157,13,225,82,60,156,56,59,194,137,179,35,44,95,95,170,178,163,231,244,170,254,193,105,5,239,152,159,192,228,32,129,201,65,86,23,34,45,7,90,34,242,140,68,228,89,93,189,47,52,128,213,110,101,226,210,36,
90,82,99,117,225,126,149,230,68,36,94,201,158,181,28,214,183,126,160,189,36,182,34,113,178,49,21,45,217,248,229,75,178,131,209,15,66,149,178,111,124,224,213,8,3,124,33,25,223,105,185,174,222,234,180,190,
20,251,237,244,237,168,116,109,160,37,34,241,125,215,35,146,44,49,250,126,232,213,9,218,131,47,36,31,235,179,219,233,219,81,233,154,64,203,68,83,60,189,183,78,96,50,200,192,228,16,39,206,141,224,63,45,
243,248,118,148,237,120,174,174,255,118,60,199,250,157,135,77,237,213,142,177,185,69,194,159,236,78,79,82,192,9,148,51,103,34,178,73,38,154,62,80,163,119,204,207,240,185,17,156,195,94,0,158,222,91,39,
19,77,85,218,199,47,134,43,235,172,23,225,176,190,117,2,93,19,104,249,68,158,205,165,13,36,217,201,192,228,80,101,205,246,116,49,214,240,139,45,170,69,54,151,54,90,182,111,177,89,25,122,75,169,171,207,
198,212,150,237,56,2,206,42,27,153,104,186,106,236,232,236,235,136,205,79,49,90,230,176,190,117,2,130,34,207,119,228,109,97,237,21,212,230,210,6,171,11,247,145,100,9,73,118,240,218,133,113,228,112,128,
108,44,139,161,21,121,240,195,50,142,33,39,54,143,196,153,43,83,232,154,206,118,131,29,220,227,219,81,146,59,59,182,189,199,20,5,181,192,202,143,127,215,245,215,146,121,180,100,249,228,127,252,195,48,
158,17,15,158,147,62,4,177,124,142,102,234,6,234,227,52,234,19,149,245,59,81,156,67,78,130,211,35,4,167,21,242,241,28,197,236,238,162,124,239,56,45,169,241,215,247,127,226,26,113,227,15,15,114,242,194,
24,90,82,163,144,170,95,115,30,197,183,78,163,107,50,218,115,180,164,134,150,212,8,78,151,175,163,220,74,249,95,231,130,104,33,189,150,66,146,203,199,30,162,36,226,29,175,95,144,219,22,27,175,235,76,221,
36,189,150,106,216,246,28,183,226,197,59,94,189,243,21,68,11,222,113,25,211,20,40,170,5,138,106,1,95,168,188,56,119,12,185,112,12,53,79,97,186,166,239,104,46,79,211,229,31,81,253,249,220,139,250,214,9,
116,108,70,19,44,96,247,237,126,233,229,187,78,189,82,22,93,34,86,251,238,46,174,144,214,48,141,250,113,181,20,179,58,70,177,4,84,103,180,86,174,146,108,30,59,22,177,241,95,74,12,221,164,184,115,164,32,
74,226,129,59,76,163,4,197,76,57,83,90,108,86,108,238,230,191,249,163,248,214,105,136,64,6,240,182,91,72,45,166,65,101,202,106,132,158,211,171,2,175,213,113,53,189,155,124,110,76,177,197,179,41,93,211,
209,181,122,109,205,48,138,37,180,228,193,1,114,56,223,58,138,180,160,200,243,191,2,179,237,86,210,167,167,249,197,98,194,183,237,86,209,167,167,49,4,193,184,102,205,230,111,254,227,149,62,146,16,120,
175,221,138,250,244,28,134,41,240,85,108,235,234,13,43,128,170,221,252,217,237,188,120,79,64,24,6,130,128,189,189,250,250,116,57,25,224,55,65,48,62,139,109,93,189,1,240,63,211,253,70,234,139,147,26,39,
0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::replaceButtonDown_png = (const char*) resource_LiveMode_replaceButtonDown_png;
const int LiveMode::replaceButtonDown_pngSize = 1522;

// JUCER_RESOURCE: removeButtonNormal_png, 1694, "../../UI/RemoveButtonNormal.png"
static const unsigned char resource_LiveMode_removeButtonNormal_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,
136,0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,6,27,
73,68,65,84,104,129,237,155,75,108,27,231,17,128,191,125,240,177,75,145,148,40,82,162,35,201,166,98,37,82,12,211,136,1,59,213,161,135,4,1,2,1,41,210,30,83,36,7,31,115,139,123,234,3,40,144,83,154,163,115,
243,53,7,3,185,181,54,16,52,64,145,184,135,20,72,156,166,170,193,212,165,82,61,28,61,172,53,69,145,166,248,38,151,187,61,80,218,136,20,73,69,74,34,146,194,126,39,254,156,127,56,243,239,206,206,206,206,
191,20,216,101,116,240,253,95,10,152,215,129,171,128,7,27,155,227,147,7,238,153,112,227,241,147,235,119,0,4,128,240,208,141,247,48,249,109,87,93,179,57,149,8,166,240,167,205,204,219,127,16,118,51,217,
95,4,89,224,220,43,83,132,46,141,34,185,229,110,251,103,211,199,212,74,58,137,251,26,171,127,91,194,212,77,76,193,120,77,242,186,231,110,2,145,200,220,51,132,95,24,67,148,197,110,251,105,211,231,136,178,
136,119,220,135,228,146,201,44,166,16,16,194,34,112,5,32,116,105,180,203,238,217,156,54,246,197,212,21,17,24,0,236,219,165,205,143,142,172,56,246,62,122,251,39,186,204,67,228,194,137,120,97,115,76,250,
34,208,98,55,191,36,175,229,59,206,57,51,59,206,185,185,169,19,242,200,230,168,244,69,160,237,71,16,4,156,126,151,53,54,170,6,213,124,5,189,172,83,78,151,144,85,7,146,75,234,162,135,54,173,232,187,64,
147,156,18,151,175,207,90,227,116,60,201,194,135,95,179,53,175,177,53,175,17,153,155,34,60,59,222,69,15,109,90,209,119,129,118,20,242,143,178,212,202,181,150,50,217,227,64,29,169,111,128,148,82,69,42,
153,178,37,243,140,121,145,156,245,172,104,26,38,217,111,51,45,245,246,40,36,242,232,249,106,75,59,146,75,194,243,148,23,128,202,78,153,210,118,209,146,169,163,30,100,213,42,152,201,174,102,48,107,230,
161,122,205,120,207,249,17,196,222,46,82,79,117,160,45,223,137,183,173,237,2,51,195,60,251,122,20,128,199,247,54,216,252,124,221,146,93,122,235,10,106,120,0,0,163,82,227,193,7,255,110,169,183,199,250,
167,203,164,226,219,45,237,120,194,30,162,111,93,5,32,245,96,139,135,31,47,90,178,233,215,47,50,52,19,180,198,11,183,98,232,101,253,80,189,102,174,254,238,231,61,223,53,232,109,239,90,96,212,12,182,230,
53,107,156,215,178,0,40,33,149,129,49,31,238,144,135,204,74,154,202,147,50,213,66,61,155,5,163,35,8,82,189,17,173,23,117,210,11,73,74,153,50,91,243,26,202,136,122,192,70,106,33,73,126,51,87,183,167,27,
13,178,102,189,98,162,64,105,55,27,14,77,7,145,149,250,33,53,107,6,201,88,130,106,161,198,214,188,134,115,208,197,81,169,100,202,100,150,211,228,214,235,107,28,24,243,161,132,190,243,55,189,176,141,94,
172,146,140,37,144,220,50,193,232,200,145,109,156,20,253,23,104,186,193,210,237,248,129,239,7,207,7,172,167,206,111,62,140,53,100,152,201,87,159,181,174,248,130,150,35,189,144,164,176,153,99,233,118,156,
51,45,234,185,245,187,15,219,218,111,214,219,159,9,39,94,138,88,153,176,86,210,73,198,18,84,118,74,44,221,142,19,152,25,198,23,25,58,210,90,243,155,217,134,181,6,163,35,13,245,103,236,230,151,232,197,
42,43,31,125,131,236,178,3,237,39,69,9,170,12,95,28,193,59,238,107,59,103,227,179,85,196,221,140,86,201,87,78,202,181,31,157,244,98,10,189,168,91,227,74,174,117,93,216,139,156,130,64,83,24,127,49,210,
113,206,163,207,86,79,198,153,159,152,204,98,138,204,98,170,219,110,28,139,190,11,52,209,33,50,249,234,52,149,76,137,181,187,43,228,30,229,89,252,115,156,193,169,64,219,91,199,228,47,158,65,148,91,47,
85,9,169,108,199,30,55,124,55,241,210,36,78,191,155,149,143,22,234,250,251,236,253,16,252,83,1,206,255,234,57,146,95,107,100,22,211,108,126,177,206,246,127,147,150,220,208,107,214,250,100,85,130,198,242,
144,96,116,4,255,249,225,150,191,45,244,248,153,236,113,247,14,34,138,34,161,231,71,41,104,57,214,238,174,80,217,41,145,188,175,225,80,218,215,40,193,139,157,95,125,106,14,180,161,233,97,212,240,0,223,
254,245,127,0,13,246,126,8,74,80,69,9,170,20,180,44,153,197,52,59,43,79,14,204,145,101,137,208,243,245,205,232,116,60,217,32,27,24,243,89,178,126,163,239,2,109,15,247,176,194,133,107,151,201,174,61,97,
237,147,21,146,255,217,34,183,153,227,204,207,158,98,226,229,167,9,207,158,101,249,78,156,82,170,72,252,86,12,154,250,76,190,179,126,38,94,158,236,104,99,250,205,104,71,249,232,11,99,12,205,132,88,251,
116,153,236,106,134,165,59,11,136,142,221,93,9,163,222,15,115,7,20,158,126,109,6,135,71,110,171,103,217,123,35,138,188,239,130,240,158,245,115,225,218,101,82,15,18,104,247,54,208,238,109,52,100,192,61,
102,222,136,90,125,191,94,165,111,3,77,116,72,248,34,126,106,165,122,65,92,205,150,169,102,203,12,63,23,36,112,97,4,37,4,146,179,254,0,144,93,203,28,208,119,40,135,159,24,239,132,191,163,220,29,80,112,
7,20,28,106,253,48,230,31,101,15,204,145,156,34,190,136,191,163,222,30,190,9,127,67,230,149,85,7,190,136,159,194,110,11,167,148,42,82,74,181,104,220,26,135,189,113,208,125,132,240,224,13,19,96,246,157,
23,187,236,74,123,42,185,10,166,94,63,152,130,104,226,244,185,45,153,161,27,84,247,61,125,201,170,132,228,148,15,232,53,35,58,68,28,158,122,87,190,86,212,209,247,237,32,56,188,78,68,169,49,3,26,53,147,
106,246,187,39,86,217,37,33,237,246,204,170,249,42,70,181,169,160,218,69,144,5,156,3,206,150,178,102,61,151,223,213,242,45,148,90,69,71,47,180,222,225,232,164,215,11,124,254,206,223,129,122,70,203,2,222,
90,73,239,217,238,114,187,19,5,245,183,57,93,109,154,161,157,244,246,35,41,178,21,52,109,237,72,66,91,59,123,1,123,84,190,175,158,228,148,173,139,167,159,208,139,86,2,216,17,129,175,0,18,247,181,182,10,
54,54,199,33,241,213,230,222,199,127,74,30,247,92,90,128,95,239,60,76,35,185,100,212,97,21,209,97,255,111,192,230,248,232,197,42,218,23,27,172,221,125,8,166,105,8,130,113,77,0,56,227,127,255,93,83,48,
127,223,101,255,108,78,31,134,41,240,199,199,233,235,239,74,0,185,242,199,159,120,148,87,254,37,32,140,2,33,224,251,21,55,54,54,173,201,2,255,16,4,227,154,150,254,205,45,128,255,3,154,41,68,74,225,80,
18,99,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::removeButtonNormal_png = (const char*) resource_LiveMode_removeButtonNormal_png;
const int LiveMode::removeButtonNormal_pngSize = 1694;

// JUCER_RESOURCE: removeButtonOver_png, 1753, "../../UI/RemoveButtonOver.png"
static const unsigned char resource_LiveMode_removeButtonOver_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,6,86,73,
68,65,84,104,129,237,154,93,80,83,103,26,199,127,39,223,33,223,40,24,88,69,72,172,131,51,69,219,10,187,59,171,123,177,162,109,167,66,229,182,83,139,222,181,51,109,93,188,114,55,75,91,219,105,109,103,122,
177,72,215,153,170,119,82,110,58,179,17,139,157,209,182,112,81,113,170,109,161,51,182,4,250,45,232,64,16,8,36,33,146,144,175,189,72,115,32,36,193,165,181,38,113,206,111,38,51,57,121,206,115,158,231,157,
247,127,158,243,190,207,137,192,47,172,51,31,223,39,16,111,1,234,0,29,18,18,191,158,0,240,121,28,218,38,102,91,62,0,16,0,172,150,182,183,136,115,36,167,169,73,220,151,8,113,225,205,113,239,223,29,194,
47,149,172,75,169,138,113,228,200,40,251,26,39,49,24,163,185,206,79,162,128,241,251,228,156,61,87,194,219,111,87,16,94,144,17,23,98,79,202,13,154,199,223,5,42,29,142,17,246,63,237,70,173,142,231,58,79,
137,2,71,173,142,179,109,219,28,122,125,148,75,151,204,8,8,86,25,80,11,176,175,113,50,199,233,73,220,111,236,123,114,42,249,181,86,6,232,1,233,113,41,113,215,49,153,34,201,175,6,69,46,19,89,13,241,184,
176,162,93,16,164,71,126,62,83,16,66,107,106,170,97,120,120,229,142,75,115,243,56,14,199,200,61,202,72,98,181,20,132,208,150,34,147,65,89,89,72,60,14,6,229,76,79,43,152,155,147,115,243,166,6,179,57,140,
94,47,45,3,242,13,89,174,19,88,45,58,93,148,158,158,175,196,207,107,175,254,8,128,211,89,202,238,221,15,225,252,111,73,142,51,148,200,68,193,85,180,213,240,205,55,58,2,129,204,67,44,46,14,243,192,3,183,
1,24,25,209,224,118,171,69,91,77,205,28,69,69,137,170,24,137,8,244,247,27,51,250,37,249,254,251,34,60,30,101,198,56,58,93,132,7,31,12,0,48,49,161,226,250,117,173,104,219,188,57,128,197,34,46,152,25,232,
55,16,142,200,238,232,183,156,237,219,125,40,20,249,189,70,189,175,133,214,218,106,203,186,182,171,175,247,112,226,196,119,0,116,118,174,227,204,153,50,209,214,117,246,26,213,91,18,98,154,191,45,227,192,
129,45,25,253,146,180,181,173,167,167,167,56,99,156,234,234,0,93,93,95,3,112,241,66,49,199,222,172,20,109,39,254,243,45,245,187,103,196,227,103,159,171,198,239,151,223,209,111,57,95,124,254,69,222,119,
13,10,78,104,11,11,2,78,103,169,120,60,228,42,2,96,147,253,54,53,91,3,216,55,205,115,229,138,145,177,49,13,179,179,137,42,211,216,48,133,66,153,184,227,189,94,5,189,189,22,198,198,213,56,157,165,108,218,
20,72,139,209,211,91,140,107,72,15,64,48,148,186,219,93,238,247,195,15,58,198,198,19,213,112,215,174,25,113,75,31,9,11,116,159,95,203,236,172,18,167,179,148,242,242,224,170,199,58,62,174,230,179,207,76,
92,187,102,0,96,235,214,0,118,251,98,53,237,237,181,224,245,42,232,254,112,45,6,67,148,198,134,169,108,151,202,57,5,39,180,80,72,134,195,97,75,251,253,47,59,188,226,174,243,249,231,55,167,84,152,151,95,
254,89,188,227,135,135,138,232,237,181,48,228,210,225,112,216,104,110,30,79,187,214,59,239,172,207,26,127,185,223,210,74,120,232,197,27,98,37,244,251,228,116,159,95,139,219,173,194,225,176,81,95,239,225,
79,127,244,173,106,172,174,193,162,148,177,54,236,157,164,249,128,91,60,110,106,170,193,235,85,240,218,171,85,146,208,126,111,108,85,243,60,177,119,154,135,182,249,179,158,115,234,244,31,80,169,98,0,76,
77,171,238,85,106,119,157,79,251,204,120,125,139,83,54,53,85,56,99,41,120,161,85,217,230,121,225,133,155,43,158,115,250,116,249,61,202,230,247,165,239,146,153,190,75,230,92,167,241,171,40,56,161,105,52,
81,142,30,189,206,216,152,154,246,246,245,12,14,234,57,242,15,59,59,119,122,179,62,58,94,121,229,103,180,218,88,70,155,221,62,79,119,247,154,148,223,14,29,186,73,121,121,136,163,71,43,1,82,226,253,22,
118,252,213,203,91,166,31,233,62,191,134,203,125,102,206,116,88,249,232,147,197,71,124,48,40,19,199,103,50,133,137,69,83,215,135,141,13,83,236,216,233,205,120,109,133,50,243,248,242,133,130,19,154,82,
9,77,77,147,12,15,21,209,222,190,30,183,91,197,185,174,18,76,198,72,86,161,53,236,157,90,113,87,182,92,104,187,254,230,161,122,203,109,222,120,163,18,72,141,247,91,176,219,230,177,219,230,113,185,138,
184,220,103,230,234,85,83,218,57,26,77,34,30,64,207,39,150,20,91,77,205,156,104,43,52,10,78,104,73,54,86,6,233,232,112,209,223,111,160,173,109,3,23,46,174,193,229,210,241,204,51,110,14,31,190,193,193,
131,110,90,91,109,140,140,104,120,246,185,106,100,178,212,62,83,109,173,159,150,150,27,43,198,56,121,114,120,69,251,254,253,19,236,217,51,195,191,219,54,48,208,111,224,95,173,118,180,218,132,160,99,177,
68,53,218,184,49,200,235,175,255,132,197,18,206,234,151,228,221,147,195,24,13,139,55,196,246,90,63,29,29,46,46,94,40,230,189,78,43,239,117,90,249,232,227,244,54,202,169,83,223,138,125,191,124,165,96,133,
166,213,198,168,171,243,225,243,38,250,78,183,38,84,220,154,80,241,232,30,15,143,61,230,1,230,197,73,31,24,48,164,249,47,249,103,65,86,30,121,36,251,6,3,160,162,34,72,69,69,16,139,57,33,162,193,193,244,
158,157,86,27,165,174,206,183,162,95,146,237,15,251,83,42,175,217,28,161,174,206,39,182,112,70,71,53,140,142,106,210,98,68,239,60,148,156,35,88,205,109,113,128,225,225,43,185,206,37,43,183,38,149,68,194,
137,142,185,76,22,199,106,93,16,109,161,144,140,233,233,197,174,188,201,20,65,167,139,166,249,45,71,163,137,81,92,156,152,104,159,47,241,174,52,73,73,201,2,74,101,106,5,12,135,5,38,39,23,119,121,122,125,
20,163,49,49,195,30,143,146,96,48,115,28,133,50,70,105,73,56,163,109,185,95,89,217,66,198,127,161,4,2,114,188,222,236,53,33,155,95,62,80,93,253,103,32,81,209,252,128,193,239,147,231,109,119,57,219,68,
1,168,213,49,202,203,67,25,109,43,249,45,197,104,140,136,162,201,134,82,25,207,26,39,41,216,213,242,255,250,233,116,81,241,230,41,36,150,220,28,62,25,208,15,112,246,156,244,50,90,226,238,242,254,251,226,
27,156,47,229,58,205,227,51,2,60,117,229,170,17,189,62,74,85,85,16,181,58,191,183,202,18,249,141,215,171,160,163,195,202,241,246,13,196,98,66,76,16,98,7,5,128,50,211,241,99,113,33,254,207,92,39,40,113,
223,17,139,11,188,52,49,211,114,76,14,48,23,186,208,163,211,62,58,32,32,172,3,74,128,194,121,183,33,145,143,248,129,203,130,16,59,232,158,57,220,9,240,63,64,66,89,204,154,69,209,176,0,0,0,0,73,69,78,68,
174,66,96,130,0,0};

const char* LiveMode::removeButtonOver_png = (const char*) resource_LiveMode_removeButtonOver_png;
const int LiveMode::removeButtonOver_pngSize = 1753;

// JUCER_RESOURCE: removeButtonDown_png, 1541, "../../UI/RemoveButtonDown.png"
static const unsigned char resource_LiveMode_removeButtonDown_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,154,0,0,0,26,8,6,0,0,0,79,79,69,207,0,0,0,4,115,66,73,84,8,8,8,8,124,8,100,136,
0,0,0,9,112,72,89,115,0,0,13,215,0,0,13,215,1,66,40,155,120,0,0,0,25,116,69,88,116,83,111,102,116,119,97,114,101,0,119,119,119,46,105,110,107,115,99,97,112,101,46,111,114,103,155,238,60,26,0,0,5,130,73,
68,65,84,104,129,237,154,77,108,19,87,16,128,191,93,175,255,109,28,59,78,216,144,4,72,72,137,75,177,218,72,64,123,160,7,168,84,21,33,37,234,13,137,67,123,228,86,56,85,170,84,169,183,114,107,122,227,200,
161,72,28,17,42,18,23,68,15,173,68,129,22,84,35,72,104,32,129,16,146,216,142,19,59,241,255,254,244,96,103,137,29,39,105,248,137,99,107,191,219,243,188,241,204,219,157,157,157,55,111,5,202,236,108,249,
121,72,64,63,11,28,6,220,152,152,188,62,105,224,182,14,195,179,11,103,175,2,8,0,178,127,248,60,58,223,214,213,53,147,166,68,208,133,31,167,147,223,124,39,148,51,217,149,122,59,100,210,188,232,130,54,40,
150,95,151,38,38,239,12,65,23,207,137,192,161,122,59,98,210,244,28,18,1,79,189,189,48,105,122,188,82,189,61,248,223,8,27,200,245,45,241,194,228,53,105,136,64,11,159,57,140,91,94,191,227,50,125,235,5,207,
174,143,109,145,71,38,155,165,33,2,109,37,186,174,83,72,230,141,177,104,21,177,186,109,72,118,9,187,223,129,146,41,162,230,213,58,122,104,82,139,134,11,52,181,160,114,111,248,150,49,246,135,130,244,159,
58,72,219,128,76,219,128,204,196,245,49,102,110,189,168,163,135,38,181,104,184,64,219,12,238,93,94,44,118,75,77,153,146,46,146,137,166,1,112,4,156,216,124,118,67,150,158,90,68,45,148,178,162,32,10,120,
247,248,106,234,45,227,106,119,35,185,173,53,237,168,121,149,244,203,69,0,108,59,236,56,90,157,134,44,51,155,70,201,20,141,177,119,183,15,193,34,108,168,87,205,226,179,36,186,182,189,139,212,166,14,180,
222,193,208,154,181,93,98,100,142,199,151,35,0,236,60,210,73,199,39,93,134,236,159,11,119,201,204,44,1,32,218,44,28,248,234,163,154,122,203,116,29,239,37,16,106,173,105,39,61,147,38,114,225,14,0,129,3,
109,236,253,162,207,144,141,94,126,192,252,72,220,24,247,159,14,35,217,165,13,245,170,185,115,254,119,212,156,178,166,124,59,208,112,129,38,90,68,218,6,100,99,236,150,189,0,100,99,25,150,166,82,228,98,
105,124,61,126,108,45,118,172,174,82,54,139,71,162,232,170,6,128,228,148,240,247,7,113,248,236,180,13,200,100,163,153,85,54,2,253,65,220,29,165,174,143,40,137,21,178,106,61,103,187,11,71,57,27,206,143,
198,81,178,165,27,46,88,68,130,225,118,172,46,11,109,3,50,133,133,60,155,197,230,179,227,235,245,227,233,42,173,113,105,42,69,54,246,202,95,127,127,43,146,211,74,48,220,142,154,83,136,71,162,155,182,177,
85,52,94,160,73,34,251,134,66,171,126,95,120,146,48,118,157,251,79,133,43,50,204,248,181,199,198,19,239,146,61,248,251,131,184,58,60,236,27,10,49,93,163,158,235,58,182,119,77,251,213,122,43,51,225,228,
205,9,35,19,90,28,18,193,112,59,182,29,14,246,13,133,72,140,204,145,154,152,223,212,90,221,29,222,138,181,198,35,209,138,250,51,124,230,48,146,211,74,207,201,253,40,121,51,208,222,41,217,120,134,185,7,
81,22,95,164,214,156,211,121,116,55,90,57,163,217,220,182,173,114,237,173,227,239,11,32,57,95,221,50,155,167,118,93,184,29,105,130,64,203,242,226,183,137,117,231,236,58,186,123,107,156,121,199,248,250,
2,248,250,2,245,118,227,181,104,184,64,211,138,26,227,215,70,177,249,28,116,31,235,193,179,203,77,223,151,33,22,198,18,107,190,58,198,127,253,23,77,169,93,44,103,99,25,90,195,59,43,126,155,188,57,78,33,
153,163,231,100,127,73,127,133,189,55,33,57,150,224,201,149,71,4,15,202,248,250,252,116,124,220,69,235,251,65,67,46,74,22,99,125,74,70,133,202,242,144,120,36,74,242,201,92,205,255,214,183,247,94,160,1,
3,77,211,136,221,159,197,37,123,232,62,214,131,109,135,131,224,135,50,197,236,218,53,74,252,193,236,186,187,178,234,64,155,31,157,35,51,179,196,158,19,239,1,84,216,123,19,178,241,12,217,120,6,151,236,
197,215,231,103,71,79,203,170,57,138,162,18,187,63,11,148,122,132,43,89,154,74,25,178,70,163,225,2,109,153,220,92,150,135,23,239,225,237,110,161,251,179,30,130,31,180,225,233,240,48,253,231,75,38,111,
60,101,230,214,115,122,7,67,56,2,78,66,167,195,80,213,103,74,61,79,50,121,99,124,93,27,163,191,68,214,149,207,222,158,98,126,36,70,247,241,94,188,187,125,236,27,236,71,43,150,79,37,196,82,63,44,151,200,
242,244,234,8,197,180,178,166,158,97,239,82,4,101,197,3,177,248,124,129,135,23,239,17,56,208,142,124,164,19,249,72,103,69,6,92,102,228,82,196,232,251,109,87,26,54,208,180,162,74,106,34,137,197,81,42,136,
173,94,59,86,175,157,185,71,113,18,15,163,100,99,160,22,74,27,0,111,183,111,149,126,49,187,241,141,89,156,76,174,43,207,37,178,228,18,89,138,153,82,112,184,119,121,87,205,81,11,26,169,137,228,186,122,
203,164,38,147,21,153,87,201,40,164,38,146,184,202,45,28,71,192,137,35,80,163,113,43,110,244,197,65,253,17,228,150,225,237,221,82,6,108,30,27,130,84,186,152,186,38,80,72,229,12,153,40,137,88,87,236,190,
148,140,138,90,80,86,233,85,163,21,53,138,233,82,87,222,226,148,144,86,156,32,20,23,11,104,106,229,101,17,45,2,86,239,171,29,171,146,87,81,203,61,51,171,219,138,104,173,42,168,202,232,138,78,97,169,80,
83,86,173,151,79,230,107,126,133,98,177,73,72,174,218,39,28,235,233,109,39,4,185,101,56,5,172,126,20,77,76,222,30,41,17,248,171,222,94,152,52,61,119,69,29,126,170,183,23,38,77,141,38,8,218,15,150,116,
238,250,168,215,126,194,142,192,167,245,246,200,164,233,208,116,129,239,103,230,207,93,178,0,44,229,175,223,112,59,63,255,91,64,216,9,180,1,141,123,78,99,178,29,88,4,254,16,4,237,235,153,249,115,151,0,
254,3,15,138,28,237,154,166,173,217,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* LiveMode::removeButtonDown_png = (const char*) resource_LiveMode_removeButtonDown_png;
const int LiveMode::removeButtonDown_pngSize = 1541;


//[EndFile] You can add extra defines here...
//[/EndFile]

