#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int d;
	int x;
	int y;

	std::cout << "Enter Coordinates" << std::endl;
	std::cin >> a >> b >> c >> d;
	
	x = std::abs(a - c);
	y = std::abs(b - d);

	std::cout << "Area is " << x * y << std::endl;
}
