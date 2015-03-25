#include "pixel.h"
#include "bitmap.h"
#include<stdlib.h>

//Colors will be generated for the basic colors like black, grey, blue...
pixel color_black, color_yellow, color_blue, color_red, color_grey, color_white, color_green;

//Funciton is called from create_bitmap(bitmap.c)
void create_colors()
{
	//Defining black color 
	color_black.R=0x00;
	color_black.G=0x00;
	color_black.B=0x00;
	
	//Defining yellow color
	color_yellow.R=0xff;
	color_yellow.G=0xff;
	color_yellow.B=0x00;
	
	//defining gray color
	color_grey.R=0xb8;
	color_grey.G=0xb8;
	color_grey.B=0xb8;

	//Defining white color
	color_white.R=0xff;
	color_white.B=0xff;
	color_white.G=0xff;

	//defining blue color
	color_blue.R=0x00;
	color_blue.G=0x80;
	color_blue.B=0xFF;
	
	//defining color red
	color_red.R=0xFF;
	color_red.G=0x00;
	color_red.B=0x00;
	
	//defining color green
	color_green.R=0x0E;
	color_green.G=0x81;
	color_green.B=0x46;		
}

pixel** get_pixels(int width, int height)
{
	pixel **p;
	p = (pixel**) malloc(sizeof(pixel*)*height);
	int i;
	for(i=0; i<height; ++i)
		p[i]=(pixel*)malloc(sizeof(pixel)*width);
	return p;
}

void set_background(unsigned char R,unsigned char G,unsigned char B, bitmap *image, pixel **p)
{
	int i, j;
	for(i=0; i<image->height; ++i)
	{
		for(j=0; j<image->width; ++j)
		{
			p[i][j].R=R;
			p[i][j].B=B;
			p[i][j].G=G;
		}
	}
}

void set_backgroundc(pixel color,bitmap *image,pixel **p)
{
	int i, j;
	for(i=0; i<image->height; ++i)
	{
		for(j=0; j<image->width; ++j)
		{
			p[i][j]=color;
		}
	}
}

