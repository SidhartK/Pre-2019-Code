#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main (){
	int binary;
	cout << "Do you want table of logs (press 0), root checker (press 1), root finder (press 2), pell equation value finder (press 3), pell equation solver (press 4): " << endl;
	cin >> binary;
	if (binary == 0){
		int n;
		cout << "Insert mod: ";
		cin >> n;
		int a;
		cout << "Insert the base: ";
		cin >> a;
		int m;
		cout << "Insert mth power: ";
		cin >> m;
		int power = 0;
		int value = 1;

		cout << "power " << "value" << endl;

		for (int i = 0; i < n; i++){
			if (i % m == 0){
				cout << power << "     " << value << endl;
			}	
			power ++;
			value = (a * value) % n;  
		}
	}
	if (binary == 1){
		int n;
		cout << "Insert mod: ";
		cin >> n;
		int a;
		cout << "Insert the base: ";
		cin >> a;
		int m;
		cout << "Insert mth power: ";
		cin >> m;

		int k = (n - 1)/m;
		int value = 1;

		for (int i = 0; i < k; i++){
			value = (a * value) % n;
		}
		if (value == 1){
			cout << "Yes it is an mth power" << endl;
		}
		else{ 
			cout << "No it is not an mth power" << endl;
		}
	}
	if (binary == 2){
		int n;
		cout << "Insert mod: ";
		cin >> n;
		int m;
		cout << "Insert power: ";
		cin >> m;
		int a;
		cout << "Insert the value of the mth power: ";
		cin >> a;
		int product = 1;
		int solnum = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				product = (product * i) % n;
			}
			if ((product % n) == a){
				cout << "One root is: " << i << endl;
				solnum ++; 
			}
			product = 1;
		}
		if (solnum == 0){
			cout << "There are no solutions." << endl;
		}
	}
	if (binary == 3){
		int n;
		cout << "Enter value of n in x^2 + ny^2: ";
		cin >> n;
		int max;
		cout << "Enter value of maximum value of x^2 + ny^2: ";
		cin >> max;
		cout << "The values of k that work are: " << endl;
		for (int k = 0; k <= max; k++){
			float x = k / n;
			int a = pow(x, 0.5);
			for (int i = 0; i <= a; i++){
				int b = k - (n * pow(i, 2));
				int p = pow(b, 0.5);
				if (pow(p, 2) + (n * pow(i, 2)) == k){
					cout << k << endl;
					break;
				}
			}
		}
	}
	if (binary == 4){
		int n;
		cout << "Enter value of n in x^2 + ny^2: ";
		cin >> n;
		int k;
		cout << "Enter value of x^2 + ny^2: ";
		cin >> k;
		float x = k/n;
		int max = pow(x, 0.5);
		bool solutions = false;
		for (int i = 0; i <= max; i++){
			int b = k - (n * pow(i, 2));
			int p = pow(b, 0.5);
			if (pow(p, 2) + (n * (pow(i, 2))) == k){
				solutions = true;
				break;
			}
		}
		if (!solutions){
			cout << "There are no solutions." << endl;
		}
		else{ 
			cout << "The solutions are (x,y) = " << endl;
			for (int i = 0; i <= max; i++){
				int b = k - (n * pow(i, 2));
				int p = pow(b, 0.5);
				if (pow(p, 2) + (n * (pow(i, 2))) == k){
					cout << "(" << p << ", " << i << ")" << endl;
				}
			}
		}

	}
}