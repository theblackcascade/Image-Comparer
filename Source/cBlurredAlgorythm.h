#pragma once
#include "calgorythm.h"
class cBlurredAlgorythm :
	public cAlgorythm
{
public:
	cBlurredAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
	~cBlurredAlgorythm(void);
};

