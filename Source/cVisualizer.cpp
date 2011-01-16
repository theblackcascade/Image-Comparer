#include "cVisualizer.h"
#include <string>
#include <iostream>

cVisualizer::cVisualizer(void)
{
}
cVisualizer::~cVisualizer(void)
{
}
void cVisualizer::SaveMask(cBitmap mask)
{
	if(mask.bppx == 32)
		SaveMask32(mask);
	else if(mask.bppx == 24)
		SaveMask24(mask);
	else
		void(); //throw smth bro
}
void cVisualizer::SaveMask32(cBitmap mask)
{
	FILE* file = fopen("mask32.bmp","w");
	int size = mask.height*mask.width*4 + 2;
	int totalsize = size + 54;
	int zero = 0;
	int dataoffset = 54;
	int headersize = 40;
	short plates = 1;
	int ratio = 39;
	short padding = 0;
	short ending = 3338;
	fwrite("BM",1,2,file);
	fwrite(&totalsize,4,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&dataoffset,4,1,file);
	fwrite(&headersize,4,1,file);
	fwrite(&mask.width,4,1,file);
	fwrite(&mask.height,4,1,file);
	fwrite(&plates,2,1,file);
	fwrite(&mask.bppx,2,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&size,4,1,file);
	fwrite(&ratio,4,1,file);//тонкое место
	fwrite(&ratio,4,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&zero,4,1,file);
	for(int i = 0; i<(mask.height*mask.width);i++)
	{
		fwrite(&mask.data[i].B,1,1,file);
		fwrite(&mask.data[i].G,1,1,file);
		fwrite(&mask.data[i].R,1,1,file);
		fwrite(&mask.data[i].A,1,1,file);
	}
	fwrite(&padding,2,1,file);
	if(ferror(file))
	   fclose(file);
	fclose(file);

	//42 4D xx xx xx xx 00 00 00 00 36 00 00 00 28 00 00 00 ww ww ww ww hh hh hh hh 01 00 20 00 00 00 00 00 wh wh wh wh 13 0B 00 00 13 0B 00 00 00 00 00 00 00 00 00 00
	//Это капец!
}

void cVisualizer::SaveMask24(cBitmap mask)
{
	FILE* file = fopen("mask24.bmp","w");
	int size = mask.height*mask.width*3 + 2;
	int totalsize = size + 54;
	int zero = 0;
	int dataoffset = 54;
	int headersize = 40;
	short plates = 1;
	int ratio = 39;
	short padding = 0;
	short ending = 3338;
	fwrite("BM",1,2,file);
	fwrite(&totalsize,4,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&dataoffset,4,1,file);
	fwrite(&headersize,4,1,file);
	fwrite(&mask.width,4,1,file);
	fwrite(&mask.height,4,1,file);
	fwrite(&plates,2,1,file);
	fwrite(&mask.bppx,2,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&size,4,1,file);
	fwrite(&ratio,4,1,file);//тонкое место
	fwrite(&ratio,4,1,file);
	fwrite(&zero,4,1,file);
	fwrite(&zero,4,1,file);
	for(int i = 0; i<(mask.height*mask.width);i++)
	{
		fwrite(&mask.data[i].B,1,1,file);
		fwrite(&mask.data[i].G,1,1,file);
		fwrite(&mask.data[i].R,1,1,file);
	}
	fwrite(&padding,2,1,file);
	if(ferror(file))
	   fclose(file);
	fclose(file);
}