#include <iostream>
#include <string>
#include <assert.h>
using std::cout;
//int add(int a, int b)
//{
//	return a + b;
//}
//
//float add(float a, float b)
//{
//	return a + b;
//}
//
//template<typename T>
//T sub(T a, T b)
//{
//	return a - b;
//}
template <typename t>
t print(t a)
{
	return a;
}

template<typename T>
T min(T a, T b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
template<typename T>
T max(T a, T b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

template <typename t>
t clamp(t a, t b, t v)
{
	int temp = v;
	temp = min(temp, b);
	temp = max(temp, a);
	return temp;
}
class person
{
public:
	int age;
	float height;
	std::string name;
};

template <typename s>
void swap(s &a, s &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << " Swap: " << a << ", " << b << "\n\n";
}
template<bool b>
bool boolAssert(bool a)
{
	assert(b == a);
	
}
template<typename t>
t equal(t a, t b)
{
	assert(b == a); 

}
template<typename t>
t notequal(t a, t b)
{
	assert(b != a);

}
int main()
{
	/*int vi = add(5, 2);
	float v2 = add(2.1f, 3.2f);

	int s1 = sub(1, 1);
	float s2 = sub(2.5f, 1.1f);
	int s3 = sub<int>(1, 2.0f);*/
	person Solstice;
	Solstice.name = "Solstice";
	Solstice.age = 16;
	Solstice.height = 5.2f;

	cout << "\nName: " << Solstice.name << ", Age: " << Solstice.age << ", Height: " << Solstice.height << "\n\n";

	int prt1 = print(1);
	float prt2 = print(1.2f);
	bool prt3 = print(true);
	cout << "Int: " <<prt1 << ", Float: " << prt2 << ", Bool: " << prt3 << "\n\n";

	int min1 = min(2, 5);
	int max1 = max(10, 2);
	int clamp1 = clamp(2, 10, 20);
	cout << "min: " << min1 << ", max: " << max1 << ", Clamp: " << clamp1 << "\n\n";

	int a = 12;
	int b = 5;
	cout << a << ", " << b;
	swap(a, b);

	char min2 = min('z', 'w');
	char max2 = max('s', 'd');
	cout << "min: " << min2 << ", max: " << max2 << "\n\n";

	int m = 5;
	int k = 6;
	equal(m, k);


	while (true){}
}