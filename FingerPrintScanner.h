#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(bool state, double cost) :IReader("������ ��������� ������", state, cost) {};

    bool tryToEnter();
    bool scanIdentifier();
    string getRequest();
};

