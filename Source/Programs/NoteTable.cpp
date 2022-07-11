#include "NoteTable.h"

#include <array>

#include "ArpRow.h"
#include "Wavetable.h"

#include "../SIDProgram.h"

NoteTable::NoteTable (
        const std::shared_ptr < EventDispatcher >& dispatcher
        )
    :
    dispatcher (
                dispatcher )
{
    notes . add (
                 new ArpRow {
                         RELATIVE
                       , 0
                 } );
    notes . add (
                 new ArpRow {
                         COMMAND
                       , END_COMMAND
                 } );
}

NoteTable::NoteTable (
        const std::shared_ptr < EventDispatcher >& dispatcher
      , XmlElement*                                e
        )
    :
    dispatcher (
                dispatcher )
{
    for ( auto i = 0 ; i < e -> getNumChildElements () ; i++ )
    {
        const auto r = e -> getChildElement (
                                             i );
        auto new_row = new ArpRow {
                RELATIVE
              , 0
        };
        if ( r -> getTagName () == "relative" )
        {
            new_row -> value = r -> getIntAttribute (
                                                     "offset" );
        }
        else if ( r -> getTagName () == "absolute" )
        {
            new_row -> rowType = ABSOLUTE;
            new_row -> value   = r -> getIntAttribute (
                                                       "frequency" );
        }
        else if ( r -> getTagName () == "command" )
        {
            new_row -> rowType = COMMAND;
            auto command_type  = r -> getStringAttribute (
                                                          "type" );
            if ( command_type == "end" ) { new_row -> value = END_COMMAND; }
            else if ( command_type == "goto" )
            {
                new_row -> value = GOTO_COMMAND | r -> getIntAttribute (
                                                                        "argument" );
            }
            else if ( command_type == "sustain-to" )
            {
                new_row -> value = SUSTAIN_TO_COMMAND | r -> getIntAttribute (
                                                                              "argument" );
            }
        }
        notes . add (
                     new_row );
    }
}

NoteTable::NoteTable (
        const NoteTable& other
        )
    :
    dispatcher (
                other . dispatcher )
  , noteTableIndex (
                    other . noteTableIndex )
  , sustained (
               other . sustained )
  , released (
              other . released )
  , releaseCounter (
                    other . releaseCounter )
  , selectedRow (
                 other . selectedRow )
  , forVoice (
              other . forVoice )
{
    for ( auto row : other . notes )
    {
        const auto dupe = new ArpRow (
                                      *row );
        notes . add (
                     dupe );
    }
}

NoteTable::NoteTable (
        NoteTable&& other
        ) noexcept
    :
    dispatcher (
                other . dispatcher )
  , noteTableIndex (
                    other . noteTableIndex )
  , sustained (
               other . sustained )
  , released (
              other . released )
  , releaseCounter (
                    other . releaseCounter )
  , selectedRow (
                 other . selectedRow )
  , forVoice (
              other . forVoice )
{
    for ( auto row : other . notes )
    {
        notes . add (
                     row );
    }
    other . notes . clear (
                           false );
}

auto
    NoteTable::operator= (
            const NoteTable& other
            ) -> NoteTable&
{
    if ( &other == this ) { return *this; }
    noteTableIndex = other . noteTableIndex;
    sustained      = other . sustained;
    released       = other . released;
    releaseCounter = other . releaseCounter;
    selectedRow    = other . selectedRow;
    forVoice       = other . forVoice;
    notes . clear ();
    for ( auto row : other . notes )
    {
        const auto dupe = new ArpRow (
                                      *row );
        notes . add (
                     dupe );
    }
    return *this;
}

auto
    NoteTable::operator= (
            NoteTable&& other
            ) noexcept -> NoteTable&
{
    if ( &other == this ) { return *this; }
    noteTableIndex = other . noteTableIndex;
    sustained      = other . sustained;
    released       = other . released;
    releaseCounter = other . releaseCounter;
    selectedRow    = other . selectedRow;
    forVoice       = other . forVoice;
    notes . clear ();
    for ( auto row : other . notes )
    {
        notes . add (
                     row );
    }
    other . notes . clear (
                           false );
    return *this;
}

void
    NoteTable::Select (
            const bool value
            )
{
    if ( value )
    {
        dispatcher -> patchEditorShowNoteTableListeners -> add (
                                                                this );
        dispatcher -> patchEditorShowPulseTableListeners -> add (
                                                                 this );
        dispatcher -> patchEditorShowWaveTableListeners -> add (
                                                                this );
        dispatcher -> noteTableSelectionChangedListeners -> add (
                                                                 this );
        dispatcher -> noteTableRowChangedListeners -> add (
                                                           this );
    }
    else
    {
        dispatcher -> patchEditorShowNoteTableListeners -> add (
                                                                this );
        dispatcher -> patchEditorShowPulseTableListeners -> add (
                                                                 this );
        dispatcher -> patchEditorShowWaveTableListeners -> add (
                                                                this );
        dispatcher -> noteTableSelectionChangedListeners -> add (
                                                                 this );
        dispatcher -> noteTableRowChangedListeners -> remove (
                                                              this );
    }
}

