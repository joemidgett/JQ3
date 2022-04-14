/*
  ==============================================================================
    This file contains the basic framework code for a JUCE plugin editor.
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/RotarySliderWithLabels.h"
#include "GUI/PowerButton.h"
#include "GUI/AnalyzerButton.h"
#include "GUI/LookAndFeel.h"
#include "GUI/ResponseCurveComponent.h"

class JQ3AudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    JQ3AudioProcessorEditor(JQ3AudioProcessor&);
    ~JQ3AudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JQ3AudioProcessor& audioProcessor;

    RotarySliderWithLabels peakFreqSlider,
        peakGainSlider,
        peakQualitySlider,
        lowCutFreqSlider,
        highCutFreqSlider,
        lowCutSlopeSlider,
        highCutSlopeSlider;

    ResponseCurveComponent responseCurveComponent;

    using APVTS = juce::AudioProcessorValueTreeState;
    using Attachment = APVTS::SliderAttachment;

    Attachment peakFreqSliderAttachment,
        peakGainSliderAttachment,
        peakQualitySliderAttachment,
        lowCutFreqSliderAttachment,
        highCutFreqSliderAttachment,
        lowCutSlopeSliderAttachment,
        highCutSlopeSliderAttachment;

    PowerButton lowcutBypassButton, peakBypassButton, highcutBypassButton; 
    AnalyzerButton analyzerEnabledButton;

    using ButtonAttachment = APVTS::ButtonAttachment;
    ButtonAttachment lowcutBypassButtonAttachment, 
        peakBypassButtonAttachment, 
        highcutBypassButtonAttachment, 
        analyzerEnabledButtonAttachment;

    std::vector<juce::Component*> getComps();

    LookAndFeel lnf;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(JQ3AudioProcessorEditor)
};