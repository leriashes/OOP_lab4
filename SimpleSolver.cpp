#include "SimpleSolver.h"

bool SimpleSolver::processData()
{
	cout << "���������..." << endl;

	bool result = rand() % 2;

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
	cout << "���������� �������� ���������..." << endl;
}

