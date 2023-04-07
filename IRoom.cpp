#include "IRoom.h"

IRoom::IRoom(string s, ISolver* solv, IOpener* o, IReader* r)
{ 
	myName = s; 
	myOpener = o;
	myReader = r;

	setSolver(solv);
}

void IRoom::name() 
{ 
	cout << myName << endl; 
}

void IRoom::setOpener(IOpener* o)
{
	myOpener = o;
	mySolver->setOpener(myOpener);
}

void IRoom::setReader(IReader* r)
{
	myReader = r;
	myReader->setSolver(mySolver);
}

void IRoom::setSolver(ISolver* s)
{
	mySolver = s;

	mySolver->setOpener(myOpener);
	myReader->setSolver(mySolver);
}

void IRoom::turnOnReader()
{
	myReader->setState(true);
}

void IRoom::turnOffReader()
{
	myReader->setState(false);
}

