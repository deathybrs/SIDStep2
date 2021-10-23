#ifndef EXPORTVOICEFILTERCHANGED_H_INCLUDED
#define EXPORTVOICEFILTERCHANGED_H_INCLUDED


class ExportVoiceFilterChanged {
public:
	virtual ~ExportVoiceFilterChanged() {}

	virtual void onExportVoiceFilterChanged(unsigned int voice, bool value) = 0;
};


#endif  // LIVEVOICEFILTERCHANGED_H_INCLUDED
