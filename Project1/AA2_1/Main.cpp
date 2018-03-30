#include "Boar.h"

int main(int, char *[])
{
	srand(time(NULL));

	enum Movement{UP, DOWN, LEFT, RIGHT};

	Vec2 position;
	int score, countCoins; //mantiene el número de monedas recogidas
	bool GameOver=false;
	char input;
	Boar myB;
	myB.InitializeBoard();

	while(!GameOver)
	{
		Sleep(50);
		system("cls");
		myB.printBoard();
		
		while (!GameOver)
		{
			Sleep(50);
			system("cls");

			std::cin >> input;
			bool ignore = false;
			Movement move;
			switch (input)
			{			
			case VK_LEFT: 
				move = Movement::LEFT;
			break;

			case VK_RIGHT: 
				move = Movement::RIGHT;
			break;

			case VK_ESCAPE:
				return 0;
				break;

			default:
				ignore = true;
				break;
			};

			/*if (!ignore) {
				if (board.checkMovement(player.position, move))
				{
					if (board.existCoin(player.position, move)) { player.updateScore(1); player.setPickedCoins(1); };
					player.setPos(board.movePlayer(player.position, move));
				};
			};*/

		}


	}
	return 0;
}