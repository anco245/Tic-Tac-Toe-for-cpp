#include <iostream>
#include <string>
#include "board.h"

using namespace std;

board::board() {

}

// Determines if there's a tie by seeing if every cell is filled
bool board::isATie(){
	bool tie = true;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if (grid[x][y] == "-")
			{
				tie = false;
			}
		}
	}

	return tie;
}

// Determines if the given cell already has an answer in it
bool board::occupied(int pos)
{
	switch(pos)
	{
		case 1:
			if(grid[0][0] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 2:
			if(grid[0][1] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 3:
			if(grid[0][2] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 4:
			if(grid[1][0] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 5:
			if(grid[1][1] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 6:
			if(grid[1][2] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 7:
			if(grid[2][0] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 8:
			if(grid[2][1] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;

		case 9:
			if(grid[2][2] != "-")
			{
				return true;
			} else {
				return false;
			}
			break;
	}
}

// Determines if there's a winner along the 3 rows
bool board::horizontal(string given)
{
	int inarow = 0;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(grid[x][y] == given)
			{
				inarow++;

				if(inarow == 3)
				{
					return true;
				}
			}
		}

		inarow = 0;
	}

	return false;
}

// Determines if there's a winner along the 3 columns
bool board::vertical(string given)
{
	int inarow = 0;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if(grid[y][x] == given)
			{
				inarow++;

				if(inarow == 3)
				{
					return true;
				}
			}
		}

		inarow = 0;
	}

	return false;
}

// Determines if there's a winner on a diagnal
bool board::diagonal(string given)
{
	if(grid[0][0] == given && grid[1][1] == given && grid[2][2] == given)
	{
		return true;
	} else if (grid[0][2] == given && grid[1][1] == given && grid[2][0] == given) {
		return true;
	} else {
		return false;
	}
}

// Dermines if there's a winner in the horizontal, vertical, or diagonal for each player
bool board::winner(int n) {
	
	if(n>=3)
	{
		if(horizontal("x"))
		{
			winningPlayer = "x";
			return true;

		} else if (horizontal("o")) {
			winningPlayer = "o";
			return true;

		} else if (vertical("x")) {
			winningPlayer = "x";
			return true;

		} else if (vertical("o")) {
			winningPlayer = "o";
			return true;

		} else if (diagonal("x")) {
			winningPlayer = "x";
			return true;

		} else if (diagonal("o")) {
			winningPlayer = "o";
			return true;

		} else if (n==9){
			if(isATie())
			{
				return true;
			} else {
				return false;
			}

		} else {
			return false;
		}	
	} else {
		
		return false;
	}
}

// Inserts either an x or an o into the given cell, depending on who's turn it is
void board::answer(int pos, string player)
{

	switch(pos)
	{
		case 1:
			grid[0][0] = player;
			break;

		case 2:
			grid[0][1] = player;
			break;

		case 3:
			grid[0][2] = player;
			break;

		case 4:
			grid[1][0] = player;
			break;

		case 5:
			grid[1][1] = player;
			break;

		case 6:
			grid[1][2] = player;
			break;

		case 7:
			grid[2][0] = player;
			break;

		case 8:
			grid[2][1] = player;
			break;

		case 9:
			grid[2][2] = player;
			break;
	}

}

// Prints the board
string board::print() {
	string str = "";

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			if ((x == 0 && y == 2) || (x == 1 && y == 2) || (x == 2 && y == 2))
			{
				str = str + grid[x][y] + "\n";
			} else {
				str = str + grid[x][y] + " ";
			}
		}
	}

	return str;
}
