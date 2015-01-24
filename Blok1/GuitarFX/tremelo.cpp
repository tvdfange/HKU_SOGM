//
//  tremelo.cpp
//  guitarFX
//
//  Created by Thomas on 19/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//
#include "tremelo.h"
#include <math.h>

Tremolo::Tremolo()
{
	Amplifier();
	this->frequentie = 3;

}

void Tremolo::setLevel(float frequentie)
{
	this->frequentie = frequentie;

}

void Tremolo::showLevel()
{
      cout << "Tremolo frequentie: " << frequentie << endl;
}

void Tremolo::process()
{
        for (int i = 0; i < numFrames * numChannels; i++)
        {
            sample++;
            buffer[i] *= level * sin(2 * M_PI * (float)(sample / ((float)samplerate / frequentie) + 1));;
        }
    
}

void Tremolo::info()
{
      cout << "Tremolo running" << endl;
}

