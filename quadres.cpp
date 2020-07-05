#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool isprime (int n)
{
	if (n == 1)
	{
		return false;
	}

	for (int i = 2; i <= floor(sqrt(n)); i++)
	{
		if (n % i == 0) 
		{
			return false;
		}
	}

	return true;	
}

bool isquadres (int a, int p)
{
	int x = floor((p - 1) / 2);
	int y = int (pow(a, x) ) % p;

	// y is a quadratic residue when it not -1 mod p
	return (y != (p-1));
}


void list_quadres(int a, int p, std::set<int> & quadresset)
{
	for (int i=1; i<= floor((p - 1) / 2); i++)
  	{
  		int y = int (pow(i, 2)) % p;
  		quadresset.insert(y); 
  	} 
}


int main ()
{
	int a, p;

	cout << "Insert a, p ";
	cin >> a >> p;


	cout << "Outside increment_ap " << a << " " << p << endl;

	// Return if p is not a prime
	if (!isprime(p))
	{
		cout << "The integer " << p << " is not a prime" << endl;
		return 0;
	}

	cout << "The integer " << a << " is";
	cout << (isquadres(a, p) ? "" : " not");
	cout << " a quadratic residue of " << p << endl;

	std::set<int> quadresset;
	list_quadres(a, p, quadresset);
	cout << "Here are the quadratic residues:";
	for (auto it=quadresset.begin(); it!=quadresset.end(); ++it)
	{
		cout << ' ' << *it;
	}
	
	cout << '\n';
}