#include "Database.h"

Database* Database::instance = NULL;

Database* Database::Instance() 
{
    if (instance == 0) 
    {
        cout << "��: �������� �������... \n";
        instance = new Database();
    }
    else 
        cout << "��: ������ ��� ����������! \n";

    return instance;
}

bool Database::processData()
{
    cout << "��: ���������... \n";
    return rand() % 2;;
}
