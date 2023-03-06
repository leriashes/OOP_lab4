#include <iostream>
#include <string>
#include "IRoom.h"
#include "Door.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    ISolver solv;

    IRoom cabinet("Кабинет", &solv);
    cabinet.name();

    Door door;
    cabinet.setOpener(&door);



    return 0;
}
