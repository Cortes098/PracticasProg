#include "Board.h"

int main(int, char *[])
{
	srand(time(NULL));

	

	Vec2 position;
	int score, countCoins; //mantiene el número de monedas recogidas
	bool GameOver=false;
	char input;
	Board myB;
	myB.InitializeBoard();

			
		while (!GameOver)
		{
			
			Sleep(100);
			system("cls");
			myB.printBoard();
			myB.moveBall();
			if(GetKeyState(VK_LEFT) < 0)
			{
				myB.movePlayer(myB.LEFT);
			}
			if (GetKeyState(VK_RIGHT) < 0)
			{
				myB.movePlayer(myB.RIGHT);
			}
			if (GetKeyState(VK_ESCAPE) < 0)
			{
				return 0;
			}
		}


	
	return 0;
}