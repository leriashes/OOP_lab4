#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state, double cost) :IReader("—читыватель номерного знака", state, cost) {};

    bool tryToEnter();
    bool scanIdentifier();

    string getRequest();
};

