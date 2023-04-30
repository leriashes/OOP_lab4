#include "NumplateDisplayStateFactory.h"

IReader* NumplateDisplayStateFactory::createReader()
{
    IReader* nps = new NumberPlateScanner(true, 8500);
    ISolver* solv = new StateSolver(true);
    nps->setSolver(solv);

    return new DisplayReader(nps, new EngLang("Please, position the car in front of the scanner! "), 5000);
}
