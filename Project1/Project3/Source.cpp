#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>

std::list<int> superMerge(std::list<int> list1, std::list<int> list2)
{
	list1.sort();
	list2.sort();//Por si acaso
	list1.merge(list2);

	return std::list<int>(list1);
}

void change(std::forward_list<int> &listaux)
{
	int aux;
	std::forward_list<int>::iterator it;
	for (std::forward_list<int>::iterator copy=listaux.begin(); copy!=listaux.end(); ++copy)
	{
		it = copy;
	}

	aux = *it;
	*it = listaux.front();
	listaux.front()=aux;
}

int getElementPos(std::list<int> listaux, int pos)
{
	std::list<int>::iterator it = listaux.begin();
	
	for (int i = 0; i < pos-1; i++)
	{
		it++;
	}
	int value = *it;
	return value;
}

void removeDuplicates(std::list<int> &listaux)
{
	listaux.unique();
}

void remove(std::list<int> &listaux, int value)
{
	listaux.remove(value);
}

void reverse(std::list<int> &listaux)
{
	listaux.reverse();
}

void main()
{
	std::list<int> uno{ 0,1,2,3,3,3,4 };
	std::list<int> dos{ 5,6,7,8,9 };
	std::forward_list<int> f_dos{ 5,6,7,8,9 };
	
	std::list<int> tres(superMerge(uno,dos));
	change(f_dos);
	getElementPos(tres, 3);
	removeDuplicates(tres);
	remove(tres,3);
	reverse(tres);

}
