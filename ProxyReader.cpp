#include "ProxyReader.h"

void ProxyReader::setReader(IReader* reader)
{
	myReader = reader;
}

bool ProxyReader::tryToEnter()
{
	bool result;

	if (myReader->getState())
	{
		result = myReader->tryToEnter();
	}
	else
	{
		result = false;
		cout << myReader->getName() << " не работает!" << endl;
	}

	return result;
}

bool ProxyReader::scanIdentifier()
{
	bool result; 
	if (myReader->getState())
	{
		result = myReader->scanIdentifier();
	}
	else
	{
		result = false;
		cout << myReader->getName() << " не работает!" << endl;
	}

	return result;
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

string ProxyReader::getName()
{
	return myReader->getName();
}

string ProxyReader::getRequest()
{
	return myReader->getRequest();
}

