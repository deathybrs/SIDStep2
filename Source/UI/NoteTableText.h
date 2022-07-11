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
#include <JuceHeader.h>
#include "../Listeners/ListenerInitializer.h"

//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NoteTableText : public Component
{
public:
    //==============================================================================
    explicit
        NoteTableText (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    ~NoteTableText () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

    void
        mouseUp (
                const MouseEvent& e
                ) override;

    // Binary resources:
    static const char* noteTable_png;
    static const int   noteTable_pngSize;
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < EventDispatcher > dispatcher;
    int                                 selectedRow;
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_noteTable_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  NoteTableText )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
