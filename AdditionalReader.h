#pragma once
#include "IReader.h"
class AdditionalReader :
    public IReader
{
private:
    IReader* myReader;

public:
    AdditionalReader(IReader* reader, string name) :IReader(name, true) { myReader = reader; };

    void setReader(IReader* reader);
    string getName();
    void setSolver(ISolver* s);
    void setState(bool st);
    bool getState();
    string getRequest();

    virtual bool tryToEnter();
    virtual bool scanIdentifier();
};

