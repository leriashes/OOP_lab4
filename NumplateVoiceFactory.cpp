#include "NumplateVoiceFactory.h"

IReader* NumplateVoiceFactory::createReader()
{
    IReader* nps = new NumberPlateScanner(7300, new OnState(), new OffState());
    ISolver* solv = new SimpleSolver();
    nps->setSolver(solv);

    return new VoiceReader(nps, new EngLang("Please, position the car in front of the scanner! "), 1500);
}
