#pragma once
#include "IOpener.h"
class Gate :
    public IOpener
{
public:
    Gate() :IOpener("Ворота") {};

    void actionOpen();
    void actionClose();
};

