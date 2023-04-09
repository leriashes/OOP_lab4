#pragma once
#include "IOpener.h"
#include "Turnstile.h"
class TurnstileAdapter :
    public IOpener
{
private:
    Turnstile* myTurn;

public:
    TurnstileAdapter(Turnstile* turnstile) :IOpener("Турникет") { myTurn = turnstile; };

    void actionOpen();
    void actionClose();
};

