#pragma once
#include "IOpener.h"
class Gate :
    public IOpener
{
public:
    Gate() :IOpener("������") {};

    void actionOpen();
    void actionClose();
};

