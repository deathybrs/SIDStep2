#ifndef WAVETABLE_H_INCLUDED
#define WAVETABLE_H_INCLUDED

#include "JuceHeader.h"

#include <array>

#include "../Listeners/ListenerInitializer.h"


// ReSharper disable once CppInconsistentNaming
class SidProgram;

class Wavetable final
        : public ReferenceCountedObject
        , public PatchEditorNewTableRowClicked
        , public PatchEditorNewTableCommandClicked
        , public PatchEditorDeleteTableRowClicked
        , public PatchEditorShowNoteTable
        , public PatchEditorShowPulseTable
        , public PatchEditorShowWaveTable
        , public WavetableRowChanged
        , public WavetableSelectionChanged
{
public:
    explicit
        Wavetable (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    explicit
        Wavetable (
                std::shared_ptr < EventDispatcher > dispatcher
              , XmlElement*                         e
                );

    Wavetable (
            const Wavetable& other
            );

    Wavetable (
            Wavetable&& other
            ) noexcept;

    ~Wavetable () override;

    auto
        operator= (
                const Wavetable& other
                ) -> Wavetable&;

    auto
        operator= (
                Wavetable&& other
                ) noexcept -> Wavetable&;

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
              , const ReferenceCountedObjectPtr < SidProgram >& o
                );

    static void
        LoadCopyState (
                MemoryInputStream&                       stream
              , const ReferenceCountedObjectPtr < SidProgram >& o
                );

    auto
        GetWaveTableSize () const -> unsigned int;

    auto
        GetWaveTableEntryAt (
                unsigned int index
                ) const -> unsigned int;

    auto
        GetCurrentWaveTableEntry () const -> unsigned int;

    void
        AddWaveTableEntry (
                unsigned int value
                );

    void
        SetWaveTableEntryAt (
                unsigned int index
              , unsigned int value
                );

    void
        InsertWaveTableEntryAt (
                unsigned int index
              , unsigned int value
                );

    void
        RemoveWaveTableEntryAt (
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

    void
        SetForVoice (
                int value
                );

    auto
        Sustained () const -> bool;

    auto
        Released () const -> bool;

    auto
        DoneReleasing () const -> bool;

    void
        onPatchEditorNewTableRowClicked () override;

    void
        onPatchEditorNewTableCommandClicked () override;

    void
        onPatchEditorDeleteTableRowClicked () override;

    void
        onWavetableRowChanged (
                unsigned int value
                ) override;

    void
        onWavetableSelectionChanged (
                unsigned int row
                ) override;

    void
        onPatchEditorShowNoteTable () override;

    void
        onPatchEditorShowPulseTable () override;

    void
        onPatchEditorShowWaveTable () override;

private:
    std::shared_ptr < EventDispatcher > dispatcher;
    Array < unsigned int > waveTable;
    int                    waveTableIndex {
            0
    };
    bool sustained {
            false
    };
    bool released {
            true
    };
    unsigned int releaseCounter {
            0
    };
    unsigned int                                                   selectedRow;
    //SharedResourcePointer < ListenerList < WavetableRowChanged > > wavetableRowChangedListeners;
    int                                                            forVoice {
            -1
    };
public:
    static constexpr std::array < int , 16 > ATTACK_FRAMES {
            1
          , 1
          , 1
          , 2
          , 2
          , 3
          , 4
          , 5
          , 6
          , 13
          , 26
          , 41
          , 51
          , 153
          , 254
          , 406
    };
    static constexpr std::array < int , 16 > DECAY_RELEASE_FRAMES {
            1
          , 2
          , 3
          , 4
          , 6
          , 9
          , 11
          , 13
          , 16
          , 39
          , 77
          , 122
          , 153
          , 457
          , 762
          , 1218
    };
private:
    static const int DEFAULT_WAVEFORM   = 0x41;
    static const int RELEASE_MASK       = 0xFE;
    static const int END_COMMAND        = 0x100;
    static const int GOTO_COMMAND       = 0x200;
    static const int SUSTAIN_TO_COMMAND = 0x400;
    static const int TRIANGLE_BIT       = 0x10;
    static const int SAWTOOTH_BIT       = 0x20;
    static const int PULSE_BIT          = 0x40;
    static const int NOISE_BIT          = 0x80;
    static const int GATE_BIT           = 0x01;
    static const int SYNC_BIT           = 0x02;
    static const int RING_BIT           = 0x04;
    static const int TEST_BIT           = 0x08;
};
#endif  // WAVETABLE_H_INCLUDED
