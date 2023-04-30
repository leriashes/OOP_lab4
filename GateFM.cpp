#include "GateFM.h"

Gate* GateFM::createOpener(double cost)
{
    return new Gate(cost);
}
