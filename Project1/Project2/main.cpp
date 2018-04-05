#include "MyQueue.h"

void main()
{
	MyQueue mycola;
	MyQueue mycola2;

	
	mycola.Push(1);
	mycola.Push(2);
	mycola.Push(3);
	//mycola.Pop();
	
	mycola2.Push(2);
	mycola2.Push(3);
	mycola2.Push(4);

	mycola.swap(mycola2);


	
}