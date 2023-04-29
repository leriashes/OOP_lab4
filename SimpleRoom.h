#pragma once
#include <iostream>
#include <string>
#include "IRoom.h"
using namespace std;

class SimpleRoom :
    public IRoom
{
public:
    SimpleRoom(string name, ISolver* solv, IOpener* o, IReader* r) :IRoom(name, solv, o, r) {};

    void getComposite();
    double getTotalCost();
};

