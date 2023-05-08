#include "FingerDisplayFactory.h"

IReader* FingerDisplayFactory::createReader()
{
    IReader* fps = new FingerPrintScanner(8000, new OnState(), new OffState());
    ISolver* solv = new SimpleSolver();
    fps->setSolver(solv);

    return new DisplayReader(fps, new EngLang("Please, put your finger on the scanner! "), 5000);
}
