#include "IReader.h"

IReader::IReader(string s)
{
	myName = s;
}

void IReader::name()
{
	cout << myName << endl;
}

void IReader::setSolver(ISolver* s)
{
	mySolver = s;
}

void IReader::sendQuery()
{
	mySolver->processData();
}
