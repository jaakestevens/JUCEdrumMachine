/*
  ==============================================================================

    DeckGUI2.h
    Created: 6 Mar 2023 8:52:14pm
    Author:  Jake

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MyLook&Feel.h"

using namespace juce;

//==============================================================================
/*
*/
class SequencerGUI  : public Component, public Button::Listener, public Slider::Listener, public Timer
{
public:
    SequencerGUI();
    ~SequencerGUI() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(Button * button) override;
    void sliderValueChanged(Slider * slider) override;
    void timerCallback() override;
    //drag and drop

    void paintOverChildren(juce::Graphics& g) override;

private:
    
    int currentStep = 0;
    
    int timerHz; //timer interval
    juce::TextButton startSequence;
    
    juce::TextButton stepLight1;
    juce::TextButton stepLight2;
    juce::TextButton stepLight3;
    juce::TextButton stepLight4;
    juce::TextButton stepLight5;
    juce::TextButton stepLight6;
    juce::TextButton stepLight7;
    juce::TextButton stepLight8;
    juce::TextButton stepLight9;
    juce::TextButton stepLight10;
    juce::TextButton stepLight11;
    juce::TextButton stepLight12;
    juce::TextButton stepLight13;
    juce::TextButton stepLight14;
    juce::TextButton stepLight15;
    juce::TextButton stepLight16;
    
    juce::TextButton step1;
    juce::TextButton step2;
    juce::TextButton step3;
    juce::TextButton step4;
    juce::TextButton step5;
    juce::TextButton step6;
    juce::TextButton step7;
    juce::TextButton step8;
    juce::TextButton step9;
    juce::TextButton step10;
    juce::TextButton step11;
    juce::TextButton step12;
    juce::TextButton step13;
    juce::TextButton step14;
    juce::TextButton step15;
    juce::TextButton step16;
    
    bool active;
    
    std::vector<int>kickSelect;
    
    MyLookAndFeel myLookAndFeel; //placed before to avoid the jassert error
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SequencerGUI)
};

