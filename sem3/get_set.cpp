#include <iostream>
#include <cstdlib>
using namespace std;

class Vector {
	private:
		double x, y, z;
		
		void set_x (double _x) {
			x = _x;
		}
		
		void set_y (double _y) {
			y = _y;
		}
		
		void set_z (double _z) {
			z = _z;
		}
		
		double get_x () {
			return x;
		}
		
		double get_y () {
			return y;
		}
		
		double get_z () {
			return z;
		}
	
	public:
		Vector (double _x, double _y, double _z) {
			set_x(_x);
			set_y(_y);
			set_z(_z);
		}
		
		//~Vector();
		
		void print (){
			std:: cout << x << " " << y << " " << z << std:: endl;
		}
		
		Vector sum(Vector B) {
			return Vector(x + B.get_x(), y + B.get_y(), z + B.get_z());
		}
		
		
		
		int operator *(Vector& B) {
			return (x * B.get_x() + y * B.get_y() + z * B.get_z());
		}
		
		/*Vector operator *(int a) {
			return Vector(x * a,  y * a, z * a);
		}*/
		
		Vector operator [](Vector& B) {
			return Vector(y * B.get_z() - z * B.get_y(), z * B.get_x() - x * B.get_z(), x * B.get_y() - y * B.get_x());
		}
		
		friend ostream& operator<<(ostream&, Vector&);
		friend Vector operator+ (Vector& A, Vector& B);
		friend Vector operator * (int a, Vector& A);
		friend Vector operator * (Vector& A, int a);
};

Vector operator +(Vector&A, Vector& B) {
	return Vector(A.x + B.x, A.y + B.y, A.z + B.z);
}

Vector operator* (int a, Vector& A) {
	return Vector(A.x * a,  A.y * a, A.z * a);
}

Vector operator* (Vector& A, int a) {
	return Vector(A.x * a,  A.y * a, A.z * a);
}

ostream& operator << (ostream& os,  Vector& A){
	os << A.x << " " << A.y << " " << A.z << endl;
	return os;
}

int main() {
	Vector A = Vector (3, 2, 1); 
	Vector B = Vector (0, 2, 3); 
	Vector sp = Vector (0, 0, 0); 
	//Vector C = (*A) + (*B);
	Vector C = A[B];
	A.print();
	//int sp = A * B;
	sp = A + B;
	cout << sp;
	
	sp = 2 * B;
	cout << sp;
	
	cout << A;
	//std:: cout << A.get_x() << std:: endl;
	//delete A;
	return 0;
}
