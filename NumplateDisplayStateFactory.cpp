#include "NumplateDisplayStateFactory.h"

IReader* NumplateDisplayStateFactory::createReader()
{
    IReader* nps = new NumberPlateScanner(8500, new OnState(), new OffState());
    ISolver* solv = new StateSolver(true);
    nps->setSolver(solv);

    return new DisplayReader(nps, new EngLang("Please, position the car in front of the scanner! "), 5000);
}
