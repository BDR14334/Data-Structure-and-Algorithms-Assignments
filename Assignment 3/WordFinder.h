#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Dictionary.h"

using namespace std;

class WordFinder
{
public:
	WordFinder(string dictionaryPath);
	void makeWordsFromWordHelper(string word, vector <string>& isWords);
	void makeWordsFromWord(string word);
private:
	//vector <string> words;
	Dictionary dictionary;
	vector <vector < string > > isWords;
	string firstPart;
	string remainder;
};

