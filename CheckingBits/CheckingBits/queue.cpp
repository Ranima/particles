#include "queue.h"

void Queue::getLast()
{
	if (isActive == true)
	{
		for (int i = len; i > 0; --i)
		{
			if (Qdata[i].isFull == true)
			{
				last = i;
			}
		}
	}
}

void Queue::getFirst()
{
	if (isActive == true)
	{
		for (int i = 0; i < len; ++i)
		{
			if (Qdata[i].isFull == true)
			{
				first = i;
			}
		}
	}
}

int Queue::pop()
{
	if (isActive == true)
	{
		return Qdata[first].value;
		Qdata[first].isFull = false;
		getFirst();
	}
}

int Queue::push()
{
	
}
