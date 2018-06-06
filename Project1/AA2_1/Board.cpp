#include "Board.h"

Board::Board()
{
	srand(time(NULL));
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

	NUMROWS = std::stoi(vecSizes[0]);
	NUMCOL = std::stoi(vecSizes[1]);
	ROWBLOCK = std::stoi(vecSizes[2]);
	minmax.x = std::stoi(vecSizes[3]);
	minmax.y = std::stoi(vecSizes[4]);

	for (int i = 0; i < ROWBLOCK*(NUMCOL - 2); i++)
	{
		Qpoints.push(rand() % (minmax.y - minmax.x + 1) + minmax.x);
	}

	if (ROWBLOCK >= (NUMROWS / 2))
	{
		std::cout << "Error, demasiadas columnas de bloques" << std::endl;
		platform.GameOver = true;
	}

	board = new char *[NUMROWS];
	for (int i = 0; i < NUMROWS; i++)
	{
		board[i] = new char[NUMCOL];
	}

	platform.positions[0] = { NUMROWS / 2, NUMROWS / 2 };
	platform.positions[1] = { NUMROWS / 2, (NUMROWS / 2) + 1 };
	platform.positions[2] = { NUMROWS / 2, (NUMROWS / 2) + 2 };
	ball = { ROWBLOCK+1,  NUMROWS / 2 };
	velocity = { 1,1 };
}

void Board::adjustPlayer()
{
	for (int i = 0; i < 3; i++)
	{
		if ((platform.positions[i].y < 1))
		{
			platform.positions[i].y = NUMCOL - 2;
		}
		else if (platform.positions[i].y > NUMCOL - 2)
		{
			platform.positions[i].y = 1;
		}
	}
}

void Board::moveBall()
{
	std::cout << "\n********************" << ball.y << "********************\n";

	board[ball.x][ball.y] = CharName::NONE;

	if (board[ball.x + velocity.x][ball.y] == CharName::BLOCK)
	{
		board[ball.x + velocity.x][ball.y] = CharName::NONE;
		velocity.x = -(velocity.x);
		addPoints();
	}
	if (board[ball.x][ball.y + velocity.y] == CharName::BLOCK)
	{
		board[ball.x][ball.y + velocity.y] = CharName::NONE;
		velocity.y = -(velocity.y);
		addPoints();
	}
	else if (board[ball.x + velocity.x][ball.y + velocity.y] == CharName::BLOCK)
	{
		board[ball.x + velocity.x][ball.y + velocity.y] = CharName::NONE;
		velocity.y = -(velocity.y);
		velocity.x = -(velocity.x);
		addPoints();
	}

	if (board[ball.x + velocity.x][ball.y] == CharName::PLAYER)
	{
		velocity.x = -(velocity.x);
	}
	else if (board[ball.x + velocity.x][ball.y + velocity.y] == CharName::PLAYER)
	{
		velocity.y = -(velocity.y);
	}
	
	if (ball.x <= 1)			velocity.x = -(velocity.x);
	if (ball.y>=(NUMCOL-2))		velocity.y = -(velocity.y);	
	if (ball.y<=1)				velocity.x = -(velocity.x);
	if (ball.x >= NUMROWS - 2)
	{
		ball.x = ROWBLOCK;
		ball.y = NUMCOL/2;
		
		velocity.x = 1;
		
		velocity.y = rand() % 100;
		if (velocity.y > 50) velocity.y = -1;
		else				 velocity.y = 1;

		platform.lives--;
		if(platform.lives==0)
		{
			platform.GameOver == true;
		}
	}

	ball.x += velocity.x;
	ball.y += velocity.y;

	board[ball.x][ball.y] = CharName::BALL;
}
void Board::InitializeBoard()
{
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOL; j++)
		{

			if (i == 0)										board[i][j] = CharName::WALLH;
			else if (j == 0)								board[i][j] = CharName::WALLV;
			else if (j == NUMCOL - 1)						board[i][j] = CharName::WALLV;
			else if (i == NUMROWS - 1)						board[i][j] = CharName::WALLH;
			else if (i < ROWBLOCK + 1)							board[i][j] = CharName::BLOCK;
			else if ((i == platform.positions[0].x) && (j == platform.positions[0].y) || (i == platform.positions[1].x) && (j == platform.positions[1].y) || (i == platform.positions[2].x) && (j == platform.positions[2].y))
			{
				board[i][j] = CharName::PLAYER;

			}
			else if (i == ball.x && j == ball.y) board[i][j] = CharName::BALL;
			else											board[i][j] = CharName::NONE;
		}
	}
}
void Board::printBoard()
{
	for (int i = 0; i < NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOL; j++)
		{

			if ((i == platform.positions[0].x) && (j == platform.positions[0].y) || (i == platform.positions[1].x) && (j == platform.positions[1].y) || (i == platform.positions[2].x) && (j == platform.positions[2].y))
			{
				board[i][j] = CharName::PLAYER;

			}

			if (board[i][j] == CharName::NONE)		std::cout << g_CharCode[0];
			else if (board[i][j] == CharName::PLAYER)	std::cout << g_CharCode[1];
			else if (board[i][j] == CharName::BLOCK)	std::cout << g_CharCode[2];
			else if (board[i][j] == CharName::BALL)		std::cout << g_CharCode[3];
			else if (board[i][j] == CharName::WALLV)			std::cout << g_CharCode[4];
			else if (board[i][j] == CharName::WALLH)	std::cout << g_CharCode[5];
		}
		std::cout << std::endl;
	}
}
void Board::movePlayer(Movement Dir)
{
	if (Dir == LEFT)
	{
		board[platform.positions[2].x][platform.positions[2].y] = CharName::NONE;
		for (int i = 0; i < 3; i++)
		{
			platform.positions[i].y -= 1;
		}
		adjustPlayer();
	}
	else if (Dir == RIGHT)
	{
		board[platform.positions[0].x][platform.positions[0].y] = CharName::NONE;
		for (int i = 0; i < 3; i++)
		{
			platform.positions[i].y += 1;
		}
		adjustPlayer();
	}
}
void Board::addPoints()
{
	platform.score += Qpoints.front();
	Qpoints.pop();
	if (Qpoints.empty())
	{
		platform.GameOver = true;
	}
}
Board::~Board()
{
}
