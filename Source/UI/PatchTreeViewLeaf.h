#ifndef PATCHTREEVIEWLEAF_H_INCLUDED
#define PATCHTREEVIEWLEAF_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


//class Bank;
class SidStep2;


class PatchTreeViewLeaf : public TreeViewItem {
public:
	PatchTreeViewLeaf(/*ReferenceCountedObjectPtr<SIDStep2>core, */String name, String id);
	~PatchTreeViewLeaf();

	bool mightContainSubItems() override;
	void paintItem(Graphics &g, int width, int height) override;
	void itemClicked(const MouseEvent &e) override;

	String getName() const;
	String getID() const;

private:
	//ReferenceCountedObjectPtr<SIDStep2> core;
	String name;
	String id;
};


#endif  // PATCHTREEVIEWLEAF_H_INCLUDED
