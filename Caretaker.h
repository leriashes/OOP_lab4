#pragma once
#include <stack>
using namespace std;

class Memento;

class Caretaker
{
private:
    stack<Memento*>* history;

public:
    Caretaker();
    ~Caretaker();

    void push(Memento* snap);
    Memento* pop();
};

