#ifndef PATCHEDITORVIBRATODEFAULTSPEEDCHANGED_H_INCLUDED
#define PATCHEDITORVIBRATODEFAULTSPEEDCHANGED_H_INCLUDED


class PatchEditorVibratoDefaultSpeedChanged {
public:
	virtual ~PatchEditorVibratoDefaultSpeedChanged() {}

	virtual void onPatchEditorVibratoDefaultSpeedChanged(float value) = 0;
};


#endif  // PATCHEDITORVIBRATODEFAULTSPEEDCHANGED_H_INCLUDED
