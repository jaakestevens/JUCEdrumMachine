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
    void clearSteps();
    void clearPatterns();
    void drawSteps(int bank);
    void changeBank(Button *button, int bank);
    
    int bankSelected;
    
    int stepList[8][8][16];

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
    
    int currentPattern;
    
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
    
    juce::TextButton pattern1;
    juce::TextButton pattern2;
    juce::TextButton pattern3;
    juce::TextButton pattern4;
    juce::TextButton pattern5;
    juce::TextButton pattern6;
    juce::TextButton pattern7;
    juce::TextButton pattern8;
    
    juce::TextButton bigpattern1;
    juce::TextButton bigpattern2;
    juce::TextButton bigpattern3;
    juce::TextButton bigpattern4;
    juce::TextButton bigpattern5;
    juce::TextButton bigpattern6;
    juce::TextButton bigpattern7;
    juce::TextButton bigpattern8;
    
    std::vector<juce::TextButton*> bankButtons =
    {
        &bankButton1, &bankButton2, &bankButton3, &bankButton4, &bankButton5, &bankButton6, &bankButton7, &bankButton8
    };
    
    std::vector<juce::TextButton*> stepButtons =
    {
        &step1,&step2,&step3,&step4,&step5,&step6,&step7,
        &step8,&step9,&step10,&step11,&step12,&step13,&step14,
        &step15,&step16
    };
    
    std::vector<juce::TextButton*> stepLightButtons =
    {
        &stepLight1,&stepLight2,&stepLight3,&stepLight4,&stepLight5,&stepLight6,&stepLight7,&stepLight8,&stepLight9,
        &stepLight10,&stepLight11,&stepLight12,&stepLight13,&stepLight14,&stepLight15,&stepLight16
    };
    
    std::vector<DeckGUI2*> deckArray =
    {
        &deck1,&deck2,&deck3,&deck4,&deck5,&deck6,&deck7,&deck8
    };
    
    std::vector<DJAudioPlayer*> playerArray =
    {
        &player1,&player2,&player3,&player4,&player5,&player6,&player7,&player8
    };
    
    std::vector<juce::TextButton*> patternArray =
    {
        &pattern1,&pattern2,&pattern3,&pattern4,&pattern5,&pattern6,&pattern7,&pattern8
    };
    
    
    
    
    MixerAudioSource mixerSource;

    MyLookAndFeel myLookAndFeel;
    
    int tempo = 100;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    };

