/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PatchRow.h"
#include "../SIDProgram.h"
//[/Headers]

#include "Patches.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Patches::Patches ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             496
           , 16
            );


    //[Constructor] You can add your own custom stuff here..
    addMouseListener (
                      this
                    , true
                     );
    SharedResourcePointer < ListenerList < LivePatchListChanged > > () -> add (
                                                                               this
                                                                              );
    //[/Constructor]
}


Patches::~Patches ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    SharedResourcePointer < ListenerList < LivePatchListChanged > > () -> remove (
                                                                                  this
                                                                                 );
    //[/Destructor_pre]


    //[Destructor]. You can add your own custom destruction code here..
    for ( auto row : rows )
    {
        delete row;
    }

    rows . clear ();
    //[/Destructor]
}


//==============================================================================
void
    Patches::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}


void
    Patches::resized ()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    Patches::mouseUp (
            const MouseEvent& e
            )
{
    if ( e . mods . isLeftButtonDown () )
    {
        PatchRow*  selectedRow = nullptr;
        Component* clicked     = e . originalComponent;

        for each ( PatchRow* r in rows )
        {
            if ( r == nullptr && r -> getSelected () )
                selectedRow = r;

            if ( r == clicked || r -> isParentOf (
                                                  clicked
                                                 ) )
            {
                selectedRow = r;
            }
            else
                r -> setSelected (
                                  false
                                 );
        }

        selectedRow -> setSelected (
                                    true
                                   );

        livePatchListSelectedIndexChangedListeners -> call (
                                                            &LivePatchListSelectedIndexChanged::onLivePatchListSelectedIndexChanged
                                                          , getSelectedIndex ()
                                                           );

        repaint ();
    }
}


int
    Patches::getSelectedIndex () const
{
    int i = 0;

    for ( ; i < rows . size () ; i++ )
    {
        if ( rows [ i ] -> getSelected () )
            break;
    }

    return i < rows . size ()
               ? i
               : -1;
}


void
    Patches::onLivePatchListChanged (
            Array < String > programs
            )
{
    unsigned int oldSelectedIndex = 0;

    for ( int i = 0 ; i < rows . size () ; i++ )
    {
        if ( rows [ i ] -> getSelected () )
        {
            oldSelectedIndex = static_cast < unsigned int > ( i );
            break;
        }
    }

    if ( oldSelectedIndex >= programs . size () )
        oldSelectedIndex = programs . size () - 1;

    deleteAllChildren ();
    rows . clear ();

    for ( unsigned int i = 0 ; i < programs . size () ; i++ )
    {
        PatchRow* r = new PatchRow ();

        r -> setRow (
                     i + 1
                    );
        r -> setName (
                      String (
                              programs [ i ]
                             )
                     );
        r -> setSelected (
                          i == oldSelectedIndex
                         );

        r -> setBounds (
                        0
                      , i * 16
                      , getWidth ()
                      , 16
                       );

        addAndMakeVisible (
                           r
                          );
        rows . add (
                    r
                   );
    }

    setBounds (
               0
             , 0
             , getWidth () - 8
             , 16 * programs . size () + 32
              );
    repaint ();
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Patches" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="496" initialHeight="16">
  <BACKGROUND backgroundColour="ffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
