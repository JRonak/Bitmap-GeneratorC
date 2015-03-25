#ifndef BITMAP_H

#define BITMAP_H

//Bitmap header macros
#define MAGIC 0x4d420000
#define HEADER_SIZE 54
#define ZERO 0
#define START_OFFSET 54
#define BITMAPINFOHEADER 40
#define PLANE 1
#define BYTE_PIXEL 3

//Pixel is represeneted by RGB, struct below is used to color each pixel
typedef struct pixel
{
	//Red pixel value
	unsigned char R;
	
	//Green pixel value
	unsigned char G;
	
	//Blue pixel value
	unsigned char B;
}pixel;

extern pixel color_black, color_yellow, color_blue, color_red, color_grey, color_white, color_green;
//Bitmap Struct
typedef struct bmp
{
	//Size of Bitmap header used here is 54bytes
	int header[14];
	//Width of the image
	int width;
	//Height of the image
	int height;
	//Name of the file
	char *name;
}bitmap;


//Creates the bitmap header for the specific height and width and strcut bitmap is returned
bitmap* create_bitmap(int width, int height, char *name);

//Generating a bitmap with all pixels set to same RGB vales provided
void generate_color(bitmap *image, unsigned char R, unsigned char G, unsigned char B);

//Generating a bitmap with all pixels set the given color
//SImilar to generate_color, only the arguement given here is a struct pixel rather than individual RGB vales
void generate_plane(bitmap *image, pixel color);

//Generating bitmap with the given pixel array
void generate_bitmap(bitmap *image, pixel **p);

//Unallocate the image and pixels
void clean(bitmap *image, pixel **p);
#endif
