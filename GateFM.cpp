#include "GateFM.h"

Gate* GateFM::createOpener(double cost)
{
    cout << "������ ������ \"������\", ����: " << cost << " ���." << endl;
    return new Gate(cost);
}
