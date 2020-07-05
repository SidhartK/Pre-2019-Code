#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define DEBUG
#ifdef DEBUG
#define dout cout
#else
#define dout 0 && cout
#endif

int main()
{

	ifstream fin ("hps.in");
	ofstream fout ("hps.out");

	int n;
	fin >> n;

	char character [3] = {'H', 'P', 'S'};
	char moves [n];

	map<char,int> count;
	map<char,int> tcount;
	map <char,int> bcount;

	for (int i = 0; i < n; i++){
		char gesture;
		fin >> gesture;
		moves[i] = gesture;
		count[gesture]++;
		tcount[gesture]++;
		bcount[gesture] = 0;
	}

	int maxwin, tmaxwin, bmaxwin;

	for (int i = 0; i <= n; i++){
		for (int j = 0; j < 3; j++){
			if (tmaxwin < tcount[character[j]]){
				tmaxwin = tcount[character[j]];
				dout << "The Top Max Win is " << tmaxwin << endl;
			}
			if (bmaxwin < bcount[character[j]]){
				bmaxwin = bcount[character[j]];
				dout << "The Bottom Max Win is " << bmaxwin << endl;
			}
		}

		int posmaxwin = tmaxwin + bmaxwin;
		if (maxwin < posmaxwin){
			maxwin = posmaxwin;
		}

		for (int k = 0; k < 3; k++){
			if (moves[n - (i + 1)] == character[k]){
				tcount[character[k]]--;
				bcount[character[k]]++;
			}
			dout << "The top count of " << character[k] << " is " << tcount[character[k]] << endl;
			dout << "And the bottom count of " << character[k] << " is " << bcount[character[k]] << endl;
		}
		dout << "The current maximum is " << maxwin << endl;

	}

	fout << maxwin << endl;
}