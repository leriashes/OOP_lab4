#pragma once
#include "IOpener.h"
class Gate :
    public IOpener
{
public:
    Gate(double cost) :IOpener("������", cost) {};

    void actionOpen();
    void actionClose();
};

