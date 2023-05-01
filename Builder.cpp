#include "Builder.h"

void Builder::createRoom()
{
	room = new SimpleRoom("Комната", solver, opener, reader);
}

void Builder::buildOpener()
{
	opener = ofm->createOpener(20000);
}

void Builder::buildReader()
{
	reader = rfact->createReader();
}

void Builder::buildSolver()
{
	solver = SolverPool::Instance()->acquireSolver();
}

IRoom* Builder::getRoom()
{
	opener = nullptr;
	reader = nullptr;
	solver = nullptr;

	return room;
}

void Builder::setWorker(IReaderFactory* fact)
{
	rfact = fact;
}

void Builder::setWorker(OpenerFM* fact)
{
	ofm = fact;
}
