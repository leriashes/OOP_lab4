#include "StrFlyFactory.h"

StrFlyweight* StrFlyFactory::getStr(string message)
{
    if (flyweights.find(message) == flyweights.end())
    {
        cout << "������� ����������: �������� �� ������, ������ �����.\n";
        flyweights.insert(make_pair(message, new StrFlyweight(message)));
    }
    else
    {
        cout << "������� ����������: ��������� ������������� ������������� ���������.\n";
    }
    
    return flyweights.at(message);
}
