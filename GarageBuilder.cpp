#include "GarageBuilder.h"

GarageBuilder::GarageBuilder()
{
	setWorker(new GateFM());
	setWorker(new NumplateVoiceFactory());
}

void GarageBuilder::createRoom()
{
	room = new SimpleRoom("Гараж", solver, opener, reader);
}

void GarageBuilder::buildOpener()
{
	opener = ofm->createOpener(120000);
}

void GarageBuilder::buildReader()
{
	reader = rfact->createReader();
}

void GarageBuilder::buildSolver()
{
	solver = SolverPool::Instance()->acquireSolver();
}

GarageBuilder::~GarageBuilder()
{
	delete ofm;
	delete rfact;
}

