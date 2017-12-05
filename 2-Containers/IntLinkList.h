#pragma once


class intLinkList
{
public:
	struct intLinkListNode
	{
		int value;
		intLinkListNode *next;
		intLinkListNode *prev;
	};
	intLinkList();
	~intLinkList();

	void append(int value);

	int at(int index);
	
	int size() const;
	bool empty() const;
	int front() const;
	int back() const;
	void clear();
	void erase(size_t idx);
	int count(int sum) const ;
	void insert(int num, size_t idx);

private:

	intLinkListNode *head;
};