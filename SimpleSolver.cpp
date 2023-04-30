#include "SimpleSolver.h"

bool SimpleSolver::processData()
{
	cout << "Обработка..." << endl;

	bool result = rand() % 2;

	sendSolution(result);

	return result;
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

}

void SimpleSolver::info()
{
	cout << "простой\n";
}

ISolver* SimpleSolver::clone()
{
	cout << "Клонирование простого решателя...\n";
	ISolver* res = new SimpleSolver(*this);
	res->setOpener(nullptr);

	return res;
}

