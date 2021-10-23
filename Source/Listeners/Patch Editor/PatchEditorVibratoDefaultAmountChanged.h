#ifndef PATCHEDITORVIBRATODEFAULTAMOUNTCHANGED_H_INCLUDED
#define PATCHEDITORVIBRATODEFAULTAMOUNTCHANGED_H_INCLUDED


class PatchEditorVibratoDefaultAmountChanged {
public:
	virtual ~PatchEditorVibratoDefaultAmountChanged() {}

	virtual void onPatchEditorVibratoDefaultAmountChanged(float value) = 0;
};


#endif  // PATCHEDITORVIBRATODEFAULTAMOUNTCHANGED_H_INCLUDED
