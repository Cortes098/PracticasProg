#pragma once
struct Vec2
{
	int x;
	int y;
};

class Platform
{
public:
	int score;
	int lives;
	Vec2 positions[3];
	bool GameOver;

	Platform();
	~Platform();
};

