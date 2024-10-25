#include "BoggleDice.h"

BoggleDice::BoggleDice(string sides[])
{
	int pos = rand() % 6;
	face = sides[pos];
	//pick 
}
//--
string BoggleDice::getFace()
{
	return face;
}