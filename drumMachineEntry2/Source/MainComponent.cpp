#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    setSize (800, 600);

    // Some platforms require permissions to open input channels so request that here
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
    
    addAndMakeVisible(playButton);
    playButton.addListener(this); //This would usually be pointing to main component but because it inherits from button listener it compiles
    playButton.setButtonText("Play");
    
    addAndMakeVisible(stopButton);
    stopButton.addListener(this);
    stopButton.setButtonText("Stop");
    
    addAndMakeVisible(loadButton);
    loadButton.addListener(this);
    loadButton.setButtonText("Load");
    
    addAndMakeVisible(gainSlider);
    gainSlider.addListener(this);
    gainSlider.setRange(0, 1);
    gainSlider.setValue(0.5);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    player1.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    player1.getNextAudioBlock(bufferToFill);
}

void MainComponent::releaseResources()
{
    
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
   
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

   
}

void MainComponent::resized()
{
    
    playButton.setBounds(0,0, getWidth()/2, getHeight() / 5);
    stopButton.setBounds(0,getHeight() / 5, getWidth(), getHeight() / 5);
    loadButton.setBounds(getWidth()/2,0,getWidth()/2,getHeight()/5);
    
    gainSlider.setBounds(0,(getHeight() / 5) * 2, getWidth(), getHeight() / 5);
}


void MainComponent::buttonClicked(juce::Button *button)
{
    if(&playButton == button)
    {
        DBG("MainComponent::buttonClicked: playButton");
        playing = true;
        player1.play();
    }
    
    if(&stopButton == button)
    {
        DBG("MainComponent::buttonClicked: stopButton");
        playing = false;
        player1.stop();
    }
    
    if(&loadButton == button)
    {
        juce::FileChooser chooser{"Select a sound file..."};
        if(chooser.browseForFileToOpen())
        {
           player1.loadURL(juce::URL{(chooser.getResult())});
        }
    }
}

void MainComponent::sliderValueChanged(juce::Slider *slider)
{
    if(&gainSlider == slider)
    {
        DBG("MainComponent::sliderValueChanged: gainSlider" << gainSlider.getValue());
        
        gain = gainSlider.getValue();
        player1.setGain(gain);
    }
}
