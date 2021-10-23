#ifndef EXPORTBANDPASSCHANGED_H_INCLUDED
#define EXPORTBANDPASSCHANGED_H_INCLUDED


class ExportBandPassChanged {
public:
	virtual ~ExportBandPassChanged() {}

	virtual void onExportBandPassChanged(bool value) = 0;
};


#endif  // LIVEBANDPASSCHANGED_H_INCLUDED
