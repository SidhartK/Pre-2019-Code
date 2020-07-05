#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	cout << "Please insert the integers" << endl;
	int n;
	int a;
	cin >> n >> a;
	cout << "These are the integers created by a";
	for (int i = 0; i < n; i++){
		int k = pow(a, i);
		int m = k % n;
		cout << m << " ";
	}
	cout << endl;
	cout << "These are the squares";
	for (int i = 0; i < n; i++){
		int k = pow(i, 2);
		int m = k % n;
		cout << m << " ";
	}
	cout << endl;



		/*cout << "Please insert integer n" << endl;
	}
	int n;
	cin >> n;
	int s;
	s = floor (pow(n, 0.5));
	for (int i = 0; i < s + 1; i++){
		for (int j = 0; j < i; j++){
			if (pow(i, 2) + pow(j, 2) == n){
				cout << "Two possible integers are: (" << i << ", " << j << ")" << endl;
				cout << "Their sum is: " << i + j << endl;
			}
		}
	}*/
	/*cout << "Please insert the number of integers in the list" << endl;
	int n;
	cin >> n;
	cout << "Please insert the integers in the list" << endl;
	std::vector<int> integers (n); 
	for (int i = 0; i < n; i++){
		cin >> integers[i];
	}
	int counter = 0;
	while (counter < n){
		counter = 0;
		for (int i = 0; i < n - 1; i++){
			if (integers[i] < integers[i + 1]){
				int a = integers[i];
				int b = integers[i + 1];
				integers[i] = b;
				integers[i + 1] = a;
			}
			else{
				counter++;
			}
		}
	}
	cout << "The sorted list is ";
	for (int i = 0; i < n; i++){
		cout << integers[i];
	}*/
}
