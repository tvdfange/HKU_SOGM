#include "amp.h"


Amplifier::Amplifier()
{
  this->level=5; // default
}


void Amplifier::showLevel()
{
  cout << "Amplifier level: " << level << endl;
}

void Amplifier::setLevel(float level)
{
	this->level = level;
}

