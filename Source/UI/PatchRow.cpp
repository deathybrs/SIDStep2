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
//[/Headers]

#include "PatchRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatchRow::PatchRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    rowLabel.reset (new juce::Label ("new label",
                                     TRANS("00")));
    addAndMakeVisible (rowLabel.get());
    rowLabel->setFont (juce::Font ("C64 Pro Mono", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    rowLabel->setJustificationType (juce::Justification::centred);
    rowLabel->setEditable (false, false, false);
    rowLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    rowLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    rowLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    rowLabel->setBounds (0, 0, 32, 16);

    patchLabel.reset (new juce::Label ("new label",
                                       juce::String()));
    addAndMakeVisible (patchLabel.get());
    patchLabel->setFont (juce::Font ("C64 Pro", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    patchLabel->setJustificationType (juce::Justification::centredLeft);
    patchLabel->setEditable (false, false, false);
    patchLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    patchLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    patchLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    patchLabel->setBounds (40, 0, 496, 16);


    //[UserPreSize]
	selected = false;
    //[/UserPreSize]

    setSize (496, 16);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PatchRow::~PatchRow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    rowLabel = nullptr;
    patchLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchRow::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
	if (selected) g.fillAll(Colour(0xff5090d0));
	else g.fillAll(Colour(0xff181090));
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchRow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PatchRow::setRow(unsigned int value) const {
	rowLabel->setText(String(value).paddedLeft('0', 2), dontSendNotification);
}

void PatchRow::setName(String value) const {
	patchLabel->setText(value, dontSendNotification);
}

bool PatchRow::getSelected() const { return selected; }

void PatchRow::setSelected(bool value) {
	selected = value;

	Colour blue(0xff181090);
	Colour ltBlue(0xff5090d0);

	if (selected) {
		rowLabel->setColour(Label::textColourId, Colour(blue));
		patchLabel->setColour(Label::textColourId, Colour(blue));
	} else {
		rowLabel->setColour(Label::textColourId, Colour(ltBlue));
		patchLabel->setColour(Label::textColourId, Colour(ltBlue));
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchRow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="496" initialHeight="16">
  <BACKGROUND backgroundColour="ffffff"/>
  <LABEL name="new label" id="8a0848f5228e5b5f" memberName="rowLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 32 16" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="00" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="94651a31dd051d1b" memberName="patchLabel"
         virtualName="" explicitFocusOrder="0" pos="40 0 496 16" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

