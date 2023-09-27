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
    
    //is sequencer active
    active = false;
    
    
    isPlaying = true;
    looping = false;
    
    //sets starting sequence to zero
    currentStep = 0;
    currentPattern = 0;
    
    //start button
    addAndMakeVisible(startSequence);
    startSequence.addListener(this);
    startSequence.setButtonText("Start");
    
    //Initalising step pattern array
        for(int p = 0; p < 8; p++)
        {
            for(int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    stepList[p][i][j] = 0;
                }
            }
        }
    
    //deckGUI2
    for(auto i = 0; i < deckArray.size(); i++)
    {
        addAndMakeVisible(deckArray[i]);
    }
    

    //Light Buttons(show which step we are at
    for(auto i = 0; i < stepLightButtons.size(); i++)
    {
        addAndMakeVisible(stepLightButtons[i]);
        stepLightButtons[i]->setColour(TextButton::buttonColourId,Colours::grey);
        stepLightButtons[i]->setEnabled(false);
    }

    //step selection buttons
    for( auto i = 0; i < stepButtons.size(); i++)
    {
        addAndMakeVisible(stepButtons[i]);
        stepButtons[i]->setColour(TextButton::buttonColourId, Colours::grey);
        stepButtons[i]->addListener(this);
    }
    
    //bank selection buttons
    for( auto i = 0; i < bankButtons.size(); i++)
    {
        addAndMakeVisible(bankButtons[i]);
        bankButtons[i]->addListener(this);
        string bankName = std::to_string(i + 1);
        bankButtons[i]->setButtonText(bankName);
        bankButtons[i]->setColour(TextButton::buttonColourId, Colours::grey);
        
    }
    
    for(int i = 0; i < patternArray.size(); i++)
    {
        addAndMakeVisible(patternArray[i]);
        patternArray[i]->addListener(this);
        string patternName = std::to_string(i+1);
        patternArray[i]->setButtonText(patternName);
        patternArray[i]->setColour(TextButton::buttonColourId, Colours::grey);
        
    }
    
    //initalise bank to 1
    buttonClicked(&bankButton1);
    buttonClicked(&pattern1);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    
    for(int i = 0; i < playerArray.size(); i++)
    {
        mixerSource.addInputSource(playerArray[i], false);
    }

    //prepare mixer audio
    mixerSource.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    //processes audio of all channels
    mixerSource.getNextAudioBlock(bufferToFill);
}

void MainComponent::timerCallback()
{
    //Increments the curent step in sequence ever timer callback
    if(currentStep == 16)
    {
        currentStep = 1;
    }else
    {
        currentStep++;
    }
    
    int index;
    int indexBelow;
   
    if(currentStep == 1)
    {
        index = 0;
        indexBelow = 15;
    }else
    {
        index = currentStep - 1;
        indexBelow = currentStep - 2;
    }
    
    stepLightButtons[index]->setColour(TextButton::buttonColourId, Colours::red);
    stepLightButtons[indexBelow]->setColour(TextButton::buttonColourId, Colours::grey);
    
    //checks to see if the players will play
    checkSequence();
    
}

void MainComponent::checkSequence()
{
    
    for(auto i = 0; i < playerArray.size(); i++)
    {
        if(stepList[currentPattern][i][currentStep - 1] == 1)
        {
            playerArray[i]->play();
        }
    }

}

void MainComponent::releaseResources()
{
    mixerSource.removeAllInputs();
    mixerSource.releaseResources();
    
    for(auto i = 0; i < playerArray.size(); i++)
    {
        playerArray[i]->releaseResources();
    }
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::royalblue);
    
}

