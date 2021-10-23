#include "MIDIProcessor.h"


#include "SIDStep2.h"


MidiProcessor::MidiProcessor ()
{
    SharedResourcePointer < ListenerList < MIDISignal > > () -> add (
                                                                     this );
}

MidiProcessor::~MidiProcessor ()
{
    SharedResourcePointer < ListenerList < MIDISignal > > () -> remove (
                                                                        this );
}

void
    MidiProcessor::onMIDISignal (
            const MidiMessage m
            )
{
    if ( m . isNoteOff () )
    {
        MidiNoteOff (
                     m . getChannel () - 1
                   , m . getNoteNumber ()
                   , m . getVelocity () );
    }
    else if ( m . isNoteOn () )
    {
        MidiNoteOn (
                    m . getChannel () - 1
                  , m . getNoteNumber ()
                  , m . getVelocity () );
    }
    else if ( m . isProgramChange () )
    {
        MidiProgramChange (
                           m . getChannel () - 1
                         , m . getProgramChangeNumber () );
    }
    else if ( m . isPitchWheel () )
    {
        MidiPitchBend (
                       m . getChannel () - 1
                     , m . getPitchWheelValue () );
    }
}

void
    MidiProcessor::MidiNoteOff (
            const unsigned int channel
          , const unsigned int note
          , const unsigned int velocity
            )
{
    if ( channel > 2 )
    {
        return;
    }
    SharedResourcePointer < ListenerList < NoteOff > > () -> call (
                                                                   &NoteOff::onNoteOff
                                                                 , channel
                                                                 , note
                                                                 , velocity );
}

void
    MidiProcessor::MidiNoteOn (
            const unsigned int channel
          , const unsigned int note
          , const unsigned int velocity
            )
{
    if ( channel > 2 )
    {
        return;
    }
    SharedResourcePointer < ListenerList < NoteOn > > () -> call (
                                                                  &NoteOn::onNoteOn
                                                                , channel
                                                                , note
                                                                , velocity );
}

void
    MidiProcessor::MidiProgramChange (
            const unsigned int channel
          , const unsigned int program_number
            ) const
{
    if ( channel > 2 )
    {
        return;
    }

    SharedResourcePointer < ListenerList < ProgramParameterChanged > > () -> call (
                                                                                   &ProgramParameterChanged::onProgramParameterChanged
                                                                                 , channel
                                                                                 , program_number );
}

void
    MidiProcessor::MidiPitchBend (
            const unsigned int channel
          , const unsigned int value
            ) const
{
    if ( channel > 2 )
    {
        return;
    }
    SharedResourcePointer < ListenerList < PitchBend > > () -> call (
                                                                     &PitchBend::onPitchBend
                                                                   , channel
                                                                   , value );
}
