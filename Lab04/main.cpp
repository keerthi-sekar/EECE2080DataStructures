#include "Recursion.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ChessBoard chessBoard;
	int board[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
	bool status = chessBoard.Solve(chessBoard,0);
	if(status)
	{
		string output = chessBoard.ToString();
		cout << output << endl;
	}
	else
	{
		cout << "No solution found"  << endl;
	}
	

	return 0;
}