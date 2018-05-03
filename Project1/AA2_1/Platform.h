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
	Vec2 positions[3];
	bool GameOver;

	Platform();
	~Platform();
};

