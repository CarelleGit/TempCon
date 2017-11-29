#include "Intvector.h"
#include <cassert>
#include <cstring>
#include <iostream>
intvector::intvector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

intvector::~intvector()
{
	delete[] data;
}

int & intvector::at(size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return data[idx];
	// TODO: insert return statement here
}

int & intvector::append(int val)
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

int * intvector::Data() const
{
	return data;
}

size_t intvector::Capacity() const
{
	return capacity;
}

size_t intvector::Size() const
{
	return size;
}

bool intvector::Empty() const
{
	return size == 0;
}

int intvector::Front() const
{
	return data[0];
}

int intvector::Back() const
{
	return data[size - 1];
}

int & intvector::operator[](size_t idx)
{
	assert(idx >= 0);
	assert(idx < size);
	return at(idx);
	// TODO: insert return statement here
}

int intvector::operator[](size_t idx) const
{
	return data[idx];
}

void intvector::clear()
{
	size = 0;
}

void intvector::erase(size_t idx)
{
	for (int i = 0; i < size - idx; i++)
	{
		data[idx + i] = data[(idx + i) + 1];
	}

	size = size - 1;
	assert(size > 0);
}

int intvector::count(size_t idx)
{
	int counter = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (data[idx] == data[i])
		{
			counter += 1;
		}
	}

	return counter;
}

void intvector::insert(size_t idx, size_t val)
{ 
	assert(idx >= 0);
	assert(idx < size);

	append(val);

	

	for (int i = 0; i >= size; i--)
	{
		int temp = data[i];
		data[i] = data[i - 1];
		data[i - 1] = temp;
	}

}

void intvector::reserve(size_t nCap)
{
	if (nCap > capacity)
	{
		int *newData = new int[nCap];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = nCap;
	}
}

void intvector::compact()
{
	if (capacity > size)
	{
		int *newData = new int[size];
		memcpy(newData, data, sizeof(int) * size);
		delete[] data;
		data = newData;
		capacity = size;
	}
}

void intvector::printVector()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << std::endl;
	}
}

bool intvector::grow(size_t minSize)
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

	int * newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;

	data = newData;

	return true;
}


