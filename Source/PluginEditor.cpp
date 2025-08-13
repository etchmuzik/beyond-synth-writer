// SPDX-License-Identifier: MIT
//
// Implementation of the editor for the Beyond Synth Writer plugin. The
// editor provides a simple interface with a title text. In future
// iterations this class will host components such as text input for
// prompts, buttons to generate instruments, ADSR sliders, and a
// spectrograph display.

#include "PluginEditor.h"

BeyondSynthWriterAudioProcessorEditor::BeyondSynthWriterAudioProcessorEditor(BeyondSynthWriterAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    // Set the size of the plugin window. This can be adjusted when more
    // controls are added to the interface.
    setSize(400, 300);
}

BeyondSynthWriterAudioProcessorEditor::~BeyondSynthWriterAudioProcessorEditor() = default;

void BeyondSynthWriterAudioProcessorEditor::paint(juce::Graphics& g)
{
    // Fill the background with a dark colour.
    g.fillAll(juce::Colours::black);

    // Set the font and colour for drawing the title text.
    g.setColour(juce::Colours::white);
    g.setFont(18.0f);
    g.drawFittedText("Beyond Synth Writer", getLocalBounds(), juce::Justification::centred, 1);
}

void BeyondSynthWriterAudioProcessorEditor::resized()
{
    // This is where you would position any child components.
}