#pragma once
#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
#include "StackError.h"

using namespace std;

template < class T >
class Stack
{
public:

	void push(const T& elem);
	T pop(T& elem);
	T top(T& elem);
	bool isEmpty() const;
	int size() const;

private:
	DoublyLinkedList <T> list;

};

template < class T >
void Stack<T>::push(const T& elem)
{
	list.insertAtFront(elem);
}

template < class T >
T Stack<T>::pop(T& elem)
{
	if (size() == 0)
	{
		StackError ex("Cannot use pop from an empty Stack");
		throw ex;
	}
	//T elem;
	list.removeFromFront(elem);
	//return elem;
}

template < class T >
T Stack<T>::top(T& elem) 
{
	if (size() == 0)
	{
		StackError ex("Cannot use top from an empty Stack");
		throw ex;
	}
	//T* elem;
	list.first(elem);
	//list.first(elem);
	return elem;
}

template < class T >
bool Stack<T>::isEmpty() const
{
	return list.isEmpty();
}

template < class T >
int Stack<T>::size() const
{
	return list.size();
}
