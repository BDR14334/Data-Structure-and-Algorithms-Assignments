#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Cell.h"
#include "SafeArray.h"
//#include "Tracker.h"

using namespace std;

class Map
{
public:
	Map(const string& filePath); //create the cells and store the cell pointers
	//void setDirections(int num);
	void printCells(); //prints from file
	void printRoute(); //print x's and o's

	Cell* getStartCell();
	Cell* getNorth(const Cell* p_cell);
	Cell* getNorthEast(const Cell* p_cell);
	Cell* getEast(const Cell* p_cell);
	Cell* getSouth(const Cell* p_cell);
	Cell* getSouthEast(const Cell* p_cell);
	Cell* getWest(const Cell* p_cell);
	Cell* getSouthWest(const Cell* p_cell);
	Cell* getNorthWest(const Cell* p_cell);
private:
	SafeArray < Cell* > allCells;
	Cell* p_startCell;
	
	//Cell** mapCell;
	
	//int dim = sqrt(num);



};

