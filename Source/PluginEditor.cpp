#include "PluginProcessor.h"


#include "PluginEditor.h"


Sidstep2AudioProcessorEditor::Sidstep2AudioProcessorEditor (
        Sidstep2AudioProcessor& processor
        )
    :
    AudioProcessorEditor (
                          &processor )
  , processor (
               processor )
{
    setSize (
             EDITOR_WIDTH
           , EDITOR_HEIGHT );
}

void
    Sidstep2AudioProcessorEditor::paint (
            Graphics& g
            ) {}

void
    Sidstep2AudioProcessorEditor::resized () {}
