#pragma once
#include "IReader.h"
#include "OnState.h"
#include "OffState.h"

class ProxyReader :
    public IReader
{
private:
    IReader* myReader;

public:
    ProxyReader(IReader* reader) :IReader("Прокси", reader->getCost(), new OnState(), new OffState()) {myReader = reader;};

    void setReader(IReader* reader);

    bool tryToEnter();
    bool scanIdentifier();

    void setState(State* state);
    void setSolver(ISolver* solver);

    State* getState();
    State* getOnState();
    State* getOffState();

    string getName();
    string getRequest();
};

