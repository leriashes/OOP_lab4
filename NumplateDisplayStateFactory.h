#pragma once
#include "IReaderFactory.h"
#include "DisplayReader.h"
#include "NumberPlateScanner.h"
#include "StateSolver.h"
#include "EngLang.h"

class NumplateDisplayStateFactory :
    public IReaderFactory
{
public:
    virtual IReader* createReader();
};

