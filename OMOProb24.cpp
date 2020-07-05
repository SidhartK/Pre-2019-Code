#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	cout << "Input n" << endl;
	int n;
	cin >> n;
	int counter = 0;
	int m = (pow(n,2)) / 2;
	int squares[m][2];
	int index = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if ((i + j) % 2 == 0){
				squares[index][0] = i;
				squares[index][1] = j;
				index ++;
			}
		}
	}
	int checkboard[n][n];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			checkboard[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++){
		checkboard[squares[i][0]][squares[i][1]] = 1;
	}
	for (int j = 0; j < n; j++){
		for (int i = 0; i < n; i++){
			cout << checkboard[i][j];
		}
		cout << endl;
	}
	bool arrangworks = true;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < m; k++){
				if (std::abs(squares[i][0] - squares[j][0]) == std::abs(squares[i][1] - squares[j][1])){
					arrangworks = false;
				}
				if (std::abs(squares[j][0] - squares[k][0]) == std::abs(squares[j][1] - squares[k][1])){
					arrangworks = false;
				}
				if (std::abs(squares[k][0] - squares[i][0]) == std::abs(squares[k][1] - squares[i][1])){
					arrangworks = false;
				}
				if (arrangworks){
					counter ++;
				}
				arrangworks = true;
			}
		}
	}
	cout << "Number of Good Arrangements is " << counter << endl;
}
/*{
	cout << "Input prime" << endl;
	int p;
	cin >> p;
	int counter = 0;
	for (int a = 0; a < p; a++){
		for (int b = 0; b < p; b++){
			for (int c = 0; c < p; c++){
				int k = (pow(a, 3)) + (pow(b, 3)) + (pow(c, 3));
				int n = 3 * a * b * c;
				if ((k - n) % p == 1){
					cout << "(" << a << ", " << b << ", " << c << ")" << endl;
					counter ++;
				}
			}
		}
	}
	cout << "The number of ordered pairs is " << counter << endl;
}
cout << "Input k" << endl;
	int k;
	cin >> k;
	int set[k];
	cout << "Input primes" << endl;
	for (int i = 0; i < k; i++){
		cin >> set[i];
	}
	cout << "Input n" << endl;
	int n;
	cin >> n; 
	int counter = 0;
	bool fakecount = true; 
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k; j++){
			if (i % set[j] == 0){
				fakecount = false;
				break;
			}
		}
		if (fakecount){
			counter ++; 
		}
		fakecount = true;
	}
	cout << "g(n) is " << counter << endl; 
*/


