#include "DoorFM.h"

Door* DoorFM::createOpener(double cost)
{
    cout << "Создан объект \"Дверь\", цена: " << cost << " руб." << endl;
    return new Door(cost);
}
