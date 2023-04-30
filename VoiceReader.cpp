#include "VoiceReader.h"

bool VoiceReader::tryToEnter()
{
	cout << getName() << ", озвучка:\n	Здравствуйте! " << getRequest() << endl;
	bool result = scanIdentifier();
	
	if (result)
		cout << getName() << ", озвучка:\n	Проходите! " << endl;
	else
		cout << getName() << ", озвучка:\n	Проход запрещён! " << endl;

	return result;
}

bool VoiceReader::scanIdentifier()
{
	return AdditionalReader::tryToEnter();
}

void VoiceReader::info()
{
	cout << getName() << " с озвучкой - цена: " << getCost() << " руб., \n";
	infoSolver();
}
