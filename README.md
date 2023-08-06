# 8-Pieces Sliding Puzzle

## Introduction
The 8-Pieces Sliding Puzzle application is designed to visualize the solution path from a random starting position to a required end state. The application follows a two-layered architecture, comprising the Model and the View components. By creating interfaces for both components, the visualization of the application can be easily modified without altering the Model.

## Model Description
The Model component handles the mathematical representation of the puzzle and the solving algorithm. The puzzle board is mathematically represented by a 2-dimensional integer array, and the empty (or zero field) can slide in different directions. As a result, there are 9 factorial different states, which are stored in two separate representation graphs. These nodes are connected by valid sliding movements between them. To generate a random initial state, the application employs a random quantity of valid movements, ensuring a valid starting position.

## Graph Search Algorithms (A* and Ac)
The current version of the program utilizes either the A* or Ac algorithm. The `AStarPuzzleSolver` class maintains the search graph for extended nodes and the open nodes for the realized but not extended ones. An evaluation function combines the Manhattan value of the board and the node's path cost from the initial state. The `AStarPuzzle::Run` method implements a general graph search algorithm, extending nodes with minimal total cost based on the evaluation function until the end state is reached or no solution is found.

## Solution Path
Each node in the graph contains information about the represented board, the path cost from the initial state, its parent node, and the previous sliding direction. By following the chain of parent node pointers from the end state, the solution path can be obtained. Reversing the direction of this path provides the representation of the sliding movements needed to solve the puzzle.

## Improvements
### Modular View Components
The application's View components can be easily customized to create a graphical interface, thanks to the modularity of the architectural pattern.

### Interface for Puzzle Solver and Heuristic Calculator
Creating interfaces for the Puzzle Solver and heuristic value calculator allows the application to incorporate different techniques, providing flexibility and enabling future improvements.

## Source Code and Unit Tests
The source code is organized into two directories:
- `src`: Contains all the source code files.
- `test`: Contains the unit tests for the application.

Both directories have their respective `makefile` to compile the code using a C++11 compiler.

## Getting Started
To run the application, follow these steps:

1. Clone the repository to your local machine.
2. Compile the source code using the provided makefiles.
3. Execute the application, and it will visualize the solution path from a random starting position to the required end state.
