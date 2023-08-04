#include "Model.h"
#include <iostream>

// Creating an iterable solution path after the Initialize function is called.
// The function returns false if the solution path is empty.
bool Model::Initialize()
{
    Board start = DoPuzzleInitializing();

    // Initialize and run the AStarPuzzle component to find the solution path.
    m_solver.Initialize(start);
    m_solver.Run();
    m_solutionPath = m_solver.GetSolutionPath();
    return !m_solutionPath.empty();
}

// Check if the solution path has been fully traversed.
bool Model::IsEnded() const
{
    return m_solutionPath.empty();
}

void Model::NextStep() 
{
    NodePtr current = m_solutionPath.front();
    m_messageSystem.Publish(current);
    m_solutionPath.pop_front();
}

bool Model::AddSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Subscribe(s);
}
bool Model::RemoveSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Unsubscribe(s);
}

// Initialize the puzzle board by performing a random number of sliding moves.
Board Model::DoPuzzleInitializing()
{
    Board board;
    int numOfRound = rand() % 100 + 1;

    for(int i = 0; i < numOfRound; i++)
    {
        const std::vector<Direction>& directions = board.GetValidDirection();
        // Choose random direction
        int indexOfDirection = rand() % (directions.size());
        //  Do Sliding
        board.DoSliding(directions.at(indexOfDirection));
    }

    return board;
}
