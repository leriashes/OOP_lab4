#include "OnState.h"

void OnState::on()
{
	cout << "��� �������!" << endl;
}

void OnState::off()
{
	cout << "����������... ������!" << endl;
	myReader->setState(myReader->getOffState());
}

bool OnState::enter()
{
	_getch();
	return myReader->scanIdentifier();
}
