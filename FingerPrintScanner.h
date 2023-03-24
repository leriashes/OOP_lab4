#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(bool state) :IReader("Сканер отпечатка пальца", state) {};

    void tryToEnter();
    void scanIdentifier();
};

