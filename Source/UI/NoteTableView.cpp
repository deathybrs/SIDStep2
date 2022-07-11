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

#include "NoteTableCommandRow.h"
#include "NoteTableRow.h"

#include "../Listeners/NoteTableSelectionChanged.h"

//[/Headers]

#include "NoteTableView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NoteTableView::NoteTableView (
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

NoteTableView::~NoteTableView ()
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
    NoteTableView::paint (
            Graphics& g
            )
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void
    NoteTableView::resized ()
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
    if ( min_bounds < 184 ) { min_bounds = 184; }
    setBounds (
               0
             , 0
             , 590
             , min_bounds );
    //[/UserResized]
}

void
    NoteTableView::mouseUp (
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
        dispatcher -> noteTableSelectionChangedListeners -> call (
                                                                  &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                                , selectedRow );
        repaint ();
        getParentComponent () -> repaint ();
    }
    //[/UserCode_mouseUp]
}


//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void
    NoteTableView::onPatchEditorShowNoteTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> add (
                                                                     this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> add (
                                                                         this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> add (
                                                                        this );
}

void
    NoteTableView::onPatchEditorShowPulseTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}

void
    NoteTableView::onPatchEditorShowWaveTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}

void
    NoteTableView::onBankProgramChanged (
            String                                         old_id
          , const ReferenceCountedObjectPtr < SidProgram > program
            )
{
    const auto note_table = program -> GetNoteTable ();
    if ( rows . size () > 0 )
    {
        removeAllChildren ();
        rows . clear ();
    }
    for ( unsigned int i = 0 ; i < note_table -> GetNoteTableSize () ; i++ )
    {
        const auto note_row = note_table -> GetNoteTableEntryAt (
                                                                 i );
        if ( note_row . rowType != COMMAND )
        {
            // row
            auto ntr = new NoteTableRow (
                                         dispatcher );
            ntr -> Set (
                        i
                      , note_row );
            ntr -> setBounds (
                              0
                            , 8 + static_cast < int > ( i ) * 24
                            , 590
                            , 24 );
            addAndMakeVisible (
                               ntr );
            rows . add (
                        ntr );
        }
        else
        {
            // command
            auto ntc = new NoteTableCommandRow (
                                                dispatcher );
            ntc -> Set (
                        i
                      , note_row );
            ntc -> setBounds (
                              0
                            , 8 + static_cast < int > ( i ) * 24
                            , 590
                            , 24 );
            addAndMakeVisible (
                               ntc );
            rows . add (
                        ntc );
        }
    }
}

void
    NoteTableView::onPatchEditorDeleteTableRowClicked ()
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
        rows [ i ] -> Set (
                           i
                         , rows [ i ] -> Get () );
    }
    dispatcher -> noteTableSelectionChangedListeners -> call (
                                                              &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                            , selectedRow );
}

void
    NoteTableView::onPatchEditorNewTableCommandClicked ()
{
    auto ntc = new NoteTableCommandRow (
                                        dispatcher );
    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        ntc -> Set (
                    i
                  , ArpRow {
                            COMMAND
                          , 0x100
                    } );
        ntc -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24 );
        rows . add (
                    ntc );
    }
    else
    {
        ntc -> Set (
                    selectedRow
                  , ArpRow {
                            COMMAND
                          , 0x100
                    } );
        ntc -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24 );
        rows . insert (
                       selectedRow
                     , ntc );
        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24 );
            rows [ i ] -> Set (
                               i
                             , rows [ i ] -> Get () );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 ) );
    addAndMakeVisible (
                       ntc );
    repaint ();
    getParentComponent () -> repaint ();
    selectedRow++;
    dispatcher -> noteTableSelectionChangedListeners -> call (
                                                              &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                            , selectedRow );
}

void
    NoteTableView::onPatchEditorNewTableRowClicked ()
{
    auto ntr = new NoteTableRow (
                                 dispatcher );
    if ( selectedRow >= rows . size () )
    {
        const auto i = static_cast < int > ( rows . size () );
        ntr -> Set (
                    i
                  , ArpRow {
                            RELATIVE
                          , 0
                    } );
        ntr -> setBounds (
                          0
                        , 8 + i * 24
                        , 590
                        , 24 );
        rows . add (
                    ntr );
    }
    else
    {
        ntr -> Set (
                    selectedRow
                  , ArpRow {
                            RELATIVE
                          , 0
                    } );
        ntr -> setBounds (
                          0
                        , 8 + selectedRow * 24
                        , 590
                        , 24 );
        rows . insert (
                       selectedRow
                     , ntr );
        for ( auto i = selectedRow + 1 ; i < rows . size () ; i++ )
        {
            rows [ i ] -> setBounds (
                                     0
                                   , 8 + i * 24
                                   , 590
                                   , 24 );
            rows [ i ] -> Set (
                               i
                             , rows [ i ] -> Get () );
        }
    }
    setBounds (
               0
             , 0
             , 590
             , static_cast < int > ( rows . size () * 24 + 16 ) );
    addAndMakeVisible (
                       ntr );
    repaint ();
    getParentComponent () -> repaint ();
    selectedRow++;
    dispatcher -> noteTableSelectionChangedListeners -> call (
                                                              &NoteTableSelectionChanged::onNoteTableSelectionChanged
                                                            , selectedRow );
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NoteTableView" componentName=""
                 parentClasses="public juce::Component, public PatchEditorShowWaveTable, public PatchEditorShowNoteTable, public PatchEditorShowPulseTable, public BankProgramChanged, public PatchEditorNewTableRowClicked, public PatchEditorNewTableCommandClicked, public PatchEditorDeleteTableRowClicked"
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
