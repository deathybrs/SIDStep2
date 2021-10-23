#ifndef EXPORTCUTOFFCHANGED_H_INCLUDED
#define EXPORTCUTOFFCHANGED_H_INCLUDED


class ExportCutoffChanged {
public:
	virtual ~ExportCutoffChanged() {}

	virtual void onExportCutoffChanged(unsigned int value) = 0;
};


#endif  // LIVECUTOFFCHANGED_H_INCLUDED
