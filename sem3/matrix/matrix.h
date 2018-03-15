#include <iostream>

using namespace std;

class Matrix {
	private:
		unsigned int size;
		int* arr;
		
	public:
		Matrix(int);
		//Matrix(const Matrix&);
		~Matrix();
		
		int& operator[](int);
		//Matrix& operator=(const IntArray&);*/

		int get_size();

		friend ostream& operator<<(ostream&, Matrix&);
		Matrix& operator+(Matrix&);
};
