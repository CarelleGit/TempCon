#pragma once
#include "tVector.h"

template<typename t>
class Stack
{
private:
	tVector<t> vector;
public:

	Stack(size_t cap);
	~Stack();

	// top = -1

	t top();
	//empty

	bool empty();
	//pop

	void pop();

	// - return pop

	//push

	void push(t val);
	// - add element to the top of the stack
	//top
	//-access top of thes tack
};

template<typename t>
inline Stack<t>::Stack(size_t cap)
{
	vector = vector.size = 2;
	vector.Capacity = cap;
	vector.data = { 0 };
	vector.at(vector.size - 1) = -1;
}

template<typename t>
inline Stack<t>::~Stack()
{
	delete[] vector.data();
}

template<typename t>
inline t Stack<t>::top()
{

	return vector.at(vector.size-1);
}

template<typename t>
inline bool Stack<t>::empty()
{
	return vector.empty();
}

template<typename t>
inline void Stack<t>::pop()
{
}

template<typename t>
inline void Stack<t>::push(t val)
{
	vector.append(val); 
}
