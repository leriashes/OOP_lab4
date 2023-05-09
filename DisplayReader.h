#pragma once
#include "AdditionalReader.h"
#include "Memento.h"
#include "Caretaker.h"

class DisplayReader :
    public AdditionalReader
{
private:
    bool displayState;
    Caretaker* myStates;

public:
    DisplayReader(IReader* reader, LangReader* lang, double cost) :AdditionalReader(reader, lang, reader->getName() + " + дисплей", cost) { displayState = true; myStates = new Caretaker(); };
    ~DisplayReader();

    bool tryToEnter();
    bool scanIdentifier();

    void turnOff();
    void trunOn();

    void info();

    void saveState();
    void restoreState();
};

