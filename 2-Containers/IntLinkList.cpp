#include "IntLinkList.h"
#include <cassert>
intLinkList::intLinkList()
	:head(nullptr)
{


}

intLinkList::~intLinkList()
{
	intLinkListNode *iter = head;
	while (iter != nullptr)
	{
		intLinkListNode *next = iter->next;
		delete iter;
		iter = iter->next;
	}

}

void intLinkList::append(int value)
{
	intLinkListNode *newNode = new intLinkListNode;
	newNode->value = value;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		intLinkListNode *iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		iter->next = newNode;
	}
}

int intLinkList::at(int index)
{
	intLinkListNode *iter = head;
	int iterionCount = 0;
	while (iterionCount != index && iter != nullptr)
	{
		iterionCount++;
		iter = iter->next;
	}
	assert(iter != nullptr);

	return iter->value;
}

int intLinkList::size() const
{
	int count = 0;
	intLinkListNode *iter = head;
	while (iter != nullptr)
	{
		count++;
		iter = iter->next;
	}
	return count;
}

bool intLinkList::empty() const
{
	return head == nullptr;
}

int intLinkList::front() const
{
	assert(!empty());
	return head->value;
}

int intLinkList::back() const
{
	assert(!empty);
	intLinkListNode *iter = head;
	while (iter->next != nullptr)
	{
		iter = iter-> next;
	}

	return iter->value;
}

void intLinkList::clear()
{
	intLinkListNode *iter = head;
	while (iter != nullptr)
	{
		intLinkListNode *next = iter->next;
		delete iter;
		iter = next;
	}
	head = nullptr;
}

void intLinkList::erase(size_t idx)
{
	intLinkListNode *iter = head;
	assert(idx <= size());
	int count = 0;
	intLinkListNode *temp = iter;
	while (iter->next != nullptr && count != idx)
	{
		count++;
		temp = iter;
		iter->next = temp;
	}
	temp->next = iter->next;
	delete iter;
}

int intLinkList::count(int sum) const
{
	intLinkListNode *iter = head;
	int count = 0;
	while (iter != nullptr)
	{
		if (iter->value == sum)
		{
			count++;
		}
		iter = iter->next;
	}
	return count;
}

int intLinkList::insert(int num, size_t idx)
{
	intLinkListNode *iter = head;
	intLinkListNode *newItem = new intLinkListNode;
	intLinkListNode *temp = head;
	newItem->value = num;
	int count = 0;
	while (iter != nullptr)
	{
		if (count == idx - 1)
		{
			temp = iter;
		}
		if (count == idx)
		{
			temp->next = newItem;
			newItem->next = iter;
		}
		count++;
		iter = iter->next;
	}


	return 0;
}
