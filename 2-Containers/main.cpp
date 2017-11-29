#include <iostream>
#include "Intvector.h"
#include "tVector.h"
using std::cout;

int main()
{  
	tVector<int> asdf;
	intvector nums;
	nums.append(1);
	nums.append(4);
	nums.append(4);
	nums.append(4);
	nums.append(5);

	nums.erase(3);
	//int counting = nums.count(4);

	for (int i = 0; i < nums.Size(); i++)
	{
		cout << nums[i] << "\n";
	}
	//cout << counting << "\n";
	
	while (true){}
}