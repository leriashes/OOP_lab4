#pragma once
#include "IOpener.h"
#include "IReader.h"

class ISolver
{
private:
	IOpener* myOpener;
	IReader* myReader;

public:
	void setOpener(IOpener* o);
	void setReader(IReader* r);
};

