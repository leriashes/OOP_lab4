#include "FingerStateFactory.h"

IReader* FingerStateFactory::createReader()
{
    StateSolver* solv = new StateSolver(true);
    FingerPrintScanner* res = new FingerPrintScanner(10500, new OnState(), new OffState());
    res->setSolver(solv);
    return res;
}
