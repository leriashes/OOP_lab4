#include "OpenerFM.h"

IOpener* OpenerFM::cloneOpener(IOpener* opener)
{
    cout << "����������� ������� \"" << opener->getName() << "\" (����: " << opener->getCost() << ") - ";
    return createOpener(opener->getCost());
}
