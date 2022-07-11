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

//#include "WavetableView.h"

//[/Headers]


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WavetableView::WavetableView (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (
             590
           , 56 );


    //[Constructor] You can add your own custom stuff here..
    addMouseListener (
                      this
                    , true );
    dispatcher -> bankProgramChangedListeners -> add (
                                                      this );
    dispatcher -> patchEditorShowNoteTableListeners -> add (
                                                            this );
    dispatcher -> patchEditorShowPulseTableListeners -> add (
                                                             this );
    dispatcher -> patchEditorShowWaveTableListeners -> add (
                                                            this );
    //[/Constructor]
}

WavetableView::~WavetableView ()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    dispatcher -> bankProgramChangedListeners -> remove (
                                                         this );
    dispatcher -> patchEditorShowNoteTableListeners -> remove (
                                                               this );
    dispatcher -> patchEditorShowPulseTableListeners -> remove (
                                                                this );
    dispatcher -> patchEditorShowWaveTableListeners -> remove (
                                                               this );
    //[/Destructor_pre]


    //[Destructor]. You can add your own custom destruction code here..
    rows . clear (
                  true );
    //[/Destructor]
}

//==============================================================================
void
    WavetableView::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void
    WavetableView::resized ()
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
                               , 24 );
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
             , min_bounds );
    //[/UserResized]
}

void
    WavetableView::mouseUp (
            const MouseEvent& e
            )
{
    //[UserCode_mouseUp] -- Add your code here...
    if ( e . mods . isLeftButtonDown () )
    {
        const auto clicked = e . originalComponent;

        for ( selectedRow = 0 ; selectedRow < rows . size () ; selectedRow++ )
        {
            const auto r = rows [ selectedRow ];
            if ( r == clicked || r -> isParentOf (
                                                  clicked ) )
            {
                //{
                break;
            }
        }
        dispatcher -> wavetableSelectionChangedListeners -> call (
                                                                  &WavetableSelectionChanged::onWavetableSelectionChanged
                                                                , selectedRow );
        repaint ();
        getParentComponent () -> repaint ();
    }
    //[/UserCode_mouseUp]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    WavetableView::onBankProgramChanged (
            String                                   old_id
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    const auto wavetable = program -> GetWavetable ();
    if ( rows . size () > 0 )
    {
        removeAllChildren ();
        rows . clear ();
    }

    for ( unsigned int i = 0 ; i < wavetable -> GetWaveTableSize () ; i++ )
    {
        const auto value = static_cast < int > ( wavetable -> GetWaveTableEntryAt (
                                                                                   i ) );
        if ( value < 0x100 )
        {
            // row
            auto wtr = new WavetableRow (
                                         dispatcher );
            wtr -> set (
                        i
                      , value );
            wtr -> setBounds (
                              0
                            , 8 + static_cast < int > ( i ) * 24
                            , 590
                            , 24 );
            addAndMakeVisible (
                               wtr );
            rows . add (
                        wtr );
        }
        else
        {
            // command
            auto wtc = new WavetableCommandRow (
                                                dispatcher );
            wtc -> set (
                        i
                      , value & 0xff00
                      , value & 0xff );
            wtc -> setBounds (
                              0
                            , 8 + static_cast < int > ( i ) * 24
                            , 590
                            , 24 );
            addAndMakeVisible (
                               wtc );
            rows . add (
                        wtc );
        }
    }
}

void
    WavetableView::onPatchEditorNewTableRowClicked ()
{
    auto wtr = new WavetableRow (
                                 dispatcher );
    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        wtr -> set (
                    i
                  , 0 );
        wtr -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24 );
        rows . add (
                    wtr );
    }
    else
    {
        wtr -> set (
                    selectedRow
                  , 0 );
        wtr -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24 );
        rows . insert (
                       selectedRow
                     , wtr );
        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24 );
            rows [ i ] -> set (
                               i
                             , rows [ i ] -> get () );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 ) );
    addAndMakeVisible (
                       wtr );
    repaint ();
    getParentComponent () -> repaint ();
    selectedRow++;
    dispatcher -> wavetableSelectionChangedListeners -> call (
                                                              &WavetableSelectionChanged::onWavetableSelectionChanged
                                                            , selectedRow );
}

void
    WavetableView::onPatchEditorNewTableCommandClicked ()
{
    auto wtc = new WavetableCommandRow (
                                        dispatcher );
    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        wtc -> set (
                    i
                  , 0x100 );
        wtc -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24 );
        rows . add (
                    wtc );
    }
    else
    {
        wtc -> set (
                    selectedRow
                  , 0x100 );
        wtc -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24 );
        rows . insert (
                       selectedRow
                     , wtc );
        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24 );
            rows [ i ] -> set (
                               i
                             , rows [ i ] -> get () );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 ) );
    addAndMakeVisible (
                       wtc );
    repaint ();
    getParentComponent () -> repaint ();
    selectedRow++;
    dispatcher -> wavetableSelectionChangedListeners -> call (
                                                              &WavetableSelectionChanged::onWavetableSelectionChanged
                                                            , selectedRow );
}

void
    WavetableView::onPatchEditorDeleteTableRowClicked ()
{
    removeChildComponent (
                          rows [ selectedRow ] );
    rows . remove (
                   selectedRow );
    for ( auto i = selectedRow ; i < rows . size () ; i++ )
    {
        rows [ i ] -> setBounds (
                                 0
                               , 8 + i * 24
                               , 590
                               , 24 );
        rows [ i ] -> set (
                           i
                         , rows [ i ] -> get () );
    }
    dispatcher -> wavetableSelectionChangedListeners -> call (
                                                              &WavetableSelectionChanged::onWavetableSelectionChanged
                                                            , selectedRow );
}

void
    WavetableView::onPatchEditorShowNoteTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}

void
    WavetableView::onPatchEditorShowPulseTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}

void
    WavetableView::onPatchEditorShowWaveTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> add (
                                                                     this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> add (
                                                                         this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> add (
                                                                        this );
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
