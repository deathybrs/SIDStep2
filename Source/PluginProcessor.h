
#pragma once
#include <JuceHeader.h>
#include "Listeners/ListenerInitializer.h"
class SidStep2;
class ExportManager;
class LiveMode;
class PatchEditor;
class ParameterProcessor;
// ReSharper disable once CppInconsistentNaming
class MidiProcessor;
class SharedProperties;

class Sidstep2AudioProcessor final : public AudioProcessor
{
public:
    Sidstep2AudioProcessor ();

    Sidstep2AudioProcessor (
            Sidstep2AudioProcessor&& other
            ) = delete;

    ~Sidstep2AudioProcessor () override;

    auto
        operator= (
                Sidstep2AudioProcessor&& other
                ) -> Sidstep2AudioProcessor& = delete;

    void
        prepareToPlay (
                double sample_rate
              , int    samples_per_block
                ) override;

    void
        releaseResources () override;
#ifndef JucePlugin_PreferredChannelConfigurations
    bool setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet) override;
#endif
    void
        processBlock (
                AudioSampleBuffer& buffer
              , MidiBuffer&        midi_messages
                ) override;

    auto
        createEditor () -> AudioProcessorEditor* override;

    auto
        hasEditor () const -> bool override;

    auto
        getName () const -> const String override;

    auto
        acceptsMidi () const -> bool override;

    auto
        producesMidi () const -> bool override;

    auto
        getTailLengthSeconds () const -> double override;

    auto
        getNumPrograms () -> int override;

    auto
        getCurrentProgram () -> int override;

    void
        setCurrentProgram (
                int index
                ) override;

    auto
        getProgramName (
                int index
                ) -> const String override;

    void
        changeProgramName (
                int           index
              , const String& new_name
                ) override;

    void
        getStateInformation (
                MemoryBlock& dest_data
                ) override;

    void
        setStateInformation (
                const void* data
              , int         size_in_bytes
                ) override;

    auto
        GetCore () const -> std::shared_ptr < SidStep2 >;

private:
    // Keeping this as a shared resource pointer because it is static during
    // runtime, so all instances can refer to the same property set.
    SharedResourcePointer < SharedProperties > properties;
    std::shared_ptr < EventDispatcher >        dispatcher;
    std::shared_ptr < SidStep2 >               core;
    std::shared_ptr < LiveMode >               liveMode;
    std::shared_ptr < PatchEditor >            patchEditor;
    std::shared_ptr < ParameterProcessor >     parameterProcessor;
    std::shared_ptr < MidiProcessor >          midiProcessor;

    //std::shared_ptr < ExportManager >          exportManager;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  Sidstep2AudioProcessor )
};
