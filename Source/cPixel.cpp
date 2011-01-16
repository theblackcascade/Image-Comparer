#include "cPixel.h"


cPixel::cPixel(void)
{
}

cPixel::cPixel(byte r,byte g,byte b,byte a)
{
	a=A;r=R;g=G;b=B;
}


cPixel::~cPixel(void)
{
}
float cPixel::getHash()
{
	return 1000000000*B + 1000000*G + 1000*R + A;
}