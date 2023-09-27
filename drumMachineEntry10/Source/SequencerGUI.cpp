/*
  ==============================================================================

    DeckGUI2.cpp
    Created: 6 Mar 2023 8:52:04pm
    Author:  Jake

  ==============================================================================
*/
#include <JuceHeader.h>
#include "SequencerGUI.h"
#include <strings.h>

//==============================================================================
SequencerGUI::SequencerGUI() //calls the constructor on waveformdisplay
{
    for(int i = 0; i < 15; i++)
    {
        kickSelect.push_back(0);
    }
    
    
    
    currentStep = 0;
    active = false;
    
    addAndMakeVisible(startSequence);
    startSequence.setButtonText("Start");
    startSequence.addListener(this);
   
    stepLight1.setEnabled(false);
    addAndMakeVisible(stepLight1);
    
    
    stepLight2.setEnabled(false);
    addAndMakeVisible(stepLight2);
    
    
    stepLight3.setEnabled(false);
    addAndMakeVisible(stepLight3);
    
   
    stepLight4.setEnabled(false);
    addAndMakeVisible(stepLight4);
    
    
    stepLight5.setEnabled(false);
    addAndMakeVisible(stepLight5);
    
   
    stepLight6.setEnabled(false);
    addAndMakeVisible(stepLight6);
    
    
    stepLight7.setEnabled(false);
    addAndMakeVisible(stepLight7);
    
    
    stepLight8.setEnabled(false);
    addAndMakeVisible(stepLight8);
    
    
    stepLight9.setEnabled(false);
    addAndMakeVisible(stepLight9);
    
    
    stepLight10.setEnabled(false);
    addAndMakeVisible(stepLight10);
    
    
    stepLight11.setEnabled(false);
    addAndMakeVisible(stepLight11);
    
    
    stepLight12.setEnabled(false);
    addAndMakeVisible(stepLight12);
    
    
    stepLight13.setEnabled(false);
    addAndMakeVisible(stepLight13);
    
    
    stepLight14.setEnabled(false);
    addAndMakeVisible(stepLight14);
    
    
    stepLight15.setEnabled(false);
    addAndMakeVisible(stepLight15);
    
    
    stepLight16.setEnabled(false);
    addAndMakeVisible(stepLight16);
    
    
    addAndMakeVisible(step1);
    step1.addListener(this);
    
    step2.addListener(this);
    addAndMakeVisible(step2);
    
    step4.addListener(this);
    addAndMakeVisible(step3);
    
    step4.addListener(this);
    addAndMakeVisible(step4);
    
    step5.addListener(this);
    addAndMakeVisible(step5);
    
    step6.addListener(this);
    addAndMakeVisible(step6);
    
    step7.addListener(this);
    addAndMakeVisible(step7);
    
    step8.addListener(this);
    addAndMakeVisible(step8);
    
    step9.addListener(this);
    addAndMakeVisible(step9);
    
    step10.addListener(this);
    addAndMakeVisible(step10);
    
    step11.addListener(this);
    addAndMakeVisible(step11);
    
    step12.addListener(this);
    addAndMakeVisible(step12);
    
    step13.addListener(this);
    addAndMakeVisible(step13);
    
    step14.addListener(this);
    addAndMakeVisible(step14);
    
    step15.addListener(this);
    addAndMakeVisible(step15);
    
    step16.addListener(this);
    addAndMakeVisible(step16);
    
    
}

SequencerGUI::~SequencerGUI()
{
    stopTimer();
   
}

void SequencerGUI::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background
    g.setFont(20.f);
    
    
    juce::Rectangle<int> background = getLocalBounds();
    
    auto gradient = juce::ColourGradient::vertical(juce::Colour::fromFloatRGBA(0.28f, 0.3f, 0.34f, 1.0f),0.0f, juce::Colour::fromFloatRGBA(0.4f,0.3f,0.6f,1.0f), getHeight());
    //juce::ColourGradientgradient(juce::Colours::blue, 0.0f, 0.0f, juce::Colours::black, getWidth(), getHeight(), false);
    
    gradient.addColour(0.5, juce::Colour::fromFloatRGBA(0.34f, 0.3f, 0.5f, 1.0f)); //this is how to add a colour stop
    
    g.setGradientFill(gradient);
    
    g.fillRect(background);

}

void SequencerGUI::paintOverChildren(juce::Graphics &g)
{
            
     
}

