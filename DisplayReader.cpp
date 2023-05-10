#include "DisplayReader.h"

DisplayReader::~DisplayReader()
{
	delete myStates;
}

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
	cout << getName() << " с дисплеем - цена: " << getCost() << " руб., \n";
	infoSolver();
}

void DisplayReader::saveState()
{
	cout << "\nСохранение текущего состояния...\n";
	myStates->push(new Memento(displayState, getLanguage()));
}

void DisplayReader::restoreState()
{
	cout << "\nВосстановление предыдущего состояния...\n";
	Memento* snap = myStates->pop();

	displayState = snap->displayState;
	setLanguage(snap->language);

	delete snap;
}