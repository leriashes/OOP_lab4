#pragma once
#include <iostream>
using namespace std;

class IReader;

class State
{
protected:
	IReader* myReader;

public:
	virtual void on() = 0;
	virtual void off() = 0;
	virtual bool enter() = 0;
	void setReader(IReader* reader);
};

