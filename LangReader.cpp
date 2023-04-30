#include "LangReader.h"

LangReader::LangReader(string name, string shello, string swelcome, string sstop, string request, StrFlyFactory* fact)
{
	myName = name;
	hello = fact->getStr(shello);
	welcome = fact->getStr(swelcome);
	stop = fact->getStr(sstop);
	myRequest = request;
}

LangReader::LangReader(string name, string shello, string swelcome, string sstop, string request)
{
	myName = name;
	hello = new StrFlyweight(shello);
	welcome = new StrFlyweight(swelcome);
	stop = new StrFlyweight(sstop);
	myRequest = request;
}

string LangReader::getName()
{
	return myName;
}

void LangReader::printHello()
{
	cout << hello->getMessage(myRequest);
}

void LangReader::printWelcome()
{
	cout << welcome->getMessage("");
}

void LangReader::printStop()
{
	cout << stop->getMessage("");
}
