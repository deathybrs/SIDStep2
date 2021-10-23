#pragma once


#include <JuceHeader.h>


#include "PluginProcessor.h"


class LiveMode;

class Sidstep2AudioProcessorEditor final : public AudioProcessorEditor
{
public:
    explicit
        Sidstep2AudioProcessorEditor (
                Sidstep2AudioProcessor& processor
                );

    Sidstep2AudioProcessorEditor (
            Sidstep2AudioProcessorEditor&& other
            ) = delete;

    ~Sidstep2AudioProcessorEditor () override = default;

    auto
        operator= (
                Sidstep2AudioProcessorEditor&& other
                ) -> Sidstep2AudioProcessorEditor& = delete;

    void
        paint (
                Graphics& g
                ) override;

    void
        resized () override;

private:
    static const int EDITOR_WIDTH  = 1024;
    static const int EDITOR_HEIGHT = 576;

    Sidstep2AudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (
                                                  Sidstep2AudioProcessorEditor )
};
