#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

int main()
{
	string name1;
	string name2;
	cout << "Put in Player one's name: " << endl;
	cin >> name1;
	cout << "Put in Player two's name" << endl;
	cin >> name2;

	char grid [3][3];
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			grid[i][j] = '_';
		}
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	int moves = 0;
	bool win = false;
	while (!win){
		moves++;
		cout << "Input the coordinates of the grid. First the x, then a space, then the y" << endl;
		int x, y;
		cin >> x >> y;
		if (moves % 2 == 1){
			grid[x - 1][y - 1] = 'X';
		}
		if (moves % 2 == 0){
			grid[x - 1][y - 1] = 'O';
		}
		for (int i = 0; i < 3; i++){
			if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != '_'){
				win  = true;
			}
		}
		for (int j = 0; j < 3; j++){
			if (grid[0][j] == grid[1][j] && grid[0][j] == grid[2][j] && grid[0][j] != '_'){
				win  = true;
			}
		}
		if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != '_'){
			win  = true;
		}
		if (grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2] && grid[2][0] != '_'){
			win = true;
		}
		if (moves == 9){
			win =  true;
		}
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}	
	}
	if (moves < 9){
		if (moves % 2 == 1){
			cout << name1 << " Wins!!!!!!" << endl;
		}
		if (moves % 2 == 0){
			cout << name2 << " Wins!!!!!!" << endl;
		}
	}
	if (moves == 9){
		cout << "It's a tie. Good Game!!!" << endl;
	}

}