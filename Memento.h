#pragma once
class LangReader;

class Memento
{
public:
	Memento(bool dispState, LangReader* lang);

	bool displayState;
	LangReader* language;
};

