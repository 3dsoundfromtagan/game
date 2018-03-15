#include "image.h"

int main()
{
	Pixel p;
	p.red = 255;
	p.green = 0;
	p.blue = 0;
    Image tmp;
    tmp.read("img5.ppm");
    tmp.reverse_colors();
   /* tmp.set_pixel(6, 4, p);
    tmp.set_pixel(6, 7, 0, 250, 100);*/
    tmp.flip_vertically();
    
    tmp.write("img.ppm");
    
}
