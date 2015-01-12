#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioCallback.h"
#include "sndfile.h"

using namespace std;


//==============================================================================

class MainContentComponent   : public AnimatedAppComponent,
                                private AudioCallback

{
public:
    
    float mouX = 0;
    float mouY = 0;
    bool mouseClick = false;
    
    int spaceApart = 11; // space between the ellipces
    
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
    
    float audioBuffer[150000];
    float lBuffer[150000];
    float rBuffer[150000];
    
    int numChannels = 0;
    int numFrames = 0;
    int samplerate = 0;
    
    short playBackPointer = 0;
    
    
    MainContentComponent()
    {
        setSize (800,600);
        setFramesPerSecond (40);
        readSoundFile();
        
    } // main
    
    ~MainContentComponent()
    {
        stopAudioCallback();
        sf_close(inFile);
        
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
        
    } //updater
    
    void paint(Graphics& g) override
    {
        g.fillAll (Colours::steelblue);
        g.setColour (Colours::white);
        
        g.drawEllipse (circleX,circleY,circleSize*2.f,circleSize*2.f,1.5);
        g.drawEllipse (circleX2,circleY2,circleSize2*2.f,circleSize2*2.f,2);
        g.drawEllipse (circleX3,circleY3,circleSize3*2.f,circleSize3*2.f,1.5);
        g.drawEllipse (circleX4,circleY4,circleSize4*2.f,circleSize4*2.f,1);
        
        
    } //graphics

    void mouseDown (const MouseEvent& event)
    {
        mouX = event.x;
        mouY = event.y;
        circleSize = 1;
        circleSize2 = 1;
        circleSize3 = 1;
        circleSize4 = 1;
        
        if (event.x > 0){
            
            mouseClick = true;
        }
        
        if (mouseClick == true) {
            
            startAudioCallback();
            sf_seek(inFile, 0, SEEK_SET);
            playBackPointer = 0;
        }
        
    } //mousedown tracking
    
    void readSoundFile()
    {
        inFile = sf_open("/Users/Thomas/Documents/SOGM/JuceWaves/Source/splash.wav", SFM_READ, &sfInfo);
        
        if (inFile == NULL){
            cout << "Could not read soundfile" << endl;
        }
        else {
            cout << "Soundfile accepted" << endl;
        
        }
        
        numChannels = sfInfo.channels;
        numFrames = sfInfo.frames;
        samplerate = sfInfo.samplerate;
        cout << samplerate << endl;
        cout << numFrames << endl;
        cout << numChannels << endl;
        
    } // readSoundFile
    
    void audioCallback(float** buffer, int channels, int frames)
    {

        sf_readf_float(inFile, audioBuffer, frames);
         
        for (int i = 0; i < frames; i++){
                lBuffer[i] = audioBuffer[i * 2];
                rBuffer[i] = audioBuffer[i * 2 + 1];
             
        } //wrinting buffers
         
         
        for (int f = 0; f < frames; f++){
            for (int c = 0; c < numChannels; c++){
                if (c == 0){
                    buffer [c][f] = lBuffer[f];
                    }
                
                else if (c == 1){
                    buffer [c][f] = rBuffer[f];
                    }
                }
            playBackPointer++;
            
        } //writing into AudioCallback buffer
        
        if (playBackPointer > numFrames){
            sf_seek(inFile, 0, SEEK_SET);
            playBackPointer = 0;
            stopAudioCallback();
            
        } //start sample from beginning
        
    } //audiocallback

    void resized() override
    {
    }
    
    
    
private:
    //==============================================================================
    
    // Your private member variables go here...
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()    { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED