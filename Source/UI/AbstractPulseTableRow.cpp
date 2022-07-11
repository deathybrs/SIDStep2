#include "AbstractPulseTableRow.h"

AbstractPulseTableRow::AbstractPulseTableRow (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
{
    dispatcher -> pulseTableSelectionChangedListeners -> add (
                                                              this );
}

AbstractPulseTableRow::~AbstractPulseTableRow ()
{
    dispatcher -> pulseTableSelectionChangedListeners -> remove (
                                                                 this );
}

void
    AbstractPulseTableRow::onPulseTableSelectionChanged (
            const unsigned selected_row
            )
{
    selected = static_cast < unsigned int > ( row ) == selected_row;
    repaint ();
}
