#pragma once


template<typename t>
class iterator
{
public:
	iterator() = delete;

	iterator(tVector<t>& container, int initialIndex)
	: owningContainer(container), currentIndex(initialIndex)
	{

	}

	iterator(const iterator<t>& other)
		:owningContainer(other.owningContainer), currentIndex(other.currentIndex)
	{

	}

	interator<t>& operator=(const iterator<t>& other)
	{
		owningContainer = other.owningContainer;
		currentIndex = other.currentIndex;
	}

	bool<t>& operator==(const iterator<t>& other)
	{
		bool same = owningContainer == other.owningContainer;
		bool IndexSame = currentIndex == other.currentIndex;

		return same && IndexSame;
	}
	bool<t>& operator!=(const iterator<t>& other)
	{
		bool same = owningContainer == other.owningContainer;
		bool IndexSame = currentIndex == other.currentIndex;

		return !same || !IndexSame;
	}

	auto& operator*()
	{
		return owningContainer->at(currentIndex);
	}

	iterator<t>& operator++()
	{
		++currentIndex;
		return *this;
	}
	iterator<t>& operator++(int prevVal)
	{
		iterator<t> tmp(owningContainer, prevVal);
		operator++();
		return tmp;
	}

private:
	t* owningContainer;
	int currentIndex;

};
