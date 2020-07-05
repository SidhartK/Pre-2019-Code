#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

int main()
{
	std::ifstream fin ("censor.in");
	std::ofstream fout ("censor.out");

	string word;
	string censor;

	fin >> word >> censor;
	cout << word << ' ' << censor << endl;

	int n = 1;
	while (n != 0)
	{
		n = 0;
		string wcopy (word);
		int x = word.length() - censor.length();
		cout << x << endl;
		for (int i = 0; i <= x; i++){
			string check (wcopy, i, censor.length());
			if(check == censor){
				word.erase (i,censor.length());
				cout << word << endl;
				n = n + 1;
			}
			n = n - 1;
			cout << n << endl;
		}
		cout << n << endl;
		n = n + x;
	}

	fout << word << endl;
}