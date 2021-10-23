#ifndef EXPORTLOWPASSCHANGED_H_INCLUDED
#define EXPORTLOWPASSCHANGED_H_INCLUDED


class ExportLowPassChanged {
public:
	virtual ~ExportLowPassChanged() {}

	virtual void onExportLowPassChanged(bool value) = 0;
};


#endif  // LIVELOWPASSCHANGED_H_INCLUDED
