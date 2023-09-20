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
    
    for(int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            stepList[i][j] = 0;
        }
    }
    
    
    
    
    addAndMakeVisible(deck1);
    addAndMakeVisible(deck2);
    addAndMakeVisible(deck3);
    addAndMakeVisible(deck4);
    addAndMakeVisible(deck5);
    addAndMakeVisible(deck6);
    addAndMakeVisible(deck7);
    addAndMakeVisible(deck8);


    
    active = false;
    
    isPlaying = true;
    looping = false;
    
    currentStep = 0;
    
    addAndMakeVisible(startSequence);
    startSequence.addListener(this);
    startSequence.setButtonText("Start");

currentStep = 0;

stepLight1.setEnabled(false);
    stepLight1.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight1);


stepLight2.setEnabled(false);
    stepLight2.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight2);


stepLight3.setEnabled(false);
    stepLight3.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight3);


stepLight4.setEnabled(false);
    stepLight4.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight4);


stepLight5.setEnabled(false);
    stepLight5.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight5);


stepLight6.setEnabled(false);
    stepLight6.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight6);


stepLight7.setEnabled(false);
    stepLight7.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight7);


stepLight8.setEnabled(false);
    stepLight8.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight8);


stepLight9.setEnabled(false);
    stepLight9.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight9);


stepLight10.setEnabled(false);
    stepLight10.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight10);


stepLight11.setEnabled(false);
    stepLight11.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight11);


stepLight12.setEnabled(false);
    stepLight12.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight12);


stepLight13.setEnabled(false);
    stepLight13.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight13);


stepLight14.setEnabled(false);
    stepLight14.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight14);


stepLight15.setEnabled(false);
    stepLight15.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight15);


stepLight16.setEnabled(false);
    stepLight16.setColour(TextButton::buttonColourId, Colours::grey);
addAndMakeVisible(stepLight16);

    step1.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step1.addListener(this);
    addAndMakeVisible(step1);

    step2.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step2.addListener(this);
    addAndMakeVisible(step2);

    step3.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step3.addListener(this);
    addAndMakeVisible(step3);

    step4.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step4.addListener(this);
    addAndMakeVisible(step4);

    step5.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step5.addListener(this);
    addAndMakeVisible(step5);

    step6.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step6.addListener(this);
    addAndMakeVisible(step6);

    step7.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step7.addListener(this);
    addAndMakeVisible(step7);

    step8.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step8.addListener(this);
    addAndMakeVisible(step8);

    step9.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step9.addListener(this);
    addAndMakeVisible(step9);

    step10.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step10.addListener(this);
    addAndMakeVisible(step10);

    step11.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step11.addListener(this);
    addAndMakeVisible(step11);

    step12.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step12.addListener(this);
    addAndMakeVisible(step12);

    step13.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step13.addListener(this);
    addAndMakeVisible(step13);

    step14.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step14.addListener(this);
    addAndMakeVisible(step14);

    step15.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step15.addListener(this);
    addAndMakeVisible(step15);

    step16.setColour(TextButton::buttonColourId, juce::Colours::grey);
    step16.addListener(this);
    addAndMakeVisible(step16);
        
    addAndMakeVisible(bankButton1);
    bankButton1.addListener(this);
    bankButton1.setButtonText("1");
    bankButton1.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton2);
    bankButton2.addListener(this);
    bankButton2.setButtonText("2");
    bankButton2.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton3);
    bankButton3.addListener(this);
    bankButton3.setButtonText("3");
    bankButton3.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton4);
    bankButton4.addListener(this);
    bankButton4.setButtonText("4");
    bankButton4.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton5);
    bankButton5.addListener(this);
    bankButton5.setButtonText("5");
    bankButton5.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton6);
    bankButton6.addListener(this);
    bankButton6.setButtonText("6");
    bankButton6.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton7);
    bankButton7.addListener(this);
    bankButton7.setButtonText("7");
    bankButton7.setColour(TextButton::buttonColourId, Colours::grey);
    
    addAndMakeVisible(bankButton8);
    bankButton8.addListener(this);
    bankButton8.setButtonText("8");
    bankButton8.setColour(TextButton::buttonColourId, Colours::grey);

    buttonClicked(&bankButton1);
//startTimer(200);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
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

void MainComponent::timerCallback()
{
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
    
    
    checkSequence();
    
}

