// PathProducer.h

#pragma once

#include <JuceHeader.h>
#include "FFTDataGenerator.h"
#include "../GUI/AnalyzerPathGenerator.h"
#include "SingleChannelSampleFifo.h"
#include "../PluginProcessor.h"

struct PathProducer
{
    PathProducer(SingleChannelSampleFifo<JQ3AudioProcessor::BlockType>& scsf) :
        leftChannelFifo(&scsf)
    {
        leftChannelFFTDataGenerator.changeOrder(FFTOrder::order2048);
        monoBuffer.setSize(1, leftChannelFFTDataGenerator.getFFTSize());
    }

    void process(juce::Rectangle<float> fftBounds, double sampleRate);
    juce::Path getPath() { return leftChannelFFTPath; }

private:
    SingleChannelSampleFifo<JQ3AudioProcessor::BlockType>* leftChannelFifo;

    juce::AudioBuffer<float> monoBuffer;

    FFTDataGenerator<std::vector<float>> leftChannelFFTDataGenerator;

    AnalyzerPathGenerator<juce::Path> pathProducer;

    juce::Path leftChannelFFTPath;
};