#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

#define NDEBUG
#ifndef NDEBUG
#define dout std::cout
#else
#define dout 0 && std::cout
#endif

int main()
{
	std::ifstream fin ("notlast.in");
	std::ofstream fout ("notlast.out");
	std::map<string, int> milk;

	std::vector<std::string> names = { "Bessie", "Elsie", "Daisy", "Gertie",
										 "Annabelle", "Maggie", "Henrietta"};
	for (int i = 0; i < names.size(); i++) {
		milk[names[i]] = 0;
	}
	
	int n;
	fin >> n;

	for (int i = 0; i < n; i++)
	{
		string cowin;
		int milkin;
		fin >> cowin >> milkin;

		milk[cowin] = milk[cowin] + milkin;
	}

	std::map<int, string> milkinv;
	for(int i = 0; i < names.size(); i++)
	{
		milkinv[milk[names[i]]] = names[i];
	}
	
	// Find the cow with minimum milk
	int minimum = INT_MAX;
	for(std::map<string, int>::iterator it = milk.begin(); it!= milk.end(); it++)
	{
		if (minimum > it->second)
		{
			minimum = it->second;
		}
	}

	dout << "Minimum is " << minimum << " " << milkinv[minimum] << std::endl;
	int second_minimum = INT_MAX;

	// Find the cow with next to minimum milk
	for(std::map<string, int>::iterator it = milk.begin(); it!= milk.end(); it++)
	{
		if (it->second > minimum && it->second < second_minimum)
		{
			second_minimum = it->second;
		}
	}

	dout << "Second Minimum is " << second_minimum << " " << milkinv[second_minimum] << std::endl;

	// Check for repeats of the second mininum
	int second_min_count = 0;
	for(std::map<string, int>::iterator it = milk.begin(); it != milk.end(); it++)
	{
		if (second_minimum == it->second)
		{
			second_min_count++;
		}

		if (second_min_count > 1) {
			break;
		}
	}

	// If there are repeats output tie else output the name of the cow
	if (second_min_count == 1)
	{
		fout << milkinv[second_minimum];
	}
	else {
		fout << "Tie";
	}
}
