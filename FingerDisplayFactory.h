#pragma once
#include "IReaderFactory.h"
#include "FingerPrintScanner.h"
#include "DisplayReader.h"
#include "EngLang.h"
#include "SimpleSolver.h"

class FingerDisplayFactory :
    public IReaderFactory
{
public:
    virtual IReader* createReader();
};

