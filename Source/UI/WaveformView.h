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


class SidProgram;
class SID;
//[/Headers]


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WaveformView
        : public Component
        , public BankProgramChanged
        , public BankRepaintWaveform
{
public:
    //==============================================================================
    WaveformView (
            std::shared_ptr < EventDispatcher > dispatcher
            );

    ~WaveformView () override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //void setCurrentProgram(ReferenceCountedObjectPtr<SIDProgram> value);
    void
        SetNote (
                SID*         s
              , unsigned int note
                ) const;

    void
        onBankProgramChanged (
                String                                   oldID
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onBankRepaintWaveform () override;

    //[/UserMethods]

    void
        paint (
                juce::Graphics& g
                ) override;

    void
        resized () override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    std::shared_ptr < EventDispatcher >      dispatcher;
    ReferenceCountedObjectPtr < SidProgram > currentProgram;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  WaveformView )
};

//[EndFile] You can add extra defines here...
//[/EndFile]
