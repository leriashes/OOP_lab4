#include "Database.h"

Database* Database::instance = NULL;

Database* Database::Instance() 
{
    if (instance == 0) 
    {
        cout << "БД: создание объекта... \n";
        instance = new Database();
    }
    else 
        cout << "БД: объект уже существует! \n";

    return instance;
}

bool Database::processData()
{
    cout << "БД: обработка... \n";
    return rand() % 2;;
}
