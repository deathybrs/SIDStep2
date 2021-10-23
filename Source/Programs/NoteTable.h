#pragma once


#include <JuceHeader.h>

#include "../Listeners/ListenerInitializer.h"

#include "../Programs/ArpRow.h"

class NoteTable final
        : public ReferenceCountedObject
        , public PatchEditorNewTableRowClicked
        , public PatchEditorNewTableCommandClicked
        , public PatchEditorDeleteTableRowClicked
        , public PatchEditorShowPulseTable
        , public PatchEditorShowNoteTable
        , public PatchEditorShowWaveTable
        , public NoteTableSelectionChanged
        , public NoteTableRowChanged
{
public:
    NoteTable ();

    explicit
        NoteTable (
                XmlElement* e
                );

    NoteTable (
            const NoteTable& other
            );

    NoteTable (
            NoteTable&& other
            ) noexcept;

    ~NoteTable () override = default;

    auto
        operator= (
                const NoteTable& other
                ) -> NoteTable&;

    auto
        operator= (
                NoteTable&& other
                ) noexcept -> NoteTable&;

    void
        Select (
                bool value
                );

    void
        Write (
                XmlElement* e
                ) const;

    void
        WriteState (
                MemoryBlock& dest_data
                ) const;

    void
        WriteCopyState (
                MemoryBlock& dest_data
                ) const;

    static void
        LoadState (
                MemoryInputStream&                       stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    static void
        LoadCopyState (
                MemoryInputStream&                       stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    auto
        GetNoteTableSize () const -> unsigned int;

    auto
        GetNoteTableEntryAt (
                unsigned int index
                ) const -> ArpRow&;

    auto
        GetCurrentNoteTableEntry () const -> ArpRow&;

    void
        AddNoteTableEntry (
                ArpRow& value
                );

    void
        SetNoteTableEntryAt (
                unsigned int index
              , ArpRow&      value
                );

    void
        InsertNoteTableEntryAt (
                unsigned int index
              , ArpRow&      value
                );

    void
        RemoveNoteTableEntryAt (
                unsigned int index
                );

    void
        Start ();

    void
        Step ();

    void
        Release (
                unsigned int release
                );

    auto
        Sustained () const -> bool;

    auto
        Released () const -> bool;

    auto
        DoneReleasing () const -> bool;

    void
        SetForVoice (
                int value
                );

    void
        onPatchEditorDeleteTableRowClicked () override;

    void
        onPatchEditorNewTableCommandClicked () override;

    void
        onPatchEditorNewTableRowClicked () override;

    void
        onNoteTableSelectionChanged (
                unsigned row
                ) override;

    void
        onNoteTableRowChanged (
                ArpRow& value
                ) override;

    void
        onPatchEditorShowNoteTable () override;

    void
        onPatchEditorShowPulseTable () override;

    void
        onPatchEditorShowWaveTable () override;

private:
    OwnedArray < ArpRow >                                          notes;
    int                                                            noteTableIndex = 0;
    bool                                                           sustained      = false;
    bool                                                           released       = false;
    unsigned int                                                   releaseCounter = 0;
    unsigned int                                                   selectedRow    = 0;
    SharedResourcePointer < ListenerList < NoteTableRowChanged > > noteTableRowChangedListeners;
    int                                                            forVoice           = 0;
    static const int                                               END_COMMAND        = 0x100;
    static const int                                               GOTO_COMMAND       = 0x200;
    static const int                                               SUSTAIN_TO_COMMAND = 0x400;
};
