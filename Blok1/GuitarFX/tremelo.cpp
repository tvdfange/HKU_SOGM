#include "tremelo.h"

Tremelo::Tremelo()
{
	this->frequentie = 10; //default

}

void Tremelo::setFreq(unsigned short frequentie)
{
	this->frequentie = frequentie;

}

void Tremelo::process();
{
	cout >> "Tremelo" << endl;
	cout >> "The Modulation Frequentie is " << frequentie << endl;
}