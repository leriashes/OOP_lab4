#pragma once
#include "IOpener.h"

class ISolver
{
private:
	IOpener* myOpener;
	
public:
	void setOpener(IOpener* o);
	void allowOpen();
	void forbidOpen();
	virtual void info() = 0;

	virtual bool processData() = 0;
	virtual void sendSolution(bool res) = 0;
	virtual void setState(bool state) = 0;
};

