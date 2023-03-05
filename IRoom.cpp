#include "IRoom.h"

IRoom::IRoom(string s)
{ 
	name = s; 
}

void IRoom::getName() 
{ 
	cout << name << endl; 
}

