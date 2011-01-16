#pragma once
#include "cBitmap.h"
#include "cData.h"
class cAlgorythm
{
public:
	cAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2)=0;
	~cAlgorythm(void);
};

