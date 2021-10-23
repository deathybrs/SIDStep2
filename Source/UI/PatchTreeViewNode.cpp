#include "PatchTreeViewNode.h"

PatchTreeViewNode::PatchTreeViewNode(Category category): category(category) {}

PatchTreeViewNode::~PatchTreeViewNode() {}

bool PatchTreeViewNode::mightContainSubItems() { return true; }

void PatchTreeViewNode::paintItem(Graphics &g, int width, int height) {
	Colour ltBlue(0xff5090d0);

	g.setColour(ltBlue);
	g.setFont(Font("C64 Pro", 14.00f, Font::plain));
	g.drawText(getCategoryString(category), 4, 0, width - 8, height, Justification::centredLeft, true);
}

String PatchTreeViewNode::getCategoryString(Category category) {
	switch (category) {
		case Bass:
			return "Bass";
		case Drums:
			return "Drums";
		case Lead:
			return "Lead";
		case Keys:
			return "Keys";
		case Pad:
			return "Pad";
		case SFX:
			return "SFX";
		case Misc:
		default:
			return "Misc";
	}
}
