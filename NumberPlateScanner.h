#pragma once
#include "IReader.h"
class NumberPlateScanner :
    public IReader
{
public:
    NumberPlateScanner() :IReader("����������� ��������� �����") {};

    void tryToEnter();
    void scanIdentifier();
};

