#include "MainComponent.h"
//==============================================================================
MainComponent::MainComponent()
{
    
    // Make sure you set the size of the component after
    // you add any child components
    setSize(800, 600);
   
    if (juce::RuntimePermissions::isRequired (juce::RuntimePermissions::recordAudio)
        && ! juce::RuntimePermissions::isGranted (juce::RuntimePermissions::recordAudio))
    {
        juce::RuntimePermissions::request (juce::RuntimePermissions::recordAudio,
                                           [&] (bool granted) { setAudioChannels (granted ? 2 : 0, 2); });
    }
    else
    {
        // Specify the number of input and output channels that we want to open
        setAudioChannels (2, 2);
    }
    
    formatManager.registerBasicFormats();
    
    
    addAndMakeVisible(deck1);
    addAndMakeVisible(deck2);
    addAndMakeVisible(deck3);
    addAndMakeVisible(deck4);
    addAndMakeVisible(deck5);
    addAndMakeVisible(deck6);
    addAndMakeVisible(deck7);
    addAndMakeVisible(deck8);
    
    isPlaying = true;
    looping = false;
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
    xfadeSlider.setLookAndFeel(nullptr); //no longer used when mainComponent is destroyed
    xfadeSlider.setColour(3, juce::Colours::royalblue);
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    mixerSource.addInputSource(&player1, false); //adding the players together
    mixerSource.addInputSource(&player2, false);
    mixerSource.addInputSource(&player3, false); //adding the players together
    mixerSource.addInputSource(&player4, false);
    mixerSource.addInputSource(&player5, false); //adding the players together
    mixerSource.addInputSource(&player6, false);
    mixerSource.addInputSource(&player7, false); //adding the players together
    mixerSource.addInputSource(&player8, false);
    
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    
    mixerSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    mixerSource.removeAllInputs();
    mixerSource.releaseResources();
    
    player1.releaseResources();
    player2.releaseResources();
    player3.releaseResources();
    player4.releaseResources();
    player5.releaseResources();
    player6.releaseResources();
    player7.releaseResources();
    player8.releaseResources();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::royalblue);
    
}

void MainComponent::resized()
{

    
    float deckSpace = getWidth()/8;
    
    deck1.setBounds(0, 0, deckSpace, getHeight());
    deck2.setBounds(deckSpace * 1, 0, deckSpace, getHeight());
    deck3.setBounds(deckSpace * 2, 0, deckSpace, getHeight());
    deck4.setBounds(deckSpace * 3, 0, deckSpace, getHeight());
    deck5.setBounds(deckSpace * 4, 0, deckSpace, getHeight());
    deck6.setBounds(deckSpace * 5, 0, deckSpace, getHeight());
    deck7.setBounds(deckSpace * 6, 0, deckSpace, getHeight());
    deck8.setBounds(deckSpace * 7, 0, deckSpace, getHeight());
    
}
void MainComponent::sliderValueChanged(juce::Slider * slider)
{
    
}
