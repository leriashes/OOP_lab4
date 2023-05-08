#include "OffState.h"

void OffState::on()
{
	cout << "включение... Готово!" << endl;
	myReader->setState(myReader->getOnState());
}

void OffState::off()
{
	cout << "выключен." << endl;
}

bool OffState::enter()
{
	cout << "Устройство отключено..." << endl;
	return false;
}
