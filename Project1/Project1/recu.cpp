#include <iostream>
#include <algorithm>
#include <list>

std::list<int> superMerge(std::list<int> list1, std::list<int> list2)
{
	list1.merge(list2);
	list1.sort();
	return std::list<int>(list1);
}

void main()
{
	std::list<int> uno{ 1,2,3,4, };
	std::list<int> dos{ 5,6,7,8,9 };
	std::list<int> tres(superMerge(uno, dos));
}