#include "shapes.h"
#include "bitmap.h"
#include<stdlib.h>


void drawline( bitmap *image, pixel **p, int x0, int x1, int y0, int y1)
{
	float dx = abs(x1 - x0);
	float dy = abs(y1 - y0);
	float d = 2*dy-dx;
	float dy2=2*dy;
	float dxy2=2*(dy-dx);
	int x, y;
	if( x0 == x1 )
	{
		y=y0;
		if(y0>y1)
		{
			y=y1;
			y1=y0;
		}
		while(y<=y1)
			p[y++][x0]=color_white;
		return;
	}
	if( x0 > x1)
	{
		x=x1;
		y=y0;
		x1=x0;
	}
	else
	{
		x=x0;
		y=y0;
	}
	p[y][x]=color_white;
	while(x<x1)
	{
		x++;
		if(d<0)
			d+=dy2;
		else
		{
			y++;
			d+=dxy2;
		}
		p[y][x]=color_white;
	}
		
}



void drawlinec( bitmap *image, pixel **p, int x0, int x1, int y0, int y1, pixel color)
{
	float dx = abs(x1 - x0);
	float dy = abs(y1 - y0);
	float d = 2*dy-dx;
	float dy2=2*dy;
	float dxy2=2*(dy-dx);
	int x, y;
	if( x0 == x1 )
	{
		y=y0;
		if(y0>y1)
		{
			y=y1;
			y1=y0;
		}
		while(y<=y1)
			p[y++][x0]=color;
		return;
	}
	if( x0 > x1)
	{
		x=x1;
		y=y0;
		x1=x0;
	}
	else
	{
		x=x0;
		y=y0;
	}
	p[y][x]=color;
	while(x<x1)
	{
		x++;
		if(d<0)
			d+=dy2;
		else
		{
			y++;
			d+=dxy2;
		}
		p[y][x]=color;
	}
		
}

static void plot(bitmap *image, pixel **p, int x, int y, pixel color)
{
	if(x<image->width&&y<image->height)
	{
		p[y][x]=color;
	}
	
}

void drawcirlce(bitmap* image, pixel **p, int xc, int yc, int r)
{	
	int x,y,re;
	x=r;
	y=0;
	re=1-x;
	while(x>=y)
	{
		plot(image,p,xc+x,yc+y,color_black);
		plot(image,p,xc+y,yc+x,color_black);
		plot(image,p,xc-x,yc+y,color_black);
		plot(image,p,xc-y,yc+x,color_black);
		plot(image,p,xc-x,yc-y,color_black);
		plot(image,p,xc-y,yc-x,color_black);
		plot(image,p,xc+x,yc-y,color_black);
		plot(image,p,xc+y,yc-x,color_black);
		y++;
		if(re<0)
			re+=2*y+2;
		else
		{
			--x;
			re+=2*(y-x)+1;
		}
	}
}

void drawcirlcec(bitmap* image, pixel **p, int xc, int yc, int r, pixel color_black)
{	
	int x,y,re;
	x=r;
	y=0;
	re=1-x;
	while(x>=y)
	{
		plot(image,p,xc+x,yc+y,color_black);
		plot(image,p,xc+y,yc+x,color_black);
		plot(image,p,xc-x,yc+y,color_black);
		plot(image,p,xc-y,yc+x,color_black);
		plot(image,p,xc-x,yc-y,color_black);
		plot(image,p,xc-y,yc-x,color_black);
		plot(image,p,xc+x,yc-y,color_black);
		plot(image,p,xc+y,yc-x,color_black);
		y++;
		if(re<0)
			re+=2*y+2;
		else
		{
			--x;
			re+=2*(y-x)+1;
		}
	}
}


void fill_circle(bitmap* image, pixel **p, int xc, int yc, int r, pixel color)
{
	int left, right, up, down, i, j, it, jt;
	left = xc-r;
	right = xc+r;
	up = yc+r;
	down = yc-r;
	for(i=0; i<image->height; ++i)
	{
		it = i-yc;
		for(j=0; j<image->width; ++j)
		{
			jt = j - xc;
			if((it*it)+(jt*jt)<=(r*r)&&j>=left&&j<=right&&i>=down&&i<=up)
				p[i][j]=color;
		}
	}
}
