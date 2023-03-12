#include "FingerPrintScanner.h"

void FingerPrintScanner::tryToEnter()
{
	scanIdentifier();
}

void FingerPrintScanner::scanIdentifier()
{
	name();
	cout << "Отпечаток пальца считан!" << endl;
	sendQuery();
}

