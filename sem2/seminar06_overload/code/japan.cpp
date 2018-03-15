#include "image.h"

int main()
{
	Pixel p;
	p.red = 255;
	p.green = 0;
	p.blue = 0;
	
	Image j = Image(6000, 4000);
	j.reverse_colors();
	
	j.draw_circle(3000, 2000, 1000, p);
	
	j.write("japan.ppm");
	return 0;
}
