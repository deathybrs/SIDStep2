#ifndef ABSTRACTWAVETABLEROW_H_INCLUDED
#define ABSTRACTWAVETABLEROW_H_INCLUDED


#include "../../JuceLibraryCode/JuceHeader.h"


#include "../Listeners/ListenerInitializer.h"


class AbstractWavetableRow: public Component,
							public WavetableSelectionChanged
							{
public:
	AbstractWavetableRow();
	virtual ~AbstractWavetableRow();

	//void setSelected(bool value);
	void onWavetableSelectionChanged(unsigned int selectedRow) override;

	virtual unsigned int get() const = 0;
	virtual void set(unsigned int rownum, unsigned int value) = 0;

protected:
	bool selected;
	int row;
};


#endif  // ABSTRACTWAVETABLEROW_H_INCLUDED
