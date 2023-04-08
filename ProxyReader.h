#pragma once
#include "IReader.h"
class ProxyReader :
    public IReader
{
private:
    IReader* myReader;

public:
    ProxyReader(IReader* reader) :IReader("Прокси", true) {myReader = reader;};

    void setReader(IReader* reader);
    void tryToEnter();
    void scanIdentifier();
    void setState(bool st);
    void setSolver(ISolver* solver);
    bool getState();
};

