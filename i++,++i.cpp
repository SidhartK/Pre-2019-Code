#include <iostream>
#include <climits>
#include <iomanip>
#include <cmath>
using namespace std;

void func(int i)
{
	cout << "Called with " << i << endl;
	return;
}

void test()
{
	int i, savedi;

	cout << "Input i: ";
	cin >> i;
	savedi = i;

	func(i++);

	i = savedi;
	func(++i);


	int a = i+=3;
	cout << "a: " << a << " i: " << i << endl;
	int b = ++i;
	cout << "b: " << b << " i: " << i << endl;
}

void test2()
{
	short bits1 = 0x7fff;
	short bits = bits1 + 1;
	//bits = ~bits;
	cout << bits1 << " " << bits << endl;
}

int main()
{
	// test1();
	test2();
}