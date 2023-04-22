#pragma once
#include "LangReader.h"
class EngLang :
    public LangReader
{
public:
	EngLang() :LangReader("English "){};

	void printHello();
	void printWelcome();
	void printStop();
};

