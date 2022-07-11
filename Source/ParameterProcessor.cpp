#include "ParameterProcessor.h"
#include "SIDRegisters.h"

ParameterProcessor::ParameterProcessor (
        std::shared_ptr < EventDispatcher > dispatcher
        )
    :
    _CutoffParameter (
                      nullptr )
  , _ResonanceParameter (
                         nullptr )
  , _LowPassParameter (
                       nullptr )
  , _BandPassParameter (
                        nullptr )
  , _HighPassParameter (
                        nullptr )
  , _VolumeParameter (
                      nullptr )
  , dispatcher (
                dispatcher )
{
    for ( auto i = 0 ; i < 3 ; i++ )
    {
        _ProgramParameters . add (
                                  nullptr );
        _PulseWidthParameters . add (
                                     nullptr );
        _AttackParameters . add (
                                 nullptr );
        _DecayParameters . add (
                                nullptr );
        _SustainParameters . add (
                                  nullptr );
        _ReleaseParameters . add (
                                  nullptr );
        _FilterVoiceParameters . add (
                                      nullptr );
        _PitchBendParameters . add (
                                    nullptr );
        _VibratoAmountParameters . add (
                                        nullptr );
        _VibratoSpeedParameters . add (
                                       nullptr );
        _VibratoDelayParameters . add (
                                       nullptr );
        _TremoloAmountParameters . add (
                                        nullptr );
        _TremoloSpeedParameters . add (
                                       nullptr );
    }
    dispatcher -> livePulseWidthChangedListeners -> add (
                                                         this );
    dispatcher -> liveAttackChangedListeners -> add (
                                                     this );
    dispatcher -> liveDecayChangedListeners -> add (
                                                    this );
    dispatcher -> liveSustainChangedListeners -> add (
                                                      this );
    dispatcher -> liveReleaseChangedListeners -> add (
                                                      this );
    dispatcher -> liveVoiceFilterChangedListeners -> add (
                                                          this );
    dispatcher -> liveCutoffChangedListeners -> add (
                                                     this );
    dispatcher -> liveResonanceChangedListeners -> add (
                                                        this );
    dispatcher -> liveLowPassChangedListeners -> add (
                                                      this );
    dispatcher -> liveBandPassChangedListeners -> add (
                                                       this );
    dispatcher -> liveHighPassChangedListeners -> add (
                                                       this );
    dispatcher -> liveVolumeChangedListeners -> add (
                                                     this );
    dispatcher -> livePitchBendChangedListeners -> add (
                                                        this );
    dispatcher -> liveVibratoAmountChangedListeners -> add (
                                                            this );
    dispatcher -> liveVibratoDelayChangedListeners -> add (
                                                           this );
    dispatcher -> liveVibratoSpeedChangedListeners -> add (
                                                           this );
    dispatcher -> liveTremoloAmountChangedListeners -> add (
                                                            this );
    dispatcher -> liveTremoloSpeedChangedListeners -> add (
                                                           this );
    dispatcher -> liveVolumeChangedListeners -> add (
                                                     this );
    dispatcher -> frameListeners -> add (
                                         this );
}

ParameterProcessor::~ParameterProcessor ()
{
    dispatcher -> livePulseWidthChangedListeners -> remove (
                                                            this );
    dispatcher -> liveAttackChangedListeners -> remove (
                                                        this );
    dispatcher -> liveDecayChangedListeners -> remove (
                                                       this );
    dispatcher -> liveSustainChangedListeners -> remove (
                                                         this );
    dispatcher -> liveReleaseChangedListeners -> remove (
                                                         this );
    dispatcher -> liveVoiceFilterChangedListeners -> remove (
                                                             this );
    dispatcher -> liveCutoffChangedListeners -> remove (
                                                        this );
    dispatcher -> liveResonanceChangedListeners -> remove (
                                                           this );
    dispatcher -> liveLowPassChangedListeners -> remove (
                                                         this );
    dispatcher -> liveBandPassChangedListeners -> remove (
                                                          this );
    dispatcher -> liveHighPassChangedListeners -> remove (
                                                          this );
    dispatcher -> liveVolumeChangedListeners -> remove (
                                                        this );
    dispatcher -> livePitchBendChangedListeners -> remove (
                                                           this );
    dispatcher -> liveVibratoAmountChangedListeners -> remove (
                                                               this );
    dispatcher -> liveVibratoDelayChangedListeners -> remove (
                                                              this );
    dispatcher -> liveVibratoSpeedChangedListeners -> remove (
                                                              this );
    dispatcher -> liveTremoloAmountChangedListeners -> remove (
                                                               this );
    dispatcher -> liveTremoloSpeedChangedListeners -> remove (
                                                              this );
    dispatcher -> liveVolumeChangedListeners -> remove (
                                                        this );
    dispatcher -> frameListeners -> remove (
                                            this );
}

