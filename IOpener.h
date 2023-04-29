#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOpener
{
private:
	string myName;
	double myCost;

public:
	IOpener(string s, double cost);

	void name();
	double getCost();

	virtual void actionOpen() = 0;
	virtual void actionClose() = 0;
};

