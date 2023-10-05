#include<iostream>
using namespace std;
char board[3][3];

void drawBoard(char token[3][3])
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
void playerMoves(int player)
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
		switch (location)
		{
		case 1:
			board[0][0] = tokenChar;
			isValidNumber = true;
			break;
		case 2:
			board[0][1] = tokenChar;
			isValidNumber = true;
			break;
		case 3:
			board[0][2] = tokenChar;
			isValidNumber = true;
			break;
		case 4:
			board[1][0] = tokenChar;
			isValidNumber = true;
			break;
		case 5:
			board[1][1] = tokenChar;
			isValidNumber = true;
			break;
		case 6:
			board[1][2] = tokenChar;
			isValidNumber = true;
			break;
		case 7:
			board[2][0] = tokenChar;
			isValidNumber = true;
			break;
		case 8:
			board[2][1] = tokenChar;
			isValidNumber = true;
			break;
		case 9:
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

void checkMove(int player)
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

void main()
{
	cout << "TicTacToe Game" << endl;
	int input;
	bool isDraw = false;
	bool isWinner = false;

	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';

	drawBoard(board);
	do
	{
		cout << "Player 1, select a number: ";
		playerMoves(1);
		drawBoard(board);
		checkMove(1);
		cout << "Player 2, select a number: ";
		playerMoves(2);
		drawBoard(board);
		checkMove(2);
	} while ((isDraw == false) || (isWinner = false));
}
