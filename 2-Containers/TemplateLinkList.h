#pragma once
template<typename t>
class TemplateLinkList
{
public:
	struct TemplateLinkList
	{
		int value;
		TemplateLinkList *next;
		TemplateLinkList *prev;
	};
	TemplateLinkList();
	~TemplateLinkList();

	void append(int value);

	t at(t index);

	t size() const;
	bool empty() const;
	t front() const;
	t back() const;
	void clear();
	void erase(size_t idx);
	t count(t sum) const;
	void insert(t num, size_t idx);

private:

	TemplateLinkList *head;
};

template<typename t>
inline TemplateLinkList<t>::TemplateLinkList()
	:head(nullptr)
{


}

template<typename t>
inline TemplateLinkList<t>::~TemplateLinkList()
{
	TemplateLinkList *iter = head;
	while (iter != nullptr)
	{
		TemplateLinkList *next = iter->next;
		delete iter;
		iter = iter->next;
	}
}

template<typename t>
inline void TemplateLinkList<t>::append(int value)
{
	TemplateLinkList *newNode = new TemplateLinkList;
	newNode->value = value;
	newNode->next = nullptr;
	newNode->prev = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		TemplateLinkList *iter = head;
		while (iter->next != nullptr)
		{
			iter = iter->next;
		}
		newNode->prev = iter;
		iter->next = newNode;
	}
}

template<typename t>
inline t TemplateLinkList<t>::at(t index)
{
	TemplateLinkList *iter = head;
	t iterionCount = 0;
	while (iterionCount != index && iter != nullptr)
	{
		iterionCount++;
		iter = iter->next;
	}
	assert(iter != nullptr);

	return iter->value;
}

template<typename t>
inline t TemplateLinkList<t>::size() const
{
	t count = 0;
	TemplateLinkList *iter = head;
	while (iter != nullptr)
	{
		count++;
		iter = iter->next;
	}
	return count;
}

template<typename t>
inline bool TemplateLinkList<t>::empty() const
{
	return head == nullptr;
}

template<typename t>
inline t TemplateLinkList<t>::front() const
{
	assert(!empty());
	return head->value;
}

template<typename t>
inline t TemplateLinkList<t>::back() const
{
	assert(!empty);
	TemplateLinkList *iter = head;
	while (iter->next != nullptr)
	{
		iter = iter->next;
	}

	return iter->value;
}

template<typename t>
inline void TemplateLinkList<t>::clear()
{
	TemplateLinkList *iter = head;
	while (iter != nullptr)
	{
		TemplateLinkList *next = iter->next;
		delete iter;
		iter = next;
	}
	head = nullptr;
}

template<typename t>
inline void TemplateLinkList<t>::erase(size_t idx)
{
	TemplateLinkList *iter = head;
	assert(idx <= size());
	int count = 0;
	TemplateLinkList *temp = iter;
	while (iter->next != nullptr && count != idx)
	{
		count++;
		temp = iter;
		iter->next = temp;
	}
	temp->next = iter->next;
	delete iter;
}

template<typename t>
inline t TemplateLinkList<t>::count(t sum) const
{
	TemplateLinkList *iter = head;
	t count = 0;
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

template<typename t>
inline void TemplateLinkList<t>::insert(t num, size_t idx)
{
	TemplateLinkList *iter = head;
	TemplateLinkList *newItem = new TemplateLinkList;
	TemplateLinkList *temp = head;
	newItem->value = num;
	t count = 0;
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
}
