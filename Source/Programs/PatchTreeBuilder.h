#ifndef PATCHTREEBUILDER_H_INCLUDED
#define PATCHTREEBUILDER_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


#include "Categories.h"
#include "../SharedProperties.h"


class PatchTreeBuilder {
public:
	TreeViewItem *populateTree() const;

private:
	SharedResourcePointer<SharedProperties> properties;

	static Category getCategoryFromName(String n);
};


#endif  // PATCHTREEBUILDER_H_INCLUDED
