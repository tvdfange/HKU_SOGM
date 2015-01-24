//
//  tremelo.h
//  guitarFX
//
//  Created by Thomas on 19/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#ifndef _Tremelo_H_
#define _Tremelo_H_

#include <iostream>
#include "amp.h"

using namespace std;

class Tremolo : public Amplifier
{
public:
	Tremolo();
	void setLevel(float level);
	void process();
    void info();
    void showLevel();
    

private:
	float frequentie;
    int sample;
	
}; //Class Tremolo

#endif