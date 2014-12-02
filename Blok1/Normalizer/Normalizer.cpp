#include <iostream>
#include <stdio.h>
#include <sndfile.h>
#include <math.h>
#include <string>
#include <libgen.h>

using namespace std;

int main(int argc, char* argv[]){

cout << "Hello! Soon, your audiofile will be normalized. Which file would you  you like to use? " << endl;

	if(argc == 1){
		cout << "No Path.." << endl;
	}

	else{
		
	
		char* inFilePath = argv[1];
		SF_INFO info;
		SNDFILE* inFile = sf_open(inFilePath, SFM_READ, &sfinfo);

		int channels = sfinfo.channels
		int	frames = sfinfo.frames
		int samplerate = sfinfo.samplerate

		cout << "Filetpath:		" << inFilePath << endl;
		cout << "Frames:		" << frames << endl;
		cout << "Samplerate:	" << samplerate << endl;
		cout << "Channels:		" << channels << endl;

		cout << "Nomalizing..." << endl;
		cout << endl;

		//Peak

		float buffer[1000000000];
		double tempPeak = 0.0;

		for(int i = 0; i < frames; i++){
			sf_readf_float(inFile, buffer, 1);

			for (int j = 0; j < bufferSize; j++){
        
            	if(fabs(buffer[j]) > tempPeak){
            
                tempPeak = fabs(buffer[j]);
            	} // for j

        	} // for i

		
   		} // else



	}

} // main