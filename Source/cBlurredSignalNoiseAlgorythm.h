#pragma once
#include "calgorythm.h"
class cBlurredSignalNoiseAlgorythm :
	public cAlgorythm
{
public:
	cBlurredSignalNoiseAlgorythm(void);
	~cBlurredSignalNoiseAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
};

