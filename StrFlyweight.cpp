#include "StrFlyweight.h"

StrFlyweight::StrFlyweight(string message)
{
	myMessage = message;
}

string StrFlyweight::getMessage(string addMessage)
{
	return myMessage + ' ' + addMessage;
}