void
    NoteTable::Write (
            XmlElement* e
            ) const
{
    auto nt = e -> getChildByName (
                                   "notetable" );
    if ( nt == nullptr )
    {
        nt = new XmlElement (
                             "notetable" );
        e -> addChildElement (
                              nt );
    }
    nt -> deleteAllChildElements ();
    for ( auto note : notes )
    {
        switch ( note -> rowType )
        {
            case RELATIVE:
                {
                    auto row = new XmlElement (
                                               "relative" );
                    row -> setAttribute (
                                         "offset"
                                       , String (
                                                 note -> value ) );
                    nt -> addChildElement (
                                           row );
                }
                break;
            case ABSOLUTE:
                {
                    auto row = new XmlElement (
                                               "absolute" );
                    row -> setAttribute (
                                         "frequency"
                                       , String (
                                                 note -> value ) );
                    nt -> addChildElement (
                                           row );
                }
                break;
            case COMMAND:
                {
                    auto command = new XmlElement (
                                                   "command" );
                    if ( ( note -> value & END_COMMAND ) == END_COMMAND )
                    {
                        command -> setAttribute (
                                                 "type"
                                               , "end" );
                    }
                    else if ( ( note -> value & GOTO_COMMAND ) == GOTO_COMMAND )
                    {
                        command -> setAttribute (
                                                 "type"
                                               , "goto" );
                    }
                    else if ( ( note -> value & SUSTAIN_TO_COMMAND ) == SUSTAIN_TO_COMMAND )
                    {
                        command -> setAttribute (
                                                 "type"
                                               , "sustain-to" );
                    }
                    if ( ( note -> value & END_COMMAND ) != END_COMMAND )
                    {
                        command -> setAttribute (
                                                 "argument"
                                               , String (
                                                         note -> value & UCHAR_MAX ) );
                    }
                    nt -> addChildElement (
                                           command );
                }
                break;
            default: ;
        }
    }
}

void
    NoteTable::WriteState (
            MemoryBlock& dest_data
            ) const
{
    unsigned int size = notes . size ();
    dest_data . append (
                        static_cast < const void* > ( &size )
                      , sizeof size );
    for ( const auto& row : notes )
    {
        auto row_type = static_cast < int > ( row -> rowType );
        dest_data . append (
                            static_cast < const void* > ( &row_type )
                          , sizeof row_type );
        dest_data . append (
                            static_cast < const void* > ( &row -> value )
                          , sizeof row -> value );
    }
}

void
// ReSharper disable once CppMemberFunctionMayBeStatic
    NoteTable::WriteCopyState (
            MemoryBlock& dest_data
            ) const {}

void
    NoteTable::LoadState (
            MemoryInputStream&                             stream
          , const ReferenceCountedObjectPtr < SidProgram > o // NOLINT(performance-unnecessary-value-param)
            )
{
    auto nt = o -> GetNoteTable ();
    nt -> notes . clear ();
    unsigned int count;
    stream . read (
                   &count
                 , sizeof count );
    for ( unsigned int i = 0 ; i < count ; i++ )
    {
        int row_type;
        int value;
        stream . read (
                       &row_type
                     , sizeof row_type );
        stream . read (
                       &value
                     , sizeof value );
        // ReSharper disable once CppInitializedValueIsAlwaysRewritten
        ArpRow row {};
        row . rowType = static_cast < ARP_ROW_TYPE > ( row_type );
        row . value   = value;
        nt -> notes . add (
                           new ArpRow (
                                       row ) );
    }
}

void
    NoteTable::LoadCopyState (
            MemoryInputStream&                       stream
          , ReferenceCountedObjectPtr < SidProgram > o // NOLINT(performance-unnecessary-value-param)
            ) {}

auto
    NoteTable::GetNoteTableSize () const -> unsigned { return notes . size (); }

auto
    NoteTable::GetNoteTableEntryAt (
            const unsigned index
            ) const -> ArpRow& { return *notes [ static_cast < int > ( index ) ]; }

auto
    NoteTable::GetCurrentNoteTableEntry () const -> ArpRow
{
    if ( noteTableIndex == -1 )
    {
        // ReSharper disable once CppLocalVariableMayBeConst
        auto ret = ArpRow {
                ABSOLUTE
              , 0
        };
        return ret;
    }
    return GetNoteTableEntryAt (
                                noteTableIndex );
}

