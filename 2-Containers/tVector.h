#pragma once
#include <cassert>
#include "Iterator.h"

template<typename T>
class tVector
{
	T * data;
	size_t capacity;
	size_t size;

public:
	tVector()
	{
		capacity = 2;
		data = new T[capacity];
		size = 0;
	}
	~tVector()
	{
		delete[] data;
	}

	iterator<tVector<T>> begin()
	{
		return iterator<tVector<T>>(*this, 0)
	}

	iterator<tVector<T>> end()
	{
		return iterator<tVector<T>>(*this, size); 
	}

	void printVector()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << std::endl;
		}
	}

	T &at(size_t idx);
	T &append(T val);

	T* c_ptr() const;
	size_t Capacity() const;
	size_t Size() const;
	bool empty() const;
	T front() const;
	T back() const;
	void pop();

	T & operator[](size_t idx);
	T operator[](size_t idx) const;

	void clear();
	void erase(size_t idx);
	T count(T idx);
	void insert(size_t idx, int val);
	void reserve(size_t nCap);
	void compact();
	void eraseRange(size_t idx, size_t idx2);

private:
	bool grow(size_t minSize);
};

template<typename T>
inline T & tVector<T>::at(size_t idx)
{

	assert(idx >= 0);
	assert(idx < size);
	return data[idx];
	// TODO: insert return statement here
}

template<typename T>
inline T & tVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}
	data[size] = val;
	++size;
	return data[size - 1];
	// TODO: insert return statement here
}

template<typename T>
inline T * tVector<T>::c_ptr() const
{
	return data;
}

template<typename T>
inline size_t tVector<T>::Capacity() const
{
	return capacity;
}

template<typename T>
inline size_t tVector<T>::Size() const
{
	return size;
}

template<typename T>
inline bool tVector<T>::empty() const
{
	return size == 0;
}

template<typename T>
inline T tVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T tVector<T>::back() const
{
	return data[size - 1];
}

template<typename T>
inline void tVector<T>::pop()
{
	assert(size > 0);
	size -= 1;
}

template<typename T>
inline T & tVector<T>::operator[](size_t idx)
{
	//assert(idx >= 0);
	assert(idx < size);
	return at(idx);
	// TODO: insert return statement here
}

template<typename T>
inline T tVector<T>::operator[](size_t idx) const
{
	assert(idx < size);
	return data[idx];
}

template<typename T>
inline void tVector<T>::clear()
{
	size = 0;
}

template<typename T>
inline void tVector<T>::erase(size_t idx)
{
	assert(size > 0);
	for (int i = 0; i < size - idx; i++)
	{
		data[idx + i] = data[(idx + i) + 1];
	}

	size = size - 1;

}

template<typename T>
inline T tVector<T>::count(T idx)
{
	T counter = 0;
	for (size_t i = 0; i < size - 1; i++)
	{
		if (data[idx] == data[i])
		{
			counter += 1;
		}
	}

	return counter;
}

template<typename T>
inline void tVector<T>::insert(size_t idx, int val)
{
	assert(idx >= 0);
	assert(idx <= size);

	append(val);

	for (int i = size - 1; i > idx; i--)
	{
		T temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}
}

template<typename T>
inline void tVector<T>::reserve(size_t nCap)
{
	if (nCap > capacity)
	{
		T *newData = new T[nCap];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = nCap;
	}
}

template<typename T>
inline void tVector<T>::compact()
{
	if (capacity > size)
	{
		T *newData = new T[size];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}
}

template<typename T>
inline void tVector<T>::eraseRange(size_t idx, size_t idx2)
{
	assert(idx2 > idx && idx2 < size);
	for (int i = idx; i < idx2; i++)
	{
		erase(i);
	}
}

template<typename T>
inline bool tVector<T>::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	//int oldCapacity = capacity;
	while (capacity < minSize)
	{
		capacity *= 2;
	}

	T * newData = new T[capacity];
	memcpy(newData, data, sizeof(T) * size);

	delete[] data;

	data = newData;

	return true;
}
