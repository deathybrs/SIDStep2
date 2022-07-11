#include "AbstractWavetableRow.h"

AbstractWavetableRow::AbstractWavetableRow (
        std::shared_ptr < EventDispatcher > dispatcher
        )
    :
    dispatcher (
                dispatcher )
  , selected (
              false )
  , row (
         -1 )
{
    dispatcher -> wavetableSelectionChangedListeners -> add (
                                                             this );
}

AbstractWavetableRow::~AbstractWavetableRow ()
{
    dispatcher -> wavetableSelectionChangedListeners -> remove (
                                                                this );
}

//void AbstractWavetableRow::setSelected(bool value) { selected = value; }

void
    AbstractWavetableRow::onWavetableSelectionChanged (
            const unsigned selected_row
            )
{
    if ( static_cast < unsigned int > ( row ) == selected_row )
        selected = true;
    else
        selected = false;
    repaint ();
}
