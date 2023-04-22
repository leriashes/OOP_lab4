#pragma once
#include <iostream>
#include <string>
using namespace std;

class LangReader
{
private:
	string myName;

public:
	LangReader(string name);

	string getName();

	virtual void printHello() = 0;
	virtual void printWelcome() = 0;
	virtual void printStop() = 0;
};

