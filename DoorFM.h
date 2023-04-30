#pragma once
#include "OpenerFM.h"
#include "Door.h"
class DoorFM :
    public OpenerFM
{
public:
    DoorFM() :OpenerFM() {}
    virtual Door* createOpener(double cost);
};

