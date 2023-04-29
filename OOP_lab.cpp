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
#include "RusLang.h"
#include "EngLang.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    ISolver* solv = new SimpleSolver(), * solv_garage = new SimpleSolver(), *solv_korp = new SimpleSolver();
    IOpener* door = new Door(52000), * gate = new Gate(143000), *door_korp = new Door(120000);
    IReader* fingerScan = new FingerPrintScanner(true, 12800), * numplateScan = new NumberPlateScanner(true, 4650), 
        *scan = new FingerPrintScanner(true, 12800);
    
    IRoom* cabinet = new SimpleRoom("Кабинет", solv, door, fingerScan),
        *garage = new SimpleRoom("Гараж", solv_garage, gate, numplateScan);

    StrFlyFactory* fact = new StrFlyFactory();

    LangReader* rus = new RusLang(fact, "Пожалуйста, приложите ваш палец! "), 
        * eng = new EngLang(fact, "Please, put your finger on the scanner! "), 
        *engGarage = new EngLang(fact, "Please, position the car in front of the scanner! ");

    DisplayReader* displayScan = new DisplayReader(fingerScan, rus, 5400);
    cabinet->setReader(displayScan);

    cout << endl;
    displayScan->tryToEnter();
    cout << endl;

    displayScan->tryToEnter();
    cout << endl;

    displayScan->setLanguage(eng);

    displayScan->tryToEnter();
    cout << endl;

    displayScan->tryToEnter();
    cout << endl;

    DisplayReader* displayScan1 = new DisplayReader(numplateScan, engGarage, 5400);
    garage->setReader(displayScan1);

    displayScan1->tryToEnter();
    cout << endl;

    cout << "Итоговая стоимость оборудования для кабинета: " << cabinet->getTotalCost() << " руб.\n"; //дверь + сканер отпечатка + дисплей
    cout << "Итоговая стоимость оборудования для гаража: " << garage->getTotalCost() << " руб.\n"; //ворота + сканер номера + дисплей


    CompositeRoom* complex = new CompositeRoom("Корпус", solv_korp, door_korp, scan);
    complex->add(garage);
    complex->add(cabinet);

    cout << "Итоговая стоимость оборудования для корпуса: " << complex->getTotalCost() << " руб.\n";





    /*StrFlyweight* mes = fact->getStr("Hello!");

    cout << mes->getMessage(" Please, smile and wave! ");

    StrFlyweight* mes1 = fact->getStr("Hello!");

    cout << mes1->getMessage(" Please1, smile1 and1 wave1! ");

    delete mes1;*/


    /*

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


    //Итератор

    typedef MyAggregate<IRoom*> MyContainer;
    MyContainer cont;   

    cont.push(complex1);
    cont.push(complex2);
    cont.push(cabinet);
    cont.push(library);

    for (MyContainer::myIter it = cont.begin(); it != cont.end(); ++it) {
        (*(it.next()))->name();
    }

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
    */
    return 0;
}
