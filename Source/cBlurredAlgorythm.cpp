#include "cBlurredAlgorythm.h"
#include <iostream>

cBlurredAlgorythm::cBlurredAlgorythm(void)
{
}


cBlurredAlgorythm::~cBlurredAlgorythm(void)
{
}

cData cBlurredAlgorythm::Compare(cBitmap bitmap1, cBitmap bitmap2)
{
	int blur;
	std::cout << "Enter Blur Coefficient ";
	std::cin >> blur;
	int errorPixelCounter = 0;
	cBitmap mask;
	if(bitmap1.height == bitmap2.height && bitmap1.width == bitmap2.width)
	{
		mask.height = bitmap1.height;
		mask.width = bitmap1.width;
		mask.allocateMemory();
		for(int i=0;i<bitmap1.height*bitmap1.width;i+=blur)
		{
			if(bitmap1.data[i].getHash() == bitmap2.data[i].getHash())
			{
					mask.data[i].A = 0;
					mask.data[i].B = 0;
					mask.data[i].G = 0;
					mask.data[i].R = 0;
			}
			else
			{
				mask.data[i].A = 0;
				mask.data[i].B = 255;
				mask.data[i].G = 255;
				mask.data[i].R = 255;
				errorPixelCounter++;
			}
		}
		std::cout << "error pixel count: " << errorPixelCounter << std::endl;
		std::cout << "errors " << (float(errorPixelCounter*blur*100))/(float(bitmap1.height*bitmap1.width)) << " %" << std::endl;
		cData data;
		data.bitmap = mask;
		std::cout << "Mask Save Format (24/32)" << std::endl;
		std::cin >> data.bitmap.bppx;
		return data;
	}
}