#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BoggleDice
{
public:
	BoggleDice(string sides[]);
	string getFace();

private:
	string face;
	//int diceNum;
};

