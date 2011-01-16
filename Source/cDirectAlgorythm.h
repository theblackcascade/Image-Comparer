#pragma once
#include "calgorythm.h"
class cDirectAlgorythm : public cAlgorythm
{
public:
	cDirectAlgorythm(void);
	virtual cData Compare(cBitmap bitmap1, cBitmap bitmap2);
	~cDirectAlgorythm(void);
};

