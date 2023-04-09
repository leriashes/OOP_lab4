#include "AdditionalReader.h"

void AdditionalReader::setReader(IReader* reader)
{
    myReader = reader;
}

string AdditionalReader::getName()
{
    return myReader->getName();
}

void AdditionalReader::setSolver(ISolver* s)
{
    myReader->setSolver(s);
}

void AdditionalReader::setState(bool st)
{
    myReader->setState(st);
}

bool AdditionalReader::getState()
{
    return myReader->getState();
}

string AdditionalReader::getRequest()
{
    return myReader->getRequest();
}

bool AdditionalReader::tryToEnter()
{
    return myReader->tryToEnter();
}

bool AdditionalReader::scanIdentifier()
{
    return myReader->scanIdentifier();
}
