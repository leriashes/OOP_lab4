#pragma once
#include "IOpener.h"
class Door : public IOpener
{
  
public:
    Door(double cost) :IOpener("Дверь", cost) {};

    void actionOpen();
    void actionClose();
};

