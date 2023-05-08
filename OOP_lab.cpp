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
 
    IReader* fps = new FingerPrintScanner(8000, new OnState(), new OffState());

    fps->on();
    fps->off();
    fps->off();
    fps->on();
    fps->on();

    IRoom* room = new SimpleRoom("Кабинет", new SimpleSolver(), new Door(64000), fps);

    cout << "\n\nПопытка входа:\n";
    fps->tryToEnter();

    cout << endl;
    room->turnOffReader();
    room->turnOffReader();

    cout << "\n\nПопытка входа:\n";
    fps->tryToEnter();

    cout << endl;
    room->turnOnReader();
    room->turnOnReader();

    delete room;

    return 0;
}
