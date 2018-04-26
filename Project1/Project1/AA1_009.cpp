#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

void printM(std::map<std::string, int> map)
{	
	while (map.size()>0)
	{
		std::map<std::string, int>::iterator aux = map.begin();
		std::map<std::string, int>::iterator it = map.begin();

		for (; it != map.end(); ++it)
		{
			if (it->second>aux->second)
			{
				aux = it;
			}
		}
		std::cout << aux->first<<": "<< aux->second<<std::endl;
		map.erase(aux);
	}	
}
void addPlayerM(std::map<std::string, int> &map)
{
	std::string name;
	int points;

	std::cout << "Introduce nombre del jugador" << std::endl;
	std::cin >> name;
	std::cout << "Introduce puntuacion del jugador" << std::endl;
	std::cin >> points;

	std::map<std::string, int>::iterator it = map.find(name);
	if (it == map.end())
		map[name] = points;
}

void printV(std::vector<std::pair<std::string, int>> vector)
{
	while (vector.size()>0)
	{
		std::vector<std::pair<std::string, int>>::iterator aux = vector.begin();
		std::vector<std::pair<std::string, int>>::iterator it = vector.begin();

		for (; it != vector.end(); ++it)
		{
			if (it->second>aux->second)
			{
				aux = it;
			}
		}
		std::cout << aux->first << ": " << aux->second << std::endl;
		vector.erase(aux);
	}
}
void addPlayerV(std::vector<std::pair<std::string, int>> &vector)
{
	std::string name;
	int points;

	std::cout << "Introduce nombre del jugador" << std::endl;
	std::cin >> name;

	std::pair<std::string, int> my_pair = { name, points };

	std::vector<std::pair<std::string, int>>::iterator it = std::find(vector.begin(), vector.end(), my_pair);

	/*while (it!=vector.end())
	{		
		std::cout << "Nombre ya en uso, introduce otro" << std::endl;
		std::cin >> name;
		it = std::find(vector.begin(), vector.end(), name);
	}*/	

	std::cout << "Introduce puntuacion del jugador" << std::endl;
	std::cin >> points;
	
	
	
}

void main() 
{
	std::map<std::string, int> m_ranking;
	std::vector<std::pair<std::string, int>> v_ranking;

	//m_ranking["AAE"] = 80;
	m_ranking.insert (std::pair<std::string, int>("AAA", 10));
	m_ranking.insert (std::pair<std::string, int>("AAB", 10));
	m_ranking.insert (std::pair<std::string, int>("AAC", 20));
	m_ranking.insert (std::pair<std::string, int>("AAD", 30));	

	//addPlayerM(m_ranking);
	//printM(m_ranking);

	v_ranking.push_back(std::pair<std::string, int>("AAA", 40));
	v_ranking.push_back(std::pair<std::string, int>("AAB", 05));
	v_ranking.push_back(std::pair<std::string, int>("AAC", 20));
	v_ranking.push_back(std::pair<std::string, int>("AAD", 30));

	addPlayerV(v_ranking);
	printV(v_ranking);

}
