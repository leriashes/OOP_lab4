#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOpener
{
private:
	string myName;

public:
	IOpener(string s);

	void(* Action)();
	void name();
	
	virtual void actionOpen() = 0;
	virtual void actionClose() = 0;
};

