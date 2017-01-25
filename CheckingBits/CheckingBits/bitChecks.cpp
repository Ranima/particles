#include <iostream>

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

void main()
{
	if (isRightMostBitSet(1))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (isLeftMostBitSet(1024))
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;


	system("pause");
}