void MainComponent::resized()
{

    float deckHeight = getHeight() * .6;
    float deckSpace = getWidth()/8;
    
    //DECK INSTANCES
    for(auto i = 0; i < deckArray.size(); i++)
    {
        deckArray[i]->setBounds(deckSpace * i, 0, deckSpace, deckHeight);
    }
    
    float column = getWidth() / 20;
    float row = getHeight() / 8;
    
    
    float startingHeight = getHeight() *.75;
    
   
    startSequence.setBounds(column,startingHeight + row, column * 2, row * .7);

    //STEPLIGHT BUTTONS
    for(auto i = 0; i < stepLightButtons.size(); i++)
    {
        stepLightButtons[i]->setBounds(column * (i+2), startingHeight, column * .8, row / 4);
    }
    
    row = getHeight() / 6;
    startingHeight = getHeight() * .8;
    
    float bankButtonStartingHeight = getHeight() * .6;
    float bankButtonHeight = getHeight() * .1;
    
    
    //STEP BUTTONS
    for(auto i = 0; i < stepButtons.size(); i++)
    {
        stepButtons[i]->setBounds(column * (i + 2), startingHeight, column * .8, row / 4);
    }
    
    //BANK BUTTONS
    for(auto i = 0; i < bankButtons.size(); i++)
    {
        bankButtons[i]->setBounds(deckSpace * i, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    }
    
    
    
    //PATTERN BUTTONS
    
    int patternStartX = getWidth() * .2;
    int patternStartY = getHeight() * .9;
    int patternWidth = 50;
    int patternHeight = 30;
    
    for(int i = 0; i < patternArray.size(); i++)
    {
        if(i < 4)
        {
            patternArray[i]->setBounds(patternStartX + (i * 50), patternStartY, patternWidth, patternHeight);
        }else
        {
            patternArray[i]->setBounds(patternStartX + ((i - 4) * 50), patternStartY + patternHeight, patternWidth, patternHeight);
        }
    }
    
}
void MainComponent::sliderValueChanged(juce::Slider * slider)
{
    
}
void MainComponent::buttonClicked(Button *button)
{
    if(&startSequence == button && active == false)
    {
        startTimer(tempo);
        timerCallback();
        active = true;
    }else if(&startSequence == button && active == true)
    {
        stopTimer();
        clearLights();
        active = false;
        currentStep = 0;
    }
    
    for(int i = 0; i < stepButtons.size(); i++)
    {
        if(stepButtons[i] == button)
        {
            addStep(stepButtons[i], i + 1);
        }
    }
    
    for(int i = 0; i < bankButtons.size(); i++)
    {
        if(bankButtons[i] == button)
        {
            clearBanks();
            changeBank(bankButtons[i], i + 1);
        }
    }
    for(int i = 0; i < patternArray.size(); i++)
    {
        if(patternArray[i] == button)
        {
            currentPattern = i;
            clearSteps();
            clearPatterns();
            drawSteps(bankSelected);
            patternArray[i]->setColour(TextButton::buttonColourId, Colours::purple);
        }
    }
    
}

void MainComponent::clearLights()
{
    
    for(auto i = 0; i < stepLightButtons.size(); i++)
    {
        stepLightButtons[i]->setEnabled(false);
    }
}

void MainComponent::clearBanks()
{
    bankSelected = 0;
    
    for(auto i = 0; i < bankButtons.size(); i++)
    {
        bankButtons[i]->setColour(TextButton::buttonColourId, Colours::grey);
    }
    
}

void MainComponent::clearPatterns()
{
    for(int i = 0; i < patternArray.size(); i++)
    {
        patternArray[i]->setColour(TextButton::buttonColourId, Colours::grey);
    }
}
void MainComponent::changeBank(Button *button, int bank)
{
    clearSteps();
    bankSelected = bank;
    
    button->setColour(TextButton::buttonColourId, Colours::blue);
    for(int i = 0; i < 15; i++)
    {
        std::cout<<stepList[currentPattern][bankSelected - 1][i]<<std::endl;
    }
    
    drawSteps(bankSelected);
}

void MainComponent::addStep(Button *button, int step)
{
    int currentBank = bankSelected - 1;
    int newStep = step - 1;
    int bankAndStep = stepList[currentPattern][currentBank][newStep];
    
    if(bankAndStep == 0)
    {
        stepList[currentPattern][currentBank][newStep] = 1;
        button->setColour(TextButton::buttonColourId, Colours::blue);
    }
    else if(bankAndStep == 1)
    {
        //add
//        button->setColour(TextButton::buttonColourId, Colours::grey);
        stepList[currentPattern][currentBank][newStep] = 0;
        button->setColour(TextButton::buttonColourId, Colours::grey);
    }
}

void MainComponent::clearSteps()
{
    DBG("clearing steps");
    
    for(auto i = 0; i < stepButtons.size(); i++)
    {
        stepButtons[i]->setColour(juce::TextButton::buttonColourId, Colours::grey);
    }
}

void MainComponent::drawSteps(int bank)
{
    bank = bank-1;
    //draw the steps from the array
    
    int buttons = 16;
    
        for(int j = 0; j < buttons; j++)
        {
            if(stepList[currentPattern][bank][j] == 1)
            {
                stepButtons[j]->setColour(TextButton::buttonColourId, Colours::blue);
            }
        }
}


