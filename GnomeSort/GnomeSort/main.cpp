#include <iostream>
#include <random>
#include <ctime>

void printData(int *data, size_t length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void randFill(int *data, size_t length)
{
	for (int i = 0; i < length; ++i)
	{
		data[i] = rand() % 100 + 1;
	}
}

void gnomeSort(int *data, int len)
{
	int i = 0;

	while (i < len)
	{
		if (i == 0 || data[i - 1] <= data[i]) i++;
		else
		{
		int tmp = data[i];
		data[i] = data[i - 1];
		data[--i] = tmp;
		}
	}
}

void main()
{
	const size_t len = 40;

	int data[len];

	srand(time(1));

	randFill(data, len);
	printData(data, len);
	gnomeSort(data, len);
	printData(data, len);
	system("pause");
}