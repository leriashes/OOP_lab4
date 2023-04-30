#include "SimpleSolver.h"

bool SimpleSolver::processData()
{
	cout << "���������..." << endl;

	bool result = Database::Instance()->processData();
	sendSolution(result);

	return result;
}

void SimpleSolver::sendSolution(bool res)
{
	map <bool, string> solutions;
	solutions[false] = "������ ��������!";
	solutions[true] = "������ ��������!";

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
	cout << "������� ��������\n";
}

ISolver* SimpleSolver::clone()
{
	ISolver* res = new SimpleSolver(*this);
	res->setOpener(nullptr);

	cout << "������������ �������� ��������...\n" << this << " --clone--> " << res << endl;

	return res;
}

