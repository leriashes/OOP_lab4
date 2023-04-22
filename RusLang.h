#pragma once
#include "LangReader.h"
class RusLang :
    public LangReader
{
public:
	RusLang() :LangReader("Русский ") {};

	void printHello();
	void printWelcome();
	void printStop();
};

