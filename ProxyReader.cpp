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
		cout << myReader->getName() << " не работает!" << endl;
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
		cout << myReader->getName() << " не работает!" << endl;
	}
}
