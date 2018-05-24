#include "Board.h"

int main(int, char *[])
{
	int score; //mantiene el número de monedas recogidas	
	Board myB;
	myB.InitializeBoard();
	std::stack<Board::Movement> input;
		while (!myB.platform.GameOver)
		{
			
			Sleep(100);
			system("cls");
						
			
			//INPUT
			if (GetKeyState(VK_LEFT) < 0)
			{
				input.push(myB.LEFT);
			}
			if (GetKeyState(VK_RIGHT) < 0)
			{
				input.push(myB.RIGHT);
			}
			if (GetKeyState(VK_ESCAPE) < 0)
			{
				input.push(myB.EXIT);
			}
			//MOVEMENT
			while (!input.empty())
			{
				if (input.top() == myB.RIGHT)
				{
					myB.movePlayer(myB.RIGHT);
					input.pop();
				}
				else if (input.top() == myB.LEFT)
				{
					myB.movePlayer(myB.LEFT);
					input.pop();
				}
				else if (input.top() == myB.EXIT)
				{
					return 0;
				}
			}
			myB.moveBall();

			//PRINT
			myB.printBoard();
			std::cout << myB.platform.score << std::endl;
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