void
    ParameterProcessor::onFrame ()
{
    ProcessGlobalParameters ();
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        ProcessVoiceParameters (
                                v );
    }
}

void
    ParameterProcessor::ProcessGlobalParameters () const
{
    PROCESS_PARAMETER (
                       Cutoff
                     , UnsignedInt
                     , CutoffParameterChanged
                     , dispatcher->cutoffParameterChangedListeners );
    PROCESS_PARAMETER (
                       Resonance
                     , UnsignedInt
                     , ResonanceParameterChanged
                     , dispatcher->resonanceParameterChangedListeners );
    PROCESS_PARAMETER (
                       LowPass
                     , Boolean
                     , LowPassParameterChanged
                     , dispatcher->lowPassParameterChangedListeners );
    PROCESS_PARAMETER (
                       BandPass
                     , Boolean
                     , BandPassParameterChanged
                     , dispatcher->bandPassParameterChangedListeners );
    PROCESS_PARAMETER (
                       HighPass
                     , Boolean
                     , HighPassParameterChanged
                     , dispatcher->highPassParameterChangedListeners );
    PROCESS_PARAMETER (
                       Volume
                     , UnsignedInt
                     , VolumeParameterChanged
                     , dispatcher->volumeParameterChangedListeners );
}

void
    ParameterProcessor::ProcessVoiceParameters (
            const int v
            ) const
{
    PROCESS_VOICE_PARAMETER (
                             Program
                           , UnsignedInt
                           , ProgramParameterChanged
                           , dispatcher->programParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             PulseWidth
                           , SignedPercent
                           , PulseWidthParameterChanged
                           , dispatcher->pulseWidthParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             Attack
                           , UnsignedInt
                           , AttackParameterChanged
                           , dispatcher->attackParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             Decay
                           , UnsignedInt
                           , DecayParameterChanged
                           , dispatcher->decayParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             Sustain
                           , UnsignedInt
                           , SustainParameterChanged
                           , dispatcher->sustainParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             Release
                           , UnsignedInt
                           , ReleaseParameterChanged
                           , dispatcher->releaseParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             FilterVoice
                           , Boolean
                           , FilterVoiceParameterChanged
                           , dispatcher->filterVoiceParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             PitchBend
                           , SignedPercent
                           , PitchBendParameterChanged
                           , dispatcher->pitchBendParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             VibratoAmount
                           , UnsignedPercent
                           , VibratoAmountParameterChanged
                           , dispatcher->vibratoAmountParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             VibratoDelay
                           , UnsignedInt
                           , VibratoDelayParameterChanged
                           , dispatcher->vibratoDelayParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             VibratoSpeed
                           , UnsignedPercent
                           , VibratoSpeedParameterChanged
                           , dispatcher->vibratoSpeedParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             TremoloAmount
                           , UnsignedPercent
                           , TremoloAmountParameterChanged
                           , dispatcher->tremoloAmountParameterChangedListeners );
    PROCESS_VOICE_PARAMETER (
                             TremoloSpeed
                           , UnsignedPercent
                           , TremoloSpeedParameterChanged
                           , dispatcher->tremoloSpeedParameterChangedListeners );
}
