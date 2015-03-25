#ifndef PIXEL_H
//Guard for the pixel header file
#define PIXEL_H
#include"bitmap.h"

//Declaring the generic colors 
extern pixel color_black, color_yellow, color_blue, color_red, color_grey, color_white, color_green;
//Initializing the generic colors
void create_colors();
//Generates pixels for the Bitmap manipulations
pixel** get_pixels(int width, int height);
//Set all the pixels to a specific color passed as RGB individually
void set_background(unsigned char R,unsigned char G,unsigned char B, bitmap *image, pixel **p);
//Set all the pixels to a specific color passed as a pixel
void set_backgroundc(pixel color,bitmap *image,pixel **p);

#endif
