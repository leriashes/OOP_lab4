#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include "SimpleRoom.h"
#include "Gate.h"
#include "ProxyReader.h"
#include "CompositeRoom.h"
#include "RusLang.h"

#include "DoorFM.h"
#include "GateFM.h"
#include "FingerStateFactory.h"
#include "FingerDisplayFactory.h"
#include "NumplateVoiceFactory.h"
#include "NumplateDisplayStateFactory.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    OpenerFM* dfm = new DoorFM();

    IOpener* door = dfm->createOpener(57000);
    IOpener* door1 = dfm->createOpener(95000);
    IOpener* door2 = dfm->cloneOpener(door);

    cout << endl;
    door->info();
    door1->info();
    door2->info();
    cout << endl;

    OpenerFM* gfm = new GateFM();

    IOpener* gate = gfm->createOpener(142000);
    IOpener* gate1 = gfm->cloneOpener(gate);

    cout << endl;
    gate->info();
    gate1->info();
    cout << endl;
    cout << endl;


    IReaderFactory* fsf = new FingerStateFactory();
    IReader* read = fsf->createReader();

    read->info();
    cout << endl;

    IReaderFactory* fdf = new FingerDisplayFactory();
    IReader* read1 = fdf->createReader();

    read1->info();
    cout << endl;

    IReaderFactory* nvf = new NumplateVoiceFactory();
    IReader* read2 = nvf->createReader();

    read2->info();
    cout << endl;

    IReaderFactory* ndsf = new NumplateDisplayStateFactory();
    IReader* read3 = ndsf->createReader();

    read3->info();
    cout << endl;
    cout << endl;


    ISolver* solv = new SimpleSolver(), *st_solv = new StateSolver(true);

    solv->info();
    ISolver* solv1 = solv->clone();
    solv1->info();
    cout << endl;

    st_solv->info();
    ISolver* solv2 = st_solv->clone();
    solv2->info();
    cout << endl;

    
    


    ISolver* solv_garage = new SimpleSolver(), *solv_korp = new SimpleSolver();


    IOpener *door_korp = new Door(120000);
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

    ISolver* stsolv = new StateSolver(true);
    garage->setSolver(stsolv);

    cout << "\nБлокировка гаража: \n";
    garage->lock();
    cout << endl;

    cout << "Разблокировка гаража: \n";
    garage->unlock();
    cout << endl;

    cout << "Блокировка кабинета: \n";
    cabinet->lock();
    cout << endl;

    cout << "Разблокировка кабинета: \n";
    cabinet->unlock();
    cout << endl;

    delete solv;
    delete solv_garage;
    delete solv_korp;
    delete stsolv;

    delete door;
    delete gate;
    delete door_korp;

    delete numplateScan;
    delete fingerScan;
    delete scan;

    delete displayScan;
    delete displayScan1;

    delete cabinet;
    delete garage;
    delete complex;

    delete rus;
    delete eng;
    delete engGarage;

    delete fact;

    return 0;
}
