#include "PatchTreeViewLeaf.h"
#include "../SIDStep2.h"

PatchTreeViewLeaf::PatchTreeViewLeaf (
        std::shared_ptr < EventDispatcher > dispatcher
       ,
        /*ReferenceCountedObjectPtr<SIDStep2> core, */String name
      , String                                               id
        )
    : /*core(core), */
    dispatcher (
                dispatcher )
  , name (
          name )
  , id (
        id ) {}

PatchTreeViewLeaf::~PatchTreeViewLeaf ()
{
    //core = nullptr;
}

bool
    PatchTreeViewLeaf::mightContainSubItems () { return false; }

void
    PatchTreeViewLeaf::paintItem (
            Graphics& g
          , int       width
          , int       height
            )
{
    Colour ltBlue (
                   0xff5090d0 );
    g . setColour (
                   ltBlue );
    g . setFont (
                 Font (
                       "C64 Pro"
                     , 14.00f
                     , Font::plain ) );
    g . drawText (
                  name
                , 4
                , 0
                , width - 8
                , height
                , Justification::centredLeft
                , true );
}

void
    PatchTreeViewLeaf::itemClicked (
            const MouseEvent&
            )
{
    dispatcher -> bankLoadListeners -> call (
                                             &BankLoad::onBankLoad
                                           , id );
    //core->loadProgram(id);
}

String
    PatchTreeViewLeaf::getName () const { return name; }

String
    PatchTreeViewLeaf::getID () const { return id; }
