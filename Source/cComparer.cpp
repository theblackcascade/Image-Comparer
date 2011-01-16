#include "cComparer.h"


cComparer::cComparer(void)
{
}


cComparer::~cComparer(void)
{
}

cData cComparer::Compare(cBitmap& bitmap1, cBitmap& bitmap2, cAlgorythm* algorythm)
{
	return algorythm->Compare(bitmap1,bitmap2);
}