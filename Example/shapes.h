#ifndef SHAPES_H
#define SHAPES_H

#include "bitmap.h"

//Fucntion draws the line with default white color
//Bresenham's algorithm used to draw the line
void drawline( bitmap *image, pixel **p, int x0, int x1, int y0, int y1);

//Function draws the line with given color
void drawlinec( bitmap *image, pixel **p, int x0, int x1, int y0, int y1, pixel color);

void drawcirlce(bitmap*image, pixel **p, int x_center, int y_center, int r);

static void plot(bitmap *image, pixel **p, int x, int y, pixel color);

void fill_circle(bitmap* image, pixel **p, int xc, int yc, int r, pixel color);


void drawcirlcec(bitmap* image, pixel **p, int xc, int yc, int r, pixel color_black);
#endif
