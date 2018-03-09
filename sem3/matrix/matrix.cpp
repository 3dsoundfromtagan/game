#include "matrix.h"
#include <cstdlib>

using namespace std;

Matrix:: Matrix(int _size = 1) {
	arr = new int[_size * _size];
	size = _size;
	cout << "..in constructor.." << endl;
}

/*Matrix:: Matrix(const Matrix& src) {
	arr = new int[src.get_size()];
	size = src.get_size();
	for(int i = 0; i < size; ++i) 
		arr[i] = src.arr[i];
}*/

Matrix:: ~Matrix () {
	delete [] arr;
	cout << "..in destructor.." << endl;
}

int Matrix:: get_size() {
	return size;
}

int& Matrix:: operator[](int n){
	if ((n >= size * size) || (n < 0)) {
		cerr << "Out of range!" << endl;
		exit(-1);
	}
	return arr[n];
}
ostream& operator<<(ostream&, Matrix& A) {
	for (int i = 0; i < A.size; ++i) {
		for (int j = 0; j < A.size; ++j) {
			if (j != A.size - 1) {
				cout << A.arr[i * A.size + j] << "\t";
			}
			else {
				cout << A.arr[i * A.size + j] << endl;
			}
		}
	}
}

Matrix& Matrix:: operator+(Matrix& right){
	if (this->size != right.size) {
		cerr << "Out of range!" << endl;
		exit(-1);
	}
	for (int i = 0; i < this->size; ++i) {
		for (int j = 0; j < this->size; ++j) {
			this->arr[i * this->size + j] += right.arr[i * this->size + j];
		}
	}
	return *this;
}

