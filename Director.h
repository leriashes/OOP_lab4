#pragma once
#include "Builder.h"

class Director
{
private:
	Builder* myBuilder;

public:
	Director(Builder* builder);
	IRoom* constructRoom();
};

