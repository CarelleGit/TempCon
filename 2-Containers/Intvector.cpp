#include "Intvector.h"
#include <cassert>
#include <cstring>

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
	return data[size + 1];
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
		capacity * 2;
	}

	int * newData = new int[capacity];
	memcpy(newData, data, sizeof(int) * size);

	delete[] data;

	data = newData;

	return true;
}


