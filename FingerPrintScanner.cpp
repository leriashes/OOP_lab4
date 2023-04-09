#include "FingerPrintScanner.h"

bool FingerPrintScanner::tryToEnter()
{
	_getch();
	return scanIdentifier();
}

bool FingerPrintScanner::scanIdentifier()
{
	name();
	cout << "Отпечаток пальца считан!" << endl;
	return sendQuery();
}

string FingerPrintScanner::getRequest()
{
	return "Пожалуйста, приложите Ваш палец. ";
}

