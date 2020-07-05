#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	/*int n;
	cin >> n;
	bool isprime = true;
	if (n == 1){
		isprime = false;
	}

	for (int i = 2; i <= floor(sqrt(n)); i++){
		if (n % i == 0) 
		{
			isprime = false;
			cout << i << " divides it. ";
			break;
		}
	}
	if (isprime){
		cout << "It is a prime" << endl;
	}
	else{
		cout << "So is composite" << endl;
	}*/	
	/*int m;
	cin >> m;
	int counter = 0;
	for (int i = 70000000; i < m; i++){
		int n = i;
		int sum = 0;
		for (int j = 0; j < 8; j++){
			int a = n % 10;
			int b = pow(a, 8);
			sum = sum + b;
			n = (n - a) / 10;
		}
		if (i == sum){
			cout << i << endl;
			counter = counter + 1;
		}
	} 
	if (counter == 0){
		cout << "No solutions" << endl;
	}*/
	int m;
	cin >> m;
	cout << 3 << endl << 5 << endl << 7 << endl << 17 << endl;
	for (int i = 50000; i < m; i++){
		int j = 2 * i + 1;
		int x = 1;
		for (int k = 0; k < j; k++){
			int y = 16 * x;
			x = y % (j - 2);
		}
		if (x == 1){
			if (j % 3 != 0 ){
				if (j % 5 != 0){
					if (j % 7 != 0){
						cout << j << endl;
					}
				}
			}
		}
	}
}


