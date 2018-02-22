#include <iostream>
#include <stdlib.h>
//vector of int
class Vector 
{
	private:
		//the num of elements
		unsigned int N;
		
		
	
	public:
		//constructor
		Vector (unsigned int N0)
		{
			arr = (int*)malloc(N0 * sizeof(int));
			N = N0;
		}
		//destructor
		~Vector()
		{
			free(arr);
		}
		int* arr;
		
		Vector operator[] (unsigned int i)
		{
			 
		}
		
};







int main ()
{
	Vector a = Vector(5);
	std:: cout << a.arr[1];
	return 0;
}
