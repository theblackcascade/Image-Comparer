#include "cHistogramAlgorythm.h"
#include <iostream>

cHistogramAlgorythm::cHistogramAlgorythm(void)
{
}

cData cHistogramAlgorythm::Compare(cBitmap bitmap1, cBitmap bitmap2)
{
	float errorPixel = 0;
	std::cout << "Enter Histogram Resolution" << std::endl;
	int b1res = bitmap1.height*bitmap1.width;
	int b2res = bitmap2.height*bitmap2.width;
	int hResolution;
	std::cin >> hResolution;
	int opt = 255/hResolution;
	int* histogramB1;int* histogramB2;
	int* histogramG1;int* histogramG2;
	int* histogramR1;int* histogramR2;
	histogramB1 = new int[hResolution];
	histogramG1 = new int[hResolution];
	histogramR1 = new int[hResolution];
	histogramB2 = new int[hResolution];
	histogramG2 = new int[hResolution];
	histogramR2 = new int[hResolution];
	for(int i=0;i<hResolution;i++)
	{
		histogramB1[i] = 0;
		histogramG1[i] = 0;
		histogramR1[i] = 0;
		histogramB2[i] = 0;
		histogramG2[i] = 0;
		histogramR2[i] = 0;
	}

	for(int i=0;i<b1res;i++)
	{
		histogramB1[bitmap1.data[i].B/opt] ++;
		histogramG1[bitmap1.data[i].G/opt] ++;
		histogramR1[bitmap1.data[i].R/opt] ++;
	}
	for(int i=0;i<b2res;i++)
	{
		histogramB2[bitmap2.data[i].B/opt] ++;
		histogramG2[bitmap2.data[i].G/opt] ++;
		histogramR2[bitmap2.data[i].R/opt] ++;
	}
	for(int i=0;i<hResolution;i++)
	{
		errorPixel = 0;
		std::cout << i*opt << " - " << (i+1) * opt << " b1 " << float(histogramB1[i])/(float)b1res*100 << "%" <<   std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " g1 " << float(histogramG1[i])/(float)b1res*100 << "%" << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " r1 " << float(histogramR1[i])/(float)b1res*100 << "%" << std::endl;
		
		std::cout << i*opt << " - " << (i+1) * opt << " b2 " << float(histogramB2[i])/(float)b2res*100 << "%" << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " g2 " << float(histogramG2[i])/(float)b2res*100 << "%" << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " r2 " << float(histogramR2[i])/(float)b2res*100 << "%" << std::endl;
		
		errorPixel += abs(float(histogramB1[i])/(float)b1res*100-float(histogramB2[i])/(float)b2res*100);
		errorPixel += abs(float(histogramG1[i])/(float)b1res*100-float(histogramG2[i])/(float)b2res*100);
		errorPixel += abs(float(histogramR1[i])/(float)b1res*100-float(histogramR2[i])/(float)b2res*100);

		std::cout << float(100) - errorPixel << " Identity" << std::endl;
		/*std::cout << i*opt << " - " << (i+1) * opt << " b1 " << (histogramB1[i]) << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " b2 " << (histogramB2[i]) << std::endl << std::endl;
		
		std::cout << i*opt << " - " << (i+1) * opt << " g1 " << (histogramG1[i]) << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " g2 " << (histogramG2[i]) << std::endl << std::endl;
		
		std::cout << i*opt << " - " << (i+1) * opt << " r1 " << (histogramR1[i]) << std::endl;
		std::cout << i*opt << " - " << (i+1) * opt << " r2 " << (histogramR2[i]) << std::endl << std::endl;*/
	}
	cData data;
	return data;
}

cHistogramAlgorythm::~cHistogramAlgorythm(void)
{

}
