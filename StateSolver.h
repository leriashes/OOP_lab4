#pragma once
#include <map>
#include "ISolver.h"

class StateSolver :
    public ISolver
{
private:
    map <bool, void (StateSolver::*)()> stateActions = { {false, &StateSolver::stopProcessing}, {true, &StateSolver::startProcessing} };
    void(StateSolver::* stateProcessing)();

public:
    StateSolver(bool state) :ISolver() { stateProcessing = stateActions[state]; };

    void setState(bool state);

    void processData();
    void sendSolution(bool res);

    void startProcessing();
    void stopProcessing();
};

