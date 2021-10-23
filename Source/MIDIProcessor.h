#pragma once


#include <JuceHeader.h>


#include "Listeners/ListenerInitializer.h"


class MidiProcessor final
        : public ReferenceCountedObject
        , public MIDISignal
{
public:
    MidiProcessor ();

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

    static void
        MidiNoteOff (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                );

    static void
        MidiNoteOn (
                unsigned int channel
              , unsigned int note
              , unsigned int velocity
                );

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
};
