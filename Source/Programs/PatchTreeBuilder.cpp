#include "PatchTreeBuilder.h"


#include "../UI/PatchTreeViewNode.h"
#include "../UI/PatchTreeViewLeaf.h"


using namespace juce;

TreeViewItem *PatchTreeBuilder::populateTree() const {
	TreeViewItem *root = new PatchTreeViewNode(Misc);

	ScopedPointer<XmlElement> patchesElement = properties->GetPatches();

	for (int i = 0; i < patchesElement->getNumChildElements(); i++) {
		XmlElement *categoryElement = patchesElement->getChildElement(i);

		PatchTreeViewNode *category = new PatchTreeViewNode(getCategoryFromName(categoryElement->getTagName()));
		root->addSubItem(category);

		for (int j = 0; j < categoryElement->getNumChildElements(); j++) {
			XmlElement *patch = categoryElement->getChildElement(j);
			category->addSubItem(new PatchTreeViewLeaf(patch->getStringAttribute("name"),
				patch->getStringAttribute("id")));
		}
	}

	return root;
}

// TODO: Check to see if this is the only place this gets used, or if it should be used into a more accessible class
Category PatchTreeBuilder::getCategoryFromName(String n) {
	if (n == "basses") return Bass;
	if (n == "drums") return Drums;
	if (n == "leads") return Lead;
	if (n == "keys") return Keys;
	if (n == "pads") return Pad;
	if (n == "sfx") return SFX;
	return Misc;
}
