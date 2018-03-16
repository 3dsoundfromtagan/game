#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

/*Реализованы как перегрузка оператора cout, так и дружественная функция print*/

class Complex 
{
	private: 
		double re, im;
		
	public:
		Complex ();
		Complex (double _re) {
			set_re(_re);
		}
		Complex (double _re, double _im) {
			set_re(_re);
			set_im(_im);
		}
		
		~Complex() {}
		
		double get_re() {
			return re;
		}
		
		double get_im() {
			return im;
		}
		
		void set_re (double _re) {
			re = _re;
		}
		
		void set_im (double _im) {
			im = _im;
		}
		
		void display()
		{
			if (get_im() >= 0) {
				cout << get_re() << " + " << get_im() << "i" << endl;
			}
			else {
				cout << get_re() << " - " << abs(get_im()) << "i" << endl;
			}
		}  
		
		friend double norm (Complex& src);								//Модуль комплексного числа
		friend Complex operator +(Complex& a, Complex& b);
		friend Complex operator +(double& a, Complex& b);
		friend Complex operator +(Complex& a, double& b);
		
		friend Complex operator -(Complex& a, Complex& b);
		friend Complex operator -(double& a, Complex& b);
		friend Complex operator -(Complex& a, double& b);
		friend Complex operator -(Complex& a);
		
		friend Complex operator *(Complex& a, Complex& b);
		friend Complex operator *(double& a, Complex& b);
		friend Complex operator *(Complex& a, double& b);
		
		friend Complex operator /(Complex& a, Complex& b);
		friend Complex operator /(double& a, Complex& b);
		friend Complex operator /(Complex& a, double& b);
		
		friend int operator ==(Complex& a, Complex& b);
		friend ostream& operator<<(ostream&, Complex&);
		friend void display (Complex&);
		
};

int main()
{
	Complex a = Complex( 1, 3 );  
	Complex b = Complex( -5, -2 );
	Complex c = Complex( 0.0, 0.0 );  
	cout << b;
	display(c);
	
	c = a + b;
	display(c);
	
	c = a - b;
	display(c);
	
	c = a * b;
	cout << c;
	
	c = -a;
	display(c);
	
	c = a / b;
	display(c);
	
	double x = 5;
	c = a - x;
	display(c);
	
	c = x / a;
	display(c);
	
	//Проверка комплексных чисел на равенство
	int eq = a == b;
	cout << eq << endl;;
	return 0;
}

double norm (Complex& src) {
	return sqrt(src.get_re() * src.get_re() + src.get_im() * src.get_im());
}

ostream& operator << (ostream& os,  Complex& src){
	if (src.get_im() >= 0) {
		os << src.get_re() << " + " << src.get_im() << "i" << endl;
	}
	else {
		os << src.get_re() << " - " << abs(src.get_im()) << "i" << endl;
	}
	return os;
}

Complex operator +(Complex& A, Complex& B) {
	return Complex(A.get_re() + B.get_re(), A.get_im() + B.get_im());
}

Complex operator +(double& A, Complex& B) {
	return Complex(A + B.get_re(), B.get_im());
}

Complex operator +(Complex& A, double& B) {
	return Complex(A.get_re() + B, A.get_im());
}

Complex operator -(Complex& A, Complex& B) {
	return Complex(A.get_re() - B.get_re(), A.get_im() - B.get_im());
}

Complex operator -(double& A, Complex& B) {
	return Complex(A - B.get_re(), - B.get_im());
}

Complex operator -(Complex& A, double& B) {
	return Complex(A.get_re() - B, A.get_im());
}

Complex operator -(Complex& A) {
	return Complex(-A.get_re(), -A.get_im());
}

Complex operator *(Complex& A, Complex& B) {
	return Complex(A.get_re() * B.get_re() - A.get_im() * B.get_im(), A.get_re() * B.get_im() + A.get_im() * B.get_re());
}

Complex operator *(double& a, Complex& B) {
	return Complex(a * B.get_re(), a * B.get_im());
}

Complex operator *(Complex& a, double& b) {
	return Complex(b * a.get_re(), b * a.get_im());
}

Complex operator /(Complex& A, Complex& B) {
	if (B.get_re() == 0 && B.get_im() == 0) {
		cerr << "div by zero!" << endl;
		exit(-1);
	}
	
	double my_re = (A.get_re() * B.get_re() + A.get_im() * B.get_im()) / (B.get_re() * B.get_re() + B.get_im() * B.get_im());
	double my_im = (A.get_im() * B.get_re() - A.get_re() * B.get_im()) / (B.get_re() * B.get_re() + B.get_im() * B.get_im());
	return Complex(my_re, my_im);
}

Complex operator /(Complex& a, double& b) {
	return Complex(a.get_re() / b, a.get_im() / b);
}

Complex operator /(double& a, Complex& b) {
	Complex tmp = Complex(a, 0);
	return tmp / b;
}

int operator ==(Complex& A, Complex& B) {
	return (A.get_re() == B.get_re()) && (A.get_im() == B.get_im());
}

void display(Complex& src)
{
	if (src.get_im() >= 0) {
		cout << src.get_re() << " + " << src.get_im() << "i" << endl;
	}
	else {
		cout << src.get_re() << " - " << abs(src.get_im()) << "i" << endl;
	}
}
