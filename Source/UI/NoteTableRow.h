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
class NoteTableRow final
        : public AbstractNoteTableRow
        , public Button::Listener
        , public Label::Listener
{
public:
    //==============================================================================
    explicit
        NoteTableRow (
                const std::shared_ptr < EventDispatcher >& dispatcher
                );

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
                Graphics& g
                ) override;

    void
        resized () override;

    void
        buttonClicked (
                Button* button_that_was_clicked
                ) override;

    void
        labelTextChanged (
                Label* label_that_has_changed
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
    std::unique_ptr < ToggleButton > relativeAbsolute;
    std::unique_ptr < Label >        noteOffset;
    std::unique_ptr < Label >        frequency;
    std::unique_ptr < Label >        rowLabel;
    Image                            cachedImage_noteTableAbsoluteRow_png_1;
    Image                            cachedImage_noteTableRelativeRow_png_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  NoteTableRow )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
