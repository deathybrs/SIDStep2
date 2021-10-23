#include "AbstractNoteTableRow.h"


AbstractNoteTableRow::AbstractNoteTableRow ()
{
    SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> add (
                                                                                    this
                                                                                   );
}


AbstractNoteTableRow::~AbstractNoteTableRow ()
{
    SharedResourcePointer < ListenerList < NoteTableSelectionChanged > > () -> remove (
                                                                                       this
                                                                                      );
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
