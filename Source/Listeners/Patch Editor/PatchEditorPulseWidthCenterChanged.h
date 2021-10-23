#ifndef PATCHEDITORPULSEWIDTHCENTERCHANGED_H_INCLUDED
#define PATCHEDITORPULSEWIDTHCENTERCHANGED_H_INCLUDED


class PatchEditorPulseWidthCenterChanged {
public:
	virtual ~PatchEditorPulseWidthCenterChanged() {}

	virtual void onPatchEditorPulseWidthCenterChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORPULSEWIDTHCENTERCHANGED_H_INCLUDED
