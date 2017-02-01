#pragma once

#include <vector>

template <typename T>
class obpool
{
	const static size_t Default_Pool_Size = 100;

	std::vector<T> pool;
	std::vector<bool> poolValidity;

	size_t nextEmpty()
	{
		for (size_t i = 0; i < poolValidity.size(); ++i)
		{
			return i;
		}

		size_t newIdx = pool.size();
		pool.resize(pool.size() * 1.5);
		poolValidity.resize(poolValidity.size() * 1.5);

		return newIdx;
	}

public:
	obpool()
	{

	}
	~obpool();

	class handle
	{
	public:
		handle() : pool(NULL) {}
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {}

		obpool * pool;
		size_t index;
	};
};


