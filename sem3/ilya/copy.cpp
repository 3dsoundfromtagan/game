#include <iostream>

using namespace std;

class A {
	int *p;
public:
	A(int);
	A(const A&);
	~A();
	
	void set_p(int n) { *p = n; };
	A& operator= (const A&); 
	friend ostream& operator<< (ostream&, const A&);
};

A::A(int n = 0) {
	cout << "in constructor..." << endl;
	p = new int;
	*p = n;
}

A::A(const A& right) {
	cout << "in copy constructor..." << endl;
	p = new int;
	*(this->p) = *right.p;
}

A::~A(){
	cout << "in destructor..." << endl;
	delete p;
}

A& A::operator=(const A& right) {
	if(this == &right)
		return *this;
	*(this->p) = *right.p;
	return *this;
}

ostream& operator<< (ostream &os, const A& a){
	os << *(a.p);
	return os;
}

int main() {
	A b(100);
	A a = b;
	//b = a; 
	a.set_p(10000000);
	cout << "a = " << a << ", b = " << b << endl; 
	
	
	/*int m =100;
	const int N = 1000;
	const double PI = 3.1416;
	
	const int* p = &m;
	//*p = 101;
	//p = 0;
	int * const p1 = &m;
	//*p1 = 101;
	//p1 = 0;
	const int * const p2 = &m;
	//*p2 = 101;
	//p2 = 0;*/
	
	return 0;
}

