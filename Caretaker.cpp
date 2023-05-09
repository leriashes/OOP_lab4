#include "Caretaker.h"

Caretaker::Caretaker()
{
	history = new stack<Memento*>();
}

Caretaker::~Caretaker()
{
	while (!history->empty())
	{
		delete history->top();
		history->pop();
	}

	delete history;
}

void Caretaker::push(Memento* snap)
{
	history->push(snap);
}

Memento* Caretaker::pop()
{
	Memento* h = history->top();
	history->pop();
	return h;
}
