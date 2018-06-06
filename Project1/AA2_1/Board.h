#pragma once
#include "Platform.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <queue>
#include <stack>

struct Ball 
{
	char x;
	char y;
};

class Board
{	
	
public:

	Platform platform;
	enum Movement { LEFT, RIGHT, EXIT};

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

std::map<std::string, int>::iterator aux = _ranking.begin();
std::map<std::string, int>::iterator it = _ranking.begin();

int mida = _ranking.size();

if (mida <= 5)
{
	std::ofstream MyFileWrite("ranking.txt", std::ios::app);
	if (MyFileWrite.is_open())	MyFileWrite << _name << ' ' << _score << ' ';
	MyFileWrite.close();
}
else
{
	std::ofstream MyFileWrite("ranking.txt", std::ios::out);

	if (MyFileWrite.is_open()) {
		while (mida > 1)
		{
			for (; it != _ranking.end(); ++it)
			{
				if (it->second > aux->second)
				{
					aux = it;
				}
			}
			MyFileWrite << aux-> << ' ' << _score << ' ';
			_ranking.erase(aux);
		}
	}
}

