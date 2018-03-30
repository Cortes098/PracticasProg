#include "Boar.h"

Boar::Boar()
{
	delimiter = ';';
	playerPos = { NUMROWS - 5, NUMCOL / 2 };
}

void Boar::InitializeBoard()
{
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

	char **board = new char*[NUMROWS];
	for (int i = 0; i < NUMROWS; ++i)
		board[i] = new char[NUMCOL];
	
	for (int i = 0; i<NUMROWS; i++)
	{
		for (int j = 0; j < NUMCOL; j++)
		{

			if (i == 0)					board[i][j] = CharName::WALLH;
			else if (j == 0)			board[i][j] = CharName::WALLV;
			else if (j == NUMCOL - 1)	board[i][j] = CharName::WALLV;
			else if (i == NUMROWS - 1)	board[i][j] = CharName::WALLH;
			else if (i<ROWBLOCK)		board[i][j] = CharName::BLOCK;
			else						board[i][j] = CharName::NONE;
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

void Boar::printBoard()
{
	for (int i = 0; i < NUMROWS; i++) {
		for (int j = 0; j < NUMCOL; j++) {
			
			if(board[i][j] == CharName::WALLV)			std::cout << g_CharCode[4];
			else if (board[i][j] == CharName::WALLH)	std::cout << g_CharCode[5];
			else if (board[i][j] == CharName::BLOCK)	std::cout << g_CharCode[1];
			else if (board[i][j] == CharName::PLAYER)	std::cout << g_CharCode[3];
			else if (board[i][j] == CharName::NONE)		std::cout << g_CharCode[0];

			std::cout << g_CharCode[0];
		}
		std::cout << std::endl;
	}
}



Boar::~Boar()
{
}
