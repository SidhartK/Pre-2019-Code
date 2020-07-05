#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main() 
{
	std::ifstream fin ("square.in");
	std::ofstream fout ("square.out");

	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;

	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

	int a;
	int b;
	int c;
	int d;

	a = std::min(x1 , x3);
	b = std::max(x2 , x4);

	c = std::min(y1 , y3);
	d = std::max(y2 , y4);

	int u;
	int v;
	int w;

	u = b - a;
	v = d - c;
	w = std::max(u , v);

	fout << w * w << std::endl;

}