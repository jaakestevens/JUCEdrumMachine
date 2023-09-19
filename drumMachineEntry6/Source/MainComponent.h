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
class MainComponent  : public AudioAppComponent, public Timer, public Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void buttonClicked(Button * button) override;
    void releaseResources() override;
    void sliderValueChanged(Slider * slider);
    void timerCallback()override;
    
    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    void clearLights();
    void checkSequence();
    void printVector();
    void newButton(int i);
    void addStep(Button *button, int step);
    
    void clearBanks();
    void addBank(Button *button, int bank);
    
    int BankSelected;
    
    std::vector<int>kickSelect;
    std::vector<int>snareSelect;
    std::vector<int>hat1Select;
    std::vector<int>hat2Select;
    
    
    std::vector<std::vector<int>> stepList
    {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, //banks
        {0,0,0,0,0,0,0,0} //steps
    };

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
    
    DeckGUI2 deck1{player1, formatManager, thumbCache, 1}; //feeding objects into the gui constructor
    DeckGUI2 deck2{player2, formatManager, thumbCache, 2}; //My own GUI
    DeckGUI2 deck3{player3, formatManager, thumbCache, 3};
    DeckGUI2 deck4{player4, formatManager, thumbCache, 4};
    DeckGUI2 deck5{player5, formatManager, thumbCache, 5};
    DeckGUI2 deck6{player6, formatManager, thumbCache, 6};
    DeckGUI2 deck7{player7, formatManager, thumbCache, 7};
    DeckGUI2 deck8{player8, formatManager, thumbCache, 8};
    
    int currentStep;
    
    //SequencerGUI sequencer;
    
    juce::TextButton startSequence;
    
    bool active;

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
    
    
    std::vector<juce::TextButton>stepLights;

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
    
    juce::TextButton bankButton1;
    juce::TextButton bankButton2;
    juce::TextButton bankButton3;
    juce::TextButton bankButton4;
    juce::TextButton bankButton5;
    juce::TextButton bankButton6;
    juce::TextButton bankButton7;
    juce::TextButton bankButton8;
    
    MixerAudioSource mixerSource;

    MyLookAndFeel myLookAndFeel;
    
    int tempo = 50;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    };

