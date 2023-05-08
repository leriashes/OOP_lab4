#pragma once
#include "IReader.h"
#include "OnState.h"
#include "OffState.h"

class IReaderFactory
{
public:
	virtual IReader* createReader() = 0;
};
