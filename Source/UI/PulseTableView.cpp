/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "../SIDProgram.h"

#include "PulseTableCommandRow.h"
#include "PulseTableRow.h"

#include "../Listeners/PulseTableSelectionChanged.h"

//[/Headers]

#include "PulseTableView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PulseTableView::PulseTableView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    addMouseListener (
                      this
                    , true
                     );

    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> add (
                                                                             this
                                                                            );
    SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> add (
                                                                                   this
                                                                                  );
    SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> add (
                                                                                    this
                                                                                   );
    SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> add (
                                                                                   this
                                                                                  );
    //[/Constructor]
}

PulseTableView::~PulseTableView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    SharedResourcePointer < ListenerList < BankProgramChanged > > () -> remove (
                                                                                this
                                                                               );
    SharedResourcePointer < ListenerList < PatchEditorShowNoteTable > > () -> remove (
                                                                                      this
                                                                                     );
    SharedResourcePointer < ListenerList < PatchEditorShowPulseTable > > () -> remove (
                                                                                       this
                                                                                      );
    SharedResourcePointer < ListenerList < PatchEditorShowWaveTable > > () -> remove (
                                                                                      this
                                                                                     );
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    rows . clear ();
    //[/Destructor]
}

//==============================================================================
void PulseTableView::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PulseTableView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    for ( auto i = 0 ; i < rows . size () ; i++ )
    {
        rows [ i ] -> setBounds (
                                 0
                               , 8 + i * 24
                               , 590
                               , 24
                                );
    }
    auto min_bounds = static_cast < int > ( 8 + ( rows . size () + 1 ) * 24 );
    if ( min_bounds < 184 )
    {
        min_bounds = 184;
    }

    setBounds (
               0
             , 0
             , 590
             , min_bounds
              );
    //[/UserResized]
}

void PulseTableView::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    if ( e . mods . isLeftButtonDown () )
    {
        const auto clicked = e . originalComponent;

        for ( selectedRow = 0 ; selectedRow < rows . size () ; selectedRow++ )
        {
            const auto r = rows [ selectedRow ];
            if ( r == clicked || r -> isParentOf (
                                                  clicked
                                                 ) ) //{
                break;
        }

        pulseTableSelectionChangedListeners -> call (
                                                     &PulseTableSelectionChanged::onPulseTableSelectionChanged
                                                   , selectedRow
                                                    );

        repaint ();
        getParentComponent () -> repaint ();
    }
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    PulseTableView::onBankProgramChanged (
            String                                   old_id
          , ReferenceCountedObjectPtr < SidProgram > program
            )
{
    const auto pulse_table = program -> GetPulseTable ();

    if ( rows . size () > 0 )
    {
        removeAllChildren ();

        rows . clear ();
    }

    if (pulse_table != nullptr)
    {
        for ( unsigned int i = 0 ; i < pulse_table -> GetPulseTableSize () ; i++ )
        {
            const auto pulse_row = pulse_table -> GetPulseTableEntryAt (
                                                                        i );
            if ( ( pulse_row & 0xF000 ) == 0x0000 )
            {
                // row
                auto ptr = new PulseTableRow ();
                ptr -> Set (
                            i
                          , pulse_row );
                ptr -> setBounds (
                                  0
                                , 8 + i * 24
                                , 590
                                , 24 );
                addAndMakeVisible (
                                   ptr );
                rows . add (
                            ptr );
            }
            else
            {
                // command
                auto ptc = new PulseTableCommandRow ();
                ptc -> Set (
                            i
                          , pulse_row );
                ptc -> setBounds (
                                  0
                                , 8 + i * 24
                                , 590
                                , 24 );
                addAndMakeVisible (
                                   ptc );
                rows . add (
                            ptc );
            }
        }
    }
}


void
    PulseTableView::onPatchEditorDeleteTableRowClicked ()
{
    removeChildComponent (
                          rows [ selectedRow ]
                         );
    rows . remove (
                   selectedRow
                  );

    for ( auto i = selectedRow ; i < rows . size () ; i++ )
    {
        rows [ i ] -> setBounds (
                                 0
                               , 8 + i * 24
                               , 590
                               , 24
                                );
        rows [ i ] -> Set (
                           i
                         , rows [ i ] -> Get ()
                          );
    }

    pulseTableSelectionChangedListeners -> call (
                                                 &PulseTableSelectionChanged::onPulseTableSelectionChanged
                                               , selectedRow
                                                );
}


void
    PulseTableView::onPatchEditorNewTableCommandClicked ()
{
    auto ptc = new PulseTableCommandRow ();

    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        ptc -> Set (
                    i
                  , 0x1000
                   );
        ptc -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24
                         );
        rows . add (
                    ptc
                   );
    }
    else
    {
        ptc -> Set (
                    selectedRow
                  , 0x1000
                   );
        ptc -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24
                         );
        rows . insert (
                       selectedRow
                     , ptc
                      );

        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24
                                    );
            rows [ i ] -> Set (
                               i
                             , rows [ i ] -> Get ()
                              );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 )
              );

    addAndMakeVisible (
                       ptc
                      );
    repaint ();
    getParentComponent () -> repaint ();

    selectedRow++;
    pulseTableSelectionChangedListeners -> call (
                                                 &PulseTableSelectionChanged::onPulseTableSelectionChanged
                                               , selectedRow
                                                );
}


void
    PulseTableView::onPatchEditorNewTableRowClicked ()
{
    auto ptr = new PulseTableRow ();

    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        ptr -> Set (
                    i
                  , 2048
                   );
        ptr -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24
                         );
        rows . add (
                    ptr
                   );
    }
    else
    {
        ptr -> Set (
                    selectedRow
                  , 2048
                   );
        ptr -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24
                         );
        rows . insert (
                       selectedRow
                     , ptr
                      );

        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24
                                    );
            rows [ i ] -> Set (
                               i
                             , rows [ i ] -> Get ()
                              );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 )
              );

    addAndMakeVisible (
                       ptr
                      );
    repaint ();
    getParentComponent () -> repaint ();

    selectedRow++;
    pulseTableSelectionChangedListeners -> call (
                                                 &PulseTableSelectionChanged::onPulseTableSelectionChanged
                                               , selectedRow
                                                );
}


void
    PulseTableView::onPatchEditorShowNoteTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> remove (
                                                                                           this
                                                                                          );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> remove (
                                                                                               this
                                                                                              );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> remove (
                                                                                              this
                                                                                             );
}


void
    PulseTableView::onPatchEditorShowPulseTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> add (
                                                                                        this
                                                                                       );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> add (
                                                                                            this
                                                                                           );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> add (
                                                                                           this
                                                                                          );
}


void
    PulseTableView::onPatchEditorShowWaveTable ()
{
    SharedResourcePointer < ListenerList < PatchEditorNewTableRowClicked > > () -> remove (
                                                                                           this
                                                                                          );
    SharedResourcePointer < ListenerList < PatchEditorNewTableCommandClicked > > () -> remove (
                                                                                               this
                                                                                              );
    SharedResourcePointer < ListenerList < PatchEditorDeleteTableRowClicked > > () -> remove (
                                                                                              this
                                                                                             );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PulseTableView" componentName=""
                 parentClasses="public juce::Component, public PatchEditorShowWaveTable, public PatchEditorShowNoteTable, public PatchEditorShowPulseTable, public BankProgramChanged, public PatchEditorNewTableRowClicked, public PatchEditorNewTableCommandClicked, public PatchEditorDeleteTableRowClicked"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <METHODS>
    <METHOD name="mouseUp (const juce::MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

