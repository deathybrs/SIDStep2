#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "../Listeners/ListenerInitializer.h"

class SidProgram;

class sEnvelope
        : public ReferenceCountedObject
        , public PatchEditorAttackChanged
        , public PatchEditorDecayChanged
        , public PatchEditorSustainChanged
        , public PatchEditorReleaseChanged
        , public LiveAttackChanged
        , public LiveDecayChanged
        , public LiveSustainChanged
        , public LiveReleaseChanged
        , public AttackParameterChanged
        , public DecayParameterChanged
        , public SustainParameterChanged
        , public ReleaseParameterChanged
{
public:
    sEnvelope ();

    sEnvelope (
            XmlElement* e
            );

    sEnvelope (
            sEnvelope& original
            );

    ~sEnvelope ();

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
                MemoryInputStream&                       stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    static void
        loadCopyState (
                MemoryInputStream&                       stream
              , ReferenceCountedObjectPtr < SidProgram > o
                );

    unsigned int
        getDefaultAttack () const;

    void
        setDefaultAttack (
                unsigned int value
                );

    unsigned int
        getDefaultDecay () const;

    void
        setDefaultDecay (
                unsigned int value
                );

    unsigned int
        getDefaultSustain () const;

    void
        setDefaultSustain (
                unsigned int value
                );

    unsigned int
        getDefaultRelease () const;

    void
        setDefaultRelease (
                unsigned int value
                );

    unsigned int
        getAttack () const;

    void
        setAttack (
                unsigned int value
                );

    unsigned int
        getDecay () const;

    void
        setDecay (
                unsigned int value
                );

    unsigned int
        getSustain () const;

    void
        setSustain (
                unsigned int value
                );

    unsigned int
        getRelease () const;

    void
        setRelease (
                unsigned int value
                );

    void
        onPatchEditorAttackChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorDecayChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorSustainChanged (
                unsigned int value
                ) override;

    void
        onPatchEditorReleaseChanged (
                unsigned int value
                ) override;

    void
        onLiveAttackChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onLiveDecayChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onLiveSustainChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onLiveReleaseChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onAttackParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onDecayParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onSustainParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        onReleaseParameterChanged (
                unsigned int voice
              , unsigned int value
                ) override;

    void
        SetForVoice (
                int value
                );

private:
    unsigned int defaultAttack;
    unsigned int defaultDecay;
    unsigned int defaultSustain;
    unsigned int defaultRelease;
    unsigned int attack;
    unsigned int decay;
    unsigned int sustain;
    unsigned int release;
    int          forVoice;
};

