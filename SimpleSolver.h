#pragma once
#include <map>
#include "ISolver.h"

class SimpleSolver :
    public ISolver
{
    bool processData();
    void sendSolution(bool res);
    void setState(bool state);
    void info();
};

