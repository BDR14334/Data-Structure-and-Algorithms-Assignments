#include "WordFinder.h"
using namespace std;

int main()
{
    WordFinder finder("C:/Users/brand/Documents/txt/bigDictionary.txt");

    finder.makeWordsFromWord("carton");
    finder.makeWordsFromWord("sodapop");
    finder.makeWordsFromWord("ihaveafriendwhosenameisjane");
    finder.makeWordsFromWord("abcxyz");

    return 0;
}