#ifndef PATCHEDITORATTACKCHANGED_H_INCLUDED
#define PATCHEDITORATTACKCHANGED_H_INCLUDED


class PatchEditorAttackChanged {
public:
	virtual ~PatchEditorAttackChanged() {}

	virtual void onPatchEditorAttackChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORATTACKCHANGED_H_INCLUDED
