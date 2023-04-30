#pragma once
#include "IReader.h"

class IReaderFactory
{
public:
	virtual IReader* createReader() = 0;
};
