#include <iostream>
#include <string>
#include "IRoom.h"
#include "Door.h"
#include "FingerPrintScanner.h"
#include "SimpleSolver.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    SimpleSolver solv;
    Door door;
    FingerPrintScanner finger_scan;


    IRoom cabinet("Кабинет", &solv, &door, &finger_scan);
    cabinet.name();

    finger_scan.tryToEnter();

    return 0;
}
