#include "DisplayReader.h"

bool DisplayReader::tryToEnter()
{
	if (displayState)
	{
		cout << getName() << ", �������:\n	";
		hello();
		cout << endl;
	}

	bool result = scanIdentifier();

	if (displayState)
	{
		if (result)
		{
			cout << getName() << ", �������:\n	";
			welcome();
			cout << endl;
		}
		else
		{
			cout << getName() << ", �������:\n	";
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
	cout << getName() << ": ������� ��������" << endl;
}

void DisplayReader::trunOn()
{
	displayState = false;
	cout << getName() << ": ������� �������" << endl;
}

void DisplayReader::info()
{
	cout << getName() << " � �������� - ����: " << getCost() << " ���., \n��������: ";
	infoSolver();
}
