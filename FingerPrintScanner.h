#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner() :IReader("������ ��������� ������") {};

    void tryToEnter();
    void scanIdentifier();
};

