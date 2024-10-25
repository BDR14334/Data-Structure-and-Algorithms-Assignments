#include "Trie.h"

Trie::Trie(const string& filepath)
{
    //create the node make root point to it
    root = new TriElement;
    for (int i = 0; i < 26; i++)
    {
        root->elements[i] = 0;
    }
    root->wordSoFar = "";// filepath;
    root->isCompleteWord = false;


    ifstream infile;

    infile.open(filepath);

    if (infile.good())
    {
        string line;

        infile >> line;

        while (infile.good())
        {
            //words.push_back(line);
            //if (!line.size())
           // {
            insert(line);
            //}


            infile >> line;

        }
    }
    else
    {
        cout << "Cannot open the file: " << filepath << endl;
    }
}
//--
Trie::~Trie()
{
    removeAll(root);
}
//--
void Trie::removeAll(TriElement*& p)
{
    // TriElement T;
         //* elements[26];
    if (p != 0)
    {
        //for 26
        //removeAll(woelements[26]rdSoFar->elements[i]);
        for (int i = 0; i < 26; i++)
        {
            //p = p->elements[26];
            removeAll(p->elements[i]);
        }
        delete p;
    }
}
//--
void Trie::insert(const string& newWord)
{
    insertHelper(root, newWord);
}
//--
void Trie::insertHelper(TriElement*& p, const string& newWord)
{
    //bool isCompleteWord = false;
    if (newWord.length() == 0)
    {
        p->isCompleteWord = true;
        //root-> elements[26] = p;
        //root->wordSoFar = newWord;

    }
    else
    {
        //first letter
        char first = tolower(newWord[0]);
        string rest = newWord.substr(1);
        //convert to 0-25 
        int pos = first - 'a';
        //p->wordSoFar = newWord[pos];
        //p->isCompleteWord = false;

        //if the sub-node exists
        if (p->elements[pos] == 0)
        {
            TriElement* p_new = new TriElement;
            for (int i = 0; i < 26; i++)
            {
                p_new->elements[i] = 0;
            }
            p_new->isCompleteWord = false;
            p_new->wordSoFar = first + p->wordSoFar;

            p->elements[pos] = p_new;
            //return newWord[pos];
        }

        // recurse
        insertHelper(p->elements[pos], rest);





        //p->isCompleteWord = true;
        //p->wordSoFar = newWord;



       /* for (int i = 0; newWord.length(); i++)
        {
            insert(p->wordSoFar);
        }*/
        //isCompleteWord = true;
    }
}
//--
string Trie::search(const string& word)
{
    string result;
    searchHelper(root, word, result);
    return result;
}
//--
void Trie::searchHelper(TriElement*& p, const string& word, string& result)
{

    //T.isCompleteWord = false;
    //if (element[i].find(word) == isCompleteWord )
    if (word.length() == 0)
    {
        if (p->isCompleteWord == false)
        {
            result = "PARTIAL";

        }
        else
        {
            result = "FOUND";
        }

        //return (p, word, result);

    }
    else //if (element[i].find(word) != isCompleteWord)
    {

        char first = tolower(word[0]);
        string rest = word.substr(1);
        //convert to 0-25
        int pos = first - 'a';
        //if the sub-node exists
        if (p->elements[pos] == 0)
        {
            //p->isCompleteWord = false;
            result = "NOT FOUND";
        }
        else
        {
            //recurse 
            searchHelper(p->elements[pos], rest, result);
        }


        //wordSoFar->elements[i] = p;
        //cout << "NOT FOUND" << word << endl; 

    }

}