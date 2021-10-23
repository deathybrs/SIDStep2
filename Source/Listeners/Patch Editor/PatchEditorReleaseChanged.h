#ifndef PATCHEDITORRELEASECHANGED_H_INCLUDED
#define PATCHEDITORRELEASECHANGED_H_INCLUDED


class PatchEditorReleaseChanged {
public:
	virtual ~PatchEditorReleaseChanged() {}

	virtual void onPatchEditorReleaseChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORRELEASECHANGED_H_INCLUDED
