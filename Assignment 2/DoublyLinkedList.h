#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void insertAtFront(const T& elem);
	void insertAtRear(const T& elem);
	bool removeFromFront(T& elem); //true if an item is removed, elem holds that value
	bool removeFromRear(T& elem); //true if an item is removed, elem holds that value
	bool remove();
	//bool remove(int pos); //remove the element that the current pointer points to
	bool remove(const T& elem); //remove all occurrences of the element that is passed in.
	int size() const;
	bool first(T& elem);
	bool last(T& elem);
	bool next(T& elem);
	bool previous(T& elem);
	bool isEmpty();
	bool find(const T& elem); //returns a true/false value indicating if an element is present in the list
	T& at(int pos); //a method that simulates accessing the list like an array.
	T& operator[](int pos); //call at()

private:
	struct Node
	{
		T data;
		Node* p_next;
		Node* p_previous;
	};
	Node* p_start;
	Node* p_end;
	Node* p_current;
	int numElements;
};


template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	p_start = 0; // initializes first node pointer to nullptr
	p_current = 0; // initialize current position to nullptr
	numElements = 0; // initialize number of elements in the list to nullptr
}
//--
template<class T>
DoublyLinkedList<T>:: ~DoublyLinkedList() 
{
	// declare a node pointer that holds pointer node to be deleted
	Node* p_delete;
	// loop checks if all nodes are deleleted
	while (!isEmpty())
	{
		p_delete = p_start; // sets p_delete to point to the first node
		p_start = p_start->p_next; // points to next node to move forward
		delete p_delete; // delete node and data that points to p_delete
		numElements--; // one element removed from list
	}
}
//--
template<class T>
void DoublyLinkedList<T>::insertAtFront(const T& elem)
{
	Node* p_newNode;
	p_newNode = new Node;

	//if list is empty
	if (size() == 0)
	{
		//make new node
		p_newNode->p_next = 0;
		p_newNode->p_previous = 0;
		p_newNode->data = elem;

		//p_start and p_end point to p_newNode
		p_start = p_newNode;
		p_end = p_newNode;
	}
	else
	{
		p_newNode->data = elem; //intialize new node wirh data
		p_newNode->p_previous = 0; //set previous pointer to null
		p_newNode->p_next = p_start; //set next pointer to the current start
		p_start->p_previous = p_newNode; //update previous pointer of the current to point to new node
		p_start = p_newNode; //update p_start to point to the new node
		//p_current = p_current->p_next;
	}
	numElements++;
	//insert at front of Array pointer
}
//--
template<class T>
void DoublyLinkedList<T>::insertAtRear(const T& elem)
{
	//declare new node
	Node* p_newNode;
	//create new node
	p_newNode = new Node;
	
	//if list is empty
	if (size() == 0)
	{
		//set pointers to null
		p_newNode->p_next = 0;
		p_newNode->p_previous = 0;
		//initialize the new node with data
		p_newNode->data = elem;
		//set both p_start and p_end point to the new node
		p_start = p_newNode;
		p_end = p_newNode;
	}
	else
	{
		//initialize the new node with data
		p_newNode->data = elem; 
		p_newNode->p_previous = p_end; //set previous pointer to the current end
		p_newNode->p_next = 0; //set next pointer to null
		p_end->p_next = p_newNode; //update next pointer of end to point to the new node
		p_end = p_newNode; //update p_end to point to the new node
		
	}
	numElements++;
	// Increment the element count to reflect the addition of a new element
}
//--
template<class T>
bool DoublyLinkedList<T>::removeFromFront(T& elem)
{
	bool retVal = false;
	Node* p_delete = p_start; //create a pointer to the node to be deleted, which is the current front

	//if size of list is greater than 1
	if (size() > 1)
	{
		retVal = true;
		elem = p_start->data; //copy data of the current front node to the 'elem'
		p_start = p_start->p_next; //update p_start to point to the next node in the list
		delete p_delete; //delete the node pointed to by p_delete
		p_start->p_previous = 0; //update the previous pointer of the new front node to null
		//delete p_start;
		//decrease
		numElements--;
	} 
	else if (size() == 1) //if the list has only one element
	{
		retVal = true; 
		delete p_start;
		//set both p_startand p_end to null, indicating an empty list
		p_start = 0;
		p_end = 0;
		numElements--;
		//copy the data of the removed node to the elem
		elem = p_start->data;

	}


	return retVal;

	// true if an item is removed, element holds that value
}
//--
template<class T>
bool DoublyLinkedList<T>::removeFromRear(T& elem)
{
	bool retVal = false;
	Node* p_delete = p_end;

	if (size() > 1)
	{
		retVal = true;
		elem = p_end->data; //copy  data of the current rear node to the elem
		p_end = p_end->p_previous; //update p_end to point to the previous node in the list
		delete p_delete; //delete the node pointed to
		p_end->p_next = 0; //update next pointer of the new end node to null
		//delete p_end;
		numElements--;
	}
	else if (size() == 1)
	{
		elem = p_end->data; //copy  data of the current rear node to the elem

		retVal = true;
		delete p_end; //delete the current end node
		//set both p_start and p_end to null
		p_start = 0;
		p_end = 0;
		numElements--;


	}
	return retVal;
	//true if an item is removed, elem holds that value
}
template<class T>
bool DoublyLinkedList<T>::remove()
{
	bool retVal = false;

	//p_current = p_start;
	//while (!isEmpty()) //continue while the list is not empty
	//{
	//	T elem;
	//	removeFromFront(elem); //remove elements from the front until the list is empty
	//	retVal = true;
	//}
	
	//if size = 1 and p_current = head
	
	if (size() == 1 && p_current == p_start)
	{
		retVal = true;
		delete p_current;
		p_start = 0;
		p_end = 0;
		p_current = 0;
		
	}
	else if (p_current == p_start)
	{
		retVal = true;
		p_start->p_next->p_previous = 0;
		p_start = p_start->p_next;
		delete p_current;
		p_current = p_start;
	}
	else if (p_current == p_end)
	{
		retVal = true;
		p_end->p_previous->p_next = 0;
		p_end = p_end->p_previous;
		delete p_current;
		p_current = 0;
	}
	else
	{
		Node* p_newNode = p_current->p_previous;
		retVal = true;
		p_current->p_next->p_previous = p_current->p_previous;
		p_current->p_previous->p_next = p_current->p_next;
		delete p_current;
		p_current = p_newNode;
		
	}

	if (retVal == true)
	{
		numElements--;
	}
	//if p_start is equal to something
	//if p_tail is equal to something
	//else assumes its in the middle


	return retVal; ;
}
//--
//template<class T>
//bool DoublyLinkedList<T>::remove(int pos)
//{
//	bool retVal = false;
//
//
//	p_current = p_start;
//	for(int i = 0; i <= pos;i++)//continue while the list is not empty
//	{
//		
//		p_current = p_current->p_next;
//		
//		if (i == pos)
//		{
//			p_current->p_next->p_previous = p_current->p_previous;
//			p_current->p_previous->p_next = p_current->p_next;
//			delete p_current;
//		}
//
//		retVal = true;
//	}
//	
//
//	return retVal; 
//}
//--
template<class T>
bool DoublyLinkedList<T>::remove(const T& elem)
{
	bool retVal = false;

	p_current = p_start;
	//for (int i = 0; i < numElements; i++)
	while(p_current != 0)
	{
		if (p_current->data == elem)
		{
			retVal = true;
			remove();
		}
		if (p_current != 0)
		{
			p_current = p_current->p_next;
		}
		
	}
	
	return retVal;

}
//--
template<class T>
int DoublyLinkedList<T>::size() const
{
	//the size of the array
	return numElements;
}
//--
template<class T>
bool DoublyLinkedList<T>::first(T& elem)
{
	bool retVal = false;

	if (!isEmpty())
	{
		retVal = true;
		p_current = p_start;
		elem = p_current->data;
	}

	//print first element of the array 
	return retVal;
}
//--
template<class T>
bool DoublyLinkedList<T>::last(T& elem)
{
	bool retVal = false;

	if (!isEmpty())
	{
		retVal = true;
		p_current = p_end;
		elem = p_current->data;

	}

	return retVal;
	//place the current pointer at the last element;
}
//--
template<class T>
bool DoublyLinkedList<T>::next(T& elem)
{
	bool retVal = false;

	if (p_current != 0 && p_current->p_next)
	{
		p_current = p_current->p_next;
		retVal = true;
		elem = p_current->data;

	}

	return retVal;
	//go to next object in array; move forward in container
}
//--
template<class T>
bool DoublyLinkedList<T>::previous(T& elem)
{
	bool retVal = false;

	p_current = p_current->p_previous;

	if (p_current != 0)
	{
		retVal = true;
		elem = p_current->data;
	}

	return retVal;
	//move backward into container; previous() method that will move one node backwards
}
//--
template<class T>
bool DoublyLinkedList<T>::isEmpty()
{
	bool retVal = false;

	if (numElements == 0)
	{
		retVal = true;
		//return size() = 0;

	}

	return retVal;
	//check if array value is empty
}
//--
template<class T>
bool DoublyLinkedList<T>::find(const T& elem)
{
	bool retVal = false;
	Node* p_find = p_start;

	while (p_find != 0)
	{
		if (p_find->data == elem)
		{
			retVal = true;
			break;
		}
		p_find = p_find->p_next;
	}

	return retVal;
	//returns a true/false value indicating if an element is present in the list
}
//--
template<class T>
T& DoublyLinkedList<T>::at(int pos)
{
	//a method that simulates accessing the list like an array.
	p_current = p_start;
	if (numElements > pos)
	{
		for (int i = 0; i < pos; i++)
		{
			p_current = p_current->p_next;
		}
	}
	else
	{
		int x = 0;
		throw x;
	}
	
	return p_current->data;
}
//--
template<class T>
T& DoublyLinkedList<T>::operator[](int pos)
{
	//call at()
	return at(pos);
}
