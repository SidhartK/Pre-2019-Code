#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n;
	cout << "Insert maximum degree + 1: ";
	cin >> n;

	int Tpoly[n][n + 1];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n + 1; j++){
			Tpoly[i][j] = 0;
		}
	}
	Tpoly[0][0] = 1;
	Tpoly[1][1] = 1;
	for (int i = 2; i < n; i++){
		for (int j = 0; j < n + 1; j++){
			if (j == 0){
				if ((i % 2) == 0){
					if (i % 4 == 0){
						Tpoly[i][j] = 1;
					}
					if (i % 4 == 2){
						Tpoly[i][j] = -1;
					}
				}
			}
			else{
				Tpoly[i][j] = 2 * Tpoly[i - 1][j - 1] - Tpoly[i - 2][j];	
			}
		}
	}
	int Sum[n];
	for (int i = 0; i < n; i++){
		Sum[i] = 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = i; j >= 0; j--){
			/*if (Tpoly[i][j] >= 0 ){
				Sum[i] = Sum[i] + Tpoly[i][j];
			}
			else{
				Sum[i] = Sum[i] - Tpoly[i][j];
			}
			
			*/cout << Tpoly[i][j] << " ";
		}
		//cout << ";" << " The Sum of absolute values is:  " << Sum[i];
		cout << endl;
	}
}