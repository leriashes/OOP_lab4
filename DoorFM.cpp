#include "DoorFM.h"

Door* DoorFM::createOpener(double cost)
{
    cout << "������ ������ \"�����\", ����: " << cost << endl;
    return new Door(cost);
}
