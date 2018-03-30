#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <vector>

struct Vec2
{
	int x;
	int y;
};

class Boar
{	
public:
	char **board;
	char delimiter;	
	int maxscore, countscore;

	Vec2 playerPos;
	std::vector <std::string> vecSizes;

	Boar();
	void InitializeBoard();
	void printBoard();
	~Boar();

private:
	enum CharName { NONE, PLAYER, BLOCK, BALL, WALLV, WALLH };
	char g_CharCode[6] = { ' ', '@', '*','-','|', '_' };
	int NUMROWS, NUMCOL, ROWBLOCK;
};

