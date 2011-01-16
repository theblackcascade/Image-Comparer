#pragma once
#include "calgorythm.h"
class cSignalNoiseAlgorythm :
	public cAlgorythm
{
public:
	cSignalNoiseAlgorythm(void);
	~cSignalNoiseAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
};

