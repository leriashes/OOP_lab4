#pragma once
#include "AdditionalReader.h"
class VoiceReader :
    public AdditionalReader
{
public:
    VoiceReader(IReader* reader) :AdditionalReader(reader, reader->getName() + " + озвучка") {};

    bool tryToEnter();
    bool scanIdentifier();
};

