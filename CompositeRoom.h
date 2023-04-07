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
    CompositeRoom(string name, ISolver* solv, IOpener* o, IReader* r) :IRoom(name, solv, o, r) {};

    void add(IRoom* room);
    void remove(IRoom* room);

    void turnOnReader();
    void turnOffReader();

    void getComposite();
};

