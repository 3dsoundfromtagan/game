#include <iostream>

class Complex 
{
	private: 
		double re, im;
		
	public:
		Complex(double re0, double im0);
		void display()
		{
			std:: cout << re << " " << im << std:: endl;
		}  
		Complex operator+ (Complex &tmp)
		{
			return Complex(re + tmp.re, im + tmp.im); 
		}
		
		void operator<< (Complex &tmp)
		{
			std:: cout << tmp.re << " " << tmp.im << std:: endl;
		}
	
};

int main()
{
	Complex a = Complex( 1.2, 3.4 );  
	Complex b = Complex( 5.6, 7.8 );  
	Complex c = Complex( 0.0, 0.0 );  
	c = a + b;  
	//c.display();
	Complex:: cout << c;
	return 0;
}

Complex:: Complex(double re0, double im0)
{
	re = re0;
	im = im0;
}

