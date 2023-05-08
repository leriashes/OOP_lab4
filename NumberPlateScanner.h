#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(double cost, State* onSt, State* offSt) :IReader("����������� ��������� �����", cost, onSt, offSt) {};

    bool tryToEnter();
    bool scanIdentifier();

    string getRequest();
};

