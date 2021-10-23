#ifndef EXPORTTREMOLOAMOUNTCHANGED_H_INCLUDED
#define EXPORTTREMOLOAMOUNTCHANGED_H_INCLUDED


class ExportTremoloAmountChanged {
public:
	virtual ~ExportTremoloAmountChanged() {}

	virtual void onExportTremoloAmountChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVETREMOLOAMOUNTCHANGED_H_INCLUDED
