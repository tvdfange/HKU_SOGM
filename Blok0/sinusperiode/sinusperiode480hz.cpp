#include <iostream>
#include <math.h>

// To plot in GNUPLOT :
// gnuplot --persist -e 'plot "[file].dat" u 1:2'

using namespace std;
 
int main ()
{

	
  	int sampleRate = 48000;
  	int frequency = 480;


  	int samples = sampleRate / frequency;

   	// for loop execution
   		for( double i = 0; i < samples; i++ )
   		{
   			double pi = 3.14159265358979323846;
   			double w = pi * 2 * frequency;
   			double x = (i / sampleRate);
       		double y = sin(w*x); 

       		cout << i << " " << y << endl;
       		
   }
 
   return 0;
}