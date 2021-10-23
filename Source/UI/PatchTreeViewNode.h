#ifndef PATCHTREEVIEWNODE_H_INCLUDED
#define PATCHTREEVIEWNODE_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"

#include <map>
#include "../Programs/Categories.h"


class PatchTreeViewNode: public TreeViewItem {
public:
	PatchTreeViewNode(Category category);
	~PatchTreeViewNode();

	bool mightContainSubItems() override;
	void paintItem(Graphics &g, int width, int height) override;

	static String getCategoryString(Category category);

private:
	Category category;
};


#endif  // PATCHTREEVIEWNODE_H_INCLUDED
