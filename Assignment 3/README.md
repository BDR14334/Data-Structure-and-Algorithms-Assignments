# Word Finder

## Overview
This project is a C++ program that helps break down a string into valid words using a dictionary. The program uses a `WordFinder` class to recursively identify combinations of complete words from a given input string, ensuring that all identified segments are present in a provided dictionary file.

## Key Features
- **Dictionary**: A class that loads and stores words from a dictionary file using an `unordered_set`, and provides a method to check if a word exists.
- **WordFinder**: A class that breaks down an input string into valid dictionary words using recursion and backtracking.
- **Efficient Search**: Only checks word combinations that start with valid dictionary entries, reducing unnecessary checks and improving performance.

## Usage
1. The `Dictionary` class loads words from the provided dictionary file and uses an unordered set for fast lookups.
2. The `WordFinder` class is responsible for recursively splitting strings into dictionary-valid word combinations and printing them.
