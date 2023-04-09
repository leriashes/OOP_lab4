#include "DisplayReader.h"

bool DisplayReader::tryToEnter()
{
	if (displayState) 
		cout << getName() << ", дисплей:\n	Здравствуйте! " << getRequest() << endl;

	bool result = scanIdentifier();

	if (displayState)
	{
		if (result)
			cout << getName() << ", дисплей:\n	Проходите! " << endl;
		else
			cout << getName() << ", дисплей:\n	Проход запрещён! " << endl;
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
	cout << getName() << ": дисплей отключен" << endl;
}

void DisplayReader::trunOn()
{
	displayState = false;
	cout << getName() << ": дисплей включен" << endl;
}
