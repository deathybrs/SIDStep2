#pragma once


#include <JuceHeader.h>

#include "Listeners/ListenerInitializer.h"


class SidStep2;
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
        GetCore () const -> ReferenceCountedObjectPtr < SidStep2 >;

private:
    ScopedPointer < ListenerInitializer >                        listeners;
    ReferenceCountedObjectPtr < SidStep2 >                       core;
    ScopedPointer < LiveMode >                                   liveMode;
    ScopedPointer < PatchEditor >                                patchEditor;
    ScopedPointer < ParameterProcessor >                         parameterProcessor;
    ReferenceCountedObjectPtr < MidiProcessor >                  midiProcessor;
    SharedResourcePointer < ListenerList < SampleRateChanged > > sampleRateChangedListeners;
    SharedResourcePointer < SharedProperties >                   properties;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  Sidstep2AudioProcessor )
};
