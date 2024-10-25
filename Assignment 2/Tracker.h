#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Cell.h"
#include "SafeArray.h"
#include "Map.h"

using namespace std;

class Tracker
{
public:
	Tracker();
	~Tracker();
	void findPath(Map* p_map);

private:
	Stack <Cell*> onPathCells;
	Cell* p_currentCell;

};

