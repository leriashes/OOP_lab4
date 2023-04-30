#include "SolverPool.h"

SolverPool* SolverPool::instance = NULL;

SolverPool* SolverPool::Instance()
{
    if (instance == 0)
    {
        instance = new SolverPool();
    }

    return instance;
}

ISolver* SolverPool::acquireSolver()
{
    if (pool.empty()) 
    {
        cout << "Пул решателей: добавление нового объекта в пул \n";
        pool.push(new SimpleSolver());
    }

    cout << "Пул решателей: выдача объекта ";

    ISolver* res = pool.front();

    pool.pop();

    cout << "(адрес: " << res << ")\n";

    return res;
}

void SolverPool::releaseSolver(ISolver* solv)
{
    cout << "Пул решателей: принятие объекта ";
    pool.push(solv);
    cout << "(адрес: " << solv << ")\n";
}

SolverPool::~SolverPool()
{
    while (!pool.empty())
    {
        delete pool.front();
        pool.pop();
    }
}
