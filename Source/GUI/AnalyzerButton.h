// AnalyzerButton.h

#pragma once

struct AnalyzerButton : juce::ToggleButton 
{ 
    void resized() override
    {
        auto bounds = getLocalBounds();
        auto insetRect = bounds.reduced(4);

        randomPath.clear();

        juce::Random r;

        randomPath.startNewSubPath(insetRect.getX(), insetRect.getY() + insetRect.getHeight() * r.nextFloat());

        for (auto x = insetRect.getX() + 1; x < insetRect.getRight(); x += 2)
        {
            // Should pre-cache Y value, but can do that later
            randomPath.lineTo(x, insetRect.getY() + insetRect.getHeight() * r.nextFloat());
        }
    }

    juce::Path randomPath;
};