#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner() :IReader("—читыватель номерного знака") {};

    void tryToEnter();
    void scanIdentifier();
};

