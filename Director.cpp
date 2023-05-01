#include "Director.h"

Director::Director(Builder* builder)
{
	myBuilder = builder;
}

IRoom* Director::constructRoom()
{
	myBuilder->buildOpener();
	myBuilder->buildReader();
	myBuilder->buildSolver();
	myBuilder->createRoom();
	
	return myBuilder->getRoom();
}
