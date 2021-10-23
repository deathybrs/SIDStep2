#ifndef PATCHEDITORTREMOLORANGECHANGED_H_INCLUDED
#define PATCHEDITORTREMOLORANGECHANGED_H_INCLUDED


class PatchEditorTremoloRangeChanged {
public:
	virtual ~PatchEditorTremoloRangeChanged() {}

	virtual void onPatchEditorTremoloRangeChanged(unsigned int value) = 0;
};


#endif  // PATCHEDITORTREMOLORANGECHANGED_H_INCLUDED
