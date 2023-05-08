#pragma once
#include "State.h"
#include "IReader.h"

class OffState :
    public State
{
    void on();
    void off();
    bool enter();
};

