#include "Board.h"

Board::Board()
{
	delimiter = ';';
	std::ifstream fileConfig("config.txt");
	if (fileConfig.is_open())
	{
		std::string str;
		while (std::getline(fileConfig, str, delimiter))
		{
			vecSizes.push_back(str);
		}
		fileConfig.close();
	}

	NUMCOL = std::stoi(vecSizes[0]);
	NUMROWS = std::stoi(vecSizes[1]);
	ROWBLOCK = std::stoi(vecSizes[2]);

	board = new char *[NUMROWS];
	for (int i = 0; i < NUMROWS; i++) 
	{
		board[i] = new char[NUMCOL];
	}	
	playerPos[0] = { NUMROWS - 5, NUMCOL / 2 };
	playerPos[1] = { NUMROWS - 5, (NUMCOL / 2)+1 };
	playerPos[2] = { NUMROWS - 5, (NUMCOL / 2)+2 };
	ball = { NUMROWS - 6, (NUMCOL / 2) + 1 };
	velocity = { 1,1 };
}
void Board::adjustPlayer() 
{
	for (int i = 0; i < 3; i++)
	{
		if ((playerPos[i].y == 0) || (playerPos[i].y == 19))
		{
			if (playerPos[i].y == 0) playerPos[i].y == 18;
			else if (playerPos[i].y == 19) playerPos[i].y == 1;
		}
		else if ((playerPos[i].y>1) && (playerPos[i].y<NUMCOL - 2))
		{
			board[playerPos[i].x][playerPos[i].y - 1] = CharName::PLAYER;
			board[playerPos[i].x][playerPos[i].y - 2] = CharName::PLAYER;
		}
	}
		
}


void Board::moveBall()
{
	board[ball.x][ball.y] = CharName::NONE;
	
	if (ball.y == 1 || ball.y == NUMROWS - 2)
		velocity.y = -(velocity.y);
	if (ball.x == 1 || ball.x == NUMCOL -2)
		velocity.x = -(velocity.x);
	board[ball.x += -velocity.x][ball.y += velocity.y] = CharName::BALL;

}


void Board::InitializeBoard()
{	
	for (int i = 0; i<NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOL; j++)
		{

			if (i == 0)										board[i][j] = CharName::WALLH;
			else if (j == 0)								board[i][j] = CharName::WALLV;
			else if (j == NUMCOL - 1)						board[i][j] = CharName::WALLV;
			else if (i == NUMROWS - 1)						board[i][j] = CharName::WALLH;
			else if (i<ROWBLOCK)							board[i][j] = CharName::BLOCK;
			else if ((i == playerPos[0].x) && (j == playerPos[0].y) || (i == playerPos[1].x) && (j == playerPos[1].y) || (i == playerPos[2].x) && (j == playerPos[2].y))
			{ 
				board[i][j] = CharName::PLAYER;
				
			}
			else if(i == ball.x && j == ball.y) board[i][j] = CharName::BALL;
			else											board[i][j] = CharName::NONE;
		}
	}

	for (int i = 0; i < NUMROWS; i++) {
		for (int j = 0; j < NUMCOL; j++) {
			switch (board[i][j])
			{
			case  CharName::WALLV:
				std::cout << g_CharCode[4];
				break;
			case  CharName::WALLH:
				std::cout << g_CharCode[5];
				break;
			case  CharName::BLOCK:
				std::cout << g_CharCode[1];
				break;
			case  CharName::PLAYER:
				std::cout << g_CharCode[3];
				break;
			case  CharName::NONE:
				std::cout << g_CharCode[0];
				break;
			default:
				break;
			}
			std::cout << g_CharCode[0];
		}
		std::cout << std::endl;
	}	
}
void Board::printBoard()
{
	for (int i = 0; i < NUMROWS; i++) 
	{
		for (int j = 0; j < NUMCOL; j++) 
		{
			
			if ((i == playerPos[0].x) && (j == playerPos[0].y) || (i == playerPos[1].x) && (j == playerPos[1].y) || (i == playerPos[2].x) && (j == playerPos[2].y))
			{
				board[i][j] = CharName::PLAYER;
				
			}

			if(board[i][j] == CharName::WALLV)			std::cout << g_CharCode[4];
			else if (board[i][j] == CharName::WALLH)	std::cout << g_CharCode[5];
			else if (board[i][j] == CharName::BLOCK)	std::cout << g_CharCode[1];
			else if (board[i][j] == CharName::PLAYER)	std::cout << g_CharCode[3];
			else if (board[i][j] == CharName::NONE)		std::cout << g_CharCode[0];
			else if (board[i][j] == CharName::BALL)		std::cout << g_CharCode[2];

			std::cout << g_CharCode[0];
		}
		std::cout << std::endl;
	}
}

void Board::movePlayer(Movement Dir)
{	
	if (Dir == LEFT) 
	{
		board[playerPos[2].x][playerPos[2].y] = CharName::NONE;
		for (int i = 0; i < 3; i++)
		{
			if (playerPos[i].y == 1)
			{
				playerPos[i].y = NUMROWS-2;
			}
			else
			{
				playerPos[i].y -= 1;
			}
		}		
	}

	else if(Dir==RIGHT)
	{
		board[playerPos[0].x][playerPos[0].y] = CharName::NONE;
		for (int i = 0; i < 3; i++)
		{
			if(playerPos[i].y== NUMROWS - 2)
			{
				playerPos[i].y = 1;
			}
			else
			{
				playerPos[i].y += 1;
			}
		}
	}
}



Board::~Board()
{
}
