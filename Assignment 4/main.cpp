#include <iostream>
#include <ctime>
#include "BoggleBoard.h"

using namespace std;

int main()
{
    //comment this out while debugging to get the same board over and over again
    srand(time(0));

    BoggleBoard bb("C:/Users/brand/Documents/txt/bigDictionary.txt");

    bb.printBoard();
    string wordSoFar = ""; // Initialize the wordSoFar string
    vector<string> foundWords;

    bb.solve(wordSoFar, foundWords);

    cout << foundWords;

    return 0;
}