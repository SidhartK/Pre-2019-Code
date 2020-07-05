#include <iostream>

using namespace std;

int main()
{
	cout << "Please input the number of elements in your list" << endl;
	int n;
	cin >> n;
	cout << "Please input the list in any order" << endl;
	double list[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}

	double max = list[0];

	for (int i = 0; i < n; i++)
	{
		if (list[i] > max)
		{
			max = list[i];
		}
	}

	cout << "The maximum of the list is " << max << endl;

	return max;

}	