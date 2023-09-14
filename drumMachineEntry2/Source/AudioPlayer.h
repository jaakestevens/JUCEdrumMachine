/*
  ==============================================================================

    AudioPlayer.h
    Created: 14 Sep 2023 8:32:09pm
    Author:  Jake

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class AudioPlayer : public juce::AudioSource{
    public:
    AudioPlayer();
    ~AudioPlayer();
    
    void prepareToPlay(int samplesPerBlockExpected , double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    
    bool loadURL(const juce::URL& url);
    void play();
    void stop();
    void setStartPosition(double posInsecs);
    double getStartPosition();
    void setPositionRelative(double pos);
    void setGain(double gain);
    
private:
    
    juce::AudioFormatManager formatManager; //manages formats of sound files(mp4, wav....)
    
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;//reads from buffer
    
    juce::AudioTransportSource transportSource; //transports sound to speaker (dac)
    
    double startPos = 0;
    
    double endPos;
    
};
