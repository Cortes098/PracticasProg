#include "MyQueue.h"



MyQueue::MyQueue()
{
	first = nullptr;
	first = last;
	m_size = 0;
}

MyQueue::MyQueue(const MyQueue &copy)
{

}

void MyQueue::Push(int num) 
{
	if (first==nullptr) 
	{
		node *aux = new node{ num, nullptr };
		last = aux;
		first = aux;
	}
	else 
	{
		node *aux = new node{ num, nullptr };
		last->next = aux;
		last = aux;
	}
	m_size++;
}

void MyQueue::Pop()
{
	node *aux = first->next;
	delete[] first;
	first = aux;
	m_size--;
}

int MyQueue::front()
{
	return first->info;
}

int MyQueue::back()
{
	return last->info;
}

void MyQueue::swap( MyQueue & aux)
{
	node *copy = this->first;
	this->first = aux.first;
	aux.first = copy;

	copy = this->last;
	this->last = aux.last;
	aux.last = copy;	


}

int MyQueue::size()
{
	return m_size;
}

MyQueue::~MyQueue()
{
}
