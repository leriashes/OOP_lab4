#pragma once
#include <iostream>
#include <string>
#include "StrFlyFactory.h"
using namespace std;

class LangReader
{
private:
	string myName;
	string myRequest;
	StrFlyweight* hello;
	StrFlyweight* welcome;
	StrFlyweight* stop;

public:
	LangReader(string name, string shello, string swelcome, string sstop, string request, StrFlyFactory* fact);

	string getName();

	void printHello();
	void printWelcome();
	void printStop();
};

