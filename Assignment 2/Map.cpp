#include "Map.h"

Map::Map(const string& filePath)
{
	ifstream infile(filePath);

    if (!infile.is_open()) {
        cout << "Failed to open the map file: " << filePath << std::endl;
        exit(1);
    }

    //vector<Cell> row;
    char letter;
    //size = 0;
    infile >> letter;
    while (infile.good())
    {
        if (letter != ' ')
        {
            Cell* cell = new Cell();
            cell->setType(letter);
            allCells.push_back(cell);
        }
        infile >> letter;
    }

    
    int num = allCells.size();
    int dim = sqrt(num);
    //row will always be i % dim
    int r=0;
    int c=0;
    for (int i = 0; i < num; i++)
    {
        if ((i + 1) % dim == 0)
        {

            c = i % dim;
            allCells[i]->setRow(r);
            r++;
            allCells[i]->setColumn(c);
        }
        else
        {
            c = i % dim;
            allCells[i]->setRow(r);
            allCells[i]->setColumn(c);
        }
        
    }


    infile.close();
}

void Map::printCells()
{
    int num = allCells.size();
    int dim = sqrt(num);
    //cout << allCells.size() << endl;
    for (int i = 0; i < num; i++)
    {
        if ((i + 1) % dim == 0)
        {
            cout << allCells[i]->getType() << endl;
        }
        else
        {
            cout << allCells[i]->getType();
        }

        
    }
    //allCells[i] = getStartCell();
    
    /*for (int i = 0; i < num; i++)
    {
        cout << allCells[i]->getRow() << endl;
        cout << allCells[i]->getColumn() << endl;

    }*/


}

void Map::printRoute()
{
    //Tracker* p_tracker = new Tracker;
    int num = allCells.size();
    int dim = sqrt(num);
    //cout << allCells.size() << endl;
    for (int i = 0; i < num; i++)
    {
        if ((i + 1) % dim == 0)
        {
            if (allCells[i]->getOnPath() == true)
            {
                cout << 'O'<<endl;
            }
            else
            {
                cout << 'X'<<endl;
            }  
        }
        else
        {
            if (allCells[i]->getOnPath() == true)
            {
                cout << 'O';
            }
            else
            {
                cout << 'X';
            }
        }
    }
}

Cell* Map::getStartCell()
{
    int num = allCells.size();
    int dim = sqrt(num);
    for (int i = 0; i < num; i++)
    {
        if (allCells[i]->getType() == 'S')
        {
            p_startCell=allCells[i];
        }
    }

	return p_startCell;
}

Cell* Map::getNorth(const Cell* p_cell)//p_cell equals to current pointer
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();

    // Check if moving north is within the bounds of the map
    if (r > 0) 
    {
        // Calculate the index of the cell to the north
        int northIndex = (r - 1) * dim + c;

        // Return the cell to the north from the SafeArray 'allCells'
        return allCells[northIndex];
    }
    else 
    {
        // Handle the case where moving north is not possible
        //return allCells[0];
        return nullptr;
    }
}

Cell* Map::getNorthEast(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();

    // Check if moving north-east is within the bounds of the map
    if (r > 0 && c < dim - 1) {
        // Calculate the index of the cell to the north-east
        int northEastIndex = (r - 1) * dim + (c + 1);

        // Return the cell to the north-east from the SafeArray 'allCells'
        return allCells[northEastIndex];
    }
    else {
        // Handle the case where moving north-east is not possible
        return nullptr;
    }
}

Cell* Map::getEast(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();
    // Check if moving east is within the bounds of the map
    if (c < dim - 1) {
        // Calculate the index of the cell to the east
        int eastIndex = r * dim + (c + 1);

        // Return the cell to the east from the SafeArray 'allCells'
        return allCells[eastIndex];
    }
    else {
        // Handle the case where moving east is not possible
        return nullptr;
    }
}

Cell* Map::getSouth(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();

    // Check if moving south is within the bounds of the map
    if (r < dim - 1 && c >= 0 && c < dim) 
    {
        // Calculate the index of the cell to the south
        int southIndex = (r + 1) * dim + c;

        // Return the cell to the south from the SafeArray 'allCells'
        return allCells[southIndex];
    }
    else 
    {
        // Handle the case where moving south is not possible
        return nullptr;
    }
}

Cell* Map::getSouthEast(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();
    // Check if moving south-east is within the bounds of the map
    if (r < dim - 1 && c < dim - 1) 
    {
        // Calculate the index of the cell to the south-east
        int southEastIndex = (r + 1) * dim + (c + 1);

        // Return the cell to the south-east from the SafeArray 'allCells'
        return allCells[southEastIndex];
    }
    else 
    {
        // Handle the case where moving south-east is not possible
        return nullptr;
    }
}

Cell* Map::getWest(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();
    // Check if moving south-east is within the bounds of the map
    if (r < dim - 1 && c < dim - 1) {
        // Calculate the index of the cell to the south-east
        int southEastIndex = (r + 1) * dim + (c + 1);

        // Return the cell to the south-east from the SafeArray 'allCells'
        return allCells[southEastIndex];
    }
    else {
        // Handle the case where moving south-east is not possible
        return nullptr;
    }
}

Cell* Map::getSouthWest(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();
    // Check if moving west is within the bounds of the map
    if (c > 0) {
        // Calculate the index of the cell to the west
        int westIndex = r * dim + (c - 1);

        // Return the cell to the west from the SafeArray 'allCells'
        return allCells[westIndex];
    }
    else {
        // Handle the case where moving west is not possible
        return nullptr;
    }
}

Cell* Map::getNorthWest(const Cell* p_cell)
{
    int num = allCells.size();
    int dim = sqrt(num);
    int r = p_cell->getRow();
    int c = p_cell->getColumn();
    // Check if moving north-west is within the bounds of the map
    if (r > 0 && c > 0) {
        // Calculate the index of the cell to the north-west
        int northWestIndex = (r - 1) * dim + (c - 1);

        // Return the cell to the north-west from the SafeArray 'allCells'
        return allCells[northWestIndex];
    }
    else {
        // Handle the case where moving north-west is not possible
        return nullptr;
    }
}
