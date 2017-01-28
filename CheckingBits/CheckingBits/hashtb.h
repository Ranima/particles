#pragma once
//https://www.google.com/search?q=UINT32_C&oq=UINT32_C&aqs=chrome..69i57j0l5.295j0j7&sourceid=chrome&es_sm=93&ie=UTF-8
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