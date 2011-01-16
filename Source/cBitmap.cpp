#include "cBitmap.h"
#include <iostream>


cBitmap::cBitmap(void)
{
	width = 0;
	height = 0;
	data = 0;
	bppx = 0;
}


cBitmap::~cBitmap(void)
{

}

void cBitmap::allocateMemory(void)
{
	cPixel NullPixel(0,0,0,0); 
	delete[] data;
	data = new cPixel[width*height];
	for(int i=0;i<height*width;i++)
	{
		data[i].A = 255;
		data[i].B = 0;
		data[i].G = 0;
		data[i].R = 0;
	}
		
}

void cBitmap::Display(void)
{
	int i;
	for(i=0;i<width*height;i++)
	{
		std::cout << data[i].B << " " << data[i].G << " "  << data[i].R << " "  << data[i].A << "|";
		if((i+1)%width == 0)
			std::cout << std::endl;
	}	
}