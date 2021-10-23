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
#include "WavetableView.h"


#include "../SIDProgram.h"

#include "WavetableCommandRow.h"
#include "WavetableRow.h"

//[/Headers]

#include "WavetableView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WavetableView::WavetableView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (590, 56);


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

WavetableView::~WavetableView()
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
    rows . clear (
                  true
                 );
    //[/Destructor]
}

//==============================================================================
void WavetableView::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WavetableView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    for ( int i = 0 ; i < rows . size () ; i++ )
        rows [ i ] -> setBounds (
                                 0
                               , 8 + i * 24
                               , 590
                               , 24
                                );
    int minBounds = static_cast < int > ( 8 + ( rows . size () + 1 ) * 24 );
    if ( minBounds < 184 )
        minBounds = 184;
    setBounds (
               0
             , 0
             , 590
             , minBounds
              );
    //[/UserResized]
}

void WavetableView::mouseUp (const juce::MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    if ( e . mods . isLeftButtonDown () )
    {
        //selectedRow = rows;
        Component* clicked = e . originalComponent;

        //int selectedRow = rows.size();
        //unsigned int i;
        //for each (AbstractWavetableRow *r in rows) {
        for ( selectedRow = 0 ; selectedRow < rows . size () ; selectedRow++ )
        {
            AbstractWavetableRow* r = rows [ selectedRow ];
            if ( r == clicked || r -> isParentOf (
                                                  clicked
                                                 ) ) //{
                break;
            //	r->setSelected(true);
            //	//selectedRow = r;
            //	selectedRow = i;
            //} else
            //	r->setSelected(false);
        }

        wavetableSelectionChangedListeners -> call (
                                                    &WavetableSelectionChanged::onWavetableSelectionChanged
                                                  , selectedRow
                                                   );

        repaint ();
        //if (waveform != nullptr) waveform->repaint();
        getParentComponent () -> repaint ();
    }
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    WavetableView::onBankProgramChanged (
            String                                   old_id
          , ReferenceCountedObjectPtr < SidProgram > program
            )
{
    const auto wavetable = program -> GetWavetable ();

    if ( rows . size () > 0 )
    {
        removeAllChildren ();

        rows . clear ();
    }

    //ReferenceCountedObjectPtr<Wavetable> wt = program->getWavetable();

    for ( unsigned int i = 0 ; i < wavetable -> GetWaveTableSize () ; i++ )
    {
        const int value = wavetable -> GetWaveTableEntryAt (
                                                            i
                                                           );

        if ( value < 0x100 )
        {
            // row
            auto wtr = new WavetableRow ();
            wtr -> set (
                        i
                      , value
                       );
            wtr -> setBounds (
                              0
                            , 8 + i * 24
                            , 590
                            , 24
                             );
            addAndMakeVisible (
                               wtr
                              );
            rows . add (
                        wtr
                       );
        }
        else
        {
            // command
            auto wtc = new WavetableCommandRow ();
            wtc -> set (
                        i
                      , value & 0xff00
                      , value & 0xff
                       );
            wtc -> setBounds (
                              0
                            , 8 + i * 24
                            , 590
                            , 24
                             );
            addAndMakeVisible (
                               wtc
                              );
            rows . add (
                        wtc
                       );
        }
    }
}


void
    WavetableView::onPatchEditorNewTableRowClicked ()
{
    auto wtr = new WavetableRow ();

    if ( selectedRow >= rows . size () )
    {
        int i = static_cast < int > ( rows . size () );
        wtr -> set (
                    i
                  , 0
                   );
        wtr -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24
                         );
        rows . add (
                    wtr
                   );
    }
    else
    {
        wtr -> set (
                    selectedRow
                  , 0
                   );
        wtr -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24
                         );
        rows . insert (
                       selectedRow
                     , wtr
                      );

        for ( int i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24
                                    );
            rows [ i ] -> set (
                               i
                             , rows [ i ] -> get ()
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
                       wtr
                      );
    repaint ();
    getParentComponent () -> repaint ();

    selectedRow++;
    wavetableSelectionChangedListeners -> call (
                                                &WavetableSelectionChanged::onWavetableSelectionChanged
                                              , selectedRow
                                               );
}


void
    WavetableView::onPatchEditorNewTableCommandClicked ()
{
    WavetableCommandRow* wtc = new WavetableCommandRow ();

    if ( selectedRow >= rows . size () )
    {
        int i = static_cast < int > ( rows . size () );
        wtc -> set (
                    i
                  , 0x100
                   );
        wtc -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24
                         );
        rows . add (
                    wtc
                   );
    }
    else
    {
        wtc -> set (
                    selectedRow
                  , 0x100
                   );
        wtc -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24
                         );
        rows . insert (
                       selectedRow
                     , wtc
                      );

        for ( int i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24
                                    );
            rows [ i ] -> set (
                               i
                             , rows [ i ] -> get ()
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
                       wtc
                      );
    repaint ();
    getParentComponent () -> repaint ();

    selectedRow++;
    wavetableSelectionChangedListeners -> call (
                                                &WavetableSelectionChanged::onWavetableSelectionChanged
                                              , selectedRow
                                               );
}


void
    WavetableView::onPatchEditorDeleteTableRowClicked ()
{
    removeChildComponent (
                          rows [ selectedRow ]
                         );
    rows . remove (
                   selectedRow
                  );

    for ( int i = selectedRow ; i < rows . size () ; i++ )
    {
        rows [ i ] -> setBounds (
                                 0
                               , 8 + i * 24
                               , 590
                               , 24
                                );
        rows [ i ] -> set (
                           i
                         , rows [ i ] -> get ()
                          );
    }

    wavetableSelectionChangedListeners -> call (
                                                &WavetableSelectionChanged::onWavetableSelectionChanged
                                              , selectedRow
                                               );
}


void
    WavetableView::onPatchEditorShowNoteTable ()
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
    WavetableView::onPatchEditorShowPulseTable ()
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
    WavetableView::onPatchEditorShowWaveTable ()
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
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WavetableView" componentName=""
                 parentClasses="public Component, public BankProgramChanged, public PatchEditorNewTableRowClicked, public PatchEditorNewTableCommandClicked, public PatchEditorDeleteTableRowClicked, public PatchEditorShowWaveTable, public PatchEditorShowNoteTable, public PatchEditorShowPulseTable"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="590"
                 initialHeight="56">
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

