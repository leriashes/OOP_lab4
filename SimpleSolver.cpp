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

	map <bool, void (ISolver::*)() > actions;
	actions[false] = &ISolver::forbidOpen;
	actions[true] = &ISolver::allowOpen;

	(this->*(actions[res]))();
}

void SimpleSolver::setState(bool state)
{
	cout << "Невозможно изменить состояние..." << endl;
}

