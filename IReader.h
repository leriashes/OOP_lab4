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

public:
	IReader(string s);

	void name();
	void setSolver(ISolver* s);

	virtual void tryToEnter() = 0;
	virtual void scanIdentifier() = 0;
	void sendQuery();
};

