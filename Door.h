#pragma once
#include "IOpener.h"
class Door : public IOpener
{
  
public:
    Door():IOpener("�����") {};

    void actionOpen();
    void actionClose();
};

