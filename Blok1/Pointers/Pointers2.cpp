/*
Schrijf een klein C++ programma dat enkele eigenschappen van pointers en scope laat zien, zoals:
- 	via een pointer benaderen van een variabele (lezen en schrijven)
- 	doorgeven van een variabele aan een functie "by value" en via een pointer, 
	met als doel te laten zien dat in het ene geval een kopie gemaakt wordt en 
	in het andere geval met de originele variabele gewerkt wordt

	(cout'jes heb ik geleend van Nino, thx Nino)

*/

#include <iostream>

using namespace std;

int byValue(int gainVal) {

	gainVal = gainVal * 2;

	return gainVal;

} // byValue

int byPointer(int* gainPointer) {

	*gainPointer = *gainPointer * 10;

	return *gainPointer; 

} //byPointer

int main() {

	int gainInit = 5;


	int *gainInitPointer = &gainInit;

  cout << gainInit << " is de waarde van de variabele" << endl;
  cout << byValue(gainInit) << " is de uitkomst van de byValue-functie" << endl;
  cout << gainInit << " is de waarde van de variabele na de byValue-functie" << endl;
  cout << *gainInitPointer << " is de waarde van de variabele via de pointer" << endl;
  *gainInitPointer = gainInit + 3;
  cout << gainInit << " is de waarde van de variabele na het aanpassen via de pointer" << endl;
  cout << byPointer(gainInitPointer) << " is de uitkomst van een functie met een pointer" << endl;
  cout << gainInit << " is de waarde van de variabele na de pointerfunctie" << endl;

}