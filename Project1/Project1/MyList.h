#pragma once

struct node
{
	int info;
	node *node;
};

class MyList
{
public:
	node *first;
	node *last;
	node *next;
	node *prev; 

	int size;

	MyList();
	~MyList();
};

