#include "NumberPlateScanner.h"

void NumberPlateScanner::tryToEnter()
{
	scanIdentifier();
}

void NumberPlateScanner::scanIdentifier()
{
	name();
	cout << "Номерной знак считан!" << endl;
	sendQuery();
}
