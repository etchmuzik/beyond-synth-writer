// SPDX-License-Identifier: MIT
//
// This header declares the editor component for the Beyond Synth Writer
// plugin. The editor is responsible for drawing the plugin's user
// interface and providing controls for parameters. For now the editor
// displays only a simple title, but it can be extended with text boxes,
// sliders, and visualisations as the project progresses.

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class BeyondSynthWriterAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit BeyondSynthWriterAudioProcessorEditor(BeyondSynthWriterAudioProcessor&);
    ~BeyondSynthWriterAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    BeyondSynthWriterAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BeyondSynthWriterAudioProcessorEditor)
};