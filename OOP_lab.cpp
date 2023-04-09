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
#include "VoiceReader.h"
#include "DisplayReader.h"
#include "Turnstile.h"
#include "TurnstileAdapter.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    ISolver* solv = new SimpleSolver(), * solv_garage = new SimpleSolver();
    IOpener* door = new Door(), * gate = new Gate();
    IReader* fingerScan = new FingerPrintScanner(true), * numplateScan = new NumberPlateScanner(true);
    

    //Адаптер
    Turnstile* turn = new Turnstile();
    IOpener* adptTurn = new TurnstileAdapter(turn);

    IRoom* cabinet = new SimpleRoom("Кабинет", solv, adptTurn, fingerScan);

    cabinet->name();
    fingerScan->tryToEnter();
    cout << endl;

    cabinet->name();
    fingerScan->tryToEnter();
    cout << endl;

    cabinet->setOpener(door);

    delete adptTurn;
    delete turn;

    system("cls");

    //Декоратор

    IReader* voiceScan = new VoiceReader(fingerScan);

    cabinet->setReader(voiceScan);

    cabinet->name();
    voiceScan->tryToEnter();
    cout << endl;

    DisplayReader* displayScan = new DisplayReader(voiceScan);
    cabinet->setReader(displayScan);

    displayScan->tryToEnter();
    cout << endl;

    displayScan->turnOff();
    displayScan->tryToEnter();
    cout << endl;

    IReader* prox = new ProxyReader(displayScan);
    prox->tryToEnter();
    cout << endl;

    prox->setState(false);
    prox->tryToEnter();
    cout << endl;


    IReader* dScan = new DisplayReader(numplateScan);
    IRoom* garage = new SimpleRoom("Гараж", solv_garage, gate, dScan);

    garage->name();
    dScan->tryToEnter();
    cout << endl;
    _getch();




    system("cls");

    //Композит

    ISolver* solv_base = new SimpleSolver(), * solv_c1 = new SimpleSolver(), * solv_c2 = new SimpleSolver(),
        * solv_lib = new SimpleSolver();

    IOpener * gate_base = new Gate(),
        * door_c1 = new Door(), * door_c2 = new Door(),
        * door_lib = new Door();

    IReader* fingerScanlib = new FingerPrintScanner(true), * fingerScan_base = new FingerPrintScanner(true),
        * fingerScan_c1 = new FingerPrintScanner(true), * fingerScan_c2 = new FingerPrintScanner(true);

    IReader* pgarage = new ProxyReader(dScan), * plib = new ProxyReader(fingerScanlib),
        * pbase = new ProxyReader(fingerScan_base), * pcomp1 = new ProxyReader(fingerScan_c1),
        * pcomp2 = new ProxyReader(fingerScan_c2);


    IRoom* library = new SimpleRoom("Библиотека", solv_lib, door_lib, plib);

    CompositeRoom* base = new CompositeRoom("База", solv_base, gate_base, pbase), 
        * complex1 = new CompositeRoom("Корпус А", solv_c1, door_c1, pcomp1),
        * complex2 = new CompositeRoom("Корпус Б", solv_c2, door_c2, pcomp2);

    garage->setReader(pgarage);


    complex1->add(cabinet);
    complex1->add(garage);
    complex1->getComposite();

    complex2->add(library);
    complex2->getComposite();

    base->add(complex1);
    base->add(complex2);
    base->getComposite();
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

    //помещения
    delete cabinet;
    delete garage;
    delete library;
    delete complex1;
    delete complex2;
    delete base;

    //решатели
    delete solv_base;
    delete solv_c1;
    delete solv_c2;
    delete solv_lib;
    delete solv_garage;
    delete solv;

    //двери
    delete door;
    delete gate;
    delete gate_base;
    delete door_c1;
    delete door_c2;
    delete door_lib;

    //считыватели
    delete fingerScan;
    delete numplateScan;
    delete fingerScanlib;
    delete fingerScan_base;
    delete fingerScan_c1;
    delete fingerScan_c2;

    //прокси
    delete prox;
    delete pgarage;
    delete plib;
    delete pbase;
    delete pcomp1;
    delete pcomp2;

    return 0;
}
