#include <iostream>
#include "amp.h"
#include "tremelo.h"
#include "audio_io.h"
#include "distortion.h"

using namespace std;

Amplifier* state;

int main(int argc, char* argv[])
{
    //user input
    
    if (argc < 3){
        cout << "This is guitarFX" << endl;
        cout << "To use this programm, we are gonna need some arguments" << endl;
        cout << endl;
        cout << "Run like this:" << endl;
        cout << "$ guitarFX [effect] [level]" << endl;
        cout << endl;
        cout << "You can use the following effects:" << endl;
        cout << "guitarFX amplifier [0.0 - 1.0]" << endl;
        cout << "guitarFX tremolo [0.0 - 10.0]" << endl;
        cout << "guitarFX distortion [0.0 - 100.0]" << endl;
        cout << endl;
        cout << "Quitting..." << endl;
        return 0;
        
    }
    
    else if (argc > 2){
        if (strcmp(argv[1], "amplifier") == 0){
            
            state = new Amplifier();
            
            }
        else if (strcmp(argv[1], "tremolo") == 0){
            
            state = new Tremolo();
            
            }
        else if (strcmp(argv[1], "distortion") == 0){
            
            state = new Distortion();
            
            }
    
    //user argument
    state->setLevel(atof(argv[2]));
    
    //audio initializing
    state->startAudioCallback();
    state->showLevel();
    state->info();
    cout << endl;
    cout << "To quit press cntl+c" << endl;
   
    //audio processing
    while (true){
        state->readBuffer();
        state->process();
        state->writeBuffer();
    }
  }

} // main()

