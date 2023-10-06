#include<iostream>
#include"TicTacToe.h"
using namespace std;

int main()
{
	TicTacToe game;
	bool isDraw = false;
	bool isWinner = false;

	cout << "TicTacToe Game" << endl;
	game.drawBoard(game.board);
	do
	{
		cout << "Player 1, select a number: ";
		game.playerMoves(1);
		game.drawBoard(game.board);
		game. checkMove(1);
		cout << "Player 2, select a number: ";
		game.playerMoves(2);
		game.drawBoard(game.board);
		game.checkMove(2);
	} while ((isDraw == false) || (isWinner = false));
	return 0;
}