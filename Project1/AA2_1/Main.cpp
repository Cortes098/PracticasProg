#include "Board.h"

int main(int, char *[])
{
	int score; //mantiene el número de monedas recogidas	
	char input;
	Board myB;
	myB.InitializeBoard();
				
		while (!myB.platform.GameOver)
		{
			
			Sleep(500);
			system("cls");
						
			
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
			myB.moveBall();

			myB.printBoard();
			std::cout<<myB.platform.score<<std::endl;
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