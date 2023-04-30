#pragma once
#include "OpenerFM.h"
#include "Gate.h"
class GateFM :
    public OpenerFM
{
public:
    GateFM() :OpenerFM() {}
    virtual Gate* createOpener(double cost);
};

