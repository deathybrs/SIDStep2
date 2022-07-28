#pragma once


#include "JuceHeader.h"


#include "../Listeners/ListenerInitializer.h"


class PulseTable final
        : public ReferenceCountedObject
        , public PatchEditorNewTableRowClicked
        , public PatchEditorNewTableCommandClicked
        , public PatchEditorDeleteTableRowClicked
        , public PatchEditorShowPulseTable
        , public PatchEditorShowNoteTable
        , public PatchEditorShowWaveTable
        , public PulseTableSelectionChanged
        , public PulseTableRowChanged
{
public:
    explicit
        PulseTable (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    explicit
        PulseTable (
                std::shared_ptr < EventDispatcher > dispatcher
              , XmlElement*                         e
                );

    PulseTable (
            const PulseTable& other
            );

    PulseTable (
            PulseTable&& other
            ) noexcept;

    ~PulseTable () override;

    auto
        operator= (
                const PulseTable& other
                ) -> PulseTable&;

    auto
        operator= (
                PulseTable&& other
                ) noexcept -> PulseTable&;

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
                MemoryInputStream&                              stream
              , const ReferenceCountedObjectPtr < SidProgram >& o
                );

    static void
        LoadCopyState (
                MemoryInputStream&                              stream
              , const ReferenceCountedObjectPtr < SidProgram >& o
                );

    auto
        GetPulseTableSize () const -> unsigned int;

    auto
        GetPulseTableEntryAt (
                unsigned int index
                ) const -> unsigned;

    auto
        GetCurrentPulseTableEntry () const -> unsigned;

    void
        AddPulseTableEntry (
                unsigned value
                );

    void
        SetPulseTableEntryAt (
                unsigned int index
              , unsigned     value
                );

    void
        InsertPulseTableEntryAt (
                unsigned int index
              , unsigned     value
                );

    void
        RemovePulseTableEntryAt (
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
        onPulseTableSelectionChanged (
                unsigned row
                ) override;

    void
        onPulseTableRowChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorShowPulseTable () override;

    void
        onPatchEditorShowNoteTable () override;

    void
        onPatchEditorShowWaveTable () override;

private:
    std::shared_ptr < EventDispatcher > dispatcher;
    Array < unsigned int >              table;
    int                                 pulseTableIndex = 0;
    bool                                sustained       = false;
    bool                                released        = false;
    unsigned int                        releaseCounter  = 0;
    unsigned int                        selectedRow     = 0;
    //SharedResourcePointer < ListenerList < PulseTableRowChanged > > pulseTableRowChangedListeners;
    int              forVoice             = 0;
    static const int END_COMMAND          = 0x1000;
    static const int GOTO_COMMAND         = 0x2000;
    static const int SUSTAIN_TO_COMMAND   = 0x4000;
    static const int CYCLE_CENTER         = 0x0800;
    static const int COMMAND_NYBBLE_MASK  = 0xF000;
    static const int ARGUMENT_NYBBLE_MASK = 0x0FFF;
};
