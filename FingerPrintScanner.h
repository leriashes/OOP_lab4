#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(bool state) :IReader("������ ��������� ������", state) {};

    void tryToEnter();
    void scanIdentifier();
};

