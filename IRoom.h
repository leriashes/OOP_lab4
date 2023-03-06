#pragma once
#include <iostream>
#include <string>
#include "IOpener.h"
#include "IReader.h"
#include "ISolver.h"
using namespace std;

class IRoom
{
private:
	string myName;

	IOpener* myOpener;
	IReader* myReader;
	ISolver* mySolver;

public:
	IRoom(string s, ISolver* solv);

	void name();
	void setOpener(IOpener* o);
	void setReader(IReader* r);
	void setSolver(ISolver* s);
};

