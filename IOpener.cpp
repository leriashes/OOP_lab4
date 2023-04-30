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

string IOpener::getName()
{
	return myName;
}

double IOpener::getCost()
{
	return myCost;
}

void IOpener::info()
{
	cout << myName << " - цена: " << myCost << " руб." << endl;
}
