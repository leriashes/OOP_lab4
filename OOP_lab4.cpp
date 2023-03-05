#include <iostream>
#include <string>
#include "IRoom.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    IRoom room1("Кабинет");
    room1.getName();
}
