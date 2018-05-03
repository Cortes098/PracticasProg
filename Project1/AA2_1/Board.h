#pragma once
#include "Platform.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <queue>

struct Ball 
{
	char x;
	char y;
};

class Board
{	
	
public:

	Platform platform;
	enum Movement { LEFT, RIGHT };

	char **board;
	char delimiter;	
	

	Vec2 ball;
	Vec2 velocity;

	std::vector <std::string> vecSizes;
	Board();
	void InitializeBoard();
	void printBoard();
	void movePlayer(Movement Dir);
	void adjustPlayer();
	void moveBall();
	void addPoints();
	~Board();

private:
	int NUMROWS, NUMCOL, ROWBLOCK;
	Vec2 minmax;
	std::queue<int> Qpoints;
	enum CharName { NONE, PLAYER, BLOCK, BALL, WALLV, WALLH };
	char g_CharCode[6] = { ' ', '-', '@','*','|', '_' };

	
};