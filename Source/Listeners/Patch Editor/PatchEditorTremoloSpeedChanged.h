#ifndef PATCHEDITORTREMOLOSPEEDCHANGED_H_INCLUDED
#define PATCHEDITORTREMOLOSPEEDCHANGED_H_INCLUDED


class PatchEditorTremoloSpeedChanged {
public:
	virtual ~PatchEditorTremoloSpeedChanged() {}

	virtual void onPatchEditorTremoloSpeedChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORTREMOLOSPEEDCHANGED_H_INCLUDED
