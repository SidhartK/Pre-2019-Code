
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
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
	std::ifstream fin ("circlecross.in");
	std::ofstream fout ("circlecross.out");

	std::string input;
	fin >> input;

	int crosspnum = 0;
	for (int i = 0; i < 52; i++){
		for (int j = 0; j <= i; j++){
			if (input[i] != input[j]){
				int seci, secj;
				for (int k = 0; k < 52; k++){
					if (input[i] == input[k] && i != k){
						for (int l = 0; l < 52; l++){
							if (input[j] == input[l] && j != l){
								seci = k;
								secj = l;
							}
						}
						
					}

				}

				if (i < secj && secj < seci){
					crosspnum ++;

				}		
			}
		}
	}
	fout << crosspnum << endl;

}