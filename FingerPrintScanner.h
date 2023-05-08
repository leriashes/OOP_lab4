#pragma once
#include "IReader.h"
class FingerPrintScanner :
    public IReader
{
public:
    FingerPrintScanner(double cost, State* onSt, State* offSt) :IReader("������ ��������� ������", cost, onSt, offSt) {};

    bool tryToEnter();
    bool scanIdentifier();
    string getRequest();
};

