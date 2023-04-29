#pragma once
#include "IOpener.h"
#include "Turnstile.h"
class TurnstileAdapter :
    public IOpener
{
private:
    Turnstile* myTurn;

public:
    TurnstileAdapter(Turnstile* turnstile, double cost) :IOpener("��������", cost) { myTurn = turnstile; };

    void actionOpen();
    void actionClose();
};

