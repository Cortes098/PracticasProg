#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <vector>

enum class Movement { LEFT, RIGHT };

struct Vec2
{
	int x;
	int y;
};
struct Board
{

	enum CharName { NONE, PLAYER, BLOCK, BALL, WALLV, WALLH };
	char g_CharCode[6] = { ' ', '@', '*','-','|', '_' };
	char **board;
	int countscore;
	int maxscore;
	int NUMROWS, NUMCOL, ROWBLOCK;
	Vec2 playerPos{ NUMROWS - 5, NUMCOL / 2 };
	std::vector <std::string> vecSizes;
	char delimiter=';';

	void InitializeBoard()
	{
		std::ifstream fileConfig("config.txt");
		if (fileConfig.is_open()) 
		{
			std::string str;
			while(std::getline(fileConfig,str, delimiter))
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

		Vec2 playerPos{ NUMROWS - 5, NUMCOL / 2 };

		//**************BOARD**************//

		for (int i = 0; i<NUMROWS; i++)
		{
			for (int j = 0; j < NUMCOL; j++)
			{

				if (i == 0)										board[i][j] = CharName::WALLH;
				else if (j == 0)								board[i][j] = CharName::WALLV;
				else if (j == NUMCOL - 1)						board[i][j] = CharName::WALLV;
				else if (i == NUMROWS - 1)						board[i][j] = CharName::WALLH;
				else if (i<ROWBLOCK)							board[i][j] = CharName::BLOCK;
				
				else											board[i][j] = CharName::NONE;

			}
		}

		

		board[playerPos.x][playerPos.y] = CharName::PLAYER;
		if(playerPos.x== 1)
			board[NUMCOL-1][playerPos.y]= CharName::PLAYER;
		else if(playerPos.x == 1)

		std::cout << NUMROWS - 5 << " " << NUMCOL - 6 << "\n";
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
	
	void movePlayer(Vec2 pos) 
	{
		board[pos.x][pos.y] = g_CharCode[CharName::PLAYER];
	}

	void printBoard(char **myb)
	{
		for (int i = 0; i < NUMROWS; i++) {
			for (int j = 0; j < NUMCOL; j++) {
				switch (myb[i][j])
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

	/*bool checkMovement(Vec2 pos, Movement mov)
	{
		switch (mov)
		{
		case Movement::LEFT:
			return !(pos.y - 1 < 0 || board[pos.x][pos.y - 1] == g_CharCode[CharName::WALLV]);
			break;
		case Movement::RIGHT:
			return !(pos.y + 1 > NUMCOL - 1 || board[pos.x][pos.y + 1] == g_CharCode[CharName::WALLH]);
			break;
		default:
			break;
		};
	}*/	
	Vec2 movePlayer(Vec2 const &pos_, Movement move)
		{
			Vec2 newPos = pos_;

			//calcular cual seria la nueva posicion
			switch (move)
			{
			case Movement::LEFT: newPos = { pos_.x, pos_.y - 1 };
								 break;
			case Movement::RIGHT: newPos = { pos_.x, pos_.y + 1 };
								  break;
			
			}

			board[pos_.x][pos_.y] = g_CharCode[CharName::NONE];
			board[newPos.x][newPos.y] = g_CharCode[CharName::PLAYER];
			return newPos;

		}
};

