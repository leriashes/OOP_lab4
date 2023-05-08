#pragma once
#include "IReader.h"
#include "LangReader.h"
#include "OnState.h"
#include "OffState.h"

class AdditionalReader :
    public IReader
{
private:
    IReader* myReader;
    LangReader* myLanguage;

public:
    AdditionalReader(IReader* reader, LangReader* language, string name, double cost) :IReader(name, reader->getCost() + cost, new OnState(), new OffState())
    {   myReader = reader; 
        myLanguage = language;
    };

    void setLanguage(LangReader* language);
    void setReader(IReader* reader);

    string getName();

    void setSolver(ISolver* s);
    void setState(State* state);

    State* getState();
    State* getOnState();
    State* getOffState();

    string getRequest();

    void infoSolver();

    virtual bool tryToEnter();
    virtual bool scanIdentifier();

    void hello();
    void welcome();
    void stop();
};

