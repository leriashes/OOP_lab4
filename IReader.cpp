#include "IReader.h"

IReader::IReader(string s, bool st)
{
	myName = s;
	state = st;
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
	state = st;

	if (state)
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
	return state;
}

string IReader::getName()
{
	return myName;
}

void IReader::sendQuery()
{
	mySolver->processData();
}
