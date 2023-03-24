#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state) :IReader("—читыватель номерного знака", state) {};

    void tryToEnter();
    void scanIdentifier();
};

