#include "DisplayReader.h"

bool DisplayReader::tryToEnter()
{
	if (displayState)
	{
		cout << getName() << ", дисплей:\n	";
		hello();
		cout << endl;
	}

	bool result = scanIdentifier();

	if (displayState)
	{
		if (result)
		{
			cout << getName() << ", дисплей:\n	";
			welcome();
			cout << endl;
		}
		else
		{
			cout << getName() << ", дисплей:\n	";
			stop();
			cout << endl;
		}
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

void DisplayReader::info()
{
	cout << getName() << " с дисплеем - цена: " << getCost() << " руб., \nрешатель: ";
	infoSolver();
}
