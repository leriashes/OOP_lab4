#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state) :IReader("—читыватель номерного знака", state) {};

    bool tryToEnter();
    bool scanIdentifier();

    string getRequest();
};

