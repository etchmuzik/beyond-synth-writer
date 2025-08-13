// SPDX-License-Identifier: MIT
//
// The implementation of the Beyond Synth Writer audio processor. This class
// currently implements a simple pass-through of audio and MIDI. It sets up
// an empty parameter tree that can be extended in the future with controls
// for synthesis parameters such as ADSR envelopes, filter cutoff, and more.

#include "PluginProcessor.h"
#include "PluginEditor.h"

BeyondSynthWriterAudioProcessor::BeyondSynthWriterAudioProcessor()
    : AudioProcessor(BusesProperties()
                     .withInput("Input", juce::AudioChannelSet::stereo(), true)
                     .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, nullptr, juce::Identifier("Params"), createParameterLayout())
{
}

BeyondSynthWriterAudioProcessor::~BeyondSynthWriterAudioProcessor() = default;

//==============================================================================
const juce::String BeyondSynthWriterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BeyondSynthWriterAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    // Accept only stereo input and output. If you need to support mono
    // configurations or other channel layouts, customise this logic.
    if (layouts.getMainInputChannelSet() != juce::AudioChannelSet::stereo()
        || layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
    return true;
}

void BeyondSynthWriterAudioProcessor::prepareToPlay(double /*sampleRate*/, int /*samplesPerBlock*/)
{
    // This method will be called before the processor starts playing. Use it
    // to allocate resources such as buffers or reset state. Currently we
    // don't need to initialise anything.
}

void BeyondSynthWriterAudioProcessor::releaseResources()
{
    // Use this method to free any resources you allocated in prepareToPlay().
}

void BeyondSynthWriterAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& /*midiMessages*/)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // For any channels beyond the input channel count, clear them to avoid
    // passing uninitialised data to the host.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // Pass-through: copy input to output. If you implement your own synth,
    // this is where you'd generate audio and mix it with incoming audio/MIDI.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        // Nothing to do; the buffer already contains the input data.
        juce::ignoreUnused(channelData);
    }
}

juce::AudioProcessorEditor* BeyondSynthWriterAudioProcessor::createEditor()
{
    return new BeyondSynthWriterAudioProcessorEditor(*this);
}

juce::AudioProcessorValueTreeState::ParameterLayout BeyondSynthWriterAudioProcessor::createParameterLayout()
{
    // At present, no parameters are defined. Add parameters here by
    // constructing unique_ptr<juce::RangedAudioParameter> objects and
    // adding them to the layout vector. For example:
    // auto attack = std::make_unique<juce::AudioParameterFloat>("attack", "Attack", 0.0f, 5.0f, 0.1f);
    // params.push_back(std::move(attack));
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    return { params.begin(), params.end() };
}
