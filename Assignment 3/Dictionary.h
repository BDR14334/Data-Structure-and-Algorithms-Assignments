#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_set>

using namespace std;

class Dictionary
{
public:
	Dictionary(string dictionaryPath);
	bool isWordPresent(string word);

private:
	unordered_set <string> allWords;
};

