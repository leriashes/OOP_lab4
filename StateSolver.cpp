#include "StateSolver.h"

void StateSolver::setState(bool s)
{
	stateProcessing = stateActions[s];

	map <bool, string> states;
	states[false] = "��������� �������������";
	states[true] = "��������� ��������������";

	cout << states[s] << endl;
}

void StateSolver::processData()
{
	(this->*(stateProcessing))();
}

void StateSolver::startProcessing()
{
	cout << "���������..." << endl;

	bool result = rand() % 2;

	sendSolution(result);
}

void StateSolver::stopProcessing() 
{
	cout << "������ ��������!" << endl;
}

void StateSolver::sendSolution(bool res)
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