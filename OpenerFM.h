#pragma once
#include "IOpener.h"

class OpenerFM
{
private:
	IOpener* myOpener;

public:
	virtual IOpener* createOpener(double cost) = 0;
	IOpener* cloneOpener(IOpener* opener);
};

