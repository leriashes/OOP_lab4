#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state) :IReader("����������� ��������� �����", state) {};

    bool tryToEnter();
    bool scanIdentifier();

    string getRequest();
};

