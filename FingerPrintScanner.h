#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(bool state, double cost) :IReader("Сканер отпечатка пальца", state, cost) {};

    bool tryToEnter();
    bool scanIdentifier();
    string getRequest();
};

