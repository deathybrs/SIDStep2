#ifndef PATCHEDITORPULSEWIDTHRANGECHANGED_H_INCLUDED
#define PATCHEDITORPULSEWIDTHRANGECHANGED_H_INCLUDED


class PatchEditorPulseWidthRangeChanged {
public:
	virtual ~PatchEditorPulseWidthRangeChanged() {}

	virtual void onPatchEditorPulseWidthRangeChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORPULSEWIDTHRANGECHANGED_H_INCLUDED
