// Thomas van der Fange, 2014 HKU

#include <iostream>

using namespace std;


int main()
{
char letter = 97;
char *letterpointer;

  cout << "Inhoud van de variabele letter: ";
  cout << letter << endl;

  letterpointer = &letter;
  cout << "Inhoud van de pointer letterpointer: ";
  cout << (unsigned long) letterpointer << endl;

  cout << "Inhoud van waar de pointer letterpointer naar wijst: ";
  cout << *letterpointer << endl;

  *letterpointer = 'b';
  cout << "De variabele letter heeft via letterpointer een nieuwe waarde gekregen: ";
  cout << *letterpointer << endl;

  cout << "Inhoud van de variabele letter: ";
  cout << letter << endl;
  cout << endl;

  // OEFENINGEN
  unsigned short year = 2013;
  unsigned short *yearpointer;

  yearpointer = &year;
  cout << "Inhoud van de variabele year: ";
  cout << year << endl;
  cout << "Inhoud van de pointer yearpointer: ";
  cout << (unsigned long) yearpointer << endl;
  cout << "Inhoud van waar de pointer yearpointer naar wijst: ";
  cout << *yearpointer << endl;
  cout << endl;

  // geef year via de pointer een nieuwe waarde
  *yearpointer = 1999;
  cout << "Inhoud van de variabele year: ";
  cout << *yearpointer << endl;
  cout << endl;

  // maak nog een pointer genaamd anotheryearpointer en laat deze ook naar
  // year wijzen
  
   unsigned short *anotheryearpointer;
   anotheryearpointer = yearpointer;

  cout << "Inhoud van de pointer anotheryearpointer: ";
  cout << anotheryearpointer << endl;
  cout << "Inhoud van waar de pointer anotheryearpointer naar wijst: ";
  cout << *anotheryearpointer << endl;

  // geef year via de pointer een nieuwe waarde
  *anotheryearpointer = 1500;
  cout << "Inhoud van de variabele year: ";
  cout << year << endl;
  cout << "Inhoud van waar de pointer yearpointer naar wijst: ";
  cout << *anotheryearpointer << endl;

} // main()
