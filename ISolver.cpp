#include "ISolver.h"

void ISolver::setOpener(IOpener* o)
{
	myOpener = o;
}

void ISolver::setReader(IReader* r)
{
	myReader = r;
}