#ifndef EXPORTPATCHCHANGED_H_INCLUDED
#define EXPORTPATCHCHANGED_H_INCLUDED


class ExportPatchChanged {
public:
	virtual ~ExportPatchChanged() {}

	virtual void onExportPatchChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVEPATCHCHANGED_H_INCLUDED
