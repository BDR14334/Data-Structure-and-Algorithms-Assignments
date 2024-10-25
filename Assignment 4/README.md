# Boggle Solver with Trie Data Structure

## Overview
This C++ project implements a Boggle Solver using a `Trie` data structure to efficiently search for words within a 5x5 Boggle board. The program includes classes to represent a Boggle die, the board itself, and a trie that stores dictionary words. By leveraging recursion and the trie structure, the program quickly identifies valid words on the board.

## Key Features
- **Trie**: A class that builds a trie from a dictionary file, supporting efficient word lookups with three possible outcomes: `FOUND`, `NOT FOUND`, or `PARTIAL`. This allows for fast validation of complete and partial words.
- **BoggleBoard**: A class that sets up and displays a 5x5 board of randomized dice, checks all possible letter combinations using recursive backtracking, and avoids reusing dice within the same word.
- **Efficient Word Search**: The recursive `solve()` method narrows down potential word paths using partial word matches, drastically reducing search time compared to a brute-force approach.

## Usage
1. **Trie**: Initializes from a dictionary file and allows searching for complete and partial words.
2. **BoggleBoard**: Generates a randomized 5x5 board of dice letters and uses the trie to search for all possible words.
