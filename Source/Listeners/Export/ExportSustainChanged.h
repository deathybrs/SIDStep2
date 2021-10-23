#ifndef EXPORTSUSTAINCHANGED_H_INCLUDED
#define EXPORTSUSTAINCHANGED_H_INCLUDED


class ExportSustainChanged {
public:
	virtual ~ExportSustainChanged() {}

	virtual void onExportSustainChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVESUSTAINCHANGED_H_INCLUDED
