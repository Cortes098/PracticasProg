#include "Board.h"
#include <map>
enum class InputKey { NONE, ESC, LEFT, RIGHT, ENTER, PAUSE, NUM1, NUM2, NUM0, NUM_KEYS };

int main(int, char *[])
{
	//*************RANKING_INI*************//
	std::map<std::string, int> ranking;
	std::string str;
	int num;

	std::ifstream MyFileRead("ranking.bin", std::ios::binary);
	for (int i = 0; !MyFileRead.eof() && !ranking.empty() && i<5; i++)
	{
		MyFileRead >> str >> num;
		if (num >= 0 && str != "")
		{
			ranking[str] = { num };
		}
	}
	MyFileRead.close();
	//**************************//


	Board myB;
	myB.InitializeBoard();

	std::stack<InputKey> my_input;

	enum class GameState { MENU, PLAY, SCORE, RANKING, EXIT, MAX };
	GameState myGameState = GameState::MENU;

	while (!myB.platform.GameOver)
	{
		switch (myGameState)
		{
		case GameState::MENU:

			//*********EVENTHANDLE*********//
			if (GetKeyState(VK_NUMPAD1) < 0)
			{
				my_input.push(InputKey::NUM1);
			}
			else if (GetKeyState(VK_NUMPAD2) < 0)
			{
				my_input.push(InputKey::NUM2);
			}
			else if (GetKeyState(VK_NUMPAD0) < 0)
			{
				my_input.push(InputKey::NUM0);
			}
			//*********UPDATE*********//
			while (!my_input.empty())
			{
				if (my_input.top() == InputKey::NUM1)
				{
					myGameState = GameState::PLAY;
					my_input.pop();
				}
				else if (my_input.top() == InputKey::NUM2)
				{
					myGameState = GameState::RANKING;
					my_input.pop();
				}
				else if (my_input.top() == InputKey::NUM0)
				{
					return 0;
				}
			}
			//*********PRINT*********//
			std::cout << "1-Play" << std::endl;
			std::cout << "2-Ranking" << std::endl;
			std::cout << "0-Exit" << std::endl;
			break;
		
		case GameState::PLAY:
			//*********EVENTHANDLE*********//
			if (GetKeyState(VK_LEFT) < 0)
			{
				my_input.push(InputKey::LEFT);
			}
			if (GetKeyState(VK_RIGHT) < 0)
			{
				my_input.push(InputKey::RIGHT);
			}
			if (GetKeyState(VK_ESCAPE) < 0)
			{
				my_input.push(InputKey::ESC);
			}
			//*********UPDATE*********//
			while (!my_input.empty())
			{
				if (my_input.top() == InputKey::RIGHT)
				{
					myB.movePlayer(myB.RIGHT);
					my_input.pop();
				}
				else if (my_input.top() == InputKey::LEFT)
				{
					myB.movePlayer(myB.LEFT);
					my_input.pop();
				}
				else if (my_input.top() == InputKey::ESC)
				{
					return 0;
				}
			}
			if (myB.platform.lives <= 0) myGameState = GameState::SCORE;
			myB.moveBall();
			//*********PRINT*********//
			std::cout << myB.platform.lives << std::endl;
			std::cout << myB.platform.score << std::endl;
			myB.printBoard();			
			break;
		case GameState::SCORE:


			break;
		case GameState::RANKING:

			break;
		case GameState::EXIT:
			break;
		default:
			break;
		}
		Sleep(250);
		system("cls");
	}
	while (true)
	{
		if (GetKeyState(VK_ESCAPE) < 0)
		{
			return 0;
		}
	}
	return 0;
}

void printScore(std::map<std::string, int> _ranking)
{
	std::map<std::string, int>::iterator it;
	for (it=_ranking.begin();it!=_ranking.end();it++) 
	{

	}
}