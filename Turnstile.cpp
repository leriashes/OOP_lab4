#include "Turnstile.h"

void Turnstile::unlock()
{
	cout << "Турникет разблокирован " << endl;
}

void Turnstile::block()
{
	cout << "Турникет заблокирован " << endl;
}

void Turnstile::greenLight()
{
	cout << "*зелёный свет* ";
}

void Turnstile::redLight()
{
	cout << "*красный свет* ";
}


