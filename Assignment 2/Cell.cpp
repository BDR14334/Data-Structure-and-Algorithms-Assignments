#include "Cell.h"
Cell::Cell()
{
	x = 0;
	y = 0;
	type = ' ';
	hasBeenVisited = false;
	onPath = false;
}
//set x coordinates
void Cell::setRow(int isX)
{
	x = isX;
}
//return x coordinate using get function
int Cell::getRow() const
{
	return x;
}
//set y coordinates
void Cell::setColumn(int isY)
{
	y = isY;
}
//return y coordinate using get function
int Cell::getColumn() const
{
	return y;
}
//set cell type
void Cell::setType(char isType)
{
	type = isType;
}
//return cell type
char Cell::getType()
{
	return type;
}
//set and check see if cell hasbeenvistited
void Cell::setHasBeenVisited(bool v)
{
	hasBeenVisited = v;
	//return hasBeenVisited;
}
//return hasbeenvisted 
bool Cell::getHasBeenVisited()
{
	return hasBeenVisited;
}
void Cell::setOnPath(bool p)
{
	onPath = p;
}
bool Cell::getOnPath()
{
	return onPath;
}