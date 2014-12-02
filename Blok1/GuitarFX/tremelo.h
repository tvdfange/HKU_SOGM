#pragma once

#include <iostream>

using namespace std;

class Tremelo
{
public:
	Tremelo(); //constructor
	void setFreq(unsigned short frequentie);
	void process();

private:
	unsigned short frequentie;
	
}