#include "Model.h"
#include <iostream>

bool Model::Initialize()
{
    m_board = DoPuzzleInitializing();
    m_messageSystem.Publish(m_board);
    std::cout << "Manhattan " << m_board.GetManhattanHeuristicValue() << std::endl;
}

bool Model::IsReady() const
{
    return m_board.IsEndState();
}

void Model::NextStep() 
{

    m_messageSystem.Publish(m_board);
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
    int numOfRound = rand() % 100 + 1;
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