void MainComponent::checkSequence()
{
    if(stepList[0][currentStep - 1] == 1)
    {
        player1.play();
    }
    if(stepList[1][currentStep - 1] == 1)
    {
        player2.play();
    }
    if(stepList[2][currentStep - 1] == 1)
    {
        player3.play();
    }
    if(stepList[3][currentStep - 1] == 1)
    {
        player4.play();
    }
    if(stepList[4][currentStep - 1] == 1)
    {
        player5.play();
    }
    if(stepList[5][currentStep - 1] == 1)
    {
        player6.play();
    }
    if(stepList[6][currentStep - 1] == 1)
    {
        player7.play();
    }
    if(stepList[7][currentStep - 1] == 1)
    {
        player8.play();
    }

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

    float deckHeight = getHeight() * .6;
    float deckSpace = getWidth()/8;
    
    deck1.setBounds(0, 0, deckSpace, deckHeight);
    deck2.setBounds(deckSpace * 1, 0, deckSpace, deckHeight);
    deck3.setBounds(deckSpace * 2, 0, deckSpace, deckHeight);
    deck4.setBounds(deckSpace * 3, 0, deckSpace, deckHeight);
    deck5.setBounds(deckSpace * 4, 0, deckSpace, deckHeight);
    deck6.setBounds(deckSpace * 5, 0, deckSpace, deckHeight);
    deck7.setBounds(deckSpace * 6, 0, deckSpace, deckHeight);
    deck8.setBounds(deckSpace * 7, 0, deckSpace, deckHeight);
    
    float column = getWidth() / 20;
    float row = getHeight() / 8;
    
    
    float startingHeight = getHeight() *.75;
    
   
    startSequence.setBounds(column,startingHeight + row, column * 2, row * .7);

    stepLight1.setBounds(column * 2,startingHeight, column * .8, row / 4);
    stepLight2.setBounds(column * 3,startingHeight, column * .8, row / 4);
    stepLight3.setBounds(column * 4,startingHeight, column * .8, row / 4);
    stepLight4.setBounds(column * 5,startingHeight, column * .8, row / 4);
    stepLight5.setBounds(column * 6,startingHeight, column * .8, row / 4);
    stepLight6.setBounds(column * 7,startingHeight, column * .8, row / 4);
    stepLight7.setBounds(column * 8,startingHeight, column * .8, row / 4);
    stepLight8.setBounds(column * 9,startingHeight, column * .8, row / 4);
    stepLight9.setBounds(column * 10,startingHeight, column * .8, row / 4);
    stepLight10.setBounds(column * 11,startingHeight, column * .8, row / 4);
    stepLight11.setBounds(column * 12,startingHeight, column * .8, row / 4);
    stepLight12.setBounds(column * 13,startingHeight, column * .8, row / 4);
    stepLight13.setBounds(column * 14,startingHeight, column * .8, row / 4);
    stepLight14.setBounds(column * 15,startingHeight, column * .8, row / 4);
    stepLight15.setBounds(column * 16,startingHeight, column * .8, row / 4);
    stepLight16.setBounds(column * 17,startingHeight, column * .8, row / 4);
    
    row = getHeight() / 6;
    startingHeight = getHeight() * .8;
    
    step1.setBounds(column * 2,startingHeight, column * .8, row / 4);
    step2.setBounds(column * 3,startingHeight, column * .8, row / 4);
    step3.setBounds(column * 4,startingHeight, column * .8, row / 4);
    step4.setBounds(column * 5,startingHeight, column * .8, row / 4);
    step5.setBounds(column * 6,startingHeight, column * .8, row / 4);
    step6.setBounds(column * 7,startingHeight, column * .8, row / 4);
    step7.setBounds(column * 8,startingHeight, column * .8, row / 4);
    step8.setBounds(column * 9,startingHeight, column * .8, row / 4);
    step9.setBounds(column * 10,startingHeight, column * .8, row / 4);
    step10.setBounds(column * 11,startingHeight, column * .8, row / 4);
    step11.setBounds(column * 12,startingHeight, column * .8, row / 4);
    step12.setBounds(column * 13,startingHeight, column * .8, row / 4);
    step13.setBounds(column * 14,startingHeight, column * .8, row / 4);
    step14.setBounds(column * 15,startingHeight, column * .8, row / 4);
    step15.setBounds(column * 16,startingHeight, column * .8, row / 4);
    step16.setBounds(column * 17,startingHeight, column * .8, row / 4);
    
    float bankButtonStartingHeight = getHeight() * .6;
    float bankButtonHeight = getHeight() * .1;
    
    bankButton1.setBounds(0, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton2.setBounds(deckSpace * 1, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton3.setBounds(deckSpace * 2, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton4.setBounds(deckSpace * 3, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton5.setBounds(deckSpace * 4, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton6.setBounds(deckSpace * 5, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton7.setBounds(deckSpace * 6, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    bankButton8.setBounds(deckSpace * 7, bankButtonStartingHeight, deckSpace, bankButtonHeight);
    

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
    stepLight1.setEnabled(false);
    stepLight2.setEnabled(false);
    stepLight3.setEnabled(false);
    stepLight4.setEnabled(false);
    
    stepLight5.setEnabled(false);
    stepLight6.setEnabled(false);
    stepLight7.setEnabled(false);
    stepLight8.setEnabled(false);
    
    stepLight9.setEnabled(false);
    stepLight10.setEnabled(false);
    stepLight11.setEnabled(false);
    stepLight12.setEnabled(false);
    
    stepLight13.setEnabled(false);
    stepLight14.setEnabled(false);
    stepLight15.setEnabled(false);
    stepLight16.setEnabled(false);
}

void MainComponent::clearBanks()
{
    bankSelected = 0;
    
    bankButton1.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton2.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton3.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton4.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton5.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton6.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton7.setColour(TextButton::buttonColourId, Colours::grey);
    bankButton8.setColour(TextButton::buttonColourId, Colours::grey);
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
    step1.setColour(TextButton::buttonColourId, Colours::grey);
    step2.setColour(TextButton::buttonColourId, Colours::grey);
    step3.setColour(TextButton::buttonColourId, Colours::grey);
    step4.setColour(TextButton::buttonColourId, Colours::grey);
    
    step5.setColour(TextButton::buttonColourId, Colours::grey);
    step6.setColour(TextButton::buttonColourId, Colours::grey);
    step7.setColour(TextButton::buttonColourId, Colours::grey);
    step8.setColour(TextButton::buttonColourId, Colours::grey);
    
    step9.setColour(TextButton::buttonColourId, Colours::grey);
    step10.setColour(TextButton::buttonColourId, Colours::grey);
    step11.setColour(TextButton::buttonColourId, Colours::grey);
    step12.setColour(TextButton::buttonColourId, Colours::grey);
    
    step13.setColour(TextButton::buttonColourId, Colours::grey);
    step14.setColour(TextButton::buttonColourId, Colours::grey);
    step15.setColour(TextButton::buttonColourId, Colours::grey);
    step16.setColour(TextButton::buttonColourId, Colours::grey);
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


