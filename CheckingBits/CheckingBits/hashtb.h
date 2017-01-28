#pragma once

#include <cmath>

class hashtable
{
	const static int TBSIZE = 128;

	struct pair
	{
		int key;
		int value;

		bool isSet;

		pair()
		{
			isSet = false;
		}
	};

	// backing array
	pair things[TBSIZE];

	int getIndex(int key);

public:
	hashtable();

	void set(int key, int value);
	int  get(int key);

	int count();

};