#pragma once
#include "IRoom.h"
#include "IReaderFactory.h"
#include "OpenerFM.h"
#include "SolverPool.h"
#include "SimpleRoom.h"

class Builder
{
protected:
	IRoom* room;
	IOpener* opener;
	IReader* reader;
	ISolver* solver;

	IReaderFactory* rfact;
	OpenerFM* ofm;

public:
	virtual void createRoom();
	virtual void buildOpener();
	virtual void buildReader();
	virtual void buildSolver();
	virtual IRoom* getRoom();

	void setWorker(IReaderFactory* fact);
	void setWorker(OpenerFM* fact);
};

