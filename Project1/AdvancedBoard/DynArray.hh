#pragma once
#include <iostream>

struct DynArray
{

	size_t	m_capacity;													// actual size of the allocated memory
	size_t  m_size;														// current number of elements in the array
	int	   *data;														// pointer to the memory allocated in the Heap

	// static constants
	static const size_t DYN_ARRAY_DEFAULT_SIZE{ 8 };					// initial constant size of the array memory
	static const size_t DYN_ARRAY_MAX_SIZE{ 1073741823 };				// maximum constant size that the array memory can hold

	// constructors
	DynArray();															// constructs the array by default
	DynArray(size_t size);												// creates the array with a defined size
	DynArray(size_t size, const int &value);							// creates and initializes the elements of the array with a value
																			
	// iterator methods
	int* begin() ;														// returns an iterator(pointer) to the first element
	int* end() ;														// returns an iterator(pointer) to the last element

	// capacity methods
	void resize(size_t n);												// resizes the array so that it contains n elements
	void reserve(size_t n);												// requests the capacity to be at least enough to contain n elements
	void shrink();														// requests the array to reduce its capacity to fit its size
	bool empty() ;														// returns whether the array size is 0 or not
	size_t capacity() ;													// returns the size of the currently allocated storage space
	size_t size() ;														// returns the number of elements in the array
	size_t maxSize();													// returns the maximum number of elements that the array can hold

	// element access methods
	int& operator[]	(size_t n) ;										// returns a reference to the element at position n in the array
	int& at(size_t n) ;													// returns a reference to the element at position n in the array
	int& front() ;														// returns a reference to the first element in the array
	int& back() ;														// returns a reference to the last element in the array
							
	// modifiers methods
	void push(const int &val);											// adds a new element at the end of the array, after its current last element
	void pop();															// removes the last element effectively reducing the array size by one
	void insert(size_t position, const int &val);						// a new element is inserted before the element at the specified position
	void erase(size_t position);										// removes from the array a single element
	void erase(size_t first, size_t last);								// removes from the array a range of elements
	void clear();														// removes all elements from the array leaving it with a size of 0

	// utils methods
	void fill(int *first, int *last, int value);						// assigns the given value to the elements in the range [first, last)
	void copy(int *first, int *last, int *dest);						// copies all elements in the range [first, last) to dest
	void print();														// print the array
};