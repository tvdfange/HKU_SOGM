//
//  distortion.cpp
//  guitarFX
//
//  Created by Thomas on 23/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#include "distortion.h"
#include <math.h>

Distortion::Distortion()
{
    Amplifier();
    this->level = 1;
}

void Distortion::showLevel()
{
    cout << "Distortion output level: " << level << endl;
}

void Distortion::setLevel(float level)
{
    this->level = level;
}

void Distortion::process()
{
    for ( int i = 0; i < numFrames * numChannels; ++i) {
        
        buffer[i]= tanh(buffer[i]*level);
    }
}

void Distortion::info()
{
    cout << "Distortion running" << endl;
}