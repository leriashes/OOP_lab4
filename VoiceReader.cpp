#include "VoiceReader.h"

bool VoiceReader::tryToEnter()
{
	cout << getName() << ", �������:\n	������������! " << getRequest() << endl;
	bool result = scanIdentifier();
	
	if (result)
		cout << getName() << ", �������:\n	���������! " << endl;
	else
		cout << getName() << ", �������:\n	������ ��������! " << endl;

	return result;
}

bool VoiceReader::scanIdentifier()
{
	return AdditionalReader::tryToEnter();
}

void VoiceReader::info()
{
	cout << getName() << " � �������� - ����: " << getCost() << " ���., \n";
	infoSolver();
}
