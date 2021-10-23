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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>

#include <map>

#include "AbstractNoteTableRow.h"
//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NoteTableRow
        : public AbstractNoteTableRow
        , public juce::Button::Listener
        , public juce::Label::Listener
{
public:
    //==============================================================================
    NoteTableRow ();

    ~NoteTableRow () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    auto
        Get () const -> ArpRow override;

    void
        Set (
                unsigned row_num
              , ArpRow   value
                ) override;

    void
        SetNoteFromFrequency () const;

    void
        SetFrequencyFromNote () const;

    //[/UserMethods]

    void
        paint (
                juce::Graphics& g
                ) override;

    void
        resized () override;

    void
        buttonClicked (
                juce::Button* buttonThatWasClicked
                ) override;

    void
        labelTextChanged (
                juce::Label* labelThatHasChanged
                ) override;

    // Binary resources:
    static const char* noteTableAbsoluteRow_png;
    static const int   noteTableAbsoluteRow_pngSize;
    static const char* noteTableRelativeRow_png;
    static const int   noteTableRelativeRow_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr < juce::ToggleButton > relativeAbsolute;
    std::unique_ptr < juce::Label >        noteOffset;
    std::unique_ptr < juce::Label >        frequency;
    std::unique_ptr < juce::Label >        rowLabel;
    juce::Image                            cachedImage_noteTableAbsoluteRow_png_1;
    juce::Image                            cachedImage_noteTableRelativeRow_png_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  NoteTableRow )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
