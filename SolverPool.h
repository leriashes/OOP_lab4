#pragma once
#include <queue>
#include "SimpleSolver.h"
using namespace std;

class SolverPool
{
private:
	static SolverPool* instance;
	queue <ISolver*> pool;

protected:
	SolverPool() {}

public:
	static SolverPool* Instance();
	ISolver* acquireSolver();
	void releaseSolver(ISolver* solv);

	~SolverPool();
};

