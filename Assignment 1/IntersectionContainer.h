#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "SafeArray.h"

using namespace std;

template<class T>
class IntersectionContainer
{
public:
	void add(const SafeArray<T>& set);
	SafeArray<T> getCommonElements();

private:
	SafeArray<T> elements;
	bool isFirstAdd=true;
	//SafeArray<T> wordSet
	char isChar;
	int pos;

};

template<class T>
void IntersectionContainer<T>::add(const SafeArray<T>& set)
{
	if (isFirstAdd==true) 
	{
		// If it's the first add, simply copy the entire set
		elements = set;
		isFirstAdd = false;
	}
	else {
		// loop thru elements and check if they exist in 'set'
		for (int i = 0; i < elements.size(); i++) 
		{
			isFirstAdd = false;
			for (int j = 0; j < set.size(); j++)
			{
				if (elements[i] == set[j])
				{
					//we have found one value in set that is also in elements
					isFirstAdd = true;
					//stop looking through set
					break;
					
					
				}
			}
			
			if (isFirstAdd == false)
			{
				//erase string in array
				elements.erase(i);
				i--;
			}
		}
	}
}

template<class T>
SafeArray<T> IntersectionContainer<T>::getCommonElements()
{
	//return the rest of Array elements
	return elements;
}
