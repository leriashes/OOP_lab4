#include "NumberPlateScanner.h"

bool NumberPlateScanner::tryToEnter()
{
	_getch();
	return scanIdentifier();
}

bool NumberPlateScanner::scanIdentifier()
{
	name();
	cout << "�������� ���� ������!" << endl;
	return sendQuery();
}

string NumberPlateScanner::getRequest()
{
	return "����������, ���������� ���������� ����� �������. ";
}
