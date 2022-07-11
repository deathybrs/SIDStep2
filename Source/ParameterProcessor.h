#pragma once


#include <JuceHeader.h>


#include "Defines.h"


#include "Listeners/ListenerInitializer.h"


#include "Parameters/BooleanParameter.h"
#include "Parameters/SignedPercentParameter.h"
#include "Parameters/UnsignedIntParameter.h"
#include "Parameters/UnsignedPercentParameter.h"


class ParameterProcessor final
        : public ReferenceCountedObject
        , public Frame
        , public LivePulseWidthChanged
        , public LiveAttackChanged
        , public LiveDecayChanged
        , public LiveSustainChanged
        , public LiveReleaseChanged
        , public LiveVoiceFilterChanged
        , public LiveCutoffChanged
        , public LiveResonanceChanged
        , public LiveLowPassChanged
        , public LiveBandPassChanged
        , public LiveHighPassChanged
        , public LiveVolumeChanged
        , public LivePitchBendChanged
        , public LiveVibratoAmountChanged
        , public LiveVibratoSpeedChanged
        , public LiveVibratoDelayChanged
        , public LiveTremoloAmountChanged
        , public LiveTremoloSpeedChanged
        , public LivePatchChanged
{
public:
    explicit
        ParameterProcessor (
                std::shared_ptr < EventDispatcher > dispatcher
                );

    ParameterProcessor (
            const ParameterProcessor& other
            ) = delete;

    ParameterProcessor (
            ParameterProcessor&& other
            ) = delete;

    ~ParameterProcessor () override;

    auto
        operator= (
                const ParameterProcessor& other
                ) -> ParameterProcessor& = delete;

    auto
        operator= (
                ParameterProcessor&& other
                ) -> ParameterProcessor& = delete;

    // Pulse Width ($d402-$d403 / $d409-$d40a / $d410-$d411)
    SET_VOICE_PARAMETER (
                         PulseWidth
                       , SignedPercent
                       , float
                       , LivePulseWidthChanged )

    // ADSR ($d405-$d406 / $d40c-$d40d / $d413-$d414)
    SET_VOICE_PARAMETER (
                         Attack
                       , UnsignedInt
                       , unsigned int
                       , LiveAttackChanged )
    SET_VOICE_PARAMETER (
                         Decay
                       , UnsignedInt
                       , unsigned int
                       , LiveDecayChanged )
    SET_VOICE_PARAMETER (
                         Sustain
                       , UnsignedInt
                       , unsigned int
                       , LiveSustainChanged )
    SET_VOICE_PARAMETER (
                         Release
                       , UnsignedInt
                       , unsigned int
                       , LiveReleaseChanged )

    // $Filter Routing ($d417)
    SET_VOICE_PARAMETER (
                         FilterVoice
                       , Boolean
                       , bool
                       , LiveVoiceFilterChanged )

    // Filter Cutoff ($d415-$d416)
    SET_PARAMETER (
                   Cutoff
                 , UnsignedInt
                 , unsigned int
                 , LiveCutoffChanged )

    // Filter Resonance ($d417)
    SET_PARAMETER (
                   Resonance
                 , UnsignedInt
                 , unsigned int
                 , LiveResonanceChanged )

    // Filter Mode & Volume Control ($d418)
    SET_PARAMETER (
                   LowPass
                 , Boolean
                 , bool
                 , LiveLowPassChanged )
    SET_PARAMETER (
                   BandPass
                 , Boolean
                 , bool
                 , LiveBandPassChanged )
    SET_PARAMETER (
                   HighPass
                 , Boolean
                 , bool
                 , LiveHighPassChanged )
    SET_PARAMETER (
                   Volume
                 , UnsignedInt
                 , unsigned int
                 , LiveVolumeChanged )

    // No direct memory reference
    SET_VOICE_PARAMETER (
                         PitchBend
                       , SignedPercent
                       , float
                       , LivePitchBendChanged )
    SET_VOICE_PARAMETER (
                         VibratoAmount
                       , UnsignedPercent
                       , float
                       , LiveVibratoAmountChanged )
    SET_VOICE_PARAMETER (
                         VibratoSpeed
                       , UnsignedPercent
                       , float
                       , LiveVibratoSpeedChanged )
    SET_VOICE_PARAMETER (
                         VibratoDelay
                       , UnsignedInt
                       , unsigned int
                       , LiveVibratoDelayChanged )
    SET_VOICE_PARAMETER (
                         TremoloAmount
                       , UnsignedPercent
                       , float
                       , LiveTremoloAmountChanged )
    SET_VOICE_PARAMETER (
                         TremoloSpeed
                       , UnsignedPercent
                       , float
                       , LiveTremoloSpeedChanged )
    SET_VOICE_PARAMETER (
                         Program
                       , UnsignedInt
                       , unsigned int
                       , LivePatchChanged )

    void
        onFrame () override;

    void
        ProcessGlobalParameters () const;

    void
        ProcessVoiceParameters (
                int v
                ) const;

private:
    std::shared_ptr < EventDispatcher > dispatcher;
};
