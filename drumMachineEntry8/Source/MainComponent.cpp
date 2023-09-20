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
    
    //start button
    addAndMakeVisible(startSequence);
    startSequence.addListener(this);
    startSequence.setButtonText("Start");
    
    //Initalising step pattern array
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            stepList[i][j] = 0;
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
    
    //initalise bank to 1
    buttonClicked(&bankButton1);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    //mix all player sources together
    mixerSource.addInputSource(&player1, false); //adding the players together
    mixerSource.addInputSource(&player2, false);
    mixerSource.addInputSource(&player3, false); //adding the players together
    mixerSource.addInputSource(&player4, false);
    mixerSource.addInputSource(&player5, false); //adding the players together
    mixerSource.addInputSource(&player6, false);
    mixerSource.addInputSource(&player7, false); //adding the players together
    mixerSource.addInputSource(&player8, false);
    
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

    if(currentStep == 1)
    {
        stepLight16.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight1.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 2)
    {
        stepLight1.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight2.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 3)
    {
        stepLight2.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight3.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 4)
    {
        stepLight3.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight4.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 5)
    {
        stepLight4.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight5.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 6)
    {
        stepLight5.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight6.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 7)
    {
        stepLight6.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight7.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 8)
    {
        stepLight7.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight8.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 9)
    {
        stepLight8.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight9.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 10)
    {
        stepLight9.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight10.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 11)
    {
        stepLight10.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight11.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 12)
    {
        stepLight11.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight12.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 13)
    {
        stepLight12.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight13.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 14)
    {
        stepLight13.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight14.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 15)
    {
        stepLight14.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight15.setColour(TextButton::buttonColourId, Colours::red);
    }else if(currentStep == 16)
    {
        stepLight15.setColour(TextButton::buttonColourId, Colours::grey);
        stepLight16.setColour(TextButton::buttonColourId, Colours::red);
    }
    
    //checks to see if the players will play
    checkSequence();
    
}

void MainComponent::checkSequence()
{
    
    for(auto i = 0; i < playerArray.size(); i++)
    {
        if(stepList[i][currentStep - 1] == 1)
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
    
//    for(int i = 0; i < stepButtons.size(); i++)
//    {
//
//        auto currentButton = stepButtons[i];
//
//        if(currentButton == button)
//        {
//            addStep(currentButton, i - 1);
//        }
//    }
    
    if(&step1 == button)
    {
        addStep(&step1, 1);
    }
    if(&step2 == button)
    {
        addStep(&step2, 2);
    }
    if(&step3 == button)
    {
        addStep(&step3, 3);
    }
    if(&step4 == button)
    {
        addStep(&step4, 4);
    }
    if(&step5 == button)
    {
        addStep(&step5, 5);
    }
    if(&step6 == button)
    {
        addStep(&step6, 6);
    }
    if(&step7 == button)
    {
        addStep(&step7, 7);
    }
    if(&step8 == button)
    {
        addStep(&step8, 8);
    }
    if(&step9 == button)
    {
        addStep(&step9, 9);
    }
    if(&step10 == button)
    {
        addStep(&step10, 10);
    }
    if(&step11 == button)
    {
        addStep(&step11, 11);
    }
    if(&step12 == button)
    {
        addStep(&step12, 12);
    }
    if(&step13 == button)
    {
        addStep(&step13, 13);
    }
    if(&step14 == button)
    {
        addStep(&step14, 14);
    }
    if(&step15 == button)
    {
        addStep(&step15, 15);
    }
    if(&step16 == button)
    {
        addStep(&step16, 16);
    }
        
    
    if(&bankButton1 == button)
    {
        clearBanks();
        changeBank(&bankButton1, 1);
    }
    if(&bankButton2 == button)
    {
        clearBanks();
        changeBank(&bankButton2, 2);
    }
    if(&bankButton3 == button)
    {
        clearBanks();
        changeBank(&bankButton3, 3);
    }
    if(&bankButton4 == button)
    {
        clearBanks();
        changeBank(&bankButton4, 4);
    }
    if(&bankButton5 == button)
    {
        clearBanks();
        changeBank(&bankButton5, 5);
    }
    if(&bankButton6 == button)
    {
        clearBanks();
        changeBank(&bankButton6, 6);
    }
    if(&bankButton7 == button)
    {
        clearBanks();
        changeBank(&bankButton7, 7);
    }
    if(&bankButton8 == button)
    {
        clearBanks();
        changeBank(&bankButton8, 8);
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
void MainComponent::changeBank(Button *button, int bank)
{
    clearSteps();
    bankSelected = bank;
    
    button->setColour(TextButton::buttonColourId, Colours::blue);
    for(int i = 0; i < 15; i++)
    {
        std::cout<<stepList[bankSelected - 1][i]<<std::endl;
    }
    
    drawSteps(bankSelected);
}

void MainComponent::addStep(Button *button, int step)
{
    int currentBank = bankSelected - 1;
    int newStep = step - 1;
    int bankAndStep = stepList[currentBank][newStep];
    
    if(bankAndStep == 0)
    {
        stepList[currentBank][newStep] = 1;
        button->setColour(TextButton::buttonColourId, Colours::blue);
    }
    else if(bankAndStep == 1)
    {
        //add
//        button->setColour(TextButton::buttonColourId, Colours::grey);
        stepList[currentBank][newStep] = 0;
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
    if(stepList[bank][0] == 1)
    {
        step1.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][1] == 1)
    {
        step2.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][2] == 1)
    {
        step3.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][3] == 1)
    {
        step4.setColour(TextButton::buttonColourId, Colours::blue);
    }
    
    if(stepList[bank][4] == 1)
    {
        step5.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][5] == 1)
    {
        step6.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][6] == 1)
    {
        step7.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][7] == 1)
    {
        step8.setColour(TextButton::buttonColourId, Colours::blue);
    }
    
    if(stepList[bank][8] == 1)
    {
        step9.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][9] == 1)
    {
        step10.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][10] == 1)
    {
        step11.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][11] == 1)
    {
        step12.setColour(TextButton::buttonColourId, Colours::blue);
    }
    
    if(stepList[bank][12] == 1)
    {
        step13.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][13] == 1)
    {
        step14.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][14] == 1)
    {
        step15.setColour(TextButton::buttonColourId, Colours::blue);
    }
    if(stepList[bank][15] == 1)
    {
        step16.setColour(TextButton::buttonColourId, Colours::blue);
    }
}


