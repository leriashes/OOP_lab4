#include "IReader.h"

IReader::IReader(string s, double cost, State* onSt, State* offSt)
{
	myName = s;
	myCost = cost;

	onState = onSt;
	offState = offSt;

	onState->setReader(this);
	offState->setReader(this);

	currentState = offState;
}

void IReader::name()
{
	cout << myName << endl;
}

void IReader::info()
{
	cout << myName << " - цена: " << myCost << " руб., \n"; 
	mySolver->info();
}

void IReader::infoSolver()
{
	mySolver->info();
}

void IReader::setSolver(ISolver* s)
{
	mySolver = s;
}

void IReader::setState(State* state)
{
	currentState = state;
}

State* IReader::getState()
{
	return currentState;
}

State* IReader::getOnState()
{
	return onState;
}

State* IReader::getOffState()
{
	return offState;
}

string IReader::getName()
{
	return myName;
}

void IReader::on()
{
	cout << myName << ": ";
	currentState->on();
}

void IReader::off()
{
	cout << myName << ": ";
	currentState->off();
}

bool IReader::sendQuery()
{
	return mySolver->processData();
}

double IReader::getCost()
{
	return myCost;
}

IReader::~IReader()
{
	delete onState;
	delete offState;
}
