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
#include "../Programs/ArpRow.h"

//[/Headers]

#include "NoteTableCommandRow.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NoteTableCommandRow::NoteTableCommandRow ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    commandSelector.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (commandSelector.get());
    commandSelector->setEditableText (false);
    commandSelector->setJustificationType (juce::Justification::centredLeft);
    commandSelector->setTextWhenNothingSelected (juce::String());
    commandSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    commandSelector->addItem (TRANS("Goto"), 1);
    commandSelector->addItem (TRANS("Sustain To"), 2);
    commandSelector->addItem (TRANS("End"), 3);
    commandSelector->addListener (this);

    commandSelector->setBounds (54, 0, 160, 24);

    rowLabel.reset (new juce::Label ("new label",
                                     TRANS("01")));
    addAndMakeVisible (rowLabel.get());
    rowLabel->setFont (juce::Font ("C64 Pro Mono", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    rowLabel->setJustificationType (juce::Justification::centredRight);
    rowLabel->setEditable (false, false, false);
    rowLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    rowLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    rowLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    rowLabel->setBounds (0, 4, 44, 18);

    argumentLabel.reset (new juce::Label ("new label",
                                          TRANS("01")));
    addAndMakeVisible (argumentLabel.get());
    argumentLabel->setFont (juce::Font ("C64 Pro Mono", 12.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    argumentLabel->setJustificationType (juce::Justification::centredLeft);
    argumentLabel->setEditable (true, true, false);
    argumentLabel->setColour (juce::Label::textColourId, juce::Colour (0xff5090d0));
    argumentLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    argumentLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
    argumentLabel->addListener (this);

    argumentLabel->setBounds (224, 4, 44, 18);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    commandSelector -> setColour (
                                  ComboBox::backgroundColourId
                                , Colour (
                                          0xff5090d0
                                         )
                                 );
    commandSelector -> setColour (
                                  ComboBox::textColourId
                                , Colour (
                                          0xff181090
                                         )
                                 );
    commandSelector -> setColour (
                                  ComboBox::buttonColourId
                                , Colour (
                                          0xff5090d0
                                         )
                                 );
    commandSelector -> setColour (
                                  ComboBox::arrowColourId
                                , Colour (
                                          0xff181090
                                         )
                                 );
    //[/Constructor]
}

NoteTableCommandRow::~NoteTableCommandRow()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    commandSelector = nullptr;
    rowLabel = nullptr;
    argumentLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NoteTableCommandRow::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    if ( selected )
    {
        const Colour lt_blue (
                              0xff5090d0
                             );
        g . setColour (
                       lt_blue
                      );
        Path p;
        p . addTriangle (
                         0.0f
                       , 0.0f
                       , 12.0f
                       , 12.0f
                       , 0.0f
                       , 24.0f
                        );
        g . fillPath (
                      p
                     );
    }
    //[/UserPaint]
}

void NoteTableCommandRow::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NoteTableCommandRow::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == commandSelector.get())
    {
        //[UserComboBoxCode_commandSelector] -- add your combo box handling code here..
        argumentLabel -> setVisible (
                                     commandSelector -> getSelectedItemIndex () < 2
                                    );
        SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> call (
                                                                                         &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                                                       , static_cast < unsigned int > ( row )
                                                                                        );
        SharedResourcePointer < ListenerList < NoteTableRowChanged > > () -> call (
                                                                                   &NoteTableRowChanged::onNoteTableRowChanged
                                                                                 , Get ()
                                                                                  );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserComboBoxCode_commandSelector]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void NoteTableCommandRow::labelTextChanged (juce::Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == argumentLabel.get())
    {
        //[UserLabelCode_argumentLabel] -- add your label text handling code here..
        SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> call (
                                                                                         &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                                                       , static_cast < unsigned int > ( row )
                                                                                        );
        SharedResourcePointer < ListenerList < NoteTableRowChanged > > () -> call (
                                                                                   &NoteTableRowChanged::onNoteTableRowChanged
                                                                                 , Get ()
                                                                                  );
        argumentLabel -> setText (
                                  argumentLabel -> getText () . paddedLeft (
                                                                            '0'
                                                                          , 2
                                                                           )
                                , dontSendNotification
                                 );
        SharedResourcePointer < ListenerList < BankRepaintWaveform > > () -> call (
                                                                                   &BankRepaintWaveform::onBankRepaintWaveform
                                                                                  );
        //[/UserLabelCode_argumentLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
auto
    NoteTableCommandRow::Get () const -> ArpRow
{
    ArpRow ret {
                    COMMAND
                  , 0
            };

    switch ( commandSelector -> getSelectedItemIndex () )
    {
        case 0 :
            ret . value = 0x200;
            break;
        case 1 :
            ret . value = 0x400;
            break;
        default :
            ret . value = 0x100;
    }
    ret . value |= argumentLabel -> getText () . getIntValue () - 1;

    return ret;
}


void
    NoteTableCommandRow::Set (
            const unsigned row_num
          , const ArpRow value
            )
{
    row              = static_cast < int > ( row_num );
    const auto row_string = String (
                                    row_num + 1
                                   );
    rowLabel -> setText (
                         row_string . paddedLeft (
                                                  '0'
                                                , 2
                                                 )
                       , dontSendNotification
                        );

    const auto argument_string = String (
                                         value . value + 1
                                        );
    argumentLabel -> setText (
                              argument_string . paddedLeft (
                                                            '0'
                                                          , 2
                                                           )
                            , dontSendNotification
                             );

    const auto i = ( value . value & 0xf00 ) >> 8;
    switch ( i )
    {
        case 2 :
        case 4 :
            commandSelector -> setSelectedItemIndex (
                                                     i / 2 - 1
                                                   , dontSendNotification
                                                    );
            argumentLabel -> setVisible (
                                         true
                                        );
            break;
        default :
            commandSelector -> setSelectedItemIndex (
                                                     2
                                                   , dontSendNotification
                                                    );
            argumentLabel -> setVisible (
                                         false
                                        );
            break;
    }
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NoteTableCommandRow" componentName=""
                 parentClasses="public AbstractNoteTableRow" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
  <COMBOBOX name="new combo box" id="71776e2269f86f67" memberName="commandSelector"
            virtualName="" explicitFocusOrder="0" pos="54 0 160 24" editable="0"
            layout="33" items="Goto&#10;Sustain To&#10;End" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="1b4eae892bfe6bdb" memberName="rowLabel"
         virtualName="" explicitFocusOrder="0" pos="0 4 44 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="01" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="db3fddcc74ccd0f7" memberName="argumentLabel"
         virtualName="" explicitFocusOrder="0" pos="224 4 44 18" textCol="ff5090d0"
         edTextCol="ff000000" edBkgCol="0" labelText="01" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="C64 Pro Mono"
         fontsize="12.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

