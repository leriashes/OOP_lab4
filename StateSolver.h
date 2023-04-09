#pragma once
#include <map>
#include "ISolver.h"

class StateSolver :
    public ISolver
{
private:
    map <bool, bool (StateSolver::*)()> stateActions = { {false, &StateSolver::stopProcessing}, {true, &StateSolver::startProcessing} };
    bool(StateSolver::* stateProcessing)();

public:
    StateSolver(bool state) :ISolver() { stateProcessing = stateActions[state]; };

    void setState(bool state);

    bool processData();
    void sendSolution(bool res);

    bool startProcessing();
    bool stopProcessing();
};

