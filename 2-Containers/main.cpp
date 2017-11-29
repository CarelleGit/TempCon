#include <iostream>
#include "Intvector.h"
#include "tVector.h"
using std::cout;

int main()
{  
	tVector<int> asdf;

	asdf.append(1);
	asdf.append(2);
	asdf.append(12);
	asdf.append(12);
	asdf.append(5);


	asdf.printVector();
	
	//int counting = nums.count(4);
	//cout << counting << "\n";
	
	while (true){}
}