#pragma once
#include "cPixel.h"
typedef unsigned char byte;
class cBitmap
{
public:
	cBitmap(void);
	~cBitmap(void);
	int width;
	int height;
	short bppx;
	cPixel* data;
	void allocateMemory();
	void Display();
};

