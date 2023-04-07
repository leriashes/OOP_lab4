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
#include "ProxyReader.h"
#include "CompositeRoom.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    ISolver* solv = new SimpleSolver(), * stSolv = new StateSolver(false);
    IOpener* door = new Door(), *gate = new Gate();
    IReader* fingerScan = new FingerPrintScanner(true), *numplateScan = new NumberPlateScanner(true);
    IRoom* cabinet = new SimpleRoom("Кабинет", solv, door, fingerScan), * garage = new SimpleRoom("Гараж", stSolv, gate, numplateScan);
    
    IRoom* cabinet1 = new SimpleRoom("Кабинет 1", solv, door, fingerScan), * cabinet2 = new SimpleRoom("Кабинет 2", solv, door, fingerScan);

    CompositeRoom* base = new CompositeRoom("База", solv, door, fingerScan);
    CompositeRoom* complex1 = new CompositeRoom("Корпус А", solv, door, fingerScan);
    CompositeRoom* complex2 = new CompositeRoom("Корпус Б", solv, door, fingerScan);

    /*cabinet->name();
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

    fingerScan->tryToEnter();
    cout << endl;

    stSolv1->setState(false);
    fingerScan->tryToEnter();
    cout << endl << endl;*/


    /*IReader* proxyScan1 = new ProxyReader(numplateScan), * proxyScan2 = new ProxyReader(fingerScan);
    garage->setReader(proxyScan1);

    garage->name();
    proxyScan1->tryToEnter();
    cout << endl;

    numplateScan->setState(false);

    proxyScan1->tryToEnter();
    cout << endl << endl;


    cabinet->setReader(proxyScan2);

    cabinet->name();
    proxyScan2->tryToEnter();
    cout << endl;

    fingerScan->setState(false);

    proxyScan2->tryToEnter();
    cout << endl;

    stSolv1->setState(false);
    proxyScan2->tryToEnter();
    cout << endl;

    fingerScan->setState(true);

    proxyScan2->tryToEnter();
    cout << endl;

    stSolv1->setState(true);
    proxyScan2->tryToEnter();
    cout << endl;
    */


    complex1->add(cabinet);
    complex1->add(garage);
    complex1->getComposite();

    complex2->add(cabinet1);
    complex2->add(cabinet2);
    complex2->getComposite();

    complex2->turnOffReader();
    complex1->turnOnReader();

    base->add(complex1);
    base->add(complex2);

    base->getComposite();

    delete cabinet;
    delete garage;

    //delete proxyScan1;
    //delete proxyScan2;

    delete fingerScan;
    delete numplateScan;

    delete solv;
    delete stSolv;

    delete door;
    delete gate;

    return 0;
}
