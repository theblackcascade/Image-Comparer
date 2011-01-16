#pragma once
#include "cVisualizer.h"
#include "cBitmap.h"
#include "cLoader.h"
#include "cComparer.h"
#include "cDirectAlgorythm.h"
#include "cBlurredAlgorythm.h"
#include "cHistogramAlgorythm.h"
#include "cVisualizer.h"
#include "cBlurredHistogramAlgorythm.h"
#include "cSignalNoiseAlgorythm.h"
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Shellapi.h>
#include "cBlurredSignalNoiseAlgorythm.h"
int main()
{
	cComparer comparer;
	cVisualizer visualizer;
	cDirectAlgorythm algorythm;
	cBlurredAlgorythm algorythm2;
	cHistogramAlgorythm algorythm3;
	cBlurredHistogramAlgorythm algorythm4;
	cSignalNoiseAlgorythm algorythm5;
	cBlurredSignalNoiseAlgorythm algorythm6;
	std::string title;
	std::string response;
	std::cout << "Please enter first image title, you can manually specify it's path\n";
	std::cin >> title;
	std::cout << "Image Title: " << title;
	cLoader loader;
	char* ctitle = new char[title.size()+1];
	strcpy(ctitle,title.c_str());
	cBitmap b;
	loader.LoadBMP(ctitle,b);
	std::cout << "\nIf you want to see your image type see or skip, to skip this step\n";
	std::cin >> response;
	if(response == "see")
	ShellExecuteA(NULL, "open", ctitle, NULL, NULL, SW_SHOWNORMAL);

	title = "";
	response = "";
	
	std::cout << "Please enter second image title, you can manually specify it's path\n";
	std::cin >> title;
	std::cout << "Image Title: " << title;
	ctitle = new char[title.size()+1];
	strcpy(ctitle,title.c_str());
	cBitmap b2;
	loader.LoadBMP(ctitle,b2);
	std::cout << "\nIf you want to see your image type \'see\' or \'skip\', to skip this step\n" << std::endl;
	std::cin >> response;
	if(response == "see")
	ShellExecuteA(NULL, "open", ctitle, NULL, NULL, SW_SHOWNORMAL);
	char symbol;
	std::cout << "Please Chose one of comparers\n" << "1.Direct\n" << "2.Blurred Direct\n" << "3.Histogram\n" << "4.Blurred Histogram\n" << "5.SignalNoise\n" << "6.Blurred SignalNoise" << std::endl;
	std::cin >> symbol;
	switch(symbol)
	{
		case '1':
			visualizer.SaveMask(comparer.Compare(b,b2,&algorythm).bitmap);
			ShellExecuteA(NULL, "open", "mask32.bmp", NULL, NULL, SW_SHOWNORMAL);
			break;
		case '2':
			visualizer.SaveMask(comparer.Compare(b,b2,&algorythm2).bitmap);
			ShellExecuteA(NULL, "open", "mask32.bmp", NULL, NULL, SW_SHOWNORMAL);
			break;
		case '3':
			comparer.Compare(b,b2,&algorythm3);
			break;
		case '4':
			comparer.Compare(b,b2,&algorythm4);
			break;
		case '5':
			comparer.Compare(b,b2,&algorythm5);
			break;
		case '6':
			comparer.Compare(b,b2,&algorythm6);
			break;
		default:
			std::cout << "Input error, check" << std::endl;
			break;
	}
	std::cin >> response;
	return 0;
}