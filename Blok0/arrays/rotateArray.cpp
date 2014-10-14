#include <iostream>

using namespace std;
 


void rotateArray(int array[], int l){

	int x=array[0];
	  
    for( int i = 0; i < l; i++ ){
  		
  		
  		array[i]=array[i+1];
  		array[l]=x;

  		cout << array[i] << endl;
      }

 

}
 


int main()
{

  int array1[] = {1, 2, 3, 4, 5, 6, 7};

  rotateArray(array1, 7);

  cout << endl;

  int array2[] = {6, 2, 13, 4, 7, 15, 1, 9};

  rotateArray(array2, 8);

 
return 0;

}