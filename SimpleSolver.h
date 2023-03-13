#pragma once
#include "ISolver.h"
#include <map>

class SimpleSolver :
    public ISolver
{
    void processData();
    void sendSolution(bool res);
};

