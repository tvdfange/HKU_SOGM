#include <iostream>

using namespace std;



int optellen(int a, int b)
{
	return a + b;
}

int main(){


		int x1=5;
		int y1=7;
		int x2=6;
		int	y2=1;

		int som1=optellen(x1,y1);
		int som2=optellen(x2,y2);

		cout << "Som 1: " << som1 << endl;
		cout << "Som 2: " << som2 << endl;

	return 0;
}