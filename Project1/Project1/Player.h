#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

struct Vec2
{
	int x;
	int y;
};



static const int NUM_ROWS = 10;
static const int NUM_COLUMNS = 10;
int BoardCoins = 0;

struct Player
{
	Vec2 position;
	int score=0;
	
	Player()
	{
		position.x = rand() % NUM_ROWS;
		position.y = rand() % NUM_COLUMNS;
	}

	inline void printScore() {
		std::cout << "---- Score: " << score << " ----" << std::endl;
		std::cout << "X->" << position.x << " // Y->" << position.y << std::endl;
	};

	inline void updateScore(int points) { score += points;  BoardCoins--; }

	void setPos(Vec2 pos) 
	{
		position = pos;
	}
};