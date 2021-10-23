#ifndef EXPORTRELEASECHANGED_H_INCLUDED
#define EXPORTRELEASECHANGED_H_INCLUDED


class ExportReleaseChanged {
public:
	virtual ~ExportReleaseChanged() {}

	virtual void onExportReleaseChanged(unsigned int voice, unsigned int value) = 0;
};


#endif  // LIVERELEASECHANGED_H_INCLUDED
