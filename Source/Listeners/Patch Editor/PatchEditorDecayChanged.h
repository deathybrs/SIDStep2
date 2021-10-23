#ifndef PATCHEDITORDECAYCHANGED_H_INCLUDED
#define PATCHEDITORDECAYCHANGED_H_INCLUDED


class PatchEditorDecayChanged {
public:
	virtual ~PatchEditorDecayChanged() {}

	virtual void onPatchEditorDecayChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORDECAYCHANGED_H_INCLUDED
