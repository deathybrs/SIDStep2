#ifndef EXPORTHIGHPASSCHANGED_H_INCLUDED
#define EXPORTHIGHPASSCHANGED_H_INCLUDED


class ExportHighPassChanged {
public:
	virtual ~ExportHighPassChanged() {}

	virtual void onExportHighPassChanged(bool value) = 0;
};


#endif  // LIVEHIGHPASSCHANGED_H_INCLUDED
