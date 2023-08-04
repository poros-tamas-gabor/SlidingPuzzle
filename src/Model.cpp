#include "Model.h"
#include <iostream>

bool Model::Initialize()
{
    Board start = DoPuzzleInitializing();
    m_solver.Initialize(start);
    m_solver.Run();
  
    m_solutionPath = m_solver.GetSolutionPath();

    return !m_solutionPath.empty();
}

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

Board Model::DoPuzzleInitializing()
{
    Board board;
    int numOfRound = rand() % 10 + 1;
    std::cout <<  "numOfRound = "<< numOfRound << std::endl;

    for(int i = 0; i < numOfRound; i++)
    {
        const std::vector<Direction>& directions = board.GetValidDirection();

        //choose random direction
        int indexOfDirection = rand() % (directions.size());
        //std::cout << "indexofDirection : " << indexOfDirection << " Dir : " << directions.at(indexOfDirection) << std::endl;

        //Do Sliding
        board.DoSliding(directions.at(indexOfDirection));
        //m_messageSystem.Publish(board);
    }

    return board;
}
