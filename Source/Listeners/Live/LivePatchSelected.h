#ifndef LIVEPATCHSELECTED_H_INCLUDED
#define LIVEPATCHSELECTED_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


class SidProgram;

class LivePatchSelected {
public:
	virtual ~LivePatchSelected() {}

	// TODO: May want to switch this to an index
	virtual void onLivePatchSelected(ReferenceCountedObjectPtr<SidProgram> program) = 0;
};


#endif  // LIVEPATCHSELECTED_H_INCLUDED
