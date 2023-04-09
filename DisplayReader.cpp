#include "DisplayReader.h"

bool DisplayReader::tryToEnter()
{
	if (displayState) 
		cout << getName() << ", �������:\n	������������! " << getRequest() << endl;

	bool result = scanIdentifier();

	if (displayState)
	{
		if (result)
			cout << getName() << ", �������:\n	���������! " << endl;
		else
			cout << getName() << ", �������:\n	������ ��������! " << endl;
	}

	return result;
}

bool DisplayReader::scanIdentifier()
{
	return AdditionalReader::tryToEnter();
}

void DisplayReader::turnOff()
{
	displayState = false;
	cout << getName() << ": ������� ��������" << endl;
}

void DisplayReader::trunOn()
{
	displayState = false;
	cout << getName() << ": ������� �������" << endl;
}
