#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "StrFlyweight.h"
using namespace std;

class StrFlyFactory
{
private:
	unordered_map<string, StrFlyweight*> flyweights;

public:
	StrFlyweight* getStr(string message);
};

