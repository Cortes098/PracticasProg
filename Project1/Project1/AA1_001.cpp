#include <iostream>
#include <string>
#include <time.h>

enum EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH, MAX };

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

bool equalEnemies(Enemy a, Enemy b)
{
	return ((a.name == b.name) && (a.type == b.type));	
}

Enemy CreateRandomEnemy()
{
	const int HEALTH{ 100 };
	const std::string names[]{ "TONA", "ANIOL", "IDROJ", "RADEV", "ENRIQUE", "CCORONADO", "LOURDES", "NICOLICH" };
	
	return
	{
		static_cast<EnemyType> (rand() % static_cast<int> (EnemyType::MAX)), //Tipo del enemigo
		names[(rand() % sizeof(names) / sizeof(std::string))],				 //Nombre
		rand() % HEALTH														 //Vida
	};
}

std::string getEnemyTypeString(Enemy a)
{
	switch (a.type)
	{

	case 0:
		return "ZOMBIE";
		break;

	case 1:
		return "VAMPIRE";
		break;

	case 2:
		return "GHOST";
		break;

	case 3:
		return "WITCH";
		break;

	default:
		break;
	}
}

int main()
{
	const int MAX_ENEMIES = 5;
	int act_enemies = 0;
	Enemy enemies[MAX_ENEMIES];
	
	for(int i=0; act_enemies<MAX_ENEMIES; i++)
	{
		enemies[i] = CreateRandomEnemy();

		for(int j=0; j<i;j++)
		{
			if ( (enemies[i].name == enemies[j].name) ) 
			{			
				enemies[i] = CreateRandomEnemy();
				
				j = 0;
			}
		}
		act_enemies++;
	}


	for(int i=0; i<MAX_ENEMIES; i++)
	{
		std::cout <<"NAME: "<< enemies[i].name << "\n" <<"TYPE: "<<getEnemyTypeString(enemies[i]) << "\n"<<"HEALTH: " << enemies[i].health<<"\n\n\n";
	}	
}

