/*#include "Board.h"


int main(int, char *[])
{
	srand(time(NULL));
	std::string str;
	Player player;
	Board board(player.position);

	char c = ' ';

	std::ifstream my_file("example.txt");

	if(my_file.is_open())
	{
	}

	while (c != 'x' && !board.gameOver())
	{
		system("cls");
		player.printScore();
		board.printBoard();
		std::cin >> c;

		Movement move;
		switch (c)
		{
		case 'w': 
			move = Movement::UP;
			c = ' ';
			break;
		case 'W':
			move = Movement::UP;
			c = ' ';
			break;

		case 's': 
			move = Movement::DOWN;
			c = ' ';
			break;
		case 'S':
			move = Movement::DOWN;
			c = ' ';
			break;

		case 'a':
			move = Movement::LEFT;
			c = ' ';
			break;
		case 'A':
			move = Movement::LEFT;
			c = ' ';
			break;

		case 'd': 
			move = Movement::RIGHT;
			c = ' ';
			break;
		case 'D':
			move = Movement::RIGHT;
			c = ' ';
			break;
		default:
			break;
		};

		if (board.checkMovement(player.position, move))
		{
			if (board.existCoin(player.position, move)) { player.updateScore(1); };
			board.movePlayer(player.position, move);
		};
	}
	return 0;
}*/