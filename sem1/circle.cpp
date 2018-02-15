#include <iostream>
#include "circle.h"

int main ()
{
	Circle c1 = Circle(10, 20, 10);
	Circle c2 = Circle(5, 5, 10);
	
	if (c1.is_intersect(c2))
	{
		std:: cout << "Circles are intersect";
	}
	else
	{
		std:: cout << "Circles aren't intersect";
	}
	return 0;
}


