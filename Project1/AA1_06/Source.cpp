#include <iostream>
#include <vector>
#include <time.h>
struct info 
{
	std::string name;
	int DNI;
	int fecha;
};

std::vector <int> addVector(std::vector <int> one, std::vector <int> two)
{
	std::vector<int> three;

	if (one.size() == two.size()) 
	{
		for (int i = 0; i < one.size(); i++)
		{
			three.push_back(one[i] + two[i]);
		}
	}
	return three;
}

std::vector <std::string> concatVector(std::vector <std::string> one, std::vector <std::string> two)
{
	for (int i = 0; i < two.size(); i++)
	{
		one.push_back(two[i]);
	}
	return one;
}

std::vector <int> shiftRight(std::vector <int> &one)
{
	std::vector<int>::iterator it = one.begin();	
	one.insert(it, rand() % 100);
	return one;
}

std::vector <int> rotateLeft(std::vector <int> &one) 
{
	std::vector<int>::iterator it = one.begin();
	one.insert(it, one[one.size()-1]);
	one.pop_back();
	return one;
}

std::vector <int> searchAdjacent(std::vector <int> one)
{
	for (int i = 0; i < one.size()-1; i++)
	{
		if ((one[i]==one[i+1]) && (i<one.size()-2))
		{
			if (one[i+1]==one[i+2])
			{
				one.erase(one.begin()+i, one.begin()+(i+3));
				i = 0;
			}
		}
	}

	one.push_back(rand() % 100);
	one.push_back(rand() % 100);
	one.push_back(rand() % 100);

	return one;
}

bool isPalindrome(std::vector <char> one)
{
	std::vector <char>::iterator beg = one.begin();
	std::vector <char>::iterator end = one.end()-1;

	if((*beg==*end) && (one.size>1))
	{
		while ((*beg == *end) && (beg<end))
		{
						
			beg++;
			end--;
		}
		if (beg >= end)
		{
			return true;
		}
		return false;
	}
	

}

int main()
{
	std::vector <int> v1(5);
	std::vector <int> v2(10, 0);
	std::vector <int> v3 = { 10,9,8,7,6,5,4,3,2,1 };
	std::vector <int> prueba = { 10,9,8,7,6,6,6,3,2,1 };
	std::vector <std::string> v4 = { "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio","Fulgencia" };
	std::vector <int> v5(v3);
	std::vector <info> v6 = {{ "Gertrudiz", 5674288, 170899 }, { "Pancracia", 8943853, 80265 }, { "Pancracia", 7965466, 50682 }};
	std::vector <char> prueba2;
	std::vector <char> prueba3 = { 'R','E','C','O','N','O','c','E','R' };
	//shiftRight(v3);
	//prueba=searchAdjacent(prueba);
	bool quisap  =isPalindrome(prueba2);
	bool quisap2 = isPalindrome(prueba3);

}