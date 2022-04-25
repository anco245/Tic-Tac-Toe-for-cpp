#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string>

using namespace std;

class board {
public:
	board();
	string print();
	bool isATie();
	bool winner();
	bool occupied(int pos);
	void answer(int pos, string player);
	string winningPlayer;

private:
	bool horizontal(string s);
	bool vertical(string s);
	bool diagonal(string s);
	string grid [3][3] = {{"-", "-", "-"},
				 	 	  {"-", "-", "-"},
						  {"-", "-", "-"}};
};

#endif /* BOARD_H_ */