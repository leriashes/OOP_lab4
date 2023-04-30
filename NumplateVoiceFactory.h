#pragma once
#include "IReaderFactory.h"
#include "NumberPlateScanner.h"
#include "SimpleSolver.h"
#include "VoiceReader.h"
#include "EngLang.h"

class NumplateVoiceFactory :
    public IReaderFactory
{
public:
    virtual IReader* createReader();
};

