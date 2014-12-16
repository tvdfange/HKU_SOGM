/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (800,600);
    circleSize = 0;
   
    
    startTimer(0, 33);
    
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colours::steelblue);
    g.setColour (Colours::white);
    
    g.drawEllipse (circleX,circleY,circleSize*2.f,circleSize*2.f,2);
}

void MainContentComponent::resized()
{
 
}

void MainContentComponent::timerCallback(int timerID)
{
    circleX = mouX - circleSize;
    circleY = mouY - circleSize;
    if (circleSize > 0) circleSize = circleSize+2;
    repaint();
}

void MainContentComponent::mouseDown (const MouseEvent& event)
{
    mouX = event.x;
    mouY = event.y;
    circleSize = 1;
}


