#include "DoorFM.h"

Door* DoorFM::createOpener(double cost)
{
    return new Door(cost);
}
