#pragma once

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Player.h"

enum CharName { NONE, PLAYER, STONE, COIN };
enum class Movement { UP, DOWN, LEFT, RIGHT };
char g_CharCode[4] = { ' ', '@', 'X','$' };

struct Board
{
	Vec2 playerOnBoard;

	char board[NUM_ROWS][NUM_COLUMNS];

	Board(Vec2 position) 
	{
		InitializeBoard();
		setPlayer(position);
	}

	void InitializeBoard()
	{
		int countStones = 0, countCoins = 0;
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				switch (GetRandomCell())
				{
				case NONE:
					board[i][j] = g_CharCode[CharName::NONE];
					break;
				case STONE:
					board[i][j] = (countStones < (NUM_ROWS*NUM_COLUMNS)*0.2) ? g_CharCode[CharName::STONE] : g_CharCode[CharName::NONE];
					countStones++;
					break;
				case COIN:
					board[i][j] = (countCoins < (NUM_ROWS*NUM_COLUMNS)*0.3) ? g_CharCode[CharName::COIN] : g_CharCode[CharName::NONE];
					countCoins++;
					break;
				default:
					board[i][j] = g_CharCode[CharName::NONE];
					break;
				}
			}
		}
	}

	CharName GetRandomCell()
	{
		int rnd = rand() % 100;
		if (rnd < 20) return CharName::STONE;
		else if (rnd < 50)
		{
			BoardCoins++;
			return CharName::COIN;
		}
		return CharName::NONE;
	}

	void setPlayer(Vec2 pos) {
		board[pos.x][pos.y] = g_CharCode[CharName::PLAYER];
	}

	bool checkMovement(Vec2 pos, Movement mov)
	{
		switch (mov)
		{
		case Movement::LEFT:
			return !(pos.y - 1 < 0 || board[pos.x][pos.y - 1] == g_CharCode[CharName::STONE]);
		case Movement::RIGHT:
			return !(pos.y + 1 > NUM_COLUMNS - 1 || board[pos.x][pos.y + 1] == g_CharCode[CharName::STONE]);
		case Movement::UP:
			return !(pos.x - 1 < 0 || board[pos.x - 1][pos.y] == g_CharCode[CharName::STONE]);
		case Movement::DOWN:
			return !(pos.x + 1 > NUM_ROWS - 1 || board[pos.x + 1][pos.y] == g_CharCode[CharName::STONE]);
		}
	}

	void printBoard() {
		for (int i = 0; i < NUM_ROWS; i++) {
			for (int j = 0; j < NUM_COLUMNS; j++) {
				std::cout << "[" << board[i][j] << "] ";
			}
			std::cout << std::endl;
		}
	}

	bool existCoin(Vec2 pos, Movement mov) {
		switch (mov)
		{
		case Movement::LEFT:
			return (board[pos.x][pos.y - 1] == g_CharCode[CharName::COIN]);
		case Movement::RIGHT:
			return (board[pos.x][pos.y + 1] == g_CharCode[CharName::COIN]);
		case Movement::UP:
			return (board[pos.x - 1][pos.y] == g_CharCode[CharName::COIN]);
		case Movement::DOWN:
			return (board[pos.x + 1][pos.y] == g_CharCode[CharName::COIN]);
		}
	}
 
	void movePlayer(Vec2 &pos_, Movement move)
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
		pos_ = newPos;  //actualiza la posicion del jugador

	}
	bool gameOver() { return(BoardCoins <= 0);}
};