#ifndef A_STAR_PUZZLE_SOLVER_H
#define A_STAR_PUZZLE_SOLVER_H

#include "Node.h"
#include <vector>
#include <memory>
#include <list>

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
};

#endif