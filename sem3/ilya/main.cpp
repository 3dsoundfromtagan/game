#include "intarray.h"
#include <iostream>

using namespace std;

int main() {
	IntArray a1(10), a2(10), a3(20);
	
	for(int i = 0; i < 10; ++i){
		a1[i] = i;
	}
	a2 = a1;
	cout << a1 << endl << a2 << endl;
	IntArray a4 = a1;
	cout << a4 << endl;
	
	return 0;
}
