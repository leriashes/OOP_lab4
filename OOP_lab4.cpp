#include <iostream>
#include <string>
#include <time.h>
#include "SimpleRoom.h"
#include "Door.h"
#include "Gate.h"
#include "FingerPrintScanner.h"
#include "NumberPlateScanner.h"
#include "SimpleSolver.h"
#include "StateSolver.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    ISolver* solv = new SimpleSolver(), * stSolv = new StateSolver(false);
    IOpener* door = new Door(), *gate = new Gate();
    IReader* fingerScan = new FingerPrintScanner(), *numplateScan = new NumberPlateScanner();
    IRoom* cabinet = new SimpleRoom("Кабинет", solv, door, fingerScan), * garage = new SimpleRoom("Гараж", stSolv, gate, numplateScan);
    
    cabinet->name();
    fingerScan->tryToEnter();
    cout << endl;

    fingerScan->tryToEnter();
    cout << endl << endl;


    garage->name();
    numplateScan->tryToEnter();
    cout << endl;

    stSolv->setState(true);
    numplateScan->tryToEnter();
    cout << endl;

    numplateScan->tryToEnter();
    cout << endl << endl;


    ISolver* stSolv1 = new StateSolver(true);
    cabinet->setSolver(stSolv1);

    cabinet->name();
    fingerScan->tryToEnter();
    cout << endl;

    cabinet->name();
    fingerScan->tryToEnter();
    cout << endl;

    stSolv1->setState(false);
    fingerScan->tryToEnter();

    return 0;
}
