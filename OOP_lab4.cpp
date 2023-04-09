#include <iostream>
#include <string>
#include <conio.h>
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

    ISolver* solv_base = new SimpleSolver(), * solv_c1 = new SimpleSolver(), * solv_c2 = new SimpleSolver(),
        * solv_cab1 = new SimpleSolver(), * solv_cab2 = new SimpleSolver(),
        * solv_garage = new SimpleSolver(), * solv = new SimpleSolver();

    IOpener* door = new Door(), *gate = new Gate(), * gate_garage = new Gate(),
        * door_c1 = new Door(), * door_c2 = new Door(),
        * door_cab1 = new Door(), * door_cab2 = new Door();

    IReader* fingerScan = new FingerPrintScanner(true), *numplateScan = new NumberPlateScanner(true), 
        * fingerScanlib = new FingerPrintScanner(true), * fingerScan_base = new FingerPrintScanner(true),
        * fingerScan_c1 = new FingerPrintScanner(true), * fingerScan_c2 = new FingerPrintScanner(true);

    IReader* pcabinet = new ProxyReader(fingerScan), * pgarage = new ProxyReader(numplateScan),
        * plib = new ProxyReader(fingerScanlib), * pbase = new ProxyReader(fingerScan_base),
        * pcomp1 = new ProxyReader(fingerScan_c1), * pcomp2 = new ProxyReader(fingerScan_c2);


    IRoom* cabinet = new SimpleRoom("Кабинет", solv, door, pcabinet),
        * garage = new SimpleRoom("Гараж", solv_garage, gate_garage, pgarage),
        * library = new SimpleRoom("Библиотека", solv_cab1, door_cab1, plib);

    CompositeRoom* base = new CompositeRoom("База", solv_base, gate, pbase), 
        * complex1 = new CompositeRoom("Корпус А", solv_c1, door_c1, pcomp1),
        * complex2 = new CompositeRoom("Корпус Б", solv_c2, door_c2, pcomp2);


    complex1->add(cabinet);
    complex1->add(garage);
    complex1->getComposite();

    complex2->add(library);
    complex2->getComposite();

    base->add(complex1);
    base->add(complex2);
    base->getComposite();
    cout << endl;
    _getch();


    base->name();
    pbase->tryToEnter();
    cout << endl;

    complex1->name();
    pcomp1->tryToEnter();
    cout << endl;

    complex2->name();
    pcomp2->tryToEnter();
    cout << endl;

    garage->name();
    pgarage->tryToEnter();
    cout << endl << endl;
    _getch();

    base->turnOffReader();
    cout << endl;

    base->name();
    pbase->tryToEnter();
    cout << endl;

    complex1->name();
    pcomp1->tryToEnter();
    cout << endl;

    complex2->name();
    pcomp2->tryToEnter();
    cout << endl;

    garage->name();
    pgarage->tryToEnter();
    cout << endl << endl;
    _getch();

    complex1->turnOnReader();
    cout << endl;

    base->name();
    pbase->tryToEnter();
    cout << endl;

    complex1->name();
    pcomp1->tryToEnter();
    cout << endl;

    complex2->name();
    pcomp2->tryToEnter();
    cout << endl;

    garage->name();
    pgarage->tryToEnter();
    cout << endl << endl;
    _getch();

    library->turnOnReader();
    cout << endl;

    base->name();
    pbase->tryToEnter();
    cout << endl;

    complex2->name();
    pcomp2->tryToEnter();
    cout << endl;

    library->name();
    plib->tryToEnter();
    cout << endl << endl;

    delete cabinet;
    delete garage;
    delete library;
    delete complex1;
    delete complex2;
    delete base;


    delete solv_base;
    delete solv_c1;
    delete solv_c2;
    delete solv_cab1;
    delete solv_cab2;
    delete solv_garage;
    delete solv;

    delete door;
    delete gate;
    delete gate_garage;
    delete door_c1;
    delete door_c2;
    delete door_cab1;
    delete door_cab2;

    delete fingerScan;
    delete numplateScan;
    delete fingerScanlib;
    delete fingerScan_base;
    delete fingerScan_c1;
    delete fingerScan_c2;

    delete pcabinet;
    delete pgarage;
    delete plib;
    delete pbase;
    delete pcomp1;
    delete pcomp2;

    return 0;
}
