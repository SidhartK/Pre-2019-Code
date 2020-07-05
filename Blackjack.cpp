#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <vector>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>
#include <algorithm>    
#include <vector>       
#include <ctime>        
#include <cstdlib>
#include <string>

using namespace std;

int myrandom (int i) { return std::rand()%i;}

int deckshuffle (int deck[52]) {
	std::srand ( unsigned ( std::time(0) ) );
	std::vector<int> myvector;
	for (int i=1; i < 53; ++i) {
		myvector.push_back(i); 
	} 

	std::random_shuffle ( myvector.begin(), myvector.end() );
	std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);
	int ind = 0;
 	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
 		int value = *it;
 		deck[ind] = value;
 		ind = ind + 1;
 	}
  return 0;
}
int PlayerMovesAfterFirst (int numcard, int hand[3][12], int handvalue, int handnumA, int deck[52], int index){
	int movesleft = 11 - numcard;
	std::string move;
	int k = handnumA;
	for (int i = numcard + 1; i < 12; i++){
		cout << "What move do you want to do?" << endl;
		cin >> move;
		while (move != "Hit" && move != "Stay"){
			cout << "That is not a valid move. Please enter one of the following moves:" << endl;
			cout << "'Hit', 'Stay'" << endl;
			cout << "What move do you want to do?" << endl;
			cin >> move;
		}
		if (move == "Hit"){
			hand[0][i] = deck[index];
			index += 1;
			hand[1][i] = (hand[0][i] % 13) + 1;
			cout << "The card you were dealt is: ";
			if (hand[1][i] > 1 && hand[1][i] < 11){
				hand[2][i] = hand[1][i];
				cout << hand[2][i];
			}
			else if (hand[1][i] == 1){
				hand[2][i] = 11;
				cout << "A";
				handnumA += 1;
			}
			else if (hand[1][i] == 11){
				hand[2][i] = 10;
				cout << "J";
			}
			else if (hand[1][i] == 12){
				hand[2][i] = 10;
				cout << "Q";
			}
			else if (hand[1][i] == 13){
				hand[2][i] = 10;
				cout << "K";
			}
			cout << endl;
			handvalue += hand[2][i];
			k = handnumA;
			if (handvalue > 21 && handnumA > 0){
				for (int j = 0; j < k; j++){
					handvalue = handvalue - 10;
					handnumA = handnumA - 1;
					if (handvalue <= 21){
						break;
					}
				}
			}
			if (handvalue > 21){
				break;
			}
		}
		if (move == "Stay"){
			break;
		}
	}
	return index;
}

