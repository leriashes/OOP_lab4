#include "DoorFM.h"

Door* DoorFM::createOpener(double cost)
{
    cout << "Создан объект \"Дверь\", цена: " << cost << endl;
    return new Door(cost);
}
