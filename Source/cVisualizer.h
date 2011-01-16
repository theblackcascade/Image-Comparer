#include "cBitmap.h"
#pragma once
class cVisualizer
{
public:
	cVisualizer(void);
	~cVisualizer(void);
	void SaveMask(cBitmap mask);
private:
	void SaveMask32(cBitmap mask);
	void SaveMask24(cBitmap mask);
};

