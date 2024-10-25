#include "CrosswordHelper.h"

CrosswordHelper::CrosswordHelper(const string& dictionaryPath, int requestedWordLength)
{
    // Initialize the wordCollection with empty maps
    words.resize(requestedWordLength);

    for (int i = 0; i < requestedWordLength; i++)
    {
        words[i].resize(26);
    }

    ifstream infile;

    // Open the dictionary file
    infile.open(dictionaryPath);

    if (!infile.good())
    {
        cout << "Error: Unable to open the dictionary file." << endl;
        return;
    }

    string word;
    while(infile.good())
    {
        infile >> word;
        if (word.length() == requestedWordLength)
        {
            for (int i = 0; i < word.size(); i++)
            {
                int row = i;
                int col = word[i] - 'a';

                if (col >= 0 && col < 26)
                {
                    words[row][col].push_back(word);
                }
            }

        }
   
    }
    // Close the dictionary file
   //infile.close();

    //sort it into SafeArray<SafeArray<SafeArray<string>>> words alphabetically;

}

SafeArray<string> CrosswordHelper::findWords(const string& searchWord) const
{
    //create intersection container of strings
    IntersectionContainer<string> ic;

    //loop thru the searchWord
    for (int i = 0; i < searchWord.length(); i++)
    {
        //created char variable to account for letter in searchWord
        char isChar = searchWord[i];
        //if the letter doesnt equal -
        if (isChar != '-')
        {
            //use col to find the word that start with user input
            int col = isChar - 'a';
            //add the words to intersection container to filter
            ic.add(words[i][col]);
        }

    }
    //return all the common elements that intersect
    return ic.getCommonElements();
}



//findWOrd

//create an intersectionContainers of strings, private data memember
//look thru the search word using for loop
// when you get an actually letter like x or s
//you want to match letters
//so find words at position 3 that start with x, whats in the safe array