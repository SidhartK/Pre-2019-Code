#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>

using namespace std;

typedef struct s {
	int id;
	string name;
} s; 

bool compare (const s &a, const s &b){
	return (a.id < b.id);
}


int main()
{
	ifstream fin("sort.in");

	int N; fin >> N;
	vector<vector<int> > B (10, vector<int> (20));
	std::vector<s> A (N);
	for (int i = 0; i < N; i++){
		fin >> A[i].id >> A[i].name;
	}
	/* for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			if (A[i].name < A[j].name){
				myswap (A[i], A[j]);
			}
		}
	} */
	sort(A.begin(), A.end(), compare);
	for (int i = 0; i < N; i++){
		cout << A[i].id << " " << A[i].name << endl;
	}
}