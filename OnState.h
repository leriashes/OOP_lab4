#pragma once
#include "State.h"
#include "IReader.h"

class OnState :
    public State
{
public:
    void on();
    void off();
    bool enter();
};

