#include "FingerPrintScanner.h"

bool FingerPrintScanner::tryToEnter()
{
	return getState()->enter();
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

