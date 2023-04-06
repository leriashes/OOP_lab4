#pragma once
#include <iostream>
#include <list>
#include "IRoom.h"

class CompositeRoom :
    public IRoom
{
private:
    list<IRoom*> children;

public:
    void add(IRoom* room);
    void remove(IRoom* room);
};

