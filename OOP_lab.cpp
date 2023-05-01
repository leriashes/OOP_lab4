#include <conio.h>
#include <time.h>
#include "ProxyReader.h"
#include "CompositeRoom.h"
#include "RusLang.h"

#include "DoorFM.h"
#include "GateFM.h"
#include "FingerStateFactory.h"
#include "FingerDisplayFactory.h"
#include "NumplateVoiceFactory.h"
#include "NumplateDisplayStateFactory.h"
#include "Database.h"
#include "GarageBuilder.h"
#include "Director.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
 
    Builder* gb = new GarageBuilder();
    Director* dir = new Director(gb);

    IRoom* gar = dir->constructRoom();
    IRoom* gar1 = dir->constructRoom();

    cout << endl;
    gar->info();
    gar1->info();
    cout << endl;

    delete dir;
    delete gb;
    delete gar;
    delete gar1;

    Builder* cb = new Builder();
    OpenerFM* doorfm = new DoorFM();
    IReaderFactory* fact = new FingerDisplayFactory();
    cb->setWorker(doorfm);
    cb->setWorker(fact);

    dir = new Director(cb);

    IRoom* cab = dir->constructRoom();

    delete fact;
    fact = new FingerStateFactory();
    cb->setWorker(fact);

    IRoom* cab1 = dir->constructRoom();

    cout << endl;
    cab->info();
    cab1->info();
    cout << endl;

    delete dir;
    delete cb;
    delete doorfm;
    delete fact;
    delete cab;
    delete cab1;
    delete SolverPool::Instance();

    return 0;
}
