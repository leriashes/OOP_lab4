#include "IRoom.h"

IRoom::IRoom(string s, ISolver* solv, IOpener* o, IReader* r)
{ 
	myName = s; 
	myOpener = o;
	myReader = r;

	setSolver(solv);
}

IRoom::~IRoom()
{
	if (myOpener != nullptr)
		delete myOpener;

	if (myReader != nullptr)
		delete myReader;

	if (mySolver != nullptr)
		delete mySolver;
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

void IRoom::info()
{
	cout << "Название комнаты: " << myName << endl;
	myOpener->info();
	myReader->info();
	cout << endl;
}

void IRoom::turnOnReader()
{
	cout << myName << ": ";
	myReader->on();
}

void IRoom::turnOffReader()
{
	cout << myName << ": ";
	myReader->off();
}

double IRoom::getCost()
{
	return myOpener->getCost() + myReader->getCost();
}

void IRoom::lock()
{
	myOpener->update(0);
	myReader->update(0);
	mySolver->setState(false);
}

void IRoom::unlock()
{
	myOpener->update(1);
	myReader->update(1);
	mySolver->setState(true);
}

