#include "DisplayReader.h"

DisplayReader::~DisplayReader()
{
	delete myStates;
}

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
	cout << getName() << " � �������� - ����: " << getCost() << " ���., \n";
	infoSolver();
}

void DisplayReader::saveState()
{
	cout << "\n���������� �������� ���������...\n";
	myStates->push(new Memento(displayState, getLanguage()));
}

void DisplayReader::restoreState()
{
	cout << "\n�������������� ����������� ���������...\n";
	Memento* snap = myStates->pop();

	displayState = snap->displayState;
	setLanguage(snap->language);

	delete snap;
}