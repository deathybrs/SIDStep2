#ifndef PATCHEDITORVIBRATOSPEEDCHANGED_H_INCLUDED
#define PATCHEDITORVIBRATOSPEEDCHANGED_H_INCLUDED


class PatchEditorVibratoSpeedChanged {
public:
	virtual ~PatchEditorVibratoSpeedChanged() {}

	virtual void onPatchEditorVibratoSpeedChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORVIBRATOSPEEDCHANGED_H_INCLUDED
