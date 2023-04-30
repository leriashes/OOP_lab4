#pragma once
#include "IReaderFactory.h"
#include "FingerPrintScanner.h"
#include "StateSolver.h"

class FingerStateFactory :
    public IReaderFactory
{
public:
    virtual IReader* createReader();
};

