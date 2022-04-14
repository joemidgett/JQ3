// ResponseCurveComponent.h

#pragma once

#include <JuceHeader.h>
#include "../DSP/ChainSettings.h"
#include "../DSP/PathProducer.h"

struct ResponseCurveComponent : juce::Component,
    juce::AudioProcessorParameter::Listener,
    juce::Timer
{
    ResponseCurveComponent(JQ3AudioProcessor&);
    ~ResponseCurveComponent();

    void parameterValueChanged(int parameterIndex, float newValue) override;

    void parameterGestureChanged(int parameterIndex, bool gestureIsStarting) override { }

    void timerCallback() override;

    void paint(juce::Graphics& g) override;

    void resized() override;

    void toggleAnalysisEnablement(bool enabled)
    {
        shouldShowFFTAnalysis = enabled;
    }

private:
    JQ3AudioProcessor& audioProcessor;
    juce::Atomic<bool> parametersChanged { false };

    MonoChain monoChain;

    void updateChain();

    juce::Image background;

    juce::Rectangle<int> getRenderArea();

    juce::Rectangle<int> getAnalysisArea();

    PathProducer leftPathProducer, rightPathProducer;

    bool shouldShowFFTAnalysis = true;
};