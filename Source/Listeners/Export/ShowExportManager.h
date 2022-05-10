#ifndef SHOWEXPORTMANAGER_H_INCLUDED
#define SHOWEXPORTMANAGER_H_INCLUDED

#include <memory>

class Recorder;

class ShowExportManager {
public:
	virtual ~ShowExportManager() {}

	virtual void onShowExportManager(std::shared_ptr < Recorder > record) = 0;
};


#endif  // SHOWEXPORTMANAGER_H_INCLUDED
