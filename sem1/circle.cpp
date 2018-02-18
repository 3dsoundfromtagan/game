//Friendly function
#include <iostream>
#include "circle.h"


int main ()
{
	Circle c1 = Circle(10, 20, 4);
	Circle c2 = Circle(5, 5, 6);
	
	if (c1.is_intersect(c2))
	{
		std:: cout << "Circles are intersect\n";
	}
	else
	{
		std:: cout << "Circles aren't intersect\n";
	}
	return 0;
}


