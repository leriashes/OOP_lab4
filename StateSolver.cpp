#include "StateSolver.h"

void StateSolver::setState(bool s)
{
	stateProcessing = stateActions[s];

	map <bool, string> states;
	states[false] = "Помещение заблокировано";
	states[true] = "Помещение разблокировано";

	cout << states[s] << endl;
}

bool StateSolver::processData()
{
	return (this->*(stateProcessing))();
}

bool StateSolver::startProcessing()
{
	cout << "Обработка..." << endl;

	bool result = rand() % 2;

	sendSolution(result);

	return result;
}

bool StateSolver::stopProcessing() 
{
	cout << "Проход запрещён!" << endl;
	return false;
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