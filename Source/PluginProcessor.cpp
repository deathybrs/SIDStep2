#include "PluginProcessor.h"

#include "Defines.h"
#include "MIDIProcessor.h"
#include "ParameterProcessor.h"
#include "PluginEditor.h"
#include "SIDStep2.h"
#include "UI/LiveMode.h"
#include "UI/PatchEditor.h"

#include "Parameters/BooleanParameter.h"
#include "Parameters/SignedPercentParameter.h"
#include "Parameters/UnsignedIntParameter.h"
#include "Parameters/UnsignedPercentParameter.h"
//#include "UI/ExportManager.h"

Sidstep2AudioProcessor::Sidstep2AudioProcessor ()
{
    dispatcher = std::make_shared < EventDispatcher > ();

    //exportManager = std::make_shared < ExportManager > ();
    patchEditor = std::make_shared < PatchEditor > (
                                                    dispatcher );
    liveMode = std::make_shared < LiveMode > (
                                              dispatcher );
    core = std::make_shared < SidStep2 > (
                                          dispatcher );
    midiProcessor = std::make_shared < MidiProcessor > (
                                                        dispatcher );
    parameterProcessor = std::make_shared < ParameterProcessor > (
                                                                  dispatcher );
    for ( auto v = 0 ; v < 3 ; v++ )
    {
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("Program " + String(v + 1), 0, 255)
                              , Program );
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("Attack " + String(v + 1), 0, 15)
                              , Attack );
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("Decay " + String(v + 1), 0, 15)
                              , Decay );
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("Sustain " + String(v + 1), 15, 15)
                              , Sustain );
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("Release " + String(v + 1), 0, 15)
                              , Release );
        CREATE_VOICE_PARAMETER (
                                SignedPercent
                              , ("Pulse Width " + String(v + 1), 0.0F, 4096)
                              , PulseWidth );
        CREATE_VOICE_PARAMETER (
                                Boolean
                              , ("Filter " + String(v + 1), false)
                              , FilterVoice );
        CREATE_VOICE_PARAMETER (
                                SignedPercent
                              , ("Pitch Bend " + String(v + 1), 0.0F, 16384)
                              , PitchBend );
        CREATE_VOICE_PARAMETER (
                                UnsignedPercent
                              , ("Vibrato " + String(v + 1), 0.0F, 16384)
                              , VibratoAmount );
        CREATE_VOICE_PARAMETER (
                                UnsignedPercent
                              , ("V.Speed " + String(v + 1), 1.0F, 100)
                              , VibratoSpeed );
        CREATE_VOICE_PARAMETER (
                                UnsignedInt
                              , ("V.Delay " + String(v + 1), 0, 15)
                              , VibratoDelay );
    }
    CREATE_PARAMETER (
                      UnsignedInt
                    , ("Cutoff", 0, 2047)
                    , Cutoff );
    CREATE_PARAMETER (
                      UnsignedInt
                    , ("Resonance", 0, 15)
                    , Resonance );
    CREATE_PARAMETER (
                      Boolean
                    , ("Low Pass", false)
                    , LowPass );
    CREATE_PARAMETER (
                      Boolean
                    , ("Band Pass", false)
                    , BandPass );
    CREATE_PARAMETER (
                      Boolean
                    , ("High Pass", false)
                    , HighPass );
    CREATE_PARAMETER (
                      UnsignedInt
                    , ("Volume", 15, 15)
                    , Volume );

    // ReSharper disable once CppDeclaratorNeverUsed
    const auto load = properties -> GetPatches ();  // NOLINT(clang-diagnostic-unused-variable)
}

Sidstep2AudioProcessor::~Sidstep2AudioProcessor ()
{
    core          = nullptr;
    liveMode      = nullptr;
    patchEditor   = nullptr;
    midiProcessor = nullptr;
    //exportManager = nullptr;
}


// ReSharper disable once CppConstValueFunctionReturnType
auto  // NOLINT(readability-const-return-type)
    Sidstep2AudioProcessor::getName () const -> const String { return JucePlugin_Name; }

auto
    Sidstep2AudioProcessor::acceptsMidi () const -> bool
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

auto
    Sidstep2AudioProcessor::producesMidi () const -> bool
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

auto
    Sidstep2AudioProcessor::getTailLengthSeconds () const -> double { return 0.0; }

auto
    Sidstep2AudioProcessor::getNumPrograms () -> int
{
    return 128;
}

auto
    Sidstep2AudioProcessor::getCurrentProgram () -> int { return 0; }

void
    Sidstep2AudioProcessor::setCurrentProgram (
            int index
            ) {}

// ReSharper disable once CppConstValueFunctionReturnType
auto  // NOLINT(readability-const-return-type)
    Sidstep2AudioProcessor::getProgramName (
            int index
            ) -> const String { return String (); }

void
    Sidstep2AudioProcessor::changeProgramName (
            int index
          , const String& new_name
            ) {}


void
    Sidstep2AudioProcessor::prepareToPlay (
            const double sample_rate
          , int samples_per_block
            )
{
    dispatcher -> sampleRateChangedListeners -> call (
                                                      &SampleRateChanged::onSampleRateChanged
                                                    , sample_rate );
}

void
    Sidstep2AudioProcessor::releaseResources () {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Sidstep2AudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    const int numChannels = preferredSet.size();

#if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
#elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
#else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
#endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void
    Sidstep2AudioProcessor::processBlock (
            AudioSampleBuffer& buffer
          , MidiBuffer&        midi_messages
            )
{
    AudioPlayHead::CurrentPositionInfo position_info {};
    if ( !playHead -> getCurrentPosition (
                                          position_info ) )
    {
        NativeMessageBox::showMessageBox (
                                          AlertWindow::AlertIconType::WarningIcon
                                        , "Fucking Shit"
                                        , "Your DAW is a piece of shit, go get a better one." );
    }
    core -> Generate (
                      midi_messages
                    , buffer
                    , position_info );
}


auto
    Sidstep2AudioProcessor::hasEditor () const -> bool
{
    return true; 
}

auto
    Sidstep2AudioProcessor::createEditor () -> AudioProcessorEditor*
{
    auto ed = new Sidstep2AudioProcessorEditor (
                                                *this );
    ed -> addAndMakeVisible (
                             *liveMode );
    ed -> addChildComponent (
                             *patchEditor );
    //ed -> addChildComponent (
    //                         *exportManager );
    return ed;
}


void
    Sidstep2AudioProcessor::getStateInformation (
            MemoryBlock& dest_data
            )
{
    core -> GetStateInformation (
                                 dest_data );
}

void
    Sidstep2AudioProcessor::setStateInformation (
            const void* data
          , const int   size_in_bytes
            )
{
    core -> SetStateInformation (
                                 data
                               , size_in_bytes );
}

auto
    Sidstep2AudioProcessor::GetCore () const -> std::shared_ptr < SidStep2 > { return core; }


// ReSharper disable once CppInconsistentNaming
auto JUCE_CALLTYPE createPluginFilter () -> AudioProcessor* { return new Sidstep2AudioProcessor (); }
