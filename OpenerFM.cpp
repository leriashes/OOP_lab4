#include "OpenerFM.h"

IOpener* OpenerFM::cloneOpener(IOpener* opener)
{
    cout << "Копирование объекта \"" << opener->getName() << "\" (цена: " << opener->getCost() << " руб.) - ";
    return createOpener(opener->getCost());
}
