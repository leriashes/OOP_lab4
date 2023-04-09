#include "StateSolver.h"

void StateSolver::setState(bool s)
{
	stateProcessing = stateActions[s];

	map <bool, string> states;
	states[false] = "��������� �������������";
	states[true] = "��������� ��������������";

	cout << states[s] << endl;
}

bool StateSolver::processData()
{
	return (this->*(stateProcessing))();
}

bool StateSolver::startProcessing()
{
	cout << "���������..." << endl;

	bool result = rand() % 2;

	sendSolution(result);

	return result;
}

bool StateSolver::stopProcessing() 
{
	cout << "������ ��������!" << endl;
	return false;
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