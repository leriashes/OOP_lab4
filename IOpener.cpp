#include "IOpener.h"

IOpener::IOpener(string s)
{
	myName = s;
}

void IOpener::name()
{
	cout << myName << endl;
}