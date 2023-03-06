#include "IRoom.h"

IRoom::IRoom(string s, ISolver* solv)
{ 
	myName = s; 
	mySolver = solv;
}

void IRoom::name() 
{ 
	cout << myName << endl; 
}

 

void IRoom::setSolver(ISolver* s)
{
	mySolver = s;
}

