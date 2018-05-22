#include <iostream>
#include <time.h>

int* lineaSearchMultiple1(int _arr[], int size, int value) 
{
	int *count=nullptr;
	int num=0;
	int *pointer;
	for (int i = 0; i<size; i++)
	{
		if(_arr[i]==value)
		{
			num++;
			int *aux = count;
			count = new int[num];
			count = aux;
			pointer = count;
			for(int i=0;i<num;i++)
			{
				*pointer++;
			}
			*pointer = i;
		}
	}	
	for (int i = 0; i<size; i++)
	{
		std::cout << count[i] << " - ";
	}
	return count;
}

void main() 
{
	const int size = 10;
	int arr[size];
	
	for(int i=0; i<size;i++)
	{
		arr[i] = rand() % 10;
	}
	
	lineaSearchMultiple1(arr, size, 4);

	for (int i = 0; i<size; i++)
	{
		std::cout << arr[i] << " - "<< std::endl;;
	}

}