#include "TurnstileAdapter.h"

void TurnstileAdapter::actionOpen()
{
	myTurn->unlock();
	myTurn->greenLight();
	cout << endl;
}

void TurnstileAdapter::actionClose()
{
	myTurn->block();
	myTurn->redLight();
	cout << endl;
}
