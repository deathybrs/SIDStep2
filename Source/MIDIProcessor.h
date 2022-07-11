#pragma once


#include <JuceHeader.h>


#include "Listeners/ListenerInitializer.h"


class MidiProcessor final
        : public ReferenceCountedObject
        , public MIDISignal
{
public:
    explicit
        MidiProcessor (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    MidiProcessor (
            const MidiProcessor& other
            ) = delete;

    MidiProcessor (
            MidiProcessor&& other
            ) = delete;

    ~MidiProcessor () override;

    auto
        operator= (
                const MidiProcessor& other
                ) -> MidiProcessor& = delete;

    auto
        operator= (
                MidiProcessor&& other
                ) -> MidiProcessor& = delete;

    // MIDI Processors
    void
        onMIDISignal (
                MidiMessage m
                ) override;

    void
        MidiNoteOff (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                ) const;

    void
        MidiNoteOn (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                ) const;

    void
        MidiProgramChange (
                unsigned int channel
              , unsigned int program_number
                ) const;

    void
        MidiPitchBend (
                unsigned int channel
              , unsigned int value
                ) const;

private:
    std::shared_ptr < EventDispatcher > dispatcher;
};
