#pragma once
#include "LangReader.h"
class RusLang :
    public LangReader
{
public:
	RusLang(StrFlyFactory* fact, string request) :LangReader("������� ", "������������! ", "���������! ", "������ ��������! ", request, fact) {};
};

