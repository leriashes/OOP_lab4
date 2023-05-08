#pragma once
#include <iostream>
#include <string>
#include "ISolver.h"
#include "State.h"
#include <conio.h>
using namespace std;


class IReader
{
private:
	string myName;
	ISolver* mySolver;
	double myCost;

	State* currentState;
	State* onState;
	State* offState;

public:
	IReader(string s, double cost, State* onSt, State* offSt);

	void name();
	virtual void info();
	virtual void infoSolver();

	virtual void setSolver(ISolver* s);
	virtual void setState(State* state);

	virtual State* getState();
	virtual State* getOnState();
	virtual State* getOffState();

	virtual string getName();

	virtual bool tryToEnter() = 0;
	virtual bool scanIdentifier() = 0;
	virtual string getRequest() = 0;

	virtual void on();
	virtual void off();

	bool sendQuery();
	double getCost();

	~IReader();
};

