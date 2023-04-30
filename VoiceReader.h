#pragma once
#include "AdditionalReader.h"
class VoiceReader :
    public AdditionalReader
{
public:
    VoiceReader(IReader* reader, LangReader* lang, double cost) :AdditionalReader(reader, lang, reader->getName() + " + озвучка", cost) {};

    bool tryToEnter();
    bool scanIdentifier();
    void info();
};

