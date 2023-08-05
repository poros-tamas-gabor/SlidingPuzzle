#ifndef A_STAR_PUZZLE_SOLVER_H
#define A_STAR_PUZZLE_SOLVER_H

#include "Node.h"
#include <vector>
#include <memory>
#include <list>

///////////////////////////////////////////////////////////////////////////////
// AStarPuzzleSolver.h
// ===================
//
// The 8-pieces sliding puzzle can be represented as a graph with circles, which means that local finding methods may not always find a solution.
// For example, hill climbing method can run into an endless loop due to the presence of circles in the graph.
//
// To reliably find a solution path, the application uses graph search methods, which can explore the entire graph to find the solution.
// One of the heuristic graph search algorithms used is the A* (A-star) algorithm, which allows for easy incorporation of various heuristics.
// The class represents an implementation of the A* (A-star) algorithm.
//
// The evaluation function of the A* algorithm uses the path cost of the Node and the Manhattan Heuristic Value.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////

class AStarPuzzleSolver
{
private:
    std::vector<NodePtr>    m_searchGraph;
    std::vector<NodePtr>    m_openNodes;
    std::list<NodePtr>      m_solutionPath;
public:
    AStarPuzzleSolver();
    void Initialize(const Board& start);
    void Run();
    const std::list<NodePtr>& GetSolutionPath() const;
private:
    NodePtr GetMinCostNode();
    void    CreateSolutionPath(NodePtr endNode);
    bool    IsInSearchGraph(NodePtr node);
    bool    FindAShorterPath(NodePtr node);
};

#endif