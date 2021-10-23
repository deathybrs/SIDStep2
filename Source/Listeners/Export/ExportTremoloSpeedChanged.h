#ifndef EXPORTTREMOLOSPEEDCHANGED_H_INCLUDED
#define EXPORTTREMOLOSPEEDCHANGED_H_INCLUDED


class ExportTremoloSpeedChanged {
public:
	virtual ~ExportTremoloSpeedChanged() {}

	virtual void onExportTremoloSpeedChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVETREMOLOSPEEDCHANGED_H_INCLUDED
