#pragma once
#include <iostream>
#include <string>
#include "ISolver.h"
using namespace std;


class IReader
{
private:
	string myName;
	ISolver* mySolver;
	bool myState;

public:
	IReader(string s, bool st);

	void name();
	virtual void setSolver(ISolver* s);
	virtual void setState(bool st);
	virtual bool getState();
	virtual string getName();

	virtual void tryToEnter() = 0;
	virtual void scanIdentifier() = 0;
	void sendQuery();
};

