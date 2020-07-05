#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int main (){
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
		if(i % m == 0){
			cout << power << "     " << value << endl;
		}	
		power ++;
		value = (a * value) % n;  
	}
}