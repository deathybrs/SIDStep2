#ifndef EXPORTPULSEWIDTHCHANGED_H_INCLUDED
#define EXPORTPULSEWIDTHCHANGED_H_INCLUDED


class ExportPulseWidthChanged {
public:
	virtual ~ExportPulseWidthChanged() {}

	virtual void onExportPulseWidthChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEPULSEWIDTHCHANGED_H_INCLUDED
