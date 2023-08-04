#include "AStarPuzzleSolver.h"
#include "SPException.h"
#include <iostream>

AStarPuzzleSolver::AStarPuzzleSolver() {}

void AStarPuzzleSolver::Initialize(const Board& start)
{
    NodePtr startNode = std::make_shared<Node>(start, 0, nullptr, INVALID);
    m_openNodes.push_back(startNode);  
}

void AStarPuzzleSolver::Run()
{
    while (true)
    {
        if(m_openNodes.empty())
            THROW_SPEXCEPTION("Error : Solution is not found");

        NodePtr currentNode = GetMinCostNode();
        if(currentNode && currentNode->GetBoard().IsEndState()) //FOUND THE SOLUTION
        {
            CreateSolutionPath(currentNode); 
            return; 
        }

        std::vector<Direction> validDirections = currentNode->GetBoard().GetValidDirection();
        // Delete the inversion of the previous sliding from the validDirections;
        if(std::find(validDirections.begin(), validDirections.end(), InvertDirection(currentNode->GetPrevDirection())) != validDirections.end())
        {
            validDirections.erase(std::remove(validDirections.begin(), validDirections.end(), InvertDirection(currentNode->GetPrevDirection())));
        }

        // Collect the children of the current nodes and put them into the openNodes
        for(Direction d : validDirections)
        {
            Board board = currentNode->GetBoard();
            board.DoSliding(d);

            NodePtr child = std::make_shared<Node>(board, currentNode->GetPathCost() + 1, currentNode, d);
            m_openNodes.push_back(child);
        }

        //put the extended current node into the searchGraph
        m_searchGraph.push_back(currentNode);
    }
    
}

void  AStarPuzzleSolver::CreateSolutionPath(NodePtr endNode)
{
    // From the end state node, we can create a solution path by following the parent pointers of the nodes backward
    // from the end node to the start node. The order of nodes in the path will then represent the path from the
    // start position to the end position.
    m_solutionPath.clear();
    NodePtr p = endNode;
    while(p->GetParentNode() != nullptr)
    {
        m_solutionPath.push_front(p);
        p = p->GetParentNode();
    }
    m_solutionPath.push_front(p);
}

const std::list<NodePtr>& AStarPuzzleSolver::GetSolutionPath() const
{
    return m_solutionPath;
}

NodePtr AStarPuzzleSolver::GetMinCostNode()
{
    // The evaluation function of the A* algorithm is the addition of the path cost and the Manhattan heuristic value.
    // This function returns the node with the minimum total cost from the open nodes list.
    // After returning the node, it also removes the returned node from the open nodes list.
    unsigned minCost = m_openNodes.at(0)->GetTotalCost();
    unsigned minIndex = 0;
    for(unsigned i = 1; i < m_openNodes.size(); i++)
    {
        unsigned currentCost = m_openNodes.at(i)->GetTotalCost();
        if(minCost > currentCost)
        {
            minCost = currentCost;
            minIndex = i;
        }
    }
    NodePtr minNode = m_openNodes.at(minIndex);

    m_openNodes.erase(m_openNodes.begin() + minIndex);

    return minNode;
}