void
    NoteTable::AddNoteTableEntry (
            ArpRow& value
            )
{
    notes . add (
                 new ArpRow (
                             value ) );
}

void
    NoteTable::SetNoteTableEntryAt (
            const unsigned index
          , ArpRow&        value
            )
{
    if ( notes . size () > static_cast < int > ( index ) )
    {
        notes . set (
                     static_cast < int > ( index )
                   , new ArpRow (
                                 value ) );
    }
}

void
    NoteTable::InsertNoteTableEntryAt (
            const unsigned index
          , ArpRow&        value
            )
{
    if ( notes . size () > static_cast < int > ( index ) )
    {
        notes . insert (
                        static_cast < int > ( index )
                      , new ArpRow (
                                    value ) );
    }
}

void
    NoteTable::RemoveNoteTableEntryAt (
            const unsigned index
            )
{
    if ( notes . size () > static_cast < int > ( index ) )
    {
        notes . remove (
                        static_cast < int > ( index ) );
    }
}

void
    NoteTable::Start ()
{
    noteTableIndex = -1;
    releaseCounter = 0;
    sustained      = false;
    released       = false;
}

void
    NoteTable::Step ()
{
    if ( Released () && DoneReleasing () ) { return; }
    noteTableIndex++;
    if ( noteTableIndex == notes . size () ) { noteTableIndex--; }
    const auto row = notes [ noteTableIndex ];
    if ( row -> rowType == COMMAND && ( row -> value & END_COMMAND ) == END_COMMAND ) { noteTableIndex--; }
    else if ( row -> rowType == COMMAND && ( row -> value & GOTO_COMMAND ) == GOTO_COMMAND ) { noteTableIndex = static_cast < int > ( notes [ noteTableIndex ] -> value ) & UCHAR_MAX; }
    else if ( row -> rowType == COMMAND && ( row -> value & SUSTAIN_TO_COMMAND ) == SUSTAIN_TO_COMMAND )
    {
        sustained = true;
        if ( !released ) { noteTableIndex = static_cast < int > ( notes [ noteTableIndex ] -> value ) & UCHAR_MAX; }
        else { noteTableIndex++; }
        if ( noteTableIndex == notes . size () ) { noteTableIndex -= 2; }
    }
    if ( releaseCounter > 0 ) { releaseCounter--; }
}

void
    NoteTable::Release (
            const unsigned release
            )
{
    releaseCounter = Wavetable::DECAY_RELEASE_FRAMES . at (
                                                           release );
    released = true;
}

auto
    NoteTable::Sustained () const -> bool { return sustained; }

auto
    NoteTable::Released () const -> bool { return released; }

auto
    NoteTable::DoneReleasing () const -> bool { return releaseCounter <= 0; }

void
    NoteTable::SetForVoice (
            const int value
            ) { forVoice = value; }

void
    NoteTable::onPatchEditorDeleteTableRowClicked ()
{
    RemoveNoteTableEntryAt (
                            selectedRow );
}

void
    NoteTable::onPatchEditorNewTableCommandClicked ()
{
    ArpRow row {
            COMMAND
          , END_COMMAND
    };
    if ( selectedRow < static_cast < unsigned int > ( notes . size () ) )
    {
        InsertNoteTableEntryAt (
                                selectedRow
                              , row );
    }
    else
    {
        AddNoteTableEntry (
                           row );
    }
}

void
    NoteTable::onPatchEditorNewTableRowClicked ()
{
    ArpRow row {
            RELATIVE
          , 0
    };
    if ( selectedRow < static_cast < unsigned int > ( notes . size () ) )
    {
        InsertNoteTableEntryAt (
                                selectedRow
                              , row );
    }
    else
    {
        AddNoteTableEntry (
                           row );
    }
}

void
    NoteTable::onNoteTableSelectionChanged (
            const unsigned row
            ) { selectedRow = row; }

void
    NoteTable::onNoteTableRowChanged (
            ArpRow& value
            )
{
    SetNoteTableEntryAt (
                         selectedRow
                       , value );
}

void
    NoteTable::onPatchEditorShowNoteTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> add (
                                                                     this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> add (
                                                                         this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> add (
                                                                        this );
}

void
    NoteTable::onPatchEditorShowPulseTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}

void
    NoteTable::onPatchEditorShowWaveTable ()
{
    dispatcher -> patchEditorNewWavetableRowClickedListeners -> remove (
                                                                        this );
    dispatcher -> patchEditorNewWavetableCommandClickedListeners -> remove (
                                                                            this );
    dispatcher -> patchEditorDeleteWavetableRowClickedListeners -> remove (
                                                                           this );
}
