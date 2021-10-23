#ifndef EXPORTRESONANCECHANGED_H_INCLUDED
#define EXPORTRESONANCECHANGED_H_INCLUDED


class ExportResonanceChanged {
public:
	virtual ~ExportResonanceChanged() {}

	virtual void onExportResonanceChanged(unsigned int value) = 0;
};


#endif  // LIVERESONANCECHANGED_H_INCLUDED
