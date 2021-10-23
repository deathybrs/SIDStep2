#ifndef EXPORTVIBRATOSPEEDCHANGED_H_INCLUDED
#define EXPORTVIBRATOSPEEDCHANGED_H_INCLUDED


class ExportVibratoSpeedChanged {
public:
	virtual ~ExportVibratoSpeedChanged() {}

	virtual void onExportVibratoSpeedChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEVIBRATOSPEEDCHANGED_H_INCLUDED
