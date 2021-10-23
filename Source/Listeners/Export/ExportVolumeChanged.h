#ifndef EXPORTVOLUMECHANGED_H_INCLUDED
#define EXPORTVOLUMECHANGED_H_INCLUDED


class ExportVolumeChanged {
public:
	virtual ~ExportVolumeChanged() {}

	virtual void onExportVolumeChanged(unsigned int value) = 0;
};


#endif  // LIVEVOLUMECHANGED_H_INCLUDED
