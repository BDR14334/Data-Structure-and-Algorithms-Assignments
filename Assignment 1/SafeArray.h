#pragma once
#include <iostream>
#include <string>
#include "SafeArrayException.h"

using namespace std;

template <class T>
class SafeArray
{
public:
	SafeArray();
	//~SafeArray();
	void push_back(T newVal);
	int pop_back();
	int size() const;
	T& at(int pos) const;
	T& operator[](int pos) const;
	SafeArray(const SafeArray& original);
	void erase(int pos);
	void resize(int newSize);

private:

	int arrayCapacity; //size of array

	T* p_pos;//storing data at position
	
	int latestElem;//latest number in array position
};

template <class T>
SafeArray<T>::SafeArray()
{
    arrayCapacity = 10;
    p_pos = new T[arrayCapacity];
    latestElem = 0;

}

//template <class T>
//SafeArray<T>::~SafeArray()
//{
//    cout << "Calling Destructor" << endl;
//    delete[] p_pos;
//    //delete pos;
//}

template <class T>
void SafeArray<T>::push_back(T newVal)
{
    //array that holds original size of array
    //T* p_isArray = new T[arrayCapacity];

    if (latestElem == arrayCapacity)
    {
        //double the array
        //store the new length of the array
        int newArrayCapacity = 2 * arrayCapacity;
        //create a new array of strings twice as long as the original
        T* p_newArray = new T[newArrayCapacity];

        //copy the elements from the old to the new
        for (int i = 0; i < arrayCapacity; i++)
        {
            p_newArray[i] = p_pos[i];
        }

        //get rid of the old array because it is not needed anymore
        delete[] p_pos;

        //adjust the pointer
        p_pos = p_newArray;

        //cout << "Doubling the array from " << wordArrayLength << " to " << newArrayLength << endl;

        /*update the new size of the array
        arrayCapacity = 2 * arrayCapacity;*/
        arrayCapacity = newArrayCapacity;

    }
    p_pos[latestElem] = newVal;

    latestElem++;


}

template <class T>
int SafeArray<T>::pop_back()
{
    if (size() == 0)
    {
        SafeArrayException ex("Cannot pop from an empty SafeArray");
        throw ex;
    }

    if (latestElem >= 0)
    {
        //delete array from back
        //latestNum --;

        //int* p_isArray = new int[arrayCapacity];

        //if the array ever gets reduced to one quarter full then cut the size of the array in half 
        //(however, never go below 10 elements)
        if (latestElem <= (arrayCapacity / 4) && arrayCapacity > 10)
        {
            int newArraySize = arrayCapacity / 2;
            T* newArray = new T[newArraySize];

            for (int i = 0; i < latestElem; i++)
            {
                newArray[i] = p_pos[i];
            }

            delete[] p_pos;
            p_pos = newArray;

        }

        latestElem = latestElem - 1;

        return p_pos[latestElem];
    }
    
}

//method called size()
template < class T >
int SafeArray<T>::size() const
{
    return latestElem;
}

template <class T>
T& SafeArray<T>::at(int pos) const
{
    if (pos >= 0 && pos < latestElem)
    {
        return p_pos[pos];//return reference or alias to a int
    }
    else
    {
        SafeArrayException ex("Out of bounds");
        throw ex;
        //cout << ex << endl;
        //exit(0);
    }
}

template <class T>
T& SafeArray<T>::operator[](int pos) const
{
    // TODO: insert return statement here
    return at(pos);
}

template<class T>
SafeArray<T>::SafeArray(const SafeArray& original)
{
   int newArrayCapacity = original.arrayCapacity;
    
    T* p_newArray = new T[newArrayCapacity];

    for (int i = 0; i < original.latestElem; i++)
    {
        p_newArray[i] = original.p_pos[i];
    }

    arrayCapacity =  original.arrayCapacity;
    p_pos = p_newArray;
    latestElem = original.latestElem;
}

template<class T>
void SafeArray<T>::erase(int pos)
{
    //int* p_isArray = new int[arrayCapacity];
    if (size() == 0)
    {
        SafeArrayException ex("Cannot pop from an empty SafeArray");
        throw ex;
    }

    for (int i = pos; i < latestElem - 1; i++)
    {
        p_pos[i] = p_pos[i + 1];
    }

    latestElem--;
    
    if (latestElem <= arrayCapacity / 4 && arrayCapacity > 10)
    {
        int newArraySize = arrayCapacity / 2;
        T* newArray = new T[newArraySize];

        for (int i = 0; i < latestElem; i++)
        {
            newArray[i] = p_pos[i];
        }

        delete[] p_pos;
        p_pos = newArray;
    }

}

template<class T>
void SafeArray<T>::resize(int newSize)
{
    //T* p_isArray = new T[arrayCapacity]; //change p_isArray to p_pos

    //int copyOfSize;

    T* newArray = new T[2*newSize];

    delete[] p_pos;
    
    p_pos = newArray;
    arrayCapacity = 2 * newSize;
    
    latestElem = newSize;


}
