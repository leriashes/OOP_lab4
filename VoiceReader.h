#pragma once
#include "AdditionalReader.h"
class VoiceReader :
    public AdditionalReader
{
public:
    VoiceReader(IReader* reader, LangReader* lang) :AdditionalReader(reader, lang, reader->getName() + " + �������") {};

    bool tryToEnter();
    bool scanIdentifier();
};

