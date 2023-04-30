#pragma once
#include "AdditionalReader.h"
class DisplayReader :
    public AdditionalReader
{
private:
    bool displayState;
public:
    DisplayReader(IReader* reader, LangReader* lang, double cost) :AdditionalReader(reader, lang,  reader->getName() + " + дисплей", cost) { displayState = true; };

    bool tryToEnter();
    bool scanIdentifier();

    void turnOff();
    void trunOn();

    void info();
};

