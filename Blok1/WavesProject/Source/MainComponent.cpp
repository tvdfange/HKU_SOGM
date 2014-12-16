

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include "libsndfile.h"



//==============================================================================

class MainContentComponent   : public AnimatedAppComponent,
                               private AudioCallback

{
public:
    float mouX = 0;
    float mouY = 0;
    
    int spaceApart = 11;
    
    int circleSize = 0;
    int circleSize2 = 0;
    int circleSize3 = 0;
    int circleSize4 = 0;
    
    float circleX = 0;
    float circleY = 0;
    float circleX2 = 0;
    float circleY2 = 0;
    float circleX3 = 0;
    float circleY3 = 0;
    float circleX4 = 0;
    float circleY4 = 0;
    
    SNDFILE* inFile;
    SF_INFO sfInfo;
    const char *pathAudiofile = "/Users/Thomas/Desktop/Waves/Builds/MacOSX/Splash.wav";
    float audioBuffer[4096];
    
    
    MainContentComponent()
    {
        setSize (800,600);
        setFramesPerSecond (40);
        
    }
    
    ~MainContentComponent()
    {
    }
    
    void update() override
    {
        circleX = mouX - circleSize;
        circleY = mouY - circleSize;
        if (circleSize > 0) circleSize = circleSize+2;
        
        
        circleX2 = mouX - circleSize2;
        circleY2 = mouY - circleSize2;
        if (circleSize > spaceApart) circleSize2 = circleSize2+2;
        
        
        circleX3 = mouX - circleSize3;
        circleY3 = mouY - circleSize3;
        if (circleSize2 > spaceApart) circleSize3 = circleSize3+2;
        
        
        circleX4 = mouX - circleSize4;
        circleY4 = mouY - circleSize4;
        if (circleSize3 > spaceApart) circleSize4 = circleSize4+2;
        
        
    }
    
    void paint(Graphics& g) override
    {
        g.fillAll (Colours::steelblue);
        g.setColour (Colours::white);
        
        g.drawEllipse (circleX,
                       circleY,
                       circleSize*2.f,
                       circleSize*2.f,
                       1.5);
        
        
       
        
        g.drawEllipse (circleX2,
                       circleY2,
                       circleSize2*2.f,
                       circleSize2*2.f,
                       2);
        
       
        
        g.drawEllipse (circleX3,
                       circleY3,
                       circleSize3*2.f,
                       circleSize3*2.f,
                       1.5);
        
        
        
        g.drawEllipse (circleX4,
                       circleY4,
                       circleSize4*2.f,
                       circleSize4*2.f,
                       1);
        
        
    }
    
    void mouseDown (const MouseEvent& event)
    {
        mouX = event.x;
        mouY = event.y;
        circleSize = 1;
        circleSize2 = 1;
        circleSize3 = 1;
        circleSize4 = 1;
        
        
    }
    
    
    
    void AudioCallback(float** buffer, int channels, int frames)
    {
        
        inFile = sf_open(pathAudiofile, SFM_READ, &sfInfo);
        sf_readf_float(inFile, audioBuffer, frames);
        //startAudioCallback();
        
        
        
    }
    
    
    
    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
    }



private:
    //==============================================================================

    // Your private member variables go here...



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
