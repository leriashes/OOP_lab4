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
#include "Database.h"
#include "SolverPool.h"
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

    delete dfm;
    delete door;
    delete door1;
    delete door2;
    delete gfm;
    delete gate;
    delete gate1;


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

    delete fsf;
    delete read;
    delete fdf;
    delete read1;
    delete nvf;
    delete read2;
    delete ndsf;
    delete read3;




    ISolver* solv = new SimpleSolver(), *st_solv = new StateSolver(true);

    solv->info();
    ISolver* solv1 = solv->clone();
    solv1->info();
    cout << endl;

    st_solv->info();
    ISolver* solv2 = st_solv->clone();
    solv2->info();
    cout << endl;
    cout << endl;

    delete solv;
    delete st_solv;
    delete solv1;
    delete solv2;


    
    Database* base = Database::Instance();
    Database* base1 = Database::Instance();
    cout << endl;

    SolverPool* spool = SolverPool::Instance();

    ISolver* s = spool->acquireSolver();
    cout << endl;

    ISolver* s1 = spool->acquireSolver();
    cout << endl;

    ISolver* s2 = spool->acquireSolver();
    cout << endl;

    spool->releaseSolver(s1);
    cout << endl;
    s1 = nullptr;

    spool->releaseSolver(s);
    cout << endl;
    s = nullptr;

    ISolver* s3 = spool->acquireSolver();
    cout << endl;

    delete base;
    delete s2;
    delete s3;
    delete spool;

    return 0;
}
