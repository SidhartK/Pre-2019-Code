#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

//#define DEBUG
#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

int main()
{
	std::ifstream fin ("crossroad.in");
	std::ofstream fout ("crossroad.out");

	int crossnum = 0;
	int n;
	fin >> n;

	std::map<int,int> cowstate;

	for (int i = 1; i <= 10 ; i++){
		cowstate[i] = 2;
	}

	for (int i = 0; i < n; i++){
		int cow;
		int statenow;

		fin >> cow >> statenow;

		if (cowstate[cow] != statenow){
			crossnum++;
			cowstate[cow] = statenow;
		}
	}

	int changenum = 0;
	for (int i = 1; i <= 10; i++){
		if (cowstate[i] != 2){
			changenum++;
		}
	}

	fout << crossnum - changenum << endl;
}