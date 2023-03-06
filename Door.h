#pragma once
#include "IOpener.h"
class Door : public IOpener
{
  
public:
    Door():IOpener("Дверь") {};

    void actionOpen();
    void actionClose();
};

