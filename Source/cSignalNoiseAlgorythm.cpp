#include "cSignalNoiseAlgorythm.h"
#include <iostream>

cSignalNoiseAlgorythm::cSignalNoiseAlgorythm(void)
{
}


cSignalNoiseAlgorythm::~cSignalNoiseAlgorythm(void)
{
}

cData cSignalNoiseAlgorythm::Compare(cBitmap bitmap1, cBitmap bitmap2)
{
	float errorPixel = 0;
	int b1res = bitmap1.height * bitmap1.width;
	int b2res = bitmap2.height * bitmap2.width;
	int hResolution;
	std::cout << "Enter Histogram Resolution" << std::endl;
	std::cin >> hResolution;
	int opt = 255/hResolution;
	int* signalHistogram1;
	int* signalHistogram2;
	signalHistogram1 = new int[hResolution];
	signalHistogram2 = new int[hResolution];
	
	for(int i=0;i<hResolution;i++)
	{
		signalHistogram1[i] = 0;
		signalHistogram2[i] = 0;
	}

	for(int i=0;i<b1res;i++)
	{
		signalHistogram1[bitmap1.data[i].B/opt] ++;
		signalHistogram1[bitmap1.data[i].G/opt] ++;
		signalHistogram1[bitmap1.data[i].R/opt] ++;
	}

	for(int i=0;i<b2res;i++)
	{
		signalHistogram2[bitmap2.data[i].B/opt] ++;
		signalHistogram2[bitmap2.data[i].G/opt] ++;
		signalHistogram2[bitmap2.data[i].R/opt] ++;
	}

	for(int i=0;i<hResolution;i++)
	{
		std::cout << i*opt << " - " << (i+1) * opt << " 1 " << float(signalHistogram1[i])/(float)b1res*100 << "%" << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " 2 " << float(signalHistogram2[i])/(float)b1res*100 << "%" << std::endl;
		errorPixel += abs(float(signalHistogram1[i])/(float)b1res*100-float(signalHistogram2[i])/(float)b2res*100);
		std::cout << float(100)-errorPixel << " % " << std::endl;
	}

	cData data;
	return data;
}