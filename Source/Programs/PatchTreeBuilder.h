#ifndef PATCHTREEBUILDER_H_INCLUDED
#define PATCHTREEBUILDER_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "../Listeners/ListenerInitializer.h"
#include "Categories.h"
#include "../SharedProperties.h"


class PatchTreeBuilder {
public:
    TreeViewItem*
    populateTree (
            std::shared_ptr < EventDispatcher > dispatcher
            ) const;

private:
	SharedResourcePointer<SharedProperties> properties;

	static Category getCategoryFromName(String n);
};


#endif  // PATCHTREEBUILDER_H_INCLUDED
