#ifndef PATCHEDITORPITCHBENDRANGECHANGED_H_INCLUDED
#define PATCHEDITORPITCHBENDRANGECHANGED_H_INCLUDED


class PatchEditorPitchBendRangeChanged {
public:
	virtual ~PatchEditorPitchBendRangeChanged() {}

	virtual void onPatchEditorPitchBendRangeChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORPITCHBENDRANGECHANGED_H_INCLUDED
