#pragma once
#include <iostream>

struct node 
{
	int info;
	node *next;
};



class MyQueue
{
public:
	node *first;
	node *last;
	int m_size;
	MyQueue();
	MyQueue(const MyQueue &copy);
	void Push(int a);
	void Pop();
	int front();
	int back();
	void swap(MyQueue &aux);
	int size();
	~MyQueue();
};

