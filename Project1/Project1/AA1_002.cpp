/*#include <iostream>
#include <string>
#include <time.h>

enum class Movement {UP, DOWN, LEFT, RIGHT,MAX};

struct Player
{
	int cooX;
	int cooY;
	int score;

	void UpdateScore() 
	{
		score++;
	}
	void movePlayer(Movement my_movement)
	{
		switch (my_movement)
		{
		case Movement::UP:
			cooY--;
			break;
		case Movement::DOWN:
			cooY++;
			break;
		case Movement::LEFT:
			cooX--;
			break;
		case Movement::RIGHT:
				cooX++;
			break;
		}
	}
	void setPos(char board[10][10]) 
	{
		board[cooX][cooY];
	}
	void initializeBoard(char board[10][10])
	{
		int const MAX_COINS = (10 * 10)*0.3;
		int const MAX_ROCK = (10 * 10)*0.2;

		int Num_Coins = rand() % MAX_COINS;
		int Num_Rocks = rand() % MAX_ROCK;

		int auxRandom = 0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				auxRandom = rand() % 10;

				if (auxRandom <= 2)
				{
					board[i][j] = '#';
				}
				else if (auxRandom >= 2 && auxRandom <= 5)
				{
					board[i][j] = '$';
				}
				else
				{
					board[i][j] = '.';
				}
			}
		}

		board[cooX = rand() % 10][cooY = rand() % 10] = '@';
	}
};

bool checkMovement(Movement my_movement, Player my_player, char board[10][10])
{
	switch (my_movement)
	{
	case Movement::UP:
		if((board[my_player.cooX][my_player.cooY - 1] != '#') && (my_player.cooY - 1>0) )
		{
			return true;
		}
		else return false;
		break;
	case Movement::DOWN:
		if ((board[my_player.cooX][my_player.cooY + 1] != '#') && (my_player.cooY - 1<10) )
		{
			return true;
		}
		else return false;
		break;
	case Movement::LEFT:
		if ((board[my_player.cooX-1][my_player.cooY] != '#') && (my_player.cooX - 1>0) )
		{
			return true;
		}
		else return false;
		break;
	case Movement::RIGHT:
		if ((board[my_player.cooX+1][my_player.cooY] != '#') && (my_player.cooX - 1<10))
		{
			return true;
		}
		else return false;
		break;
	default:
		break;
	}
}

bool existCoin(Movement my_movement, Player my_player, char board[10][10])
{
	switch (my_movement)
	{
	case Movement::UP:
		if ((board[my_player.cooX][my_player.cooY - 1] != '$'))
		{
			return true;
		}
		else return false;
		break;
	case Movement::DOWN:
		if ((board[my_player.cooX][my_player.cooY + 1] != '$'))
		{
			return true;
		}
		else return false;
		break;
	case Movement::LEFT:
		if ((board[my_player.cooX - 1][my_player.cooY] != '$'))
		{
			return true;
		}
		else return false;
		break;
	case Movement::RIGHT:
		if ((board[my_player.cooX + 1][my_player.cooY] != '$'))
		{
			return true;
		}
		else return false;
		break;

	default:
		break;
	}
}

bool gameOver(char board[10][10]) {

	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			if (board[i][j] == '$') return false;
		}
	}
	return true;
}

void printBoard(char board[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

void main()
{
	const int NUM_ROWS=10;
	const int NUM_COLUMN = 10;

	char BOARD[NUM_ROWS][NUM_COLUMN];
	Player my_player;	

	my_player.initializeBoard(BOARD);
	printBoard(BOARD);
}*/