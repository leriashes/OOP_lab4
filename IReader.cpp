#include "IReader.h"

IReader::IReader(string s, bool st)
{
	myName = s;
	myState = st;
}

void IReader::name()
{
	cout << myName << endl;
}

void IReader::setSolver(ISolver* s)
{
	mySolver = s;
}

void IReader::setState(bool st)
{
	myState = st;

	if (myState)
	{
		cout << myName << ": включение... Готово!" << endl;
	}
	else
	{
		cout << myName << " выключение... Готово!" << endl;
	}
}

bool IReader::getState()
{
	return myState;
}

string IReader::getName()
{
	return myName;
}

void IReader::sendQuery()
{
	mySolver->processData();
}