int main()
{
	int deck[52];
	deckshuffle(deck);
	int index = 0;
	int dealerhand [3][12];
	int dealervalue = 0;
	int dealernumA = 0;
	int playerhand [3][12];
	int playervalue = 0;
	int playernumA = 0;
	int numcards = 0;
	int playerhand2 [3][12];
	int playervalue2 = 0;
	int playernumA2 = 0;
	int numcards2 = 0;
	int playerhand3 [3][12];
	int playervalue3 = 0;
	int playernumA3 = 0;
	int numcards3 = 0;
	int playerhand4 [3][12];
	int playervalue4 = 0;
	int playernumA4 = 0;
	int numcards4 = 0;
	int numhands = 1;
	bool busted = true;
	bool busted2 = true;
	bool busted3 = true;
	bool busted4 = true;
	bool blackjack = false;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 12; j++){
			dealerhand[i][j] = 0;
			playerhand[i][j] = 0;
			playerhand2[i][j] = 0;
			playerhand3[i][j] = 0;
			playerhand4[i][j] = 0;
		}
	}
	cout << "How many dollars do you want to bet?" << endl;
	cin >> playerhand[0][0];
	dealerhand[0][1] = deck[index];
	index += 1;
	dealerhand[1][1] = (dealerhand[0][1] % 13) + 1;
	dealerhand[0][2] = deck[index];
	index += 1;
	dealerhand[1][2] = (dealerhand[0][2] % 13) + 1;
	cout << "The dealer's face up card is: ";
	if (dealerhand[1][1] > 1 && dealerhand[1][1] < 11){
			cout << dealerhand[1][1] << " ";
			dealerhand[2][1] = dealerhand[1][1];
		}
	else if (dealerhand[1][1] == 1){
		cout << "A ";
		dealerhand[2][1] = 11;
		dealernumA += 1;
	}
	else if (dealerhand[1][1] == 11){
		cout << "J ";
		dealerhand[2][1] = 10;
	}
	else if (dealerhand[1][1] == 12){
		cout << "Q ";
		dealerhand[2][1] = 10;
	}
	else if (dealerhand[1][1] == 13){
		cout << "K ";
		dealerhand[2][1] = 10;
	}
	cout << endl;
	if (dealerhand[1][2] > 1 && dealerhand[1][2] < 11){
			dealerhand[2][2] = dealerhand[1][2];
		}
	else if (dealerhand[1][2] == 1){
		dealerhand[2][2] = 11;
		dealernumA += 1;
	}
	else if (dealerhand[1][2] == 11){
		dealerhand[2][2] = 10;
	}
	else if (dealerhand[1][2] == 12){
		dealerhand[2][2] = 10;
	}
	else if (dealerhand[1][2] == 13){
		dealerhand[2][2] = 10;
	}
	dealervalue = dealerhand[2][1] + dealerhand[2][2];
	if (dealervalue > 21){
		dealervalue = 12;
		dealernumA = 1;
	}
	playerhand[0][1] = deck[index];
	index += 1;
	playerhand[1][1] = (playerhand[0][1] % 13) + 1;
	playerhand[0][2] = deck[index];
	index += 1; 
	playerhand[1][2] = (playerhand[0][2] % 13) + 1;
	cout << "Your hand is: ";
	for (int i = 1; i <= 2; i++){
		if (playerhand[1][i] > 1 && playerhand[1][i] < 11){
			cout << playerhand[1][i] << " ";
			playerhand[2][i] = playerhand[1][i];
		}
		else if (playerhand[1][i] == 1){
			cout << "A ";
			playerhand[2][i] = 11;
			playernumA += 1;
		}
		else if (playerhand[1][i] == 11){
			cout << "J ";
			playerhand[2][i] = 10;
		}
		else if (playerhand[1][i] == 12){
			cout << "Q ";
			playerhand[2][i] = 10;
		}
		else if (playerhand[1][i] == 13){
			cout << "K ";
			playerhand[2][i] = 10;
		}
		playervalue += playerhand[2][i];
	}
	cout << endl;
	if (playervalue == 21){
		cout << "You have a blackjack!" << endl;
		blackjack = true;
		cout << "The dealer's cards are: ";
		for (int i = 1; i <= 2; i++){
			if (dealerhand[1][i] > 1 && dealerhand[1][i] < 11){
				cout << dealerhand[1][i] << " ";
			}
			else if (dealerhand[1][i] == 1){
				cout << "A ";
			}
			else if (dealerhand[1][i] == 11){
				cout << "J ";
			}
			else if (dealerhand[1][i] == 12){
				cout << "Q ";
			}
			else if (dealerhand[1][i] == 13){
				cout << "K ";
			}
		}
		cout << endl;
		if (dealervalue < 21){
			cout << "You won " << playerhand[0][0] << " dollars." << endl;
		}
		if (dealervalue == 21){
			cout << "The dealer also has blackjack so you do not win or lose." << endl;
		}
	}
	std::string moves[11];
	bool cont = true;
	bool cont2 = true;
	bool cont3 = true;
	bool cont4 = true;
	if (!blackjack){
		cout << "What move do you want to do?" << endl;
		cin >> moves[0];
		while (moves[0] != "Hit" && moves[0] != "Stay" && moves[0] != "Double" && moves[0] != "Split"){
			cout << "That is not a valid move. Please enter one of the following moves:" << endl;
			cout << "'Hit', 'Stay', 'Double', 'Split'" << endl;
			cout << "What move do you want to do?" << endl;
			cin >> moves[0];
		}
		
		while (moves[0] == "Split" && (playerhand[2][1] != playerhand[2][2] || playerhand[2][1] == 11)){
			cout << "You cannot split because your two cards are different or they are both Aces. Please enter one of the following moves:" << endl;
			cout << "'Hit', 'Stay', 'Double'" << endl;
			cin >> moves[0];
		}
		if (moves[0] == "Hit"){
			playerhand[0][3] = deck[index];
			index += 1;
			playerhand[1][3] = (playerhand[0][3] % 13) + 1;
			cout << "The card you were dealt is: ";
			if (playerhand[1][3] > 1 && playerhand[1][3] < 11){
				playerhand[2][3] = playerhand[1][3];
				cout << playerhand[2][3] << " ";
			}
			else if (playerhand[1][3] == 1){
				cout << "A ";
				playerhand[2][3] = 11;
				playernumA += 1;
			}
			else if (playerhand[1][3] == 11){
				cout << "J ";
				playerhand[2][3] = 10;
			}
			else if (playerhand[1][3] == 12){
				cout << "Q ";
				playerhand[2][3] = 10;
			}
			else if (playerhand[1][3] == 13){
				cout << "K ";
				playerhand[2][3] = 10;
			}
			cout << endl;
			numcards = 3;
			playervalue += playerhand[2][3];
			if (playervalue > 21 && playernumA > 0){
				int k = playernumA;
				for (int i = 0; i < k; i++){
					playervalue = playervalue - 10;
					playernumA = playernumA - 1;
					if (playervalue <= 21){
						break;
					}
				}
			}
			if (playervalue > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand[0][0] << " dollars." << endl;
				cont = false;
			}
		}
		if (moves[0] == "Stay"){
			cont = false;
			busted = false;
		}
		if (moves[0] == "Double"){
			playerhand[0][0] = playerhand[0][0] * 2;
			playerhand[0][3] = deck[index];
			index += 1;
			playerhand[1][3] = (playerhand[0][3] % 13) + 1;
			cout << "The card you were dealt is: ";
			if (playerhand[1][3] > 1 && playerhand[1][3] < 11){
				playerhand[2][3] = playerhand[1][3];
				cout << playerhand[2][3] << " ";
			}
			else if (playerhand[1][3] == 1){
				cout << "A ";
				playerhand[2][3] = 11;
				playernumA += 1;
			}
			else if (playerhand[1][3] == 11){
				cout << "J ";
				playerhand[2][3] = 10;
			}
			else if (playerhand[1][3] == 12){
				cout << "Q ";
				playerhand[2][3] = 10;
			}
			else if (playerhand[1][3] == 13){
				cout << "K ";
				playerhand[2][3] = 10;
			}
			cout << endl;
			numcards = 3;
			playervalue += playerhand[2][3];
			if (playervalue > 21 && playernumA > 0){
				int k = playernumA;
				for (int i = 0; i < k; i++){
					playervalue = playervalue - 10;
					playernumA = playernumA - 1;
					if (playervalue <= 21){
						break;
					}
				}
			}
			cont = false;
			busted = false;
			if (playervalue > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand[0][0] << " dollars." << endl;
				cont = false;
				busted = true;
			}
		}
		if (moves[0] == "Split"){
			playerhand2[0][0] = playerhand[0][0];
			playerhand2[0][1] = playerhand[0][2];
			playerhand2[1][1] = playerhand[1][2];
			playerhand2[2][1] = playerhand[2][2];
			playerhand[0][2] = deck[index];
			index += 1;
			playerhand[1][2] = (playerhand[0][2] % 13) + 1;
			cout << "Your first hands is now: ";
			if (playerhand[1][1] > 1 && playerhand[1][1] < 11){
				cout << playerhand[1][1] << " ";
			}
			else if (playerhand[1][1] == 1){
				cout << "A ";
			}
			else if (playerhand[1][1] == 11){
				cout << "J ";
			}
			else if (playerhand[1][1] == 12){
				cout << "Q ";
			}
			else if (playerhand[1][1] == 13){
				cout << "K ";
			}
			if (playerhand[1][2] > 1 && playerhand[1][2] < 11){
				playerhand[2][2] = playerhand[1][2];
				cout << playerhand[2][2] << " ";
			}
			else if (playerhand[1][2] == 1){
				cout << "A ";
				playerhand[2][2] = 11;
				playernumA += 1;
			}
			else if (playerhand[1][2] == 11){
				cout << "J ";
				playerhand[2][2] = 10;
			}
			else if (playerhand[1][2] == 12){
				cout << "Q ";
				playerhand[2][2] = 10;
			}
			else if (playerhand[1][2] == 13){
				cout << "K ";
				playerhand[2][2] = 10;
			}
			cout << endl;
			numcards = 2;
			playerhand2[0][2] = deck[index];
			index += 1;
			playerhand2[1][2] = (playerhand2[0][2] % 13) + 1;
			cout << "Your second hands is: ";
			if (playerhand2[1][1] > 1 && playerhand2[1][1] < 11){
				cout << playerhand2[1][1] << " ";
			}
			else if (playerhand2[1][1] == 1){
				cout << "A ";
			}
			else if (playerhand2[1][1] == 11){
				cout << "J ";
			}
			else if (playerhand2[1][1] == 12){
				cout << "Q ";
			}
			else if (playerhand2[1][1] == 13){
				cout << "K ";
			}
			if (playerhand2[1][2] > 1 && playerhand2[1][2] < 11){
				playerhand2[2][2] = playerhand2[1][2];
				cout << playerhand2[2][2] << " ";
			}
			else if (playerhand2[1][2] == 1){
				cout << "A ";
				playerhand2[2][2] = 11;
				playernumA2 += 1;
			}
			else if (playerhand2[1][2] == 11){
				cout << "J ";
				playerhand2[2][2] = 10;
			}
			else if (playerhand2[1][2] == 12){
				cout << "Q ";
				playerhand2[2][2] = 10;
			}
			else if (playerhand2[1][2] == 13){
				cout << "K ";
				playerhand2[2][2] = 10;
			}
			cout << endl;
			numcards2 = 2;
			numhands = 2;
			if (playerhand[2][1] == playerhand[2][2]){
				bool splithand1 = false;
				std::string SplitHand1;
				cout << "Do you want to split your first hand? Enter 'Yes' if you do." << endl;
				cin >> SplitHand1;
				if (SplitHand1 == "Yes"){
					splithand1 = true;
				}
				if (splithand1){
					playerhand3[0][0] = playerhand[0][0];
					playerhand3[0][1] = playerhand[0][2];
					playerhand3[1][1] = playerhand[1][2];
					playerhand3[2][1] = playerhand[2][2];
					playerhand[0][2] = deck[index];
					index += 1;
					playerhand[1][2] = (playerhand[0][2] % 13) + 1;
					cout << "Your first hands is now: ";
					if (playerhand[1][1] < 11){
						cout << playerhand[1][1] << " ";
					}
					else if (playerhand[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand[1][1] == 13){
						cout << "K ";
					}
					if (playerhand[1][2] > 1 && playerhand[1][2] < 11){
						playerhand[2][2] = playerhand[1][2];
						cout << playerhand[2][2] << " ";
					}
					else if (playerhand[1][2] == 1){
						cout << "A ";
						playerhand[2][2] = 11;
						playernumA += 1;
					}
					else if (playerhand[1][2] == 11){
						cout << "J ";
						playerhand[2][2] = 10;
					}
					else if (playerhand[1][2] == 12){
						cout << "Q ";
						playerhand[2][2] = 10;
					}
					else if (playerhand[1][2] == 13){
						cout << "K ";
						playerhand[2][2] = 10;
					}
					cout << endl;
					numcards = 2;
					playerhand3[0][2] = deck[index];
					index += 1;
					playerhand3[1][2] = (playerhand3[0][2] % 13) + 1;
					cout << "Your third hands is: ";
					if (playerhand3[1][1] < 11){
						cout << playerhand3[1][1] << " ";
					}
					else if (playerhand3[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand3[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand3[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand3[1][1] == 13){
						cout << "K ";
					}
					if (playerhand3[1][2] > 1 && playerhand3[1][2] < 11){
						playerhand3[2][2] = playerhand3[1][2];
						cout << playerhand3[2][2] << " ";
					}
					else if (playerhand3[1][2] == 1){
						cout << "A ";
						playerhand3[2][2] = 11;
						playernumA3 += 1;
					}
					else if (playerhand3[1][2] == 11){
						cout << "J ";
						playerhand3[2][2] = 10;
					}
					else if (playerhand3[1][2] == 12){
						cout << "Q ";
						playerhand3[2][2] = 10;
					}
					else if (playerhand3[1][2] == 13){
						cout << "K ";
						playerhand3[2][2] = 10;
					}
					cout << endl;
					numcards3 = 2;
					numhands = 3;
				}
			}
			if (playerhand2[2][1] == playerhand2[2][2]){
				bool splithand2 = false;
				std::string SplitHand2;
				cout << "Do you want to split your second hand? Enter 'Yes' if you do." << endl;
				cin >> SplitHand2;
				if (SplitHand2 == "Yes"){
					splithand2 = true;
				}
				if (splithand2 && numhands == 2){
					playerhand3[0][0] = playerhand2[0][0];
					playerhand3[0][1] = playerhand2[0][2];
					playerhand3[1][1] = playerhand2[1][2];
					playerhand3[2][1] = playerhand2[2][2];
					playerhand2[0][2] = deck[index];
					index += 1;
					playerhand2[1][2] = (playerhand2[0][2] % 13) + 1;
					cout << "Your second hands is now: ";
					if (playerhand2[1][1] < 11){
						cout << playerhand2[1][1] << " ";
					}
					else if (playerhand2[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand2[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand2[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand2[1][1] == 13){
						cout << "K ";
					}
					if (playerhand2[1][2] > 1 && playerhand2[1][2] < 11){
						playerhand2[2][2] = playerhand2[1][2];
						cout << playerhand2[2][2] << " ";
					}
					else if (playerhand2[1][2] == 1){
						cout << "A ";
						playerhand2[2][2] = 11;
						playernumA2 += 1;
					}
					else if (playerhand2[1][2] == 11){
						cout << "J ";
						playerhand2[2][2] = 10;
					}
					else if (playerhand2[1][2] == 12){
						cout << "Q ";
						playerhand2[2][2] = 10;
					}
					else if (playerhand2[1][2] == 13){
						cout << "K ";
						playerhand2[2][2] = 10;
					}
					cout << endl;
					numcards2 = 2;
					playerhand3[0][2] = deck[index];
					index += 1;
					playerhand3[1][2] = (playerhand3[0][2] % 13) + 1;
					cout << "Your third hands is: ";
					if (playerhand3[1][1] < 11){
						cout << playerhand3[1][1] << " ";
					}
					else if (playerhand3[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand3[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand3[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand3[1][1] == 13){
						cout << "K ";
					}
					if (playerhand3[1][2] > 1 && playerhand3[1][2] < 11){
						playerhand3[2][2] = playerhand3[1][2];
						cout << playerhand3[2][2] << " ";
					}
					else if (playerhand3[1][2] == 1){
						cout << "A ";
						playerhand3[2][2] = 11;
						playernumA3 += 1;
					}
					else if (playerhand3[1][2] == 11){
						cout << "J ";
						playerhand3[2][2] = 10;
					}
					else if (playerhand3[1][2] == 12){
						cout << "Q ";
						playerhand3[2][2] = 10;
					}
					else if (playerhand3[1][2] == 13){
						cout << "K ";
						playerhand3[2][2] = 10;
					}
					cout << endl;
					numcards3 = 2;
					numhands = 3;
				}
				if (splithand2 && numhands == 3){
					playerhand4[0][0] = playerhand2[0][0];
					playerhand4[0][1] = playerhand2[0][2];
					playerhand4[1][1] = playerhand2[1][2];
					playerhand4[2][1] = playerhand2[2][2];
					playerhand2[0][2] = deck[index];
					index += 1;
					playerhand2[1][2] = (playerhand2[0][2] % 13) + 1;
					cout << "Your second hands is now: ";
					if (playerhand2[1][1] < 11){
						cout << playerhand2[1][1] << " ";
					}
					else if (playerhand2[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand2[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand2[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand2[1][1] == 13){
						cout << "K ";
					}
					if (playerhand2[1][2] > 1 && playerhand2[1][2] < 11){
						playerhand2[2][2] = playerhand2[1][2];
						cout << playerhand2[2][2] << " ";
					}
					else if (playerhand2[1][2] == 1){
						cout << "A ";
						playerhand2[2][2] = 11;
						playernumA2 += 1;
					}
					else if (playerhand2[1][2] == 11){
						cout << "J ";
						playerhand2[2][2] = 10;
					}
					else if (playerhand2[1][2] == 12){
						cout << "Q ";
						playerhand2[2][2] = 10;
					}
					else if (playerhand2[1][2] == 13){
						cout << "K ";
						playerhand2[2][2] = 10;
					}
					cout << endl;
					numcards2 = 2;
					playerhand4[0][2] = deck[index];
					index += 1;
					playerhand4[1][2] = (playerhand4[0][2] % 13) + 1;
					cout << "Your fourth and final hands is: ";
					if (playerhand4[1][1] < 11){
						cout << playerhand4[1][1] << " ";
					}
					else if (playerhand4[1][1] == 1){
						cout << "A ";
					}
					else if (playerhand4[1][1] == 11){
						cout << "J ";
					}
					else if (playerhand4[1][1] == 12){
						cout << "Q ";
					}
					else if (playerhand4[1][1] == 13){
						cout << "K ";
					}
					if (playerhand4[1][2] > 1 && playerhand4[1][2] < 11){
						playerhand4[2][2] = playerhand4[1][2];
						cout << playerhand4[2][2] << " ";
					}
					else if (playerhand4[1][2] == 1){
						cout << "A ";
						playerhand4[2][2] = 11;
						playernumA4 += 1;
					}
					else if (playerhand4[1][2] == 11){
						cout << "J ";
						playerhand4[2][2] = 10;
					}
					else if (playerhand4[1][2] == 12){
						cout << "Q ";
						playerhand4[2][2] = 10;
					}
					else if (playerhand4[1][2] == 13){
						cout << "K ";
						playerhand4[2][2] = 10;
					}
					cout << endl;
					numcards4 = 2;
					numhands = 4;
				}
			}
			numhands = 0;
			if (numcards > 0){
				numhands ++;
			}
			if (numcards2 > 0){
				numhands ++;
			}
			if (numcards3 > 0){
				numhands ++;
			}
			if (numcards4 > 0){
				numhands ++;
			}
			cout << "The number of hands in play is " << numhands << endl;
			if (numhands == 3){
				bool contsplitting = true;
				if (playerhand[2][1] == playerhand[2][2] && contsplitting){
					bool splithand11 = false;
					std::string SplitHand11;
					cout << "Do you want to split your first hand? Enter 'Yes' if you do." << endl;
					cin >> SplitHand11;
					if (SplitHand11 == "Yes"){
						splithand11 = true;
					}
					if (splithand11){
						playerhand4[0][0] = playerhand[0][0];
						playerhand4[0][1] = playerhand[0][2];
						playerhand4[1][1] = playerhand[1][2];
						playerhand4[2][1] = playerhand[2][2];
						playerhand[0][2] = deck[index];
						index += 1;
						playerhand[1][2] = (playerhand[0][2] % 13) + 1;
						cout << "Your first hands is now: ";
						if (playerhand[1][1] < 11){
							cout << playerhand[1][1] << " ";
						}
						else if (playerhand[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand[1][1] == 13){
							cout << "K ";
						}
						if (playerhand[1][2] > 1 && playerhand[1][2] < 11){
							playerhand[2][2] = playerhand[1][2];
							cout << playerhand[2][2] << " ";
						}
						else if (playerhand[1][2] == 1){
							cout << "A ";
							playerhand[2][2] = 11;
							playernumA += 1;
						}
						else if (playerhand[1][2] == 11){
							cout << "J ";
							playerhand[2][2] = 10;
						}
						else if (playerhand[1][2] == 12){
							cout << "Q ";
							playerhand[2][2] = 10;
						}
						else if (playerhand[1][2] == 13){
							cout << "K ";
							playerhand[2][2] = 10;
						}
						cout << endl;
						numcards = 2;
						playerhand4[0][2] = deck[index];
						index += 1;
						playerhand4[1][2] = (playerhand4[0][2] % 13) + 1;
						cout << "Your fourth and final hands is: ";
						if (playerhand4[1][1] < 11){
							cout << playerhand4[1][1] << " ";
						}
						else if (playerhand4[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand4[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand4[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand4[1][1] == 13){
							cout << "K ";
						}
						if (playerhand4[1][2] > 1 && playerhand4[1][2] < 11){
							playerhand4[2][2] = playerhand4[1][2];
							cout << playerhand4[2][2] << " ";
						}
						else if (playerhand4[1][2] == 1){
							cout << "A ";
							playerhand4[2][2] = 11;
							playernumA4 += 1;
						}
						else if (playerhand4[1][2] == 11){
							cout << "J ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 12){
							cout << "Q ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 13){
							cout << "K ";
							playerhand4[2][2] = 10;
						}
						cout << endl;
						numcards4 = 2;
						numhands += 1;
						contsplitting = false;
					}
				}
				if (playerhand2[2][1] == playerhand2[2][2] && contsplitting){
					bool splithand21 = false;
					std::string SplitHand21;
					cout << "Do you want to split your second hand? Enter 'Yes' if you do." << endl;
					cin >> SplitHand21;
					if (SplitHand21 == "Yes"){
						splithand21 = true;
					}
					if (splithand21){
						playerhand4[0][0] = playerhand2[0][0];
						playerhand4[0][1] = playerhand2[0][2];
						playerhand4[1][1] = playerhand2[1][2];
						playerhand4[2][1] = playerhand2[2][2];
						playerhand2[0][2] = deck[index];
						index += 1;
						playerhand2[1][2] = (playerhand2[0][2] % 13) + 1;
						cout << "Your second hands is now: ";
						if (playerhand2[1][1] < 11){
							cout << playerhand2[1][1] << " ";
						}
						else if (playerhand2[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand2[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand2[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand2[1][1] == 13){
							cout << "K ";
						}
						if (playerhand2[1][2] > 1 && playerhand2[1][2] < 11){
							playerhand2[2][2] = playerhand2[1][2];
							cout << playerhand2[2][2] << " ";
						}
						else if (playerhand2[1][2] == 1){
							cout << "A ";
							playerhand2[2][2] = 11;
							playernumA2 += 1;
						}
						else if (playerhand2[1][2] == 11){
							cout << "J ";
							playerhand2[2][2] = 10;
						}
						else if (playerhand2[1][2] == 12){
							cout << "Q ";
							playerhand2[2][2] = 10;
						}
						else if (playerhand2[1][2] == 13){
							cout << "K ";
							playerhand2[2][2] = 10;
						}
						cout << endl;
						numcards2 = 2;
						playerhand4[0][2] = deck[index];
						index += 1;
						playerhand4[1][2] = (playerhand4[0][2] % 13) + 1;
						cout << "Your fourth and final hands is: ";
						if (playerhand4[1][1] < 11){
							cout << playerhand4[1][1] << " ";
						}
						else if (playerhand4[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand4[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand4[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand4[1][1] == 13){
							cout << "K ";
						}
						if (playerhand4[1][2] > 1 && playerhand4[1][2] < 11){
							playerhand4[2][2] = playerhand4[1][2];
							cout << playerhand4[2][2] << " ";
						}
						else if (playerhand4[1][2] == 1){
							cout << "A ";
							playerhand4[2][2] = 11;
							playernumA4 += 1;
						}
						else if (playerhand4[1][2] == 11){
							cout << "J ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 12){
							cout << "Q ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 13){
							cout << "K ";
							playerhand4[2][2] = 10;
						}
						cout << endl;
						numcards4 = 2;
						numhands += 1;
						contsplitting = false;
					}
				}
				if (playerhand3[2][1] == playerhand3[2][2] && contsplitting){
					bool splithand31 = false;
					std::string SplitHand31;
					cout << "Do you want to split your third hand? Enter 'Yes' if you do." << endl;
					cin >> SplitHand31;
					if (SplitHand31 == "Yes"){
						splithand31 = true;
					}
					if (splithand31){
						playerhand4[0][0] = playerhand3[0][0];
						playerhand4[0][1] = playerhand3[0][2];
						playerhand4[1][1] = playerhand3[1][2];
						playerhand4[2][1] = playerhand3[2][2];
						playerhand3[0][2] = deck[index];
						index += 1;
						playerhand3[1][2] = (playerhand3[0][2] % 13) + 1;
						cout << "Your third hands is now: ";
						if (playerhand3[1][1] < 11){
							cout << playerhand3[1][1] << " ";
						}
						else if (playerhand3[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand3[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand3[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand3[1][1] == 13){
							cout << "K ";
						}
						if (playerhand3[1][2] > 1 && playerhand3[1][2] < 11){
							playerhand3[2][2] = playerhand3[1][2];
							cout << playerhand3[2][2] << " ";
						}
						else if (playerhand3[1][2] == 1){
							cout << "A ";
							playerhand3[2][2] = 11;
							playernumA3 += 1;
						}
						else if (playerhand3[1][2] == 11){
							cout << "J ";
							playerhand3[2][2] = 10;
						}
						else if (playerhand3[1][2] == 12){
							cout << "Q ";
							playerhand3[2][2] = 10;
						}
						else if (playerhand3[1][2] == 13){
							cout << "K ";
							playerhand3[2][2] = 10;
						}
						cout << endl;
						numcards3 = 2;
						playerhand4[0][2] = deck[index];
						index += 1;
						playerhand4[1][2] = (playerhand4[0][2] % 13) + 1;
						cout << "Your fourth and final hands is: ";
						if (playerhand4[1][1] < 11){
							cout << playerhand4[1][1] << " ";
						}
						else if (playerhand4[1][1] == 1){
							cout << "A ";
						}
						else if (playerhand4[1][1] == 11){
							cout << "J ";
						}
						else if (playerhand4[1][1] == 12){
							cout << "Q ";
						}
						else if (playerhand4[1][1] == 13){
							cout << "K ";
						}
						if (playerhand4[1][2] > 1 && playerhand4[1][2] < 11){
							playerhand4[2][2] = playerhand4[1][2];
							cout << playerhand4[2][2] << " ";
						}
						else if (playerhand4[1][2] == 1){
							cout << "A ";
							playerhand4[2][2] = 11;
							playernumA4 += 1;
						}
						else if (playerhand4[1][2] == 11){
							cout << "J ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 12){
							cout << "Q ";
							playerhand4[2][2] = 10;
						}
						else if (playerhand4[1][2] == 13){
							cout << "K ";
							playerhand4[2][2] = 10;
						}
						cout << endl;
						numcards4 = 2;
						numhands += 1;
						contsplitting = false;
					}
				}
			}
			if (numhands == 4){
				cout << "Sorry you cannot split any more." << endl;
			}
		}
		playervalue = playerhand[2][1] + playerhand[2][2] + playerhand[2][3];
		playervalue2 = playerhand2[2][1] + playerhand2[2][2];
		playervalue3 = playerhand3[2][1] + playerhand3[2][2];
		playervalue4 = playerhand4[2][1] + playerhand4[2][2];
		if (playervalue > 21 && playernumA > 1){
			int k = playernumA;
			for (int i = 0; i < k; i++){
				playervalue = playervalue - 10;
				playernumA = playernumA - 1;
				if (playervalue <= 21){
					break;
				}
			}
		}
		if (playervalue2 > 21){
			playervalue2 = 12;
			playernumA2 = 1;
		}
		if (playervalue3 > 21){
			playervalue3 = 12;
			playernumA3 = 1;
		}
		if (playervalue4 > 21){
			playervalue4 = 12;
			playernumA4 = 1;
		}
		if (playerhand[0][0] == 0){
			cont = false;
		}
		if (playerhand2[0][0] == 0){
			cont2 = false;
		}
		if (playerhand3[0][0] == 0){
			cont3 = false;
		}
		if (playerhand4[0][0] == 0){
			cont4 = false;
		}
		if (cont){
			if (numhands > 1){
				cout << "We will start with your first hand which is: ";
				for (int i = 1; i <= numcards; i++){
					if (playerhand[1][i] > 1 && playerhand[1][i] < 11){
						cout << playerhand[1][i] << " ";
					}
					else if (playerhand[1][i] == 1){
						cout << "A ";
					}
					else if (playerhand[1][i] == 11){
						cout << "J ";
					}
					else if (playerhand[1][i] == 12){
						cout << "Q ";
					}
					else if (playerhand[1][i] == 13){
						cout << "K ";
					}
				}
				cout << endl;
			}
			playernumA = PlayerMovesAfterFirst(numcards, playerhand, playervalue, playernumA, deck, index);
			for (int i = numcards + 1; i < 12; i++){
				playervalue += playerhand[2][i];
			}
			if (playervalue > 21 && playernumA > 0){
				int k = playernumA;
				for (int i = 0; i < k; i++){
					playervalue = playervalue - 10;
					playernumA = playernumA - 1;
					if (playervalue <= 21){
						break;
					}
				}
			}
			if (playervalue > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand[0][0] << " dollars" << endl;
			}
			else {
				busted = false;
			}
		}
		if (cont2){
			cout << "We will now go to your second hand which is: ";
			for (int i = 1; i <= numcards2; i++){
				if (playerhand2[1][i] > 1 && playerhand2[1][i] < 11){
					cout << playerhand2[1][i] << " ";
				}
				else if (playerhand2[1][i] == 1){
					cout << "A ";
				}
				else if (playerhand2[1][i] == 11){
					cout << "J ";
				}
				else if (playerhand2[1][i] == 12){
					cout << "Q ";
				}
				else if (playerhand2[1][i] == 13){
					cout << "K ";
				}
			}
			cout << endl;
			playernumA2 = PlayerMovesAfterFirst(numcards2, playerhand2, playervalue2, playernumA2, deck, index);
			for (int i = numcards2 + 1; i < 12; i++){
				playervalue2 += playerhand2[2][i];
			}
			if (playervalue2 >= 21 && playernumA2 > 0){
				int k = playernumA2;
				for (int i = 0; i < k; i++){
					playervalue2 = playervalue2 - 10;
					playernumA2 = playernumA2 - 1;
					if (playervalue2 <= 21){
						break;
					}
				}
			}
			if (playervalue2 > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand2[0][0] << " dollars" << endl;
			}
			else {
				busted2 = false;
			}
		}
		if (cont3){
			cout << "We will now go to your third hand which is: ";
			for (int i = 1; i <= numcards3; i++){
				if (playerhand3[1][i] > 1 && playerhand3[1][i] < 11){
					cout << playerhand3[1][i] << " ";
				}
				else if (playerhand3[1][i] == 1){
					cout << "A ";
				}
				else if (playerhand3[1][i] == 11){
					cout << "J ";
				}
				else if (playerhand3[1][i] == 12){
					cout << "Q ";
				}
				else if (playerhand3[1][i] == 13){
					cout << "K ";
				}
			}
			cout << endl;
			playernumA3 = PlayerMovesAfterFirst(numcards3, playerhand3, playervalue3, playernumA3, deck, index);
			for (int i = numcards3 + 1; i < 12; i++){
				playervalue3 += playerhand3[2][i];
			}
			if (playervalue3 >= 21 && playernumA3 > 0){
				int k = playernumA3;
				for (int i = 0; i < k; i++){
					playervalue3 = playervalue3 - 10;
					playernumA3 = playernumA3 - 1;
					if (playervalue3 <= 21){
						break;
					}
				}
			}
			if (playervalue3 > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand3[0][0] << " dollars" << endl;
			}
			else {
				busted3 = false;
			}
		}
		if (cont4){
			cout << "We will now go to your fourth hand which is: ";
			for (int i = 1; i <= numcards4; i++){
				if (playerhand4[1][i] > 1 && playerhand4[1][i] < 11){
					cout << playerhand4[1][i] << " ";
				}
				else if (playerhand4[1][i] == 1){
					cout << "A ";
				}
				else if (playerhand4[1][i] == 11){
					cout << "J ";
				}
				else if (playerhand4[1][i] == 12){
					cout << "Q ";
				}
				else if (playerhand4[1][i] == 13){
					cout << "K ";
				}
			}
			cout << endl;
			playernumA4 = PlayerMovesAfterFirst(numcards4, playerhand4, playervalue4, playernumA4, deck, index);
			for (int i = numcards4 + 1; i < 12; i++){
				playervalue4 += playerhand4[2][i];
			}
			if (playervalue4 >= 21 && playernumA4 > 0){
				int k = playernumA4;
				for (int i = 0; i < k; i++){
					playervalue4 = playervalue4 - 10;
					playernumA4 = playernumA4 - 1;
					if (playervalue4 <= 21){
						break;
					}
				}
			}
			if (playervalue4 > 21){
				cout << "This hand has busted." << endl;
				cout << "You lost " << playerhand4[0][0] << " dollars" << endl;
			}
			else {
				busted4 = false;
			}
		}
		if (!busted || !busted2 || !busted3 || !busted4){
			cout << "The dealer's cards are: ";
			for (int i = 1; i <= 2; i++){
				if (dealerhand[1][i] > 1 && dealerhand[1][i] < 11){
					cout << dealerhand[1][i] << " ";
				}
				else if (dealerhand[1][i] == 1){
					cout << "A ";
				}
				else if (dealerhand[1][i] == 11){
					cout << "J ";
				}
				else if (dealerhand[1][i] == 12){
					cout << "Q ";
				}
				else if (dealerhand[1][i] == 13){
					cout << "K ";
				}
			}
			cout << endl;
			int dealerindex = 3;
			while (dealervalue < 17){
				dealerhand[0][dealerindex] = deck[index];
				index += 1;
				dealerhand[1][dealerindex] = dealerhand[0][dealerindex] % 13 + 1;
				cout << "The card the dealer drew is: ";
				if (dealerhand[1][dealerindex] > 1 && dealerhand[1][dealerindex] < 11){
					cout << dealerhand[1][dealerindex] << endl;
					dealerhand[2][dealerindex] = dealerhand[1][dealerindex];
				}
				else if (dealerhand[1][dealerindex] == 1){
					cout << "A" << endl;
					dealerhand[2][dealerindex] = 11;
					dealernumA += 1;
				}
				else if (dealerhand[1][dealerindex] == 11){
					cout << "J" << endl;
					dealerhand[2][dealerindex] = 10;
				}
				else if (dealerhand[1][dealerindex] == 12){
					cout << "Q" << endl;
					dealerhand[2][dealerindex] = 10;
				}
				else if (dealerhand[1][dealerindex] == 13){
					cout << "K" << endl;
					dealerhand[2][dealerindex] = 10;
				}
				dealervalue += dealerhand[2][dealerindex];
				if (dealervalue > 21 && dealernumA > 0){
					int k = dealernumA;
					for (int i = 0; i < k; i++){
						dealervalue = dealervalue - 10;
						dealernumA = dealernumA - 1;
						if (dealervalue <= 21){
							break;
						}
					}
				}
				dealerindex += 1;
			}
		}
		if (!busted){
			if (numhands == 1){
				if (dealervalue > 21){
					cout << "You win because the dealer bust!" << endl;
					cout << "You won " << playerhand[0][0] << " dollars." << endl;
				}
				else if (playervalue > dealervalue){
					cout << "You win because you beat the dealer!" << endl;
					cout << "You won " << playerhand[0][0] << " dollars." << endl;
				}
				else if (playervalue == dealervalue){
					cout << "You tied to the dealer." << endl;
					cout << "You do not win or lose any money." << endl;
				}
				else if (playervalue < dealervalue){
					cout << "The dealer beat you." << endl;
					cout << "You lost " << playerhand[0][0] << " dollars" << endl;
				}
			}
			else{
				if (dealervalue > 21){
					cout << "You win your first hand because the dealer bust!" << endl;
					cout << "You won " << playerhand[0][0] << " dollars" << endl;
				}
				else if (playervalue > dealervalue){
					cout << "You win your first hand because you beat the dealer!" << endl;
					cout << "You won " << playerhand[0][0] << " dollars" << endl;
				}
				else if (playervalue == dealervalue){
					cout << "You tied your first hand to the dealer." << endl;
					cout << "You do not win or lose any money." << endl;
				}
				else if (playervalue < dealervalue){
					cout << "The dealer beat your first hand." << endl;
					cout << "You lost " << playerhand[0][0] << " dollars" << endl;

				}
			}
		}
		if (!busted2){
			if (dealervalue > 21){
				cout << "You win your second hand because the dealer bust!" << endl;
				cout << "You won " << playerhand2[0][0] << " dollars" << endl;
			}
			else if (playervalue2 > dealervalue){
				cout << "You win your second hand because you beat the dealer!" << endl;
				cout << "You won " << playerhand2[0][0] << " dollars" << endl;
			}
			else if (playervalue2 == dealervalue){
				cout << "You tied your second hand to the dealer." << endl;
				cout << "You do not win or lose any money." << endl;
			}
			else if (playervalue2 < dealervalue){
				cout << "The dealer beat your second hand." << endl;
				cout << "You lost " << playerhand2[0][0] << " dollars" << endl;
			}
		}
		if (!busted3){
			if (dealervalue > 21){
				cout << "You win your third hand because the dealer bust!" << endl;
				cout << "You won " << playerhand3[0][0] << " dollars" << endl;
			}
			else if (playervalue3 > dealervalue){
				cout << "You win your third hand because you beat the dealer!" << endl;
				cout << "You won " << playerhand3[0][0] << " dollars" << endl;
			}
			else if (playervalue3 == dealervalue){
				cout << "You tied your third hand to the dealer." << endl;
				cout << "You do not win or lose any money." << endl;
			}
			else if (playervalue3 < dealervalue){
				cout << "The dealer beat your third hand." << endl;
				cout << "You lost " << playerhand3[0][0] << " dollars" << endl;
			}
		}
		if (!busted4){
			if (dealervalue > 21){
				cout << "You win your fourth hand because the dealer bust!" << endl;
				cout << "You won " << playerhand4[0][0] << " dollars" << endl;
			}
			else if (playervalue4 > dealervalue){
				cout << "You win your fourth hand because you beat the dealer!" << endl;
				cout << "You won " << playerhand4[0][0] << " dollars" << endl;
			}
			else if (playervalue4 == dealervalue){
				cout << "You tied your fourth hand to the dealer." << endl;
				cout << "You do not win or lose any money." << endl;
			}
			else if (playervalue4 < dealervalue){
				cout << "The dealer beat your fourth hand." << endl;
				cout << "You lost " << playerhand4[0][0] << " dollars" << endl;

			}
		}
	}
}