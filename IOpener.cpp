#include "IOpener.h"

IOpener::IOpener(string s, double cost)
{
	myName = s;
	myCost = cost;
}

void IOpener::name()
{
	cout << myName << endl;
}

double IOpener::getCost()
{
	return myCost;
}
