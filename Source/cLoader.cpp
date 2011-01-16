#include "cLoader.h"


cLoader::cLoader(void)
{
}


cLoader::~cLoader(void)
{
}

void cLoader::LoadBMP(char* fileName, cBitmap& bmp)
{
	FILE* file = fopen(fileName,"rb");
	char header[54];
	
	if(!file)
		std::cout << "File Loading Failed";
	
	fread(header,54,1,file);
	
	/*Checkin File Type*/
	if(header[0]!='B' || header[1]!='M')
	{
			fclose(file);
			std::cout << "Not BMP";  //all bmp start with bm
	}
	/*Getting header info*/
	int dataOffset=*(unsigned int*)(header+10); // offset of image data in header
	bmp.width=*(unsigned int*)(header+18);
	bmp.height=*(unsigned int*)(header+22);
	bmp.bppx=short(header[28]); // Bits per pixel
	bmp.allocateMemory();
	int pixelCount = bmp.height*bmp.width;

	switch(bmp.bppx)
	{
		case(32):
				fseek(file,dataOffset,SEEK_SET);
				for(int i=0; i<bmp.height*bmp.width; i++)
				{
					bmp.data[i].B = fgetc(file);
					bmp.data[i].G = fgetc(file);
					bmp.data[i].R = fgetc(file);
					bmp.data[i].A = fgetc(file);
				}
				break;
        case(24):
                fseek(file,dataOffset,SEEK_SET);
                for(int i=0; i<bmp.height*bmp.width; i++)
				{
					bmp.data[i].B = fgetc(file);
					bmp.data[i].G = fgetc(file);
					bmp.data[i].R = fgetc(file);
					bmp.data[i].A = 0;
				}
                break;
		default:
                fclose(file);
	}
    if(ferror(file))
       fclose(file);
    fclose(file);
}
