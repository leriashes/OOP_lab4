#include "FingerPrintScanner.h"

bool FingerPrintScanner::tryToEnter()
{
	_getch();
	return scanIdentifier();
}

bool FingerPrintScanner::scanIdentifier()
{
	name();
	cout << "��������� ������ ������!" << endl;
	return sendQuery();
}

string FingerPrintScanner::getRequest()
{
	return "����������, ��������� ��� �����. ";
}

