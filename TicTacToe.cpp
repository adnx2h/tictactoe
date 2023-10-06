#include<iostream>
#include"TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe()
{
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
}

void TicTacToe::drawBoard(char token[3][3])
{
	system("cls");
	cout << "TicTacToe Game" << endl;
	cout << "     |    |    " << endl;
	cout << "  " << token[0][0] << "  |  " << token[0][1] << " |  " << token[0][2] << "  " << endl;
	cout << "     |    |    " << endl;
	cout << "---------------" << endl;
	cout << "     |    |    " << endl;
	cout << "  " << token[1][0] << "  |  " << token[1][1] << " |  " << token[1][2] << "  " << endl;
	cout << "     |    |    " << endl;
	cout << "---------------" << endl;
	cout << "     |    |    " << endl;
	cout << "  " << token[2][0] << "  |  " << token[2][1] << " |  " << token[2][2] << "  " << endl;
	cout << "     |    |    " << endl;
}
void TicTacToe::playerMoves(int player)
{
	char tokenChar;
	bool isValidNumber = true;
	int location;
	if (player == 1)
		tokenChar = 'X';
	else
		tokenChar = '0';

	do {
		cin >> location;

		if (isTaken[location - 1] == true)
		{
			cout << "Invalid selection" << endl;
			isValidNumber = false;
			continue;
		}

		switch (location)
		{
		case 1:
			isTaken[0] = true;
			board[0][0] = tokenChar;
			isValidNumber = true;
			break;
		case 2:
			isTaken[1] = true;
			board[0][1] = tokenChar;
			isValidNumber = true;
			break;
		case 3:
			isTaken[2] = true;
			board[0][2] = tokenChar;
			isValidNumber = true;
			break;
		case 4:
			isTaken[3] = true;
			board[1][0] = tokenChar;
			isValidNumber = true;
			break;
		case 5:
			isTaken[4] = true;
			board[1][1] = tokenChar;
			isValidNumber = true;
			break;
		case 6:
			isTaken[5] = true;
			board[1][2] = tokenChar;
			isValidNumber = true;
			break;
		case 7:
			isTaken[6] = true;
			board[2][0] = tokenChar;
			isValidNumber = true;
			break;
		case 8:
			isTaken[7] = true;
			board[2][1] = tokenChar;
			isValidNumber = true;
			break;
		case 9:
			isTaken[8] = true;
			board[2][2] = tokenChar;
			isValidNumber = true;
			break;
		default:
			cout << "Invalid number" << endl;
			isValidNumber = false;
			break;
		}
	} while (isValidNumber == false);
}
void TicTacToe::checkMove(int player)
{
	bool isWinner = false;
	int static numberofMoves = 0;
	numberofMoves++;

	//Check Horizontal
	if ((board[0][0] == board[0][1] && board[0][0] == board[0][2]) || 
		(board[1][0] == board[1][1] && board[1][0] == board[1][2]) || 
		(board[2][0] == board[2][1] && board[2][0] == board[2][2]))
		isWinner = true;
	//Check Vertical
	else if ((board[0][0] == board[1][0] && board[0][0] == board[2][0]) || 
		     (board[0][1] == board[1][1] && board[0][1] == board[2][1]) || 
		      (board[0][2] == board[1][2] && board[0][2] == board[2][2]))
		isWinner = true;
	//Check Diagonals
	else if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || 
		(board[0][2] == board[1][1] && board[0][2] == board[2][0]))
		isWinner = true;
	if (isWinner) {
		cout << "Player " << player << " is the winner!" << endl;
		exit(0);
	}
	if (numberofMoves == 9)
	{
		cout << "It's a draw!" << endl;
		exit(0);
	}
}
TicTacToe::~TicTacToe()
{
}