#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>

const int NUM_ROWS{ 10 };
const int NUM_COLUMNS{ 10 };

enum class Movement { LEFT, RIGHT };

struct Vec2
{
	int x;
	int y;
};
struct Board
{

	enum CharName { NONE, PLAYER, BLOCK, BALL, WALL };
	char g_CharCode[5] = { ' ', '@', '*','-','|' };
	char board[NUM_ROWS][NUM_COLUMNS];
	int countscore;
	int maxscore;

	void InitializeBoard()
	{
				
	}



	void setPlayer(Vec2 pos) 
	{
		board[pos.x][pos.y] = g_CharCode[CharName::PLAYER];
	}
	bool checkMovement(Vec2 pos, Movement mov)
	{
		switch (mov)
		{
		case Movement::LEFT:
			return !(pos.y - 1 < 0 || board[pos.x][pos.y - 1] == g_CharCode[CharName::WALL]);
			break;
		case Movement::RIGHT:
			return !(pos.y + 1 > NUM_COLUMNS - 1 || board[pos.x][pos.y + 1] == g_CharCode[CharName::WALL]);
			break;
		default:
			break;
		};
	}
	void printBoard() 
		{
			for (int i = 0; i < NUM_ROWS; i++) {
				for (int j = 0; j < NUM_COLUMNS; j++) {
					std::cout << "[" << board[i][j] << "] ";
				}
				std::cout << std::endl;
			}
		}
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
			case Movement::UP: newPos = { pos_.x - 1, pos_.y };
							   break;
			case Movement::DOWN: newPos = { pos_.x + 1, pos_.y };
								 break;
			}

			board[pos_.x][pos_.y] = g_CharCode[CharName::NONE];
			board[newPos.x][newPos.y] = g_CharCode[CharName::PLAYER];
			return newPos;

		}
};

