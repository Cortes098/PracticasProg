#pragma once

struct node
{
	int info;
	node *node;
};

class my_forwardList
{
public:
	node *first;
	node *last;
	node *next;

	int size;

	my_forwardList();
	~my_forwardList();
};
