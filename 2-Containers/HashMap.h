#pragma once
#include "tVector.h"
#include "Intvector.h"
template<typename t>
class HashMap
{
public:

	int Hash(int key);

	void put(size_t key, t value);

	t read(size_t key) const;

	void clear();

	bool equal(HashMap map);

	void remove(size_t key);

	int size();

	bool findKey(size_t key);

	bool empty(HashMap map);

	intvector keys(map);

	t &operator[](t key);
	bool &operator==(t key1, t key2);
	bool &operator!=(t key1, t key2);

private:

	tVector<int> map;


};

template<typename t>
inline int HashMap<t>::Hash(int key)
{
	return key % map.Capacity();
}

template<typename t>
inline void HashMap<t>::put(size_t key, t value)
{
	map.insert(key, value);
}

template<typename t>
inline t HashMap<t>::read(size_t key) const
{
	return map[key];
}

template<typename t>
inline void HashMap<t>::clear()
{

}

template<typename t>
inline bool HashMap<t>::equal(HashMap map)
{
	return false;
}

template<typename t>
inline void HashMap<t>::remove(size_t key)
{
}

template<typename t>
inline int HashMap<t>::size()
{
	return 0;
}

template<typename t>
inline bool HashMap<t>::findKey(size_t key)
{
	return false;
}

template<typename t>
inline bool HashMap<t>::empty(HashMap map)
{
	return false;
}

template<typename t>
inline intvector HashMap<t>::keys(map)
{
	return intvector();
}

template<typename t>
inline t & HashMap<t>::operator[](t key)
{
	return map.at(key);
}

template<typename t>
inline bool & HashMap<t>::operator==(t key1, t key2)
{
	// TODO: insert return statement here
}

template<typename t>
inline bool & HashMap<t>::operator!=(t key1, t key2)
{
	// TODO: insert return statement here
}
