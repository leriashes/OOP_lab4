#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner() :IReader("Сканер отпечатка пальца") {};

    void tryToEnter();
    void scanIdentifier();
};

