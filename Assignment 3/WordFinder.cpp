#include "WordFinder.h"

WordFinder::WordFinder(string dictionaryPath):dictionary(dictionaryPath)
{
  //do nothing
}

void WordFinder::makeWordsFromWordHelper(string word, vector<string>& words)
{
    //loop thru the word length
    for (int i = 1; i <= word.length(); i++)
    {
        //split string apart
        firstPart = word.substr(0, i);
        remainder = word.substr(i);

        //check to see if first part is in dictionary
        if (dictionary.isWordPresent(firstPart) == true)
        {
            words.push_back(firstPart);//just added
            //if their is a remainder 
            if (remainder.length() == 0)
            {
                //isWords.push_back(words);//just 
                for (int i = 0; i < words.size(); i++)
                {
                    cout << words[i] << " ";//print words
                }
                cout << endl;
            }
            else
            {
                //use recursion for remainder
                makeWordsFromWordHelper(remainder, words);
            }
            //pop vector
            words.pop_back();
        }
    }
}

void WordFinder::makeWordsFromWord(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (isupper(word[i]) == true)
        {
            word[i] = tolower(word[i]);
        }
    }
    for (int i = 0; i < word.length(); i++)
    {
        if (isalnum(word[i]) == false)
        {
            word.erase(i, 1);
        }
    }

    vector <string> words;
    makeWordsFromWordHelper(word, words);
}
