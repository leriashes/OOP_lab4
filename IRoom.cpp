#include "IRoom.h"

IRoom::IRoom(string s)
{ 
	myName = s; 
}

void IRoom::name() 
{ 
	cout << myName << endl; 
}

void IRoom::setOpener(IOpener* o)
{
	myOpener = o;
}

void IRoom::setReader(IReader* r)
{
	myReader = r;
}

void IRoom::setSolver(ISolver* s)
{
	mySolver = s;
}

