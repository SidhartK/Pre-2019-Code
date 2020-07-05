#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{

	std::ifstream fin ("hps.in");
	std::ofstream fout ("hps.out");

	std::map<int, int> count;

	int n;
	fin >> n;

	// For loop to input values and increase counts 
	for (int i = 0; i < n; i++){
		int cow1;
		int cow2;
		fin >> cow1 >> cow2;

		if(cow1 == cow2){
			continue;
		}

		int cow1cow2 = (10 * cow1) + cow2;
		count[cow1cow2] += 1;

	}

	// If 1 beats 2 the left is the number of games cow 1 wins, and if 2 beats 1 the right is the 
	// number of games cow 1 wins
	// Compare two values to output which is the maximum that cow 1 could have won
	fout << std::max(count[12] + count[23] + count[31], count[21] + count[32] + count[13]);

}