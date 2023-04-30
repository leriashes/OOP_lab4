#include "FingerDisplayFactory.h"

IReader* FingerDisplayFactory::createReader()
{
    IReader* fps = new FingerPrintScanner(true, 8000);
    ISolver* solv = new SimpleSolver();
    fps->setSolver(solv);

    return new DisplayReader(fps, new EngLang("Please, put your finger on the scanner! "), 5000);
}
