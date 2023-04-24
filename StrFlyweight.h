#pragma once
#include <iostream>
#include <string>
using namespace std;

class StrFlyweight
{
private:
	string myMessage;

public:
	StrFlyweight(string message);
	string getMessage(string addMessage);
};

