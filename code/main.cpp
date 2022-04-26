#include <iostream>
#include <cctype>

#include "board.h"

using namespace std;

int main() {

	string player1;
	string player2;

	string position;
	int count = 0;
	
	string again = "y";

	board b;

	system("clear");

	cout << "-------------TIK-TAC-TOE-------------" << endl;
	cout << "|                                   |" << endl;
	cout << "|               1 2 3               |" << endl;
	cout << "|               4 5 6               |" << endl;
	cout << "|               7 8 9               |" << endl;
	cout << "|                                   |" << endl;
	cout << "-------------------------------------" << endl;
	cout << "|                                   |" << endl;
	cout << "|            HOW TO PLAY:           |" << endl;
	cout << "|   When it's your turn, pick the   |" << endl;
	cout << "|    number that corresponds to     |" << endl;
	cout << "|       the space you want.         |" << endl;
	cout << "|                                   |" << endl;
	cout << "-------------------------------------" << endl;

	cout << endl;

	cout << "Do you want to be x or o?" << endl;
	cin >> player1;

	while(player1 != "x" && player1 != "o")
	{
		cout << endl;
		cout << "Selection has to be either x or o" << endl;
		cout << "Try again" << endl;
		cin >> player1;
	}

	if (player1 == "x")
	{
		player1 = "x";
		player2 = "o";
	} else if (player1 == "o"){
		player1 = "o";
		player2 = "x";
	}

	//cout << "-------------------------------------" << endl;
	//cout << endl;
	
	while(again=='y')
	{
		system("clear");
		       
		while(!b.winner())
		{
			count++;

			bool error = true;

			cout << "-------------TIK-TAC-TOE-------------" << endl;
			cout << "|                                   |" << endl;
			cout << "|               1 2 3               |" << endl;
			cout << "|               4 5 6               |" << endl;
			cout << "|               7 8 9               |" << endl;
			cout << "|                                   |" << endl;
			cout << "-------------------------------------" << endl;
			cout << "|                                   |" << endl;
			cout << "|            HOW TO PLAY:           |" << endl;
			cout << "|   When it's your turn, pick the   |" << endl;
			cout << "|    number that corresponds to     |" << endl;
			cout << "|       the space you want.         |" << endl;
			cout << "|                                   |" << endl;
			cout << "-------------------------------------" << endl;

			cout << endl;

			cout << b.print() << endl;

			if (count%2 == 0)
			{
				cout << "Player 2's turn" << endl;
				cout << "You are: " << player2 << endl;
			} else {
				cout << "Player 1's turn" << endl;
				cout << "You are: " << player1 << endl;
			}

			cout << "Enter your answer" << endl;
			cin >> position;

			while(error == true)
			{
				cout << endl;

				if ((position.length() == 1) && (isdigit(position[0])) &&
						(stoi(position) > 0) && (stoi(position) < 10))
				{
					if (b.occupied(stoi(position)))
					{
						cout << endl;
						cout << "That space is already occupied" << endl;
						cout << "Try Again" << endl;
						cin >> position;

						error = true;
					} else {
						error = false;
					}
				} else if (stoi(position) < 1 || stoi(position) > 10) {
					error = true;

					cout << "Error: Position has to be a number from 1 to 9" << endl;
					cout << "Try Again" << endl;
					cin >> position;

				} else {
					error = true;

					cout << "Error: Try Again" << endl;
					cin >> position;
				}
			}

			if (count%2 == 0)
			{
				b.answer(stoi(position), player2);
			} else {
				b.answer(stoi(position), player1);
			}

			system("clear");
		}

		system("clear");

		cout << b.print() << endl;

		if(b.winningPlayer == player1)
		{
			cout << "-------------------------------------" << endl;
			cout << "|           PLAYER 1 WINS           |" << endl;
			cout << "-------------------------------------" << endl;
		} else if (b.winningPlayer == player2){
			cout << "-------------------------------------" << endl;
			cout << "|           PLAYER 2 WINS           |" << endl;
			cout << "-------------------------------------" << endl;
		} else {
			cout << "-------------------------------------" << endl;
			cout << "|            IT'S A TIE             |" << endl;
			cout << "-------------------------------------" << endl;
		}
		
		cout << endl;
		
		cout << "Do you want to play again? (y/n)" << endl;
		cin >> again;
	}

}
