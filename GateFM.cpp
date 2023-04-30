#include "GateFM.h"

Gate* GateFM::createOpener(double cost)
{
    cout << "Создан объект \"Ворота\", цена: " << cost << " руб." << endl;
    return new Gate(cost);
}
