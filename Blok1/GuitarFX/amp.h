#pragma once

#include <iostream>

using namespace std;

class Amplifier
{
public:
  Amplifier(); // constructor
  void showLevel();
  float setLevel();

private:
  long level;
};