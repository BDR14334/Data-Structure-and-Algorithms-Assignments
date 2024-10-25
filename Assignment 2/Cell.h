#pragma once
#include <iostream> 
#include "DoublyLinkedList.h"

using namespace std;

class Cell
{
public:
	Cell();
	void setRow(int isX);
	int getRow() const;
	void setColumn(int isY);
	int getColumn() const;
	void setType(char isType);
	char getType();

	void setHasBeenVisited(bool v);
	bool getHasBeenVisited();
	void setOnPath(bool p);
	bool getOnPath();

private:
	int x;
	int y;
	char type;
	bool hasBeenVisited;
	bool onPath;
};
