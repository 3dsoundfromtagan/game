#include "matrix.h"
#define ORDER 10

using namespace std;

int main() {
	Matrix A = Matrix(ORDER);
	Matrix B = Matrix(ORDER);
	Matrix C = Matrix(ORDER);
	//cout << A.get_size() << endl;
	for (int i = 0; i < ORDER * ORDER; ++i) {
		 A[i] = i;
		 B[i] = 10 - i;
	}
	//A = A + B;
	cout << A;
	cout << endl;
	cout << B;
	cout << endl;
	C = A + B;
	cout << C;
	return 0;
}
