#include "hashtb.h"

#include <stdint.h>

inline unsigned int knuth(unsigned int value)
{
	return value * UINT32_C(2654435761);
}

int hashtable::getIndex(int key)
{
	return knuth(key) % TBSIZE;
}

hashtable::hashtable()
{
	
}

void hashtable::set(int key, int value)
{
	things[getIndex(key)].key = key;
	things[getIndex(key)].value = value;
	things[getIndex(key)].isSet = true;
}

int hashtable::get(int key)
{
	return things[getIndex(key)].value;
}

int hashtable::count()
{
	int total = 0;
	for (int i = 0; i < TBSIZE; ++i)
	{
		if (things[i].isSet == true)
			++total;
	}
	return total;
}

bool hashtable::empty()
{
	for (int i = 0; i < TBSIZE; ++i)
	{
		if (things[i].isSet == true)
		{
			return false;
		}
	}
	return true;
}

void hashtable::clear()
{
	for (int i = 0; i < TBSIZE; ++i)
	{
		if (things[i].isSet == true)
		{
			things[i].key = 0;
			things[i].value = 0;
			things[i].isSet = false;
		}
	}
}

void hashtable::reserve(size_t size)
{
	pointer = size;
}
