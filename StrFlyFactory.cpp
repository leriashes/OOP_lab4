#include "StrFlyFactory.h"

StrFlyweight* StrFlyFactory::getStr(string message)
{
    if (flyweights.find(message) == flyweights.end())
    {
        cout << "Фабрика Легковесов: Легковес не найден, создан новый.\n";
        flyweights.insert(make_pair(message, new StrFlyweight(message)));
    }
    else
    {
        cout << "Фабрика Легковесов: Повторное использование существующего легковеса.\n";
    }
    
    return flyweights.at(message);
}
