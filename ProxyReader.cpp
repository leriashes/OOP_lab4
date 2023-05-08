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

void ProxyReader::setState(State* state)
{
	myReader->setState(state);
}

void ProxyReader::setSolver(ISolver* solver)
{
	myReader->setSolver(solver);
}

State* ProxyReader::getState()
{
	return myReader->getState();
}

State* ProxyReader::getOnState()
{
	return myReader->getOnState();
}

State* ProxyReader::getOffState()
{
	return myReader->getOffState();
}

string ProxyReader::getName()
{
	return myReader->getName();
}

string ProxyReader::getRequest()
{
	return myReader->getRequest();
}

