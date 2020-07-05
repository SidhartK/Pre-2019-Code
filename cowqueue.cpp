
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

int main()
{
	std::ifstream fin ("cowqueue.in");
	std::ofstream fout ("cowqueue.out");

	int n;
	fin >> n;

	std::map<int,int> time;
	std::vector<int> sortcow;

	for (int i = 0; i < n; i++)
	{
		int cow;
		int cowtime;
		fin >> cow >> cowtime;
		time[cow] = cowtime;
		sortcow.insert (sortcow.begin(), cow);
	}
	std::sort (sortcow.begin(), sortcow.end());

	int totaltime = 0;
	for (int i = 0; i < n; i++){
		if (totaltime < sortcow[i]){
			totaltime = sortcow[i];
		}
		totaltime += time[sortcow[i]];
	}
	fout << totaltime << endl;
}