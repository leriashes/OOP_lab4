#include "ProxyReader.h"

void ProxyReader::setReader(IReader* reader)
{
	myReader = reader;
}

void ProxyReader::tryToEnter()
{
	if (myReader->getState())
	{
		myReader->tryToEnter();
	}
	else
	{
		cout << myReader->getName() << " �� ��������!" << endl;
	}
}

void ProxyReader::scanIdentifier()
{
	if (myReader->getState())
	{
		myReader->scanIdentifier();
	}
	else
	{
		cout << myReader->getName() << " �� ��������!" << endl;
	}
}

void ProxyReader::setState(bool st)
{
	myReader->setState(st);
}

void ProxyReader::setSolver(ISolver* solver)
{
	myReader->setSolver(solver);
}

bool ProxyReader::getState()
{
	return myReader->getState();
}

