#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

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

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void bubbleSort(int *data, size_t length)
{
	int holder = 0;
	for (int l = 0; l < length; ++l)
	{
		for (int i = 0; i < length; ++i)
		{
			if (data[i] < data[i - 1])
			{
				holder = data[i];
				data[i] = data[i - 1];
				data[i - 1] = holder;
			}
		}
	}
}

void insertionSort(int *data, size_t length)
{
	for (int i = 1; i < length; ++i)
	{
		int j = i;
		while (j > 0 && data[j - 1] > data[j])
		{
			swap(data[j], data[j - 1]);
			--j;
		}
	}
}

//void mergeSort(int*data, size_t length)
//{
//	mergeSortR(data, 0, length-1);
//}
//
//void mergeSortR(int *data, size_t L, size_t R)
//{
//	if (L < R)
//	{
//		size_t M = (L + R) / 2;
//		mergeSortR(data, L, M);
//		mergeSortR(data, M+1, R);
//		printData(data + L, R + 1);
//	}
//}

//void merge(int *data, size_t L, size_t M, size_t R)
//{
//	size_t s = R - L + 1;
//	int *A = new int[s];
//	size_t l = L, r = M + 1;
//
//	for (int i = 0; i < s; ++i)
//	{
//		if (l <= M && r <= R)
//		{
//			A[i] = (data[l] < data[r])
//		}
//	}
//}

//int *linearSearch(int *data, size_t length, int key)
//{
//	for (int i =)
//}

int *binarySearch(int *data, size_t length, int key)
{
	size_t min = 0, max = length - 1, mid = (min + max) / 2;

	while (min != max)
	{
		mid = (min + max) / 2;
		if (key == data[mid])	return &data[mid];
		if (key > data[mid])	min = mid + 1;
		if (key < data[mid])	max = mid;
	}
	return nullptr;
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

using namespace std::chrono;

void main()
{
	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

	srand(time(0));

	const size_t len = 1042;
	int data[len];

	randFill(data, len);

	t1 = high_resolution_clock::now();
	bubbleSort(data, len);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Bubble Time: " << duration << std::endl;
	
	randFill(data, len);

	t1 = high_resolution_clock::now();
	insertionSort(data, len);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Insert Time: " << duration << std::endl;
	
	randFill(data, len);

	t1 = high_resolution_clock::now();
	gnomeSort(data, len);
	t2 = high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "Gnome Time: " << duration << std::endl;

	system("pause");
}