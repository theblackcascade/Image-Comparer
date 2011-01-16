#pragma once
#include "cBitmap.h"
#include <string>
#include <iostream>
class cLoader
{
public:
	cLoader(void);
	void LoadBMP(char* fileName, cBitmap& bmp);
	~cLoader(void);
};
