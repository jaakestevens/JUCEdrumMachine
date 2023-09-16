#pragma once

#include <JuceHeader.h> //searches first in the system paths
#include "DjAudioPlayer.h" //quotation include looks for local files (in the same file as the source)
#include "DeckGUI2.h"
#include "SequencerGUI.h"

using namespace juce;

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public AudioAppComponent, public Timer
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;
    void sliderValueChanged(Slider * slider);
    void timerCallback()override;
    
    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...
    AudioFormatManager formatManager;
    AudioThumbnailCache thumbCache{20}; //we need to tell it how large the cache is
    
    bool isPlaying;
    bool looping;
        
    DJAudioPlayer player1{formatManager};
    DJAudioPlayer player2{formatManager};
    DJAudioPlayer player3{formatManager};
    DJAudioPlayer player4{formatManager};
    DJAudioPlayer player5{formatManager};
    DJAudioPlayer player6{formatManager};
    DJAudioPlayer player7{formatManager};
    DJAudioPlayer player8{formatManager};
    
    DeckGUI2 deck1{player1, formatManager, thumbCache}; //feeding objects into the gui constructor
    DeckGUI2 deck2{player2, formatManager, thumbCache}; //My own GUI
    DeckGUI2 deck3{player3, formatManager, thumbCache};
    DeckGUI2 deck4{player4, formatManager, thumbCache};
    DeckGUI2 deck5{player5, formatManager, thumbCache};
    DeckGUI2 deck6{player6, formatManager, thumbCache};
    DeckGUI2 deck7{player7, formatManager, thumbCache};
    DeckGUI2 deck8{player8, formatManager, thumbCache};
    
    int currentStep;
    
    SequencerGUI sequencer;
    
//    juce::TextButton startSequence;
//
//    juce::TextButton stepLight1;
//    juce::TextButton stepLight2;
//    juce::TextButton stepLight3;
//    juce::TextButton stepLight4;
//    juce::TextButton stepLight5;
//    juce::TextButton stepLight6;
//    juce::TextButton stepLight7;
//    juce::TextButton stepLight8;
//    juce::TextButton stepLight9;
//    juce::TextButton stepLight10;
//    juce::TextButton stepLight11;
//    juce::TextButton stepLight12;
//    juce::TextButton stepLight13;
//    juce::TextButton stepLight14;
//    juce::TextButton stepLight15;
//    juce::TextButton stepLight16;
//
//    juce::TextButton step1;
//    juce::TextButton step2;
//    juce::TextButton step3;
//    juce::TextButton step4;
//    juce::TextButton step5;
//    juce::TextButton step6;
//    juce::TextButton step7;
//    juce::TextButton step8;
//    juce::TextButton step9;
//    juce::TextButton step10;
//    juce::TextButton step11;
//    juce::TextButton step12;
//    juce::TextButton step13;
//    juce::TextButton step14;
//    juce::TextButton step15;
//    juce::TextButton step16;
    
    MixerAudioSource mixerSource;

    MyLookAndFeel myLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    };

