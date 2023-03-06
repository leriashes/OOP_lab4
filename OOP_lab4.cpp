#include <iostream>
#include <string>
#include "IRoom.h"
#include "Door.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    IRoom cabinet("Кабинет");
    cabinet.name();

    Door door;
    cabinet.setOpener(&door);



    return 0;
}
