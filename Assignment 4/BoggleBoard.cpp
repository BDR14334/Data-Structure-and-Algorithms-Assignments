#include "BoggleBoard.h"

BoggleBoard::BoggleBoard(const string& pathToDictionary) :trie(pathToDictionary)
{
    // Construct the BoggleBoard by creating BoggleDice objects
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string sides[6];
            for (int s = 0; s < 6; s++)
            {
                sides[s] = faces[i * 5 + j][s];
            }
            board[i][j] = new BoggleDice(sides);
        }
    }
}

void BoggleBoard::printBoard()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cout << board[i][j]->getFace() << " ";
        }
        cout << endl;
    }
}

void BoggleBoard::solve(string& wordSoFar, vector<string>& foundWords)
{
    // Traverse the board cells
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            bool visited[5][5] = { {false} }; // Initialize a visited array for each cell
            string word = wordSoFar + board[row][col]->getFace();
            solveHelper(row, col, word, foundWords, visited);
        }
    }
}

void BoggleBoard::solveHelper(int row, int col, string& wordSoFar, vector<string>& foundWords, bool visited[5][5])
{
    // Boundary checks and visited cell check
    if (row < 0 || col < 0 || row >= 5 || col >= 5 || visited[row][col])
        return;

    // Mark the current cell as visited
    visited[row][col] = true;

    // Form the new word and check if it's valid in the trie
    string newWord = wordSoFar + board[row][col]->getFace();
    if (trie.search(newWord) == "FOUND" || trie.search(newWord) == "PARTIAL")
    {
        if (trie.search(newWord) == "FOUND")
        {
            foundWords.push_back(newWord);
        }

        // Explore neighboring cells recursively
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = col - 1; j <= col + 1; j++)
            {
                solveHelper(i, j, newWord, foundWords, visited);
            }
        }
    }

    // Unmark the current cell as visited to backtrack
    visited[row][col] = false;
}