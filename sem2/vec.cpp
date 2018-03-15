#include <iostream>
#include <stdlib.h>
//vector of int
class Vector 
{
	private:
		//the num of elements
		int* arr;
		unsigned int N;
		int get (int i)
		{
			return arr[i];
		}
	
	public:
		//int* arr;
		//constructor
		int get_size() const;
		Vector (unsigned int N0)
		{
			arr = (int*)malloc(sizeof(int) * N0);
			N = N0;
		}
		//destructor
		~Vector()
		{
			free(arr);
		}
		
		int operator[] (unsigned int i)
		{
			if ((i >= 0) && (i < N)){
				return get(i);
			}
			else {
				std:: cerr << "Out of range!" << std:: endl;
				exit(-1);
			}
		}
		
};



int main ()
{
	Vector a = Vector(5);
	std:: cout << a[5464];
	return 0;
}
