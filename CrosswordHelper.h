#pragma once
#include <iostream>
#include <fstream> 
#include <string>
#include "IntersectionContainer.h"

using namespace std;

class CrosswordHelper
{
public:
	CrosswordHelper(const string& dictionaryPath, int requestedWordLength);
	SafeArray<string> findWords(const string& searchWord) const; //kinda like binary search -me


private:
	SafeArray<SafeArray<SafeArray<string>>> words;
	
	
	//int wordLength;

};

