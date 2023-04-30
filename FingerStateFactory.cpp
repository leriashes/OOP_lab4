#include "FingerStateFactory.h"

IReader* FingerStateFactory::createReader()
{
    StateSolver* solv = new StateSolver(true);
    FingerPrintScanner* res = new FingerPrintScanner(true, 10500);
    res->setSolver(solv);
    return res;
}
