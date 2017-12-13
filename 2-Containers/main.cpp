#include <iostream>
#include "IntLinkList.h"
#include "HashMap.h"
#include "Algorithms.h"
using std::cout;

int main()
{  
	HashMap<int> mapping;

	mapping.put(1, 75);

	std::cout << mapping.findKey(0) << std::endl;


	while (true){}
}