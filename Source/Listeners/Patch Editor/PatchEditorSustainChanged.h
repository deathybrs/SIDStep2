#ifndef PATCHEDITORSUSTAINCHANGED_H_INCLUDED
#define PATCHEDITORSUSTAINCHANGED_H_INCLUDED


class PatchEditorSustainChanged {
public:
	virtual ~PatchEditorSustainChanged() {}

	virtual void onPatchEditorSustainChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORSUSTAINCHANGED_H_INCLUDED
