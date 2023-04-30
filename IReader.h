#pragma once
#include <iostream>
#include <string>
#include "ISolver.h"
#include <conio.h>
using namespace std;


class IReader
{
private:
	string myName;
	ISolver* mySolver;
	bool myState;
	double myCost;

public:
	IReader(string s, bool st, double cost);

	void name();
	virtual void info();
	virtual void infoSolver();

	virtual void setSolver(ISolver* s);
	virtual void setState(bool st);
	virtual bool getState();
	virtual string getName();

	virtual bool tryToEnter() = 0;
	virtual bool scanIdentifier() = 0;
	virtual string getRequest() = 0;

	bool sendQuery();
	double getCost();
};

