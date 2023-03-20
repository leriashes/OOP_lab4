#pragma once
#include "IReader.h"
class ProxyReader :
    public IReader
{
private:
    IReader* myReader;

public:
    ProxyReader(IReader* reader) :IReader("—читыватель номерного знака") {myReader = reader;};
};

