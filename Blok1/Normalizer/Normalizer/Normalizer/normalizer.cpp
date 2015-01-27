//
//  normalizer.cpp
//  Normalizer
//
//  Created by Thomas on 27/01/15.
//  Copyright (c) 2015 Thomas. All rights reserved.
//

#include <stdio.h>
#include "sndfile.h"
#include <iostream>
#include <math.h>

using namespace std;



enum {ARG_NAME = 0, ARG_INPUT};



int main (int argc, char** argv)
{
    
    if (argc < 2)
    {
        cout << "To use the normalizer use the following command:" <<endl;
        cout << "$ normalizer [path input file]" << endl;
        cout << endl;
        cout << "Quitting..." <<endl;
    }
    
    else
    {
        SF_INFO sfinfo;
        
        char* inputFile = argv[ARG_INPUT];
        SNDFILE* inFile = sf_open(inputFile, SFM_READ, &sfinfo);
        
        if (inFile == NULL)
        {
            cout << "Error reading input file" <<endl;
            cout << "Quitting..." <<endl;
        } //NULL detection
    
        int samplerate = sfinfo.samplerate;
        int numChannels = sfinfo.channels;
        long int numFrames = sfinfo.frames;
        long numSeconds = numFrames/samplerate;
        
        float buffer[numChannels * numFrames];
        
        cout << "Samplerate:         " << samplerate << endl;
        cout << "Number of frames:   " << numFrames << endl;
        cout << "Number of channels: " << numChannels << endl;
        cout << "File-lenght:        " << numSeconds << " seconds" << endl;
        cout << endl;

        sf_read_float(inFile, buffer, numFrames);
        
        //Finding the highest amplitude
        
        float peak = 0;
        
        for (int i = 0; i < numFrames*numChannels; i++)
        {
            if (fabs(buffer[i]) > peak)
            {
                peak = fabs(buffer[i]);
            }
        } //peak detection
        
        float raiseValue = (1/peak);
        float peakDB = 20*log10f(peak);
    
        cout << "Old peak amplitude: " << peakDB << "dBFS." << endl;
        cout << endl;
        cout << "Continue normalizing? [y/n]" << endl;
        
        string inputContinue;
        cin >> inputContinue;
        
        if (inputContinue == "n")
        {
            cout << "Quitting..." << endl;
        }
        
        // Normalizing
        
        else if (inputContinue == "y")
        {
            
            cout << "Processing..." << endl;
            cout << endl;
        
            for (int c = 0; c < numFrames*numChannels; c++)
            {
                buffer[c] *= raiseValue;
            }
            
            //Nameing output file
            string outputFile = inputFile;
            unsigned find_ext = outputFile.find_last_of(".");
            string extension = outputFile.substr(find_ext);
            outputFile = outputFile.substr(0,find_ext);
            outputFile = outputFile + "_normalized" + extension;
            
            //Writing outputfile
            SNDFILE* outFile = sf_open(outputFile.c_str(), SFM_WRITE, &sfinfo);
            sf_writef_float(outFile, buffer, numFrames);
            
            cout << "Done." << endl;
            
            sf_close(outFile);
            sf_close(inFile);
            
        } // Normalizing process
    
        
    } //else
    
    return 0;
    
}; //main
