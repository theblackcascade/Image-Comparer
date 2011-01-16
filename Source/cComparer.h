#pragma once
#include "cAlgorythm.h"
#include "cBitmap.h"
#include "cData.h"
class cComparer
{
public:
	cComparer(void);
	cData Compare(cBitmap& bitmap1, cBitmap& bitmap2, cAlgorythm* algorythm);
	~cComparer(void);
};

