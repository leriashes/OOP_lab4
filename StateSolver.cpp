#include "StateSolver.h"

void StateSolver::setState(bool s)
{
	stateProcessing = stateActions[s];

	map <bool, string> states;
	states[false] = "Помещение заблокировано";
	states[true] = "Помещение разблокировано";

	cout << states[s] << endl;
}

void StateSolver::processData()
{
	(this->*(stateProcessing))();
}

void StateSolver::startProcessing()
{
	cout << "Обработка..." << endl;

	bool result = rand() % 2;

	sendSolution(result);
}

void StateSolver::stopProcessing() 
{
	cout << "Проход запрещён!" << endl;
}

void StateSolver::sendSolution(bool res)
{
	map <bool, string> solutions;
	solutions[false] = "Проход запрещён!";
	solutions[true] = "Проход разрешён!";

	cout << solutions[res] << endl;

	if (res)
	{
		allowOpen();
	}
	else
	{
		forbidOpen();
	}
}