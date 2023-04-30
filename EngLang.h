#pragma once
#include "LangReader.h"
class EngLang :
    public LangReader
{
public:
	EngLang(StrFlyFactory* fact, string request) :LangReader("English ", "Hello! ", "Pass on, please! ", "No entrance! ", request, fact) {};
	EngLang(string request) :LangReader("English ", "Hello! ", "Pass on, please! ", "No entrance! ", request) {};
};

