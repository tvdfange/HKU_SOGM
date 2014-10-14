#include <iostream>

using namespace std;
 


void printArray(string array[], int l){

	   for( int i = 0; i < l; i++ ){
  
      cout << i << " " << array[i] << endl;
   		
      }

}
 


int main()
{
  int length=4;

  string array[] = {"A", "List", "Of", "Stings"};

  printArray(array,length);

 
return 0;

}