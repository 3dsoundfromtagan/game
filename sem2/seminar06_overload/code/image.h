#include <stdio.h>
#include <stdlib.h>

struct Pixel
{
     unsigned char red, green, blue;
};

class Image
{
	private:
		 int x, y;
		 Pixel* data;
	public:
		Image();
		Image(const char* filename);
		//Makes black image x0*y0
		Image(int x0, int y0);
		~Image();

		void set_pixel(int n, int m, Pixel p);
		void set_pixel(int n, int m, unsigned char r, unsigned char g, unsigned char b);

		void read(const char* filename);
		void write(const char* filename);
		
		void reverse_colors(); 
		void flip_vertically();
		void draw_circle(int n, int m, int r, Pixel p);
};
