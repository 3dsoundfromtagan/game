#include "intarray.h"
#include <cstdlib>

IntArray::IntArray(int s = 1) {
	arr = new int[s];
	size = s;
}

IntArray::IntArray(const IntArray& right){
	arr = new int[right.get_size()];
	size = right.get_size();
	for(int i = 0; i < size; ++i) 
		arr[i] = right.arr[i];
}

IntArray::~IntArray(){
	delete [] arr;
}

int& IntArray::operator[] (int index) {
	if(index < 0 || index >= size) {
		cerr << "Out of range!" << endl;
		exit(-1);
	}
	return arr[index];
}

IntArray& IntArray::operator=(const IntArray& right){
	if(this == &right)
		return *this;
	delete [] arr;

	this->size = right.get_size();
	this->arr = new int[right.get_size()];
	
	for(int i = 0; i < size; ++i)
		this->arr[i] = right.arr[i];
	return *this;
}

int IntArray::get_size() const {
	return this->size;
}

ostream& operator << (ostream& os,  IntArray& a){
	os << "[";
	for(int i = 0; i < a.get_size(); ++i) 
		os << a[i] << " ";

	os << "]";
	return os;
}
