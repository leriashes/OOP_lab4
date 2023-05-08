#include "OnState.h"

void OnState::on()
{
	cout << "уже включен!" << endl;
}

void OnState::off()
{
	cout << "выключение... Готово!" << endl;
	myReader->setState(myReader->getOffState());
}

bool OnState::enter()
{
	_getch();
	return myReader->scanIdentifier();
}
