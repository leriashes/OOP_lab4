#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner(bool state) :IReader("����������� ��������� �����", state) {};

    void tryToEnter();
    void scanIdentifier();
};

