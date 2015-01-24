//
//  amp.cpp
//  guitarFX
//
//  Created by Thomas on 19/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#include "amp.h"


Amplifier::Amplifier()
{
  this->level=1; // default
  bufPointer = 0;
}

Amplifier::~Amplifier()
{
    
}

void Amplifier::showLevel()
{
  cout << "Amplifier level: " << level << endl;
}

void Amplifier::setLevel(float level)
{
	this->level = level;
}

void Amplifier::process()
{
    for (bufPointer = 0; bufPointer < numFrames * numChannels; bufPointer++)
		
        buffer[bufPointer] = buffer[bufPointer] * level;
        buffer[bufPointer] = clip(buffer[bufPointer]);
    
    
} //process

float Amplifier::clip(float input)
{
    if(input > 1) input = 1;
    else if (input < -1) input = -1;
    return input;
}


void Amplifier::startAudioCallback()
{
	audioStream.set_mode(AUDIO_IO_READWRITE);
	audioStream.set_samplerate(samplerate);
    audioStream.set_nrofchannels(numChannels);
	audioStream.set_framesperbuffer(numFrames);
    
	audioStream.initialise();	
	audioStream.list_devices();

	cout << "\nGive input device number: ";
	cin >> device;
	audioStream.set_input_device(device);
	cout << "Give output device number: ";
	cin >> device;
	audioStream.set_output_device(device);
	
	audioStream.start_server();
    cout << " " << endl;
    cout << "Stream running" << endl;
    cout << " " << endl;
    
} // startAudioCallback

void Amplifier::stopAudioCallback()
{
 	audioStream.finalise();
}

void Amplifier::readBuffer()
{
	audioStream.read(buffer);
}

void Amplifier::writeBuffer()
{
	audioStream.write(buffer);
}

void Amplifier::info()
{
    cout << "Amplifier running" << endl;
}


