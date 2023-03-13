#include "SimpleSolver.h"

void SimpleSolver::processData()
{
	cout << "Обработка..." << endl;

	bool result = rand() % 2;

	sendSolution(result);
}

void SimpleSolver::sendSolution(bool res)
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

void SimpleSolver::setState(bool state)
{
	cout << "Невозможно изменить состояние..." << endl;
}

