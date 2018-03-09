#include <iostream>

using namespace std;

class IntArray {
private:
	int size;
	int* arr;
public:
	IntArray(int);
	IntArray(const IntArray&);
	~IntArray();
	
	int& operator[](int);
	IntArray& operator=(const IntArray&);

	int get_size() const;

	friend ostream& operator<<(ostream&, IntArray&);
};
