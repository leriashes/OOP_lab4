#pragma once
#include <map>
#include "ISolver.h"

class SimpleSolver :
    public ISolver
{
    void processData();
    void sendSolution(bool res);
    void setState(bool state);
};

