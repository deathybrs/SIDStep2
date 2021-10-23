#include "AbstractPulseTableRow.h"


AbstractPulseTableRow::AbstractPulseTableRow ()
{
    SharedResourcePointer < ListenerList < PulseTableSelectionChanged > > () -> add (
                                                                                     this
                                                                                    );
}


AbstractPulseTableRow::~AbstractPulseTableRow ()
{
    SharedResourcePointer < ListenerList < PulseTableSelectionChanged > > () -> remove (
                                                                                        this
                                                                                       );
}


void
    AbstractPulseTableRow::onPulseTableSelectionChanged (
            const unsigned selected_row
            )
{
    if ( static_cast < unsigned int > ( row ) == selected_row )
        selected = true;
    else
        selected = false;

    repaint ();
}
