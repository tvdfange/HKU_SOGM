//
//  distortion.h
//  guitarFX
//
//  Created by Thomas on 23/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#ifndef __guitarFX__distortion__
#define __guitarFX__distortion__

#include <stdio.h>
#include "amp.h"

using namespace std;

class Distortion : public Amplifier
{
public:
    Distortion();
    void info();
    void setLevel(float level);
    void process();
    void showLevel();
    
private:
    float level;
    

};






#endif /* defined(__guitarFX__distortion__) */
