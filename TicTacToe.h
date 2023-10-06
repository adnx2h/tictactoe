class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();
	void drawBoard(char token[3][3]);
	void playerMoves(int player);
	void checkMove(int player);
	char board[3][3];
	bool isTaken[9] = { false, false, false, false, false, false, false, false, false };

private:

};
