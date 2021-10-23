#ifndef PATCHEDITORNAMECHANGED_H_INCLUDED
#define PATCHEDITORNAMECHANGED_H_INCLUDED


#include "../../JuceLibraryCode/JuceHeader.h"


class PatchEditorNameChanged {
public:
	virtual ~PatchEditorNameChanged() {}

	virtual void onPatchEditorNameChanged(String value) = 0;
};


#endif  // PATCHEDITORNAMECHANGED_H_INCLUDED
