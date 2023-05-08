#include "NumberPlateScanner.h"

bool NumberPlateScanner::tryToEnter()
{
	return getState()->enter();
}

bool NumberPlateScanner::scanIdentifier()
{
	name();
	cout << "Номерной знак считан!" << endl;
	return sendQuery();
}

string NumberPlateScanner::getRequest()
{
	return "Пожалуйста, разместите автомобиль перед камерой. ";
}
