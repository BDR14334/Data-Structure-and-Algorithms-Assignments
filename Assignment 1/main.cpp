#include <iostream>
#include <cassert> //for assert function
#include "SafeArray.h"
#include "SafeArrayException.h"
#include "CrosswordHelper.h"

using namespace std;

void printWords(const CrosswordHelper& helper, const string& searchWord);

int main()
{
    try {

        CrosswordHelper helper("C:/Users/brand/Documents/txt/bigDictionary.txt", 5);



        printWords(helper, "-a-se");

        printWords(helper, "-y--c");

        printWords(helper, "--x-n");

        printWords(helper, "----z");

    }
    catch (const SafeArrayException& ex) {

        cout << "Exception: " << ex.getMessage() << endl;

    }

}

void printWords(const CrosswordHelper& helper, const string& searchWord)
{

    SafeArray < string > words = helper.findWords(searchWord);



    cout << "Words for '" + searchWord + "':" << endl;

    for (int i = 0; i < words.size(); i++) {

        cout << words[i] << endl;

    }

    cout << endl;

}