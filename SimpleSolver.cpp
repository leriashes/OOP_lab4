#include "SimpleSolver.h"

bool SimpleSolver::processData()
{
	cout << "Обработка..." << endl;

	bool result = Database::Instance()->processData();
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
	cout << "Простой решатель\n";
}

ISolver* SimpleSolver::clone()
{
	ISolver* res = new SimpleSolver(*this);
	res->setOpener(nullptr);

	cout << "Клонирование простого решателя...\n" << this << " --clone--> " << res << endl;

	return res;
}

