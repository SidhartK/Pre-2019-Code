#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>

using namespace std;

int factorial (int a){
	int fact = 1;
	for (i = 1; i <= a; i++){
		fact = fact * i;
	}
	return fact;
}

int main (){
	cout << factorial(5) << endl;
}