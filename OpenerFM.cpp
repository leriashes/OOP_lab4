#include "OpenerFM.h"

IOpener* OpenerFM::cloneOpener(IOpener* opener)
{
    return createOpener(opener->getCost());
}
