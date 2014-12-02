#include <iostream>
#include "amp.h"
#include "tremelo.h"

using namespace std;


int main()
{
Amplifier amp;
Tremelo trem;

  amp.showLevel();
  trem.process();

} // main()