#include <iostream>
//#include "HashMap.h"

bool isLeftMostBitSet(unsigned int value)
{
	if (value & 1024)
		return true;
	else
		return false;
}

bool isRightMostBitSet(unsigned int value)
{
	if (value & 1)
		return true;
	else
		return false;
}


#include "hashtb.h"

void main()
{
	hashtable tb;

	//if (isRightMostBitSet(1))
	//	std::cout << "true" << std::endl;
	//else
	//	std::cout << "false" << std::endl;

	//if (isLeftMostBitSet(1024))
	//	std::cout << "true" << std::endl;
	//else
	//	std::cout << "false" << std::endl;

	tb.set(82, 403);
	std::cout << tb.get(82) << std::endl;
	tb.set(34, 17);
	std::cout << tb.get(34) << std::endl;
	tb.set(87, 1523);
	std::cout << tb.get(87) << std::endl;
	tb.set(938, 49);
	std::cout << tb.get(938) << std::endl;


	tb.count();

	std::cout << tb.count() << std::endl;

	system("pause");
}