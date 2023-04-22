#pragma once
#include "IReader.h"
#include "LangReader.h"
class AdditionalReader :
    public IReader
{
private:
    IReader* myReader;
    LangReader* myLanguage;

public:
    AdditionalReader(IReader* reader, LangReader* language, string name) :IReader(name, true) 
    {   myReader = reader; 
        myLanguage = language;
    };

    void setLanguage(LangReader* language);

    void setReader(IReader* reader);
    string getName();
    void setSolver(ISolver* s);
    void setState(bool st);
    bool getState();
    string getRequest();

    virtual bool tryToEnter();
    virtual bool scanIdentifier();

    void hello();
    void welcome();
    void stop();
};

