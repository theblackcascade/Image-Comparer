#pragma once
#include "calgorythm.h"
class cHistogramAlgorythm :
	public cAlgorythm
{
public:
	cHistogramAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
	~cHistogramAlgorythm(void);
};

