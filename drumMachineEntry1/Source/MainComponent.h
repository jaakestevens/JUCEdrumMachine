#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent, public juce::Button::Listener, public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    
    void buttonClicked(juce::Button *button) override;
    void sliderValueChanged(juce::Slider *slider) override;

private:
    //==============================================================================
    // Your private member variables go here...
    
    juce::TextButton playButton;
    juce::TextButton stopButton;
    juce::TextButton loadButton;
    juce::Slider gainSlider;
    
    juce::Random random;

    bool playing = false;
    
    double gain = 0.5;
    
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource; //reads file
    
    juce::AudioFormatManager formatManager; //manages formats of sound files
    
    juce::AudioTransportSource transportSource; //transports the source to the speakers
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    
    bool loadURL(const juce::URL& audioURL);
};
