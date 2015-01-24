//
//  apm.h
//  guitarFX
//
//  Created by Thomas on 19/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#ifndef _AMP_H_
#define _AMP_H_

#include <iostream>
#include "audio_io.h"

#define samplerate 44100
#define numChannels 1
#define numFrames 1024

using namespace std;

class Amplifier : public Audio_IO
{
public:
    Audio_IO audioStream;
    Amplifier();
    ~Amplifier();
    
    void startAudioCallback();
    void stopAudioCallback();
    void readBuffer();
    void writeBuffer();
    float clip(float input);
    virtual void setLevel(float level);
    virtual void showLevel();
    virtual void info();
    virtual void setModFreq(float frequentie){};
    
    virtual void process();

protected:
    float level;
    float buffer[numFrames * numChannels];
    int device;
    int bufPointer;

}; //Class Amplifier

#endif