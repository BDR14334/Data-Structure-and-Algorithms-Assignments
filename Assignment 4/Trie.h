#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Trie
{
public:
    Trie(const string& filepath);
    ~Trie();
    void insert(const string& newWord);
    string search(const string& word);
    //void printAllWords();

private:
    struct TriElement
    {
        TriElement* elements[26];
        string wordSoFar;
        bool isCompleteWord = false;
    };
    TriElement* root;
    void removeAll(TriElement*& p);
    void insertHelper(TriElement*& p, const string& newWord);
    void searchHelper(TriElement*& p, const string& word, string& result);

};

