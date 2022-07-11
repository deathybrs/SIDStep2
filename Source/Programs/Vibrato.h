#pragma once

#include "JuceHeader.h"

#include "../Listeners/ListenerInitializer.h"

class SidProgram;

class Vibrato final
        : public ReferenceCountedObject
        , public PatchEditorVibratoRangeChanged
        , public PatchEditorVibratoSpeedChanged
        , public PatchEditorVibratoDefaultAmountChanged
        , public PatchEditorVibratoDefaultSpeedChanged
        , public PatchEditorVibratoDelayChanged
        , public LiveVibratoAmountChanged
        , public LiveVibratoDelayChanged
        , public LiveVibratoSpeedChanged
        , public VibratoAmountParameterChanged
        , public VibratoDelayParameterChanged
        , public VibratoSpeedParameterChanged
{
public:
    explicit
        Vibrato (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    explicit
        Vibrato (
                std::shared_ptr < EventDispatcher > dispatcher
              , XmlElement*                         e
                );

    Vibrato (
            const Vibrato& other
            );

    Vibrato (
            Vibrato&& other
            ) noexcept;

    ~Vibrato () override;

    auto
        operator= (
                const Vibrato& other
                ) -> Vibrato&;

    auto
        operator= (
                Vibrato&& other
                ) noexcept -> Vibrato&;

    void
        Select (
                bool value
                );

    void
        Start ();

    void
        Step ();

    void
        Release ();

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
                MemoryInputStream&                              stream
              , const ReferenceCountedObjectPtr < SidProgram >& o
                );

    auto
        GetVibratoRange () const -> unsigned int;

    void
        SetVibratoRange (
                unsigned int value
                );

    auto
        GetVibratoSpeed () const -> unsigned int;

    void
        SetVibratoSpeed (
                unsigned int value
                );

    auto
        GetVibratoDelay () const -> unsigned int;

    void
        SetVibratoDelay (
                unsigned int value
                );

    auto
        GetDefaultVibratoAmount () const -> float;

    void
        SetDefaultVibratoAmount (
                float value
                );

    auto
        GetDefaultVibratoSpeed () const -> float;

    void
        SetDefaultVibratoSpeed (
                float value
                );

    auto
        GetCurrentVibratoAmount () const -> float;

    void
        SetCurrentVibratoAmount (
                float value
                );

    auto
        GetCurrentVibratoSpeed () const -> float;

    void
        SetCurrentVibratoSpeed (
                float value
                );

    auto
        GetCurrentVibratoDelay () const -> unsigned int;

    void
        SetCurrentVibratoDelay (
                unsigned int value
                );

    auto
        GetCurrentVibratoValue () const -> int;

    void
        SetForVoice (
                int value
                );

    void
        onPatchEditorVibratoRangeChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorVibratoSpeedChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorVibratoDefaultAmountChanged (
                float value
                ) override;

    void
        onPatchEditorVibratoDefaultSpeedChanged (
                float value
                ) override;

    void
        onLiveVibratoAmountChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onLiveVibratoSpeedChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onVibratoAmountParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onVibratoSpeedParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onLiveVibratoDelayChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onVibratoDelayParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onPatchEditorVibratoDelayChanged (
                unsigned value
                ) override;

private:
    static const int VIBRATO_RANGE = 85;
    static const int VIBRATO_SPEED = 5;
    std::shared_ptr < EventDispatcher > dispatcher;
    unsigned int     vibratoRange {
            VIBRATO_RANGE
    };
    unsigned int vibratoSpeed {
            VIBRATO_SPEED
    };
    unsigned int vibratoDelay {
            0
    };
    float defaultVibratoAmount {
            0
    };
    float defaultVibratoSpeed {
            1
    };
    float        currentVibratoAmount;
    float        currentVibratoSpeed;
    unsigned int currentVibratoDelay;
    unsigned int vibratoCounter {
            0
    };
    int forVoice {
            -1
    };
};
