#include "DynArray.hh"


DynArray::DynArray() 
{
	
	m_size = DYN_ARRAY_DEFAULT_SIZE;
	m_capacity = DYN_ARRAY_DEFAULT_SIZE +2;
	data = new int[m_capacity];
}

DynArray::DynArray(size_t size) 
{	
	m_size = size;
	m_capacity = size+2;
	data = new int[m_capacity];	
}

DynArray::DynArray(size_t size, const int &value)
{	
	m_size = size;
	m_capacity = size+2;
	data = new int[m_capacity];
	for (int i = 0; i < value; i++)
	{ 
		data[i] = value;
	}
}

bool DynArray::empty()
{
	return (m_size<=0);
}

size_t DynArray::capacity()
{
	return m_capacity;
}

size_t DynArray::size()
{
	return m_size;
}

size_t DynArray::maxSize()
{
	return m_capacity;
}

void DynArray::clear()
{	
		delete []data;
		m_size = 0;
}

void DynArray::print()
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout<<data[i]<<std::endl;
	}

}

int & DynArray::at(size_t n)
{
	return data[n];
}

int & DynArray::front()
{
	return *data;
}

int & DynArray::back()
{
	return data[m_size];
}
