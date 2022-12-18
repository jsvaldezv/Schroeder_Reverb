/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ReverbAudioProcessorEditor::ReverbAudioProcessorEditor (ReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    preDelaySlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    preDelaySlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 60, 20);
    preDelaySlider.setRange (0.0f, 200.0f);
    addAndMakeVisible (preDelaySlider);
    
    preDelayLabel.setText ("Pre Delay", juce::dontSendNotification);
    preDelayLabel.setJustificationType (juce::Justification::centred);
    preDelayLabel.attachToComponent (&preDelaySlider, false);
    
    preDelaySlider.onValueChange = [this]
    {
        audioProcessor.preDelayValue = preDelaySlider.getValue();
    };
    
    decayTimeSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    decayTimeSlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 60, 20);
    decayTimeSlider.setRange (0.0f, 0.95f);
    addAndMakeVisible (decayTimeSlider);
    
    decayLabel.setText ("Decay Time", juce::dontSendNotification);
    decayLabel.setJustificationType (juce::Justification::centred);
    decayLabel.attachToComponent (&decayTimeSlider, false);
    
    decayTimeSlider.onValueChange = [this]
    {
        audioProcessor.decayTimeValue = decayTimeSlider.getValue();
    };
    
    dryWetSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dryWetSlider.setTextBoxStyle (juce::Slider::NoTextBox, true, 60, 20);
    dryWetSlider.setRange (0.0f, 0.95f);
    addAndMakeVisible (dryWetSlider);
    
    dryWetLabel.setText ("DryWet", juce::dontSendNotification);
    dryWetLabel.setJustificationType (juce::Justification::centred);
    dryWetLabel.attachToComponent (&dryWetSlider, false);
    
    dryWetSlider.onValueChange = [this]
    {
        audioProcessor.dryWetValue = dryWetSlider.getValue();
    };
    
    setSize (400, 300);
}

ReverbAudioProcessorEditor::~ReverbAudioProcessorEditor() {}

void ReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll   (juce::Colours::rebeccapurple);
    g.setColour (juce::Colours::white);
    g.drawText  ("Schroeder Reverb", 0, 0, getWidth(), getHeight() * 0.1f, juce::Justification::centred);
}

void ReverbAudioProcessorEditor::resized()
{
    preDelaySlider.setBoundsRelative    (0.5f + 0.05f, 0.23f, 0.3f, 0.3f);
    decayTimeSlider.setBoundsRelative   (0.5f - 0.35f, 0.23f, 0.3f, 0.3f);
    dryWetSlider.setBoundsRelative      (0.5f - 0.15f, 0.63f, 0.3f, 0.3f);
}
