#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state, double cost) :IReader("����������� ��������� �����", state, cost) {};

    bool tryToEnter();
    bool scanIdentifier();

    string getRequest();
};

