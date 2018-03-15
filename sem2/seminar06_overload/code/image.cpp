#include <stdio.h>
#include <stdlib.h>
#include "image.h"

Image::Image()
{
    data = NULL;
}

Image::Image(const char* filename)
{
    data = NULL;
    read(filename);
}

Image:: Image(int x0, int y0)
{
	x = x0;
	y = y0;
	data = (Pixel*)(malloc(3 * x0 * y0));
	
}

Image::~Image()
{
    if (data)
        free(data);
}


void Image::read(const char *filename)
{
    if (data != NULL)
    {
        free(data);
    }
    char buff[16];

    FILE *fp;
    int c, rgb_comp_color;
    //open PPM file for reading
    fp = fopen(filename, "rb");
    if (!fp) 
    {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    //read image format
    if (!fgets(buff, sizeof(buff), fp)) 
    {
        perror(filename);
        exit(1);
    }

    //check the image format
    if (buff[0] != 'P' || buff[1] != '6') 
    {
         fprintf(stderr, "Invalid image format (must be 'P6')\n");
         exit(1);
    }

    //check for comments
    c = getc(fp);
    while (c == '#') 
    {
        while (getc(fp) != '\n') ;
            c = getc(fp);
    }

    ungetc(c, fp);
    //read image size information
    if (fscanf(fp, "%d %d", &x, &y) != 2) 
    {
         fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
         exit(1);
    }

    //read rgb component
    if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
         fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
         exit(1);
    }

    //check rgb component depth
    if (rgb_comp_color!= 255) {
         fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
         exit(1);
    }

    while (fgetc(fp) != '\n') ;
    //memory allocation for pixel data
    data = (Pixel*)malloc(x * y * sizeof(Pixel));

    //read pixel data from file
    if (fread(data, 3 * x, y, fp) != y) 
    {
         fprintf(stderr, "Error loading image '%s'\n", filename);
         exit(1);
    }

    fclose(fp);
}

void Image::write(const char *filename)
{
    FILE *fp;
    //open file for output
    fp = fopen(filename, "wb");
    if (!fp) 
    {
         fprintf(stderr, "Unable to open file '%s'\n", filename);
         exit(1);
    }

    //write the header file
    //image format
    fprintf(fp, "P6\n");

    //image size
    fprintf(fp, "%d %d\n", x, y);

    // rgb component depth
    fprintf(fp, "%d\n", 255);

    // pixel data
    fwrite(data, 3 * x, y, fp);
    fclose(fp);
}


void Image::reverse_colors()
{
    int i;
    if(data)
    {
         for(i=0; i< x*y; i++)
         {
              data[i].red = 255 - data[i].red;
              data[i].green = 255 - data[i].green;
              data[i].blue = 255 - data[i].blue;
         }
    }
}

void Image::flip_vertically()
{
    int i, j;
    Pixel tmp;
    for (i = 0; i < x / 2; i++)
    {
		for (j = 0; j < y; j++)
		{
			tmp.red = data[x * j + i].red;
			tmp.green = data[x * j + i].green;
			tmp.blue = data[x * j + i].blue;
			
			data[x * j + i].red = data[x * j + (x - i + 1)].red;
			data[x * j + i].green = data[x * j + (x - i + 1)].green;
			data[x * j + i].blue = data[x * j + (x - i + 1)].blue;
			
			data[x * j + (x - i + 1)].red = tmp.red;
			data[x * j + (x - i + 1)].green = tmp.green;
			data[x * j + (x - i + 1)].blue = tmp.blue;
		}
	}
}

void Image:: set_pixel(int n, int m, Pixel p)
{
	data[x * m + n].red = p.red;
	data[x * m + n].green = p.green;
	data[x * m + n].blue = p.blue;
}

void Image:: set_pixel(int n, int m, unsigned char r, unsigned char g, unsigned char b)
{
	data[x * m + n].red = r;
	data[x * m + n].green = g;
	data[x * m + n].blue = b;
}

void Image:: draw_circle(int n, int m, int r, Pixel p)
{
	int i, j;
    for (i = 0; i < x; i++)
    {
		for (j = 0; j < y; j++)
		{
			if ((n - i) * (n - i)  + (m - j) * (m - j) <= r * r)
			{
				set_pixel(i, j, p);
			}
		}
	}
}
