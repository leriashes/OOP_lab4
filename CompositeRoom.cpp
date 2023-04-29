#include "CompositeRoom.h"

void CompositeRoom::add(IRoom* room)
{
	children.push_back(room);
}

void CompositeRoom::remove(IRoom* room)
{
	children.remove(room);
}

void CompositeRoom::turnOnReader()
{
	IRoom::turnOnReader();

	for (list<IRoom*>::iterator iter = children.begin(); iter != children.end(); iter++)
	{
		(*iter)->turnOnReader();
	}
}

void CompositeRoom::turnOffReader()
{
	IRoom::turnOffReader();

	for (list<IRoom*>::iterator iter = children.begin(); iter != children.end(); iter++)
	{
		(*iter)->turnOffReader();
	}
}

void CompositeRoom::getComposite()
{
	name();
	if (children.size() > 0)
	{
		cout << "Содержит:" << endl;

		for (list<IRoom*>::iterator iter = children.begin(); iter != children.end(); iter++)
		{
			(*iter)->getComposite();
		}
	}

	cout << endl;
}

double CompositeRoom::getTotalCost()
{
	double result = this->getCost();

	if (children.size() > 0)
	{
		for (list<IRoom*>::iterator iter = children.begin(); iter != children.end(); iter++)
		{
			result += ((*iter)->getTotalCost());
		}
	}

	return result;
}
