// SPDX-License-Identifier: MIT
//
// This file defines the core audio processor class for the Beyond Synth Writer
// plugin. The processor is responsible for managing the audio and MIDI
// workflow, including preparing resources, processing audio blocks and
// exposing parameters. At present the processor does nothing except
// pass audio through unchanged. The class is designed to be extended with
// synthesis capabilities controlled by text prompts.

#pragma once

#include <JuceHeader.h>

class BeyondSynthWriterAudioProcessor : public juce::AudioProcessor
{
public:
    BeyondSynthWriterAudioProcessor();
    ~BeyondSynthWriterAudioProcessor() override;

    //==============================================================================
    const juce::String getName() const override;
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    // This method creates our editor component. See PluginEditor.h
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    //==============================================================================
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

    // We expose our parameter tree so that editors and controllers can attach
    // components to the parameters. The layout currently has no parameters,
    // but can be extended using the createParameterLayout() helper.
    juce::AudioProcessorValueTreeState parameters;

private:
    // Helper method to define the parameter layout. Extend this method with
    // additional parameters (e.g. ADSR envelopes, filter cutoff) as the
    // synthesis engine evolves.
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BeyondSynthWriterAudioProcessor)
};
