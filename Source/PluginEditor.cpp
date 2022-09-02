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
    preDelaySlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    preDelaySlider.setRange (0.0f, 200.0f);
    addAndMakeVisible (preDelaySlider);
    
    preDelaySlider.onValueChange = [this]
    {
        audioProcessor.preDelayValue = preDelaySlider.getValue();
    };
    
    decayTimeSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    decayTimeSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    decayTimeSlider.setRange (0.0f, 0.95f);
    addAndMakeVisible (decayTimeSlider);
    
    decayTimeSlider.onValueChange = [this]
    {
        audioProcessor.decayTimeValue = decayTimeSlider.getValue();
    };
    
    dryWetSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    dryWetSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, true, 60, 20);
    dryWetSlider.setRange (0.0f, 0.95f);
    addAndMakeVisible (dryWetSlider);
    
    dryWetSlider.onValueChange = [this]
    {
        audioProcessor.dryWetValue = dryWetSlider.getValue();
    };
    
    setSize (400, 300);
}

ReverbAudioProcessorEditor::~ReverbAudioProcessorEditor() {}

void ReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    
}

void ReverbAudioProcessorEditor::resized()
{
    preDelaySlider.setBoundsRelative (0.0f, 0.0f, 0.3f, 0.3f);
    decayTimeSlider.setBoundsRelative (0.3f, 0.0f, 0.3f, 0.3f);
    dryWetSlider.setBoundsRelative (0.6f, 0.0f, 0.3f, 0.3f);
}
