#pragma once
#include "calgorythm.h"
class cBlurredHistogramAlgorythm :
	public cAlgorythm
{
public:
	cBlurredHistogramAlgorythm(void);
	~cBlurredHistogramAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
};

