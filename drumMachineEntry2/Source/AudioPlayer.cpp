/*
  ==============================================================================

    AudioPlayer.cpp
    Created: 14 Sep 2023 8:32:09pm
    Author:  Jake

  ==============================================================================
*/

#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
    formatManager.registerBasicFormats();
}

AudioPlayer::~AudioPlayer()
{
    
}

bool AudioPlayer::loadURL(const juce::URL &url)
{
    auto * reader = formatManager.createReaderFor(url.getLocalFile());
    
    if(reader){
                std::unique_ptr <juce::AudioFormatReaderSource > newSource(new juce::AudioFormatReaderSource(reader , true));
    
        transportSource.setSource(newSource.get(), 0, nullptr , reader ->sampleRate);
        
        readerSource.reset(newSource.release());
        
            return true;
                }
    
    return false;
}

void AudioPlayer::prepareToPlay(int samplesPerBlockExpected , double sampleRate)
{
    transportSource.prepareToPlay(samplesPerBlockExpected,sampleRate);
}

void AudioPlayer::getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill)
{
    if(!readerSource.get())
    {
    bufferToFill.clearActiveBufferRegion();
    return;
    }
    transportSource.getNextAudioBlock(bufferToFill);
}

void AudioPlayer::releaseResources()
{
    transportSource.releaseResources();
}

void AudioPlayer::play()
{
    transportSource.start();
}

void AudioPlayer::stop()
{
    transportSource.stop();
}

void AudioPlayer::setStartPosition(double posInsecs)
{
    if(posInsecs < 0 || posInsecs > transportSource.getLengthInSeconds())
    {
        DBG("Warning: Seconds over or under the length of the sample");
        return;
    }
    transportSource.setPosition(posInsecs);
    
    startPos = posInsecs;
}

double AudioPlayer::getStartPosition()
{
    return startPos;
}

void AudioPlayer::setPositionRelative(double pos)
{
    auto posInSecs = pos * transportSource.getLengthInSeconds();
    setStartPosition(posInSecs);
}

void AudioPlayer::setGain(double gain)
{
    transportSource.setGain(gain);
}
