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
	bool state;

public:
	IReader(string s, bool st);

	void name();
	void setSolver(ISolver* s);
	void setState(bool st);

	bool getState();
	string getName();

	virtual void tryToEnter() = 0;
	virtual void scanIdentifier() = 0;
	void sendQuery();
};

