#ifndef EXPORTPITCHBENDCHANGED_H_INCLUDED
#define EXPORTPITCHBENDCHANGED_H_INCLUDED


class ExportPitchBendChanged {
public:
	virtual ~ExportPitchBendChanged() {}

	virtual void onExportPitchBendChanged(unsigned int voice, float value) = 0;
};


#endif  // LIVEPITCHBENDCHANGED_H_INCLUDED
