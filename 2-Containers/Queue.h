#pragma once
#include"TemplateLinkList.h"
template<typename t>
class Queue
{
private:
	TemplateLinkList list;
public:
	Queue();
	~Queue();



	//front = head
	t front() const;
	//empty
	bool empty();
	//size
	int size();
	//push
	void push(t val);
	//pop
	void pop();
	
	//front
	//back
	t back() const;
};

template<typename t>
inline Queue<t>::Queue()
	:head(nullptr)
{

}

template<typename t>
inline Queue<t>::~Queue()
{
	list.~TemplateLinkList();
}

template<typename t>
inline t Queue<t>::front() const
{
	return list.front();
}

template<typename t>
inline bool Queue<t>::empty()
{
	return list.head == nullptr;
}

template<typename t>
inline int Queue<t>::size()
{
	return list.size();
}

template<typename t>
inline void Queue<t>::push(t val)
{
	list.append(val);
}

template<typename t>
inline void Queue<t>::pop()
{

}

template<typename t>
inline t Queue<t>::back() const
{
	return list.back();
}


