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
		pool.resize(Default_Pool_Size);
		poolValidity.resize(Default_Pool_Size);

		for (size_t i = 0; i < Default_Pool_Size; ++i)
		{
			pool.push_back(T());
			poolValidity.push_back(false);
		}
	}
	~obpool()
	{}

	class handle
	{
	public:
		handle() : pool(NULL) {}
		handle(obpool * poolPtr, size_t poolIdx) : pool(poolPtr), index(poolIdx) {}

		obpool * pool;
		size_t index;

		T& value() const
		{
			return pool->at(index);
		}

		void free()
		{
			pool->pop(index);
		}

		bool isValid() const
		{
			return pool->isValid(index);
		}

		size_t getIndex() const
		{
			return index;
		}

		handle &operator++()
		{
			for (size_t i = index + 1; i < pool->poolValidity.size(); ++i)
			{
				if (pool->poolValidity[i])
				{
					index = i;
					return *this;
				}
			}

			index = pool->pool.size();
			return *this;
		}

		T& operator*() const
		{
			return value();
		}

		const T& operator*() const
		{
			return value();
		}

		T& operator->()
		{
			return value();
		}

		const T& operator->() const
		{
			return value();
		}

		bool operator==(const handle& other) const
		{
			return other.pool == pool && other.index == index;
		}

		bool operator==(const handle& other) const
		{
			return other.pool == pool && other.index == index;
		}

		bool operator!=(const handle& other)
		{
			return !(other == *this);
		}
	};

	handle push(const T& cpy)
	{
		size_t idx = nextEmpty();
		assert(idx != -1);

		pool[idx] = cpy;
		poolValidity[idx] = true;

		return handle(this, idx);
	}

	void pop(size_t idx)
	{
		poolValidity[idx] = false;
	}

	bool isValid(size_t idx) const
	{
		return poolValidity[idx];
	}

	handle begin()
	{
		for (size_t i = 0; i < poolValidity.size(); ++i)
		{
			if (poolValidity[i])
			{
				return handle(this, i);
			}
		}

		assert(false && "can not iterate over a pool with no elements!");
	}

	handle get(size_t idx)
	{
		assert(idx < pool.size());
		return handle(this, idx);
	}

	handle end()
	{
		return handle(this, pool.size());
	}

	T& at(size_t idx)
	{
		assert(isValid(idx));
		return pool[idx];
	}

	const T& at(size_t idx)
	{
		assert(isValid(idx));
		return pool[idx];
	}

	const T& at(size_t idx) const
	{
		assert(isValid(idx));
		return pool[idx];
	}
};


