/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_188841F534497368__
#define __JUCE_HEADER_188841F534497368__

//[Headers]     -- You can add your own extra header files here --
#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Listeners/ListenerInitializer.h"

class PatchRow;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Patches  : public Component,
				 public LivePatchListChanged
{
public:
    //==============================================================================
    Patches ();
    ~Patches();
	//==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void mouseUp(const MouseEvent &event) override;
	int getSelectedIndex() const;
	void onLivePatchListChanged(Array<String> programs) override;
	//[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	Array<PatchRow *> rows;
	SharedResourcePointer<ListenerList<LivePatchListSelectedIndexChanged>> livePatchListSelectedIndexChangedListeners;
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Patches)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_188841F534497368__
