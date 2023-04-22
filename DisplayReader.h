#pragma once
#include "AdditionalReader.h"
class DisplayReader :
    public AdditionalReader
{
private:
    bool displayState;
public:
    DisplayReader(IReader* reader, LangReader* lang) :AdditionalReader(reader, lang,  reader->getName() + " + дисплей") { displayState = true; };

    bool tryToEnter();
    bool scanIdentifier();

    void turnOff();
    void trunOn();
};

