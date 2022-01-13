#pragma once

#include <array>

#include "Listeners/ListenerInitializer.h"

enum class COMMANDS;

class Command;

class Recorder final
        : public NoteOff
        , public NoteOn
        , public AttackParameterChanged
        , public BandPassParameterChanged
        , public CutoffParameterChanged
        , public DecayParameterChanged
        , public FilterVoiceParameterChanged
        , public HighPassParameterChanged
        , public LowPassParameterChanged
        , public PitchBendParameterChanged
        , public LoadLivePatch
        , public ProgramParameterChanged
        , public PulseWidthParameterChanged
        , public ReleaseParameterChanged
        , public ResonanceParameterChanged
        , public SustainParameterChanged
        , public VibratoAmountParameterChanged
        , public VibratoDelayParameterChanged
        , public VibratoSpeedParameterChanged
        , public VolumeParameterChanged
        , public QuarterNoteTick
{
public:
    Recorder () = default;

    Recorder (
            const Recorder& other
            ) = delete;

    Recorder (
            Recorder&& other
            ) = delete;

    ~Recorder () override;

    auto
        operator= (
                const Recorder& other
                ) -> Recorder& = delete;

    auto
        operator= (
                Recorder&& other
                ) -> Recorder& = delete;

    void
        Start ();

    void
        Stop ();

    void
        Frame (
                unsigned frame
                );

    void
        SaveDebug ();

    void
        onNoteOff (
                unsigned channel
              , unsigned note
              , unsigned velocity
                ) override;

    void
        onNoteOn (
                unsigned channel
              , unsigned note
              , unsigned velocity
                ) override;

    void
        onAttackParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onBandPassParameterChanged (
                bool value
                ) override;

    void
        onCutoffParameterChanged (
                unsigned value
                ) override;

    void
        onDecayParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onFilterVoiceParameterChanged (
                unsigned voice
              , bool     value
                ) override;

    void
        onHighPassParameterChanged (
                bool value
                ) override;

    void
        onLowPassParameterChanged (
                bool value
                ) override;

    void
        onPitchBendParameterChanged (
                unsigned voice
              , float    value
                ) override;

    void
        onLoadLivePatch (
                unsigned                                 voice
              , ReferenceCountedObjectPtr < SidProgram > program
                ) override;

    void
        onProgramParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onPulseWidthParameterChanged (
                unsigned voice
              , float    value
                ) override;

    void
        onReleaseParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onResonanceParameterChanged (
                unsigned value
                ) override;

    void
        onSustainParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onVibratoAmountParameterChanged (
                unsigned voice
              , float    value
                ) override;

    void
        onVibratoDelayParameterChanged (
                unsigned voice
              , unsigned value
                ) override;

    void
        onVibratoSpeedParameterChanged (
                unsigned voice
              , float    value
                ) override;

    void
        onVolumeParameterChanged (
                unsigned value
                ) override;

    void
        onQuarterNoteTick (
                unsigned ppq
                ) override;

private:
    void
        RemovePendingGlobal (
                COMMANDS type
                );

    void
        RemovePendingVoice (
                COMMANDS type
              , unsigned voice
                );

    bool recording {
            false
    };
    std::vector < std::shared_ptr < Command > >                    globalCommands;
    std::array < std::vector < std::shared_ptr < Command > > , 3 > voiceCommands;
    std::vector < std::shared_ptr < Command > >                    currentGlobalCommands;
    std::array < std::vector < std::shared_ptr < Command > > , 3 > currentVoiceCommands;
    std::array < std::vector < unsigned char > , 3 >               currentNotes;
    std::array < bool , 3 >                                        notesChanged {
            false
          , false
          , false
    };
    unsigned currentFrame {
            0
    };
    std::vector < std::array < size_t , 4 > >                   patternIndexes {};
    std::vector < unsigned >                                    patternFrame {};
    std::array < ReferenceCountedObjectPtr < SidProgram > , 3 > programs {};
    std::array < unsigned char , 3 >                            currentAttack {};
    std::array < unsigned char , 3 >                            currentDecay {};
    std::array < unsigned char , 3 >                            currentSustain {};
    std::array < unsigned char , 3 >                            currentRelease {};
    int currentPpq {
            -1
    };
    bool                                                        currentBandPass {
            false
    };
    bool currentHighPass {
            false
    };
    bool currentLowPass {
            false
    };
    std::array < bool , 3 > currentVoiceFilters {
            false
          , false
          , false
    };
    std::array < unsigned , 3 > currentProgram {
            256
          , 256
          , 256
    };
    unsigned short              currentCutoff {};
    float                       currentPitchBend {};
    int                         currentVibratoAmount {};
    unsigned                    currentVibratoDelay {};
    unsigned char               currentVibratoSpeed {};
    int                         currentPulseWidth {};
    unsigned                    currentResonance {};
    unsigned                    currentVolume {};

    friend class Exporter;
    friend class CommandView;
};
