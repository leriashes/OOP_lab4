#pragma once
#include "AdditionalReader.h"
class VoiceReader :
    public AdditionalReader
{
public:
    VoiceReader(IReader* reader) :AdditionalReader(reader, reader->getName() + " + �������") {};

    bool tryToEnter();
    bool scanIdentifier();
};

