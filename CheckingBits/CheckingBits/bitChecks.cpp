#include <iostream>
#include <cassert>

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


//#include "hashtb.h"
#include "stack.h"

void main()
{
//	hashtable tb;
	
	//if (isRightMostBitSet(1))
	//	std::cout << "true" << std::endl;
	//else
	//	std::cout << "false" << std::endl;

	//if (isLeftMostBitSet(1024))
	//	std::cout << "true" << std::endl;
	//else
	//	std::cout << "false" << std::endl;
/*
	tb.empty();
	std::cout << tb.empty() << std::endl;

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

	tb.empty();
	std::cout << tb.empty() << std::endl;

	tb.clear();

	tb.empty();
	std::cout << tb.empty() << std::endl;

	tb.count();
	std::cout << tb.count() << std::endl;*/

	Stack stack;

	stack.push(2);
	stack.push(9);
	stack.push(6);

	assert(stack.peek() == 6);

	stack.pop();
	stack.pop();
	stack.pop();

	stack.push(1);
	stack.push(66);
	stack.push(8);

	assert(stack.peek() == 8);

	system("pause");
}