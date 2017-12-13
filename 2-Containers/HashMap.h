#pragma once
#include "tVector.h"
#include "Intvector.h"
template<typename t>
class HashMap
{
public:

	HashMap();

	int Hash(int key);

	void put(size_t key, t value);

	t read(size_t key) const;

	void clear();

	bool equal(HashMap map1, HashMap map2);

	void remove(size_t key);

	int size(HashMap sMap);

	bool findKey(size_t key);

	bool empty(HashMap mapH);

	intvector keys(HashMap Hmap);

	t &operator[](t key);
	bool operator==(const t& rhs);
	bool operator!=(const t& rhs);





private:
	tVector<bool> use;

	tVector<t> map;
	intvector _keys;

};

template<typename t>
inline HashMap<t>::HashMap()
{
	map.reserve(50);

}

template<typename t>
inline int HashMap<t>::Hash(int key)
{
	assert(key > 0);
	return key % map.Capacity();
}

template<typename t>
inline void HashMap<t>::put(size_t key, t value)
{
	_keys.append(key);
	use[Hash(key)] = true;
	int ID = Hash(key);
	map[ID] = value;


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
	map.clear();
}

template<typename t>
inline bool HashMap<t>::equal(HashMap map1, HashMap map2)
{
	assert(map1.map.size() == map2.map.size() && map1.map.Capacity() == map2.map.Capacity());
	int count = 0;
	for (int i = 0; i < map.Capacity() - 1; i++)
	{
		it(map1.map[i] == map2.map[i])
		{
			count++;
		}
	}
	if (map.Capacity() == count + 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename t>
inline void HashMap<t>::remove(size_t key)
{
	map.erase(key);
}

template<typename t>
inline int HashMap<t>::size(HashMap sMap)
{
	sMap.map.Size();
}

template<typename t>
inline bool HashMap<t>::findKey(size_t key)
{
	assert(key < map.Capacity());
	if (use[Hash(key)] == true )
	{
		return true;
	}
	else
	{
		false;
	}
}

template<typename t>
inline bool HashMap<t>::empty(HashMap mapH)
{
	return mapH.map.empty();
}

template<typename t>
inline intvector HashMap<t>::keys(HashMap Hmap)
{
	//intvector tmp;
	//for (int i = 0; i < Hmap.map.Capacity(); i++)
	//{
	//	if (map[i] != nullptr)
	//	{
	//		map.append(i);
	//	}
	//}
	return _keys;
}

template<typename t>
inline t & HashMap<t>::operator[](t key)
{
	return map.at(key);
}

template<typename t>
inline bool  HashMap<t>::operator==(const t& rhs)
{
	if (*this == rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename t>
inline bool  HashMap<t>::operator!=(const t& rhs)
{
	if (*this == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}
