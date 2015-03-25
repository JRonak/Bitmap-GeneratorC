#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitmap.h"
#include "shapes.h"
int main()
{
//demo code
	char name[]="india.bmp";
	bitmap *image=create_bitmap(500,500,name);
	pixel **p= (pixel**) get_pixels(image->width,image->height);
	set_backgroundc(color_white,image,p);
	drawcirlcec(image,p,250,250,249,color_blue);
	fill_circle(image,p,250,250,249,color_black);
	int i,j;	
	drawlinec(image,p,250,300,250,400,color_blue);
	for(i=0; i<image->height; ++i)
		for(j=0; j<image->width; ++j)
			if((i*j)%20==0)
				p[i][j]=color_black;	
	generate_bitmap(image,p);
	clean(image, p);
}
