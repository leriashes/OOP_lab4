#include "ISolver.h"

void ISolver::setOpener(IOpener* o)
{
	myOpener = o;
}

void ISolver::allowOpen()
{
	myOpener->actionOpen();
}

void ISolver::forbidOpen()
{
	myOpener->actionClose();
}

