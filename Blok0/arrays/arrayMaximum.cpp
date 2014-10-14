#include <iostream>

using namespace std;
 


void printArray(int array[], int l){

    
    int maximum=0;
	  
    for( int i = 0; i < l; i++ ){
  
      if(array[i]>maximum)
        maximum=array[i];

      }

  cout << "The hightst number in the array is: " << maximum << endl;

}
 


int main()
{

  int array1[] = {1, 2, 3, 4, 5, 6, 7};

  printArray(array1, 7);

  int array2[] = {6, 2, 13, 4, 7, 15, 1, 9};

  printArray(array2, 8);

 
return 0;

}