#include "NumberPlateScanner.h"

bool NumberPlateScanner::tryToEnter()
{
	return getState()->enter();
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
