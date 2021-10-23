#ifndef PATCHEDITORVIBRATORANGECHANGED_H_INCLUDED
#define PATCHEDITORVIBRATORANGECHANGED_H_INCLUDED


class PatchEditorVibratoRangeChanged {
public:
	virtual ~PatchEditorVibratoRangeChanged() {}

	virtual void onPatchEditorVibratoRangeChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORVIBRATORANGECHANGED_H_INCLUDED
