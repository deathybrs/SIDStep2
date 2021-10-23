#ifndef EXPORTDECAYCHANGED_H_INCLUDED
#define EXPORTDECAYCHANGED_H_INCLUDED


class ExportDecayChanged {
public:
	virtual ~ExportDecayChanged() {}

	virtual void onExportDecayChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVEDECAYCHANGED_H_INCLUDED
