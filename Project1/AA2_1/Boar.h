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

	enum Movement { LEFT, RIGHT };

	char **board;
	char delimiter;	
	int maxscore, countscore;

	Vec2 playerPos[3];
	Vec2 ball;
<<<<<<< HEAD
	Vec2 velocity;
=======
>>>>>>> bebf3776999cc183b38ac095408c99f96518d3dd
	std::vector <std::string> vecSizes;
	Boar();
	void InitializeBoard();
	void printBoard();
	void movePlayer(Movement Dir);
	void adjustPlayer();
	void moveBall();
	~Boar();

private:
	enum CharName { NONE, PLAYER, BLOCK, BALL, WALLV, WALLH };

	char g_CharCode[6] = { ' ', '@', '*','-','|', '_' };
	int NUMROWS, NUMCOL, ROWBLOCK;
};

