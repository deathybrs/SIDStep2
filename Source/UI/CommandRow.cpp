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
#include "../Command.h"

//[/Headers]

#include "CommandRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CommandRow::CommandRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    commandLabel . reset (
                          new juce::Label (
                                           "new label"
                                         , TRANS (
                                                  "Change Sustain/Release" ) ) );
    addAndMakeVisible (
                       commandLabel . get () );
    commandLabel -> setFont (
                             juce::Font (
                                         "C64 Pro"
                                       , 15.00f
                                       , juce::Font::plain ) . withTypefaceStyle (
                                                                                  "Regular" ) );
    commandLabel -> setJustificationType (
                                          juce::Justification::centred );
    commandLabel -> setEditable (
                                 false
                               , false
                               , false );
    commandLabel -> setColour (
                               juce::Label::textColourId
                             , juce::Colours::red );
    commandLabel -> setColour (
                               juce::TextEditor::textColourId
                             , juce::Colours::black );
    commandLabel -> setColour (
                               juce::TextEditor::backgroundColourId
                             , juce::Colour (
                                             0x00000000 ) );
    commandLabel -> setBounds (
                               0
                             , 0
                             , 288
                             , 40 );


    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             360
           , 40 );


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

CommandRow::~CommandRow ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    commandLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void
    CommandRow::paint (
            juce::Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void
    CommandRow::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    CommandRow::AttachCommand (
            const size_t                 max_width
          , std::shared_ptr < Command >& command
            )
{
    maxWidth        = max_width;
    this -> command = command;
    String command_text;
    switch ( command -> GetType () )
    {
            //case COMMANDS::VOICE_FILTER_ON_OFF:
            //    command_text = "Voice Filter On/Off";
            //    break;
        case COMMANDS::CUTOFF:
            command_text = "Cutoff";
            break;
            //case COMMANDS::RESONANCE:
            //    command_text = "Resonance";
            //    break;
            //case COMMANDS::SET_FILTER_TYPE:
            //    command_text = "Set Filter Type";
            //    break;
            //case COMMANDS::VOLUME:
            //    command_text = "Volume";
            //    break;
        case COMMANDS::DELAY:
            command_text = "Delay";
            break;
        case COMMANDS::PROGRAM_CHANGE:
            command_text = "Program Change";
            break;
        case COMMANDS::NOTE_ON:
            command_text = "Note On";
            break;
        case COMMANDS::NOTE_OFF:
            command_text = "Note Off";
            break;
        case COMMANDS::PITCH_BEND:
            command_text = "Pitch Bend";
            break;
        case COMMANDS::PULSE_WIDTH:
            command_text = "Pulse Width";
            break;
        case COMMANDS::CHANGE_ATTACK_DECAY:
            command_text = "Change Attack/Decay";
            break;
        case COMMANDS::CHANGE_SUSTAIN_RELEASE:
            command_text = "Change Sustain/Release";
            break;
        case COMMANDS::VIBRATO_TABLE:
            command_text = "Vibrato Table";
            break;
        case COMMANDS::VIBRATO_DELAY:
            command_text = "Vibrato Delay";
            break;
        case COMMANDS::RESONANCE_ROUTING:
            command_text = "Resonance Routing";
            break;
        case COMMANDS::FILTER_MODE_VOLUME:
            command_text = "Filter Mode Volume";
            break;
        default:
            command_text = "ERROR!";
    }
    commandLabel -> setText (
                             command_text
                           , dontSendNotification );
    const auto arguments = command -> Render ();
    for ( size_t argument_index = 0 ; argument_index < arguments . size () ; argument_index++ )
    {
        auto argument_label = std::make_shared < Label > (
                                                          String::empty
                                                        , String::toHexString (
                                                                               arguments . at (
                                                                                               argument_index ) ) . paddedLeft (
                                                                                                                                '0'
                                                                                                                              , 2 ) );
        argument_label -> setFont (
                                   Font (
                                         "C64 Pro Mono"
                                       , 15.00F
                                       , Font::plain ) . withTypefaceStyle (
                                                                            "Regular" ) );
        argument_label -> setJustificationType (
                                                Justification::centred );
        argument_label -> setEditable (
                                       false
                                     , false
                                     , false );
        argument_label -> setColour (
                                     Label::textColourId
                                   , Colours::red );
        argumentLabels . push_back (
                                    argument_label );
        addAndMakeVisible (
                           *argument_label );
        argument_label -> setBounds (
                                     static_cast < int > ( 288 + argument_index * 40 )
                                   , 0
                                   , 40
                                   , 40 );
    }
    setBounds (
               0
             , 0
             , static_cast < int > ( 288 + ( maxWidth + 1 ) * 40 )
             , 40 );
    repaint ();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CommandRow" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="360" initialHeight="40">
  <BACKGROUND backgroundColour="323e44"/>
  <LABEL name="new label" id="6c90b0c5d5f4e153" memberName="commandLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 288 40" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Change Sustain/Release"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="C64 Pro" fontsize="15.0" kerning="0.0" bold="0" italic="0"
         justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