void SequencerGUI::timerCallback() //once a second
{
    if(currentStep == 16)
    {
        currentStep = 1;
    }else
    {
        currentStep++;
    }
    
    DBG(currentStep);
    
    
    if(kickSelect[currentStep] == 1)
    {
        //
    }
    
    if(currentStep == 1)
    {
        stepLight16.setEnabled(false);
        stepLight1.setEnabled(true);
    }else if(currentStep == 2)
    {
        stepLight1.setEnabled(false);
        stepLight2.setEnabled(true);
    }else if(currentStep == 3)
    {
        stepLight2.setEnabled(false);
        stepLight3.setEnabled(true);
    }else if(currentStep == 4)
    {
        stepLight3.setEnabled(false);
        stepLight4.setEnabled(true);
    }else if(currentStep == 5)
    {
        stepLight4.setEnabled(false);
        stepLight5.setEnabled(true);
    }else if(currentStep == 6)
    {
        stepLight5.setEnabled(false);
        stepLight6.setEnabled(true);
    }else if(currentStep == 7)
    {
        stepLight6.setEnabled(false);
        stepLight7.setEnabled(true);
    }else if(currentStep == 8)
    {
        stepLight7.setEnabled(false);
        stepLight8.setEnabled(true);
    }else if(currentStep == 9)
    {
        stepLight8.setEnabled(false);
        stepLight9.setEnabled(true);
    }else if(currentStep == 10)
    {
        stepLight9.setEnabled(false);
        stepLight10.setEnabled(true);
    }else if(currentStep == 11)
    {
        stepLight10.setEnabled(false);
        stepLight11.setEnabled(true);
    }else if(currentStep == 12)
    {
        stepLight11.setEnabled(false);
        stepLight12.setEnabled(true);
    }else if(currentStep == 13)
    {
        stepLight12.setEnabled(false);
        stepLight13.setEnabled(true);
    }else if(currentStep == 14)
    {
        stepLight13.setEnabled(false);
        stepLight14.setEnabled(true);
    }else if(currentStep == 15)
    {
        stepLight14.setEnabled(false);
        stepLight15.setEnabled(true);
    }else if(currentStep == 16)
    {
        stepLight15.setEnabled(false);
        stepLight16.setEnabled(true);
    }
}
    

void SequencerGUI::resized()
{
    float column = getWidth() / 20;
    float row = getHeight() / 4;
   
    startSequence.setBounds(column, row * 1.8, column * 2, row );
    
    stepLight1.setBounds(column * 2,row, column * .8, row / 4);
    stepLight2.setBounds(column * 3,row, column * .8, row / 4);
    stepLight3.setBounds(column * 4,row, column * .8, row / 4);
    stepLight4.setBounds(column * 5,row, column * .8, row / 4);
    stepLight5.setBounds(column * 6,row, column * .8, row / 4);
    stepLight6.setBounds(column * 7,row, column * .8, row / 4);
    stepLight7.setBounds(column * 8,row, column * .8, row / 4);
    stepLight8.setBounds(column * 9,row, column * .8, row / 4);
    stepLight9.setBounds(column * 10,row, column * .8, row / 4);
    stepLight10.setBounds(column * 11,row, column * .8, row / 4);
    stepLight11.setBounds(column * 12,row, column * .8, row / 4);
    stepLight12.setBounds(column * 13,row, column * .8, row / 4);
    stepLight13.setBounds(column * 14,row, column * .8, row / 4);
    stepLight14.setBounds(column * 15,row, column * .8, row / 4);
    stepLight15.setBounds(column * 16,row, column * .8, row / 4);
    stepLight16.setBounds(column * 17,row, column * .8, row / 4);
    
    row = getHeight() / 3;
    
    step1.setBounds(column * 2,row, column * .8, row / 4);
    step2.setBounds(column * 3,row, column * .8, row / 4);
    step3.setBounds(column * 4,row, column * .8, row / 4);
    step4.setBounds(column * 5,row, column * .8, row / 4);
    step5.setBounds(column * 6,row, column * .8, row / 4);
    step6.setBounds(column * 7,row, column * .8, row / 4);
    step7.setBounds(column * 8,row, column * .8, row / 4);
    step8.setBounds(column * 9,row, column * .8, row / 4);
    step9.setBounds(column * 10,row, column * .8, row / 4);
    step10.setBounds(column * 11,row, column * .8, row / 4);
    step11.setBounds(column * 12,row, column * .8, row / 4);
    step12.setBounds(column * 13,row, column * .8, row / 4);
    step13.setBounds(column * 14,row, column * .8, row / 4);
    step14.setBounds(column * 15,row, column * .8, row / 4);
    step15.setBounds(column * 16,row, column * .8, row / 4);
    step16.setBounds(column * 17,row, column * .8, row / 4);
    
}

void SequencerGUI::buttonClicked(Button * button)
{
    if(&startSequence == button && active == false)
    {
        startTimer(200);
        timerCallback();
        active = true;
        DBG("testing");
    }else if(&startSequence == button && active == true)
    {
        stopTimer();
        active = false;
        currentStep = 0;
    }
    if(&step1 == button && kickSelect[0] == 0)
    {
        step1.setColour(TextButton::buttonColourId, juce::Colours::red);
        kickSelect[0] = 1;
        DBG("Added");
        
    }else if(&step1 == button && kickSelect[0] == 1)
    {
        step1.setColour(TextButton::buttonColourId, juce::Colours::grey);
        kickSelect[0] = 0;
        DBG("Removed");
    }
    
}

void SequencerGUI::sliderValueChanged(Slider * slider)
{

}


