# Map Navigation Program

## Overview
This C++ program finds a path through a map using a stack-based backtracking approach. The map is read from a file, and the program moves from a start cell to an end cell, avoiding blocked cells and backtracking as necessary.

## Key Features
- **Stack**: A templated class using a `DoublyLinkedList` to implement `push`, `pop`, `top`, and `isEmpty` methods. Handles exceptions when accessing an empty stack.
- **Cell**: Represents a map square, with attributes like row, column, and type (`FREE`, `BLOCKED`, `START`, `END`).
- **Map**: Reads the map from a file, stores cells in a `SafeArray`, and provides methods to access neighboring cells.
- **Tracker**: Traverses the map using a stack, logging movements and backtracking to find a valid path.

The program reads a map, finds a path from start to end, and outputs both the original and path-marked maps.

