#include "CompositeRoom.h"

void CompositeRoom::add(IRoom* room)
{
	children.push_back(room);
}

void CompositeRoom::remove(IRoom* room)
{
	children.remove(room);
}
