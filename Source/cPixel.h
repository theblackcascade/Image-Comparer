#pragma once
typedef unsigned char byte;
class cPixel
{
public:
	cPixel(void);
	~cPixel(void);
	cPixel(byte r,byte g,byte b,byte a);
	byte R;
	byte B;
	byte G;
	byte A;
	float getHash();
};

