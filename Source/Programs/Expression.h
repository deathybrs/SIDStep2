#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"


#include "Vibrato.h"
#include "Tremolo.h"

#include "../Listeners/ListenerInitializer.h"


class SidProgram;


class Expressions
        : public ReferenceCountedObject ,
          public PatchEditorPitchBendRangeChanged ,
          public PatchEditorPulseWidthRangeChanged ,
          public PatchEditorPulseWidthCenterChanged ,
          public PatchEditorPulseWidthDefaultChanged ,
          public LivePitchBendChanged ,
          public LivePulseWidthChanged ,
          public PitchBend ,
          public PitchBendParameterChanged ,
          public PulseWidthParameterChanged
{
public:
    Expressions ();

    Expressions (
            XmlElement* e
            );

    Expressions (
            Expressions& original
            );

    ~Expressions ();

    void
        select (
                bool value
                );

    void
        write (
                XmlElement* e
                ) const;

    void
        writeState (
                MemoryBlock& destData
                ) const;

    void
        writeCopyState (
                MemoryBlock& destData
                ) const;

    static void
        loadState (
                MemoryInputStream&                 stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    static void
        loadCopyState (
                MemoryInputStream&                 stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    ReferenceCountedObjectPtr < Vibrato >
        getVibrato () const;

    ReferenceCountedObjectPtr < Tremolo >
        getTremolo () const;

    unsigned int
        getPitchBendRange () const;

    void
        setPitchBendRange (
                unsigned int value
                );

    unsigned int
        getPulseWidthRange () const;

    void
        setPulseWidthRange (
                unsigned int value
                );

    unsigned int
        getPulseWidthCenter () const;

    void
        setPulseWidthCenter (
                unsigned int value
                );

    float
        getPulseWidthDefault () const;

    void
        setPulseWidthDefault (
                float value
                );

    float
        getPulseOffset () const;

    void
        setPulseOffset (
                float value
                );

    float
        getPitchBend () const;

    void
        setPitchBend (
                float value
                );

    unsigned int
        getCurrentPulseValue () const;

    void
        Start () const;

    void
        Step () const;

    void
        Release () const;

    void
        onPatchEditorPitchBendRangeChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorPulseWidthRangeChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorPulseWidthCenterChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorPulseWidthDefaultChanged (
                float value
                ) override;

    void
        onLivePitchBendChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onLivePulseWidthChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onPitchBendParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onPulseWidthParameterChanged (
                unsigned int voice
              , float        value
                ) override;

    void
        onPitchBend (
                unsigned int voice
              , int          value
                ) override;

    void
        setForVoice (
                int value
                );

private:
    ReferenceCountedObjectPtr < Vibrato > vibrato;
    ReferenceCountedObjectPtr < Tremolo > tremolo;

    unsigned int pitchBendRange;
    float        pulseWidthDefault;
    unsigned int pulseWidthRange;
    unsigned int pulseWidthCenter;

    float pulseOffset;
    float currentPitchBend;

    int forVoice;
};


#endif  // EXPRESSION_H_INCLUDED
