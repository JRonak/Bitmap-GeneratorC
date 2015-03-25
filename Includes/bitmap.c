#include "bitmap.h"
//Used for malloc and other functions
#include<stdlib.h>
//Used for FILE io
#include<stdio.h>
//Colors for pixel
#include"pixel.h"
//Creating a bmp header with arguements width and height

bitmap* create_bitmap(int width, int height, char *name)
{
	bitmap *b;
	b=(bitmap*) malloc(sizeof(bitmap));
	create_colors();
	b->name=name;
	//Bitmap height in pixels
	
	b->height=height;
	
	//Bitmap width in pixels 
	
	b->width=width;
	
	//Bitmap signature is 0x4d42, two bytes used here
	
	b->header[0]=MAGIC;
	
	/*Bitmap image file size in bytes
	Header takes 54bytes, number of pixels into bytes per pixel. Padding can be ignored 
	Four Bytes used here*/
	
	b->header[1]=HEADER_SIZE+width*height*BYTE_PIXEL;
	
	//Reserved by bitmap, Four bytes used here 
	
	b->header[2]=ZERO;
	
	/*Pixel manipulation starts after the defining the header of bitmap
	Uses four bytes*/
	
	b->header[3]=START_OFFSET;
	
	/*Bitmap info header always set to 40bytes
	Four bytes used here*/
	
	b->header[4]=BITMAPINFOHEADER;
	
	/*Bitmap width defines the number of pixels in width
	Four bytes used here*/
	
	b->header[5]=width;
	
	/*Bitmap height defines the number of pixels in height
	Four bytes used here*/
	
	b->header[6]=height;
	
	/*Image plane is always set to 1. Number of bits used in bitmap is to 24 (0x18)
	4bytes used here*/
	
	b->header[7]=0x00180001;
	
	//Compression is set to zero, four bytes used here
	
	b->header[8]=ZERO;
	
	//Size of image data is the amount of bytes used by pixels, four bytes here
	
	b->header[9]=width*height*BYTE_PIXEL;
	
	//Rest are optional. Set to Zer0
	
	b->header[10]=2835;
	b->header[11]=2835;
	b->header[12]=ZERO;
	b->header[13]=ZERO;	
	//End of header definition of 24bit bitmap
	
	return b;
}
/*To generate a plane background image of given size and specific color
*/
void generate_color(bitmap *image, unsigned char R, unsigned char G, unsigned char B)
{
	int i, j, w,h;
	w=image->width;
	h=image->height;
	//Padding for alternate pixels written in bitmap
	unsigned char pad[3]={0,0,0};
	FILE *file=fopen(image->name,"wb");
	//writing the headers of the bitmap
	fwrite((char *)image->header+2,1,54,file);
	for(i=0; i<w; ++i)
	{
		for(j=0; j<h; ++j)
		{
			fwrite(&B,1,1,file);
			fwrite(&G,1,1,file);
			fwrite(&R,1,1,file);
			fwrite(pad,1,w%4,file);
		}
	}
	fclose(file);
}

void generate_plane(bitmap *image, pixel color)
{
	int i, j, w,h;
	w=image->width;
	h=image->height;
	//Padding for alternate pixels written in bitmap
	unsigned char pad[]={0,0,0};
	FILE *file=fopen(image->name,"wb");
	//writing the headers of the bitmap
	fwrite((char *)image->header+2,1,54,file);
	for(i=0; i<h; ++i)
	{
		for(j=0; j<w; ++j)
		{
			fwrite(&color.B,1,1,file);
			fwrite(&color.G,1,1,file);
			fwrite(&color.R,1,1,file);	
		}
		fwrite(pad,w%4,1,file);
	}
	fclose(file);
}

void generate_bitmap(bitmap *image, pixel **p)
{
	int w, h, t;
	w=image->width;
	h=image->height;
	int i,j,temp;
	FILE *file=fopen(image->name,"wb");
	fwrite((char *)image->header+2,1,54,file);
	unsigned char pad[]={0,0,0};
	for(i=0; i<h; ++i)
	{
		for(j=0; j<w; ++j)
		{
			fwrite(&p[i][j].B,1,1,file);
			fwrite(&p[i][j].G,1,1,file);
			fwrite(&p[i][j].R,1,1,file);
		}
		fwrite(pad,w%4,1,file);
	}
	fclose(file);
}

void clean(bitmap *image, pixel **p)
{
	int i=image->width,j=0;
	while(j!=i)
	{
		free(p[j]);
		j++;
	}	
	free(p);
	free(image);
}
