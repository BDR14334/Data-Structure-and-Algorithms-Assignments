# Crossword Puzzle Helper

## Overview
This project is a C++ program that helps solve crossword puzzles by finding words that match a partially known pattern. It uses a `CrossWordHelper` class to search a dictionary for words with specific letters in known positions (e.g., "--x-n"). 

## Key Features
- **CrossWordHelper**: Searches for words that match a given pattern using a dictionary file.
- **IntersectionContainer**: A templated class that finds common elements across multiple SafeArrays.
- **SafeArray**: A custom dynamic array class supporting element access, resizing, and manipulation.

The program efficiently narrows down word matches by finding intersections across sets of possible words, demonstrating templating and dynamic memory management in C++.