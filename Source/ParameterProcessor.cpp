#include "ParameterProcessor.h"


#include "SIDRegisters.h"


ParameterProcessor::ParameterProcessor ()
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
    SharedResourcePointer < ListenerList < LivePulseWidthChanged > > () -> add (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveAttackChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LiveDecayChanged > > () -> add (
                                                                           this );
    SharedResourcePointer < ListenerList < LiveSustainChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveReleaseChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> add (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveCutoffChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LiveResonanceChanged > > () -> add (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveLowPassChanged > > () -> add (
                                                                             this );
    SharedResourcePointer < ListenerList < LiveBandPassChanged > > () -> add (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveHighPassChanged > > () -> add (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < LivePitchBendChanged > > () -> add (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveTremoloAmountChanged > > () -> add (
                                                                                   this );
    SharedResourcePointer < ListenerList < LiveTremoloSpeedChanged > > () -> add (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> add (
                                                                            this );
    SharedResourcePointer < ListenerList < Frame > > () -> add (
                                                                this );
}

ParameterProcessor::~ParameterProcessor ()
{
    SharedResourcePointer < ListenerList < Frame > > () -> remove (
                                                                   this );
    SharedResourcePointer < ListenerList < LivePulseWidthChanged > > () -> remove (
                                                                                   this );
    SharedResourcePointer < ListenerList < LiveAttackChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveDecayChanged > > () -> remove (
                                                                              this );
    SharedResourcePointer < ListenerList < LiveSustainChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveReleaseChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveVoiceFilterChanged > > () -> remove (
                                                                                    this );
    SharedResourcePointer < ListenerList < LiveCutoffChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LiveResonanceChanged > > () -> remove (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveLowPassChanged > > () -> remove (
                                                                                this );
    SharedResourcePointer < ListenerList < LiveBandPassChanged > > () -> remove (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveHighPassChanged > > () -> remove (
                                                                                 this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> remove (
                                                                               this );
    SharedResourcePointer < ListenerList < LivePitchBendChanged > > () -> remove (
                                                                                  this );
    SharedResourcePointer < ListenerList < LiveVibratoAmountChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < LiveVibratoDelayChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < LiveVibratoSpeedChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < LiveTremoloAmountChanged > > () -> remove (
                                                                                      this );
    SharedResourcePointer < ListenerList < LiveTremoloSpeedChanged > > () -> remove (
                                                                                     this );
    SharedResourcePointer < ListenerList < LiveVolumeChanged > > () -> remove (
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
                     , CutoffParameterChanged );
    PROCESS_PARAMETER (
                       Resonance
                     , UnsignedInt
                     , ResonanceParameterChanged );
    PROCESS_PARAMETER (
                       LowPass
                     , Boolean
                     , LowPassParameterChanged );
    PROCESS_PARAMETER (
                       BandPass
                     , Boolean
                     , BandPassParameterChanged );
    PROCESS_PARAMETER (
                       HighPass
                     , Boolean
                     , HighPassParameterChanged );
    PROCESS_PARAMETER (
                       Volume
                     , UnsignedInt
                     , VolumeParameterChanged );
}

void
    ParameterProcessor::ProcessVoiceParameters (
            const int v
            ) const
{
    PROCESS_VOICE_PARAMETER (
                             Program
                           , UnsignedInt
                           , ProgramParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             PulseWidth
                           , SignedPercent
                           , PulseWidthParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             Attack
                           , UnsignedInt
                           , AttackParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             Decay
                           , UnsignedInt
                           , DecayParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             Sustain
                           , UnsignedInt
                           , SustainParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             Release
                           , UnsignedInt
                           , ReleaseParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             FilterVoice
                           , Boolean
                           , FilterVoiceParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             PitchBend
                           , SignedPercent
                           , PitchBendParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             VibratoAmount
                           , UnsignedPercent
                           , VibratoAmountParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             VibratoDelay
                           , UnsignedInt
                           , VibratoDelayParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             VibratoSpeed
                           , UnsignedPercent
                           , VibratoSpeedParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             TremoloAmount
                           , UnsignedPercent
                           , TremoloAmountParameterChanged );
    PROCESS_VOICE_PARAMETER (
                             TremoloSpeed
                           , UnsignedPercent
                           , TremoloSpeedParameterChanged );
}
