#ifndef EXPORTVIBRATOAMOUNTCHANGED_H_INCLUDED
#define EXPORTVIBRATOAMOUNTCHANGED_H_INCLUDED


class ExportVibratoAmountChanged {
public:
	virtual ~ExportVibratoAmountChanged() {}

	virtual void onExportVibratoAmountChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEVIBRATOAMOUNTCHANGED_H_INCLUDED
