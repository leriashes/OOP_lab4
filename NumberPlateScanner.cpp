#include "NumberPlateScanner.h"

void NumberPlateScanner::tryToEnter()
{
	scanIdentifier();
}

void NumberPlateScanner::scanIdentifier()
{
	name();
	cout << "�������� ���� ������!" << endl;
	sendQuery();
}
