#include "Dictionary.h"

Dictionary::Dictionary(string dictionaryPath)
{
    ifstream infile;

    infile.open(dictionaryPath);

    if (infile.good())
    {
        string word;

        infile >> word;

        while (infile.good())
        {
            allWords.insert(word);
          
            getline(infile, word);
        }
        infile.close();
    }
    else
    {
        cout << "Cannot open the file: " << dictionaryPath << endl;
    }
}

bool Dictionary::isWordPresent(string word)
{
	return allWords.count(word) > 0;
}