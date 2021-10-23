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

#include "PatchSelector.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PatchSelector::PatchSelector ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    treeView.reset (new juce::TreeView ("new treeview"));
    addAndMakeVisible (treeView.get());
    treeView->setRootItemVisible (false);

    treeView->setBounds (10, 2, 300, 172);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (322, 176);


    //[Constructor] You can add your own custom stuff here..
	SharedResourcePointer<ListenerList<BankTreeChanged>>()->add(this);

	treeView->setRootItem(populateTree());
    //[/Constructor]
}

PatchSelector::~PatchSelector()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	SharedResourcePointer<ListenerList<BankTreeChanged>>()->remove(this);
	treeView->deleteRootItem();
    //[/Destructor_pre]

    treeView = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PatchSelector::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 2.0f, y = 2.0f, width = 318.0f, height = 172.0f;
        juce::Colour fillColour = juce::Colour (0xff181090);
        juce::Colour strokeColour = juce::Colour (0xff5090d0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 2.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PatchSelector::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PatchSelector::onBankTreeChanged() {
	treeView->setRootItem(populateTree());
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PatchSelector" componentName=""
                 parentClasses="public Component, public BankTreeChanged, public PatchTreeBuilder"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="322"
                 initialHeight="176">
  <BACKGROUND backgroundColour="ffffff">
    <ROUNDRECT pos="2 2 318 172" cornerSize="10.0" fill="solid: ff181090" hasStroke="1"
               stroke="2, mitered, butt" strokeColour="solid: ff5090d0"/>
  </BACKGROUND>
  <TREEVIEW name="new treeview" id="fd62a458d403dcac" memberName="treeView"
            virtualName="" explicitFocusOrder="0" pos="10 2 300 172" rootVisible="0"
            openByDefault="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

