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
//[/Headers]

#include "ExportManager.h"
#include "CommandView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ExportManager::ExportManager ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__viewport.reset (new juce::Viewport ("new viewport"));
    addAndMakeVisible (juce__viewport.get());
    juce__viewport->setViewedComponent (new CommandView());

    juce__viewport->setBounds (0, 0, 1000, 752);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ExportManager::~ExportManager()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__viewport = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ExportManager::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ExportManager::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    ExportManager::AttachRecording (
            std::shared_ptr < Recorder >& record
            )
{
    recording = record;
    const auto& frame_view = dynamic_cast < CommandView* > ( juce__viewport -> getViewedComponent () );
    frame_view -> AttachRecording (
                                   recording );
}

void
    ExportManager::onLivePatchEditorModeClicked ()
{
    setVisible (
                false );
}

void
    ExportManager::onPatchEditorLiveModeClicked ()
{
    setVisible (
                false );
}

void
    ExportManager::onShowExportManager (
            std::shared_ptr < Recorder > record
            )
{
    AttachRecording (
                     record );
    MessageManager::callAsync (
                               [=] ()
                               {
                                   setVisible (
                                               true );
                               } );
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ExportManager" componentName=""
                 parentClasses="public Component, public LivePatchEditorModeClicked, public PatchEditorLiveModeClicked, public ShowExportManager"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="1024"
                 initialHeight="768">
  <BACKGROUND backgroundColour="ff323e44"/>
  <VIEWPORT name="new viewport" id="a4ed997b3bace219" memberName="juce__viewport"
            virtualName="" explicitFocusOrder="0" pos="0 0 1000 752" vscroll="1"
            hscroll="1" scrollbarThickness="8" contentType="1" jucerFile="CommandView.cpp"
            contentClass="" constructorParams=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

