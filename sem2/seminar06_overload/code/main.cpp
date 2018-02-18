#include "image.h"

int main()
{
	Pixel p;
	p.red = 255;
	p.green = 0;
	p.blue = 0;
    Image tmp = Image(10, 10);
    tmp.reverse_colors();
    tmp.set_pixel(6, 4, p);
    tmp.set_pixel(6, 1, 0, 250, 100);
    tmp.write("img.ppm");
    
}
