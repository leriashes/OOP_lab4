#include "OffState.h"

void OffState::on()
{
	cout << "���������... ������!" << endl;
	myReader->setState(myReader->getOnState());
}

void OffState::off()
{
	cout << "��������." << endl;
}

bool OffState::enter()
{
	cout << "���������� ���������..." << endl;
	return false;
}
