#include <iostream>
#include <cstdlib>

using namespace std;

class Point {
private:
	double x, y;
public:
		Point();
		Point(double x, double y);
		Point(char* sx, char* sy);
		
		double get_x() const;
		double get_y() const;
		
		void set_x(double x);
		void set_y(double y);
		
		Point operator*(double h) const;
};

Point::Point (): x(0), y(0) {
	/*_x = 0.0;
	_y = 0.0;*/
}

Point::Point(double x, double y): x(x), y(y) {
	/*_x = x;
	_y = y;*/
}

Point::Point(char* sx, char* sy): x(atof(sx)), y(atof(sy)) {
	/*_x = atof(sx);
	_y = atof(sy);*/
}

double Point::get_x() const {
	return x;
}

double Point::get_y() const {
	return y;
}

void Point::set_x(double x) {
	this->x = x;
}

void Point::set_y(double y) {
	this->y = y;
}

Point Point::operator*(double h) const{
	Point c(0.0,0.0);
	c.set_x(h*this->get_x());
	c.set_y(h*this->get_y());
	
	return c;
}

int main() {
	Point a;
	Point b(45.0, 37.2);
	Point c("56.21", "12.90");
	double h = 100.0;
	
	//c = a - b;
	c = b*h;
	
	cout << "c._x = " << c.get_x() << ": c._y = " << c.get_y() << endl;
	
	/*Point arr[3] = {
		Point();
		Point(1.0, 2.0);
		Point("12.3", "2131.1");
	};
	
	c = a + b;
	
	arr[0].set_x(9.6);
	arr[0].set_y(78.1);
	
	Point *p0 = &a;
	cout << "a.get_x() = " << p0->get_x() << endl;
	
	Point *p1 = new Point;
	Point *p2 = new Point(14.5, 78.1);
	
	delete [] p1;
	delete p2;*/
	
	return 0;
}
