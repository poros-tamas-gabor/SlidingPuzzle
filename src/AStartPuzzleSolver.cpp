#include "AStarPuzzleSolver.h"
#include "SPException.h"
#include <iostream>

AStarPuzzleSolver::AStarPuzzleSolver() {}

void AStarPuzzleSolver::Initialize(const Board& start)
{
    NodePtr startNode = std::make_shared<Node>(start, 0, nullptr, INVALID);
    m_openNodes.push_back(startNode);  
}

// The function runs the A* graph search algorithm.
void AStarPuzzleSolver::Run()
{
    while (true)
    {
        if(m_openNodes.empty())
            THROW_SPEXCEPTION("Error : Solution is not found");

        NodePtr currentNode = GetMinCostNode();
        if(currentNode && currentNode->GetBoard().IsEndState()) 
        {
            //Current node is the end state node.
            CreateSolutionPath(currentNode); 
            return; 
        }

        std::vector<Direction> validDirections = currentNode->GetBoard().GetValidDirection();
        // Delete the inversion of the previous sliding from the validDirections.
        if(std::find(validDirections.begin(), validDirections.end(), InvertDirection(currentNode->GetPrevDirection())) != validDirections.end())
        {
            validDirections.erase(std::remove(validDirections.begin(), validDirections.end(), InvertDirection(currentNode->GetPrevDirection())));
        }

        // Collect the children of the current nodes and put them into the openNodes.
        for(Direction d : validDirections)
        {
            Board board = currentNode->GetBoard();
            board.DoSliding(d);

            NodePtr child = std::make_shared<Node>(board, currentNode->GetPathCost() + 1, currentNode, d);

            if (!IsInSearchGraph(child) || FindAShorterPath(child))
                m_openNodes.push_back(child);
        }

        //  Put the extended current node into the searchGraph.
        m_searchGraph.push_back(currentNode);
    }  
}

// From the end state node, we can create a solution path by following the parent pointers of the nodes backward
// from the end node to the start node. The order of nodes in the path will then represent the path from the
// start position to the end position.
void  AStarPuzzleSolver::CreateSolutionPath(NodePtr endNode)
{
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

// The evaluation function of the A* algorithm is the addition of the path cost and the Manhattan heuristic value.
// This function returns the node with the minimum total cost from the open nodes list.
// After returning the node, it also removes the returned node from the open nodes list.
NodePtr AStarPuzzleSolver::GetMinCostNode()
{
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


bool AStarPuzzleSolver::IsInSearchGraph(NodePtr node)
{
    NodeEQ eq(node);
    return std::find_if(m_searchGraph.begin(), m_searchGraph.end(), eq) != m_searchGraph.end();
}

bool AStarPuzzleSolver::FindAShorterPath(NodePtr node)
{
    if(!IsInSearchGraph(node))
        return false;
    
    NodeEQ eq(node);
    auto it = std::find_if(m_searchGraph.begin(), m_searchGraph.end(), eq);

    return it->get()->GetPathCost() > node->GetPathCost();
}