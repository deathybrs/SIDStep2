#include "AbstractWavetableRow.h"

AbstractWavetableRow::AbstractWavetableRow(): selected(false), row(-1) {
	SharedResourcePointer<ListenerList<WavetableSelectionChanged>>()->add(this);
}

AbstractWavetableRow::~AbstractWavetableRow() {
	SharedResourcePointer<ListenerList<WavetableSelectionChanged>>()->remove(this);
}

//void AbstractWavetableRow::setSelected(bool value) { selected = value; }

void AbstractWavetableRow::onWavetableSelectionChanged(unsigned selectedRow) {
	if (static_cast<unsigned int>(row) == selectedRow) selected = true;
	else selected = false;

	repaint();
}
