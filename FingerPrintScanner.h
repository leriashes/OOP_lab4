#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(double cost, State* onSt, State* offSt) :IReader("Сканер отпечатка пальца", cost, onSt, offSt) {};

    bool tryToEnter();
    bool scanIdentifier();
    string getRequest();
};

