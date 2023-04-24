#pragma once
#include "LangReader.h"
class RusLang :
    public LangReader
{
public:
	RusLang(StrFlyFactory* fact, string request) :LangReader("Русский ", "Здравствуйте! ", "Проходите! ", "Проход запрещён! ", request, fact) {};
};

