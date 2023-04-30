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
        cout << "��� ���������: ���������� ������ ������� � ��� \n";
        pool.push(new SimpleSolver());
    }

    cout << "��� ���������: ������ ������� ";

    ISolver* res = pool.front();

    pool.pop();

    cout << "(�����: " << res << ")\n";

    return res;
}

void SolverPool::releaseSolver(ISolver* solv)
{
    cout << "��� ���������: �������� ������� ";
    pool.push(solv);
    cout << "(�����: " << solv << ")\n";
}

SolverPool::~SolverPool()
{
    while (!pool.empty())
    {
        delete pool.front();
        pool.pop();
    }
}
