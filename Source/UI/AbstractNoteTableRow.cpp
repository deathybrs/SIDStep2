#include "AbstractNoteTableRow.h"

AbstractNoteTableRow::AbstractNoteTableRow (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
{
    dispatcher -> noteTableSelectionChangedListeners -> add (
                                                             this );
}


AbstractNoteTableRow::~AbstractNoteTableRow ()
{
    dispatcher -> noteTableSelectionChangedListeners -> remove (
                                                                this );
}


void
    AbstractNoteTableRow::onNoteTableSelectionChanged (
            const unsigned selected_row
            )
{
    if ( static_cast < unsigned int > ( row ) == selected_row )
        selected = true;
    else
        selected = false;

    repaint ();
}
